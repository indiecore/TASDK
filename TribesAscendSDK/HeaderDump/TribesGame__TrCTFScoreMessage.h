#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrCTFScoreMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrCTFScoreMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrCTFScoreMessage." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrCTFScoreMessage : public UTLocalMessage
	{
	public:
			ADD_VAR( ::StrProperty, TeamHigherScore, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PlayerHattrick, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Team1JustGotAhead, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Team0JustGotAhead, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Team1LeadingBy2, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Team0LeadingBy2, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Team1Scored, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Team0Scored, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ScoreNone, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PreScoreNone, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ScoreBlue, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PreScoreBlue, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ScoreRed, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PreScoreRed, 0xFFFFFFFF )
			ADD_OBJECT( SoundNodeWave, TeamScoreSounds )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
