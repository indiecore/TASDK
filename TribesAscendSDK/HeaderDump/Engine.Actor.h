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
		class AnimSlotDesc
		{
		public:
			ADD_STRUCT(ScriptName, SlotName, 0)
			ADD_STRUCT(int, NumChannels, 8)
		};
		class RigidBodyState
		{
		public:
			ADD_STRUCT(byte, bNewData, 56)
			ADD_STRUCT(Object::Vector, AngVel, 44)
			ADD_STRUCT(Object::Vector, LinVel, 32)
			ADD_STRUCT(Object::Quat, Quaternion, 16)
			ADD_STRUCT(Object::Vector, Position, 0)
		};
		class RigidBodyContactInfo
		{
		public:
			ADD_OBJECT(PhysicalMaterial, PhysMaterial, 52)
			ADD_STRUCT(Object::Vector, ContactVelocity, 28)
			ADD_STRUCT(float, ContactPenetration, 24)
			ADD_STRUCT(Object::Vector, ContactNormal, 12)
			ADD_STRUCT(Object::Vector, ContactPosition, 0)
		};
		class CollisionImpactData
		{
		public:
			ADD_STRUCT(ScriptArray<Actor::RigidBodyContactInfo>, ContactInfos, 0)
			ADD_STRUCT(Object::Vector, TotalFrictionForceVector, 24)
			ADD_STRUCT(Object::Vector, TotalNormalForceVector, 12)
		};
		class PhysEffectInfo
		{
		public:
			ADD_OBJECT(SoundCue, Sound, 12)
			ADD_OBJECT(ParticleSystem, Effect, 8)
			ADD_STRUCT(float, ReFireDelay, 4)
			ADD_STRUCT(float, Threshold, 0)
		};
		class ActorReference
		{
		public:
			ADD_STRUCT(Object::Guid, Guid, 4)
			ADD_OBJECT(Actor, Actor, 0)
		};
		class NavReference
		{
		public:
			ADD_STRUCT(Object::Guid, Guid, 4)
			ADD_OBJECT(NavigationPoint, Nav, 0)
		};
		class BasedPosition
		{
		public:
			ADD_STRUCT(Object::Vector, CachedTransPosition, 40)
			ADD_STRUCT(Object::Rotator, CachedBaseRotation, 28)
			ADD_STRUCT(Object::Vector, CachedBaseLocation, 16)
			ADD_STRUCT(Object::Vector, Position, 4)
			ADD_OBJECT(Actor, Base, 0)
		};
		class TraceHitInfo
		{
		public:
			ADD_OBJECT(Material, Material, 0)
			ADD_OBJECT(PhysicalMaterial, PhysMaterial, 4)
			ADD_STRUCT(int, Item, 8)
			ADD_STRUCT(int, LevelIndex, 12)
			ADD_STRUCT(ScriptName, BoneName, 16)
		};
		class ImpactInfo
		{
		public:
			ADD_OBJECT(Actor, HitActor, 0)
			ADD_STRUCT(Object::Vector, HitLocation, 4)
			ADD_STRUCT(Object::Vector, HitNormal, 16)
			ADD_STRUCT(Object::Vector, RayDir, 28)
			ADD_STRUCT(Object::Vector, StartTrace, 40)
			ADD_STRUCT(Actor::TraceHitInfo, HitInfo, 52)
		};
		class AnimSlotInfo
		{
		public:
			ADD_STRUCT(ScriptName, SlotName, 0)
			ADD_STRUCT(ScriptArray<float>, ChannelWeights, 8)
		};
		class TimerData
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
		ADD_STRUCT(Object::Vector, Location, 188)
		ADD_STRUCT(Object::Rotator, Rotation, 84)
		ADD_BOOL(bDeleteMe, 164, 0x8)
		ADD_STRUCT(Actor::ENetRole, Role, 138)
		ADD_STRUCT(Actor::ENetRole, RemoteRole, 137)
		ADD_BOOL(bTearOff, 164, 0x4000000)
		ADD_OBJECT(PhysicsVolume, PhysicsVolume, 324)
		ADD_OBJECT(Actor, Base, 148)
		ADD_BOOL(bBounce, 172, 0x200)
		ADD_BOOL(bHardAttach, 168, 0x400)
		ADD_STRUCT(Object::Vector, RelativeLocation, 388)
		ADD_STRUCT(Object::Rotator, RelativeRotation, 400)
		ADD_STRUCT(ScriptName, BaseBoneName, 368)
		ADD_STRUCT(Object::Vector, Velocity, 328)
		ADD_STRUCT(Object::Vector, Acceleration, 340)
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
		ADD_STRUCT(Object::Vector, DrawScale3D, 100)
		ADD_STRUCT(Object::Vector, PrePivot, 112)
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
		ADD_STRUCT(Object::QWord, HiddenEditorViews, 284)
		ADD_STRUCT(ScriptArray<class Actor*>, Touching, 292)
		ADD_STRUCT(ScriptArray<class Actor*>, Children, 304)
		ADD_STRUCT(float, LatentFloat, 316)
		ADD_OBJECT(AnimNodeSequence, LatentSeqNode, 320)
		ADD_STRUCT(Object::Vector, AngularVelocity, 352)
		ADD_STRUCT(int, OverlapTag, 416)
		ADD_STRUCT(Object::Rotator, RotationRate, 420)
		ADD_OBJECT(Actor, PendingTouch, 432)
		ADD_OBJECT(ScriptClass, MessageClass, 436)
		ADD_STRUCT(ScriptArray<ScriptClass*>, SupportedEvents, 440)
		void ForceUpdateComponents(bool bCollisionUpdate, bool bTransformOnly)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.ForceUpdateComponents");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bCollisionUpdate;
			*(bool*)&params[4] = bTransformOnly;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* ConsoleCommand(ScriptString* Command, bool bWriteToLog)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.ConsoleCommand");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = Command;
			*(bool*)&params[12] = bWriteToLog;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[16];
		}
		void Sleep(float Seconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.Sleep");
			byte params[4] = { NULL };
			*(float*)&params[0] = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FinishAnim(class AnimNodeSequence* SeqNode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.FinishAnim");
			byte params[4] = { NULL };
			*(class AnimNodeSequence**)&params[0] = SeqNode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCollision(bool bNewColActors, bool bNewBlockActors, bool bNewIgnoreEncroachers)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetCollision");
			byte params[12] = { NULL };
			*(bool*)&params[0] = bNewColActors;
			*(bool*)&params[4] = bNewBlockActors;
			*(bool*)&params[8] = bNewIgnoreEncroachers;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCollisionSize(float NewRadius, float NewHeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetCollisionSize");
			byte params[8] = { NULL };
			*(float*)&params[0] = NewRadius;
			*(float*)&params[4] = NewHeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCollisionType(Actor::ECollisionType NewCollisionType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetCollisionType");
			byte params[1] = { NULL };
			*(Actor::ECollisionType*)&params[0] = NewCollisionType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDrawScale(float NewScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetDrawScale");
			byte params[4] = { NULL };
			*(float*)&params[0] = NewScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDrawScale3D(Object::Vector NewScale3D)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetDrawScale3D");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = NewScale3D;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool Move(Object::Vector Delta)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.Move");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = Delta;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool SetLocation(Object::Vector NewLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetLocation");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = NewLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool SetRotation(Object::Rotator NewRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetRotation");
			byte params[16] = { NULL };
			*(Object::Rotator*)&params[0] = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		Actor::EMoveDir MovingWhichWay(float& Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.MovingWhichWay");
			byte params[5] = { NULL };
			*(float*)&params[0] = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Amount = *(float*)&params[0];
			return *(Actor::EMoveDir*)&params[4];
		}
		void SetZone(bool bForceRefresh)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetZone");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bForceRefresh;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SetRelativeRotation(Object::Rotator NewRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetRelativeRotation");
			byte params[16] = { NULL };
			*(Object::Rotator*)&params[0] = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool SetRelativeLocation(Object::Vector NewLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetRelativeLocation");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = NewLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void SetHardAttach(bool bNewHardAttach)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetHardAttach");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewHardAttach;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int fixedTurn(int Current, int Desired, int DeltaRate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.fixedTurn");
			byte params[16] = { NULL };
			*(int*)&params[0] = Current;
			*(int*)&params[4] = Desired;
			*(int*)&params[8] = DeltaRate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		bool MoveSmooth(Object::Vector Delta)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.MoveSmooth");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = Delta;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void AutonomousPhysics(float DeltaSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.AutonomousPhysics");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaSeconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetTerminalVelocity()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetTerminalVelocity");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void SetBase(class Actor* NewBase, Object::Vector NewFloor, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp, ScriptName AttachName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetBase");
			byte params[28] = { NULL };
			*(class Actor**)&params[0] = NewBase;
			*(Object::Vector*)&params[4] = NewFloor;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[16] = SkelComp;
			*(ScriptName*)&params[20] = AttachName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetOwner(class Actor* NewOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetOwner");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = NewOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FindBase()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.FindBase");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsBasedOn(class Actor* TestActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.IsBasedOn");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = TestActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class Actor* GetBaseMost()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetBaseMost");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[0];
		}
		bool IsOwnedBy(class Actor* TestActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.IsOwnedBy");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = TestActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		Object::Vector GetAggregateBaseVelocity(class Actor* TestBase)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetAggregateBaseVelocity");
			byte params[16] = { NULL };
			*(class Actor**)&params[0] = TestBase;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[4];
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetForcedInitialReplicatedProperty(class Property* PropToReplicate, bool bAdd)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetForcedInitialReplicatedProperty");
			byte params[8] = { NULL };
			*(class Property**)&params[0] = PropToReplicate;
			*(bool*)&params[4] = bAdd;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Vect2BP(Actor::BasedPosition& BP, Object::Vector pos, class Actor* ForcedBase)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.Vect2BP");
			byte params[68] = { NULL };
			*(Actor::BasedPosition*)&params[0] = BP;
			*(Object::Vector*)&params[52] = pos;
			*(class Actor**)&params[64] = ForcedBase;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			BP = *(Actor::BasedPosition*)&params[0];
		}
		Object::Vector BP2Vect(Actor::BasedPosition BP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.BP2Vect");
			byte params[64] = { NULL };
			*(Actor::BasedPosition*)&params[0] = BP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[52];
		}
		void SetBasedPosition(Actor::BasedPosition& BP, Object::Vector pos, class Actor* ForcedBase)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetBasedPosition");
			byte params[68] = { NULL };
			*(Actor::BasedPosition*)&params[0] = BP;
			*(Object::Vector*)&params[52] = pos;
			*(class Actor**)&params[64] = ForcedBase;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			BP = *(Actor::BasedPosition*)&params[0];
		}
		Object::Vector GetBasedPosition(Actor::BasedPosition BP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetBasedPosition");
			byte params[64] = { NULL };
			*(Actor::BasedPosition*)&params[0] = BP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[52];
		}
		void FlushPersistentDebugLines()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.FlushPersistentDebugLines");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawDebugLine(Object::Vector LineStart, Object::Vector LineEnd, byte R, byte G, byte B, bool bPersistentLines)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.DrawDebugLine");
			byte params[31] = { NULL };
			*(Object::Vector*)&params[0] = LineStart;
			*(Object::Vector*)&params[12] = LineEnd;
			params[24] = R;
			params[25] = G;
			params[26] = B;
			*(bool*)&params[28] = bPersistentLines;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawDebugPoint(Object::Vector Position, float Size, Object::LinearColor PointColor, bool bPersistentLines)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.DrawDebugPoint");
			byte params[36] = { NULL };
			*(Object::Vector*)&params[0] = Position;
			*(float*)&params[12] = Size;
			*(Object::LinearColor*)&params[16] = PointColor;
			*(bool*)&params[32] = bPersistentLines;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawDebugBox(Object::Vector Center, Object::Vector Extent, byte R, byte G, byte B, bool bPersistentLines)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.DrawDebugBox");
			byte params[31] = { NULL };
			*(Object::Vector*)&params[0] = Center;
			*(Object::Vector*)&params[12] = Extent;
			params[24] = R;
			params[25] = G;
			params[26] = B;
			*(bool*)&params[28] = bPersistentLines;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawDebugStar(Object::Vector Position, float Size, byte R, byte G, byte B, bool bPersistentLines)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.DrawDebugStar");
			byte params[23] = { NULL };
			*(Object::Vector*)&params[0] = Position;
			*(float*)&params[12] = Size;
			params[16] = R;
			params[17] = G;
			params[18] = B;
			*(bool*)&params[20] = bPersistentLines;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawDebugCoordinateSystem(Object::Vector AxisLoc, Object::Rotator AxisRot, float Scale, bool bPersistentLines)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.DrawDebugCoordinateSystem");
			byte params[32] = { NULL };
			*(Object::Vector*)&params[0] = AxisLoc;
			*(Object::Rotator*)&params[12] = AxisRot;
			*(float*)&params[24] = Scale;
			*(bool*)&params[28] = bPersistentLines;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawDebugSphere(Object::Vector Center, float Radius, int Segments, byte R, byte G, byte B, bool bPersistentLines)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.DrawDebugSphere");
			byte params[27] = { NULL };
			*(Object::Vector*)&params[0] = Center;
			*(float*)&params[12] = Radius;
			*(int*)&params[16] = Segments;
			params[20] = R;
			params[21] = G;
			params[22] = B;
			*(bool*)&params[24] = bPersistentLines;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawDebugCylinder(Object::Vector Start, Object::Vector End, float Radius, int Segments, byte R, byte G, byte B, bool bPersistentLines)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.DrawDebugCylinder");
			byte params[39] = { NULL };
			*(Object::Vector*)&params[0] = Start;
			*(Object::Vector*)&params[12] = End;
			*(float*)&params[24] = Radius;
			*(int*)&params[28] = Segments;
			params[32] = R;
			params[33] = G;
			params[34] = B;
			*(bool*)&params[36] = bPersistentLines;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawDebugCone(Object::Vector Origin, Object::Vector Direction, float Length, float AngleWidth, float AngleHeight, int NumSides, Object::Color DrawColor, bool bPersistentLines)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.DrawDebugCone");
			byte params[48] = { NULL };
			*(Object::Vector*)&params[0] = Origin;
			*(Object::Vector*)&params[12] = Direction;
			*(float*)&params[24] = Length;
			*(float*)&params[28] = AngleWidth;
			*(float*)&params[32] = AngleHeight;
			*(int*)&params[36] = NumSides;
			*(Object::Color*)&params[40] = DrawColor;
			*(bool*)&params[44] = bPersistentLines;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawDebugString(Object::Vector TextLocation, ScriptString* Text, class Actor* TestBaseActor, Object::Color TextColor, float Duration)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.DrawDebugString");
			byte params[36] = { NULL };
			*(Object::Vector*)&params[0] = TextLocation;
			*(ScriptString**)&params[12] = Text;
			*(class Actor**)&params[24] = TestBaseActor;
			*(Object::Color*)&params[28] = TextColor;
			*(float*)&params[32] = Duration;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawDebugFrustrum(Object::Matrix& FrustumToWorld, byte R, byte G, byte B, bool bPersistentLines)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.DrawDebugFrustrum");
			byte params[71] = { NULL };
			*(Object::Matrix*)&params[0] = FrustumToWorld;
			params[64] = R;
			params[65] = G;
			params[66] = B;
			*(bool*)&params[68] = bPersistentLines;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			FrustumToWorld = *(Object::Matrix*)&params[0];
		}
		void FlushDebugStrings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.FlushDebugStrings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChartData(ScriptString* DataName, float DataValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.ChartData");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = DataName;
			*(float*)&params[12] = DataValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetHidden(bool bNewHidden)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetHidden");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewHidden;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetOnlyOwnerSee(bool bNewOnlyOwnerSee)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetOnlyOwnerSee");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewOnlyOwnerSee;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPhysics(Actor::EPhysics newPhysics)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetPhysics");
			byte params[1] = { NULL };
			*(Actor::EPhysics*)&params[0] = newPhysics;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Clock(float& Time)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.Clock");
			byte params[4] = { NULL };
			*(float*)&params[0] = Time;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Time = *(float*)&params[0];
		}
		void UnClock(float& Time)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.UnClock");
			byte params[4] = { NULL };
			*(float*)&params[0] = Time;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Time = *(float*)&params[0];
		}
		void AttachComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* NewComponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.AttachComponent");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = NewComponent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetachComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* ExComponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.DetachComponent");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = ExComponent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReattachComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* ComponentToReattach)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.ReattachComponent");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = ComponentToReattach;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTickGroup(Object::ETickingGroup NewTickGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetTickGroup");
			byte params[1] = { NULL };
			*(Object::ETickingGroup*)&params[0] = NewTickGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTickIsDisabled(bool bInDisabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetTickIsDisabled");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bInDisabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GainedChild(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GainedChild");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LostChild(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.LostChild");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Timer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.Timer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HitWall(Object::Vector HitNormal, class Actor* Wall, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* WallComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.HitWall");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = HitNormal;
			*(class Actor**)&params[12] = Wall;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[16] = WallComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Falling()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.Falling");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Landed(Object::Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.Landed");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = HitNormal;
			*(class Actor**)&params[12] = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PhysicsVolumeChange(class PhysicsVolume* NewVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.PhysicsVolumeChange");
			byte params[4] = { NULL };
			*(class PhysicsVolume**)&params[0] = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.Touch");
			byte params[32] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostTouch(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.PostTouch");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnTouch(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.UnTouch");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Bump(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.Bump");
			byte params[20] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Object::Vector*)&params[8] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BaseChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.BaseChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Attach(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.Attach");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Detach(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.Detach");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Actor* SpecialHandling(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SpecialHandling");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[4];
		}
		void CollisionChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.CollisionChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool EncroachingOn(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.EncroachingOn");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void EncroachedBy(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.EncroachedBy");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RanInto(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.RanInto");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnWakeRBPhysics()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.OnWakeRBPhysics");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSleepRBPhysics()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.OnSleepRBPhysics");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ClampRotation(Object::Rotator& out_Rot, Object::Rotator rBase, Object::Rotator rUpperLimits, Object::Rotator rLowerLimits)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.ClampRotation");
			byte params[52] = { NULL };
			*(Object::Rotator*)&params[0] = out_Rot;
			*(Object::Rotator*)&params[12] = rBase;
			*(Object::Rotator*)&params[24] = rUpperLimits;
			*(Object::Rotator*)&params[36] = rLowerLimits;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Rot = *(Object::Rotator*)&params[0];
			return *(bool*)&params[48];
		}
		bool OverRotated(Object::Rotator& out_Desired, Object::Rotator& out_Actual)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.OverRotated");
			byte params[28] = { NULL };
			*(Object::Rotator*)&params[0] = out_Desired;
			*(Object::Rotator*)&params[12] = out_Actual;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Desired = *(Object::Rotator*)&params[0];
			out_Actual = *(Object::Rotator*)&params[12];
			return *(bool*)&params[24];
		}
		bool UsedBy(class Pawn* User)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.UsedBy");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = User;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.FellOutOfWorld");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OutsideWorldBounds()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.OutsideWorldBounds");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void VolumeBasedDestroy(class PhysicsVolume* PV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.VolumeBasedDestroy");
			byte params[4] = { NULL };
			*(class PhysicsVolume**)&params[0] = PV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Actor* Trace(Object::Vector& HitLocation, Object::Vector& HitNormal, Object::Vector TraceEnd, Object::Vector TraceStart, bool bTraceActors, Object::Vector Extent, Actor::TraceHitInfo& HitInfo, int ExtraTraceFlags)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.Trace");
			byte params[100] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(Object::Vector*)&params[12] = HitNormal;
			*(Object::Vector*)&params[24] = TraceEnd;
			*(Object::Vector*)&params[36] = TraceStart;
			*(bool*)&params[48] = bTraceActors;
			*(Object::Vector*)&params[52] = Extent;
			*(Actor::TraceHitInfo*)&params[64] = HitInfo;
			*(int*)&params[92] = ExtraTraceFlags;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			HitLocation = *(Object::Vector*)&params[0];
			HitNormal = *(Object::Vector*)&params[12];
			HitInfo = *(Actor::TraceHitInfo*)&params[64];
			return *(class Actor**)&params[96];
		}
		bool TraceComponent(Object::Vector& HitLocation, Object::Vector& HitNormal, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* InComponent, Object::Vector TraceEnd, Object::Vector TraceStart, Object::Vector Extent, Actor::TraceHitInfo& HitInfo, bool bComplexCollision)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.TraceComponent");
			byte params[100] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(Object::Vector*)&params[12] = HitNormal;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[24] = InComponent;
			*(Object::Vector*)&params[28] = TraceEnd;
			*(Object::Vector*)&params[40] = TraceStart;
			*(Object::Vector*)&params[52] = Extent;
			*(Actor::TraceHitInfo*)&params[64] = HitInfo;
			*(bool*)&params[92] = bComplexCollision;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			HitLocation = *(Object::Vector*)&params[0];
			HitNormal = *(Object::Vector*)&params[12];
			HitInfo = *(Actor::TraceHitInfo*)&params[64];
			return *(bool*)&params[96];
		}
		bool PointCheckComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* InComponent, Object::Vector PointLocation, Object::Vector PointExtent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.PointCheckComponent");
			byte params[32] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = InComponent;
			*(Object::Vector*)&params[4] = PointLocation;
			*(Object::Vector*)&params[16] = PointExtent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		bool FastTrace(Object::Vector TraceEnd, Object::Vector TraceStart, Object::Vector BoxExtent, bool bTraceBullet)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.FastTrace");
			byte params[44] = { NULL };
			*(Object::Vector*)&params[0] = TraceEnd;
			*(Object::Vector*)&params[12] = TraceStart;
			*(Object::Vector*)&params[24] = BoxExtent;
			*(bool*)&params[36] = bTraceBullet;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[40];
		}
		bool TraceAllPhysicsAssetInteractions(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMeshComp, Object::Vector EndTrace, Object::Vector StartTrace, ScriptArray<Actor::ImpactInfo>& out_Hits, Object::Vector Extent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.TraceAllPhysicsAssetInteractions");
			byte params[56] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = SkelMeshComp;
			*(Object::Vector*)&params[4] = EndTrace;
			*(Object::Vector*)&params[16] = StartTrace;
			*(ScriptArray<Actor::ImpactInfo>*)&params[28] = out_Hits;
			*(Object::Vector*)&params[40] = Extent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Hits = *(ScriptArray<Actor::ImpactInfo>*)&params[28];
			return *(bool*)&params[52];
		}
		bool FindSpot(Object::Vector BoxExtent, Object::Vector& SpotLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.FindSpot");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = BoxExtent;
			*(Object::Vector*)&params[12] = SpotLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			SpotLocation = *(Object::Vector*)&params[12];
			return *(bool*)&params[24];
		}
		bool ContainsPoint(Object::Vector Spot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.ContainsPoint");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = Spot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool IsOverlapping(class Actor* A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.IsOverlapping");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void GetComponentsBoundingBox(Object::Box& ActorBox)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetComponentsBoundingBox");
			byte params[28] = { NULL };
			*(Object::Box*)&params[0] = ActorBox;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ActorBox = *(Object::Box*)&params[0];
		}
		void GetBoundingCylinder(float& CollisionRadius, float& CollisionHeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetBoundingCylinder");
			byte params[8] = { NULL };
			*(float*)&params[0] = CollisionRadius;
			*(float*)&params[4] = CollisionHeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CollisionRadius = *(float*)&params[0];
			CollisionHeight = *(float*)&params[4];
		}
		bool IsBlockedBy(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.IsBlockedBy");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class Actor* Spawn(ScriptClass* SpawnClass, class Actor* SpawnOwner, ScriptName SpawnTag, Object::Vector SpawnLocation, Object::Rotator SpawnRotation, class Actor* ActorTemplate, bool bNoCollisionFail)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.Spawn");
			byte params[52] = { NULL };
			*(ScriptClass**)&params[0] = SpawnClass;
			*(class Actor**)&params[4] = SpawnOwner;
			*(ScriptName*)&params[8] = SpawnTag;
			*(Object::Vector*)&params[16] = SpawnLocation;
			*(Object::Rotator*)&params[28] = SpawnRotation;
			*(class Actor**)&params[40] = ActorTemplate;
			*(bool*)&params[44] = bNoCollisionFail;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[48];
		}
		bool Destroy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.Destroy");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void TornOff()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.TornOff");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetTimer(float InRate, bool inbLoop, ScriptName inTimerFunc, class Object* inObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetTimer");
			byte params[20] = { NULL };
			*(float*)&params[0] = InRate;
			*(bool*)&params[4] = inbLoop;
			*(ScriptName*)&params[8] = inTimerFunc;
			*(class Object**)&params[16] = inObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearTimer(ScriptName inTimerFunc, class Object* inObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.ClearTimer");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = inTimerFunc;
			*(class Object**)&params[8] = inObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearAllTimers(class Object* inObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.ClearAllTimers");
			byte params[4] = { NULL };
			*(class Object**)&params[0] = inObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PauseTimer(bool bPause, ScriptName inTimerFunc, class Object* inObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.PauseTimer");
			byte params[16] = { NULL };
			*(bool*)&params[0] = bPause;
			*(ScriptName*)&params[4] = inTimerFunc;
			*(class Object**)&params[12] = inObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsTimerActive(ScriptName inTimerFunc, class Object* inObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.IsTimerActive");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = inTimerFunc;
			*(class Object**)&params[8] = inObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		float GetTimerCount(ScriptName inTimerFunc, class Object* inObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetTimerCount");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = inTimerFunc;
			*(class Object**)&params[8] = inObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float GetTimerRate(ScriptName TimerFuncName, class Object* inObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetTimerRate");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = TimerFuncName;
			*(class Object**)&params[8] = inObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float GetRemainingTimeForTimer(ScriptName TimerFuncName, class Object* inObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetRemainingTimeForTimer");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = TimerFuncName;
			*(class Object**)&params[8] = inObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		void ModifyTimerTimeDilation(ScriptName TimerName, float InTimerTimeDilation, class Object* inObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.ModifyTimerTimeDilation");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = TimerName;
			*(float*)&params[8] = InTimerTimeDilation;
			*(class Object**)&params[12] = inObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetTimerTimeDilation(ScriptName TimerName, class Object* inObj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.ResetTimerTimeDilation");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = TimerName;
			*(class Object**)&params[8] = inObj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* CreateAudioComponent(class SoundCue* InSoundCue, bool bPlay, bool bStopWhenOwnerDestroyed, bool bUseLocation, Object::Vector SourceLocation, bool bAttachToSelf)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.CreateAudioComponent");
			byte params[36] = { NULL };
			*(class SoundCue**)&params[0] = InSoundCue;
			*(bool*)&params[4] = bPlay;
			*(bool*)&params[8] = bStopWhenOwnerDestroyed;
			*(bool*)&params[12] = bUseLocation;
			*(Object::Vector*)&params[16] = SourceLocation;
			*(bool*)&params[28] = bAttachToSelf;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[32];
		}
		void PlaySound(class SoundCue* InSoundCue, bool bNotReplicated, bool bNoRepToOwner, bool bStopWhenOwnerDestroyed, Object::Vector SoundLocation, bool bNoRepToRelevant)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.PlaySound");
			byte params[32] = { NULL };
			*(class SoundCue**)&params[0] = InSoundCue;
			*(bool*)&params[4] = bNotReplicated;
			*(bool*)&params[8] = bNoRepToOwner;
			*(bool*)&params[12] = bStopWhenOwnerDestroyed;
			*(Object::Vector*)&params[16] = SoundLocation;
			*(bool*)&params[28] = bNoRepToRelevant;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MakeNoise(float Loudness, ScriptName NoiseType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.MakeNoise");
			byte params[12] = { NULL };
			*(float*)&params[0] = Loudness;
			*(ScriptName*)&params[4] = NoiseType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool PlayerCanSeeMe(bool bForceLOSCheck)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.PlayerCanSeeMe");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bForceLOSCheck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SuggestTossVelocity(Object::Vector& TossVelocity, Object::Vector Destination, Object::Vector Start, float TossSpeed, float BaseTossZ, float DesiredZPct, Object::Vector CollisionSize, float TerminalVelocity, float OverrideGravityZ, bool bOnlyTraceUp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SuggestTossVelocity");
			byte params[76] = { NULL };
			*(Object::Vector*)&params[0] = TossVelocity;
			*(Object::Vector*)&params[12] = Destination;
			*(Object::Vector*)&params[24] = Start;
			*(float*)&params[36] = TossSpeed;
			*(float*)&params[40] = BaseTossZ;
			*(float*)&params[44] = DesiredZPct;
			*(Object::Vector*)&params[48] = CollisionSize;
			*(float*)&params[60] = TerminalVelocity;
			*(float*)&params[64] = OverrideGravityZ;
			*(bool*)&params[68] = bOnlyTraceUp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			TossVelocity = *(Object::Vector*)&params[0];
			return *(bool*)&params[72];
		}
		bool CalculateMinSpeedTrajectory(Object::Vector& out_Velocity, Object::Vector End, Object::Vector Start, float MaxTossSpeed, float MinTossSpeed, Object::Vector CollisionSize, float TerminalVelocity, float GravityZ, bool bOnlyTraceUp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.CalculateMinSpeedTrajectory");
			byte params[72] = { NULL };
			*(Object::Vector*)&params[0] = out_Velocity;
			*(Object::Vector*)&params[12] = End;
			*(Object::Vector*)&params[24] = Start;
			*(float*)&params[36] = MaxTossSpeed;
			*(float*)&params[40] = MinTossSpeed;
			*(Object::Vector*)&params[44] = CollisionSize;
			*(float*)&params[56] = TerminalVelocity;
			*(float*)&params[60] = GravityZ;
			*(bool*)&params[64] = bOnlyTraceUp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Velocity = *(Object::Vector*)&params[0];
			return *(bool*)&params[68];
		}
		Object::Vector GetDestination(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetDestination");
			byte params[16] = { NULL };
			*(class Controller**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[4];
		}
		bool PreTeleport(class Teleporter* InTeleporter)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.PreTeleport");
			byte params[8] = { NULL };
			*(class Teleporter**)&params[0] = InTeleporter;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PostTeleport(class Teleporter* OutTeleporter)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.PostTeleport");
			byte params[4] = { NULL };
			*(class Teleporter**)&params[0] = OutTeleporter;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetURLMap()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetURLMap");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void AllActors(ScriptClass* BaseClass, class Actor*& Actor, ScriptClass* InterfaceClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.AllActors");
			byte params[12] = { NULL };
			*(ScriptClass**)&params[0] = BaseClass;
			*(class Actor**)&params[4] = Actor;
			*(ScriptClass**)&params[8] = InterfaceClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Actor = *(class Actor**)&params[4];
		}
		void DynamicActors(ScriptClass* BaseClass, class Actor*& Actor, ScriptClass* InterfaceClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.DynamicActors");
			byte params[12] = { NULL };
			*(ScriptClass**)&params[0] = BaseClass;
			*(class Actor**)&params[4] = Actor;
			*(ScriptClass**)&params[8] = InterfaceClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Actor = *(class Actor**)&params[4];
		}
		void ChildActors(ScriptClass* BaseClass, class Actor*& Actor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.ChildActors");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = BaseClass;
			*(class Actor**)&params[4] = Actor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Actor = *(class Actor**)&params[4];
		}
		void BasedActors(ScriptClass* BaseClass, class Actor*& Actor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.BasedActors");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = BaseClass;
			*(class Actor**)&params[4] = Actor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Actor = *(class Actor**)&params[4];
		}
		void TouchingActors(ScriptClass* BaseClass, class Actor*& Actor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.TouchingActors");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = BaseClass;
			*(class Actor**)&params[4] = Actor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Actor = *(class Actor**)&params[4];
		}
		void TraceActors(ScriptClass* BaseClass, class Actor*& Actor, Object::Vector& HitLoc, Object::Vector& HitNorm, Object::Vector End, Object::Vector Start, Object::Vector Extent, Actor::TraceHitInfo& HitInfo, int ExtraTraceFlags)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.TraceActors");
			byte params[100] = { NULL };
			*(ScriptClass**)&params[0] = BaseClass;
			*(class Actor**)&params[4] = Actor;
			*(Object::Vector*)&params[8] = HitLoc;
			*(Object::Vector*)&params[20] = HitNorm;
			*(Object::Vector*)&params[32] = End;
			*(Object::Vector*)&params[44] = Start;
			*(Object::Vector*)&params[56] = Extent;
			*(Actor::TraceHitInfo*)&params[68] = HitInfo;
			*(int*)&params[96] = ExtraTraceFlags;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Actor = *(class Actor**)&params[4];
			HitLoc = *(Object::Vector*)&params[8];
			HitNorm = *(Object::Vector*)&params[20];
			HitInfo = *(Actor::TraceHitInfo*)&params[68];
		}
		void VisibleActors(ScriptClass* BaseClass, class Actor*& Actor, float Radius, Object::Vector Loc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.VisibleActors");
			byte params[24] = { NULL };
			*(ScriptClass**)&params[0] = BaseClass;
			*(class Actor**)&params[4] = Actor;
			*(float*)&params[8] = Radius;
			*(Object::Vector*)&params[12] = Loc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Actor = *(class Actor**)&params[4];
		}
		void VisibleCollidingActors(ScriptClass* BaseClass, class Actor*& Actor, float Radius, Object::Vector Loc, bool bIgnoreHidden, Object::Vector Extent, bool bTraceActors, ScriptClass* InterfaceClass, Actor::TraceHitInfo& HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.VisibleCollidingActors");
			byte params[76] = { NULL };
			*(ScriptClass**)&params[0] = BaseClass;
			*(class Actor**)&params[4] = Actor;
			*(float*)&params[8] = Radius;
			*(Object::Vector*)&params[12] = Loc;
			*(bool*)&params[24] = bIgnoreHidden;
			*(Object::Vector*)&params[28] = Extent;
			*(bool*)&params[40] = bTraceActors;
			*(ScriptClass**)&params[44] = InterfaceClass;
			*(Actor::TraceHitInfo*)&params[48] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Actor = *(class Actor**)&params[4];
			HitInfo = *(Actor::TraceHitInfo*)&params[48];
		}
		void CollidingActors(ScriptClass* BaseClass, class Actor*& Actor, float Radius, Object::Vector Loc, bool bUseOverlapCheck, ScriptClass* InterfaceClass, Actor::TraceHitInfo& HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.CollidingActors");
			byte params[60] = { NULL };
			*(ScriptClass**)&params[0] = BaseClass;
			*(class Actor**)&params[4] = Actor;
			*(float*)&params[8] = Radius;
			*(Object::Vector*)&params[12] = Loc;
			*(bool*)&params[24] = bUseOverlapCheck;
			*(ScriptClass**)&params[28] = InterfaceClass;
			*(Actor::TraceHitInfo*)&params[32] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Actor = *(class Actor**)&params[4];
			HitInfo = *(Actor::TraceHitInfo*)&params[32];
		}
		void VisibleCollidingExtentActors(ScriptClass* BaseClass, class Actor*& Actor, float Radius, Object::Vector Loc, Object::Vector AltLoc, bool bIgnoreHidden, Object::Vector Extent, bool bTraceActors, ScriptClass* InterfaceClass, Actor::TraceHitInfo& HitInfo, float XYCheckRadius)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.VisibleCollidingExtentActors");
			byte params[92] = { NULL };
			*(ScriptClass**)&params[0] = BaseClass;
			*(class Actor**)&params[4] = Actor;
			*(float*)&params[8] = Radius;
			*(Object::Vector*)&params[12] = Loc;
			*(Object::Vector*)&params[24] = AltLoc;
			*(bool*)&params[36] = bIgnoreHidden;
			*(Object::Vector*)&params[40] = Extent;
			*(bool*)&params[52] = bTraceActors;
			*(ScriptClass**)&params[56] = InterfaceClass;
			*(Actor::TraceHitInfo*)&params[60] = HitInfo;
			*(float*)&params[88] = XYCheckRadius;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Actor = *(class Actor**)&params[4];
			HitInfo = *(Actor::TraceHitInfo*)&params[60];
		}
		void OverlappingActors(ScriptClass* BaseClass, class Actor*& out_Actor, float Radius, Object::Vector Loc, bool bIgnoreHidden)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.OverlappingActors");
			byte params[28] = { NULL };
			*(ScriptClass**)&params[0] = BaseClass;
			*(class Actor**)&params[4] = out_Actor;
			*(float*)&params[8] = Radius;
			*(Object::Vector*)&params[12] = Loc;
			*(bool*)&params[24] = bIgnoreHidden;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Actor = *(class Actor**)&params[4];
		}
		void ComponentList(ScriptClass* BaseClass, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*& out_Component)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.ComponentList");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = BaseClass;
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.AllOwnedComponents");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = BaseClass;
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.LocalPlayerControllers");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = BaseClass;
			*(class PlayerController**)&params[4] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PC = *(class PlayerController**)&params[4];
		}
		class PlayerController* GetALocalPlayerController()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetALocalPlayerController");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PlayerController**)&params[0];
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BroadcastLocalizedMessage(ScriptClass* InMessageClass, int Switch, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.BroadcastLocalizedMessage");
			byte params[20] = { NULL };
			*(ScriptClass**)&params[0] = InMessageClass;
			*(int*)&params[4] = Switch;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_2;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BroadcastLocalizedTeamMessage(int TeamIndex, ScriptClass* InMessageClass, int Switch, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.BroadcastLocalizedTeamMessage");
			byte params[24] = { NULL };
			*(int*)&params[0] = TeamIndex;
			*(ScriptClass**)&params[4] = InMessageClass;
			*(int*)&params[8] = Switch;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[16] = RelatedPRI_2;
			*(class Object**)&params[20] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetInitialState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetInitialState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ConstraintBrokenNotify(class Actor* ConOwner, class RB_ConstraintSetup* ConSetup, class RB_ConstraintInstance* ConInstance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.ConstraintBrokenNotify");
			byte params[12] = { NULL };
			*(class Actor**)&params[0] = ConOwner;
			*(class RB_ConstraintSetup**)&params[4] = ConSetup;
			*(class RB_ConstraintInstance**)&params[8] = ConInstance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifySkelControlBeyondLimit(class SkelControlLookAt* LookAt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.NotifySkelControlBeyondLimit");
			byte params[4] = { NULL };
			*(class SkelControlLookAt**)&params[0] = LookAt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool StopsProjectile(class Projectile* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.StopsProjectile");
			byte params[8] = { NULL };
			*(class Projectile**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool HurtRadius(float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Object::Vector HurtOrigin, class Actor* IgnoredActor, class Controller* InstigatedByController, bool bDoFullDamage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.HurtRadius");
			byte params[44] = { NULL };
			*(float*)&params[0] = BaseDamage;
			*(float*)&params[4] = DamageRadius;
			*(ScriptClass**)&params[8] = DamageType;
			*(float*)&params[12] = Momentum;
			*(Object::Vector*)&params[16] = HurtOrigin;
			*(class Actor**)&params[28] = IgnoredActor;
			*(class Controller**)&params[32] = InstigatedByController;
			*(bool*)&params[36] = bDoFullDamage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[40];
		}
		void KilledBy(class Pawn* EventInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.KilledBy");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Object::Vector HitLocation, Object::Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.TakeDamage");
			byte params[68] = { NULL };
			*(int*)&params[0] = DamageAmount;
			*(class Controller**)&params[4] = EventInstigator;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool HealDamage(int Amount, class Controller* Healer, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.HealDamage");
			byte params[16] = { NULL };
			*(int*)&params[0] = Amount;
			*(class Controller**)&params[4] = Healer;
			*(ScriptClass**)&params[8] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void TakeRadiusDamage(class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Object::Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.TakeRadiusDamage");
			byte params[44] = { NULL };
			*(class Controller**)&params[0] = InstigatedBy;
			*(float*)&params[4] = BaseDamage;
			*(float*)&params[8] = DamageRadius;
			*(ScriptClass**)&params[12] = DamageType;
			*(float*)&params[16] = Momentum;
			*(Object::Vector*)&params[20] = HurtOrigin;
			*(bool*)&params[32] = bFullDamage;
			*(class Actor**)&params[36] = DamageCauser;
			*(float*)&params[40] = DamageFalloffExponent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckHitInfo(Actor::TraceHitInfo& HitInfo, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* FallBackComponent, Object::Vector Dir, Object::Vector& out_HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.CheckHitInfo");
			byte params[56] = { NULL };
			*(Actor::TraceHitInfo*)&params[0] = HitInfo;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[28] = FallBackComponent;
			*(Object::Vector*)&params[32] = Dir;
			*(Object::Vector*)&params[44] = out_HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			HitInfo = *(Actor::TraceHitInfo*)&params[0];
			out_HitLocation = *(Object::Vector*)&params[44];
		}
		float GetGravityZ()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetGravityZ");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void DebugFreezeGame(class Actor* ActorToLookAt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.DebugFreezeGame");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = ActorToLookAt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckForErrors()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.CheckForErrors");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void BecomeViewTarget(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.BecomeViewTarget");
			byte params[4] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndViewTarget(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.EndViewTarget");
			byte params[4] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CalcCamera(float fDeltaTime, Object::Vector& out_CamLoc, Object::Rotator& out_CamRot, float& out_FOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.CalcCamera");
			byte params[36] = { NULL };
			*(float*)&params[0] = fDeltaTime;
			*(Object::Vector*)&params[4] = out_CamLoc;
			*(Object::Rotator*)&params[16] = out_CamRot;
			*(float*)&params[28] = out_FOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_CamLoc = *(Object::Vector*)&params[4];
			out_CamRot = *(Object::Rotator*)&params[16];
			out_FOV = *(float*)&params[28];
			return *(bool*)&params[32];
		}
		ScriptString* GetItemName(ScriptString* FullName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetItemName");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = FullName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		ScriptString* GetHumanReadableName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetHumanReadableName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void ReplaceText(ScriptString*& Text, ScriptString* Replace, ScriptString* With)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.ReplaceText");
			byte params[36] = { NULL };
			*(ScriptString**)&params[0] = Text;
			*(ScriptString**)&params[12] = Replace;
			*(ScriptString**)&params[24] = With;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Text = *(ScriptString**)&params[0];
		}
		ScriptString* GetLocalString(int Switch, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetLocalString");
			byte params[24] = { NULL };
			*(int*)&params[0] = Switch;
			*(class PlayerReplicationInfo**)&params[4] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		void MatchStarting()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.MatchStarting");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetDebugName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetDebugName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.DisplayDebug");
			byte params[12] = { NULL };
			*(class HUD**)&params[0] = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		ScriptString* GetPhysicsName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetPhysicsName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void ModifyHearSoundComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.ModifyHearSoundComponent");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = AC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* GetFaceFXAudioComponent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetFaceFXAudioComponent");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0];
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsInPain()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.IsInPain");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void PlayTeleportEffect(bool bOut, bool bSound)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.PlayTeleportEffect");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bOut;
			*(bool*)&params[4] = bSound;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanSplash()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.CanSplash");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ApplyFluidSurfaceImpact(class FluidSurfaceActor* Fluid, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.ApplyFluidSurfaceImpact");
			byte params[16] = { NULL };
			*(class FluidSurfaceActor**)&params[0] = Fluid;
			*(Object::Vector*)&params[4] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool EffectIsRelevant(Object::Vector SpawnLocation, bool bForceDedicated, float VisibleCullDistance, float HiddenCullDistance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.EffectIsRelevant");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = SpawnLocation;
			*(bool*)&params[12] = bForceDedicated;
			*(float*)&params[16] = VisibleCullDistance;
			*(float*)&params[20] = HiddenCullDistance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void DebugMessagePlayer(ScriptString* msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.DebugMessagePlayer");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool TriggerEventClass(ScriptClass* InEventClass, class Actor* InInstigator, int ActivateIndex, bool bTest, ScriptArray<class SequenceEvent*>& ActivatedEvents)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.TriggerEventClass");
			byte params[32] = { NULL };
			*(ScriptClass**)&params[0] = InEventClass;
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.ActivateEventClass");
			byte params[52] = { NULL };
			*(ScriptClass**)&params[0] = InClass;
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.ReceivedNewEvent");
			byte params[4] = { NULL };
			*(class SequenceEvent**)&params[0] = Evt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool TriggerGlobalEventClass(ScriptClass* InEventClass, class Actor* InInstigator, int ActivateIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.TriggerGlobalEventClass");
			byte params[16] = { NULL };
			*(ScriptClass**)&params[0] = InEventClass;
			*(class Actor**)&params[4] = InInstigator;
			*(int*)&params[8] = ActivateIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool FindEventsOfClass(ScriptClass* EventClass, ScriptArray<class SequenceEvent*>& out_EventList, bool bIncludeDisabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.FindEventsOfClass");
			byte params[24] = { NULL };
			*(ScriptClass**)&params[0] = EventClass;
			*(ScriptArray<class SequenceEvent*>*)&params[4] = out_EventList;
			*(bool*)&params[16] = bIncludeDisabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_EventList = *(ScriptArray<class SequenceEvent*>*)&params[4];
			return *(bool*)&params[20];
		}
		void ClearLatentAction(ScriptClass* actionClass, bool bAborted, class SeqAct_Latent* exceptionAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.ClearLatentAction");
			byte params[12] = { NULL };
			*(ScriptClass**)&params[0] = actionClass;
			*(bool*)&params[4] = bAborted;
			*(class SeqAct_Latent**)&params[8] = exceptionAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnDestroy(class SeqAct_Destroy* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.OnDestroy");
			byte params[4] = { NULL };
			*(class SeqAct_Destroy**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ForceNetRelevant()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.ForceNetRelevant");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetNetUpdateTime(float NewUpdateTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetNetUpdateTime");
			byte params[4] = { NULL };
			*(float*)&params[0] = NewUpdateTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.ShutDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PrestreamTextures(float Seconds, bool bEnableStreaming, int CinematicTextureGroups)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.PrestreamTextures");
			byte params[12] = { NULL };
			*(float*)&params[0] = Seconds;
			*(bool*)&params[4] = bEnableStreaming;
			*(int*)&params[8] = CinematicTextureGroups;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnModifyHealth(class SeqAct_ModifyHealth* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.OnModifyHealth");
			byte params[4] = { NULL };
			*(class SeqAct_ModifyHealth**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnTeleport(class SeqAct_Teleport* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.OnTeleport");
			byte params[4] = { NULL };
			*(class SeqAct_Teleport**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSetVelocity(class SeqAct_SetVelocity* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.OnSetVelocity");
			byte params[4] = { NULL };
			*(class SeqAct_SetVelocity**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSetBlockRigidBody(class SeqAct_SetBlockRigidBody* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.OnSetBlockRigidBody");
			byte params[4] = { NULL };
			*(class SeqAct_SetBlockRigidBody**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSetPhysics(class SeqAct_SetPhysics* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.OnSetPhysics");
			byte params[4] = { NULL };
			*(class SeqAct_SetPhysics**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnChangeCollision(class SeqAct_ChangeCollision* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.OnChangeCollision");
			byte params[4] = { NULL };
			*(class SeqAct_ChangeCollision**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnToggleHidden(class SeqAct_ToggleHidden* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.OnToggleHidden");
			byte params[4] = { NULL };
			*(class SeqAct_ToggleHidden**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAttachToActor(class SeqAct_AttachToActor* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.OnAttachToActor");
			byte params[4] = { NULL };
			*(class SeqAct_AttachToActor**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DoKismetAttachment(class Actor* Attachment, class SeqAct_AttachToActor* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.DoKismetAttachment");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Attachment;
			*(class SeqAct_AttachToActor**)&params[4] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAnimEnd(class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.OnAnimEnd");
			byte params[12] = { NULL };
			*(class AnimNodeSequence**)&params[0] = SeqNode;
			*(float*)&params[4] = PlayedTime;
			*(float*)&params[8] = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAnimPlay(class AnimNodeSequence* SeqNode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.OnAnimPlay");
			byte params[4] = { NULL };
			*(class AnimNodeSequence**)&params[0] = SeqNode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BeginAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.BeginAnimControl");
			byte params[4] = { NULL };
			*(class InterpGroup**)&params[0] = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAnimPosition(ScriptName SlotName, int ChannelIndex, ScriptName InAnimSeqName, float InPosition, bool bFireNotifies, bool bLooping, bool bEnableRootMotion)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetAnimPosition");
			byte params[36] = { NULL };
			*(ScriptName*)&params[0] = SlotName;
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.FinishAnimControl");
			byte params[4] = { NULL };
			*(class InterpGroup**)&params[0] = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool PlayActorFaceFXAnim(class FaceFXAnimSet* AnimSet, ScriptString* GroupName, ScriptString* SeqName, class SoundCue* SoundCueToPlay)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.PlayActorFaceFXAnim");
			byte params[36] = { NULL };
			*(class FaceFXAnimSet**)&params[0] = AnimSet;
			*(ScriptString**)&params[4] = GroupName;
			*(ScriptString**)&params[16] = SeqName;
			*(class SoundCue**)&params[28] = SoundCueToPlay;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[32];
		}
		void StopActorFaceFXAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.StopActorFaceFXAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMorphWeight(ScriptName MorphNodeName, float MorphWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetMorphWeight");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = MorphNodeName;
			*(float*)&params[8] = MorphWeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSkelControlScale(ScriptName SkelControlName, float Scale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetSkelControlScale");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SkelControlName;
			*(float*)&params[8] = Scale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsActorPlayingFaceFXAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.IsActorPlayingFaceFXAnim");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool CanActorPlayFaceFXAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.CanActorPlayFaceFXAnim");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		class FaceFXAsset* GetActorFaceFXAsset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetActorFaceFXAsset");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class FaceFXAsset**)&params[0];
		}
		bool IsStationary()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.IsStationary");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void GetActorEyesViewPoint(Object::Vector& out_Location, Object::Rotator& out_Rotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetActorEyesViewPoint");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = out_Location;
			*(Object::Rotator*)&params[12] = out_Rotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Location = *(Object::Vector*)&params[0];
			out_Rotation = *(Object::Rotator*)&params[12];
		}
		bool IsPlayerOwned()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.IsPlayerOwned");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void PawnBaseDied()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.PawnBaseDied");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		byte GetTeamNum()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetTeamNum");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[0];
		}
		byte ScriptGetTeamNum()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.ScriptGetTeamNum");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[0];
		}
		void NotifyLocalPlayerTeamReceived()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.NotifyLocalPlayerTeamReceived");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FindGoodEndView(class PlayerController* PC, Object::Rotator& GoodRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.FindGoodEndView");
			byte params[16] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(Object::Rotator*)&params[4] = GoodRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			GoodRotation = *(Object::Rotator*)&params[4];
		}
		Object::Vector GetTargetLocation(class Actor* RequestedBy, bool bRequestAlternateLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetTargetLocation");
			byte params[20] = { NULL };
			*(class Actor**)&params[0] = RequestedBy;
			*(bool*)&params[4] = bRequestAlternateLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[8];
		}
		void SpawnedByKismet()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SpawnedByKismet");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InterpolationStarted(class SeqAct_Interp* InterpAction, class InterpGroupInst* GroupInst)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.InterpolationStarted");
			byte params[8] = { NULL };
			*(class SeqAct_Interp**)&params[0] = InterpAction;
			*(class InterpGroupInst**)&params[4] = GroupInst;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InterpolationFinished(class SeqAct_Interp* InterpAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.InterpolationFinished");
			byte params[4] = { NULL };
			*(class SeqAct_Interp**)&params[0] = InterpAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InterpolationChanged(class SeqAct_Interp* InterpAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.InterpolationChanged");
			byte params[4] = { NULL };
			*(class SeqAct_Interp**)&params[0] = InterpAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RigidBodyCollision(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* HitComponent, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComponent, Actor::CollisionImpactData& RigidCollisionData, int ContactIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.RigidBodyCollision");
			byte params[48] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = HitComponent;
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.OnRanOver");
			byte params[12] = { NULL };
			*(class SVehicle**)&params[0] = Vehicle;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = RunOverComponent;
			*(int*)&params[8] = WheelIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetHUDLocation(Object::Vector NewHUDLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SetHUDLocation");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = NewHUDLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NativePostRenderFor(class PlayerController* PC, class Canvas* Canvas, Object::Vector CameraPosition, Object::Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.NativePostRenderFor");
			byte params[32] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Object::Vector*)&params[8] = CameraPosition;
			*(Object::Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Object::Vector CameraPosition, Object::Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.PostRenderFor");
			byte params[32] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(class Canvas**)&params[4] = Canvas;
			*(Object::Vector*)&params[8] = CameraPosition;
			*(Object::Vector*)&params[20] = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RootMotionModeChanged(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.RootMotionModeChanged");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RootMotionExtracted(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp, Object::BoneAtom& ExtractedRootMotionDelta)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.RootMotionExtracted");
			byte params[36] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = SkelComp;
			*(Object::BoneAtom*)&params[16] = ExtractedRootMotionDelta;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ExtractedRootMotionDelta = *(Object::BoneAtom*)&params[16];
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.PostInitAnimTree");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Guid GetPackageGuid(ScriptName PackageName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetPackageGuid");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = PackageName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Guid*)&params[8];
		}
		void OnRigidBodySpringOverextension(class RB_BodyInstance* BodyInstance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.OnRigidBodySpringOverextension");
			byte params[4] = { NULL };
			*(class RB_BodyInstance**)&params[0] = BodyInstance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsInPersistentLevel(bool bIncludeLevelStreamingPersistent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.IsInPersistentLevel");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bIncludeLevelStreamingPersistent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void GetAimFrictionExtent(float& Width, float& Height, Object::Vector& Center)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetAimFrictionExtent");
			byte params[20] = { NULL };
			*(float*)&params[0] = Width;
			*(float*)&params[4] = Height;
			*(Object::Vector*)&params[8] = Center;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Width = *(float*)&params[0];
			Height = *(float*)&params[4];
			Center = *(Object::Vector*)&params[8];
		}
		void GetAimAdhesionExtent(float& Width, float& Height, Object::Vector& Center)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetAimAdhesionExtent");
			byte params[20] = { NULL };
			*(float*)&params[0] = Width;
			*(float*)&params[4] = Height;
			*(Object::Vector*)&params[8] = Center;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Width = *(float*)&params[0];
			Height = *(float*)&params[4];
			Center = *(Object::Vector*)&params[8];
		}
		bool PlayParticleEffect(class AnimNotify_PlayParticleEffect* AnimNotifyData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.PlayParticleEffect");
			byte params[8] = { NULL };
			*(class AnimNotify_PlayParticleEffect**)&params[0] = AnimNotifyData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CreateForceField(class AnimNotify_ForceField* AnimNotifyData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.CreateForceField");
			byte params[8] = { NULL };
			*(class AnimNotify_ForceField**)&params[0] = AnimNotifyData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void TrailsNotify(class AnimNotify_Trails* AnimNotifyData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.TrailsNotify");
			byte params[4] = { NULL };
			*(class AnimNotify_Trails**)&params[0] = AnimNotifyData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TrailsNotifyTick(class AnimNotify_Trails* AnimNotifyData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.TrailsNotifyTick");
			byte params[4] = { NULL };
			*(class AnimNotify_Trails**)&params[0] = AnimNotifyData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TrailsNotifyEnd(class AnimNotify_Trails* AnimNotifyData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.TrailsNotifyEnd");
			byte params[4] = { NULL };
			*(class AnimNotify_Trails**)&params[0] = AnimNotifyData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SupportsKismetModification(class SequenceOp* AskingOp, ScriptString*& Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.SupportsKismetModification");
			byte params[20] = { NULL };
			*(class SequenceOp**)&params[0] = AskingOp;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Reason = *(ScriptString**)&params[4];
			return *(bool*)&params[16];
		}
		void AnimTreeUpdated(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelMesh)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.AnimTreeUpdated");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = SkelMesh;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostDemoRewind()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.PostDemoRewind");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicationEnded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.ReplicationEnded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Object::Vector GetAvoidanceVector(ScriptArray<class Actor*>& Obstacles, Object::Vector GoalLocation, float CollisionRadius, float MaxSpeed, int NumSamples, float VelocityStepRate, float MaxTimeTilOverlap)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetAvoidanceVector");
			byte params[56] = { NULL };
			*(ScriptArray<class Actor*>*)&params[0] = Obstacles;
			*(Object::Vector*)&params[12] = GoalLocation;
			*(float*)&params[24] = CollisionRadius;
			*(float*)&params[28] = MaxSpeed;
			*(int*)&params[32] = NumSamples;
			*(float*)&params[36] = VelocityStepRate;
			*(float*)&params[40] = MaxTimeTilOverlap;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Obstacles = *(ScriptArray<class Actor*>*)&params[0];
			return *(Object::Vector*)&params[44];
		}
		bool WillOverlap(Object::Vector PosA, Object::Vector VelA, Object::Vector PosB, Object::Vector VelB, float StepSize, float Radius, float& Time)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.WillOverlap");
			byte params[64] = { NULL };
			*(Object::Vector*)&params[0] = PosA;
			*(Object::Vector*)&params[12] = VelA;
			*(Object::Vector*)&params[24] = PosB;
			*(Object::Vector*)&params[36] = VelB;
			*(float*)&params[48] = StepSize;
			*(float*)&params[52] = Radius;
			*(float*)&params[56] = Time;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Time = *(float*)&params[56];
			return *(bool*)&params[60];
		}
		bool ShouldBeHiddenBySHOW_NavigationNodes()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.ShouldBeHiddenBySHOW_NavigationNodes");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		ScriptString* GetSpectatorName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetSpectatorName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		ScriptString* GetSpectatorDescription()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetSpectatorDescription");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void GetSpectatorHealthInfo(int& Health, int& MaxHealth)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Actor.GetSpectatorHealthInfo");
			byte params[8] = { NULL };
			*(int*)&params[0] = Health;
			*(int*)&params[4] = MaxHealth;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Health = *(int*)&params[0];
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
