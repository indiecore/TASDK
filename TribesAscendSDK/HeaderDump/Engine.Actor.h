#pragma once
#include "Engine.SeqAct_Latent.h"
#include "Engine.RB_ConstraintSetup.h"
#include "Core.Object.h"
#include "Engine.SequenceEvent.h"
#include "Engine.Canvas.h"
#include "Engine.WorldInfo.h"
#include "Engine.Pawn.h"
#include "Engine.PhysicsVolume.h"
#include "Engine.AnimNodeSequence.h"
#include "Core.Property.h"
#include "Engine.SeqAct_ChangeCollision.h"
#include "Engine.SeqAct_SetPhysics.h"
#include "Engine.SoundCue.h"
#include "Engine.Controller.h"
#include "Engine.Teleporter.h"
#include "Engine.InterpGroup.h"
#include "Engine.PlayerController.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.RB_ConstraintInstance.h"
#include "Engine.SeqAct_SetBlockRigidBody.h"
#include "Engine.Projectile.h"
#include "Engine.SkelControlLookAt.h"
#include "Engine.HUD.h"
#include "Engine.FluidSurfaceActor.h"
#include "Engine.AnimNotify_ForceField.h"
#include "Engine.SeqAct_Destroy.h"
#include "Engine.FaceFXAnimSet.h"
#include "Engine.SeqAct_ModifyHealth.h"
#include "Engine.SeqAct_Teleport.h"
#include "Engine.SeqAct_SetVelocity.h"
#include "Engine.AnimNotify_PlayParticleEffect.h"
#include "Engine.SeqAct_ToggleHidden.h"
#include "Engine.SeqAct_AttachToActor.h"
#include "Engine.FaceFXAsset.h"
#include "Engine.SeqAct_Interp.h"
#include "Engine.InterpGroupInst.h"
#include "Engine.SVehicle.h"
#include "Engine.RB_BodyInstance.h"
#include "Engine.AnimNotify_Trails.h"
#include "Engine.SequenceOp.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class Actor : public Object
	{
	public:
		static const float MINFLOORZ;
		static const float ACTORMAXSTEPHEIGHT;
		static const float RBSTATE_LINVELSCALE;
		static const float RBSTATE_ANGVELSCALE;
		static const auto RB_None = 0x00;
		static const auto RB_NeedsUpdate = 0x01;
		static const auto RB_Sleeping = 0x02;
		static const float REP_RBLOCATION_ERROR_TOLERANCE_SQ;
		static const auto TRACEFLAG_Blocking = 8;
		static const auto TRACEFLAG_SkipMovers = 4;
		static const auto TRACEFLAG_PhysicsVolumes = 2;
		static const auto TRACEFLAG_Bullet = 1;
		enum EPhysics : byte
		{
			PHYS_None = 0,
			PHYS_Walking = 1,
			PHYS_Falling = 2,
			PHYS_Swimming = 3,
			PHYS_Flying = 4,
			PHYS_Rotating = 5,
			PHYS_Projectile = 6,
			PHYS_Interpolating = 7,
			PHYS_Spider = 8,
			PHYS_Ladder = 9,
			PHYS_RigidBody = 10,
			PHYS_SoftBody = 11,
			PHYS_NavMeshWalking = 12,
			PHYS_Skiing = 13,
			PHYS_Unused = 14,
			PHYS_Custom = 15,
			PHYS_MAX = 16,
		};
		enum EMoveDir : byte
		{
			MD_Stationary = 0,
			MD_Forward = 1,
			MD_Backward = 2,
			MD_Left = 3,
			MD_Right = 4,
			MD_Up = 5,
			MD_Down = 6,
			MD_MAX = 7,
		};
		enum ECollisionType : byte
		{
			COLLIDE_CustomDefault = 0,
			COLLIDE_NoCollision = 1,
			COLLIDE_BlockAll = 2,
			COLLIDE_BlockWeapons = 3,
			COLLIDE_BlockVehicles = 4,
			COLLIDE_TouchAll = 5,
			COLLIDE_TouchWeapons = 6,
			COLLIDE_BlockAllButWeapons = 7,
			COLLIDE_TouchAllButWeapons = 8,
			COLLIDE_BlockWeaponsKickable = 9,
			COLLIDE_MAX = 10,
		};
		enum ETravelType : byte
		{
			TRAVEL_Absolute = 0,
			TRAVEL_Partial = 1,
			TRAVEL_Relative = 2,
			TRAVEL_MAX = 3,
		};
		enum EDoubleClickDir : byte
		{
			DCLICK_None = 0,
			DCLICK_Left = 1,
			DCLICK_Right = 2,
			DCLICK_Forward = 3,
			DCLICK_Back = 4,
			DCLICK_Active = 5,
			DCLICK_Done = 6,
			DCLICK_MAX = 7,
		};
		enum ENetRole : byte
		{
			ROLE_None = 0,
			ROLE_SimulatedProxy = 1,
			ROLE_AutonomousProxy = 2,
			ROLE_Authority = 3,
			ROLE_MAX = 4,
		};
		struct AnimSlotDesc
		{
		public:
			ADD_STRUCT(ScriptName, SlotName, 0)
			ADD_STRUCT(int, NumChannels, 8)
		};
		struct RigidBodyState
		{
		public:
			ADD_STRUCT(byte, bNewData, 56)
			ADD_STRUCT(Vector, AngVel, 44)
			ADD_STRUCT(Vector, LinVel, 32)
			ADD_STRUCT(Object::Quat, Quaternion, 16)
			ADD_STRUCT(Vector, Position, 0)
		};
		struct RigidBodyContactInfo
		{
		public:
			ADD_OBJECT(PhysicalMaterial, PhysMaterial, 52)
			ADD_STRUCT(Vector, ContactVelocity, 28)
			ADD_STRUCT(float, ContactPenetration, 24)
			ADD_STRUCT(Vector, ContactNormal, 12)
			ADD_STRUCT(Vector, ContactPosition, 0)
		};
		struct CollisionImpactData
		{
		public:
			ADD_STRUCT(ScriptArray<Actor::RigidBodyContactInfo>, ContactInfos, 0)
			ADD_STRUCT(Vector, TotalFrictionForceVector, 24)
			ADD_STRUCT(Vector, TotalNormalForceVector, 12)
		};
		struct PhysEffectInfo
		{
		public:
			ADD_OBJECT(SoundCue, Sound, 12)
			ADD_OBJECT(ParticleSystem, Effect, 8)
			ADD_STRUCT(float, ReFireDelay, 4)
			ADD_STRUCT(float, Threshold, 0)
		};
		struct ActorReference
		{
		public:
			ADD_STRUCT(Object::Guid, Guid, 4)
			ADD_OBJECT(Actor, Actor, 0)
		};
		struct NavReference
		{
		public:
			ADD_STRUCT(Object::Guid, Guid, 4)
			ADD_OBJECT(NavigationPoint, Nav, 0)
		};
		struct BasedPosition
		{
		public:
			ADD_STRUCT(Vector, CachedTransPosition, 40)
			ADD_STRUCT(Rotator, CachedBaseRotation, 28)
			ADD_STRUCT(Vector, CachedBaseLocation, 16)
			ADD_STRUCT(Vector, Position, 4)
			ADD_OBJECT(Actor, Base, 0)
		};
		struct TraceHitInfo
		{
		public:
			ADD_OBJECT(Material, Material, 0)
			ADD_OBJECT(PhysicalMaterial, PhysMaterial, 4)
			ADD_STRUCT(int, Item, 8)
			ADD_STRUCT(int, LevelIndex, 12)
			ADD_STRUCT(ScriptName, BoneName, 16)
		};
		struct ImpactInfo
		{
		public:
			ADD_OBJECT(Actor, HitActor, 0)
			ADD_STRUCT(Vector, HitLocation, 4)
			ADD_STRUCT(Vector, HitNormal, 16)
			ADD_STRUCT(Vector, RayDir, 28)
			ADD_STRUCT(Vector, StartTrace, 40)
			ADD_STRUCT(Actor::TraceHitInfo, HitInfo, 52)
		};
		struct AnimSlotInfo
		{
		public:
			ADD_STRUCT(ScriptName, SlotName, 0)
			ADD_STRUCT(ScriptArray<float>, ChannelWeights, 8)
		};
		struct TimerData
		{
		public:
			ADD_BOOL(bLoop, 0, 0x1)
			ADD_BOOL(bPaused, 0, 0x2)
			ADD_STRUCT(ScriptName, FuncName, 4)
			ADD_STRUCT(float, Rate, 12)
			ADD_STRUCT(float, Count, 16)
			ADD_STRUCT(float, TimerTimeDilation, 20)
			ADD_OBJECT(Object, TimerObj, 24)
		};
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, Components, 60)
		ADD_BOOL(bGameRelevant, 168, 0x10000)
		ADD_BOOL(bStatic, 164, 0x1)
		ADD_OBJECT(WorldInfo, WorldInfo, 244)
		ADD_BOOL(bNoDelete, 164, 0x4)
		ADD_BOOL(bScriptInitialized, 172, 0x800000)
		ADD_STRUCT(ScriptName, InitialState, 268)
		ADD_BOOL(bProjTarget, 168, 0x80000000)
		ADD_BOOL(bBlockActors, 168, 0x40000000)
		ADD_OBJECT(Pawn, Instigator, 240)
		ADD_BOOL(bHurtEntry, 168, 0x8000)
		ADD_BOOL(bWorldGeometry, 164, 0x80)
		ADD_BOOL(bCanBeDamaged, 168, 0x80000)
		ADD_STRUCT(ScriptArray<class SequenceEvent*>, GeneratedEvents, 452)
		ADD_STRUCT(Vector, Location, 188)
		ADD_STRUCT(Rotator, Rotation, 84)
		ADD_BOOL(bDeleteMe, 164, 0x8)
		ADD_STRUCT(Actor::ENetRole, Role, 138)
		ADD_STRUCT(Actor::ENetRole, RemoteRole, 137)
		ADD_BOOL(bTearOff, 164, 0x4000000)
		ADD_OBJECT(PhysicsVolume, PhysicsVolume, 324)
		ADD_OBJECT(Actor, Base, 148)
		ADD_BOOL(bBounce, 172, 0x200)
		ADD_BOOL(bHardAttach, 168, 0x400)
		ADD_STRUCT(Vector, RelativeLocation, 388)
		ADD_STRUCT(Rotator, RelativeRotation, 400)
		ADD_STRUCT(ScriptName, BaseBoneName, 368)
		ADD_STRUCT(Vector, Velocity, 328)
		ADD_STRUCT(Vector, Acceleration, 340)
		ADD_BOOL(bCollideActors, 168, 0x8000000)
		ADD_BOOL(bCollideWorld, 168, 0x10000000)
		ADD_OBJECT(Actor, Owner, 144)
		ADD_STRUCT(Actor::EPhysics, Physics, 136)
		ADD_BOOL(bAllowFluidSurfaceInteraction, 164, 0x10000000)
		ADD_BOOL(bDebugEffectIsRelevant, 172, 0x8000000)
		ADD_STRUCT(float, LastRenderTime, 256)
		ADD_STRUCT(ScriptArray<class SeqAct_Latent*>, LatentActions, 464)
		ADD_STRUCT(ScriptArray<class Actor*>, Attached, 376)
		ADD_BOOL(bAlwaysRelevant, 164, 0x200000)
		ADD_STRUCT(float, NetUpdateFrequency, 204)
		ADD_BOOL(bForceNetUpdate, 168, 0x100)
		ADD_BOOL(bHidden, 164, 0x2)
		ADD_BOOL(bUpdateSimulatedPosition, 164, 0x2000000)
		ADD_BOOL(bNetDirty, 164, 0x100000)
		ADD_BOOL(bOnlyDirtyReplication, 164, 0x8000000)
		ADD_BOOL(bCanBeFrictionedTo, 168, 0x4000)
		ADD_BOOL(bCanBeAdheredTo, 168, 0x2000)
		ADD_BOOL(bSkipActorPropertyReplication, 164, 0x1000000)
		ADD_BOOL(bNetInitial, 172, 0x800)
		ADD_BOOL(bReplicateMovement, 164, 0x800000)
		ADD_BOOL(bReplicateInstigator, 164, 0x400000)
		ADD_BOOL(bNetOwner, 172, 0x1000)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, AllComponents, 72)
		ADD_STRUCT(float, DrawScale, 96)
		ADD_STRUCT(Vector, DrawScale3D, 100)
		ADD_STRUCT(Vector, PrePivot, 112)
		ADD_STRUCT(Object::Color, EditorIconColor, 124)
		ADD_STRUCT(Object::RenderCommandFence, DetachFence, 128)
		ADD_STRUCT(float, CustomTimeDilation, 132)
		ADD_STRUCT(Actor::ECollisionType, CollisionType, 139)
		ADD_STRUCT(Actor::ECollisionType, ReplicatedCollisionType, 140)
		ADD_STRUCT(Object::ETickingGroup, TickGroup, 141)
		ADD_STRUCT(ScriptArray<Actor::TimerData>, Timers, 152)
		ADD_BOOL(bTicked, 164, 0x10)
		ADD_BOOL(bOnlyOwnerSee, 164, 0x20)
		ADD_BOOL(bTickIsDisabled, 164, 0x40)
		ADD_BOOL(bIgnoreRigidBodyPawns, 164, 0x100)
		ADD_BOOL(bOrientOnSlope, 164, 0x200)
		ADD_BOOL(bIgnoreEncroachers, 164, 0x400)
		ADD_BOOL(bPushedByEncroachers, 164, 0x800)
		ADD_BOOL(bDestroyedByInterpActor, 164, 0x1000)
		ADD_BOOL(bRouteBeginPlayEvenIfStatic, 164, 0x2000)
		ADD_BOOL(bIsMoving, 164, 0x4000)
		ADD_BOOL(bAlwaysEncroachCheck, 164, 0x8000)
		ADD_BOOL(bHasAlternateTargetLocation, 164, 0x10000)
		ADD_BOOL(bCanStepUpOn, 164, 0x20000)
		ADD_BOOL(bNetTemporary, 164, 0x40000)
		ADD_BOOL(bOnlyRelevantToOwner, 164, 0x80000)
		ADD_BOOL(bDemoRecording, 164, 0x20000000)
		ADD_BOOL(bDemoOwner, 164, 0x40000000)
		ADD_BOOL(bForceDemoRelevant, 164, 0x80000000)
		ADD_BOOL(bNetInitialRotation, 168, 0x1)
		ADD_BOOL(bReplicateRigidBodyLocation, 168, 0x2)
		ADD_BOOL(bKillDuringLevelTransition, 168, 0x4)
		ADD_BOOL(bExchangedRoles, 168, 0x8)
		ADD_BOOL(bConsiderAllStaticMeshComponentsForStreaming, 168, 0x10)
		ADD_BOOL(bDebug, 168, 0x20)
		ADD_BOOL(bPostRenderIfNotVisible, 168, 0x40)
		ADD_BOOL(s_bThrottleNetRelevancy, 168, 0x80)
		ADD_BOOL(bPendingNetUpdate, 168, 0x200)
		ADD_BOOL(bIgnoreBaseRotation, 168, 0x800)
		ADD_BOOL(bShadowParented, 168, 0x1000)
		ADD_BOOL(bMovable, 168, 0x20000)
		ADD_BOOL(bDestroyInPainVolume, 168, 0x40000)
		ADD_BOOL(bShouldBaseAtStartup, 168, 0x100000)
		ADD_BOOL(bPendingDelete, 168, 0x200000)
		ADD_BOOL(bCanTeleport, 168, 0x400000)
		ADD_BOOL(bAlwaysTick, 168, 0x800000)
		ADD_BOOL(bBlocksNavigation, 168, 0x1000000)
		ADD_BOOL(BlockRigidBody, 168, 0x2000000)
		ADD_BOOL(bCollideWhenPlacing, 168, 0x4000000)
		ADD_BOOL(bCollideComplex, 168, 0x20000000)
		ADD_BOOL(bBlocksTeleport, 172, 0x1)
		ADD_BOOL(bMoveIgnoresDestruction, 172, 0x2)
		ADD_BOOL(bNoEncroachCheck, 172, 0x4)
		ADD_BOOL(bCollideAsEncroacher, 172, 0x8)
		ADD_BOOL(bPhysRigidBodyOutOfWorldCheck, 172, 0x10)
		ADD_BOOL(bComponentOutsideWorld, 172, 0x20)
		ADD_BOOL(bForceOctreeSNFilter, 172, 0x40)
		ADD_BOOL(bRigidBodyWasAwake, 172, 0x80)
		ADD_BOOL(bCallRigidBodyWakeEvents, 172, 0x100)
		ADD_BOOL(bJustTeleported, 172, 0x400)
		ADD_BOOL(bHiddenEd, 172, 0x2000)
		ADD_BOOL(bEditable, 172, 0x4000)
		ADD_BOOL(bHiddenEdGroup, 172, 0x8000)
		ADD_BOOL(bHiddenEdCustom, 172, 0x10000)
		ADD_BOOL(bHiddenEdTemporary, 172, 0x20000)
		ADD_BOOL(bHiddenEdLevel, 172, 0x40000)
		ADD_BOOL(bEdShouldSnap, 172, 0x80000)
		ADD_BOOL(bTempEditor, 172, 0x100000)
		ADD_BOOL(bPathColliding, 172, 0x200000)
		ADD_BOOL(bPathTemp, 172, 0x400000)
		ADD_BOOL(bLockLocation, 172, 0x1000000)
		ADD_BOOL(bForceAllowKismetModification, 172, 0x2000000)
		ADD_BOOL(m_bPotentialSeekingTarget, 172, 0x4000000)
		ADD_STRUCT(int, NetTag, 176)
		ADD_STRUCT(int, IndexInTickList, 180)
		ADD_STRUCT(float, LastSlowRelevancyCheckTime, 184)
		ADD_STRUCT(float, NetUpdateTime, 200)
		ADD_STRUCT(float, NetPriority, 208)
		ADD_STRUCT(float, LastNetUpdateTime, 212)
		ADD_STRUCT(float, TimeSinceLastTick, 216)
		ADD_STRUCT(float, TickFrequency, 220)
		ADD_STRUCT(float, TickFrequencyAtEndDistance, 224)
		ADD_STRUCT(float, TickFrequencyDecreaseDistanceStart, 228)
		ADD_STRUCT(float, TickFrequencyDecreaseDistanceEnd, 232)
		ADD_STRUCT(float, TickFrequencyLastSeenTimeBeforeForcingMaxTickFrequency, 236)
		ADD_STRUCT(float, LifeSpan, 248)
		ADD_STRUCT(float, CreationTime, 252)
		ADD_STRUCT(ScriptName, Tag, 260)
		ADD_STRUCT(ScriptName, Group, 276)
		ADD_STRUCT(QWord, HiddenEditorViews, 284)
		ADD_STRUCT(ScriptArray<class Actor*>, Touching, 292)
		ADD_STRUCT(ScriptArray<class Actor*>, Children, 304)
		ADD_STRUCT(float, LatentFloat, 316)
		ADD_OBJECT(AnimNodeSequence, LatentSeqNode, 320)
		ADD_STRUCT(Vector, AngularVelocity, 352)
		ADD_STRUCT(int, OverlapTag, 416)
		ADD_STRUCT(Rotator, RotationRate, 420)
		ADD_OBJECT(Actor, PendingTouch, 432)
		ADD_OBJECT(ScriptClass, MessageClass, 436)
		ADD_STRUCT(ScriptArray<ScriptClass*>, SupportedEvents, 440)
		void ForceUpdateComponents(bool bCollisionUpdate, bool bTransformOnly)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3509);
			byte params[8] = { NULL };
			*(bool*)params = bCollisionUpdate;
			*(bool*)&params[4] = bTransformOnly;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* ConsoleCommand(ScriptString* Command, bool bWriteToLog)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3512);
			byte params[28] = { NULL };
			*(ScriptString**)params = Command;
			*(bool*)&params[12] = bWriteToLog;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[16];
		}
		void Sleep(float Seconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3516);
			byte params[4] = { NULL };
			*(float*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FinishAnim(class AnimNodeSequence* SeqNode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3518);
			byte params[4] = { NULL };
			*(class AnimNodeSequence**)params = SeqNode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCollision(bool bNewColActors, bool bNewBlockActors, bool bNewIgnoreEncroachers)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3520);
			byte params[12] = { NULL };
			*(bool*)params = bNewColActors;
			*(bool*)&params[4] = bNewBlockActors;
			*(bool*)&params[8] = bNewIgnoreEncroachers;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCollisionSize(float NewRadius, float NewHeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3524);
			byte params[8] = { NULL };
			*(float*)params = NewRadius;
			*(float*)&params[4] = NewHeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCollisionType(Actor::ECollisionType NewCollisionType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3527);
			byte params[1] = { NULL };
			*(Actor::ECollisionType*)params = NewCollisionType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDrawScale(float NewScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3529);
			byte params[4] = { NULL };
			*(float*)params = NewScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDrawScale3D(Vector NewScale3D)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3531);
			byte params[12] = { NULL };
			*(Vector*)params = NewScale3D;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool Move(Vector Delta)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3533);
			byte params[16] = { NULL };
			*(Vector*)params = Delta;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool SetLocation(Vector NewLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3536);
			byte params[16] = { NULL };
			*(Vector*)params = NewLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool SetRotation(Rotator NewRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3539);
			byte params[16] = { NULL };
			*(Rotator*)params = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		Actor::EMoveDir MovingWhichWay(float& Amount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3542);
			byte params[5] = { NULL };
			*(float*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Amount = *(float*)params;
			return *(Actor::EMoveDir*)&params[4];
		}
		void SetZone(bool bForceRefresh)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3545);
			byte params[4] = { NULL };
			*(bool*)params = bForceRefresh;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SetRelativeRotation(Rotator NewRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3547);
			byte params[16] = { NULL };
			*(Rotator*)params = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool SetRelativeLocation(Vector NewLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3550);
			byte params[16] = { NULL };
			*(Vector*)params = NewLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void SetHardAttach(bool bNewHardAttach)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3553);
			byte params[4] = { NULL };
			*(bool*)params = bNewHardAttach;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int fixedTurn(int Current, int Desired, int DeltaRate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3555);
			byte params[16] = { NULL };
			*(int*)params = Current;
			*(int*)&params[4] = Desired;
			*(int*)&params[8] = DeltaRate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		bool MoveSmooth(Vector Delta)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3560);
			byte params[16] = { NULL };
			*(Vector*)params = Delta;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void AutonomousPhysics(float DeltaSeconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3563);
			byte params[4] = { NULL };
			*(float*)params = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetTerminalVelocity()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3565);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void SetBase(class Actor* NewBase, Vector NewFloor, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp, ScriptName AttachName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3567);
			byte params[28] = { NULL };
			*(class Actor**)params = NewBase;
			*(Vector*)&params[4] = NewFloor;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[16] = SkelComp;
			*(ScriptName*)&params[20] = AttachName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetOwner(class Actor* NewOwner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3572);
			byte params[4] = { NULL };
			*(class Actor**)params = NewOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FindBase()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3574);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsBasedOn(class Actor* TestActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3575);
			byte params[8] = { NULL };
			*(class Actor**)params = TestActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class Actor* GetBaseMost()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3578);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)params;
		}
		bool IsOwnedBy(class Actor* TestActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3580);
			byte params[8] = { NULL };
			*(class Actor**)params = TestActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		Vector GetAggregateBaseVelocity(class Actor* TestBase)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3583);
			byte params[16] = { NULL };
			*(class Actor**)params = TestBase;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[4];
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3586);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetForcedInitialReplicatedProperty(class Property* PropToReplicate, bool bAdd)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3588);
			byte params[8] = { NULL };
			*(class Property**)params = PropToReplicate;
			*(bool*)&params[4] = bAdd;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Vect2BP(Actor::BasedPosition& BP, Vector pos, class Actor* ForcedBase)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3591);
			byte params[68] = { NULL };
			*(Actor::BasedPosition*)params = BP;
			*(Vector*)&params[52] = pos;
			*(class Actor**)&params[64] = ForcedBase;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			BP = *(Actor::BasedPosition*)params;
		}
		Vector BP2Vect(Actor::BasedPosition BP)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3595);
			byte params[64] = { NULL };
			*(Actor::BasedPosition*)params = BP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[52];
		}
		void SetBasedPosition(Actor::BasedPosition& BP, Vector pos, class Actor* ForcedBase)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3598);
			byte params[68] = { NULL };
			*(Actor::BasedPosition*)params = BP;
			*(Vector*)&params[52] = pos;
			*(class Actor**)&params[64] = ForcedBase;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			BP = *(Actor::BasedPosition*)params;
		}
		Vector GetBasedPosition(Actor::BasedPosition BP)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3602);
			byte params[64] = { NULL };
			*(Actor::BasedPosition*)params = BP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[52];
		}
		void FlushPersistentDebugLines()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3605);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawDebugLine(Vector LineStart, Vector LineEnd, byte R, byte G, byte B, bool bPersistentLines)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3606);
			byte params[31] = { NULL };
			*(Vector*)params = LineStart;
			*(Vector*)&params[12] = LineEnd;
			params[24] = R;
			params[25] = G;
			params[26] = B;
			*(bool*)&params[28] = bPersistentLines;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawDebugPoint(Vector Position, float Size, Object::LinearColor PointColor, bool bPersistentLines)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3613);
			byte params[36] = { NULL };
			*(Vector*)params = Position;
			*(float*)&params[12] = Size;
			*(Object::LinearColor*)&params[16] = PointColor;
			*(bool*)&params[32] = bPersistentLines;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawDebugBox(Vector Center, Vector Extent, byte R, byte G, byte B, bool bPersistentLines)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3618);
			byte params[31] = { NULL };
			*(Vector*)params = Center;
			*(Vector*)&params[12] = Extent;
			params[24] = R;
			params[25] = G;
			params[26] = B;
			*(bool*)&params[28] = bPersistentLines;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawDebugStar(Vector Position, float Size, byte R, byte G, byte B, bool bPersistentLines)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3625);
			byte params[23] = { NULL };
			*(Vector*)params = Position;
			*(float*)&params[12] = Size;
			params[16] = R;
			params[17] = G;
			params[18] = B;
			*(bool*)&params[20] = bPersistentLines;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawDebugCoordinateSystem(Vector AxisLoc, Rotator AxisRot, float Scale, bool bPersistentLines)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3632);
			byte params[32] = { NULL };
			*(Vector*)params = AxisLoc;
			*(Rotator*)&params[12] = AxisRot;
			*(float*)&params[24] = Scale;
			*(bool*)&params[28] = bPersistentLines;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawDebugSphere(Vector Center, float Radius, int Segments, byte R, byte G, byte B, bool bPersistentLines)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3637);
			byte params[27] = { NULL };
			*(Vector*)params = Center;
			*(float*)&params[12] = Radius;
			*(int*)&params[16] = Segments;
			params[20] = R;
			params[21] = G;
			params[22] = B;
			*(bool*)&params[24] = bPersistentLines;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawDebugCylinder(Vector Start, Vector End, float Radius, int Segments, byte R, byte G, byte B, bool bPersistentLines)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3645);
			byte params[39] = { NULL };
			*(Vector*)params = Start;
			*(Vector*)&params[12] = End;
			*(float*)&params[24] = Radius;
			*(int*)&params[28] = Segments;
			params[32] = R;
			params[33] = G;
			params[34] = B;
			*(bool*)&params[36] = bPersistentLines;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawDebugCone(Vector Origin, Vector Direction, float Length, float AngleWidth, float AngleHeight, int NumSides, Object::Color DrawColor, bool bPersistentLines)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3654);
			byte params[48] = { NULL };
			*(Vector*)params = Origin;
			*(Vector*)&params[12] = Direction;
			*(float*)&params[24] = Length;
			*(float*)&params[28] = AngleWidth;
			*(float*)&params[32] = AngleHeight;
			*(int*)&params[36] = NumSides;
			*(Object::Color*)&params[40] = DrawColor;
			*(bool*)&params[44] = bPersistentLines;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawDebugString(Vector TextLocation, ScriptString* Text, class Actor* TestBaseActor, Object::Color TextColor, float Duration)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3663);
			byte params[36] = { NULL };
			*(Vector*)params = TextLocation;
			*(ScriptString**)&params[12] = Text;
			*(class Actor**)&params[24] = TestBaseActor;
			*(Object::Color*)&params[28] = TextColor;
			*(float*)&params[32] = Duration;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawDebugFrustrum(Object::Matrix& FrustumToWorld, byte R, byte G, byte B, bool bPersistentLines)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3669);
			byte params[71] = { NULL };
			*(Object::Matrix*)params = FrustumToWorld;
			params[64] = R;
			params[65] = G;
			params[66] = B;
			*(bool*)&params[68] = bPersistentLines;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			FrustumToWorld = *(Object::Matrix*)params;
		}
		void FlushDebugStrings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3675);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChartData(ScriptString* DataName, float DataValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3676);
			byte params[16] = { NULL };
			*(ScriptString**)params = DataName;
			*(float*)&params[12] = DataValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetHidden(bool bNewHidden)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3679);
			byte params[4] = { NULL };
			*(bool*)params = bNewHidden;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetOnlyOwnerSee(bool bNewOnlyOwnerSee)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3681);
			byte params[4] = { NULL };
			*(bool*)params = bNewOnlyOwnerSee;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPhysics(Actor::EPhysics newPhysics)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3683);
			byte params[1] = { NULL };
			*(Actor::EPhysics*)params = newPhysics;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Clock(float& Time)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3685);
			byte params[4] = { NULL };
			*(float*)params = Time;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Time = *(float*)params;
		}
		void UnClock(float& Time)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3687);
			byte params[4] = { NULL };
			*(float*)params = Time;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Time = *(float*)params;
		}
		void AttachComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* NewComponent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3689);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = NewComponent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetachComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* ExComponent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3691);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = ExComponent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReattachComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* ComponentToReattach)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3693);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = ComponentToReattach;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTickGroup(Object::ETickingGroup NewTickGroup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3695);
			byte params[1] = { NULL };
			*(Object::ETickingGroup*)params = NewTickGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTickIsDisabled(bool bInDisabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3697);
			byte params[4] = { NULL };
			*(bool*)params = bInDisabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3699);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GainedChild(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3700);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LostChild(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3702);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3704);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Timer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3706);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HitWall(Vector HitNormal, class Actor* Wall, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* WallComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3707);
			byte params[20] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = Wall;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[16] = WallComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Falling()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3712);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Landed(Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3713);
			byte params[16] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PhysicsVolumeChange(class PhysicsVolume* NewVolume)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3716);
			byte params[4] = { NULL };
			*(class PhysicsVolume**)params = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3718);
			byte params[32] = { NULL };
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostTouch(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3723);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnTouch(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3725);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Bump(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3727);
			byte params[20] = { NULL };
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Vector*)&params[8] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BaseChange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3731);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Attach(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3732);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Detach(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3734);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Actor* SpecialHandling(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3736);
			byte params[8] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[4];
		}
		void CollisionChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3739);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool EncroachingOn(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3740);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void EncroachedBy(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3743);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RanInto(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3745);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnWakeRBPhysics()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3747);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSleepRBPhysics()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3748);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ClampRotation(Rotator& out_Rot, Rotator rBase, Rotator rUpperLimits, Rotator rLowerLimits)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3749);
			byte params[52] = { NULL };
			*(Rotator*)params = out_Rot;
			*(Rotator*)&params[12] = rBase;
			*(Rotator*)&params[24] = rUpperLimits;
			*(Rotator*)&params[36] = rLowerLimits;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Rot = *(Rotator*)params;
			return *(bool*)&params[48];
		}
		bool OverRotated(Rotator& out_Desired, Rotator& out_Actual)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3755);
			byte params[28] = { NULL };
			*(Rotator*)params = out_Desired;
			*(Rotator*)&params[12] = out_Actual;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Desired = *(Rotator*)params;
			out_Actual = *(Rotator*)&params[12];
			return *(bool*)&params[24];
		}
		bool UsedBy(class Pawn* User)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3759);
			byte params[8] = { NULL };
			*(class Pawn**)params = User;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3762);
			byte params[4] = { NULL };
			*(ScriptClass**)params = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OutsideWorldBounds()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3764);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void VolumeBasedDestroy(class PhysicsVolume* PV)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3765);
			byte params[4] = { NULL };
			*(class PhysicsVolume**)params = PV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Actor* Trace(Vector& HitLocation, Vector& HitNormal, Vector TraceEnd, Vector TraceStart, bool bTraceActors, Vector Extent, Actor::TraceHitInfo& HitInfo, int ExtraTraceFlags)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3767);
			byte params[100] = { NULL };
			*(Vector*)params = HitLocation;
			*(Vector*)&params[12] = HitNormal;
			*(Vector*)&params[24] = TraceEnd;
			*(Vector*)&params[36] = TraceStart;
			*(bool*)&params[48] = bTraceActors;
			*(Vector*)&params[52] = Extent;
			*(Actor::TraceHitInfo*)&params[64] = HitInfo;
			*(int*)&params[92] = ExtraTraceFlags;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			HitLocation = *(Vector*)params;
			HitNormal = *(Vector*)&params[12];
			HitInfo = *(Actor::TraceHitInfo*)&params[64];
			return *(class Actor**)&params[96];
		}
		bool TraceComponent(Vector& HitLocation, Vector& HitNormal, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* InComponent, Vector TraceEnd, Vector TraceStart, Vector Extent, Actor::TraceHitInfo& HitInfo, bool bComplexCollision)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3785);
			byte params[100] = { NULL };
			*(Vector*)params = HitLocation;
			*(Vector*)&params[12] = HitNormal;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[24] = InComponent;
			*(Vector*)&params[28] = TraceEnd;
			*(Vector*)&params[40] = TraceStart;
			*(Vector*)&params[52] = Extent;
			*(Actor::TraceHitInfo*)&params[64] = HitInfo;
			*(bool*)&params[92] = bComplexCollision;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			HitLocation = *(Vector*)params;
			HitNormal = *(Vector*)&params[12];
			HitInfo = *(Actor::TraceHitInfo*)&params[64];
			return *(bool*)&params[96];
		}
		bool PointCheckComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* InComponent, Vector PointLocation, Vector PointExtent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3795);
			byte params[32] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = InComponent;
			*(Vector*)&params[4] = PointLocation;
			*(Vector*)&params[16] = PointExtent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		bool FastTrace(Vector TraceEnd, Vector TraceStart, Vector BoxExtent, bool bTraceBullet)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3800);
			byte params[44] = { NULL };
			*(Vector*)params = TraceEnd;
			*(Vector*)&params[12] = TraceStart;
			*(Vector*)&params[24] = BoxExtent;
			*(bool*)&params[36] = bTraceBullet;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[40];
		}
		bool TraceAllPhysicsAssetInteractions(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMeshComp, Vector EndTrace, Vector StartTrace, ScriptArray<Actor::ImpactInfo>& out_Hits, Vector Extent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3806);
			byte params[56] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelMeshComp;
			*(Vector*)&params[4] = EndTrace;
			*(Vector*)&params[16] = StartTrace;
			*(ScriptArray<Actor::ImpactInfo>*)&params[28] = out_Hits;
			*(Vector*)&params[40] = Extent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Hits = *(ScriptArray<Actor::ImpactInfo>*)&params[28];
			return *(bool*)&params[52];
		}
		bool FindSpot(Vector BoxExtent, Vector& SpotLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3821);
			byte params[28] = { NULL };
			*(Vector*)params = BoxExtent;
			*(Vector*)&params[12] = SpotLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			SpotLocation = *(Vector*)&params[12];
			return *(bool*)&params[24];
		}
		bool ContainsPoint(Vector Spot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3825);
			byte params[16] = { NULL };
			*(Vector*)params = Spot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool IsOverlapping(class Actor* A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3828);
			byte params[8] = { NULL };
			*(class Actor**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void GetComponentsBoundingBox(Object::Box& ActorBox)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3831);
			byte params[28] = { NULL };
			*(Object::Box*)params = ActorBox;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ActorBox = *(Object::Box*)params;
		}
		void GetBoundingCylinder(float& CollisionRadius, float& CollisionHeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3833);
			byte params[8] = { NULL };
			*(float*)params = CollisionRadius;
			*(float*)&params[4] = CollisionHeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CollisionRadius = *(float*)params;
			CollisionHeight = *(float*)&params[4];
		}
		bool IsBlockedBy(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3836);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class Actor* Spawn(ScriptClass* SpawnClass, class Actor* SpawnOwner, ScriptName SpawnTag, Vector SpawnLocation, Rotator SpawnRotation, class Actor* ActorTemplate, bool bNoCollisionFail)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3839);
			byte params[52] = { NULL };
			*(ScriptClass**)params = SpawnClass;
			*(class Actor**)&params[4] = SpawnOwner;
			*(ScriptName*)&params[8] = SpawnTag;
			*(Vector*)&params[16] = SpawnLocation;
			*(Rotator*)&params[28] = SpawnRotation;
			*(class Actor**)&params[40] = ActorTemplate;
			*(bool*)&params[44] = bNoCollisionFail;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[48];
		}
		bool Destroy()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3848);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void TornOff()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3850);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetTimer(float InRate, bool inbLoop, ScriptName inTimerFunc, class Object* inObj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3851);
			byte params[20] = { NULL };
			*(float*)params = InRate;
			*(bool*)&params[4] = inbLoop;
			*(ScriptName*)&params[8] = inTimerFunc;
			*(class Object**)&params[16] = inObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearTimer(ScriptName inTimerFunc, class Object* inObj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3856);
			byte params[12] = { NULL };
			*(ScriptName*)params = inTimerFunc;
			*(class Object**)&params[8] = inObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearAllTimers(class Object* inObj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3859);
			byte params[4] = { NULL };
			*(class Object**)params = inObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PauseTimer(bool bPause, ScriptName inTimerFunc, class Object* inObj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3861);
			byte params[16] = { NULL };
			*(bool*)params = bPause;
			*(ScriptName*)&params[4] = inTimerFunc;
			*(class Object**)&params[12] = inObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsTimerActive(ScriptName inTimerFunc, class Object* inObj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3865);
			byte params[16] = { NULL };
			*(ScriptName*)params = inTimerFunc;
			*(class Object**)&params[8] = inObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		float GetTimerCount(ScriptName inTimerFunc, class Object* inObj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3869);
			byte params[16] = { NULL };
			*(ScriptName*)params = inTimerFunc;
			*(class Object**)&params[8] = inObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float GetTimerRate(ScriptName TimerFuncName, class Object* inObj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3873);
			byte params[16] = { NULL };
			*(ScriptName*)params = TimerFuncName;
			*(class Object**)&params[8] = inObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float GetRemainingTimeForTimer(ScriptName TimerFuncName, class Object* inObj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3877);
			byte params[16] = { NULL };
			*(ScriptName*)params = TimerFuncName;
			*(class Object**)&params[8] = inObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		void ModifyTimerTimeDilation(ScriptName TimerName, float InTimerTimeDilation, class Object* inObj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3883);
			byte params[16] = { NULL };
			*(ScriptName*)params = TimerName;
			*(float*)&params[8] = InTimerTimeDilation;
			*(class Object**)&params[12] = inObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetTimerTimeDilation(ScriptName TimerName, class Object* inObj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3887);
			byte params[12] = { NULL };
			*(ScriptName*)params = TimerName;
			*(class Object**)&params[8] = inObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* CreateAudioComponent(class SoundCue* InSoundCue, bool bPlay, bool bStopWhenOwnerDestroyed, bool bUseLocation, Vector SourceLocation, bool bAttachToSelf)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3890);
			byte params[36] = { NULL };
			*(class SoundCue**)params = InSoundCue;
			*(bool*)&params[4] = bPlay;
			*(bool*)&params[8] = bStopWhenOwnerDestroyed;
			*(bool*)&params[12] = bUseLocation;
			*(Vector*)&params[16] = SourceLocation;
			*(bool*)&params[28] = bAttachToSelf;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[32];
		}
		void PlaySound(class SoundCue* InSoundCue, bool bNotReplicated, bool bNoRepToOwner, bool bStopWhenOwnerDestroyed, Vector SoundLocation, bool bNoRepToRelevant)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3898);
			byte params[32] = { NULL };
			*(class SoundCue**)params = InSoundCue;
			*(bool*)&params[4] = bNotReplicated;
			*(bool*)&params[8] = bNoRepToOwner;
			*(bool*)&params[12] = bStopWhenOwnerDestroyed;
			*(Vector*)&params[16] = SoundLocation;
			*(bool*)&params[28] = bNoRepToRelevant;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MakeNoise(float Loudness, ScriptName NoiseType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3905);
			byte params[12] = { NULL };
			*(float*)params = Loudness;
			*(ScriptName*)&params[4] = NoiseType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool PlayerCanSeeMe(bool bForceLOSCheck)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3908);
			byte params[8] = { NULL };
			*(bool*)params = bForceLOSCheck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SuggestTossVelocity(Vector& TossVelocity, Vector Destination, Vector Start, float TossSpeed, float BaseTossZ, float DesiredZPct, Vector CollisionSize, float TerminalVelocity, float OverrideGravityZ, bool bOnlyTraceUp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3911);
			byte params[76] = { NULL };
			*(Vector*)params = TossVelocity;
			*(Vector*)&params[12] = Destination;
			*(Vector*)&params[24] = Start;
			*(float*)&params[36] = TossSpeed;
			*(float*)&params[40] = BaseTossZ;
			*(float*)&params[44] = DesiredZPct;
			*(Vector*)&params[48] = CollisionSize;
			*(float*)&params[60] = TerminalVelocity;
			*(float*)&params[64] = OverrideGravityZ;
			*(bool*)&params[68] = bOnlyTraceUp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			TossVelocity = *(Vector*)params;
			return *(bool*)&params[72];
		}
		bool CalculateMinSpeedTrajectory(Vector& out_Velocity, Vector End, Vector Start, float MaxTossSpeed, float MinTossSpeed, Vector CollisionSize, float TerminalVelocity, float GravityZ, bool bOnlyTraceUp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3923);
			byte params[72] = { NULL };
			*(Vector*)params = out_Velocity;
			*(Vector*)&params[12] = End;
			*(Vector*)&params[24] = Start;
			*(float*)&params[36] = MaxTossSpeed;
			*(float*)&params[40] = MinTossSpeed;
			*(Vector*)&params[44] = CollisionSize;
			*(float*)&params[56] = TerminalVelocity;
			*(float*)&params[60] = GravityZ;
			*(bool*)&params[64] = bOnlyTraceUp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Velocity = *(Vector*)params;
			return *(bool*)&params[68];
		}
		Vector GetDestination(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3934);
			byte params[16] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[4];
		}
		bool PreTeleport(class Teleporter* InTeleporter)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3937);
			byte params[8] = { NULL };
			*(class Teleporter**)params = InTeleporter;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PostTeleport(class Teleporter* OutTeleporter)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3940);
			byte params[4] = { NULL };
			*(class Teleporter**)params = OutTeleporter;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetURLMap()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3942);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void AllActors(ScriptClass* BaseClass, class Actor*& Actor, ScriptClass* InterfaceClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3944);
			byte params[12] = { NULL };
			*(ScriptClass**)params = BaseClass;
			*(class Actor**)&params[4] = Actor;
			*(ScriptClass**)&params[8] = InterfaceClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Actor = *(class Actor**)&params[4];
		}
		void DynamicActors(ScriptClass* BaseClass, class Actor*& Actor, ScriptClass* InterfaceClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3948);
			byte params[12] = { NULL };
			*(ScriptClass**)params = BaseClass;
			*(class Actor**)&params[4] = Actor;
			*(ScriptClass**)&params[8] = InterfaceClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Actor = *(class Actor**)&params[4];
		}
		void ChildActors(ScriptClass* BaseClass, class Actor*& Actor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3952);
			byte params[8] = { NULL };
			*(ScriptClass**)params = BaseClass;
			*(class Actor**)&params[4] = Actor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Actor = *(class Actor**)&params[4];
		}
		void BasedActors(ScriptClass* BaseClass, class Actor*& Actor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3955);
			byte params[8] = { NULL };
			*(ScriptClass**)params = BaseClass;
			*(class Actor**)&params[4] = Actor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Actor = *(class Actor**)&params[4];
		}
		void TouchingActors(ScriptClass* BaseClass, class Actor*& Actor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3958);
			byte params[8] = { NULL };
			*(ScriptClass**)params = BaseClass;
			*(class Actor**)&params[4] = Actor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Actor = *(class Actor**)&params[4];
		}
		void TraceActors(ScriptClass* BaseClass, class Actor*& Actor, Vector& HitLoc, Vector& HitNorm, Vector End, Vector Start, Vector Extent, Actor::TraceHitInfo& HitInfo, int ExtraTraceFlags)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3961);
			byte params[100] = { NULL };
			*(ScriptClass**)params = BaseClass;
			*(class Actor**)&params[4] = Actor;
			*(Vector*)&params[8] = HitLoc;
			*(Vector*)&params[20] = HitNorm;
			*(Vector*)&params[32] = End;
			*(Vector*)&params[44] = Start;
			*(Vector*)&params[56] = Extent;
			*(Actor::TraceHitInfo*)&params[68] = HitInfo;
			*(int*)&params[96] = ExtraTraceFlags;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Actor = *(class Actor**)&params[4];
			HitLoc = *(Vector*)&params[8];
			HitNorm = *(Vector*)&params[20];
			HitInfo = *(Actor::TraceHitInfo*)&params[68];
		}
		void VisibleActors(ScriptClass* BaseClass, class Actor*& Actor, float Radius, Vector Loc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3971);
			byte params[24] = { NULL };
			*(ScriptClass**)params = BaseClass;
			*(class Actor**)&params[4] = Actor;
			*(float*)&params[8] = Radius;
			*(Vector*)&params[12] = Loc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Actor = *(class Actor**)&params[4];
		}
		void VisibleCollidingActors(ScriptClass* BaseClass, class Actor*& Actor, float Radius, Vector Loc, bool bIgnoreHidden, Vector Extent, bool bTraceActors, ScriptClass* InterfaceClass, Actor::TraceHitInfo& HitInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3976);
			byte params[76] = { NULL };
			*(ScriptClass**)params = BaseClass;
			*(class Actor**)&params[4] = Actor;
			*(float*)&params[8] = Radius;
			*(Vector*)&params[12] = Loc;
			*(bool*)&params[24] = bIgnoreHidden;
			*(Vector*)&params[28] = Extent;
			*(bool*)&params[40] = bTraceActors;
			*(ScriptClass**)&params[44] = InterfaceClass;
			*(Actor::TraceHitInfo*)&params[48] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Actor = *(class Actor**)&params[4];
			HitInfo = *(Actor::TraceHitInfo*)&params[48];
		}
		void CollidingActors(ScriptClass* BaseClass, class Actor*& Actor, float Radius, Vector Loc, bool bUseOverlapCheck, ScriptClass* InterfaceClass, Actor::TraceHitInfo& HitInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3986);
			byte params[60] = { NULL };
			*(ScriptClass**)params = BaseClass;
			*(class Actor**)&params[4] = Actor;
			*(float*)&params[8] = Radius;
			*(Vector*)&params[12] = Loc;
			*(bool*)&params[24] = bUseOverlapCheck;
			*(ScriptClass**)&params[28] = InterfaceClass;
			*(Actor::TraceHitInfo*)&params[32] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Actor = *(class Actor**)&params[4];
			HitInfo = *(Actor::TraceHitInfo*)&params[32];
		}
		void VisibleCollidingExtentActors(ScriptClass* BaseClass, class Actor*& Actor, float Radius, Vector Loc, Vector AltLoc, bool bIgnoreHidden, Vector Extent, bool bTraceActors, ScriptClass* InterfaceClass, Actor::TraceHitInfo& HitInfo, float XYCheckRadius)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(3994);
			byte params[92] = { NULL };
			*(ScriptClass**)params = BaseClass;
			*(class Actor**)&params[4] = Actor;
			*(float*)&params[8] = Radius;
			*(Vector*)&params[12] = Loc;
			*(Vector*)&params[24] = AltLoc;
			*(bool*)&params[36] = bIgnoreHidden;
			*(Vector*)&params[40] = Extent;
			*(bool*)&params[52] = bTraceActors;
			*(ScriptClass**)&params[56] = InterfaceClass;
			*(Actor::TraceHitInfo*)&params[60] = HitInfo;
			*(float*)&params[88] = XYCheckRadius;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Actor = *(class Actor**)&params[4];
			HitInfo = *(Actor::TraceHitInfo*)&params[60];
		}
		void OverlappingActors(ScriptClass* BaseClass, class Actor*& out_Actor, float Radius, Vector Loc, bool bIgnoreHidden)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4006);
			byte params[28] = { NULL };
			*(ScriptClass**)params = BaseClass;
			*(class Actor**)&params[4] = out_Actor;
			*(float*)&params[8] = Radius;
			*(Vector*)&params[12] = Loc;
			*(bool*)&params[24] = bIgnoreHidden;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Actor = *(class Actor**)&params[4];
		}
		void ComponentList(ScriptClass* BaseClass, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*& out_Component)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4012);
			byte params[8] = { NULL };
			*(ScriptClass**)params = BaseClass;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = out_Component;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Component = *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4];
		}
		void AllOwnedComponents(ScriptClass* BaseClass, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*& OutComponent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4015);
			byte params[8] = { NULL };
			*(ScriptClass**)params = BaseClass;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OutComponent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutComponent = *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4];
		}
		void LocalPlayerControllers(ScriptClass* BaseClass, class PlayerController*& PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4018);
			byte params[8] = { NULL };
			*(ScriptClass**)params = BaseClass;
			*(class PlayerController**)&params[4] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PC = *(class PlayerController**)&params[4];
		}
		class PlayerController* GetALocalPlayerController()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4021);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PlayerController**)params;
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4023);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BroadcastLocalizedMessage(ScriptClass* InMessageClass, int Switch, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4032);
			byte params[20] = { NULL };
			*(ScriptClass**)params = InMessageClass;
			*(int*)&params[4] = Switch;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_2;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BroadcastLocalizedTeamMessage(int TeamIndex, ScriptClass* InMessageClass, int Switch, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4039);
			byte params[24] = { NULL };
			*(int*)params = TeamIndex;
			*(ScriptClass**)&params[4] = InMessageClass;
			*(int*)&params[8] = Switch;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[16] = RelatedPRI_2;
			*(class Object**)&params[20] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4046);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetInitialState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4047);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ConstraintBrokenNotify(class Actor* ConOwner, class RB_ConstraintSetup* ConSetup, class RB_ConstraintInstance* ConInstance)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4050);
			byte params[12] = { NULL };
			*(class Actor**)params = ConOwner;
			*(class RB_ConstraintSetup**)&params[4] = ConSetup;
			*(class RB_ConstraintInstance**)&params[8] = ConInstance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifySkelControlBeyondLimit(class SkelControlLookAt* LookAt)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4054);
			byte params[4] = { NULL };
			*(class SkelControlLookAt**)params = LookAt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool StopsProjectile(class Projectile* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4056);
			byte params[8] = { NULL };
			*(class Projectile**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool HurtRadius(float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, class Actor* IgnoredActor, class Controller* InstigatedByController, bool bDoFullDamage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4061);
			byte params[44] = { NULL };
			*(float*)params = BaseDamage;
			*(float*)&params[4] = DamageRadius;
			*(ScriptClass**)&params[8] = DamageType;
			*(float*)&params[12] = Momentum;
			*(Vector*)&params[16] = HurtOrigin;
			*(class Actor**)&params[28] = IgnoredActor;
			*(class Controller**)&params[32] = InstigatedByController;
			*(bool*)&params[36] = bDoFullDamage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[40];
		}
		void KilledBy(class Pawn* EventInstigator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4085);
			byte params[4] = { NULL };
			*(class Pawn**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4087);
			byte params[68] = { NULL };
			*(int*)params = DamageAmount;
			*(class Controller**)&params[4] = EventInstigator;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool HealDamage(int Amount, class Controller* Healer, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4098);
			byte params[16] = { NULL };
			*(int*)params = Amount;
			*(class Controller**)&params[4] = Healer;
			*(ScriptClass**)&params[8] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void TakeRadiusDamage(class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4103);
			byte params[44] = { NULL };
			*(class Controller**)params = InstigatedBy;
			*(float*)&params[4] = BaseDamage;
			*(float*)&params[8] = DamageRadius;
			*(ScriptClass**)&params[12] = DamageType;
			*(float*)&params[16] = Momentum;
			*(Vector*)&params[20] = HurtOrigin;
			*(bool*)&params[32] = bFullDamage;
			*(class Actor**)&params[36] = DamageCauser;
			*(float*)&params[40] = DamageFalloffExponent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckHitInfo(Actor::TraceHitInfo& HitInfo, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* FallBackComponent, Vector Dir, Vector& out_HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4120);
			byte params[56] = { NULL };
			*(Actor::TraceHitInfo*)params = HitInfo;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[28] = FallBackComponent;
			*(Vector*)&params[32] = Dir;
			*(Vector*)&params[44] = out_HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			HitInfo = *(Actor::TraceHitInfo*)params;
			out_HitLocation = *(Vector*)&params[44];
		}
		float GetGravityZ()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4131);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void DebugFreezeGame(class Actor* ActorToLookAt)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4133);
			byte params[4] = { NULL };
			*(class Actor**)params = ActorToLookAt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckForErrors()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4135);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void BecomeViewTarget(class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4137);
			byte params[4] = { NULL };
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndViewTarget(class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4139);
			byte params[4] = { NULL };
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CalcCamera(float fDeltaTime, Vector& out_CamLoc, Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4141);
			byte params[36] = { NULL };
			*(float*)params = fDeltaTime;
			*(Vector*)&params[4] = out_CamLoc;
			*(Rotator*)&params[16] = out_CamRot;
			*(float*)&params[28] = out_FOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamLoc = *(Vector*)&params[4];
			out_CamRot = *(Rotator*)&params[16];
			out_FOV = *(float*)&params[28];
			return *(bool*)&params[32];
		}
		ScriptString* GetItemName(ScriptString* FullName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4150);
			byte params[24] = { NULL };
			*(ScriptString**)params = FullName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		ScriptString* GetHumanReadableName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4154);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void ReplaceText(ScriptString*& Text, ScriptString* Replace, ScriptString* With)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4156);
			byte params[36] = { NULL };
			*(ScriptString**)params = Text;
			*(ScriptString**)&params[12] = Replace;
			*(ScriptString**)&params[24] = With;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Text = *(ScriptString**)params;
		}
		ScriptString* GetLocalString(int Switch, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4162);
			byte params[24] = { NULL };
			*(int*)params = Switch;
			*(class PlayerReplicationInfo**)&params[4] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		void MatchStarting()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4167);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetDebugName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4168);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4170);
			byte params[12] = { NULL };
			*(class HUD**)params = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		ScriptString* GetPhysicsName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4203);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void ModifyHearSoundComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4206);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = AC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* GetFaceFXAudioComponent()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4208);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params;
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4210);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsInPain()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4211);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void PlayTeleportEffect(bool bOut, bool bSound)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4216);
			byte params[8] = { NULL };
			*(bool*)params = bOut;
			*(bool*)&params[4] = bSound;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanSplash()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4219);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ApplyFluidSurfaceImpact(class FluidSurfaceActor* Fluid, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4221);
			byte params[16] = { NULL };
			*(class FluidSurfaceActor**)params = Fluid;
			*(Vector*)&params[4] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool EffectIsRelevant(Vector SpawnLocation, bool bForceDedicated, float VisibleCullDistance, float HiddenCullDistance)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4231);
			byte params[28] = { NULL };
			*(Vector*)params = SpawnLocation;
			*(bool*)&params[12] = bForceDedicated;
			*(float*)&params[16] = VisibleCullDistance;
			*(float*)&params[20] = HiddenCullDistance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void DebugMessagePlayer(ScriptString* msg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4252);
			byte params[12] = { NULL };
			*(ScriptString**)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool TriggerEventClass(ScriptClass* InEventClass, class Actor* InInstigator, int ActivateIndex, bool bTest, ScriptArray<class SequenceEvent*>& ActivatedEvents)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4264);
			byte params[32] = { NULL };
			*(ScriptClass**)params = InEventClass;
			*(class Actor**)&params[4] = InInstigator;
			*(int*)&params[8] = ActivateIndex;
			*(bool*)&params[12] = bTest;
			*(ScriptArray<class SequenceEvent*>*)&params[16] = ActivatedEvents;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ActivatedEvents = *(ScriptArray<class SequenceEvent*>*)&params[16];
			return *(bool*)&params[28];
		}
		bool ActivateEventClass(ScriptClass* InClass, class Actor* InInstigator, ScriptArray<class SequenceEvent*>& EventList, ScriptArray<int>& ActivateIndices, bool bTest, ScriptArray<class SequenceEvent*>& ActivatedEvents)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4274);
			byte params[52] = { NULL };
			*(ScriptClass**)params = InClass;
			*(class Actor**)&params[4] = InInstigator;
			*(ScriptArray<class SequenceEvent*>*)&params[8] = EventList;
			*(ScriptArray<int>*)&params[20] = ActivateIndices;
			*(bool*)&params[32] = bTest;
			*(ScriptArray<class SequenceEvent*>*)&params[36] = ActivatedEvents;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			EventList = *(ScriptArray<class SequenceEvent*>*)&params[8];
			ActivateIndices = *(ScriptArray<int>*)&params[20];
			ActivatedEvents = *(ScriptArray<class SequenceEvent*>*)&params[36];
			return *(bool*)&params[48];
		}
		void ReceivedNewEvent(class SequenceEvent* Evt)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4275);
			byte params[4] = { NULL };
			*(class SequenceEvent**)params = Evt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool TriggerGlobalEventClass(ScriptClass* InEventClass, class Actor* InInstigator, int ActivateIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4277);
			byte params[16] = { NULL };
			*(ScriptClass**)params = InEventClass;
			*(class Actor**)&params[4] = InInstigator;
			*(int*)&params[8] = ActivateIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool FindEventsOfClass(ScriptClass* EventClass, ScriptArray<class SequenceEvent*>& out_EventList, bool bIncludeDisabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4305);
			byte params[24] = { NULL };
			*(ScriptClass**)params = EventClass;
			*(ScriptArray<class SequenceEvent*>*)&params[4] = out_EventList;
			*(bool*)&params[16] = bIncludeDisabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_EventList = *(ScriptArray<class SequenceEvent*>*)&params[4];
			return *(bool*)&params[20];
		}
		void ClearLatentAction(ScriptClass* actionClass, bool bAborted, class SeqAct_Latent* exceptionAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4316);
			byte params[12] = { NULL };
			*(ScriptClass**)params = actionClass;
			*(bool*)&params[4] = bAborted;
			*(class SeqAct_Latent**)&params[8] = exceptionAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnDestroy(class SeqAct_Destroy* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4322);
			byte params[4] = { NULL };
			*(class SeqAct_Destroy**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ForceNetRelevant()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4331);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetNetUpdateTime(float NewUpdateTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4335);
			byte params[4] = { NULL };
			*(float*)params = NewUpdateTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShutDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4337);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PrestreamTextures(float Seconds, bool bEnableStreaming, int CinematicTextureGroups)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4341);
			byte params[12] = { NULL };
			*(float*)params = Seconds;
			*(bool*)&params[4] = bEnableStreaming;
			*(int*)&params[8] = CinematicTextureGroups;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnModifyHealth(class SeqAct_ModifyHealth* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4345);
			byte params[4] = { NULL };
			*(class SeqAct_ModifyHealth**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnTeleport(class SeqAct_Teleport* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4354);
			byte params[4] = { NULL };
			*(class SeqAct_Teleport**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSetVelocity(class SeqAct_SetVelocity* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4377);
			byte params[4] = { NULL };
			*(class SeqAct_SetVelocity**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSetBlockRigidBody(class SeqAct_SetBlockRigidBody* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4386);
			byte params[4] = { NULL };
			*(class SeqAct_SetBlockRigidBody**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSetPhysics(class SeqAct_SetPhysics* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4391);
			byte params[4] = { NULL };
			*(class SeqAct_SetPhysics**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnChangeCollision(class SeqAct_ChangeCollision* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4395);
			byte params[4] = { NULL };
			*(class SeqAct_ChangeCollision**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnToggleHidden(class SeqAct_ToggleHidden* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4405);
			byte params[4] = { NULL };
			*(class SeqAct_ToggleHidden**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAttachToActor(class SeqAct_AttachToActor* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4413);
			byte params[4] = { NULL };
			*(class SeqAct_AttachToActor**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DoKismetAttachment(class Actor* Attachment, class SeqAct_AttachToActor* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4422);
			byte params[8] = { NULL };
			*(class Actor**)params = Attachment;
			*(class SeqAct_AttachToActor**)&params[4] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAnimEnd(class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4435);
			byte params[12] = { NULL };
			*(class AnimNodeSequence**)params = SeqNode;
			*(float*)&params[4] = PlayedTime;
			*(float*)&params[8] = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAnimPlay(class AnimNodeSequence* SeqNode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4439);
			byte params[4] = { NULL };
			*(class AnimNodeSequence**)params = SeqNode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BeginAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4441);
			byte params[4] = { NULL };
			*(class InterpGroup**)params = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAnimPosition(ScriptName SlotName, int ChannelIndex, ScriptName InAnimSeqName, float InPosition, bool bFireNotifies, bool bLooping, bool bEnableRootMotion)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4443);
			byte params[36] = { NULL };
			*(ScriptName*)params = SlotName;
			*(int*)&params[8] = ChannelIndex;
			*(ScriptName*)&params[12] = InAnimSeqName;
			*(float*)&params[20] = InPosition;
			*(bool*)&params[24] = bFireNotifies;
			*(bool*)&params[28] = bLooping;
			*(bool*)&params[32] = bEnableRootMotion;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FinishAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4451);
			byte params[4] = { NULL };
			*(class InterpGroup**)params = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool PlayActorFaceFXAnim(class FaceFXAnimSet* AnimSet, ScriptString* GroupName, ScriptString* SeqName, class SoundCue* SoundCueToPlay)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4453);
			byte params[36] = { NULL };
			*(class FaceFXAnimSet**)params = AnimSet;
			*(ScriptString**)&params[4] = GroupName;
			*(ScriptString**)&params[16] = SeqName;
			*(class SoundCue**)&params[28] = SoundCueToPlay;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[32];
		}
		void StopActorFaceFXAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4459);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMorphWeight(ScriptName MorphNodeName, float MorphWeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4460);
			byte params[12] = { NULL };
			*(ScriptName*)params = MorphNodeName;
			*(float*)&params[8] = MorphWeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSkelControlScale(ScriptName SkelControlName, float Scale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4463);
			byte params[12] = { NULL };
			*(ScriptName*)params = SkelControlName;
			*(float*)&params[8] = Scale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsActorPlayingFaceFXAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4466);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool CanActorPlayFaceFXAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4468);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		class FaceFXAsset* GetActorFaceFXAsset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4470);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class FaceFXAsset**)params;
		}
		bool IsStationary()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4472);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void GetActorEyesViewPoint(Vector& out_Location, Rotator& out_Rotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4474);
			byte params[24] = { NULL };
			*(Vector*)params = out_Location;
			*(Rotator*)&params[12] = out_Rotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Location = *(Vector*)params;
			out_Rotation = *(Rotator*)&params[12];
		}
		bool IsPlayerOwned()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4477);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void PawnBaseDied()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4479);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		byte GetTeamNum()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4480);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *params;
		}
		byte ScriptGetTeamNum()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4482);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *params;
		}
		void NotifyLocalPlayerTeamReceived()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4484);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FindGoodEndView(class PlayerController* PC, Rotator& GoodRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4485);
			byte params[16] = { NULL };
			*(class PlayerController**)params = PC;
			*(Rotator*)&params[4] = GoodRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			GoodRotation = *(Rotator*)&params[4];
		}
		Vector GetTargetLocation(class Actor* RequestedBy, bool bRequestAlternateLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4488);
			byte params[20] = { NULL };
			*(class Actor**)params = RequestedBy;
			*(bool*)&params[4] = bRequestAlternateLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[8];
		}
		void SpawnedByKismet()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4492);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InterpolationStarted(class SeqAct_Interp* InterpAction, class InterpGroupInst* GroupInst)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4493);
			byte params[8] = { NULL };
			*(class SeqAct_Interp**)params = InterpAction;
			*(class InterpGroupInst**)&params[4] = GroupInst;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InterpolationFinished(class SeqAct_Interp* InterpAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4496);
			byte params[4] = { NULL };
			*(class SeqAct_Interp**)params = InterpAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InterpolationChanged(class SeqAct_Interp* InterpAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4498);
			byte params[4] = { NULL };
			*(class SeqAct_Interp**)params = InterpAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RigidBodyCollision(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* HitComponent, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComponent, Actor::CollisionImpactData& RigidCollisionData, int ContactIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4500);
			byte params[48] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = HitComponent;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComponent;
			*(Actor::CollisionImpactData*)&params[8] = RigidCollisionData;
			*(int*)&params[44] = ContactIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			RigidCollisionData = *(Actor::CollisionImpactData*)&params[8];
		}
		void OnRanOver(class SVehicle* Vehicle, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* RunOverComponent, int WheelIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4505);
			byte params[12] = { NULL };
			*(class SVehicle**)params = Vehicle;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = RunOverComponent;
			*(int*)&params[8] = WheelIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetHUDLocation(Vector NewHUDLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4509);
			byte params[12] = { NULL };
			*(Vector*)params = NewHUDLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NativePostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4511);
			byte params[32] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Vector*)&params[8] = CameraPosition;
			*(Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4516);
			byte params[32] = { NULL };
			*(class PlayerController**)params = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Vector*)&params[8] = CameraPosition;
			*(Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RootMotionModeChanged(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4521);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RootMotionExtracted(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp, Object::BoneAtom& ExtractedRootMotionDelta)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4523);
			byte params[36] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			*(Object::BoneAtom*)&params[16] = ExtractedRootMotionDelta;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ExtractedRootMotionDelta = *(Object::BoneAtom*)&params[16];
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4526);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Guid GetPackageGuid(ScriptName PackageName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4528);
			byte params[24] = { NULL };
			*(ScriptName*)params = PackageName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Guid*)&params[8];
		}
		void OnRigidBodySpringOverextension(class RB_BodyInstance* BodyInstance)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4531);
			byte params[4] = { NULL };
			*(class RB_BodyInstance**)params = BodyInstance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsInPersistentLevel(bool bIncludeLevelStreamingPersistent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4533);
			byte params[8] = { NULL };
			*(bool*)params = bIncludeLevelStreamingPersistent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void GetAimFrictionExtent(float& Width, float& Height, Vector& Center)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4536);
			byte params[20] = { NULL };
			*(float*)params = Width;
			*(float*)&params[4] = Height;
			*(Vector*)&params[8] = Center;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Width = *(float*)params;
			Height = *(float*)&params[4];
			Center = *(Vector*)&params[8];
		}
		void GetAimAdhesionExtent(float& Width, float& Height, Vector& Center)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4541);
			byte params[20] = { NULL };
			*(float*)params = Width;
			*(float*)&params[4] = Height;
			*(Vector*)&params[8] = Center;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Width = *(float*)params;
			Height = *(float*)&params[4];
			Center = *(Vector*)&params[8];
		}
		bool PlayParticleEffect(class AnimNotify_PlayParticleEffect* AnimNotifyData)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4546);
			byte params[8] = { NULL };
			*(class AnimNotify_PlayParticleEffect**)params = AnimNotifyData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CreateForceField(class AnimNotify_ForceField* AnimNotifyData)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4549);
			byte params[8] = { NULL };
			*(class AnimNotify_ForceField**)params = AnimNotifyData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void TrailsNotify(class AnimNotify_Trails* AnimNotifyData)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4552);
			byte params[4] = { NULL };
			*(class AnimNotify_Trails**)params = AnimNotifyData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TrailsNotifyTick(class AnimNotify_Trails* AnimNotifyData)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4554);
			byte params[4] = { NULL };
			*(class AnimNotify_Trails**)params = AnimNotifyData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TrailsNotifyEnd(class AnimNotify_Trails* AnimNotifyData)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4556);
			byte params[4] = { NULL };
			*(class AnimNotify_Trails**)params = AnimNotifyData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SupportsKismetModification(class SequenceOp* AskingOp, ScriptString*& Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4558);
			byte params[20] = { NULL };
			*(class SequenceOp**)params = AskingOp;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Reason = *(ScriptString**)&params[4];
			return *(bool*)&params[16];
		}
		void AnimTreeUpdated(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMesh)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4562);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelMesh;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostDemoRewind()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4564);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicationEnded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4565);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Vector GetAvoidanceVector(ScriptArray<class Actor*>& Obstacles, Vector GoalLocation, float CollisionRadius, float MaxSpeed, int NumSamples, float VelocityStepRate, float MaxTimeTilOverlap)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4566);
			byte params[56] = { NULL };
			*(ScriptArray<class Actor*>*)params = Obstacles;
			*(Vector*)&params[12] = GoalLocation;
			*(float*)&params[24] = CollisionRadius;
			*(float*)&params[28] = MaxSpeed;
			*(int*)&params[32] = NumSamples;
			*(float*)&params[36] = VelocityStepRate;
			*(float*)&params[40] = MaxTimeTilOverlap;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Obstacles = *(ScriptArray<class Actor*>*)params;
			return *(Vector*)&params[44];
		}
		bool WillOverlap(Vector PosA, Vector VelA, Vector PosB, Vector VelB, float StepSize, float Radius, float& Time)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4576);
			byte params[64] = { NULL };
			*(Vector*)params = PosA;
			*(Vector*)&params[12] = VelA;
			*(Vector*)&params[24] = PosB;
			*(Vector*)&params[36] = VelB;
			*(float*)&params[48] = StepSize;
			*(float*)&params[52] = Radius;
			*(float*)&params[56] = Time;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Time = *(float*)&params[56];
			return *(bool*)&params[60];
		}
		bool ShouldBeHiddenBySHOW_NavigationNodes()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4585);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		ScriptString* GetSpectatorName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4587);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		ScriptString* GetSpectatorDescription()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4589);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void GetSpectatorHealthInfo(int& Health, int& MaxHealth)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4591);
			byte params[8] = { NULL };
			*(int*)params = Health;
			*(int*)&params[4] = MaxHealth;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Health = *(int*)params;
			MaxHealth = *(int*)&params[4];
		}
	};
	const float Actor::MINFLOORZ = 0.7f;
	const float Actor::ACTORMAXSTEPHEIGHT = 35.0f;
	const float Actor::RBSTATE_LINVELSCALE = 10.0f;
	const float Actor::RBSTATE_ANGVELSCALE = 1000.0f;
	const float Actor::REP_RBLOCATION_ERROR_TOLERANCE_SQ = 16.0f;
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
