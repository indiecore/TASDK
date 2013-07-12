#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrDevice_LightAssaultRifle." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrDevice_LightAssaultRifle." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrDevice_LightAssaultRifle." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDevice_LightAssaultRifle : public TrDevice_AssaultRifle
	{
	public:
			ADD_VAR( ::FloatProperty, m_fBurtShotRefireTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bHoldingFire, 0x1 )
			ADD_VAR( ::IntProperty, m_nShotsSoFar, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nShotBurstCount, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
