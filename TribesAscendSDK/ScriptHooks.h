#pragma once

//RegisterNative is sub_4AF670 in TA dev

//from constructor at sub_4BDBD0
//node is +0x10
//object is +0x14
//code is +0x18
//locals is +0x1C
//previous_frame is +0x20
struct ScriptStackFrame
{
	byte __padding__[ 0x10 ];

	ScriptStruct *node;
	ScriptObject *object;
	byte *code;
	byte *locals;

	ScriptStackFrame *previous_frame;

	template< class T > T GetArg()
	{
		void *result = malloc( sizeof( T ) );
		script_hooks::native_array[ *code++ ]( object, *this, result );
		T ret_val = *( T* )( result );
		free( result );
		return ret_val;
	}
};

enum HookType
{
	kHookContinue,
	kHookBlock
};

typedef void( __thiscall *NativeFunction )( void *thisptr, ScriptStackFrame &stack, void *result );
typedef HookType( *HookFunction )( void *object, void *result, byte *args );
typedef void( __stdcall *CleanupStack )( ScriptStackFrame &stack, void *result, ScriptFunction *function );
typedef void( __thiscall *CallFunction )( void  *thisptr, ScriptStackFrame &stack, void *result, ScriptFunction *function );

namespace script_hooks
{
	extern NativeFunction *native_array;
	extern CleanupStack cleanup_stack;
	extern CallFunction call_function;

	void AddHook( char *function_name, void *function );
}