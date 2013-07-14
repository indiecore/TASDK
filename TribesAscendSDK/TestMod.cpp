#include "TASDK.h"
#include "Armor.h"

const char *kLogName = "SDKTest.log";

using namespace UnrealScript;

#define M_PI ( float )( 3.14159f )
void AngleVectors( ShortRotator angles, Vector &forward, Vector &right, Vector &up )
{
	float	 angle;
	float	 sr, sp, sy, cr, cp, cy;

	angle = angles.y * (M_PI*2 / 65535);
	sy = sin(angle);
	cy = cos(angle);
	angle = angles.x * (M_PI*2 / 65535);
	sp = sin(angle);
	cp = cos(angle);
	angle = angles.z * (M_PI*2 / 65535);
	sr = sin(angle);
	cr = cos(angle);

	//if (forward)
	//{
		forward.x = cp*cy;
		forward.y = cp*sy;
		forward.z = sp;
	//}
	//if (right)
	//{
		right.x = (-1*sr*sp*cy+-1*cr*-sy);
		right.y = (-1*sr*sp*sy+-1*cr*cy);
		right.z = sr*cp;
	//}
	//if (up)
	//{
		up.x = (cr*sp*cy+-sr*-sy);
		up.y = (cr*sp*sy+-sr*cy);
		up.z = -cr*cp;
	//}
}

inline float MetersToUnits( float meters )
{
	return meters * 50.0f;
}

struct ProcessMove_Params
{
	float delta_time;
	Vector new_accel;
	byte double_click_move;
	ShortRotator delta_rotation;
};

HookType PlayerMove( TrPlayerController *controller, void *result, float delta_time )
{
	OutputLog( "delta_time: %f\n", delta_time );

	TrPawn *pawn = ( TrPawn* )( controller->var_Pawn() );
	pawn->var_CustomGravityScaling() = 0.0f;

	pawn->var_Velocity() = ( Vector )( pawn->var_Velocity() ) + Vector( 0, 0, MetersToUnits( -22.0f ) ) * delta_time;

	if( controller->var_m_bPressingJetpack() )
	{
		Vector forward, right, up;

		ShortRotator rotation = controller->var_Rotation();
		rotation.x = 0.0f;

		AngleVectors( rotation, forward, right, up );

		OutputLog( "forward: %f %f %f\n", forward.x, forward.y, forward.z );
		OutputLog( "right: %f %f %f\n", right.x, right.y, right.z );

		Vector move_direction;
		move_direction += controller->var_PlayerInput()->var_aForward() * forward;
		move_direction += controller->var_PlayerInput()->var_aStrafe() * right * -1;
		OutputLog( "move direction: %f %f %f\n", move_direction.x, move_direction.y, move_direction.z );

		if( move_direction.Length() )
			move_direction = move_direction.GetNormal();

		OutputLog( "move direction: %f %f %f\n", move_direction.x, move_direction.y, move_direction.z );

		Vector velocity = controller->var_Pawn()->var_Velocity();
		float orientation = velocity.DotProduct( move_direction );
		
		float side_power;
		float jet_forward = MetersToUnits( LightArmor::jet_data.jet_forward );
		if( orientation > jet_forward )
			side_power = 0.0f;
		else if( orientation < 0.0f )
			side_power = LightArmor::jet_data.jet_side_pct;
		else
			side_power = ( 1 - ( orientation / jet_forward ) );

		side_power = min( side_power, LightArmor::jet_data.jet_side_pct );

		float jet_force = MetersToUnits( LightArmor::jet_data.jet_force );
		Vector side_force = ( side_power * jet_force ) * move_direction;
		Vector up_force = Vector( 0, 0, ( ( 1 - side_power ) * jet_force ) );

		Vector accel = up_force + side_force;
		OutputLog( "accel: %f %f %f\n", accel.x, accel.y, accel.z );

		pawn->var_Velocity() = velocity + accel * delta_time;

		return kHookContinue;
	}

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

	script_hooks::AddHook( "Function TribesGame.TrPlayerController.PlayerWalking.PlayerMove", PlayerMove );
}