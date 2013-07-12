#include <Windows.h>
#include "TASDK.h"

using namespace UnrealScript;

struct HookInfo
{
	HookFunction hook_function;
	ScriptFunction *hook_target;

	int arg_count;
	int *arg_size;
	int arg_size_total;
};

namespace script_hooks
{
	HookInfo *hook_array = NULL;
	int hook_count = 0;

	NativeFunction *native_array;
	NativeFunction OrigVirtualFunction;
	CleanupStack cleanup_stack;

	__declspec( naked ) HookType CallHook( HookFunction function, ScriptObject *object, int num_params, int param_size, void *result, byte *func_args )
	{	
		__asm
		{
			push ebp
			mov ebp, esp

			push edx

			mov edx, func_args
			add edx, param_size
		}
push_loop:
		__asm
		{
			sub edx, 4
			push [edx]
			cmp edx, func_args
			jg push_loop

			push result
			push num_params
			push object

			call function
			add esp, 12
			add esp, param_size

			pop edx
			pop ebp

			retn
		}
	}

	void __fastcall VirtualFunction( ScriptObject *thisptr, int edx, ScriptStackFrame &stack, void *result )
	{
		for( int i = 0; i < hook_count; i++ )
		{
			if( stack.node == hook_array[ i ].hook_target )
			{
				byte *orig_code = stack.code;

				stack.code += sizeof( ScriptName );

				byte *func_args = ( byte* )( calloc( 1, hook_array[ i ].arg_size_total ) );
				int arg_offset = 0;
				int num_params = 0;

				//for( int i = 0; i < 20; i++ )
				//	OutputLog( "*stack.code: 0x%X\n",  stack.code[ i ] );

				float delta_time = stack.GetArg< float >();
				OutputLog( "delta time (from stack): %f\n", delta_time );
				stack.code = orig_code + sizeof( ScriptName );

				while( *stack.code != 0x16 )
				{
					native_array[ *stack.code++ ]( stack.object, stack, func_args + arg_offset );
					arg_offset += hook_array[ i ].arg_size[ num_params++ ];
					OutputLog( "arg_offset: %i\n", arg_offset );
				}

				OutputLog( "Param size: %i\n", ( int )( 4.0f * ceil( 0.25f * hook_array[ i ].arg_size_total ) ) );
				if( CallHook( hook_array[ i ].hook_function, stack.object, num_params, ( int )( 4.0f * ceil( 0.25f * hook_array[ i ].arg_size_total ) ), result, func_args ) == kHookBlock )
				{
					cleanup_stack( stack, result, hook_array[ i ].hook_target );
					free( func_args );
					return;
				}

				free( func_args );

				stack.code = orig_code;

				break;
			}
		}

		OrigVirtualFunction( thisptr, stack, result );
	}

	void SetupHooks()
	{
		//OrigVirtualFunction = native_array[ 0x1B ];
		//native_array[ 0x1B ] = ( NativeFunction )( VirtualFunction );
		OutputLog( "Hooked execVirtualFunction\n" );
	}

	struct SetXP_Params
	{
		TrPlayerController *controller;
		int exp;
	};

	void __fastcall Test( TrPlayerController *thisptr, int edx, ScriptStackFrame &stack, void *result )
	{
		byte *orig_code = stack.code;
		for( int i = 0; i < 50; i++ )
		{
			OutputLog( "Stack.Code: 0x%X\n", *stack.code++ );
		}
		stack.code = orig_code;

		OutputLog( "Stack: 0x%X\n", &stack );
		OutputLog( "Result: 0x%X\n", result );
		OutputLog( "PRI: 0x%X\n", stack.GetArg< PlayerReplicationInfo* >() );
		OutputLog( "Slot: %i\n", stack.GetArg< int >() );

		stack.code++;
	}

	void AddHook( char *function_name, void *function )
	{
		ScriptFunction *script_function = ( ScriptFunction* )( ScriptObject::Find( function_name ) );

		if( script_function )
		{
			if( hook_array == NULL )
			{
				hook_array = ( HookInfo* )( malloc( sizeof( HookInfo ) ) );
			}
			else
			{
				hook_array = ( HookInfo* )( realloc( hook_array, ( hook_count + 1 ) * sizeof( HookInfo ) ) );
			}

			hook_array[ hook_count ].hook_function = ( HookFunction )( function );
			hook_array[ hook_count ].hook_target = script_function;

			hook_array[ hook_count ].arg_size_total = 0;
			hook_array[ hook_count ].arg_count = 0;

			hook_array[ hook_count ].arg_size = ( int* )( malloc( 4 ) );

			for( ScriptProperty *script_property = ( ScriptProperty* )( script_function->children() ); script_property; script_property = ( ScriptProperty* )( script_property->next() ) )
			{
				if( script_property->property_flags & ScriptProperty::kPropParm )
				{
					OutputLog( "Arg %s size %i\n", script_property->GetName(), script_property->element_size );
					hook_array[ hook_count ].arg_size[ hook_array[ hook_count ].arg_count++ ] = script_property->element_size;
					hook_array[ hook_count ].arg_size_total += script_property->element_size;

					hook_array[ hook_count ].arg_size = ( int* )( realloc( hook_array[ hook_count ].arg_size, hook_array[ hook_count ].arg_count * 4 ) );
				}
			}

			script_function->set_function_flags( script_function->function_flags() | ScriptFunction::kFuncNative );
			script_function->set_function( Test );

			hook_count++;

			OutputLog( "Hooked function %s (0x%X)\n", function_name, script_function );
		}
		else
		{
			OutputLog( "Error: could not find function %s.\n", function_name );
		}
	}
}