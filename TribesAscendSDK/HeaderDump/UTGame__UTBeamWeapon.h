#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.UTBeamWeapon." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.UTBeamWeapon." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.UTBeamWeapon." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTBeamWeapon : public UTWeapon
	{
	public:
			ADD_OBJECT( ForceFeedbackWaveform, BeamWeaponFireWaveForm )
			ADD_VAR( ::NameProperty, BeamPostFireAnim, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, BeamFireAnim, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, BeamPreFireAnim, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, EndPointParamName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, BeamSockets, 0xFFFFFFFF )
			ADD_OBJECT( ParticleSystem, BeamTemplate )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
