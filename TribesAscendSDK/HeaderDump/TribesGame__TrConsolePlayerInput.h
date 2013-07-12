#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrConsolePlayerInput." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrConsolePlayerInput." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrConsolePlayerInput." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrConsolePlayerInput : public TrPlayerInput
	{
	public:
			ADD_VAR( ::FloatProperty, HoverBoardPitchMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AutoPitchStopAdjustingValue, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AutoPitchCenterSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ViewAccel_BackToCenterSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ViewAccel_BackToCenterBoundary, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ViewAccel_LookingUpOrDownBoundary, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ViewAccel_PitchThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ViewAccel_MaxTurnSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ViewAccel_RampSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MagicScaleForSensitivityEdge, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MagicScaleForSensitivityMiddle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RightThumbStickDeadZoneThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LeftThumbStickDeadZoneThreshold, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, LastDeltaRot, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastCamLoc, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastAdjustZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastAdjustY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastDistFromAimZa, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastDistFromAimYa, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastTargetHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastTargetRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastAdhesionAmtZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastAdhesionAmtY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastFrictionMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastDistFromAimY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastDistFromAimZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastDistMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastDistToTarget, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastFrictionTargetTime, 0xFFFFFFFF )
			ADD_OBJECT( Pawn, LastFrictionTarget )
			ADD_VAR( ::FloatProperty, Dodge_Threshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ViewAccel_Twitchy, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ViewAccel_TimeHeld, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ViewAccel_TimeToHoldBeforeFastAcceleration, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ViewAccel_CurrMutliplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ViewAccel_BaseMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ViewAccel_DiagonalThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ViewAccel_YawThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SlowTurnScaling, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AutoVehicleCenterSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AutoCenterDelay, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastTurnTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsLookingDown, 0x100 )
			ADD_VAR( ::BoolProperty, bIsLookingUp, 0x80 )
			ADD_VAR( ::BoolProperty, bAppliedTargetFriction, 0x40 )
			ADD_VAR( ::BoolProperty, bDebugTargetFriction, 0x20 )
			ADD_VAR( ::BoolProperty, bTargetFrictionEnabled, 0x10 )
			ADD_VAR( ::BoolProperty, bDebugViewAcceleration, 0x8 )
			ADD_VAR( ::BoolProperty, bViewAccelerationEnabled, 0x4 )
			ADD_VAR( ::BoolProperty, bAutoCenterVehiclePitch, 0x2 )
			ADD_VAR( ::BoolProperty, bAutoCenterPitch, 0x1 )
			ADD_VAR( ::FloatProperty, TurningAccelerationMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SensitivityMultiplier, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
