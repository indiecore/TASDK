#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKVehicleSimCar." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKVehicleSimCar." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKVehicleSimCar." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKVehicleSimCar : public SVehicleSimCar
	{
	public:
			ADD_VAR( ::FloatProperty, InAirUprightMaxTorque, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, InAirUprightTorqueFactor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AirControlTurnTorque, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpeedBasedTurnDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ConsoleHardTurnGripFactor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FrontalCollisionGripFactor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ActualHandbrake, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HandbrakeSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HardTurnMotorTorque, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinHardTurnSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SteeringReductionMinSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SteeringReductionSpeed, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumWheelsForFullSteering, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentSteeringReduction, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SteeringReductionRampUpRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SteeringReductionFactor, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAutoHandbrake, 0x8 )
			ADD_VAR( ::BoolProperty, bDriverlessBraking, 0x4 )
			ADD_VAR( ::BoolProperty, bHasForcedThrottle, 0x2 )
			ADD_VAR( ::BoolProperty, bForceThrottle, 0x1 )
			ADD_VAR( ::FloatProperty, ActualThrottle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxRPM, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinRPM, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ThrottleSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LSDFactor, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
