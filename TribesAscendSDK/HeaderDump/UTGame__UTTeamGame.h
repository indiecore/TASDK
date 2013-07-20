#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTTeamGame." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTTeamGame." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTTeamGame." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTTeamGame : public UTDeathmatch
	{
	public:
			ADD_VAR( ::NameProperty, FlagKillMessageName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SwapRequestTime, 0xFFFFFFFF )
			ADD_OBJECT( PlayerController, PendingTeamSwap )
			ADD_OBJECT( ScriptClass, TeamScoreMessageClass )
			ADD_VAR( ::StrProperty, TeamFactions, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, TeamAIType )
			ADD_OBJECT( UTTeamInfo, Teams )
			ADD_VAR( ::FloatProperty, TeammateBoost, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FriendlyFireScale, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bForceAllRed, 0x20 )
			ADD_VAR( ::BoolProperty, bScoreVictimsTarget, 0x10 )
			ADD_VAR( ::BoolProperty, bSpawnInTeamArea, 0x8 )
			ADD_VAR( ::BoolProperty, bScoreTeamKills, 0x4 )
			ADD_VAR( ::BoolProperty, bAllowNonTeamChat, 0x2 )
			ADD_VAR( ::BoolProperty, bPlayersBalanceTeams, 0x1 )
			void PreBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.PreBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostLogin( class PlayerController* NewPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.PostLogin" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )params = NewPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FindNewObjectives( class UTGameObjective* DisabledObjective )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.FindNewObjectives" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTGameObjective** )params = DisabledObjective;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CreateTeam( int TeamIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.CreateTeam" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = TeamIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetHandicapNeed( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.GetHandicapNeed" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			class UTTeamInfo* GetBotTeam( int TeamBots, bool bUseTeamIndex, int TeamIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.GetBotTeam" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = TeamBots;
				*( bool* )( params + 4 ) = bUseTeamIndex;
				*( int* )( params + 8 ) = TeamIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTTeamInfo** )( params + function->return_val_offset() );
			}

			int LevelRecommendedPlayers(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.LevelRecommendedPlayers" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool CheckMaxLives( class PlayerReplicationInfo* Scorer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.CheckMaxLives" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )params = Scorer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void InitGame( ScriptArray< wchar_t > Options, ScriptArray< wchar_t > &ErrorMessage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.InitGame" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = Options;
				*( ScriptArray< wchar_t >* )( params + 12 ) = ErrorMessage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ErrorMessage = *( ScriptArray< wchar_t >* )( params + 12 );
			}

			bool TooManyBots( class Controller* botToRemove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.TooManyBots" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )params = botToRemove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void NotifyKilled( class Controller* Killer, class Controller* KilledPlayer, class Pawn* KilledPawn, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.NotifyKilled" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Controller** )params = Killer;
				*( class Controller** )( params + 4 ) = KilledPlayer;
				*( class Pawn** )( params + 8 ) = KilledPawn;
				*( ScriptClass** )( params + 12 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CheckEndGame( class PlayerReplicationInfo* Winner, ScriptArray< wchar_t > Reason )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.CheckEndGame" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class PlayerReplicationInfo** )params = Winner;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Reason;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetEndGameFocus( class PlayerReplicationInfo* Winner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.SetEndGameFocus" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )params = Winner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanSpectate( class PlayerController* Viewer, class PlayerReplicationInfo* ViewTarget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.CanSpectate" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerController** )params = Viewer;
				*( class PlayerReplicationInfo** )( params + 4 ) = ViewTarget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void RestartGame(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.RestartGame" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte PickTeam( byte Num, class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.PickTeam" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = Num;
				*( class Controller** )( params + 4 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			bool ChangeTeam( class Controller* Other, int Num, bool bNewTeam )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.ChangeTeam" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class Controller** )params = Other;
				*( int* )( params + 4 ) = Num;
				*( bool* )( params + 8 ) = bNewTeam;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetTeam( class Controller* Other, class UTTeamInfo* NewTeam, bool bNewTeam )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.SetTeam" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class Controller** )params = Other;
				*( class UTTeamInfo** )( params + 4 ) = NewTeam;
				*( bool* )( params + 8 ) = bNewTeam;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float RatePlayerStart( class PlayerStart* P, byte Team, class Controller* Player )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.RatePlayerStart" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( class PlayerStart** )params = P;
				*( byte* )( params + 4 ) = Team;
				*( class Controller** )( params + 8 ) = Player;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool CheckScore( class PlayerReplicationInfo* Scorer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.CheckScore" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )params = Scorer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class Pawn* FindVictimsTarget( class Controller* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.FindVictimsTarget" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Pawn** )( params + function->return_val_offset() );
			}

			bool NearGoal( class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.NearGoal" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )params = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ScoreKill( class Controller* Killer, class Controller* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.ScoreKill" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )params = Killer;
				*( class Controller** )( params + 4 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CampaignSkillAdjust( class UTBot* aBot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.CampaignSkillAdjust" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )params = aBot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AdjustSkill( class AIController* B, class PlayerController* P, bool bWinner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.AdjustSkill" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class AIController** )params = B;
				*( class PlayerController** )( params + 4 ) = P;
				*( bool* )( params + 8 ) = bWinner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendFlagKillMessage( class Controller* Killer, class UTPlayerReplicationInfo* KillerPRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.SendFlagKillMessage" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )params = Killer;
				*( class UTPlayerReplicationInfo** )( params + 4 ) = KillerPRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool DominatingVictory(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.DominatingVictory" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsAWinner( class PlayerController* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.IsAWinner" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )params = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsWinningTeam( class TeamInfo* T )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.IsWinningTeam" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TeamInfo** )params = T;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PlayRegularEndOfMatchMessage(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.PlayRegularEndOfMatchMessage" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AnnounceScore( int ScoringTeam )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.AnnounceScore" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ScoringTeam;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OverridePRI( class PlayerController* PC, class PlayerReplicationInfo* OldPRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.OverridePRI" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerController** )params = PC;
				*( class PlayerReplicationInfo** )( params + 4 ) = OldPRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AllowClientToTeleport( class UTPlayerReplicationInfo* ClientPRI, class Actor* DestinationActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.AllowClientToTeleport" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTPlayerReplicationInfo** )params = ClientPRI;
				*( class Actor** )( params + 4 ) = DestinationActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ShowPathTo( class PlayerController* P, int TeamNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.ShowPathTo" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerController** )params = P;
				*( int* )( params + 4 ) = TeamNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetSeamlessTravelActorList( bool bToEntry )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.GetSeamlessTravelActorList" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( bool* )params = bToEntry;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Logout( class Controller* Exiting )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.Logout" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )params = Exiting;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HandleSeamlessTravelPlayer( class Controller* &C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.HandleSeamlessTravelPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )params = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				C = *( class Controller** )params;
			}

			void ParseSpeechRecipients( class UTPlayerController* Speaker )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.ParseSpeechRecipients" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class UTPlayerController** )params = Speaker;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProcessSpeechOrders( class UTPlayerController* Speaker )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.ProcessSpeechOrders" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class UTPlayerController** )params = Speaker;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProcessSpeechRecognition( class UTPlayerController* Speaker )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTTeamGame.ProcessSpeechRecognition" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class UTPlayerController** )params = Speaker;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
