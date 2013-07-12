#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrArenaMessage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrArenaMessage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrArenaMessage." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrArenaMessage : public UTLocalMessage
	{
	public:
			ADD_VAR( ::StrProperty, WeLostTheRound, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, WeWonTheRound, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, CannotSwitchTeam, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, NoRespawnsRemain, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Fight, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, YouAreLastManStanding, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, TeamRespawnsDepleted, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, FiveTeamRespawnsRemain, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, TenTeamRespawnsRemain, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
