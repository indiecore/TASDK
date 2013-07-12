#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrSavedMove." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrSavedMove." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrSavedMove." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrSavedMove : public SavedMove
	{
	public:
			ADD_VAR( ::ByteProperty, m_CurrentDecelerationFactor, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bBlink, 0x8 )
			ADD_VAR( ::BoolProperty, m_bJumpJet, 0x4 )
			ADD_VAR( ::BoolProperty, m_bPressingJetpack, 0x2 )
			ADD_VAR( ::BoolProperty, m_bAirSpeedBoundToGroundSpeed, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
