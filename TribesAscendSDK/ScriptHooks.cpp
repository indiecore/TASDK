#include "TASDK.h"
#include <deque>

using namespace UnrealScript;

struct HookInfo
{
	HookFunction hook_function;
	ScriptFunction *hook_target;
	NativeFunction orig_function;

	std::deque< int > arg_size;
	int stack_size;
};

namespace script_hooks
{
	std::deque< HookInfo > hook_array;

	NativeFunction *native_array;
	NativeFunction OrigVirtualFunction;
	CleanupStack cleanup_stack;
	CallFunction call_function;

	DWORD test;
	__declspec( naked ) HookType CallHook( HookFunction function, ScriptObject *object, int param_size, void *result, byte *func_args )
	{	
		__asm
		{
			push ebp
			mov ebp, esp

			push edx
			push ecx

			mov ecx, func_args
			add ecx, param_size

			mov edx, func_args
		}
push_loop:
		__asm
		{
			push [edx]
			add edx, 4

			cmp edx, ecx
			jl push_loop

			push result
			push object

			call function
			add esp, 8
			add esp, param_size

			pop ecx
			pop edx
			pop ebp

			retn
		}
	}

	__declspec( naked ) uintptr_t *GetEBP()
	{
		__asm
		{
			mov eax, ebp
			retn
		}
	}

	void __fastcall HookHandler( ScriptObject *thisptr, int edx, ScriptStackFrame &stack, void *result )
	{
		byte *orig_code = stack.code;
		for( DWORD i = 0; i < hook_array.size(); i++ )
		{
			//lea ebp, [esp-404] in CallFunction
			uintptr_t function = *( uintptr_t* )( *GetEBP() + 0x414 ); //3rd arg of CallFunction

			if( function == ( uintptr_t )( hook_array[ i ].hook_target ) )
			{
				byte *func_args = ( byte* )( malloc( hook_array[ i ].stack_size ) );
				int arg_offset = hook_array[ i ].stack_size;

				for( int num_params = 0; *stack.code != 0x16; num_params++ ) //copy args to buffer, respecting LIFO
				{
					arg_offset -= hook_array[ i ].arg_size[ num_params ];
					native_array[ *stack.code++ ]( stack.object, stack, func_args + arg_offset );
				}

				if( CallHook( hook_array[ i ].hook_function, stack.object, hook_array[ i ].stack_size, result, func_args ) == kHookBlock )
				{
					cleanup_stack( stack, result, hook_array[ i ].hook_target );
					free( func_args );
					return;
				}

				free( func_args );
				stack.code = orig_code;

				if( hook_array[ i ].orig_function )
				{
					hook_array[ i ].hook_target->set_function( hook_array[ i ].orig_function );
					call_function( thisptr, stack, result, hook_array[ i ].hook_target );
					hook_array[ i ].hook_target->set_function( HookHandler );
				}
				else
				{
					hook_array[ i ].hook_target->set_function_flags( hook_array[ i ].hook_target->function_flags() & ~ScriptFunction::kFuncNative );
					call_function( thisptr, stack, result, hook_array[ i ].hook_target );
					hook_array[ i ].hook_target->set_function_flags( hook_array[ i ].hook_target->function_flags() | ScriptFunction::kFuncNative );
				}

				return;
			}
		}
	}

	void AddHook( char *function_name, void *function )
	{
		ScriptFunction *script_function = ScriptObject::Find< ScriptFunction >( function_name );

		if( script_function )
		{
			HookInfo new_hook;

			new_hook.hook_function = ( HookFunction )( function );
			new_hook.hook_target = script_function;

			new_hook.stack_size = 0;

			if( script_function->function_flags() & ScriptFunction::kFuncNative )
			{
				new_hook.orig_function = ( NativeFunction )( script_function->function() );
			}
			else
			{
				new_hook.orig_function = NULL;
			}

			script_function->set_function_flags( script_function->function_flags() | ScriptFunction::kFuncNative );
			script_function->set_function( HookHandler );

			for( ScriptProperty *script_property = ( ScriptProperty* )( script_function->children() ); script_property; script_property = ( ScriptProperty* )( script_property->next() ) )
			{
				if( script_property->property_flags & ScriptProperty::kPropParm )
				{
					OutputLog( "Arg %s size %i\n", script_property->GetName(), script_property->element_size );
					new_hook.arg_size.push_back( script_property->element_size );
					new_hook.stack_size += script_property->element_size;
				}
			}

			new_hook.stack_size = ( int )( ceil( new_hook.stack_size / 4.0f ) ) * 4;

			hook_array.push_back( new_hook );

			OutputLog( "Hooked function %s (0x%X) (args %i)\n\n", function_name, script_function, new_hook.stack_size );
		}
		else
		{
			OutputLog( "Error: could not find function %s.\n\n", function_name );
		}
	}
}