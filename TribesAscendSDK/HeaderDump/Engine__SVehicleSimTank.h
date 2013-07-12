#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.SVehicleSimTank." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.SVehicleSimTank." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.SVehicleSimTank." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SVehicleSimTank : public SVehicleSimCar
	{
	public:
			ADD_VAR( ::BoolProperty, bTurnInPlaceOnSteer, 0x1 )
			ADD_VAR( ::FloatProperty, TurnGripScaleRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TurnMaxGripReduction, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TurnInPlaceThrottle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SteeringLatStiffnessFactor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, InsideTrackTorqueFactor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EngineDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxEngineTorque, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RightTrackTorque, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LeftTrackTorque, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RightTrackVel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LeftTrackVel, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
