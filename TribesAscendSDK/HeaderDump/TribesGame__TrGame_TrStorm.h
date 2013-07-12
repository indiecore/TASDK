#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrGame_TrStorm." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrGame_TrStorm." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrGame_TrStorm." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrGame_TrStorm : public TrGame
	{
	public:
			ADD_VAR( ::FloatProperty, MatchEndingTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nMaxCoreHealth, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nMaxShieldHealth, 0xFFFFFFFF )
			ADD_OBJECT( TrStormCore, m_CarrierCore )
			ADD_OBJECT( TrStormCarrierShield, m_CarrierShields )
			ADD_VAR( ::FloatProperty, m_fMissileDamageAmount, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
