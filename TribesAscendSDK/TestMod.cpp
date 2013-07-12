#include <Windows.h>
#include "TASDK.h"

const char *kLogName = "SDKTest.log";

using namespace UnrealScript;

#define M_PI ( float )( 3.14159f )
void AngleVectors( Rotator angles, Vector &forward, Vector &right, Vector &up )
{
	float	 angle;
	float	 sr, sp, sy, cr, cp, cy;

	angle = angles.y * (M_PI*2 / 360);
	sy = sin(angle);
	cy = cos(angle);
	angle = angles.x * (M_PI*2 / 360);
	sp = sin(angle);
	cp = cos(angle);
	angle = angles.z * (M_PI*2 / 360);
	sr = sin(angle);
	cr = cos(angle);

	//if (forward)
	//{
		forward.x = cp*cy;
		forward.y = cp*sy;
		forward.z = -sp;
	//}
	//if (right)
	//{
		right.x = (-1*sr*sp*cy+-1*cr*-sy);
		right.y = (-1*sr*sp*sy+-1*cr*cy);
		right.z = -1*sr*cp;
	//}
	//if (up)
	//{
		up.x = (cr*sp*cy+-sr*-sy);
		up.y = (cr*sp*sy+-sr*cy);
		up.z = cr*cp;
	//}
}

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

	script_hooks::AddHook( "Function TribesGame.TrDevice.GetReloadTime", ProcessMove );
}