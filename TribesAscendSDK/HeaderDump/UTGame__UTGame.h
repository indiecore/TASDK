#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTGame." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTGame." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTGame." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTGame : public UDKGame
	{
	public:
			ADD_OBJECT( UTVehicle, VehicleList )
			class Actor* GetAutoObjectiveFor( class UTPlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.GetAutoObjectiveFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, ResetTimeDelay, 0xFFFFFFFF )
			bool ForceRespawn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.ForceRespawn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bWarmupRound, 0x1000 )
			ADD_VAR( ::IntProperty, WarmupTime, 0xFFFFFFFF )
			ADD_OBJECT( GameplayEventsWriter, GameplayEventsWriter )
			ADD_VAR( ::StrProperty, GameplayEventsWriterClassName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, MidgameScorePanelTag, 0xFFFFFFFF )
			ADD_OBJECT( Pawn, Sniper )
			ADD_VAR( ::FloatProperty, LastManDownTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastEncouragementTime, 0xFFFFFFFF )
			ADD_OBJECT( SpeechRecognition, SpeechRecognitionData )
			ADD_VAR( ::StrProperty, EndOfMatchRulesTemplateStr_Time, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, EndOfMatchRulesTemplateStr_ScoringSingle, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, EndOfMatchRulesTemplateStr_Scoring, 0xFFFFFFFF )
			ADD_OBJECT( NavigationPoint, ScriptedStartSpot )
			ADD_VAR( ::IntProperty, MapCycleIndex, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, BotClass )
			ADD_VAR( ::StrProperty, DemoPrefix, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, ConsolePlayerControllerClass )
			ADD_OBJECT( ScriptClass, VictoryMessageClass )
			ADD_VAR( ::StrProperty, EnemyRosterName, 0xFFFFFFFF )
			ADD_OBJECT( UTTeamInfo, EnemyRoster )
			ADD_VAR( ::IntProperty, ResetCountDown, 0xFFFFFFFF )
			ADD_OBJECT( Actor, EndGameFocus )
			ADD_VAR( ::StrProperty, GameUMenuType, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RulesMenuType, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, EndMessageCounter, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, EndMessageWait, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EndTime, 0xFFFFFFFF )
			ADD_OBJECT( NavigationPoint, LastStartSpot )
			ADD_OBJECT( NavigationPoint, LastPlayerStartSpot )
			ADD_VAR( ::IntProperty, PlayerDeaths, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PlayerKills, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AdjustedDifficulty, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CountDown, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PendingMatchElapsedTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LateEntryLives, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DefaultMaxLives, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpawnProtectionTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DesiredPlayerCount, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, WeaponTauntUsed, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, StartupStage, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, WarmupRemaining, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RestartWait, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MinNetPlayers, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ClientProcessingTimeout, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NetWait, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BotRatio, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EndTimeDelay, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ServerSkillLevel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Description, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Acronym, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bGivePhysicsGun, 0x40 )
			ADD_VAR( ::BoolProperty, bLogGameplayEvents, 0x20 )
			ADD_VAR( ::BoolProperty, bUseClassicHUD, 0x10 )
			ADD_VAR( ::BoolProperty, bIgnoreTeamForVoiceChat, 0x8 )
			ADD_VAR( ::BoolProperty, bNecrisLocked, 0x4 )
			ADD_VAR( ::BoolProperty, bForceMidGameMenuAtStart, 0x2 )
			ADD_VAR( ::BoolProperty, bMidGameHasMap, 0x1 )
			ADD_VAR( ::BoolProperty, bPlayedOneKill, 0x80000000 )
			ADD_VAR( ::BoolProperty, bPlayedFiveKills, 0x40000000 )
			ADD_VAR( ::BoolProperty, bPlayedTenKills, 0x20000000 )
			ADD_VAR( ::BoolProperty, bScoreDeaths, 0x10000000 )
			ADD_VAR( ::BoolProperty, bAllowKeyboardAndMouse, 0x8000000 )
			ADD_VAR( ::BoolProperty, bConsoleServer, 0x4000000 )
			ADD_VAR( ::BoolProperty, bAllowHoverboard, 0x2000000 )
			ADD_VAR( ::BoolProperty, bStartWithLockerWeaps, 0x1000000 )
			ADD_VAR( ::BoolProperty, bUndrivenVehicleDamage, 0x800000 )
			ADD_VAR( ::BoolProperty, bDemoMode, 0x400000 )
			ADD_VAR( ::BoolProperty, bMustJoinBeforeStart, 0x200000 )
			ADD_VAR( ::BoolProperty, bPlayerBecameActive, 0x100000 )
			ADD_VAR( ::BoolProperty, bMustHaveMultiplePlayers, 0x80000 )
			ADD_VAR( ::BoolProperty, bOverTimeBroadcast, 0x40000 )
			ADD_VAR( ::BoolProperty, bFinalStartup, 0x20000 )
			ADD_VAR( ::BoolProperty, bStartedCountDown, 0x10000 )
			ADD_VAR( ::BoolProperty, bSkipPlaySound, 0x8000 )
			ADD_VAR( ::BoolProperty, bQuickStart, 0x4000 )
			ADD_VAR( ::BoolProperty, bFirstBlood, 0x2000 )
			ADD_VAR( ::BoolProperty, bShouldWaitForNetPlayers, 0x800 )
			ADD_VAR( ::BoolProperty, bWaitForNetPlayers, 0x400 )
			ADD_VAR( ::BoolProperty, bTempForceRespawn, 0x200 )
			ADD_VAR( ::BoolProperty, bForceRespawn, 0x100 )
			ADD_VAR( ::BoolProperty, bPlayersMustBeReady, 0x80 )
			ADD_VAR( ::BoolProperty, bAutoNumBots, 0x40 )
			ADD_VAR( ::BoolProperty, bCustomBots, 0x20 )
			ADD_VAR( ::BoolProperty, bPlayersVsBots, 0x10 )
			ADD_VAR( ::BoolProperty, bSoaking, 0x8 )
			ADD_VAR( ::BoolProperty, bTeamScoreRounds, 0x4 )
			ADD_VAR( ::BoolProperty, bWeaponStay, 0x2 )
			ADD_VAR( ::BoolProperty, bExportMenuData, 0x1 )
			bool JustStarted( float MaxElapsedTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.JustStarted" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = MaxElapsedTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class UTTeamInfo* GetBotTeam( int TeamBots, bool bUseTeamIndex, int TeamIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.GetBotTeam" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )( params + 0 ) = TeamBots;
				*( bool* )( params + 4 ) = bUseTeamIndex;
				*( int* )( params + 8 ) = TeamIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTTeamInfo** )( params + function->return_val_offset() );
			}

			bool UseLowGore( class WorldInfo* WI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.UseLowGore" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class WorldInfo** )( params + 0 ) = WI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool TooManyBots( class Controller* botToRemove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.TooManyBots" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = botToRemove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AllowMutator( ScriptArray< wchar_t > MutatorClassName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.AllowMutator" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = MutatorClassName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptClass* SetGameType( ScriptArray< wchar_t > MapName, ScriptArray< wchar_t > Options, ScriptArray< wchar_t > Portal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.SetGameType" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = MapName;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Options;
				*( ScriptArray< wchar_t >* )( params + 24 ) = Portal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			void DriverEnteredVehicle( class Vehicle* V, class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.DriverEnteredVehicle" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Vehicle** )( params + 0 ) = V;
				*( class Pawn** )( params + 4 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DriverLeftVehicle( class Vehicle* V, class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.DriverLeftVehicle" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Vehicle** )( params + 0 ) = V;
				*( class Pawn** )( params + 4 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AllowBecomeActivePlayer( class PlayerController* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.AllowBecomeActivePlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FindNewObjectives( class UTGameObjective* DisabledObjective )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.FindNewObjectives" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTGameObjective** )( params + 0 ) = DisabledObjective;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyNavigationChanged( class NavigationPoint* N )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.NotifyNavigationChanged" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class NavigationPoint** )( params + 0 ) = N;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > ParseKillMessage( ScriptArray< wchar_t > KillerName, ScriptArray< wchar_t > VictimName, ScriptArray< wchar_t > DeathMessage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.ParseKillMessage" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = KillerName;
				*( ScriptArray< wchar_t >* )( params + 12 ) = VictimName;
				*( ScriptArray< wchar_t >* )( params + 24 ) = DeathMessage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool SkipPlaySound(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.SkipPlaySound" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetGameSpeed( float T )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.SetGameSpeed" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = T;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BroadcastDeathMessage( class Controller* Killer, class Controller* Other, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.BroadcastDeathMessage" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class Controller** )( params + 0 ) = Killer;
				*( class Controller** )( params + 4 ) = Other;
				*( ScriptClass** )( params + 8 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ScoreKill( class Controller* Killer, class Controller* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.ScoreKill" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )( params + 0 ) = Killer;
				*( class Controller** )( params + 4 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AdjustSkill( class AIController* B, class PlayerController* P, bool bWinner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.AdjustSkill" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class AIController** )( params + 0 ) = B;
				*( class PlayerController** )( params + 4 ) = P;
				*( bool* )( params + 8 ) = bWinner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Killed( class Controller* Killer, class Controller* KilledPlayer, class Pawn* KilledPawn, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.Killed" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Controller** )( params + 0 ) = Killer;
				*( class Controller** )( params + 4 ) = KilledPlayer;
				*( class Pawn** )( params + 8 ) = KilledPawn;
				*( ScriptClass** )( params + 12 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitGame( ScriptArray< wchar_t > Options, ScriptArray< wchar_t > &ErrorMessage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.InitGame" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Options;
				*( ScriptArray< wchar_t >* )( params + 12 ) = ErrorMessage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ErrorMessage = *( ScriptArray< wchar_t >* )( params + 12 );
			}

			void GenericPlayerInitialization( class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.GenericPlayerInitialization" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool SetPause( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.SetPause" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int LevelRecommendedPlayers(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.LevelRecommendedPlayers" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			class PlayerController* Login( ScriptArray< wchar_t > Portal, ScriptArray< wchar_t > Options, void* UniqueId, ScriptArray< wchar_t > &ErrorMessage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.Login" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Portal;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Options;
				*( void** )( params + 24 ) = UniqueId;
				*( ScriptArray< wchar_t >* )( params + 32 ) = ErrorMessage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ErrorMessage = *( ScriptArray< wchar_t >* )( params + 32 );
				return *( class PlayerController** )( params + function->return_val_offset() );
			}

			bool ShouldRespawn( class PickupFactory* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.ShouldRespawn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PickupFactory** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool WantFastSpawnFor( class AIController* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.WantFastSpawnFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class AIController** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float SpawnWait( class AIController* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.SpawnWait" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class AIController** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void RestartGame(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.RestartGame" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CheckEndGame( class PlayerReplicationInfo* Winner, ScriptArray< wchar_t > Reason )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.CheckEndGame" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class PlayerReplicationInfo** )( params + 0 ) = Winner;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Reason;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetEndGameFocus( class PlayerReplicationInfo* Winner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.SetEndGameFocus" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )( params + 0 ) = Winner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AtCapacity( bool bSpectator )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.AtCapacity" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bSpectator;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PostLogin( class PlayerController* NewPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.PostLogin" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = NewPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateGameSettingsCounts(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.UpdateGameSettingsCounts" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AssignHoverboard( class UTPawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.AssignHoverboard" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetHandicapNeed( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.GetHandicapNeed" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void RestartPlayer( class Controller* aPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.RestartPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = aPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CampaignSkillAdjust( class UTBot* aBot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.CampaignSkillAdjust" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = aBot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddDefaultInventory( class Pawn* PlayerPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.AddDefaultInventory" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = PlayerPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanSpectate( class PlayerController* Viewer, class PlayerReplicationInfo* ViewTarget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.CanSpectate" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerController** )( params + 0 ) = Viewer;
				*( class PlayerReplicationInfo** )( params + 4 ) = ViewTarget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ChangeName( class Controller* Other, ScriptArray< wchar_t > S, bool bNameChange )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.ChangeName" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Controller** )( params + 0 ) = Other;
				*( ScriptArray< wchar_t >* )( params + 4 ) = S;
				*( bool* )( params + 16 ) = bNameChange;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DiscardInventory( class Pawn* Other, class Controller* Killer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.DiscardInventory" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )( params + 0 ) = Other;
				*( class Controller** )( params + 4 ) = Killer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Logout( class Controller* Exiting )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.Logout" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = Exiting;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KillBots(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.KillBots" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KillOthers(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.KillOthers" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KillThis(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.KillThis" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KillBot( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.KillBot" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool NeedPlayers(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.NeedPlayers" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class UTBot* AddBot( ScriptArray< wchar_t > BotName, bool bUseTeamIndex, int TeamIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.AddBot" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = BotName;
				*( bool* )( params + 12 ) = bUseTeamIndex;
				*( int* )( params + 16 ) = TeamIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTBot** )( params + function->return_val_offset() );
			}

			class UTBot* SpawnBot( ScriptArray< wchar_t > BotName, bool bUseTeamIndex, int TeamIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.SpawnBot" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = BotName;
				*( bool* )( params + 12 ) = bUseTeamIndex;
				*( int* )( params + 16 ) = TeamIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTBot** )( params + function->return_val_offset() );
			}

			void InitializeBot( class UTBot* NewBot, class UTTeamInfo* BotTeam, void* &BotInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.InitializeBot" );
				byte *params = ( byte* )( malloc( 120 ) );
				*( class UTBot** )( params + 0 ) = NewBot;
				*( class UTTeamInfo** )( params + 4 ) = BotTeam;
				*( void** )( params + 8 ) = BotInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				BotInfo = *( void** )( params + 8 );
			}

			void InitGameReplicationInfo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.InitGameReplicationInfo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetMapTypeRule(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.GetMapTypeRule" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetEndGameConditionRule(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.GetEndGameConditionRule" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void NotifySpree( class UTPlayerReplicationInfo* Other, int Num )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.NotifySpree" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTPlayerReplicationInfo** )( params + 0 ) = Other;
				*( int* )( params + 4 ) = Num;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndSpree( class UTPlayerReplicationInfo* Killer, class UTPlayerReplicationInfo* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.EndSpree" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTPlayerReplicationInfo** )( params + 0 ) = Killer;
				*( class UTPlayerReplicationInfo** )( params + 4 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateGameplayMuteList( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.UpdateGameplayMuteList" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetupPlayerMuteList( class UTPlayerController* PC, bool bForceSpectatorChannel )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.SetupPlayerMuteList" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTPlayerController** )( params + 0 ) = PC;
				*( bool* )( params + 4 ) = bForceSpectatorChannel;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemovePlayerFromMuteLists( class UTPlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.RemovePlayerFromMuteLists" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetAllPlayerMuteListsToSpectatorChannel(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.ResetAllPlayerMuteListsToSpectatorChannel" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartMatch(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.StartMatch" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndGame( class PlayerReplicationInfo* Winner, ScriptArray< wchar_t > Reason )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.EndGame" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class PlayerReplicationInfo** )( params + 0 ) = Winner;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Reason;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndLogging( ScriptArray< wchar_t > Reason )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.EndLogging" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Reason;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class NavigationPoint* FindPlayerStart( class Controller* Player, byte InTeam, ScriptArray< wchar_t > IncomingName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.FindPlayerStart" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( class Controller** )( params + 0 ) = Player;
				*( byte* )( params + 4 ) = InTeam;
				*( ScriptArray< wchar_t >* )( params + 8 ) = IncomingName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class NavigationPoint** )( params + function->return_val_offset() );
			}

			bool DominatingVictory(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.DominatingVictory" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsAWinner( class PlayerController* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.IsAWinner" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PlayEndOfMatchMessage(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.PlayEndOfMatchMessage" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayRegularEndOfMatchMessage(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.PlayRegularEndOfMatchMessage" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayStartupMessage(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.PlayStartupMessage" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndRound( class Actor* EndRoundFocus )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.EndRound" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = EndRoundFocus;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool MatchIsInProgress(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.MatchIsInProgress" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddInitialBots(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.AddInitialBots" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int CalculatedNetSpeed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.CalculatedNetSpeed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool IsConsoleDedicatedServer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.IsConsoleDedicatedServer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class PlayerStart* ChoosePlayerStart( class Controller* Player, byte InTeam )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.ChoosePlayerStart" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( class Controller** )( params + 0 ) = Player;
				*( byte* )( params + 4 ) = InTeam;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class PlayerStart** )( params + function->return_val_offset() );
			}

			float RatePlayerStart( class PlayerStart* P, byte Team, class Controller* Player )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.RatePlayerStart" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( class PlayerStart** )( params + 0 ) = P;
				*( byte* )( params + 4 ) = Team;
				*( class Controller** )( params + 8 ) = Player;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool CheckMaxLives( class PlayerReplicationInfo* Scorer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.CheckMaxLives" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )( params + 0 ) = Scorer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CheckScore( class PlayerReplicationInfo* Scorer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.CheckScore" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )( params + 0 ) = Scorer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void RegisterVehicle( class UTVehicle* V )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.RegisterVehicle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTVehicle** )( params + 0 ) = V;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ActivateVehicleFactory( class UTVehicleFactory* VF )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.ActivateVehicleFactory" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTVehicleFactory** )( params + 0 ) = VF;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ViewObjective( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.ViewObjective" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddMutator( ScriptArray< wchar_t > mutname, bool bUserAdded )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.AddMutator" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = mutname;
				*( bool* )( params + 12 ) = bUserAdded;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AllowClientToTeleport( class UTPlayerReplicationInfo* ClientPRI, class Actor* DestinationActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.AllowClientToTeleport" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTPlayerReplicationInfo** )( params + 0 ) = ClientPRI;
				*( class Actor** )( params + 4 ) = DestinationActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ShowPathTo( class PlayerController* P, int TeamNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.ShowPathTo" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerController** )( params + 0 ) = P;
				*( int* )( params + 4 ) = TeamNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetSeamlessTravelActorList( bool bToEntry )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.GetSeamlessTravelActorList" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( bool* )( params + 0 ) = bToEntry;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostSeamlessTravel(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.PostSeamlessTravel" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HandleSeamlessTravelPlayer( class Controller* &C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.HandleSeamlessTravelPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				C = *( class Controller** )( params + 0 );
			}

			class UTMutator* GetBaseUTMutator(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.GetBaseUTMutator" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTMutator** )( params + function->return_val_offset() );
			}

			void ProcessSpeechRecognition( class UTPlayerController* Speaker )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.ProcessSpeechRecognition" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class UTPlayerController** )( params + 0 ) = Speaker;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void WriteOnlinePlayerScores(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.WriteOnlinePlayerScores" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetCurrentMapCycleIndex(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.GetCurrentMapCycleIndex" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetNextMap(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.GetNextMap" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void ProcessServerTravel( ScriptArray< wchar_t > URL, bool bAbsolute )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.ProcessServerTravel" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = URL;
				*( bool* )( params + 12 ) = bAbsolute;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ContinueSeamlessTravel(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.ContinueSeamlessTravel" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetEndOfMatchRules( int InGoalScore, int InTimeLimit )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.GetEndOfMatchRules" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = InGoalScore;
				*( int* )( params + 4 ) = InTimeLimit;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool GetLocationFor( class Pawn* StatusPawn, class Actor* &LocationObject, int &MessageIndex, int LocationSpeechOffset )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.GetLocationFor" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Pawn** )( params + 0 ) = StatusPawn;
				*( class Actor** )( params + 4 ) = LocationObject;
				*( int* )( params + 8 ) = MessageIndex;
				*( int* )( params + 12 ) = LocationSpeechOffset;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				LocationObject = *( class Actor** )( params + 4 );
				MessageIndex = *( int* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AllowCheats( class PlayerController* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.AllowCheats" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void UpdateGameSettings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGame.UpdateGameSettings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
