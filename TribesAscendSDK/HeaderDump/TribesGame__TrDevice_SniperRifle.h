#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrDevice_SniperRifle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrDevice_SniperRifle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrDevice_SniperRifle." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDevice_SniperRifle : public TrDevice
	{
	public:
			ADD_VAR( ::FloatProperty, m_fDivCoeff, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMultCoeff, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fAimChargeTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAimChargeDeltaTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxAimedDamage, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
