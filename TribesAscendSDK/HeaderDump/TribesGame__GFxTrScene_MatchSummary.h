#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.GFxTrScene_MatchSummary." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.GFxTrScene_MatchSummary." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.GFxTrScene_MatchSummary." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrScene_MatchSummary : public GFxTrScene
	{
	public:
			ADD_VAR( ::BoolProperty, bUseSNS, 0x1 )
			int CreditsSort( class TrPlayerReplicationInfo* A, class TrPlayerReplicationInfo* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_MatchSummary.CreditsSort" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class TrPlayerReplicationInfo** )( params + 0 ) = A;
				*( class TrPlayerReplicationInfo** )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( TrSummaryHelper, SummaryHelper )
			ADD_VAR( ::IntProperty, Team2Score, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Team1Score, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MatchDate, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MatchDuration, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MatchGameType, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MatchMapId, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MatchId, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, WinningTeam, 0xFFFFFFFF )
			ADD_OBJECT( GFxObject, ScoreboardDataList )
			ADD_OBJECT( GFxObject, AccoladeDataList )
			ADD_OBJECT( GFxObject, AwardDataList )
			ADD_OBJECT( GFxObject, MiscDataList )
			ADD_VAR( ::IntProperty, ScoreboardDataCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AccoladeDataCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AwardDataCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MiscDataCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SCOREBOARD_SIZE, 0xFFFFFFFF )
			void Initialize(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_MatchSummary.Initialize" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearSummary(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_MatchSummary.ClearSummary" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SummaryReady(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_MatchSummary.SummaryReady" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LoadTeamStatsData( class GFxObject* List )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_MatchSummary.LoadTeamStatsData" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )( params + 0 ) = List;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LoadTeamAccoladeData( class GFxObject* List )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_MatchSummary.LoadTeamAccoladeData" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )( params + 0 ) = List;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LoadTeamScoreboardData( class GFxObject* List )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_MatchSummary.LoadTeamScoreboardData" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )( params + 0 ) = List;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LoadTeamMiscData( class GFxObject* List )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_MatchSummary.LoadTeamMiscData" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )( params + 0 ) = List;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddAward( int PlayerID, int AwardId, int val )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_MatchSummary.AddAward" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )( params + 0 ) = PlayerID;
				*( int* )( params + 4 ) = AwardId;
				*( int* )( params + 8 ) = val;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddAccolade( int PlayerID, int AccoladeId, int val )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_MatchSummary.AddAccolade" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )( params + 0 ) = PlayerID;
				*( int* )( params + 4 ) = AccoladeId;
				*( int* )( params + 8 ) = val;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddScoreSlot( ScriptArray< wchar_t > PlayerName, int Kills, int Assists, int Credits, int Rank )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_MatchSummary.AddScoreSlot" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = PlayerName;
				*( int* )( params + 12 ) = Kills;
				*( int* )( params + 16 ) = Assists;
				*( int* )( params + 20 ) = Credits;
				*( int* )( params + 24 ) = Rank;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddMiscData(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_MatchSummary.AddMiscData" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > FormatResult( int aWinningTeam )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_MatchSummary.FormatResult" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = aWinningTeam;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > FormatTime( int Seconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_MatchSummary.FormatTime" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Seconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > FindPlayerName( int PlayerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_MatchSummary.FindPlayerName" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = PlayerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void PopulateScoreboardDataFromGRI(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrScene_MatchSummary.PopulateScoreboardDataFromGRI" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
