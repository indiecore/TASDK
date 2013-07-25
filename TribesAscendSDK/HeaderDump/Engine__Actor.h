#pragma once
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__SoundCue.h"
#include "Core__Property.h"
#include "Engine__SeqAct_ToggleHidden.h"
#include "Core__Object.h"
#include "Engine__Projectile.h"
#include "Engine__AnimNodeSequence.h"
#include "Engine__WorldInfo.h"
#include "Engine__Pawn.h"
#include "Engine__Teleporter.h"
#include "Engine__Controller.h"
#include "Engine__PhysicsVolume.h"
#include "Engine__SeqAct_ModifyHealth.h"
#include "Engine__PlayerController.h"
#include "Engine__RB_ConstraintSetup.h"
#include "Engine__RB_ConstraintInstance.h"
#include "Engine__SkelControlLookAt.h"
#include "Engine__InterpGroup.h"
#include "Engine__HUD.h"
#include "Engine__FluidSurfaceActor.h"
#include "Engine__SequenceEvent.h"
#include "Engine__SeqAct_Destroy.h"
#include "Engine__SeqAct_Latent.h"
#include "Engine__SeqAct_Teleport.h"
#include "Engine__SeqAct_SetVelocity.h"
#include "Engine__SeqAct_SetBlockRigidBody.h"
#include "Engine__SeqAct_SetPhysics.h"
#include "Engine__SeqAct_ChangeCollision.h"
#include "Engine__RB_BodyInstance.h"
#include "Engine__SeqAct_AttachToActor.h"
#include "Engine__FaceFXAnimSet.h"
#include "Engine__FaceFXAsset.h"
#include "Engine__SeqAct_Interp.h"
#include "Engine__AnimNotify_PlayParticleEffect.h"
#include "Engine__InterpGroupInst.h"
#include "Engine__SVehicle.h"
#include "Engine__AnimNotify_ForceField.h"
#include "Engine__Canvas.h"
#include "Engine__AnimNotify_Trails.h"
#include "Engine__SequenceOp.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Actor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Actor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Actor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Actor : public Object
	{
	public:
		ADD_VAR(::BoolProperty, bGameRelevant, 0x10000)
		ADD_VAR(::BoolProperty, bStatic, 0x1)
		ADD_OBJECT(WorldInfo, WorldInfo)
		ADD_VAR(::BoolProperty, bNoDelete, 0x4)
		ADD_VAR(::BoolProperty, bScriptInitialized, 0x800000)
		ADD_VAR(::NameProperty, InitialState, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bProjTarget, 0x80000000)
		ADD_VAR(::BoolProperty, bBlockActors, 0x40000000)
		ADD_OBJECT(Pawn, Instigator)
		ADD_VAR(::BoolProperty, bHurtEntry, 0x8000)
		ADD_VAR(::BoolProperty, bWorldGeometry, 0x80)
		ADD_VAR(::BoolProperty, bCanBeDamaged, 0x80000)
		ADD_STRUCT(::VectorProperty, Location, 0xFFFFFFFF
		ADD_STRUCT(::RotatorProperty, Rotation, 0xFFFFFFFF
		ADD_VAR(::BoolProperty, bDeleteMe, 0x8)
		ADD_VAR(::ByteProperty, Role, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, RemoteRole, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bTearOff, 0x4000000)
		ADD_OBJECT(PhysicsVolume, PhysicsVolume)
		ADD_OBJECT(Actor, Base)
		ADD_VAR(::BoolProperty, bBounce, 0x200)
		ADD_VAR(::BoolProperty, bHardAttach, 0x400)
		ADD_STRUCT(::VectorProperty, RelativeLocation, 0xFFFFFFFF
		ADD_STRUCT(::RotatorProperty, RelativeRotation, 0xFFFFFFFF
		ADD_VAR(::NameProperty, BaseBoneName, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Velocity, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, Acceleration, 0xFFFFFFFF
		ADD_VAR(::BoolProperty, bCollideActors, 0x8000000)
		ADD_VAR(::BoolProperty, bCollideWorld, 0x10000000)
		ADD_OBJECT(Actor, Owner)
		ADD_VAR(::ByteProperty, Physics, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAllowFluidSurfaceInteraction, 0x10000000)
		ADD_VAR(::BoolProperty, bDebugEffectIsRelevant, 0x8000000)
		ADD_VAR(::FloatProperty, LastRenderTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAlwaysRelevant, 0x200000)
		ADD_VAR(::FloatProperty, NetUpdateFrequency, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bForceNetUpdate, 0x100)
		ADD_VAR(::BoolProperty, bHidden, 0x2)
		ADD_VAR(::BoolProperty, bUpdateSimulatedPosition, 0x2000000)
		ADD_VAR(::BoolProperty, bNetDirty, 0x100000)
		ADD_VAR(::BoolProperty, bOnlyDirtyReplication, 0x8000000)
		ADD_VAR(::BoolProperty, bCanBeFrictionedTo, 0x4000)
		ADD_VAR(::BoolProperty, bCanBeAdheredTo, 0x2000)
		ADD_VAR(::BoolProperty, bSkipActorPropertyReplication, 0x1000000)
		ADD_VAR(::BoolProperty, bNetInitial, 0x800)
		ADD_VAR(::BoolProperty, bReplicateMovement, 0x800000)
		ADD_VAR(::BoolProperty, bReplicateInstigator, 0x400000)
		ADD_VAR(::BoolProperty, bNetOwner, 0x1000)
		ADD_VAR(::FloatProperty, DrawScale, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, DrawScale3D, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, PrePivot, 0xFFFFFFFF
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'EditorIconColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.RenderCommandFence' for the property named 'DetachFence'!
		ADD_VAR(::FloatProperty, CustomTimeDilation, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, CollisionType, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ReplicatedCollisionType, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, TickGroup, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bTicked, 0x10)
		ADD_VAR(::BoolProperty, bOnlyOwnerSee, 0x20)
		ADD_VAR(::BoolProperty, bTickIsDisabled, 0x40)
		ADD_VAR(::BoolProperty, bIgnoreRigidBodyPawns, 0x100)
		ADD_VAR(::BoolProperty, bOrientOnSlope, 0x200)
		ADD_VAR(::BoolProperty, bIgnoreEncroachers, 0x400)
		ADD_VAR(::BoolProperty, bPushedByEncroachers, 0x800)
		ADD_VAR(::BoolProperty, bDestroyedByInterpActor, 0x1000)
		ADD_VAR(::BoolProperty, bRouteBeginPlayEvenIfStatic, 0x2000)
		ADD_VAR(::BoolProperty, bIsMoving, 0x4000)
		ADD_VAR(::BoolProperty, bAlwaysEncroachCheck, 0x8000)
		ADD_VAR(::BoolProperty, bHasAlternateTargetLocation, 0x10000)
		ADD_VAR(::BoolProperty, bCanStepUpOn, 0x20000)
		ADD_VAR(::BoolProperty, bNetTemporary, 0x40000)
		ADD_VAR(::BoolProperty, bOnlyRelevantToOwner, 0x80000)
		ADD_VAR(::BoolProperty, bDemoRecording, 0x20000000)
		ADD_VAR(::BoolProperty, bDemoOwner, 0x40000000)
		ADD_VAR(::BoolProperty, bForceDemoRelevant, 0x80000000)
		ADD_VAR(::BoolProperty, bNetInitialRotation, 0x1)
		ADD_VAR(::BoolProperty, bReplicateRigidBodyLocation, 0x2)
		ADD_VAR(::BoolProperty, bKillDuringLevelTransition, 0x4)
		ADD_VAR(::BoolProperty, bExchangedRoles, 0x8)
		ADD_VAR(::BoolProperty, bConsiderAllStaticMeshComponentsForStreaming, 0x10)
		ADD_VAR(::BoolProperty, bDebug, 0x20)
		ADD_VAR(::BoolProperty, bPostRenderIfNotVisible, 0x40)
		ADD_VAR(::BoolProperty, s_bThrottleNetRelevancy, 0x80)
		ADD_VAR(::BoolProperty, bPendingNetUpdate, 0x200)
		ADD_VAR(::BoolProperty, bIgnoreBaseRotation, 0x800)
		ADD_VAR(::BoolProperty, bShadowParented, 0x1000)
		ADD_VAR(::BoolProperty, bMovable, 0x20000)
		ADD_VAR(::BoolProperty, bDestroyInPainVolume, 0x40000)
		ADD_VAR(::BoolProperty, bShouldBaseAtStartup, 0x100000)
		ADD_VAR(::BoolProperty, bPendingDelete, 0x200000)
		ADD_VAR(::BoolProperty, bCanTeleport, 0x400000)
		ADD_VAR(::BoolProperty, bAlwaysTick, 0x800000)
		ADD_VAR(::BoolProperty, bBlocksNavigation, 0x1000000)
		ADD_VAR(::BoolProperty, BlockRigidBody, 0x2000000)
		ADD_VAR(::BoolProperty, bCollideWhenPlacing, 0x4000000)
		ADD_VAR(::BoolProperty, bCollideComplex, 0x20000000)
		ADD_VAR(::BoolProperty, bBlocksTeleport, 0x1)
		ADD_VAR(::BoolProperty, bMoveIgnoresDestruction, 0x2)
		ADD_VAR(::BoolProperty, bNoEncroachCheck, 0x4)
		ADD_VAR(::BoolProperty, bCollideAsEncroacher, 0x8)
		ADD_VAR(::BoolProperty, bPhysRigidBodyOutOfWorldCheck, 0x10)
		ADD_VAR(::BoolProperty, bComponentOutsideWorld, 0x20)
		ADD_VAR(::BoolProperty, bForceOctreeSNFilter, 0x40)
		ADD_VAR(::BoolProperty, bRigidBodyWasAwake, 0x80)
		ADD_VAR(::BoolProperty, bCallRigidBodyWakeEvents, 0x100)
		ADD_VAR(::BoolProperty, bJustTeleported, 0x400)
		ADD_VAR(::BoolProperty, bHiddenEd, 0x2000)
		ADD_VAR(::BoolProperty, bEditable, 0x4000)
		ADD_VAR(::BoolProperty, bHiddenEdGroup, 0x8000)
		ADD_VAR(::BoolProperty, bHiddenEdCustom, 0x10000)
		ADD_VAR(::BoolProperty, bHiddenEdTemporary, 0x20000)
		ADD_VAR(::BoolProperty, bHiddenEdLevel, 0x40000)
		ADD_VAR(::BoolProperty, bEdShouldSnap, 0x80000)
		ADD_VAR(::BoolProperty, bTempEditor, 0x100000)
		ADD_VAR(::BoolProperty, bPathColliding, 0x200000)
		ADD_VAR(::BoolProperty, bPathTemp, 0x400000)
		ADD_VAR(::BoolProperty, bLockLocation, 0x1000000)
		ADD_VAR(::BoolProperty, bForceAllowKismetModification, 0x2000000)
		ADD_VAR(::BoolProperty, m_bPotentialSeekingTarget, 0x4000000)
		ADD_VAR(::IntProperty, NetTag, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, IndexInTickList, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastSlowRelevancyCheckTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NetUpdateTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NetPriority, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastNetUpdateTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeSinceLastTick, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TickFrequency, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TickFrequencyAtEndDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TickFrequencyDecreaseDistanceStart, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TickFrequencyDecreaseDistanceEnd, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TickFrequencyLastSeenTimeBeforeForcingMaxTickFrequency, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LifeSpan, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CreationTime, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, Tag, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, Group, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.QWord' for the property named 'HiddenEditorViews'!
		ADD_VAR(::FloatProperty, LatentFloat, 0xFFFFFFFF)
		ADD_OBJECT(AnimNodeSequence, LatentSeqNode)
		ADD_STRUCT(::VectorProperty, AngularVelocity, 0xFFFFFFFF
		ADD_VAR(::IntProperty, OverlapTag, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, RotationRate, 0xFFFFFFFF
		ADD_OBJECT(Actor, PendingTouch)
		ADD_OBJECT(ScriptClass, MessageClass)
		// Here lies the not-yet-implemented method 'ForceUpdateComponents'
		// Here lies the not-yet-implemented method 'ConsoleCommand'
		// Here lies the not-yet-implemented method 'Sleep'
		// Here lies the not-yet-implemented method 'FinishAnim'
		// Here lies the not-yet-implemented method 'SetCollision'
		// Here lies the not-yet-implemented method 'SetCollisionSize'
		// Here lies the not-yet-implemented method 'SetCollisionType'
		// Here lies the not-yet-implemented method 'SetDrawScale'
		// Here lies the not-yet-implemented method 'SetDrawScale3D'
		// Here lies the not-yet-implemented method 'Move'
		// Here lies the not-yet-implemented method 'SetLocation'
		// Here lies the not-yet-implemented method 'SetRotation'
		// Here lies the not-yet-implemented method 'MovingWhichWay'
		// Here lies the not-yet-implemented method 'SetZone'
		// Here lies the not-yet-implemented method 'SetRelativeRotation'
		// Here lies the not-yet-implemented method 'SetRelativeLocation'
		// Here lies the not-yet-implemented method 'SetHardAttach'
		// Here lies the not-yet-implemented method 'fixedTurn'
		// Here lies the not-yet-implemented method 'MoveSmooth'
		// Here lies the not-yet-implemented method 'AutonomousPhysics'
		// Here lies the not-yet-implemented method 'GetTerminalVelocity'
		// Here lies the not-yet-implemented method 'SetBase'
		// Here lies the not-yet-implemented method 'SetOwner'
		// Here lies the not-yet-implemented method 'FindBase'
		// Here lies the not-yet-implemented method 'IsBasedOn'
		// Here lies the not-yet-implemented method 'GetBaseMost'
		// Here lies the not-yet-implemented method 'IsOwnedBy'
		// Here lies the not-yet-implemented method 'GetAggregateBaseVelocity'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'SetForcedInitialReplicatedProperty'
		// Here lies the not-yet-implemented method 'Vect2BP'
		// Here lies the not-yet-implemented method 'BP2Vect'
		// Here lies the not-yet-implemented method 'SetBasedPosition'
		// Here lies the not-yet-implemented method 'GetBasedPosition'
		// Here lies the not-yet-implemented method 'FlushPersistentDebugLines'
		// Here lies the not-yet-implemented method 'DrawDebugLine'
		// Here lies the not-yet-implemented method 'DrawDebugPoint'
		// Here lies the not-yet-implemented method 'DrawDebugBox'
		// Here lies the not-yet-implemented method 'DrawDebugStar'
		// Here lies the not-yet-implemented method 'DrawDebugCoordinateSystem'
		// Here lies the not-yet-implemented method 'DrawDebugSphere'
		// Here lies the not-yet-implemented method 'DrawDebugCylinder'
		// Here lies the not-yet-implemented method 'DrawDebugCone'
		// Here lies the not-yet-implemented method 'DrawDebugString'
		// Here lies the not-yet-implemented method 'DrawDebugFrustrum'
		// Here lies the not-yet-implemented method 'FlushDebugStrings'
		// Here lies the not-yet-implemented method 'ChartData'
		// Here lies the not-yet-implemented method 'SetHidden'
		// Here lies the not-yet-implemented method 'SetOnlyOwnerSee'
		// Here lies the not-yet-implemented method 'SetPhysics'
		// Here lies the not-yet-implemented method 'Clock'
		// Here lies the not-yet-implemented method 'UnClock'
		// Here lies the not-yet-implemented method 'AttachComponent'
		// Here lies the not-yet-implemented method 'DetachComponent'
		// Here lies the not-yet-implemented method 'ReattachComponent'
		// Here lies the not-yet-implemented method 'SetTickGroup'
		// Here lies the not-yet-implemented method 'SetTickIsDisabled'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'GainedChild'
		// Here lies the not-yet-implemented method 'LostChild'
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'Timer'
		// Here lies the not-yet-implemented method 'HitWall'
		// Here lies the not-yet-implemented method 'Falling'
		// Here lies the not-yet-implemented method 'Landed'
		// Here lies the not-yet-implemented method 'PhysicsVolumeChange'
		// Here lies the not-yet-implemented method 'Touch'
		// Here lies the not-yet-implemented method 'PostTouch'
		// Here lies the not-yet-implemented method 'UnTouch'
		// Here lies the not-yet-implemented method 'Bump'
		// Here lies the not-yet-implemented method 'BaseChange'
		// Here lies the not-yet-implemented method 'Attach'
		// Here lies the not-yet-implemented method 'Detach'
		// Here lies the not-yet-implemented method 'SpecialHandling'
		// Here lies the not-yet-implemented method 'CollisionChanged'
		// Here lies the not-yet-implemented method 'EncroachingOn'
		// Here lies the not-yet-implemented method 'EncroachedBy'
		// Here lies the not-yet-implemented method 'RanInto'
		// Here lies the not-yet-implemented method 'OnWakeRBPhysics'
		// Here lies the not-yet-implemented method 'OnSleepRBPhysics'
		// Here lies the not-yet-implemented method 'ClampRotation'
		// Here lies the not-yet-implemented method 'OverRotated'
		// Here lies the not-yet-implemented method 'UsedBy'
		// Here lies the not-yet-implemented method 'FellOutOfWorld'
		// Here lies the not-yet-implemented method 'OutsideWorldBounds'
		// Here lies the not-yet-implemented method 'VolumeBasedDestroy'
		// Here lies the not-yet-implemented method 'Trace'
		// Here lies the not-yet-implemented method 'TraceComponent'
		// Here lies the not-yet-implemented method 'PointCheckComponent'
		// Here lies the not-yet-implemented method 'FastTrace'
		// Here lies the not-yet-implemented method 'TraceAllPhysicsAssetInteractions'
		// Here lies the not-yet-implemented method 'FindSpot'
		// Here lies the not-yet-implemented method 'ContainsPoint'
		// Here lies the not-yet-implemented method 'IsOverlapping'
		// Here lies the not-yet-implemented method 'GetComponentsBoundingBox'
		// Here lies the not-yet-implemented method 'GetBoundingCylinder'
		// Here lies the not-yet-implemented method 'IsBlockedBy'
		// Here lies the not-yet-implemented method 'Spawn'
		// Here lies the not-yet-implemented method 'Destroy'
		// Here lies the not-yet-implemented method 'TornOff'
		// Here lies the not-yet-implemented method 'SetTimer'
		// Here lies the not-yet-implemented method 'ClearTimer'
		// Here lies the not-yet-implemented method 'ClearAllTimers'
		// Here lies the not-yet-implemented method 'PauseTimer'
		// Here lies the not-yet-implemented method 'IsTimerActive'
		// Here lies the not-yet-implemented method 'GetTimerCount'
		// Here lies the not-yet-implemented method 'GetTimerRate'
		// Here lies the not-yet-implemented method 'GetRemainingTimeForTimer'
		// Here lies the not-yet-implemented method 'ModifyTimerTimeDilation'
		// Here lies the not-yet-implemented method 'ResetTimerTimeDilation'
		// Here lies the not-yet-implemented method 'CreateAudioComponent'
		// Here lies the not-yet-implemented method 'PlaySound'
		// Here lies the not-yet-implemented method 'MakeNoise'
		// Here lies the not-yet-implemented method 'PlayerCanSeeMe'
		// Here lies the not-yet-implemented method 'SuggestTossVelocity'
		// Here lies the not-yet-implemented method 'CalculateMinSpeedTrajectory'
		// Here lies the not-yet-implemented method 'GetDestination'
		// Here lies the not-yet-implemented method 'PreTeleport'
		// Here lies the not-yet-implemented method 'PostTeleport'
		// Here lies the not-yet-implemented method 'GetURLMap'
		// Here lies the not-yet-implemented method 'AllActors'
		// Here lies the not-yet-implemented method 'DynamicActors'
		// Here lies the not-yet-implemented method 'ChildActors'
		// Here lies the not-yet-implemented method 'BasedActors'
		// Here lies the not-yet-implemented method 'TouchingActors'
		// Here lies the not-yet-implemented method 'TraceActors'
		// Here lies the not-yet-implemented method 'VisibleActors'
		// Here lies the not-yet-implemented method 'VisibleCollidingActors'
		// Here lies the not-yet-implemented method 'CollidingActors'
		// Here lies the not-yet-implemented method 'VisibleCollidingExtentActors'
		// Here lies the not-yet-implemented method 'OverlappingActors'
		// Here lies the not-yet-implemented method 'ComponentList'
		// Here lies the not-yet-implemented method 'AllOwnedComponents'
		// Here lies the not-yet-implemented method 'LocalPlayerControllers'
		// Here lies the not-yet-implemented method 'GetALocalPlayerController'
		// Here lies the not-yet-implemented method 'PreBeginPlay'
		// Here lies the not-yet-implemented method 'BroadcastLocalizedMessage'
		// Here lies the not-yet-implemented method 'BroadcastLocalizedTeamMessage'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'SetInitialState'
		// Here lies the not-yet-implemented method 'ConstraintBrokenNotify'
		// Here lies the not-yet-implemented method 'NotifySkelControlBeyondLimit'
		// Here lies the not-yet-implemented method 'StopsProjectile'
		// Here lies the not-yet-implemented method 'HurtRadius'
		// Here lies the not-yet-implemented method 'KilledBy'
		// Here lies the not-yet-implemented method 'TakeDamage'
		// Here lies the not-yet-implemented method 'HealDamage'
		// Here lies the not-yet-implemented method 'TakeRadiusDamage'
		// Here lies the not-yet-implemented method 'CheckHitInfo'
		// Here lies the not-yet-implemented method 'GetGravityZ'
		// Here lies the not-yet-implemented method 'DebugFreezeGame'
		// Here lies the not-yet-implemented method 'CheckForErrors'
		// Here lies the not-yet-implemented method 'BecomeViewTarget'
		// Here lies the not-yet-implemented method 'EndViewTarget'
		// Here lies the not-yet-implemented method 'CalcCamera'
		// Here lies the not-yet-implemented method 'GetItemName'
		// Here lies the not-yet-implemented method 'GetHumanReadableName'
		// Here lies the not-yet-implemented method 'ReplaceText'
		// Here lies the not-yet-implemented method 'GetLocalString'
		// Here lies the not-yet-implemented method 'MatchStarting'
		// Here lies the not-yet-implemented method 'GetDebugName'
		// Here lies the not-yet-implemented method 'DisplayDebug'
		// Here lies the not-yet-implemented method 'GetPhysicsName'
		// Here lies the not-yet-implemented method 'ModifyHearSoundComponent'
		// Here lies the not-yet-implemented method 'GetFaceFXAudioComponent'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'IsInPain'
		// Here lies the not-yet-implemented method 'PlayTeleportEffect'
		// Here lies the not-yet-implemented method 'CanSplash'
		// Here lies the not-yet-implemented method 'ApplyFluidSurfaceImpact'
		// Here lies the not-yet-implemented method 'EffectIsRelevant'
		// Here lies the not-yet-implemented method 'DebugMessagePlayer'
		// Here lies the not-yet-implemented method 'TriggerEventClass'
		// Here lies the not-yet-implemented method 'ActivateEventClass'
		// Here lies the not-yet-implemented method 'ReceivedNewEvent'
		// Here lies the not-yet-implemented method 'TriggerGlobalEventClass'
		// Here lies the not-yet-implemented method 'FindEventsOfClass'
		// Here lies the not-yet-implemented method 'ClearLatentAction'
		// Here lies the not-yet-implemented method 'OnDestroy'
		// Here lies the not-yet-implemented method 'ForceNetRelevant'
		// Here lies the not-yet-implemented method 'SetNetUpdateTime'
		// Here lies the not-yet-implemented method 'ShutDown'
		// Here lies the not-yet-implemented method 'PrestreamTextures'
		// Here lies the not-yet-implemented method 'OnModifyHealth'
		// Here lies the not-yet-implemented method 'OnTeleport'
		// Here lies the not-yet-implemented method 'OnSetVelocity'
		// Here lies the not-yet-implemented method 'OnSetBlockRigidBody'
		// Here lies the not-yet-implemented method 'OnSetPhysics'
		// Here lies the not-yet-implemented method 'OnChangeCollision'
		// Here lies the not-yet-implemented method 'OnToggleHidden'
		// Here lies the not-yet-implemented method 'OnAttachToActor'
		// Here lies the not-yet-implemented method 'DoKismetAttachment'
		// Here lies the not-yet-implemented method 'OnAnimEnd'
		// Here lies the not-yet-implemented method 'OnAnimPlay'
		// Here lies the not-yet-implemented method 'BeginAnimControl'
		// Here lies the not-yet-implemented method 'SetAnimPosition'
		// Here lies the not-yet-implemented method 'FinishAnimControl'
		// Here lies the not-yet-implemented method 'PlayActorFaceFXAnim'
		// Here lies the not-yet-implemented method 'StopActorFaceFXAnim'
		// Here lies the not-yet-implemented method 'SetMorphWeight'
		// Here lies the not-yet-implemented method 'SetSkelControlScale'
		// Here lies the not-yet-implemented method 'IsActorPlayingFaceFXAnim'
		// Here lies the not-yet-implemented method 'CanActorPlayFaceFXAnim'
		// Here lies the not-yet-implemented method 'GetActorFaceFXAsset'
		// Here lies the not-yet-implemented method 'IsStationary'
		// Here lies the not-yet-implemented method 'GetActorEyesViewPoint'
		// Here lies the not-yet-implemented method 'IsPlayerOwned'
		// Here lies the not-yet-implemented method 'PawnBaseDied'
		// Here lies the not-yet-implemented method 'GetTeamNum'
		// Here lies the not-yet-implemented method 'ScriptGetTeamNum'
		// Here lies the not-yet-implemented method 'NotifyLocalPlayerTeamReceived'
		// Here lies the not-yet-implemented method 'FindGoodEndView'
		// Here lies the not-yet-implemented method 'GetTargetLocation'
		// Here lies the not-yet-implemented method 'SpawnedByKismet'
		// Here lies the not-yet-implemented method 'InterpolationStarted'
		// Here lies the not-yet-implemented method 'InterpolationFinished'
		// Here lies the not-yet-implemented method 'InterpolationChanged'
		// Here lies the not-yet-implemented method 'RigidBodyCollision'
		// Here lies the not-yet-implemented method 'OnRanOver'
		// Here lies the not-yet-implemented method 'SetHUDLocation'
		// Here lies the not-yet-implemented method 'NativePostRenderFor'
		// Here lies the not-yet-implemented method 'PostRenderFor'
		// Here lies the not-yet-implemented method 'RootMotionModeChanged'
		// Here lies the not-yet-implemented method 'RootMotionExtracted'
		// Here lies the not-yet-implemented method 'PostInitAnimTree'
		// Here lies the not-yet-implemented method 'GetPackageGuid'
		// Here lies the not-yet-implemented method 'OnRigidBodySpringOverextension'
		// Here lies the not-yet-implemented method 'IsInPersistentLevel'
		// Here lies the not-yet-implemented method 'GetAimFrictionExtent'
		// Here lies the not-yet-implemented method 'GetAimAdhesionExtent'
		// Here lies the not-yet-implemented method 'PlayParticleEffect'
		// Here lies the not-yet-implemented method 'CreateForceField'
		// Here lies the not-yet-implemented method 'TrailsNotify'
		// Here lies the not-yet-implemented method 'TrailsNotifyTick'
		// Here lies the not-yet-implemented method 'TrailsNotifyEnd'
		// Here lies the not-yet-implemented method 'SupportsKismetModification'
		// Here lies the not-yet-implemented method 'AnimTreeUpdated'
		// Here lies the not-yet-implemented method 'PostDemoRewind'
		// Here lies the not-yet-implemented method 'ReplicationEnded'
		// Here lies the not-yet-implemented method 'GetAvoidanceVector'
		// Here lies the not-yet-implemented method 'WillOverlap'
		// Here lies the not-yet-implemented method 'ShouldBeHiddenBySHOW_NavigationNodes'
		// Here lies the not-yet-implemented method 'GetSpectatorName'
		// Here lies the not-yet-implemented method 'GetSpectatorDescription'
		// Here lies the not-yet-implemented method 'GetSpectatorHealthInfo'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
