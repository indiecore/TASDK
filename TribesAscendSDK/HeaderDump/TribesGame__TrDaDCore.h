#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrDaDCore." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrDaDCore." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrDaDCore." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDaDCore : public TrGameObjective
	{
	public:
			ADD_OBJECT( TrDaDShell, m_Shell )
			ADD_OBJECT( TrDaDCoreShield, m_Shields )
			ADD_OBJECT( TrDaDCapacitor, m_Capacitors )
			ADD_VAR( ::FloatProperty, m_fShieldBarPlacementY, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, m_ShieldBarMIC )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
