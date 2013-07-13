#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKVehicleSimChopper." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKVehicleSimChopper." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKVehicleSimChopper." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKVehicleSimChopper : public SVehicleSimBase
	{
	public:
			ADD_VAR( ::FloatProperty, HardLimitAirSpeedScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StoppedBrakeTorque, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, OldVelocity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentStabilizationMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StabilizationForceMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AccumulatedTime, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, RandTorque, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, RandForce, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PitchViewCorrelation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetPitch, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetHeading, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StrafeTurnDamping, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bStabilizeStops, 0x40 )
			ADD_VAR( ::BoolProperty, bHeadingInitialized, 0x20 )
			ADD_VAR( ::BoolProperty, bStrafeAffectsTurnDamping, 0x10 )
			ADD_VAR( ::BoolProperty, bRecentlyHit, 0x8 )
			ADD_VAR( ::BoolProperty, bShouldCutThrustMaxOnImpact, 0x4 )
			ADD_VAR( ::BoolProperty, bFullThrustOnDirectionChange, 0x2 )
			ADD_VAR( ::BoolProperty, bAllowZThrust, 0x1 )
			ADD_VAR( ::FloatProperty, RandForceInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxRandForce, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StopThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RollDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RollTorqueMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RollTorqueStrafeFactor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RollTorqueTurnFactor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PitchDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PitchTorqueMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PitchTorqueFactor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxYawRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TurnDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TurnTorqueMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TurnTorqueFactor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, UpDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxRiseForce, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DirectionChangeForce, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LatDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxStrafeForce, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LongDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxReverseForce, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxThrustForce, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
