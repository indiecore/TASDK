#include <Windows.h>
#include "TASDK.h"

const char *kLogName = "SDKTest.log";

using namespace UnrealScript;

HookType ProcessMove( TrPlayerController *controller, int num_params, void *result, float delta_time )
{
	OutputLog( "delta time: %f\n", delta_time );
	return kHookContinue;
}

void ModInit()
{
	ScriptObject *test = ScriptObject::object_array()->data()[ 0 ];
	OutputLog( "ScriptObject offsets:\n" );
	OutputLog( "object_internal_integer: 0x%X\n", offsetof( ScriptObject, object_internal_integer_ ) );
	OutputLog( "object_flags: 0x%X\n", offsetof( ScriptObject, object_flags_ ) );
	OutputLog( "hash_next: 0x%X\n", offsetof( ScriptObject, hash_next_ ) );
	OutputLog( "hash_outer_next: 0x%X\n", offsetof( ScriptObject, hash_outer_next_ ) );
	OutputLog( "state_frame: 0x%X\n", offsetof( ScriptObject, state_frame_ ) );
	OutputLog( "linker: 0x%X\n", offsetof( ScriptObject, linker_ ) );
	OutputLog( "linker_index: 0x%X\n", offsetof( ScriptObject, linker_index_ ) );
	OutputLog( "net_index: 0x%X\n", offsetof( ScriptObject, net_index_ ) );
	OutputLog( "outer: 0x%X\n", offsetof( ScriptObject, outer_ ) );
	OutputLog( "name: 0x%X\n", offsetof( ScriptObject, name_ ) );
	OutputLog( "object_class: 0x%X\n", offsetof( ScriptObject, object_class_ ) );
	OutputLog( "object_archetype: 0x%X\n", offsetof( ScriptObject, object_archetype_ ) );
	OutputLog( "\n" );

	OutputLog( "ScriptStackFrame offsets:\n" );
	OutputLog( "node: 0x%X\n", offsetof( ScriptStackFrame, node ) );
	OutputLog( "object: 0x%X\n", offsetof( ScriptStackFrame, object ) );
	OutputLog( "code: 0x%X\n", offsetof( ScriptStackFrame, code ) );
	OutputLog( "locals: 0x%X\n", offsetof( ScriptStackFrame, locals ) );
	OutputLog( "\n" );

	script_hooks::AddHook( "Function TribesGame.TrDevice.GetReloadTime", ProcessMove ); //This is like this because GetReloadTime is a script->script
																						//call and it's easy to compare the bytecode to what it should
																						//be in the UPK.

																						//Hooks aren't working because ScriptStackFrame::code gives garbage data.
																						
}