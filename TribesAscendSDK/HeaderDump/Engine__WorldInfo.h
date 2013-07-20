#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.WorldInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.WorldInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.WorldInfo." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class WorldInfo : public ZoneInfo
	{
	public:
			ADD_VAR( ::ByteProperty, NetMode, 0xFFFFFFFF )
			ADD_OBJECT( GameInfo, Game )
			ADD_VAR( ::FloatProperty, TimeSeconds, 0xFFFFFFFF )
			class Sequence* GetGameSequence(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.GetGameSequence" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Sequence** )( params + function->return_val_offset() );
			}

			void AllControllers( ScriptClass* BaseClass, class Controller* &C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.AllControllers" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )params = BaseClass;
				*( class Controller** )( params + 4 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				C = *( class Controller** )( params + 4 );
			}

			ADD_OBJECT( GameReplicationInfo, GRI )
			bool IsConsoleBuild( byte ConsoleType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.IsConsoleBuild" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = ConsoleType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_STRUCT( ::VectorProperty, DefaultColorScale, 0xFFFFFFFF )
			class WorldInfo* GetWorldInfo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.GetWorldInfo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class WorldInfo** )( params + function->return_val_offset() );
			}

			ADD_OBJECT( EmitterPool, MyEmitterPool )
			ADD_VAR( ::FloatProperty, TimeDilation, 0xFFFFFFFF )
			ScriptArray< wchar_t > GetMapName( bool bIncludePrefix )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.GetMapName" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bIncludePrefix;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptClass* GetGameClass(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.GetGameClass" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			ADD_OBJECT( PlayerReplicationInfo, Pauser )
			ADD_VAR( ::FloatProperty, MoveRepSize, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bPlayersOnly, 0x200 )
			void AllNavigationPoints( ScriptClass* BaseClass, class NavigationPoint* &N )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.AllNavigationPoints" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )params = BaseClass;
				*( class NavigationPoint** )( params + 4 ) = N;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				N = *( class NavigationPoint** )( params + 4 );
			}

			ADD_VAR( ::FloatProperty, StallZ, 0xFFFFFFFF )
			void ForceGarbageCollection( bool bFullPurge )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.ForceGarbageCollection" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bFullPurge;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsPreparingMapChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.IsPreparingMapChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PrepareMapChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.PrepareMapChange" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CommitMapChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.CommitMapChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CancelPendingMapChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.CancelPendingMapChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bRequestedBlockOnAsyncLoading, 0x80 )
			ADD_VAR( ::FloatProperty, PauseDelay, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WorldGravityZ, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bPlayersOnlyPending, 0x400 )
			ADD_VAR( ::FloatProperty, DemoPlayTimeDilation, 0xFFFFFFFF )
			void ReleaseCachedConstraintsAndEvaluators(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.ReleaseCachedConstraintsAndEvaluators" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class NavMeshPathConstraint* GetNavMeshPathConstraintFromCache( ScriptClass* ConstraintClass, class NavigationHandle* Requestor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.GetNavMeshPathConstraintFromCache" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )params = ConstraintClass;
				*( class NavigationHandle** )( params + 4 ) = Requestor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class NavMeshPathConstraint** )( params + function->return_val_offset() );
			}

			class NavMeshPathGoalEvaluator* GetNavMeshPathGoalEvaluatorFromCache( ScriptClass* GoalEvalClass, class NavigationHandle* Requestor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.GetNavMeshPathGoalEvaluatorFromCache" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )params = GoalEvalClass;
				*( class NavigationHandle** )( params + 4 ) = Requestor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class NavMeshPathGoalEvaluator** )( params + function->return_val_offset() );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateMusicTrack( void* NewMusicTrack )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.UpdateMusicTrack" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )params = NewMusicTrack;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddOnScreenDebugMessage( int Key, float TimeToDisplay, void* DisplayColor, ScriptArray< wchar_t > DebugMessage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.AddOnScreenDebugMessage" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( int* )params = Key;
				*( float* )( params + 4 ) = TimeToDisplay;
				*( void** )( params + 8 ) = DisplayColor;
				*( ScriptArray< wchar_t >* )( params + 12 ) = DebugMessage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsMenuLevel( ScriptArray< wchar_t > MapName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.IsMenuLevel" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = MapName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float GetGravityZ(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.GetGravityZ" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void* GetAllRootSequences(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.GetAllRootSequences" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void SetLevelRBGravity( Vector NewGrav )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.SetLevelRBGravity" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = NewGrav;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetLocalURL(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.GetLocalURL" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool IsDemoBuild(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.IsDemoBuild" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsPlayInEditor(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.IsPlayInEditor" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsPlayInPreview(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.IsPlayInPreview" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void VerifyNavList(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.VerifyNavList" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetAddressURL(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.GetAddressURL" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void ServerTravel( ScriptArray< wchar_t > URL, bool bAbsolute, bool bShouldSkipGameNotify )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.ServerTravel" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptArray< wchar_t >* )params = URL;
				*( bool* )( params + 12 ) = bAbsolute;
				*( bool* )( params + 16 ) = bShouldSkipGameNotify;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::ByteProperty, NextTravelType, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, NextURL, 0xFFFFFFFF )
			bool IsInSeamlessTravel(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.IsInSeamlessTravel" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, NextSwitchCountdown, 0xFFFFFFFF )
			void ThisIsNeverExecuted( class DefaultPhysicsVolume* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.ThisIsNeverExecuted" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class DefaultPhysicsVolume** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PreBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.PreBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::StrProperty, EmitterPoolClassPath, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DecalManagerClassPath, 0xFFFFFFFF )
			ADD_OBJECT( DecalManager, MyDecalManager )
			ADD_VAR( ::StrProperty, FractureManagerClassPath, 0xFFFFFFFF )
			ADD_OBJECT( FractureManager, MyFractureManager )
			ADD_VAR( ::StrProperty, ParticleEventManagerClassPath, 0xFFFFFFFF )
			ADD_OBJECT( ParticleEventManager, MyParticleEventManager )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::BoolProperty, bUseConsoleInput, 0x20000 )
			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RadiusNavigationPoints( ScriptClass* BaseClass, class NavigationPoint* &N, Vector Point, float Radius )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.RadiusNavigationPoints" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptClass** )params = BaseClass;
				*( class NavigationPoint** )( params + 4 ) = N;
				*( Vector* )( params + 8 ) = Point;
				*( float* )( params + 20 ) = Radius;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				N = *( class NavigationPoint** )( params + 4 );
			}

			void NavigationPointCheck( Vector Point, Vector Extent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.NavigationPointCheck" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( Vector* )params = Point;
				*( Vector* )( params + 12 ) = Extent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AllPawns( ScriptClass* BaseClass, class Pawn* &P, Vector TestLocation, float TestRadius )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.AllPawns" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptClass** )params = BaseClass;
				*( class Pawn** )( params + 4 ) = P;
				*( Vector* )( params + 8 ) = TestLocation;
				*( float* )( params + 20 ) = TestRadius;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				P = *( class Pawn** )( params + 4 );
			}

			void NotifyMatchStarted( bool bShouldActivateLevelStartupEvents, bool bShouldActivateLevelBeginningEvents, bool bShouldActivateLevelLoadedEvents )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.NotifyMatchStarted" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( bool* )params = bShouldActivateLevelStartupEvents;
				*( bool* )( params + 4 ) = bShouldActivateLevelBeginningEvents;
				*( bool* )( params + 8 ) = bShouldActivateLevelLoadedEvents;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsMapChangeReady(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.IsMapChangeReady" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SeamlessTravel( ScriptArray< wchar_t > URL, bool bAbsolute, void* MapPackageGuid )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.SeamlessTravel" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( ScriptArray< wchar_t >* )params = URL;
				*( bool* )( params + 12 ) = bAbsolute;
				*( void** )( params + 16 ) = MapPackageGuid;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetSeamlessTravelMidpointPause( bool bNowPaused )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.SetSeamlessTravelMidpointPause" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNowPaused;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class MapInfo* GetMapInfo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.GetMapInfo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class MapInfo** )( params + function->return_val_offset() );
			}

			void SetMapInfo( class MapInfo* NewMapInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.SetMapInfo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class MapInfo** )params = NewMapInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetDetailMode(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.GetDetailMode" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			bool IsRecordingDemo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.IsRecordingDemo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsPlayingDemo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.IsPlayingDemo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void GetDemoFrameInfo( int &CurrentFrame, int &TotalFrames )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.GetDemoFrameInfo" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = CurrentFrame;
				*( int* )( params + 4 ) = TotalFrames;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				CurrentFrame = *( int* )params;
				TotalFrames = *( int* )( params + 4 );
			}

			bool GetDemoRewindPoints(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.GetDemoRewindPoints" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void DoMemoryTracking(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.DoMemoryTracking" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* GetWorldFractureSettings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.GetWorldFractureSettings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			class EnvironmentVolume* FindEnvironmentVolume( Vector TestLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.FindEnvironmentVolume" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = TestLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class EnvironmentVolume** )( params + function->return_val_offset() );
			}

			bool BeginHostMigration(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.BeginHostMigration" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ToggleHostMigration( bool bEnabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.ToggleHostMigration" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearPhysicsPools(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.WorldInfo.ClearPhysicsPools" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( PostProcessChain, WorldPostProcessChain )
			ADD_VAR( ::BoolProperty, bPersistPostProcessToNextLevel, 0x1 )
			ADD_VAR( ::BoolProperty, bFogEnabled, 0x2 )
			ADD_VAR( ::BoolProperty, bBumpOffsetEnabled, 0x4 )
			ADD_VAR( ::BoolProperty, bMapNeedsLightingFullyRebuilt, 0x8 )
			ADD_VAR( ::BoolProperty, bMapHasDLEsOutsideOfImportanceVolume, 0x10 )
			ADD_VAR( ::BoolProperty, bMapHasMultipleDominantLightsAffectingOnePrimitive, 0x20 )
			ADD_VAR( ::BoolProperty, bMapHasPathingErrors, 0x40 )
			ADD_VAR( ::BoolProperty, bBegunPlay, 0x100 )
			ADD_VAR( ::BoolProperty, bDropDetail, 0x800 )
			ADD_VAR( ::BoolProperty, bAggressiveLOD, 0x1000 )
			ADD_VAR( ::BoolProperty, bStartup, 0x2000 )
			ADD_VAR( ::BoolProperty, bPathsRebuilt, 0x4000 )
			ADD_VAR( ::BoolProperty, bHasPathNodes, 0x8000 )
			ADD_VAR( ::BoolProperty, bIsMenuLevel, 0x10000 )
			ADD_VAR( ::BoolProperty, bNoDefaultInventoryForPlayer, 0x40000 )
			ADD_VAR( ::BoolProperty, bNoPathWarnings, 0x80000 )
			ADD_VAR( ::BoolProperty, bHighPriorityLoading, 0x100000 )
			ADD_VAR( ::BoolProperty, bHighPriorityLoadingLocal, 0x200000 )
			ADD_VAR( ::BoolProperty, bUseProcBuildingRulesetOverride, 0x400000 )
			ADD_VAR( ::BoolProperty, bSupportDoubleBufferedPhysics, 0x800000 )
			ADD_VAR( ::BoolProperty, bEnableChanceOfPhysicsChunkOverride, 0x1000000 )
			ADD_VAR( ::BoolProperty, bLimitExplosionChunkSize, 0x2000000 )
			ADD_VAR( ::BoolProperty, bLimitDamageChunkSize, 0x4000000 )
			ADD_VAR( ::BoolProperty, bPrecomputeVisibility, 0x8000000 )
			ADD_VAR( ::BoolProperty, bPlaceCellsOnSurfaces, 0x10000000 )
			ADD_VAR( ::BoolProperty, bAllowLightEnvSphericalHarmonicLights, 0x20000000 )
			ADD_VAR( ::BoolProperty, bAllowModulateBetterShadows, 0x40000000 )
			ADD_VAR( ::BoolProperty, bIncreaseFogNearPrecision, 0x80000000 )
			ADD_VAR( ::BoolProperty, bUseGlobalIllumination, 0x1 )
			ADD_VAR( ::BoolProperty, bForceNoPrecomputedLighting, 0x2 )
			ADD_VAR( ::BoolProperty, bSimpleLightmapsStoredInLinearSpace, 0x4 )
			ADD_VAR( ::BoolProperty, bHaveActiveCrowd, 0x8 )
			ADD_VAR( ::BoolProperty, bAllowHostMigration, 0x10 )
			ADD_VAR( ::FloatProperty, SquintModeKernelSize, 0xFFFFFFFF )
			ADD_OBJECT( PostProcessVolume, HighestPriorityPostProcessVolume )
			ADD_VAR( ::FloatProperty, FogStart, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FogEnd, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BumpEnd, 0xFFFFFFFF )
			ADD_OBJECT( ReverbVolume, HighestPriorityReverbVolume )
			ADD_OBJECT( BookMark, BookMarks )
			ADD_OBJECT( KismetBookMark, KismetBookMarks )
			ADD_VAR( ::FloatProperty, RealTimeSeconds, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AudioTimeSeconds, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DeltaSeconds, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RealTimeToUnPause, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, VisibleGroups, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SelectedGroups, 0xFFFFFFFF )
			ADD_OBJECT( Texture2D, DefaultTexture )
			ADD_OBJECT( Texture2D, WireframeTexture )
			ADD_OBJECT( Texture2D, WhiteSquareTexture )
			ADD_OBJECT( Texture2D, LargeVertex )
			ADD_OBJECT( Texture2D, BSPVertex )
			ADD_VAR( ::ByteProperty, VisibilityAggressiveness, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, LevelLightingQuality, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ComputerName, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, EngineVersion, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, MinNetVersion, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DefaultGravityZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, GlobalGravityZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RBPhysicsGravityScaling, 0xFFFFFFFF )
			ADD_OBJECT( NavigationPoint, NavigationPointList )
			ADD_OBJECT( Controller, ControllerList )
			ADD_OBJECT( Pawn, PawnList )
			ADD_OBJECT( CoverLink, CoverList )
			ADD_OBJECT( Pylon, PylonList )
			ADD_VAR( ::IntProperty, PackedLightAndShadowMapTextureSize, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, GameTypeForPIE )
			ADD_VAR( ::NameProperty, CommittedPersistentLevelName, 0xFFFFFFFF )
			ADD_OBJECT( ObjectReferencer, PersistentMapForcedObjects )
			ADD_VAR( ::StrProperty, Title, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Author, 0xFFFFFFFF )
			ADD_OBJECT( MapInfo, MyMapInfo )
			ADD_OBJECT( ProcBuildingRuleset, ProcBuildingRulesetOverride )
			ADD_VAR( ::FloatProperty, MaxPhysicsDeltaTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxPhysicsSubsteps, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DefaultSkinWidth, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ApexLODResourceBudget, 0xFFFFFFFF )
			ADD_OBJECT( PhysicsLODVerticalEmitter, EmitterVertical )
			ADD_VAR( ::FloatProperty, ChanceOfPhysicsChunkOverride, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxExplosionChunkSize, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxDamageChunkSize, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FractureExplosionVelScale, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxNumFacturedChunksToSpawnInAFrame, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumFacturedChunksSpawnedThisFrame, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FracturedMeshWeaponDamage, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, VisibilityCellSize, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CharacterLitIndirectBrightness, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CharacterLitIndirectContrastFactor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CharacterShadowedIndirectBrightness, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CharacterShadowedIndirectContrastFactor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CharacterLightingContrastFactor, 0xFFFFFFFF )
			ADD_OBJECT( Texture2D, ImageReflectionEnvironmentTexture )
			ADD_VAR( ::FloatProperty, ImageReflectionEnvironmentRotation, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxTrianglesPerLeaf, 0xFFFFFFFF )
			ADD_OBJECT( LightmassLevelSettings, LMLevelSettings )
			ADD_OBJECT( CrowdPopulationManagerBase, PopulationManager )
			ADD_VAR( ::FloatProperty, HostMigrationTimeout, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
