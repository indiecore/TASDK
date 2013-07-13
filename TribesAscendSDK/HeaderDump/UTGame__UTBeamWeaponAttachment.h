#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTBeamWeaponAttachment." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTBeamWeaponAttachment." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTBeamWeaponAttachment." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTBeamWeaponAttachment : public UTWeaponAttachment
	{
	public:
			ADD_VAR( ::NameProperty, EndPointParamName, 0xFFFFFFFF )
			ADD_OBJECT( UTPawn, PawnOwner )
			ADD_VAR( ::NameProperty, BeamSockets, 0xFFFFFFFF )
			ADD_OBJECT( ParticleSystem, BeamTemplate )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
