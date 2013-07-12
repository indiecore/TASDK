#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrAnimNodeBlendByGravCycleTilt." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrAnimNodeBlendByGravCycleTilt." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrAnimNodeBlendByGravCycleTilt." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrAnimNodeBlendByGravCycleTilt : public AnimNodeBlendBase
	{
	public:
			ADD_VAR( ::FloatProperty, m_fDeadZone, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, m_RootBoneName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTiltScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTiltAmount, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
