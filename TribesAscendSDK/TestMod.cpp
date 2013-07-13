#include <Windows.h>
#include "TASDK.h"

const char *kLogName = "SDKTest.log";

using namespace UnrealScript;

HookType ProcessMove( TrPlayerController *controller, void *result, float delta_time, Vector new_accel, byte double_click_dir, ShortRotator delta_rot )
{
	OutputLog( "delta_time: %f\n", delta_time );

	return kHookContinue;
}

void ModInit()
{
	/*OutputLog( "ScriptObject offsets:\n" );
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
	OutputLog( "\n" );*/

	script_hooks::AddHook( "Function TribesGame.TrPlayerController.PlayerWalking.ProcessMove", ProcessMove );
}