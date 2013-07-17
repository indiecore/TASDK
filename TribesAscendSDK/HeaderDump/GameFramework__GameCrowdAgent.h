#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.GameCrowdAgent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.GameCrowdAgent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.GameCrowdAgent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameCrowdAgent : public CrowdAgentBase
	{
	public:
			ADD_VAR( ::FloatProperty, InitialLastRenderTime, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, SpawnOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxLOSLifeDistanceSq, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DesiredGroupRadiusSq, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DesiredGroupRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ReachThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ForceUpdateTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RandomBehaviorInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SeePlayerInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxSeePlayerDistSq, 0xFFFFFFFF )
			ADD_OBJECT( GameCrowdAgentBehavior, CurrentBehavior )
			ADD_OBJECT( SoundCue, AmbientSoundCue )
			ADD_OBJECT( Texture2D, BeaconTexture )
			ADD_STRUCT( ::VectorProperty, BeaconOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BeaconMaxDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxRunningSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxWalkingSpeed, 0xFFFFFFFF )
			ADD_OBJECT( GameCrowdAgent, MyArchetype )
			ADD_VAR( ::FloatProperty, NotVisibleTickScalingFactor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, NotVisibleLifeSpan, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastUpdateTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastPathingAttempt, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WalkableFloorZ, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ObstacleCheckCount, 0xFFFFFFFF )
			ADD_OBJECT( NavigationHandle, NavigationHandle )
			ADD_OBJECT( ScriptClass, NavigationHandleClass )
			ADD_STRUCT( ::VectorProperty, SearchExtent, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, IntermediatePoint, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, GroundOffset, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastKnownGoodPosition, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, VisibleProximityLODDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ProximityLODDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EyeZOffset, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, MeshMaxScale3D, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, MeshMinScale3D, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxYawRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RotateToTargetSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, VelocityDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FollowPathStrength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MatchVelStrength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, GroupAttractionStrength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AvoidOtherRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AvoidPlayerStrength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AvoidOtherStrength, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AwareUpdateInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AwareRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastGroundZ, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CurrentConformTraceInterval, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ConformTraceInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ConformTraceDist, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ConformType, 0xFFFFFFFF )
			ADD_OBJECT( GameCrowdGroup, MyGroup )
			ADD_VAR( ::BoolProperty, bIsInSpawnPool, 0x8000 )
			ADD_VAR( ::BoolProperty, bHasNotifiedSpawner, 0x4000 )
			ADD_VAR( ::BoolProperty, bPreferVisibleDestinationOnSpawn, 0x2000 )
			ADD_VAR( ::BoolProperty, bPreferVisibleDestination, 0x1000 )
			ADD_VAR( ::BoolProperty, bWantsGroupIdle, 0x800 )
			ADD_VAR( ::BoolProperty, bIsPanicked, 0x400 )
			ADD_VAR( ::BoolProperty, bPotentialEncounter, 0x200 )
			ADD_VAR( ::BoolProperty, bClampMovementSpeed, 0x100 )
			ADD_VAR( ::BoolProperty, bSimulateThisTick, 0x80 )
			ADD_VAR( ::BoolProperty, bBadHitNormal, 0x40 )
			ADD_VAR( ::BoolProperty, bHitObstacle, 0x20 )
			ADD_VAR( ::BoolProperty, bAllowPitching, 0x10 )
			ADD_VAR( ::BoolProperty, bWantsSeePlayerNotification, 0x8 )
			ADD_VAR( ::BoolProperty, bUseNavMeshPathing, 0x4 )
			ADD_VAR( ::BoolProperty, bCheckForObstacles, 0x2 )
			ADD_VAR( ::BoolProperty, bUniformScale, 0x1 )
			ADD_VAR( ::IntProperty, AwareUpdateFrameCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ConformTraceFrameCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DeadBodyDuration, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Health, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, InterpZTranslation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, ExternalForce, 0xFFFFFFFF )
			ADD_OBJECT( GameCrowdDestination, PreviousDestination )
			ADD_OBJECT( GameCrowdDestination, BehaviorDestination )
			ADD_OBJECT( GameCrowdDestination, CurrentDestination )
			ADD_VAR( ::FloatProperty, AvoidanceShare, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PreferredVelocity, 0xFFFFFFFF )
			bool PickBehaviorFrom( Vector BestCameraLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.PickBehaviorFrom" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 12 ) = BestCameraLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void FellOutOfWorld( ScriptClass* dmgType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.FellOutOfWorld" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = dmgType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsPanicked(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.IsPanicked" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetPanic( class Actor* PanicActor, bool bNewPanic )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.SetPanic" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )( params + 0 ) = PanicActor;
				*( bool* )( params + 4 ) = bNewPanic;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void WaitForGroupMembers(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.WaitForGroupMembers" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetCurrentDestination( class GameCrowdDestination* NewDest )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.SetCurrentDestination" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCrowdDestination** )( params + 0 ) = NewDest;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMaxSpeed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.SetMaxSpeed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KillAgent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.KillAgent" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetPooledAgent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.ResetPooledAgent" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisplayDebug( class HUD* HUD, float &out_YL, float &out_YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.DisplayDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class HUD** )( params + 0 ) = HUD;
				*( float* )( params + 4 ) = out_YL;
				*( float* )( params + 8 ) = out_YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_YL = *( float* )( params + 4 );
				out_YPos = *( float* )( params + 8 );
			}

			void SetLighting( bool bEnableLightEnvironment, void* AgentLightingChannel, bool bCastShadows )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.SetLighting" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( bool* )( params + 0 ) = bEnableLightEnvironment;
				*( void** )( params + 4 ) = AgentLightingChannel;
				*( bool* )( params + 8 ) = bCastShadows;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitializeAgent( class Actor* SpawnLoc, class GameCrowdAgent* AgentTemplate, class GameCrowdGroup* NewGroup, float AgentWarmupTime, bool bWarmupPosition, bool bCheckWarmupVisibility )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.InitializeAgent" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( class Actor** )( params + 0 ) = SpawnLoc;
				*( class GameCrowdAgent** )( params + 4 ) = AgentTemplate;
				*( class GameCrowdGroup** )( params + 8 ) = NewGroup;
				*( float* )( params + 12 ) = AgentWarmupTime;
				*( bool* )( params + 16 ) = bWarmupPosition;
				*( bool* )( params + 20 ) = bCheckWarmupVisibility;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPlayAgentAnimation( class SeqAct_PlayAgentAnimation* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.OnPlayAgentAnimation" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_PlayAgentAnimation** )( params + 0 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayIdleAnimation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.PlayIdleAnimation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopIdleAnimation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.StopIdleAnimation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HandlePotentialAgentEncounter(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.HandlePotentialAgentEncounter" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlaySpawnBehavior(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.PlaySpawnBehavior" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifySeePlayer( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.NotifySeePlayer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TryRandomBehavior(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.TryRandomBehavior" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetSeePlayer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.ResetSeePlayer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ActivateBehavior( class GameCrowdAgentBehavior* NewBehaviorArchetype, class Actor* LookAtActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.ActivateBehavior" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class GameCrowdAgentBehavior** )( params + 0 ) = NewBehaviorArchetype;
				*( class Actor** )( params + 4 ) = LookAtActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetCurrentBehavior( class GameCrowdAgentBehavior* BehaviorArchetype )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.SetCurrentBehavior" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCrowdAgentBehavior** )( params + 0 ) = BehaviorArchetype;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ActivateInstancedBehavior( class GameCrowdAgentBehavior* NewBehaviorObject )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.ActivateInstancedBehavior" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCrowdAgentBehavior** )( params + 0 ) = NewBehaviorObject;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopBehavior(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.StopBehavior" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsIdle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.IsIdle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CalcCamera( float fDeltaTime, Vector &out_CamLoc, Rotator &out_CamRot, float &out_FOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.CalcCamera" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( float* )( params + 0 ) = fDeltaTime;
				*( Vector* )( params + 4 ) = out_CamLoc;
				*( Rotator* )( params + 16 ) = out_CamRot;
				*( float* )( params + 28 ) = out_FOV;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_CamLoc = *( Vector* )( params + 4 );
				out_CamRot = *( Rotator* )( params + 16 );
				out_FOV = *( float* )( params + 28 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void UpdateIntermediatePoint( class Actor* DestinationActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.UpdateIntermediatePoint" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = DestinationActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayDeath( Vector KillMomentum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.PlayDeath" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = KillMomentum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FireDeathEvent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.FireDeathEvent" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeDamage( int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, void* HitInfo, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.TakeDamage" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( int* )( params + 0 ) = DamageAmount;
				*( class Controller** )( params + 4 ) = EventInstigator;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = Momentum;
				*( ScriptClass** )( params + 32 ) = DamageType;
				*( void** )( params + 36 ) = HitInfo;
				*( class Actor** )( params + 64 ) = DamageCauser;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OverlappedActorEvent( class Actor* A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.OverlappedActorEvent" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitNavigationHandle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.InitNavigationHandle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector GeneratePathToActor( class Actor* Goal, float WithinDistance, bool bAllowPartialPath )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.GeneratePathToActor" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class Actor** )( params + 0 ) = Goal;
				*( float* )( params + 4 ) = WithinDistance;
				*( bool* )( params + 8 ) = bAllowPartialPath;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void NativePostRenderFor( class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.NativePostRenderFor" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( Vector* )( params + 8 ) = CameraPosition;
				*( Vector* )( params + 20 ) = CameraDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostRenderFor( class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.PostRenderFor" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( Vector* )( params + 8 ) = CameraPosition;
				*( Vector* )( params + 20 ) = CameraDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetDestString(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.GetDestString" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetBehaviorString(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgent.GetBehaviorString" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
