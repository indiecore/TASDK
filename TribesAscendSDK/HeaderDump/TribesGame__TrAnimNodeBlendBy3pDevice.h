#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrAnimNodeBlendBy3pDevice." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrAnimNodeBlendBy3pDevice." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrAnimNodeBlendBy3pDevice." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrAnimNodeBlendBy3pDevice : public TrAnimNodeBlendList
	{
	public:
			ADD_VAR( ::NameProperty, m_StandardReloadAnimName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, m_SkiingReloadName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, m_StandardFireAnimName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, m_SkiingFireName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRefireTimePreview, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bCurrentDeviceSupportsAltSkiReloadAnims, 0x10 )
			ADD_VAR( ::BoolProperty, m_bCurrentDeviceSupportsAltSkiFireAnims, 0x8 )
			ADD_VAR( ::BoolProperty, m_bScalePutawayRetrieveAnims, 0x4 )
			ADD_VAR( ::BoolProperty, m_bFirePreview, 0x2 )
			ADD_VAR( ::BoolProperty, m_bScaleFireByRefireTime, 0x1 )
			ADD_OBJECT( TrPawn, m_TrPawn )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
