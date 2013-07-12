#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.SVehicleSimCar." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.SVehicleSimCar." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.SVehicleSimCar." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SVehicleSimCar : public SVehicleSimBase
	{
	public:
			ADD_VAR( ::FloatProperty, TimeSinceThrottle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ActualSteering, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsDriving, 0x1 )
			ADD_VAR( ::FloatProperty, StopThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxBrakeTorque, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EngineBrakeFactor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ReverseThrottle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SteerSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ChassisTorqueScale, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
