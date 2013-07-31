#pragma once
#include "Core.Object.h"
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Engine.Weapon.h"
#include "Engine.InventoryManager.h"
#include "Engine.PhysicsVolume.h"
#include "Engine.SeqAct_AttachToActor.h"
#include "Engine.LadderVolume.h"
#include "Engine.SeqAct_PlayFaceFXAnim.h"
#include "Engine.AnimNodeSlot.h"
#include "Engine.NavigationPoint.h"
#include "Engine.SeqAct_SetMaterial.h"
#include "Engine.PlayerController.h"
#include "Engine.InterpGroup.h"
#include "Engine.SequenceEvent.h"
#include "Engine.EngineTypes.h"
#include "Engine.SeqAct_AssignController.h"
#include "Engine.Inventory.h"
#include "Engine.MaterialInstanceConstant.h"
#include "Engine.RB_BodyInstance.h"
#include "Engine.InterpGroupInst.h"
#include "Engine.PathGoalEvaluator.h"
#include "Engine.Vehicle.h"
#include "Engine.PlayerStart.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.PathConstraint.h"
#include "Engine.FaceFXAnimSet.h"
#include "Engine.SoundCue.h"
#include "Engine.AnimSet.h"
#include "Engine.SeqAct_Interp.h"
#include "Engine.FaceFXAsset.h"
#include "Engine.Pylon.h"
#include "Engine.HUD.h"
#include "Engine.SeqAct_GiveInventory.h"
#include "Engine.TeamInfo.h"
#include "Engine.SeqAct_Teleport.h"
#include "Engine.Canvas.h"
#include "Engine.SeqAct_SetVelocity.h"
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
	class Pawn : public Actor
	{
	public:
		enum EPathSearchType : byte
		{
			PST_Default = 0,
			PST_Breadth = 1,
			PST_NewBestPathTo = 2,
			PST_Constraint = 3,
			PST_MAX = 4,
		};
		struct ScalarParameterInterpStruct
		{
		public:
			ADD_STRUCT(float, WarmupTime, 16)
			ADD_STRUCT(float, InterpTime, 12)
			ADD_STRUCT(float, ParameterValue, 8)
			ADD_STRUCT(ScriptName, ParameterName, 0)
		};
		struct LastHitInfoStruct
		{
		public:
			ADD_OBJECT(ScriptClass, Type, 16)
			ADD_OBJECT(Actor, Causer, 12)
			ADD_STRUCT(float, Distance, 8)
			ADD_STRUCT(float, Amount, 4)
			ADD_BOOL(bDirectHit, 0, 0x1)
		};
		ADD_OBJECT(Controller, Controller, 508)
		ADD_STRUCT(int, MaxPitchLimit, 664)
		ADD_OBJECT(Weapon, Weapon, 984)
		ADD_OBJECT(InventoryManager, InvManager, 980)
		ADD_BOOL(bIsWalking, 528, 0x4)
		ADD_STRUCT(float, EyeHeight, 728)
		ADD_STRUCT(float, BaseEyeHeight, 724)
		ADD_STRUCT(int, Health, 752)
		ADD_BOOL(bForceRMVelocity, 532, 0x100000)
		ADD_STRUCT(Vector, Floor, 732)
		ADD_BOOL(bRootMotionFromInterpCurve, 532, 0x8000000)
		ADD_STRUCT(float, CrouchHeight, 548)
		ADD_BOOL(bIsCrouched, 528, 0x10)
		ADD_STRUCT(float, MaxStepHeight, 480)
		ADD_BOOL(bForceMaxAccel, 532, 0x20000)
		ADD_STRUCT(float, VehicleCheckRadius, 944)
		ADD_STRUCT(float, LastStartTime, 888)
		ADD_OBJECT(PhysicsVolume, HeadVolume, 748)
		ADD_STRUCT(float, BreathTime, 760)
		ADD_STRUCT(float, UnderWaterTime, 764)
		ADD_STRUCT(ScriptName, WaterMovementState, 876)
		ADD_STRUCT(ScriptName, LandMovementState, 868)
		ADD_STRUCT(float, AccelRate, 684)
		ADD_STRUCT(Actor::EPhysics, WalkingPhysics, 536)
		ADD_OBJECT(LadderVolume, OnLadder, 864)
		ADD_BOOL(bUpAndOut, 528, 0x2)
		ADD_STRUCT(float, OutofWaterZ, 692)
		ADD_OBJECT(NavigationPoint, Anchor, 612)
		ADD_STRUCT(ScriptArray<class AnimNodeSlot*>, SlotNodes, 1028)
		ADD_STRUCT(ScriptArray<class InterpGroup*>, InterpGroupList, 1040)
		ADD_STRUCT(ScriptArray<Pawn::ScalarParameterInterpStruct>, ScalarParameterInterpArray, 1064)
		ADD_STRUCT(Pawn::LastHitInfoStruct, LastHitInfo, 1124)
		ADD_STRUCT(Vector, RootMotionInterpCurveLastValue, 1112)
		ADD_STRUCT(float, RootMotionInterpCurrentTime, 1108)
		ADD_STRUCT(float, RootMotionInterpRate, 1104)
		ADD_STRUCT(EngineTypes::RootMotionCurve, RootMotionInterpCurve, 1076)
		ADD_OBJECT(MaterialInstanceConstant, MIC_PawnHair, 1060)
		ADD_OBJECT(MaterialInstanceConstant, MIC_PawnMat, 1056)
		ADD_STRUCT(int, FailedLandingCount, 1024)
		ADD_OBJECT(RB_BodyInstance, PhysicsPushBody, 1020)
		ADD_STRUCT(int, ShotCount, 1012)
		ADD_STRUCT(Vector, LastFiringFlashLocation, 1000)
		ADD_STRUCT(Vector, FlashLocation, 988)
		ADD_OBJECT(ScriptClass, InventoryManagerClass, 976)
		ADD_STRUCT(Rotator, DesiredRotation, 964)
		ADD_STRUCT(int, AllowedYawError, 960)
		ADD_STRUCT(float, ViewPitchMax, 956)
		ADD_STRUCT(float, ViewPitchMin, 952)
		ADD_OBJECT(Controller, LastHitBy, 948)
		ADD_STRUCT(float, AlwaysRelevantDistanceSquared, 940)
		ADD_OBJECT(Vehicle, DrivenVehicle, 936)
		ADD_STRUCT(float, RBPushStrength, 932)
		ADD_STRUCT(float, RBPushRadius, 928)
		ADD_STRUCT(Vector, TearOffMomentum, 908)
		ADD_OBJECT(ScriptClass, HitDamageType, 904)
		ADD_STRUCT(Vector, TakeHitLocation, 892)
		ADD_OBJECT(PlayerStart, LastStartSpot, 884)
		ADD_OBJECT(PlayerReplicationInfo, PlayerReplicationInfo, 860)
		ADD_OBJECT(ScriptClass, ControllerClass, 856)
		ADD_STRUCT(ScriptString*, MenuName, 844)
		ADD_STRUCT(float, DamageScaling, 840)
		ADD_STRUCT(float, SoundDampening, 836)
		ADD_STRUCT(float, noise2loudness, 832)
		ADD_OBJECT(Pawn, noise2other, 828)
		ADD_STRUCT(float, noise2time, 824)
		ADD_STRUCT(Vector, noise2spot, 812)
		ADD_STRUCT(float, noise1loudness, 808)
		ADD_OBJECT(Pawn, noise1other, 804)
		ADD_STRUCT(float, noise1time, 800)
		ADD_STRUCT(Vector, noise1spot, 788)
		ADD_STRUCT(Vector, RMVelocity, 776)
		ADD_STRUCT(float, KismetDeathDelayTime, 772)
		ADD_STRUCT(float, LastPainTime, 768)
		ADD_STRUCT(int, HealthMax, 756)
		ADD_STRUCT(float, SplashTime, 744)
		ADD_STRUCT(float, AIMaxFallSpeedFactor, 720)
		ADD_STRUCT(float, MaxFallSpeed, 716)
		ADD_STRUCT(float, CrouchedPct, 712)
		ADD_STRUCT(float, MovementSpeedModifier, 708)
		ADD_STRUCT(float, WalkingPct, 704)
		ADD_STRUCT(float, AirControl, 700)
		ADD_STRUCT(float, MaxOutOfWaterStepHeight, 696)
		ADD_STRUCT(float, JumpZ, 688)
		ADD_STRUCT(float, LadderSpeed, 680)
		ADD_STRUCT(float, AirSpeed, 676)
		ADD_STRUCT(float, WaterSpeed, 672)
		ADD_STRUCT(float, GroundSpeed, 668)
		ADD_STRUCT(float, SpawnTime, 660)
		ADD_STRUCT(float, SerpentineTime, 656)
		ADD_STRUCT(float, SerpentineDist, 652)
		ADD_STRUCT(Vector, SerpentineDir, 640)
		ADD_STRUCT(float, NextPathRadius, 636)
		ADD_STRUCT(float, DestinationOffset, 632)
		ADD_STRUCT(float, LastValidAnchorTime, 628)
		ADD_STRUCT(float, FindAnchorFailedTime, 624)
		ADD_OBJECT(NavigationPoint, LastAnchor, 620)
		ADD_STRUCT(int, AnchorItem, 616)
		ADD_STRUCT(float, MeleeRange, 608)
		ADD_STRUCT(float, Buoyancy, 604)
		ADD_STRUCT(float, Mass, 600)
		ADD_STRUCT(float, AvgPhysicsTime, 596)
		ADD_STRUCT(float, PeripheralVision, 592)
		ADD_STRUCT(float, SightRadius, 588)
		ADD_STRUCT(float, Alertness, 584)
		ADD_STRUCT(float, HearingThreshold, 580)
		ADD_STRUCT(float, MaxDesiredSpeed, 576)
		ADD_STRUCT(float, DesiredSpeed, 572)
		ADD_OBJECT(PathGoalEvaluator, PathGoalList, 568)
		ADD_OBJECT(PathConstraint, PathConstraintList, 564)
		ADD_STRUCT(float, NonPreferredVehiclePathMultiplier, 560)
		ADD_STRUCT(int, FullHeight, 556)
		ADD_STRUCT(float, CrouchRadius, 552)
		ADD_STRUCT(float, UncrouchTime, 544)
		ADD_STRUCT(byte, FiringMode, 540)
		ADD_STRUCT(byte, FlashCount, 539)
		ADD_STRUCT(byte, RemoteViewPitch, 538)
		ADD_STRUCT(Pawn::EPathSearchType, PathSearchType, 537)
		ADD_STRUCT(Object::Pointer, VfTable_IInterface_Speaker, 476)
		ADD_BOOL(bDebugShowCameraLocation, 532, 0x10000000)
		ADD_BOOL(bNeedsBaseTickedFirst, 532, 0x4000000)
		ADD_BOOL(bUnlockWhenReached, 532, 0x2000000)
		ADD_BOOL(bLockDesiredRotation, 532, 0x1000000)
		ADD_BOOL(bDesiredRotationSet, 532, 0x800000)
		ADD_BOOL(bPlayedDeath, 532, 0x400000)
		ADD_BOOL(bForceRegularVelocity, 532, 0x200000)
		ADD_BOOL(bReplicateHealthToAll, 532, 0x80000)
		ADD_BOOL(bLimitFallAccel, 532, 0x40000)
		ADD_BOOL(bRunPhysicsWithNoController, 532, 0x10000)
		ADD_BOOL(bPathfindsAsVehicle, 532, 0x8000)
		ADD_BOOL(bModifyNavPointDest, 532, 0x4000)
		ADD_BOOL(bModifyReachSpecCost, 532, 0x2000)
		ADD_BOOL(bNoWeaponFiring, 532, 0x1000)
		ADD_BOOL(bCachedRelevant, 532, 0x800)
		ADD_BOOL(bStationary, 532, 0x400)
		ADD_BOOL(bRollToDesired, 532, 0x200)
		ADD_BOOL(bDontPossess, 532, 0x100)
		ADD_BOOL(bMuffledHearing, 532, 0x80)
		ADD_BOOL(bLOSHearing, 532, 0x40)
		ADD_BOOL(bAmbientCreature, 532, 0x20)
		ADD_BOOL(bCanPickupInventory, 532, 0x10)
		ADD_BOOL(bDisplayPathErrors, 532, 0x8)
		ADD_BOOL(bCanCoverSlip, 532, 0x4)
		ADD_BOOL(bCanLeap, 532, 0x2)
		ADD_BOOL(bCanSwatTurn, 532, 0x1)
		ADD_BOOL(bCanClimbCeilings, 528, 0x80000000)
		ADD_BOOL(bCanClimbUp, 528, 0x40000000)
		ADD_BOOL(bCanMantle, 528, 0x20000000)
		ADD_BOOL(bForceKeepAnchor, 528, 0x10000000)
		ADD_BOOL(bForceFloorCheck, 528, 0x8000000)
		ADD_BOOL(bPushesRigidBodies, 528, 0x4000000)
		ADD_BOOL(bDirectHitWall, 528, 0x2000000)
		ADD_BOOL(bSimGravityDisabled, 528, 0x1000000)
		ADD_BOOL(bCanBeBaseForPawns, 528, 0x800000)
		ADD_BOOL(bCanWalkOffLedges, 528, 0x400000)
		ADD_BOOL(bIgnoreForces, 528, 0x200000)
		ADD_BOOL(bSimulateGravity, 528, 0x100000)
		ADD_BOOL(bPartiallyOverLedge, 528, 0x80000)
		ADD_BOOL(bAllowLedgeOverhang, 528, 0x40000)
		ADD_BOOL(bStopAtLedges, 528, 0x20000)
		ADD_BOOL(bAvoidLedges, 528, 0x10000)
		ADD_BOOL(bCanStrafe, 528, 0x8000)
		ADD_BOOL(bCanClimbLadders, 528, 0x4000)
		ADD_BOOL(bCanFly, 528, 0x2000)
		ADD_BOOL(bCanSwim, 528, 0x1000)
		ADD_BOOL(bCanWalk, 528, 0x800)
		ADD_BOOL(bCanJump, 528, 0x400)
		ADD_BOOL(bJumpCapable, 528, 0x200)
		ADD_BOOL(bReducedSpeed, 528, 0x100)
		ADD_BOOL(bCrawler, 528, 0x80)
		ADD_BOOL(bCanCrouch, 528, 0x40)
		ADD_BOOL(bTryToUncrouch, 528, 0x20)
		ADD_BOOL(bWantsToCrouch, 528, 0x8)
		ADD_BOOL(bScriptTickSpecial, 528, 0x1)
		ADD_OBJECT(Actor, LastViewer, 524)
		ADD_OBJECT(PlayerController, LastRealViewer, 520)
		ADD_STRUCT(float, NetRelevancyTime, 516)
		ADD_OBJECT(Pawn, NextPawn, 512)
		ADD_STRUCT(Vector, PartialLedgeMoveDir, 496)
		ADD_STRUCT(float, LedgeCheckThreshold, 492)
		ADD_STRUCT(float, WalkableFloorZ, 488)
		ADD_STRUCT(float, MaxJumpHeight, 484)
		bool IsHumanControlled(class Controller* PawnController)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4254);
			byte params[8] = { NULL };
			*(class Controller**)params = PawnController;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsLocallyControlled(class Controller* PawnController)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4256);
			byte params[8] = { NULL };
			*(class Controller**)params = PawnController;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool PlayActorFaceFXAnim(class FaceFXAnimSet* AnimSet, ScriptString* GroupName, ScriptString* SeqName, class SoundCue* SoundCueToPlay)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5980);
			byte params[36] = { NULL };
			*(class FaceFXAnimSet**)params = AnimSet;
			*(ScriptString**)&params[4] = GroupName;
			*(ScriptString**)&params[16] = SeqName;
			*(class SoundCue**)&params[28] = SoundCueToPlay;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[32];
		}
		bool StopFiring()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6070);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		Rotator GetBaseAimRotation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6080);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)params;
		}
		ScriptString* GetHumanReadableName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6256);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		bool Died(class Controller* Killer, ScriptClass* DamageType, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8006);
			byte params[24] = { NULL };
			*(class Controller**)params = Killer;
			*(ScriptClass**)&params[4] = DamageType;
			*(Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		ScriptName GetDefaultCameraMode(class PlayerController* RequestedBy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8056);
			byte params[12] = { NULL };
			*(class PlayerController**)params = RequestedBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[4];
		}
		bool CanThrowWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8316);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool SetDesiredRotation(Rotator TargetDesiredRotation, bool InLockDesiredRotation, bool InUnlockWhenReached, float InterpolationTime, bool bResetRotationRate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8509);
			byte params[32] = { NULL };
			*(Rotator*)params = TargetDesiredRotation;
			*(bool*)&params[12] = InLockDesiredRotation;
			*(bool*)&params[16] = InUnlockWhenReached;
			*(float*)&params[20] = InterpolationTime;
			*(bool*)&params[24] = bResetRotationRate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		bool DoJump(bool bUpdating)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8523);
			byte params[8] = { NULL };
			*(bool*)params = bUpdating;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void SetRemoteViewPitch(int NewRemoteViewPitch)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8543);
			byte params[4] = { NULL };
			*(int*)params = NewRemoteViewPitch;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CannotJumpNow()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8558);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool CheckWaterJump(Vector& WallNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8659);
			byte params[16] = { NULL };
			*(Vector*)params = WallNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			WallNormal = *(Vector*)params;
			return *(bool*)&params[12];
		}
		bool TouchingWaterVolume()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8662);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool ReachedDestination(class Actor* Goal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9726);
			byte params[8] = { NULL };
			*(class Actor**)params = Goal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SpecialMoveTo(class NavigationPoint* Start, class NavigationPoint* End, class Actor* Next)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9868);
			byte params[16] = { NULL };
			*(class NavigationPoint**)params = Start;
			*(class NavigationPoint**)&params[4] = End;
			*(class Actor**)&params[8] = Next;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void SetScalarParameterInterp(Pawn::ScalarParameterInterpStruct& ScalarParameterInterp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11399);
			byte params[20] = { NULL };
			*(Pawn::ScalarParameterInterpStruct*)params = ScalarParameterInterp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ScalarParameterInterp = *(Pawn::ScalarParameterInterpStruct*)params;
		}
		bool CheatFly()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12672);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool CheatWalk()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12675);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool CheatGhost()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12678);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsPlayerPawn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12697);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		class Inventory* FindInventoryType(ScriptClass* DesiredClass, bool bAllowSubclass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12716);
			byte params[12] = { NULL };
			*(ScriptClass**)params = DesiredClass;
			*(bool*)&params[4] = bAllowSubclass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Inventory**)&params[8];
		}
		class Inventory* CreateInventory(ScriptClass* NewInvClass, bool bDoNotActivate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12718);
			byte params[12] = { NULL };
			*(ScriptClass**)params = NewInvClass;
			*(bool*)&params[4] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Inventory**)&params[8];
		}
		bool InGodMode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17088);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool ValidAnchor()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18180);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		class NavigationPoint* GetBestAnchor(class Actor* TestActor, Vector TestLocation, bool bStartPoint, bool bOnlyCheckVisible, float& out_Dist)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18182);
			byte params[32] = { NULL };
			*(class Actor**)params = TestActor;
			*(Vector*)&params[4] = TestLocation;
			*(bool*)&params[16] = bStartPoint;
			*(bool*)&params[20] = bOnlyCheckVisible;
			*(float*)&params[24] = out_Dist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Dist = *(float*)&params[24];
			return *(class NavigationPoint**)&params[28];
		}
		class PathGoalEvaluator* CreatePathGoalEvaluator(ScriptClass* GoalEvalClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18184);
			byte params[8] = { NULL };
			*(ScriptClass**)params = GoalEvalClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PathGoalEvaluator**)&params[4];
		}
		float GetCollisionHeight()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18391);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		Vector GetCollisionExtent()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18393);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		Rotator GetViewRotation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18874);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)params;
		}
		bool CanGrabLadder()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19149);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool LineOfSightTo(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19425);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool PickWallAdjust(Vector WallHitNormal, class Actor* HitActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19944);
			byte params[20] = { NULL };
			*(Vector*)params = WallHitNormal;
			*(class Actor**)&params[12] = HitActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void LockDesiredRotation(bool Lock, bool InUnlockWhenReached)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19953);
			byte params[8] = { NULL };
			*(bool*)params = Lock;
			*(bool*)&params[4] = InUnlockWhenReached;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetDesiredRotation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19956);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckDesiredRotation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19957);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsDesiredRotationInUse()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19958);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsDesiredRotationLocked()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19960);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19962);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CacheAnimNodes()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19964);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearAnimNodes()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19965);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateAnimSetList()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19966);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BuildScriptAnimSetList()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19967);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddAnimSets(ScriptArray<class AnimSet*>& CustomAnimSets)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19968);
			byte params[12] = { NULL };
			*(ScriptArray<class AnimSet*>*)params = CustomAnimSets;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CustomAnimSets = *(ScriptArray<class AnimSet*>*)params;
		}
		void AnimSetListUpdated()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19971);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool RestoreAnimSetsToDefault()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19972);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void BeginAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19974);
			byte params[4] = { NULL };
			*(class InterpGroup**)params = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MAT_BeginAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19976);
			byte params[4] = { NULL };
			*(class InterpGroup**)params = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FinishAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19978);
			byte params[4] = { NULL };
			*(class InterpGroup**)params = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MAT_FinishAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19980);
			byte params[4] = { NULL };
			*(class InterpGroup**)params = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAnimPosition(ScriptName SlotName, int ChannelIndex, ScriptName InAnimSeqName, float InPosition, bool bFireNotifies, bool bLooping, bool bEnableRootMotion)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19982);
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
		void MAT_SetAnimPosition(ScriptName SlotName, int ChannelIndex, ScriptName InAnimSeqName, float InPosition, bool bFireNotifies, bool bLooping, bool bEnableRootMotion)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19990);
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
		void MAT_SetAnimWeights(ScriptArray<Actor::AnimSlotInfo> SlotInfos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19998);
			byte params[12] = { NULL };
			*(ScriptArray<Actor::AnimSlotInfo>*)params = SlotInfos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MAT_SetMorphWeight(ScriptName MorphNodeName, float MorphWeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20001);
			byte params[12] = { NULL };
			*(ScriptName*)params = MorphNodeName;
			*(float*)&params[8] = MorphWeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MAT_SetSkelControlScale(ScriptName SkelControlName, float Scale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20004);
			byte params[12] = { NULL };
			*(ScriptName*)params = SkelControlName;
			*(float*)&params[8] = Scale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InterpolationStarted(class SeqAct_Interp* InterpAction, class InterpGroupInst* GroupInst)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20007);
			byte params[8] = { NULL };
			*(class SeqAct_Interp**)params = InterpAction;
			*(class InterpGroupInst**)&params[4] = GroupInst;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InterpolationFinished(class SeqAct_Interp* InterpAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20010);
			byte params[4] = { NULL };
			*(class SeqAct_Interp**)params = InterpAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MAT_BeginAIGroup(Vector StartLoc, Rotator StartRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20012);
			byte params[24] = { NULL };
			*(Vector*)params = StartLoc;
			*(Rotator*)&params[12] = StartRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MAT_FinishAIGroup()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20015);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopActorFaceFXAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20020);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* GetFaceFXAudioComponent()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20021);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params;
		}
		bool IsActorPlayingFaceFXAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20023);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool CanActorPlayFaceFXAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20025);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void OnPlayFaceFXAnim(class SeqAct_PlayFaceFXAnim* inAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20027);
			byte params[4] = { NULL };
			*(class SeqAct_PlayFaceFXAnim**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FaceFXAudioFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20033);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = AC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class FaceFXAsset* GetActorFaceFXAsset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20035);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class FaceFXAsset**)params;
		}
		void SetMorphWeight(ScriptName MorphNodeName, float MorphWeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20038);
			byte params[12] = { NULL };
			*(ScriptName*)params = MorphNodeName;
			*(float*)&params[8] = MorphWeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSkelControlScale(ScriptName SkelControlName, float Scale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20041);
			byte params[12] = { NULL };
			*(ScriptName*)params = SkelControlName;
			*(float*)&params[8] = Scale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20044);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsAliveAndWell()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20046);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		Vector AdjustDestination(class Actor* GoalActor, Vector Dest)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20048);
			byte params[28] = { NULL };
			*(class Actor**)params = GoalActor;
			*(Vector*)&params[4] = Dest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[16];
		}
		bool SuggestJumpVelocity(Vector& JumpVelocity, Vector Destination, Vector Start, bool bRequireFallLanding)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20052);
			byte params[44] = { NULL };
			*(Vector*)params = JumpVelocity;
			*(Vector*)&params[12] = Destination;
			*(Vector*)&params[24] = Start;
			*(bool*)&params[36] = bRequireFallLanding;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			JumpVelocity = *(Vector*)params;
			return *(bool*)&params[40];
		}
		float GetFallDuration()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20058);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		bool IsValidEnemyTargetFor(class PlayerReplicationInfo* PRI, bool bNoPRIisEnemy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20060);
			byte params[12] = { NULL };
			*(class PlayerReplicationInfo**)params = PRI;
			*(bool*)&params[4] = bNoPRIisEnemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool IsInvisible()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20064);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SetAnchor(class NavigationPoint* NewAnchor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20067);
			byte params[4] = { NULL };
			*(class NavigationPoint**)params = NewAnchor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ReachedPoint(Vector Point, class Actor* NewAnchor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20075);
			byte params[20] = { NULL };
			*(Vector*)params = Point;
			*(class Actor**)&params[12] = NewAnchor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void ForceCrouch()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20079);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPushesRigidBodies(bool NewPush)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20080);
			byte params[4] = { NULL };
			*(bool*)params = NewPush;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ReachedDesiredRotation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20082);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void GetBoundingCylinder(float& CollisionRadius, float& CollisionHeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20084);
			byte params[8] = { NULL };
			*(float*)params = CollisionRadius;
			*(float*)&params[4] = CollisionHeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CollisionRadius = *(float*)params;
			CollisionHeight = *(float*)&params[4];
		}
		bool InitRagdoll()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20087);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool TermRagdoll()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20089);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool SpecialMoveThruEdge(Pylon::ENavMeshEdgeType Type, int Dir, Vector MoveStart, Vector MoveDest, class Actor* RelActor, int RelItem)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20094);
			byte params[41] = { NULL };
			*(Pylon::ENavMeshEdgeType*)params = Type;
			*(int*)&params[4] = Dir;
			*(Vector*)&params[8] = MoveStart;
			*(Vector*)&params[20] = MoveDest;
			*(class Actor**)&params[32] = RelActor;
			*(int*)&params[36] = RelItem;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[40];
		}
		void SetBaseEyeheight()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20102);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayerChangedTeam()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20103);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20104);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20106);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20108);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		byte GetWeaponFiringMode(class Weapon* InWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20110);
			byte params[5] = { NULL };
			*(class Weapon**)params = InWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[4];
		}
		void SetFiringMode(class Weapon* InWeapon, byte InFiringMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20113);
			byte params[5] = { NULL };
			*(class Weapon**)params = InWeapon;
			params[4] = InFiringMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FiringModeUpdated(class Weapon* InWeapon, byte InFiringMode, bool bViaReplication)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20116);
			byte params[9] = { NULL };
			*(class Weapon**)params = InWeapon;
			params[4] = InFiringMode;
			*(bool*)&params[8] = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void IncrementFlashCount(class Weapon* InWeapon, byte InFiringMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20120);
			byte params[5] = { NULL };
			*(class Weapon**)params = InWeapon;
			params[4] = InFiringMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FlashCountUpdated(class Weapon* InWeapon, byte InFlashCount, bool bViaReplication)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20123);
			byte params[9] = { NULL };
			*(class Weapon**)params = InWeapon;
			params[4] = InFlashCount;
			*(bool*)&params[8] = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFlashCount(class Weapon* InWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20127);
			byte params[4] = { NULL };
			*(class Weapon**)params = InWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFlashLocation(class Weapon* InWeapon, byte InFiringMode, Vector NewLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20129);
			byte params[17] = { NULL };
			*(class Weapon**)params = InWeapon;
			params[4] = InFiringMode;
			*(Vector*)&params[8] = NewLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFlashLocation(class Weapon* InWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20133);
			byte params[4] = { NULL };
			*(class Weapon**)params = InWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FlashLocationUpdated(class Weapon* InWeapon, Vector InFlashLocation, bool bViaReplication)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20135);
			byte params[20] = { NULL };
			*(class Weapon**)params = InWeapon;
			*(Vector*)&params[4] = InFlashLocation;
			*(bool*)&params[16] = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WeaponFired(class Weapon* InWeapon, bool bViaReplication, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20139);
			byte params[20] = { NULL };
			*(class Weapon**)params = InWeapon;
			*(bool*)&params[4] = bViaReplication;
			*(Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WeaponStoppedFiring(class Weapon* InWeapon, bool bViaReplication)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20143);
			byte params[8] = { NULL };
			*(class Weapon**)params = InWeapon;
			*(bool*)&params[4] = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool BotFire(bool bFinished)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20146);
			byte params[8] = { NULL };
			*(bool*)params = bFinished;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CanAttack(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20149);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool TooCloseToAttack(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20154);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool FireOnRelease()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20157);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool HasRangedAttack()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20161);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsFiring()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20163);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool NeedToTurn(Vector targ)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20167);
			byte params[16] = { NULL };
			*(Vector*)params = targ;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void PlayTeleportEffect(bool bOut, bool bSound)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20172);
			byte params[8] = { NULL };
			*(bool*)params = bOut;
			*(bool*)&params[4] = bSound;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyTeamChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20175);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PossessedBy(class Controller* C, bool bVehicleTransition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20176);
			byte params[8] = { NULL };
			*(class Controller**)params = C;
			*(bool*)&params[4] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateControllerOnPossess(bool bVehicleTransition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20179);
			byte params[4] = { NULL };
			*(bool*)params = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnPossessed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20181);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DropToGround()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20183);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool RecommendLongRangedAttack()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20184);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		float RangedAttackTime()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20186);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void SetWalking(bool bNewIsWalking)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20188);
			byte params[4] = { NULL };
			*(bool*)params = bNewIsWalking;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanSplash()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20190);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void EndClimbLadder(class LadderVolume* OldLadder)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20192);
			byte params[4] = { NULL };
			*(class LadderVolume**)params = OldLadder;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClimbLadder(class LadderVolume* L)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20194);
			byte params[4] = { NULL };
			*(class LadderVolume**)params = L;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20196);
			byte params[12] = { NULL };
			*(class HUD**)params = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		bool IsFirstPerson()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20206);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ProcessViewRotation(float DeltaTime, Rotator& out_ViewRotation, Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20209);
			byte params[28] = { NULL };
			*(float*)params = DeltaTime;
			*(Rotator*)&params[4] = out_ViewRotation;
			*(Rotator*)&params[16] = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ViewRotation = *(Rotator*)&params[4];
			out_DeltaRot = *(Rotator*)&params[16];
		}
		void GetActorEyesViewPoint(Vector& out_Location, Rotator& out_Rotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20213);
			byte params[24] = { NULL };
			*(Vector*)params = out_Location;
			*(Rotator*)&params[12] = out_Rotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Location = *(Vector*)params;
			out_Rotation = *(Rotator*)&params[12];
		}
		Vector GetPawnViewLocation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20216);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		Vector GetWeaponStartTraceLocation(class Weapon* CurrentWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20218);
			byte params[16] = { NULL };
			*(class Weapon**)params = CurrentWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[4];
		}
		bool InFreeCam()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20225);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		Rotator GetAdjustedAimFor(class Weapon* W, Vector StartFireLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20228);
			byte params[28] = { NULL };
			*(class Weapon**)params = W;
			*(Vector*)&params[4] = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[16];
		}
		void SetViewRotation(Rotator NewRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20232);
			byte params[12] = { NULL };
			*(Rotator*)params = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMoveTarget(class Actor* NewTarget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20234);
			byte params[4] = { NULL };
			*(class Actor**)params = NewTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HandlePickup(class Inventory* Inv)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20237);
			byte params[4] = { NULL };
			*(class Inventory**)params = Inv;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientMessage(ScriptString* S, ScriptName Type)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20239);
			byte params[20] = { NULL };
			*(ScriptString**)params = S;
			*(ScriptName*)&params[12] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20242);
			byte params[4] = { NULL };
			*(ScriptClass**)params = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OutsideWorldBounds()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20244);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UnCrouch()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20245);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShouldCrouch(bool bCrouch)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20246);
			byte params[4] = { NULL };
			*(bool*)params = bCrouch;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndCrouch(float HeightAdjust)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20248);
			byte params[4] = { NULL };
			*(float*)params = HeightAdjust;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartCrouch(float HeightAdjust)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20250);
			byte params[4] = { NULL };
			*(float*)params = HeightAdjust;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HandleMomentum(Vector Momentum, Vector HitLocation, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20252);
			byte params[56] = { NULL };
			*(Vector*)params = Momentum;
			*(Vector*)&params[12] = HitLocation;
			*(ScriptClass**)&params[24] = DamageType;
			*(Actor::TraceHitInfo*)&params[28] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddVelocity(Vector NewVelocity, Vector HitLocation, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20257);
			byte params[56] = { NULL };
			*(Vector*)params = NewVelocity;
			*(Vector*)&params[12] = HitLocation;
			*(ScriptClass**)&params[24] = DamageType;
			*(Actor::TraceHitInfo*)&params[28] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KilledBy(class Pawn* EventInstigator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20262);
			byte params[4] = { NULL };
			*(class Pawn**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeFallingDamage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20265);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Restart()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20267);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientRestart()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20268);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientSetRotation(Rotator NewRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20269);
			byte params[12] = { NULL };
			*(Rotator*)params = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdatePawnRotation(Rotator NewRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20271);
			byte params[12] = { NULL };
			*(Rotator*)params = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FaceRotation(Rotator NewRotation, float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20273);
			byte params[16] = { NULL };
			*(Rotator*)params = NewRotation;
			*(float*)&params[12] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool EncroachingOn(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20276);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void EncroachedBy(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20279);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void gibbedBy(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20281);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void JumpOffPawn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20283);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StuckOnPawn(class Pawn* OtherPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20284);
			byte params[4] = { NULL };
			*(class Pawn**)params = OtherPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BaseChange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20286);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanBeBaseForPawn(class Pawn* aPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20288);
			byte params[8] = { NULL };
			*(class Pawn**)params = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void CrushedBy(class Pawn* OtherPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20291);
			byte params[4] = { NULL };
			*(class Pawn**)params = OtherPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetachFromController(bool bDestroyController)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20293);
			byte params[4] = { NULL };
			*(bool*)params = bDestroyController;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20296);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20297);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20298);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnDefaultController()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20299);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceivedNewEvent(class SequenceEvent* Evt)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20300);
			byte params[4] = { NULL };
			*(class SequenceEvent**)params = Evt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAssignController(class SeqAct_AssignController* inAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20302);
			byte params[4] = { NULL };
			*(class SeqAct_AssignController**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnGiveInventory(class SeqAct_GiveInventory* inAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20306);
			byte params[4] = { NULL };
			*(class SeqAct_GiveInventory**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Gasp()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20313);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMovementPhysics()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20314);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AdjustDamage(int& InDamage, Vector& Momentum, class Controller* InstigatedBy, Vector HitLocation, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20315);
			byte params[68] = { NULL };
			*(int*)params = InDamage;
			*(Vector*)&params[4] = Momentum;
			*(class Controller**)&params[16] = InstigatedBy;
			*(Vector*)&params[20] = HitLocation;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InDamage = *(int*)params;
			Momentum = *(Vector*)&params[4];
		}
		bool HealDamage(int Amount, class Controller* Healer, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20323);
			byte params[16] = { NULL };
			*(int*)params = Amount;
			*(class Controller**)&params[4] = Healer;
			*(ScriptClass**)&params[8] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void PruneDamagedBoneList(ScriptArray<ScriptName>& Bones)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20328);
			byte params[12] = { NULL };
			*(ScriptArray<ScriptName>*)params = Bones;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Bones = *(ScriptArray<ScriptName>*)params;
		}
		bool TakeRadiusDamageOnBones(class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, ScriptArray<ScriptName> Bones)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20331);
			byte params[56] = { NULL };
			*(class Controller**)params = InstigatedBy;
			*(float*)&params[4] = BaseDamage;
			*(float*)&params[8] = DamageRadius;
			*(ScriptClass**)&params[12] = DamageType;
			*(float*)&params[16] = Momentum;
			*(Vector*)&params[20] = HurtOrigin;
			*(bool*)&params[32] = bFullDamage;
			*(class Actor**)&params[36] = DamageCauser;
			*(ScriptArray<ScriptName>*)&params[40] = Bones;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[52];
		}
		void NotifyTakeHit(class Controller* InstigatedBy, Vector HitLocation, int Damage, ScriptClass* DamageType, Vector Momentum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20350);
			byte params[36] = { NULL };
			*(class Controller**)params = InstigatedBy;
			*(Vector*)&params[4] = HitLocation;
			*(int*)&params[16] = Damage;
			*(ScriptClass**)&params[20] = DamageType;
			*(Vector*)&params[24] = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Controller* SetKillInstigator(class Controller* InstigatedBy, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20356);
			byte params[12] = { NULL };
			*(class Controller**)params = InstigatedBy;
			*(ScriptClass**)&params[4] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Controller**)&params[8];
		}
		void TakeDamage(int Damage, class Controller* InstigatedBy, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20360);
			byte params[68] = { NULL };
			*(int*)params = Damage;
			*(class Controller**)&params[4] = InstigatedBy;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		byte GetTeamNum()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20371);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *params;
		}
		class TeamInfo* GetTeam()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20373);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TeamInfo**)params;
		}
		bool IsSameTeam(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20375);
			byte params[8] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ThrowWeaponOnDeath()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20378);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DelayTriggerDeath()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20383);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Falling()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20384);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Landed(Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20385);
			byte params[16] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TickSpecial(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20388);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HeadVolumeChange(class PhysicsVolume* newHeadVolume)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20390);
			byte params[4] = { NULL };
			*(class PhysicsVolume**)params = newHeadVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BreathTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20393);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeDrowningDamage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20394);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayDyingSound()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20404);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayHit(float Damage, class Controller* InstigatedBy, Vector HitLocation, ScriptClass* DamageType, Vector Momentum, Actor::TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20405);
			byte params[64] = { NULL };
			*(float*)params = Damage;
			*(class Controller**)&params[4] = InstigatedBy;
			*(Vector*)&params[8] = HitLocation;
			*(ScriptClass**)&params[20] = DamageType;
			*(Vector*)&params[24] = Momentum;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TurnOff()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20412);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetDyingPhysics()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20413);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayDying(ScriptClass* DamageType, Vector HitLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20460);
			byte params[16] = { NULL };
			*(ScriptClass**)params = DamageType;
			*(Vector*)&params[4] = HitLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TornOff()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20463);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayFootStepSound(int FootDown)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20464);
			byte params[4] = { NULL };
			*(int*)params = FootDown;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayLanded(float ImpactVel)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20466);
			byte params[4] = { NULL };
			*(float*)params = ImpactVel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Vehicle* GetVehicleBase()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20468);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Vehicle**)params;
		}
		void Suicide()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20470);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartDriving(class Vehicle* V)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20473);
			byte params[4] = { NULL };
			*(class Vehicle**)params = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopDriving(class Vehicle* V)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20475);
			byte params[4] = { NULL };
			*(class Vehicle**)params = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddDefaultInventory()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20477);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawHUD(class HUD* H)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20482);
			byte params[4] = { NULL };
			*(class HUD**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ThrowActiveWeapon(bool bDestroyWeap)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20484);
			byte params[4] = { NULL };
			*(bool*)params = bDestroyWeap;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TossInventory(class Inventory* Inv, Vector ForceVelocity)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20486);
			byte params[16] = { NULL };
			*(class Inventory**)params = Inv;
			*(Vector*)&params[4] = ForceVelocity;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetActiveWeapon(class Weapon* NewWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20495);
			byte params[4] = { NULL };
			*(class Weapon**)params = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayWeaponSwitch(class Weapon* OldWeapon, class Weapon* NewWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20497);
			byte params[8] = { NULL };
			*(class Weapon**)params = OldWeapon;
			*(class Weapon**)&params[4] = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetCollisionRadius()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20500);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		bool IsStationary()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20503);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SpawnedByKismet()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20505);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DoKismetAttachment(class Actor* Attachment, class SeqAct_AttachToActor* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20506);
			byte params[8] = { NULL };
			*(class Actor**)params = Attachment;
			*(class SeqAct_AttachToActor**)&params[4] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetDamageScaling()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20513);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void OnSetMaterial(class SeqAct_SetMaterial* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20515);
			byte params[4] = { NULL };
			*(class SeqAct_SetMaterial**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnTeleport(class SeqAct_Teleport* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20517);
			byte params[4] = { NULL };
			*(class SeqAct_Teleport**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MessagePlayer(ScriptString* msg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20529);
			byte params[12] = { NULL };
			*(ScriptString**)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BecomeViewTarget(class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20531);
			byte params[4] = { NULL };
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SoakPause()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20533);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearConstraints()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20535);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddPathConstraint(class PathConstraint* Constraint)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20536);
			byte params[4] = { NULL };
			*(class PathConstraint**)params = Constraint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddGoalEvaluator(class PathGoalEvaluator* Evaluator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20538);
			byte params[4] = { NULL };
			*(class PathGoalEvaluator**)params = Evaluator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class PathConstraint* CreatePathConstraint(ScriptClass* ConstraintClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20540);
			byte params[8] = { NULL };
			*(ScriptClass**)params = ConstraintClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PathConstraint**)&params[4];
		}
		void IncrementPathStep(int Cnt, class Canvas* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20544);
			byte params[8] = { NULL };
			*(int*)params = Cnt;
			*(class Canvas**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void IncrementPathChild(int Cnt, class Canvas* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20547);
			byte params[8] = { NULL };
			*(int*)params = Cnt;
			*(class Canvas**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawPathStep(class Canvas* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20550);
			byte params[4] = { NULL };
			*(class Canvas**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearPathStep()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20552);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ZeroMovementVariables()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20553);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetCinematicMode(bool bInCinematicMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20554);
			byte params[4] = { NULL };
			*(bool*)params = bInCinematicMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetRootMotionInterpCurrentTime(float inTime, float DeltaTime, bool bUpdateSkelPose)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20556);
			byte params[12] = { NULL };
			*(float*)params = inTime;
			*(float*)&params[4] = DeltaTime;
			*(bool*)&params[8] = bUpdateSkelPose;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Speak(class SoundCue* Cue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20561);
			byte params[4] = { NULL };
			*(class SoundCue**)params = Cue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSetVelocity(class SeqAct_SetVelocity* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20563);
			byte params[4] = { NULL };
			*(class SeqAct_SetVelocity**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckClotheslineDamage(class Pawn* PawnHittingMe)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20565);
			byte params[8] = { NULL };
			*(class Pawn**)params = PawnHittingMe;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
