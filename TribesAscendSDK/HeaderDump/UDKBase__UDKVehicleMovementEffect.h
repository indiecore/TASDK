#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UDKBase.UDKVehicleMovementEffect." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UDKBase.UDKVehicleMovementEffect." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UDKBase.UDKVehicleMovementEffect." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKVehicleMovementEffect : public Actor
	{
	public:
			ADD_VAR( ::FloatProperty, AirCurrentLevel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AirMaxDelta, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, AirEffectScalar, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxVelocityForAirEffect, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinVelocityForAirEffect, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
