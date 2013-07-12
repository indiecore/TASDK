#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrEffect_Sensor." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrEffect_Sensor." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrEffect_Sensor." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrEffect_Sensor : public TrEffect_Managed
	{
	public:
			ADD_VAR( ::BoolProperty, m_bSeeLowHealthEnemy, 0x20 )
			ADD_VAR( ::BoolProperty, m_bSeeStealthedEnemy, 0x10 )
			ADD_VAR( ::BoolProperty, m_bSeeNormalEnemy, 0x8 )
			ADD_VAR( ::BoolProperty, m_bDisplayForeground, 0x4 )
			ADD_VAR( ::BoolProperty, m_bDisplayInGame, 0x2 )
			ADD_VAR( ::BoolProperty, m_bRequiresLOS, 0x1 )
			ADD_VAR( ::FloatProperty, m_fScannerRange, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fScannerFOV, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
