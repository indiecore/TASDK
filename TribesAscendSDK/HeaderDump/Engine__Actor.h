#pragma once
#include "Core__Object.h"
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
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
