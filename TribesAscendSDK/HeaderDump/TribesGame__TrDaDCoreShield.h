#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrDaDCoreShield." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrDaDCoreShield." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrDaDCoreShield." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDaDCoreShield : public DynamicSMActor
	{
	public:
			ADD_OBJECT( TrDaDShell, m_Shell )
			ADD_VAR( ::IntProperty, m_nShieldIndex, 0xFFFFFFFF )
			ADD_OBJECT( TrDaDCore, m_Core )
			ADD_OBJECT( Material, m_BaseMaterial )
			ADD_VAR( ::ByteProperty, m_DefenderTeamIndex, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
