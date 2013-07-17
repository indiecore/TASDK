#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.GameInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.GameInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.GameInfo." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameInfo : public Info
	{
	public:
			bool CheckRelevance( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.CheckRelevance" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, NumPlayers, 0xFFFFFFFF )
			ScriptArray< wchar_t > ParseOption( ScriptArray< wchar_t > Options, ScriptArray< wchar_t > InKey )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.ParseOption" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Options;
				*( ScriptArray< wchar_t >* )( params + 12 ) = InKey;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool AtCapacity( bool bSpectator )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.AtCapacity" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bSpectator;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( ScriptClass, GameMessageClass )
			ADD_OBJECT( ScriptClass, PlayerReplicationInfoClass )
			ADD_VAR( ::StrProperty, DefaultPlayerName, 0xFFFFFFFF )
			void ForceClearUnpauseDelegates( class Actor* PauseActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.ForceClearUnpauseDelegates" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = PauseActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsAutomatedPerfTesting(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.IsAutomatedPerfTesting" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, MaxTimeMargin, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bRequiresPushToTalk, 0x400000 )
			ADD_VAR( ::BoolProperty, bTeamGame, 0x4 )
			bool SetPause( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.SetPause" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ChangeTeam( class Controller* Other, int N, bool bNewTeam )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.ChangeTeam" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class Controller** )( params + 0 ) = Other;
				*( int* )( params + 4 ) = N;
				*( bool* )( params + 8 ) = bNewTeam;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CanSpectate( class PlayerController* Viewer, class PlayerReplicationInfo* ViewTarget )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.CanSpectate" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerController** )( params + 0 ) = Viewer;
				*( class PlayerReplicationInfo** )( params + 4 ) = ViewTarget;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bWaitingToStartMatch, 0x40 )
			bool PlayerCanRestartGame( class PlayerController* aPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.PlayerCanRestartGame" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = aPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool PlayerCanRestart( class PlayerController* aPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.PlayerCanRestart" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = aPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, ArbitratedLeaderboardId, 0xFFFFFFFF )
			bool IsDoingASentinelRun(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.IsDoingASentinelRun" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, GameDifficulty, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TimeLimit, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, CauseEventCommand, 0xFFFFFFFF )
			class CoverReplicator* GetCoverReplicator(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.GetCoverReplicator" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class CoverReplicator** )( params + function->return_val_offset() );
			}

			bool PickupQuery( class Pawn* Other, ScriptClass* ItemClass, class Actor* Pickup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.PickupQuery" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class Pawn** )( params + 0 ) = Other;
				*( ScriptClass** )( params + 4 ) = ItemClass;
				*( class Actor** )( params + 8 ) = Pickup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bHasNetworkError, 0x200000 )
			ADD_VAR( ::BoolProperty, bRestartLevel, 0x1 )
			bool GetSupportedGameTypes( ScriptArray< wchar_t > &InFilename, void* &OutGameType, bool bCheckExt )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.GetSupportedGameTypes" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = InFilename;
				*( void** )( params + 12 ) = OutGameType;
				*( bool* )( params + 64 ) = bCheckExt;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				InFilename = *( ScriptArray< wchar_t >* )( params + 0 );
				OutGameType = *( void** )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetMapCommonPackageName( ScriptArray< wchar_t > &InFilename, ScriptArray< wchar_t > &OutCommonPackageName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.GetMapCommonPackageName" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = InFilename;
				*( ScriptArray< wchar_t >* )( params + 12 ) = OutCommonPackageName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				InFilename = *( ScriptArray< wchar_t >* )( params + 0 );
				OutCommonPackageName = *( ScriptArray< wchar_t >* )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PreBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.PreBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::IntProperty, AdjustedNetSpeed, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxDynamicBandwidth, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, GameSpeed, 0xFFFFFFFF )
			ADD_OBJECT( GameReplicationInfo, GameReplicationInfo )
			ADD_OBJECT( ScriptClass, GameReplicationInfoClass )
			ADD_OBJECT( CoverReplicator, CoverReplicatorBase )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisplayDebug( class HUD* HUD, float &out_YL, float &out_YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.DisplayDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class HUD** )( params + 0 ) = HUD;
				*( float* )( params + 4 ) = out_YL;
				*( float* )( params + 8 ) = out_YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_YL = *( float* )( params + 4 );
				out_YPos = *( float* )( params + 8 );
			}

			ADD_VAR( ::StrProperty, GameName, 0xFFFFFFFF )
			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bGameEnded, 0x8 )
			ADD_VAR( ::BoolProperty, bOverTime, 0x10 )
			bool ShouldReset( class Actor* ActorToReset )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.ShouldReset" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = ActorToReset;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ResetLevel(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.ResetLevel" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Timer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.Timer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( BroadcastHandler, BroadcastHandler )
			ADD_VAR( ::BoolProperty, bDoFearCostFallOff, 0x80000 )
			void DoNavFearCostFallOff(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.DoNavFearCostFallOff" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyNavigationChanged( class NavigationPoint* N )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.NotifyNavigationChanged" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class NavigationPoint** )( params + 0 ) = N;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GameEnding(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.GameEnding" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KickIdler( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.KickIdler" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( AccessControl, AccessControl )
			void ForceKickPlayer( class PlayerController* PC, ScriptArray< wchar_t > KickReason )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.ForceKickPlayer" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				*( ScriptArray< wchar_t >* )( params + 4 ) = KickReason;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitGameReplicationInfo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.InitGameReplicationInfo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetNetworkNumber(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.GetNetworkNumber" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			int GetNumPlayers(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.GetNumPlayers" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, NumTravellingPlayers, 0xFFFFFFFF )
			bool CanUnpause(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.CanUnpause" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ClearPause(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.ClearPause" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DebugPause(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.DebugPause" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetGameSpeed( float T )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.SetGameSpeed" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = T;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GrabOption( ScriptArray< wchar_t > &Options, ScriptArray< wchar_t > &Result )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.GrabOption" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Options;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Result;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Options = *( ScriptArray< wchar_t >* )( params + 0 );
				Result = *( ScriptArray< wchar_t >* )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void GetKeyValue( ScriptArray< wchar_t > Pair, ScriptArray< wchar_t > &Key, ScriptArray< wchar_t > &Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.GetKeyValue" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Pair;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Key;
				*( ScriptArray< wchar_t >* )( params + 24 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Key = *( ScriptArray< wchar_t >* )( params + 12 );
				Value = *( ScriptArray< wchar_t >* )( params + 24 );
			}

			bool HasOption( ScriptArray< wchar_t > Options, ScriptArray< wchar_t > InKey )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.HasOption" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Options;
				*( ScriptArray< wchar_t >* )( params + 12 ) = InKey;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int GetIntOption( ScriptArray< wchar_t > Options, ScriptArray< wchar_t > ParseString, int CurrentValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.GetIntOption" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Options;
				*( ScriptArray< wchar_t >* )( params + 12 ) = ParseString;
				*( int* )( params + 24 ) = CurrentValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetDefaultGameClassPath( ScriptArray< wchar_t > MapName, ScriptArray< wchar_t > Options, ScriptArray< wchar_t > Portal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.GetDefaultGameClassPath" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = MapName;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Options;
				*( ScriptArray< wchar_t >* )( params + 24 ) = Portal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptClass* SetGameType( ScriptArray< wchar_t > MapName, ScriptArray< wchar_t > Options, ScriptArray< wchar_t > Portal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.SetGameType" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = MapName;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Options;
				*( ScriptArray< wchar_t >* )( params + 24 ) = Portal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			void InitGame( ScriptArray< wchar_t > Options, ScriptArray< wchar_t > &ErrorMessage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.InitGame" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Options;
				*( ScriptArray< wchar_t >* )( params + 12 ) = ErrorMessage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ErrorMessage = *( ScriptArray< wchar_t >* )( params + 12 );
			}

			ADD_VAR( ::IntProperty, MaxPlayers, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxPlayersAllowed, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxSpectators, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxSpectatorsAllowed, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, BroadcastHandlerClass )
			ADD_OBJECT( ScriptClass, AccessControlClass )
			ADD_VAR( ::BoolProperty, bFixedPlayerStart, 0x40000 )
			ADD_OBJECT( AutoTestManager, MyAutoTestManager )
			ADD_OBJECT( ScriptClass, AutoTestManagerClass )
			ADD_VAR( ::StrProperty, BugLocString, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, BugRotString, 0xFFFFFFFF )
			ADD_OBJECT( Mutator, BaseMutator )
			ADD_OBJECT( OnlineSubsystem, OnlineSub )
			ADD_VAR( ::BoolProperty, bUsingArbitration, 0x2000 )
			ADD_VAR( ::StrProperty, ServerOptions, 0xFFFFFFFF )
			void NotifyPendingConnectionLost(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.NotifyPendingConnectionLost" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddMutator( ScriptArray< wchar_t > mutname, bool bUserAdded )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.AddMutator" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = mutname;
				*( bool* )( params + 12 ) = bUserAdded;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveMutator( class Mutator* MutatorToRemove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.RemoveMutator" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Mutator** )( params + 0 ) = MutatorToRemove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProcessServerTravel( ScriptArray< wchar_t > URL, bool bAbsolute )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.ProcessServerTravel" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = URL;
				*( bool* )( params + 12 ) = bAbsolute;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bLevelChange, 0x800 )
			ADD_VAR( ::BoolProperty, bUseSeamlessTravel, 0x100000 )
			class PlayerController* ProcessClientTravel( ScriptArray< wchar_t > &URL, void* NextMapGuid, bool bSeamless, bool bAbsolute )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.ProcessClientTravel" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = URL;
				*( void** )( params + 12 ) = NextMapGuid;
				*( bool* )( params + 28 ) = bSeamless;
				*( bool* )( params + 32 ) = bAbsolute;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				URL = *( ScriptArray< wchar_t >* )( params + 0 );
				return *( class PlayerController** )( params + function->return_val_offset() );
			}

			bool RequiresPassword(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.RequiresPassword" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PreLogin( ScriptArray< wchar_t > Options, ScriptArray< wchar_t > Address, ScriptArray< wchar_t > &ErrorMessage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.PreLogin" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Options;
				*( ScriptArray< wchar_t >* )( params + 12 ) = Address;
				*( ScriptArray< wchar_t >* )( params + 24 ) = ErrorMessage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ErrorMessage = *( ScriptArray< wchar_t >* )( params + 24 );
			}

			ADD_VAR( ::BoolProperty, bHasArbitratedHandshakeBegun, 0x4000 )
			ADD_VAR( ::IntProperty, NumSpectators, 0xFFFFFFFF )
			int GetNextPlayerID(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.GetNextPlayerID" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			class PlayerController* SpawnPlayerController( Vector SpawnLocation, Rotator SpawnRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.SpawnPlayerController" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = SpawnLocation;
				*( Rotator* )( params + 12 ) = SpawnRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class PlayerController** )( params + function->return_val_offset() );
			}

			ADD_OBJECT( ScriptClass, PlayerControllerClass )
			class PlayerController* Login( ScriptArray< wchar_t > Portal, ScriptArray< wchar_t > Options, void* UniqueId, ScriptArray< wchar_t > &ErrorMessage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.Login" );
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

			ADD_VAR( ::BoolProperty, bDelayedStart, 0x20 )
			void StartMatch(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.StartMatch" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartOnlineGame(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.StartOnlineGame" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnStartOnlineGameComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.OnStartOnlineGameComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartHumans(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.StartHumans" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartBots(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.StartBots" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RestartPlayer( class Controller* NewPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.RestartPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = NewPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Pawn* SpawnDefaultPawnFor( class Controller* NewPlayer, class NavigationPoint* StartSpot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.SpawnDefaultPawnFor" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )( params + 0 ) = NewPlayer;
				*( class NavigationPoint** )( params + 4 ) = StartSpot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Pawn** )( params + function->return_val_offset() );
			}

			ScriptClass* GetDefaultPlayerClass( class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.GetDefaultPlayerClass" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			ADD_OBJECT( ScriptClass, DefaultPawnClass )
			void ReplicateStreamingStatus( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.ReplicateStreamingStatus" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GenericPlayerInitialization( class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.GenericPlayerInitialization" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( ScriptClass, HUDType )
			int BestNextHostSort( class PlayerController* A, class PlayerController* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.BestNextHostSort" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerController** )( params + 0 ) = A;
				*( class PlayerController** )( params + 4 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void UpdateBestNextHosts(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.UpdateBestNextHosts" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostLogin( class PlayerController* NewPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.PostLogin" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = NewPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateNetSpeeds(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.UpdateNetSpeeds" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, LastNetSpeedUpdateTime, 0xFFFFFFFF )
			int CalculatedNetSpeed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.CalculatedNetSpeed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, TotalNetBandwidth, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MinDynamicBandwidth, 0xFFFFFFFF )
			void PreExit(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.PreExit" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Logout( class Controller* Exiting )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.Logout" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = Exiting;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bHasEndGameHandshakeBegun, 0x20000 )
			void UnregisterPlayer( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.UnregisterPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AcceptInventory( class Pawn* PlayerPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.AcceptInventory" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = PlayerPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddDefaultInventory( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.AddDefaultInventory" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Mutate( ScriptArray< wchar_t > MutateString, class PlayerController* Sender )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.Mutate" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = MutateString;
				*( class PlayerController** )( params + 12 ) = Sender;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPlayerDefaults( class Pawn* PlayerPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.SetPlayerDefaults" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = PlayerPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyKilled( class Controller* Killer, class Controller* Killed, class Pawn* KilledPawn, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.NotifyKilled" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Controller** )( params + 0 ) = Killer;
				*( class Controller** )( params + 4 ) = Killed;
				*( class Pawn** )( params + 8 ) = KilledPawn;
				*( ScriptClass** )( params + 12 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Killed( class Controller* Killer, class Controller* KilledPlayer, class Pawn* KilledPawn, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.Killed" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Controller** )( params + 0 ) = Killer;
				*( class Controller** )( params + 4 ) = KilledPlayer;
				*( class Pawn** )( params + 8 ) = KilledPawn;
				*( ScriptClass** )( params + 12 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool PreventDeath( class Pawn* KilledPawn, class Controller* Killer, ScriptClass* DamageType, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.PreventDeath" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( class Pawn** )( params + 0 ) = KilledPawn;
				*( class Controller** )( params + 4 ) = Killer;
				*( ScriptClass** )( params + 8 ) = DamageType;
				*( Vector* )( params + 12 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void BroadcastDeathMessage( class Controller* Killer, class Controller* Other, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.BroadcastDeathMessage" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class Controller** )( params + 0 ) = Killer;
				*( class Controller** )( params + 4 ) = Other;
				*( ScriptClass** )( params + 8 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( ScriptClass, DeathMessageClass )
			void Kick( ScriptArray< wchar_t > S )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.Kick" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = S;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KickBan( ScriptArray< wchar_t > S )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.KickBan" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = S;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReduceDamage( int &Damage, class Pawn* injured, class Controller* InstigatedBy, Vector HitLocation, Vector &Momentum, ScriptClass* DamageType, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.ReduceDamage" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( int* )( params + 0 ) = Damage;
				*( class Pawn** )( params + 4 ) = injured;
				*( class Controller** )( params + 8 ) = InstigatedBy;
				*( Vector* )( params + 12 ) = HitLocation;
				*( Vector* )( params + 24 ) = Momentum;
				*( ScriptClass** )( params + 36 ) = DamageType;
				*( class Actor** )( params + 40 ) = DamageCauser;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Damage = *( int* )( params + 0 );
				Momentum = *( Vector* )( params + 24 );
			}

			bool ShouldRespawn( class PickupFactory* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.ShouldRespawn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PickupFactory** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void DiscardInventory( class Pawn* Other, class Controller* Killer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.DiscardInventory" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )( params + 0 ) = Other;
				*( class Controller** )( params + 4 ) = Killer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ChangeName( class Controller* Other, ScriptArray< wchar_t > S, bool bNameChange )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.ChangeName" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Controller** )( params + 0 ) = Other;
				*( ScriptArray< wchar_t >* )( params + 4 ) = S;
				*( bool* )( params + 16 ) = bNameChange;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte PickTeam( byte Current, class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.PickTeam" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = Current;
				*( class Controller** )( params + 4 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			void SendPlayer( class PlayerController* aPlayer, ScriptArray< wchar_t > URL )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.SendPlayer" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class PlayerController** )( params + 0 ) = aPlayer;
				*( ScriptArray< wchar_t >* )( params + 4 ) = URL;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetNextMap(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.GetNextMap" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool GetTravelType(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.GetTravelType" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void RestartGame(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.RestartGame" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bIsEndGameHandshakeComplete, 0x10000 )
			ADD_VAR( ::BoolProperty, bGameRestarted, 0x400 )
			ADD_VAR( ::BoolProperty, bChangeLevels, 0x80 )
			ADD_VAR( ::BoolProperty, bAlreadyChanged, 0x100 )
			void Broadcast( class Actor* Sender, ScriptArray< wchar_t > msg, ScriptName Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.Broadcast" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( class Actor** )( params + 0 ) = Sender;
				*( ScriptArray< wchar_t >* )( params + 4 ) = msg;
				*( ScriptName* )( params + 16 ) = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BroadcastTeam( class Controller* Sender, ScriptArray< wchar_t > msg, ScriptName Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.BroadcastTeam" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( class Controller** )( params + 0 ) = Sender;
				*( ScriptArray< wchar_t >* )( params + 4 ) = msg;
				*( ScriptName* )( params + 16 ) = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BroadcastLocalized( class Actor* Sender, ScriptClass* Message, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.BroadcastLocalized" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( class Actor** )( params + 0 ) = Sender;
				*( ScriptClass** )( params + 4 ) = Message;
				*( int* )( params + 8 ) = Switch;
				*( class PlayerReplicationInfo** )( params + 12 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 16 ) = RelatedPRI_;
				*( class Object** )( params + 20 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BroadcastLocalizedTeam( int TeamIndex, class Actor* Sender, ScriptClass* Message, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI_, class Object* OptionalObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.BroadcastLocalizedTeam" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( int* )( params + 0 ) = TeamIndex;
				*( class Actor** )( params + 4 ) = Sender;
				*( ScriptClass** )( params + 8 ) = Message;
				*( int* )( params + 12 ) = Switch;
				*( class PlayerReplicationInfo** )( params + 16 ) = RelatedPRI;
				*( class PlayerReplicationInfo** )( params + 20 ) = RelatedPRI_;
				*( class Object** )( params + 24 ) = OptionalObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CheckModifiedEndGame( class PlayerReplicationInfo* Winner, ScriptArray< wchar_t > Reason )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.CheckModifiedEndGame" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class PlayerReplicationInfo** )( params + 0 ) = Winner;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Reason;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CheckEndGame( class PlayerReplicationInfo* Winner, ScriptArray< wchar_t > Reason )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.CheckEndGame" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class PlayerReplicationInfo** )( params + 0 ) = Winner;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Reason;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void WriteOnlineStats(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.WriteOnlineStats" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( ScriptClass, OnlineStatsWriteClass )
			void WriteOnlinePlayerScores(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.WriteOnlinePlayerScores" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::IntProperty, LeaderboardId, 0xFFFFFFFF )
			void ForceRoundStart(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.ForceRoundStart" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndGame( class PlayerReplicationInfo* Winner, ScriptArray< wchar_t > Reason )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.EndGame" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class PlayerReplicationInfo** )( params + 0 ) = Winner;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Reason;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PerformEndGameHandling(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.PerformEndGameHandling" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndOnlineGame(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.EndOnlineGame" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GameEventsPoll(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.GameEventsPoll" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndLogging( ScriptArray< wchar_t > Reason )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.EndLogging" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Reason;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldSpawnAtStartSpot( class Controller* Player )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.ShouldSpawnAtStartSpot" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = Player;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class NavigationPoint* FindPlayerStart( class Controller* Player, byte InTeam, ScriptArray< wchar_t > IncomingName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.FindPlayerStart" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( class Controller** )( params + 0 ) = Player;
				*( byte* )( params + 4 ) = InTeam;
				*( ScriptArray< wchar_t >* )( params + 8 ) = IncomingName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class NavigationPoint** )( params + function->return_val_offset() );
			}

			class PlayerStart* ChoosePlayerStart( class Controller* Player, byte InTeam )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.ChoosePlayerStart" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( class Controller** )( params + 0 ) = Player;
				*( byte* )( params + 4 ) = InTeam;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class PlayerStart** )( params + function->return_val_offset() );
			}

			float RatePlayerStart( class PlayerStart* P, byte Team, class Controller* Player )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.RatePlayerStart" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( class PlayerStart** )( params + 0 ) = P;
				*( byte* )( params + 4 ) = Team;
				*( class Controller** )( params + 8 ) = Player;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void AddObjectiveScore( class PlayerReplicationInfo* Scorer, int Score )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.AddObjectiveScore" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerReplicationInfo** )( params + 0 ) = Scorer;
				*( int* )( params + 4 ) = Score;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ScoreObjective( class PlayerReplicationInfo* Scorer, int Score )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.ScoreObjective" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerReplicationInfo** )( params + 0 ) = Scorer;
				*( int* )( params + 4 ) = Score;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CheckScore( class PlayerReplicationInfo* Scorer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.CheckScore" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )( params + 0 ) = Scorer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ScoreKill( class Controller* Killer, class Controller* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.ScoreKill" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )( params + 0 ) = Killer;
				*( class Controller** )( params + 4 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::IntProperty, MaxLives, 0xFFFFFFFF )
			void ModifyScoreKill( class Controller* Killer, class Controller* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.ModifyScoreKill" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )( params + 0 ) = Killer;
				*( class Controller** )( params + 4 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DriverEnteredVehicle( class Vehicle* V, class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.DriverEnteredVehicle" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Vehicle** )( params + 0 ) = V;
				*( class Pawn** )( params + 4 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanLeaveVehicle( class Vehicle* V, class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.CanLeaveVehicle" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Vehicle** )( params + 0 ) = V;
				*( class Pawn** )( params + 4 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void DriverLeftVehicle( class Vehicle* V, class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.DriverLeftVehicle" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Vehicle** )( params + 0 ) = V;
				*( class Pawn** )( params + 4 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AllowMutator( ScriptArray< wchar_t > MutatorClassName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.AllowMutator" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = MutatorClassName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AllowCheats( class PlayerController* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.AllowCheats" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AllowPausing( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.AllowPausing" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bPauseable, 0x2 )
			ADD_VAR( ::BoolProperty, bAdminCanPause, 0x200 )
			void PreCommitMapChange( ScriptArray< wchar_t > PreviousMapName, ScriptArray< wchar_t > NextMapName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.PreCommitMapChange" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = PreviousMapName;
				*( ScriptArray< wchar_t >* )( params + 12 ) = NextMapName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostCommitMapChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.PostCommitMapChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddInactivePRI( class PlayerReplicationInfo* PRI, class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.AddInactivePRI" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerReplicationInfo** )( params + 0 ) = PRI;
				*( class PlayerController** )( params + 4 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool FindInactivePRI( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.FindInactivePRI" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetPRI( class PlayerController* PC, class PlayerReplicationInfo* NewPRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.SetPRI" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				*( class PlayerReplicationInfo** )( params + 4 ) = NewPRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OverridePRI( class PlayerController* PC, class PlayerReplicationInfo* OldPRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.OverridePRI" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				*( class PlayerReplicationInfo** )( params + 4 ) = OldPRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetSeamlessTravelActorList( bool bToEntry )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.GetSeamlessTravelActorList" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( bool* )( params + 0 ) = bToEntry;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SwapPlayerControllers( class PlayerController* OldPC, class PlayerController* NewPC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.SwapPlayerControllers" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerController** )( params + 0 ) = OldPC;
				*( class PlayerController** )( params + 4 ) = NewPC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostSeamlessTravel(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.PostSeamlessTravel" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::IntProperty, NumBots, 0xFFFFFFFF )
			void UpdateGameSettings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.UpdateGameSettings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HandleSeamlessTravelPlayer( class Controller* &C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.HandleSeamlessTravelPlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				C = *( class Controller** )( params + 0 );
			}

			void SetSeamlessTravelViewTarget( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.SetSeamlessTravelViewTarget" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateGameSettingsCounts(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.UpdateGameSettingsCounts" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProcessClientRegistrationCompletion( class PlayerController* PC, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.ProcessClientRegistrationCompletion" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				*( bool* )( params + 4 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartArbitrationRegistration(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.StartArbitrationRegistration" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartArbitratedMatch(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.StartArbitratedMatch" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RegisterServerForArbitration(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.RegisterServerForArbitration" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ArbitrationRegistrationComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.ArbitrationRegistrationComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool MatchIsInProgress(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.MatchIsInProgress" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, ArbitrationHandshakeTimeout, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bNeedsEndGameHandshake, 0x8000 )
			void NotifyArbitratedMatchEnd(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.NotifyArbitratedMatchEnd" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateGameplayMuteList( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.UpdateGameplayMuteList" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RecalculateSkillRating(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.RecalculateSkillRating" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MatineeCancelled(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.MatineeCancelled" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ProcessServerLogin(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.ProcessServerLogin" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ClearAutoLoginDelegates(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.ClearAutoLoginDelegates" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnLoginFailed( byte LocalUserNum, byte ErrorCode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.OnLoginFailed" );
				byte *params = ( byte* )( malloc( 2 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( byte* )( params + 1 ) = ErrorCode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnLoginChange( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.OnLoginChange" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RegisterServer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.RegisterServer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( ScriptClass, OnlineGameSettingsClass )
			void OnServerCreateComplete( ScriptName SessionName, bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.OnServerCreateComplete" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( bool* )( params + 8 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TellClientsToReturnToPartyHost(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.TellClientsToReturnToPartyHost" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TellClientsToTravelToSession( ScriptName SessionName, ScriptClass* SearchClass, byte PlatformSpecificInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.TellClientsToTravelToSession" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( ScriptName* )( params + 0 ) = SessionName;
				*( ScriptClass** )( params + 8 ) = SearchClass;
				*( byte* )( params + 12 ) = PlatformSpecificInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DoTravelTheWorld(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.DoTravelTheWorld" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsCheckingForFragmentation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.IsCheckingForFragmentation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsCheckingForMemLeaks(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.IsCheckingForMemLeaks" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShouldAutoContinueToNextRound(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.ShouldAutoContinueToNextRound" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CheckForSentinelRun(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.CheckForSentinelRun" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void BeginBVT( ScriptArray< wchar_t > TagDesc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.BeginBVT" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = TagDesc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableStandbyCheatDetection( bool bIsEnabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.EnableStandbyCheatDetection" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bIsEnabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StandbyCheatDetected( byte StandbyType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.StandbyCheatDetected" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = StandbyType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnEngineHasLoaded(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.GameInfo.OnEngineHasLoaded" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bKickLiveIdlers, 0x1000 )
			ADD_VAR( ::BoolProperty, bIsStandbyCheckingEnabled, 0x800000 )
			ADD_VAR( ::BoolProperty, bIsStandbyCheckingOn, 0x1000000 )
			ADD_VAR( ::BoolProperty, bHasStandbyCheatTriggered, 0x2000000 )
			ADD_VAR( ::IntProperty, GoreLevel, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CurrentID, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FearCostFallOff, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, GoalScore, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxIdleTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TimeMarginSlack, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinTimeMargin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StandbyRxCheatTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StandbyTxCheatTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, BadPingThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PercentMissingForRxStandby, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PercentMissingForTxStandby, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PercentForBadPing, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, JoinInProgressStandbyWaitTime, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DefaultGameType, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
