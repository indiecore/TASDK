#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrDaDMessage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrDaDMessage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrDaDMessage." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDaDMessage : public UTLocalMessage
	{
	public:
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
