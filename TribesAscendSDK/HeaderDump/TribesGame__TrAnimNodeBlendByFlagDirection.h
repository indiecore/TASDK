#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrAnimNodeBlendByFlagDirection." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrAnimNodeBlendByFlagDirection." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrAnimNodeBlendByFlagDirection." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrAnimNodeBlendByFlagDirection : public TrAnimNodeBlendList
	{
	public:
			ADD_VAR( ::FloatProperty, m_fIdleBlendOutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fIdleBlendInTime, 0xFFFFFFFF )
			ADD_OBJECT( AnimNodeAdditiveBlending, m_AdditiveBlendNode )
			ADD_VAR( ::NameProperty, m_nmAdditiveAnimNodeName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fIdleSpeedSizeSq, 0xFFFFFFFF )
			ADD_OBJECT( TrFlagBase, m_TrFlagOwner )
			ADD_VAR( ::ByteProperty, LastDirection, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
