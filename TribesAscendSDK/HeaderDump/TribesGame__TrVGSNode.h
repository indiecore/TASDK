#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrVGSNode." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrVGSNode." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrVGSNode." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrVGSNode : public Object
	{
	public:
			ADD_VAR( ::BoolProperty, m_bDrawHeader, 0x10 )
			ADD_VAR( ::StrProperty, m_MenuString, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, m_KeyBind, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bIgnoreCaH, 0x8 )
			ADD_VAR( ::BoolProperty, m_bIgnoreArena, 0x4 )
			ADD_VAR( ::BoolProperty, m_bIgnoreTeamRabbit, 0x2 )
			ADD_VAR( ::BoolProperty, m_bIgnoreCTF, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
