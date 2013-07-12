#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrCollisionProxy." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrCollisionProxy." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrCollisionProxy." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrCollisionProxy : public Actor
	{
	public:
			ADD_VAR( ::BoolProperty, m_bTrackLocallyControlledPawnsOnly, 0x20 )
			ADD_VAR( ::BoolProperty, m_bForwardOwnerOnly, 0x10 )
			ADD_VAR( ::BoolProperty, m_bIgnoreInvulnerablePlayers, 0x8 )
			ADD_VAR( ::BoolProperty, m_bIgnoreHackedPawns, 0x4 )
			ADD_VAR( ::BoolProperty, m_bIgnoreNonPlayers, 0x2 )
			ADD_VAR( ::BoolProperty, m_bIgnoreStealthPlayers, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
