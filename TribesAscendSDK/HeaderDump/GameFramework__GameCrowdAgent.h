#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " GameFramework.GameCrowdAgent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty GameFramework.GameCrowdAgent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty GameFramework.GameCrowdAgent." #y ) ); \
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
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
