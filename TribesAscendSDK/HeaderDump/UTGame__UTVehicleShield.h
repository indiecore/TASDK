#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTVehicleShield." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTVehicleShield." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTVehicleShield." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTVehicleShield : public UDKWeaponShield
	{
	public:
			ADD_VAR( ::BoolProperty, bFullyActive, 0x1 )
			ADD_VAR( ::FloatProperty, ShieldActivatedTime, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, DeactivatedSound )
			ADD_OBJECT( SoundCue, ActivatedSound )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
