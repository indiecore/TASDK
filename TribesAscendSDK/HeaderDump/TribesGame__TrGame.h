#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrGame." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrGame." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrGame." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrGame : public UTTeamGame
	{
	public:
			ADD_OBJECT( TrStatsInterface, Stats )
			ADD_VAR( ::BoolProperty, bFirstBloodAchieved, 0x8 )
			ADD_VAR( ::FloatProperty, m_fFriendlyFireDamageScale, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bRoamingMap, 0x200 )
			bool RequestTeam( byte RequestedTeamNum, class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.RequestTeam" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = RequestedTeamNum;
				*( class Controller** )( params + 4 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AutoAssignTeam( class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.AutoAssignTeam" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )params = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AllowRespawn( class TrPlayerController* TrPC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.AllowRespawn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPlayerController** )params = TrPC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, m_fForcedRespawnTime, 0xFFFFFFFF )
			bool CanEnterSpectate( class TrPlayerController* TrPC, bool bNeutral )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.CanEnterSpectate" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class TrPlayerController** )params = TrPC;
				*( bool* )( params + 4 ) = bNeutral;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( TrSeekingMissileManager, m_SeekingMissileManager )
			int CreditsSortViaPC( class PlayerController* A, class PlayerController* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.CreditsSortViaPC" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerController** )params = A;
				*( class PlayerController** )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int CreditSort( class PlayerReplicationInfo* A, class PlayerReplicationInfo* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.CreditSort" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerReplicationInfo** )params = A;
				*( class PlayerReplicationInfo** )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int ScoreSort( class PlayerReplicationInfo* A, class PlayerReplicationInfo* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.ScoreSort" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerReplicationInfo** )params = A;
				*( class PlayerReplicationInfo** )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, m_nMinNetPlayers, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nRoundCountdownRemainingTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nRoundCountdownTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nAutoBalanceTeamDifference, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAutoBalanceTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nPlayerTrackingInterval, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nPlayerTrackingCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CountdownWait, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SummaryWait, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, EndGameWait, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MINIMUM_CREDITS_FOR_EXPERIENCE, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_OvertimeTimeLimit, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nNextEffectInstanceId, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nEndMatchCounter, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nWinningTeam, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_sWinnerName, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bShouldAutoBalance, 0x100 )
			ADD_VAR( ::BoolProperty, PlayedEndOfGame, 0x80 )
			ADD_VAR( ::BoolProperty, bPlayedDSWinning, 0x40 )
			ADD_VAR( ::BoolProperty, bPlayedBEWinning, 0x20 )
			ADD_VAR( ::BoolProperty, bPlayTeamAudio, 0x10 )
			ADD_VAR( ::BoolProperty, bForceRoundStart, 0x4 )
			ADD_VAR( ::BoolProperty, bForceEndGame, 0x2 )
			ADD_VAR( ::BoolProperty, m_bPostedStats, 0x1 )
			int GetNextEffectInstanceId(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.GetNextEffectInstanceId" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void LocalLeaveGame(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.LocalLeaveGame" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnServerInitialized(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.OnServerInitialized" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetOnlinePlayerName( class PlayerReplicationInfo* PRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.SetOnlinePlayerName" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )params = PRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ApplyServerSettings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.ApplyServerSettings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReduceDamage( int &Damage, class Pawn* injured, class Controller* InstigatedBy, Vector HitLocation, Vector &Momentum, ScriptClass* DamageType, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.ReduceDamage" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( int* )params = Damage;
				*( class Pawn** )( params + 4 ) = injured;
				*( class Controller** )( params + 8 ) = InstigatedBy;
				*( Vector* )( params + 12 ) = HitLocation;
				*( Vector* )( params + 24 ) = Momentum;
				*( ScriptClass** )( params + 36 ) = DamageType;
				*( class Actor** )( params + 40 ) = DamageCauser;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Damage = *( int* )params;
				Momentum = *( Vector* )( params + 24 );
			}

			void PreBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.PreBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddInitialBots(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.AddInitialBots" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class UTBot* AddBot( ScriptArray< wchar_t > BotName, bool bUseTeamIndex, int TeamIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.AddBot" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptArray< wchar_t >* )params = BotName;
				*( bool* )( params + 12 ) = bUseTeamIndex;
				*( int* )( params + 16 ) = TeamIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTBot** )( params + function->return_val_offset() );
			}

			void AddBots( int Num )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.AddBots" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Num;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class UTBot* SpawnBot( ScriptArray< wchar_t > BotName, bool bUseTeamIndex, int TeamIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.SpawnBot" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptArray< wchar_t >* )params = BotName;
				*( bool* )( params + 12 ) = bUseTeamIndex;
				*( int* )( params + 16 ) = TeamIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTBot** )( params + function->return_val_offset() );
			}

			void InitializeBot( class UTBot* NewBot, class UTTeamInfo* BotTeam, void* &BotInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.InitializeBot" );
				byte *params = ( byte* )( malloc( 120 ) );
				*( class UTBot** )params = NewBot;
				*( class UTTeamInfo** )( params + 4 ) = BotTeam;
				*( void** )( params + 8 ) = BotInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				BotInfo = *( void** )( params + 8 );
			}

			void StartBots(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.StartBots" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KickIdler( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.KickIdler" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )params = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class PlayerController* Login( ScriptArray< wchar_t > Portal, ScriptArray< wchar_t > Options, void* UniqueId, ScriptArray< wchar_t > &ErrorMessage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.Login" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( ScriptArray< wchar_t >* )params = Portal;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Options;
				*( void** )( params + 24 ) = UniqueId;
				*( ScriptArray< wchar_t >* )( params + 32 ) = ErrorMessage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ErrorMessage = *( ScriptArray< wchar_t >* )( params + 32 );
				return *( class PlayerController** )( params + function->return_val_offset() );
			}

			class Pawn* SpawnDefaultPawnFor( class Controller* NewPlayer, class NavigationPoint* StartSpot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.SpawnDefaultPawnFor" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )params = NewPlayer;
				*( class NavigationPoint** )( params + 4 ) = StartSpot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Pawn** )( params + function->return_val_offset() );
			}

			int DetermineWinningTeam(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.DetermineWinningTeam" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void EndGame( class PlayerReplicationInfo* Winner, ScriptArray< wchar_t > Reason )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.EndGame" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class PlayerReplicationInfo** )params = Winner;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Reason;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndOnlineGame(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.EndOnlineGame" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetEndGameFocus( class PlayerReplicationInfo* Winner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.SetEndGameFocus" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )params = Winner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TrackPlayerMovement(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.TrackPlayerMovement" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RespawnPlayers(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.RespawnPlayers" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetScores(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.ResetScores" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetRound(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.ResetRound" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ForceRoundStart(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.ForceRoundStart" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifySpree( class UTPlayerReplicationInfo* Other, int Num )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.NotifySpree" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTPlayerReplicationInfo** )params = Other;
				*( int* )( params + 4 ) = Num;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndSpree( class UTPlayerReplicationInfo* Killer, class UTPlayerReplicationInfo* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.EndSpree" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTPlayerReplicationInfo** )params = Killer;
				*( class UTPlayerReplicationInfo** )( params + 4 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GenericPlayerInitialization( class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.GenericPlayerInitialization" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )params = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptClass* SetGameType( ScriptArray< wchar_t > MapName, ScriptArray< wchar_t > Options, ScriptArray< wchar_t > Portal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.SetGameType" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptArray< wchar_t >* )params = MapName;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Options;
				*( ScriptArray< wchar_t >* )( params + 24 ) = Portal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			void PlayEndOfMatchMessage(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.PlayEndOfMatchMessage" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendMatchOver(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.SendMatchOver" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendShowSummary(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.SendShowSummary" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendNextMatchCountdown( int Seconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.SendNextMatchCountdown" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Seconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendMatchCountdown( int Seconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.SendMatchCountdown" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Seconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ScoreKill( class Controller* Killer, class Controller* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.ScoreKill" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )params = Killer;
				*( class Controller** )( params + 4 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ForceRespawn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.ForceRespawn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void RestartPlayer( class Controller* aPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.RestartPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )params = aPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ChangeTeam( class Controller* Other, int Num, bool bNewTeam )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.ChangeTeam" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class Controller** )params = Other;
				*( int* )( params + 4 ) = Num;
				*( bool* )( params + 8 ) = bNewTeam;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			byte PickTeam( byte Num, class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.PickTeam" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = Num;
				*( class Controller** )( params + 4 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			byte PickTeamForMigration( class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.PickTeamForMigration" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )params = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			void HandleSeamlessTravelPlayer( class Controller* &C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.HandleSeamlessTravelPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )params = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				C = *( class Controller** )params;
			}

			void SetPlayerDefaults( class Pawn* PlayerPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.SetPlayerDefaults" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = PlayerPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Killed( class Controller* Killer, class Controller* KilledPlayer, class Pawn* KilledPawn, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.Killed" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Controller** )params = Killer;
				*( class Controller** )( params + 4 ) = KilledPlayer;
				*( class Pawn** )( params + 8 ) = KilledPawn;
				*( ScriptClass** )( params + 12 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AllowCheats( class PlayerController* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.AllowCheats" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AreTeamsUnbalanced(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.AreTeamsUnbalanced" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void CheckForAutoBalance(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.CheckForAutoBalance" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AutoBalanceInTwenty(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.AutoBalanceInTwenty" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AutoBalanceInFive(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.AutoBalanceInFive" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AutoBalanceTeams(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.AutoBalanceTeams" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MoveRandomPlayerFromTeam( int PlayersToMove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.MoveRandomPlayerFromTeam" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 12 ) = PlayersToMove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitGame( ScriptArray< wchar_t > Options, ScriptArray< wchar_t > &ErrorMessage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.InitGame" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = Options;
				*( ScriptArray< wchar_t >* )( params + 12 ) = ErrorMessage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ErrorMessage = *( ScriptArray< wchar_t >* )( params + 12 );
			}

			void SetPRI( class PlayerController* PC, class PlayerReplicationInfo* NewPRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.SetPRI" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerController** )params = PC;
				*( class PlayerReplicationInfo** )( params + 4 ) = NewPRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetRankFromXP( int XP )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.GetRankFromXP" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = XP;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool CanSpectate( class PlayerController* Viewer, class PlayerReplicationInfo* ViewTarget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.CanSpectate" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerController** )params = Viewer;
				*( class PlayerReplicationInfo** )( params + 4 ) = ViewTarget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void BroadcastAccolade( ScriptArray< wchar_t > Message )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.BroadcastAccolade" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Message;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendMessageToAll( ScriptClass* InMessageClass, int Switch )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.SendMessageToAll" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )params = InMessageClass;
				*( int* )( params + 4 ) = Switch;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnServerSpawnedPlayer( class TrPlayerController* TrPC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.OnServerSpawnedPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPlayerController** )params = TrPC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int FindGameTypeId(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.FindGameTypeId" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int GetGameTypeId(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.GetGameTypeId" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void OnGeneratorPowerChange( class TrPowerGenerator* G )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.OnGeneratorPowerChange" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPowerGenerator** )params = G;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TgStartGame( ScriptArray< wchar_t > &Reason )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.TgStartGame" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Reason;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Reason = *( ScriptArray< wchar_t >* )params;
			}

			void TgEndGame( ScriptArray< wchar_t > &Reason )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.TgEndGame" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Reason;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Reason = *( ScriptArray< wchar_t >* )params;
			}

			void TgChangeScore( int nTeam, int nCount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.TgChangeScore" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = nTeam;
				*( int* )( params + 4 ) = nCount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TgChangeTime( int nSeconds )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.TgChangeTime" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = nSeconds;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TgGetSpectators(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.TgGetSpectators" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class NavigationPoint* FindPlayerStart( class Controller* Player, byte InTeam, ScriptArray< wchar_t > IncomingName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrGame.FindPlayerStart" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( class Controller** )params = Player;
				*( byte* )( params + 4 ) = InTeam;
				*( ScriptArray< wchar_t >* )( params + 8 ) = IncomingName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class NavigationPoint** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
