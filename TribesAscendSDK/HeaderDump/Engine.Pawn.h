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
		class ScalarParameterInterpStruct
		{
		public:
			ADD_STRUCT(float, WarmupTime, 16)
			ADD_STRUCT(float, InterpTime, 12)
			ADD_STRUCT(float, ParameterValue, 8)
			ADD_STRUCT(ScriptName, ParameterName, 0)
		};
		class LastHitInfoStruct
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
		ADD_STRUCT(Object::Vector, Floor, 732)
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
		ADD_STRUCT(Object::Vector, RootMotionInterpCurveLastValue, 1112)
		ADD_STRUCT(float, RootMotionInterpCurrentTime, 1108)
		ADD_STRUCT(float, RootMotionInterpRate, 1104)
		ADD_STRUCT(EngineTypes::RootMotionCurve, RootMotionInterpCurve, 1076)
		ADD_OBJECT(MaterialInstanceConstant, MIC_PawnHair, 1060)
		ADD_OBJECT(MaterialInstanceConstant, MIC_PawnMat, 1056)
		ADD_STRUCT(int, FailedLandingCount, 1024)
		ADD_OBJECT(RB_BodyInstance, PhysicsPushBody, 1020)
		ADD_STRUCT(int, ShotCount, 1012)
		ADD_STRUCT(Object::Vector, LastFiringFlashLocation, 1000)
		ADD_STRUCT(Object::Vector, FlashLocation, 988)
		ADD_OBJECT(ScriptClass, InventoryManagerClass, 976)
		ADD_STRUCT(Object::Rotator, DesiredRotation, 964)
		ADD_STRUCT(int, AllowedYawError, 960)
		ADD_STRUCT(float, ViewPitchMax, 956)
		ADD_STRUCT(float, ViewPitchMin, 952)
		ADD_OBJECT(Controller, LastHitBy, 948)
		ADD_STRUCT(float, AlwaysRelevantDistanceSquared, 940)
		ADD_OBJECT(Vehicle, DrivenVehicle, 936)
		ADD_STRUCT(float, RBPushStrength, 932)
		ADD_STRUCT(float, RBPushRadius, 928)
		ADD_STRUCT(Object::Vector, TearOffMomentum, 908)
		ADD_OBJECT(ScriptClass, HitDamageType, 904)
		ADD_STRUCT(Object::Vector, TakeHitLocation, 892)
		ADD_OBJECT(PlayerStart, LastStartSpot, 884)
		ADD_OBJECT(PlayerReplicationInfo, PlayerReplicationInfo, 860)
		ADD_OBJECT(ScriptClass, ControllerClass, 856)
		ADD_STRUCT(ScriptString*, MenuName, 844)
		ADD_STRUCT(float, DamageScaling, 840)
		ADD_STRUCT(float, SoundDampening, 836)
		ADD_STRUCT(float, noise2loudness, 832)
		ADD_OBJECT(Pawn, noise2other, 828)
		ADD_STRUCT(float, noise2time, 824)
		ADD_STRUCT(Object::Vector, noise2spot, 812)
		ADD_STRUCT(float, noise1loudness, 808)
		ADD_OBJECT(Pawn, noise1other, 804)
		ADD_STRUCT(float, noise1time, 800)
		ADD_STRUCT(Object::Vector, noise1spot, 788)
		ADD_STRUCT(Object::Vector, RMVelocity, 776)
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
		ADD_STRUCT(Object::Vector, SerpentineDir, 640)
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
		ADD_STRUCT(Object::Vector, PartialLedgeMoveDir, 496)
		ADD_STRUCT(float, LedgeCheckThreshold, 492)
		ADD_STRUCT(float, WalkableFloorZ, 488)
		ADD_STRUCT(float, MaxJumpHeight, 484)
		bool IsHumanControlled(class Controller* PawnController)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IsHumanControlled");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = PawnController;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsLocallyControlled(class Controller* PawnController)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IsLocallyControlled");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = PawnController;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool PlayActorFaceFXAnim(class FaceFXAnimSet* AnimSet, ScriptString* GroupName, ScriptString* SeqName, class SoundCue* SoundCueToPlay)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PlayActorFaceFXAnim");
			byte params[36] = { NULL };
			*(class FaceFXAnimSet**)&params[0] = AnimSet;
			*(ScriptString**)&params[4] = GroupName;
			*(ScriptString**)&params[16] = SeqName;
			*(class SoundCue**)&params[28] = SoundCueToPlay;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[32];
		}
		bool StopFiring()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.StopFiring");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		Object::Rotator GetBaseAimRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetBaseAimRotation");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[0];
		}
		ScriptString* GetHumanReadableName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetHumanReadableName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		bool Died(class Controller* Killer, ScriptClass* DamageType, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.Died");
			byte params[24] = { NULL };
			*(class Controller**)&params[0] = Killer;
			*(ScriptClass**)&params[4] = DamageType;
			*(Object::Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		ScriptName GetDefaultCameraMode(class PlayerController* RequestedBy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetDefaultCameraMode");
			byte params[12] = { NULL };
			*(class PlayerController**)&params[0] = RequestedBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[4];
		}
		bool CanThrowWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CanThrowWeapon");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool SetDesiredRotation(Object::Rotator TargetDesiredRotation, bool InLockDesiredRotation, bool InUnlockWhenReached, float InterpolationTime, bool bResetRotationRate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetDesiredRotation");
			byte params[32] = { NULL };
			*(Object::Rotator*)&params[0] = TargetDesiredRotation;
			*(bool*)&params[12] = InLockDesiredRotation;
			*(bool*)&params[16] = InUnlockWhenReached;
			*(float*)&params[20] = InterpolationTime;
			*(bool*)&params[24] = bResetRotationRate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		bool DoJump(bool bUpdating)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.DoJump");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bUpdating;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void SetRemoteViewPitch(int NewRemoteViewPitch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetRemoteViewPitch");
			byte params[4] = { NULL };
			*(int*)&params[0] = NewRemoteViewPitch;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CannotJumpNow()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CannotJumpNow");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool CheckWaterJump(Object::Vector& WallNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CheckWaterJump");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = WallNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			WallNormal = *(Object::Vector*)&params[0];
			return *(bool*)&params[12];
		}
		bool TouchingWaterVolume()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.TouchingWaterVolume");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool ReachedDestination(class Actor* Goal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ReachedDestination");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Goal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SpecialMoveTo(class NavigationPoint* Start, class NavigationPoint* End, class Actor* Next)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SpecialMoveTo");
			byte params[16] = { NULL };
			*(class NavigationPoint**)&params[0] = Start;
			*(class NavigationPoint**)&params[4] = End;
			*(class Actor**)&params[8] = Next;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void SetScalarParameterInterp(Pawn::ScalarParameterInterpStruct& ScalarParameterInterp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetScalarParameterInterp");
			byte params[20] = { NULL };
			*(Pawn::ScalarParameterInterpStruct*)&params[0] = ScalarParameterInterp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ScalarParameterInterp = *(Pawn::ScalarParameterInterpStruct*)&params[0];
		}
		bool CheatFly()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CheatFly");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool CheatWalk()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CheatWalk");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool CheatGhost()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CheatGhost");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool IsPlayerPawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IsPlayerPawn");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		class Inventory* FindInventoryType(ScriptClass* DesiredClass, bool bAllowSubclass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.FindInventoryType");
			byte params[12] = { NULL };
			*(ScriptClass**)&params[0] = DesiredClass;
			*(bool*)&params[4] = bAllowSubclass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Inventory**)&params[8];
		}
		class Inventory* CreateInventory(ScriptClass* NewInvClass, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CreateInventory");
			byte params[12] = { NULL };
			*(ScriptClass**)&params[0] = NewInvClass;
			*(bool*)&params[4] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Inventory**)&params[8];
		}
		bool InGodMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.InGodMode");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool ValidAnchor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ValidAnchor");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		class NavigationPoint* GetBestAnchor(class Actor* TestActor, Object::Vector TestLocation, bool bStartPoint, bool bOnlyCheckVisible, float& out_Dist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetBestAnchor");
			byte params[32] = { NULL };
			*(class Actor**)&params[0] = TestActor;
			*(Object::Vector*)&params[4] = TestLocation;
			*(bool*)&params[16] = bStartPoint;
			*(bool*)&params[20] = bOnlyCheckVisible;
			*(float*)&params[24] = out_Dist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Dist = *(float*)&params[24];
			return *(class NavigationPoint**)&params[28];
		}
		class PathGoalEvaluator* CreatePathGoalEvaluator(ScriptClass* GoalEvalClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CreatePathGoalEvaluator");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = GoalEvalClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PathGoalEvaluator**)&params[4];
		}
		float GetCollisionHeight()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetCollisionHeight");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		Object::Vector GetCollisionExtent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetCollisionExtent");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
		Object::Rotator GetViewRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetViewRotation");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[0];
		}
		bool CanGrabLadder()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CanGrabLadder");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool LineOfSightTo(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.LineOfSightTo");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool PickWallAdjust(Object::Vector WallHitNormal, class Actor* HitActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PickWallAdjust");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = WallHitNormal;
			*(class Actor**)&params[12] = HitActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void LockDesiredRotation(bool Lock, bool InUnlockWhenReached)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.LockDesiredRotation");
			byte params[8] = { NULL };
			*(bool*)&params[0] = Lock;
			*(bool*)&params[4] = InUnlockWhenReached;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetDesiredRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ResetDesiredRotation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckDesiredRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CheckDesiredRotation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsDesiredRotationInUse()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IsDesiredRotationInUse");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool IsDesiredRotationLocked()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IsDesiredRotationLocked");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PostInitAnimTree");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CacheAnimNodes()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CacheAnimNodes");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearAnimNodes()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ClearAnimNodes");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateAnimSetList()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.UpdateAnimSetList");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BuildScriptAnimSetList()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.BuildScriptAnimSetList");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddAnimSets(ScriptArray<class AnimSet*>& CustomAnimSets)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.AddAnimSets");
			byte params[12] = { NULL };
			*(ScriptArray<class AnimSet*>*)&params[0] = CustomAnimSets;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CustomAnimSets = *(ScriptArray<class AnimSet*>*)&params[0];
		}
		void AnimSetListUpdated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.AnimSetListUpdated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool RestoreAnimSetsToDefault()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.RestoreAnimSetsToDefault");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void BeginAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.BeginAnimControl");
			byte params[4] = { NULL };
			*(class InterpGroup**)&params[0] = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MAT_BeginAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.MAT_BeginAnimControl");
			byte params[4] = { NULL };
			*(class InterpGroup**)&params[0] = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FinishAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.FinishAnimControl");
			byte params[4] = { NULL };
			*(class InterpGroup**)&params[0] = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MAT_FinishAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.MAT_FinishAnimControl");
			byte params[4] = { NULL };
			*(class InterpGroup**)&params[0] = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAnimPosition(ScriptName SlotName, int ChannelIndex, ScriptName InAnimSeqName, float InPosition, bool bFireNotifies, bool bLooping, bool bEnableRootMotion)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetAnimPosition");
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
		void MAT_SetAnimPosition(ScriptName SlotName, int ChannelIndex, ScriptName InAnimSeqName, float InPosition, bool bFireNotifies, bool bLooping, bool bEnableRootMotion)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.MAT_SetAnimPosition");
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
		void MAT_SetAnimWeights(ScriptArray<Actor::AnimSlotInfo> SlotInfos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.MAT_SetAnimWeights");
			byte params[12] = { NULL };
			*(ScriptArray<Actor::AnimSlotInfo>*)&params[0] = SlotInfos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MAT_SetMorphWeight(ScriptName MorphNodeName, float MorphWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.MAT_SetMorphWeight");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = MorphNodeName;
			*(float*)&params[8] = MorphWeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MAT_SetSkelControlScale(ScriptName SkelControlName, float Scale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.MAT_SetSkelControlScale");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SkelControlName;
			*(float*)&params[8] = Scale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InterpolationStarted(class SeqAct_Interp* InterpAction, class InterpGroupInst* GroupInst)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.InterpolationStarted");
			byte params[8] = { NULL };
			*(class SeqAct_Interp**)&params[0] = InterpAction;
			*(class InterpGroupInst**)&params[4] = GroupInst;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InterpolationFinished(class SeqAct_Interp* InterpAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.InterpolationFinished");
			byte params[4] = { NULL };
			*(class SeqAct_Interp**)&params[0] = InterpAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MAT_BeginAIGroup(Object::Vector StartLoc, Object::Rotator StartRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.MAT_BeginAIGroup");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = StartLoc;
			*(Object::Rotator*)&params[12] = StartRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MAT_FinishAIGroup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.MAT_FinishAIGroup");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopActorFaceFXAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.StopActorFaceFXAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* GetFaceFXAudioComponent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetFaceFXAudioComponent");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0];
		}
		bool IsActorPlayingFaceFXAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IsActorPlayingFaceFXAnim");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool CanActorPlayFaceFXAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CanActorPlayFaceFXAnim");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void OnPlayFaceFXAnim(class SeqAct_PlayFaceFXAnim* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.OnPlayFaceFXAnim");
			byte params[4] = { NULL };
			*(class SeqAct_PlayFaceFXAnim**)&params[0] = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FaceFXAudioFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.FaceFXAudioFinished");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = AC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class FaceFXAsset* GetActorFaceFXAsset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetActorFaceFXAsset");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class FaceFXAsset**)&params[0];
		}
		void SetMorphWeight(ScriptName MorphNodeName, float MorphWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetMorphWeight");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = MorphNodeName;
			*(float*)&params[8] = MorphWeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSkelControlScale(ScriptName SkelControlName, float Scale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetSkelControlScale");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SkelControlName;
			*(float*)&params[8] = Scale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsAliveAndWell()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IsAliveAndWell");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		Object::Vector AdjustDestination(class Actor* GoalActor, Object::Vector Dest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.AdjustDestination");
			byte params[28] = { NULL };
			*(class Actor**)&params[0] = GoalActor;
			*(Object::Vector*)&params[4] = Dest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[16];
		}
		bool SuggestJumpVelocity(Object::Vector& JumpVelocity, Object::Vector Destination, Object::Vector Start, bool bRequireFallLanding)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SuggestJumpVelocity");
			byte params[44] = { NULL };
			*(Object::Vector*)&params[0] = JumpVelocity;
			*(Object::Vector*)&params[12] = Destination;
			*(Object::Vector*)&params[24] = Start;
			*(bool*)&params[36] = bRequireFallLanding;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			JumpVelocity = *(Object::Vector*)&params[0];
			return *(bool*)&params[40];
		}
		float GetFallDuration()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetFallDuration");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		bool IsValidEnemyTargetFor(class PlayerReplicationInfo* PRI, bool bNoPRIisEnemy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IsValidEnemyTargetFor");
			byte params[12] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = PRI;
			*(bool*)&params[4] = bNoPRIisEnemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool IsInvisible()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IsInvisible");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SetAnchor(class NavigationPoint* NewAnchor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetAnchor");
			byte params[4] = { NULL };
			*(class NavigationPoint**)&params[0] = NewAnchor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ReachedPoint(Object::Vector Point, class Actor* NewAnchor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ReachedPoint");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = Point;
			*(class Actor**)&params[12] = NewAnchor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void ForceCrouch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ForceCrouch");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPushesRigidBodies(bool NewPush)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetPushesRigidBodies");
			byte params[4] = { NULL };
			*(bool*)&params[0] = NewPush;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ReachedDesiredRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ReachedDesiredRotation");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void GetBoundingCylinder(float& CollisionRadius, float& CollisionHeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetBoundingCylinder");
			byte params[8] = { NULL };
			*(float*)&params[0] = CollisionRadius;
			*(float*)&params[4] = CollisionHeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CollisionRadius = *(float*)&params[0];
			CollisionHeight = *(float*)&params[4];
		}
		bool InitRagdoll()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.InitRagdoll");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool TermRagdoll()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.TermRagdoll");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool SpecialMoveThruEdge(Pylon::ENavMeshEdgeType Type, int Dir, Object::Vector MoveStart, Object::Vector MoveDest, class Actor* RelActor, int RelItem)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SpecialMoveThruEdge");
			byte params[41] = { NULL };
			*(Pylon::ENavMeshEdgeType*)&params[0] = Type;
			*(int*)&params[4] = Dir;
			*(Object::Vector*)&params[8] = MoveStart;
			*(Object::Vector*)&params[20] = MoveDest;
			*(class Actor**)&params[32] = RelActor;
			*(int*)&params[36] = RelItem;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[40];
		}
		void SetBaseEyeheight()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetBaseEyeheight");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayerChangedTeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PlayerChangedTeam");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.StartFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.StopFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		byte GetWeaponFiringMode(class Weapon* InWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetWeaponFiringMode");
			byte params[5] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[4];
		}
		void SetFiringMode(class Weapon* InWeapon, byte InFiringMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetFiringMode");
			byte params[5] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			params[4] = InFiringMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FiringModeUpdated(class Weapon* InWeapon, byte InFiringMode, bool bViaReplication)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.FiringModeUpdated");
			byte params[9] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			params[4] = InFiringMode;
			*(bool*)&params[8] = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void IncrementFlashCount(class Weapon* InWeapon, byte InFiringMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IncrementFlashCount");
			byte params[5] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			params[4] = InFiringMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FlashCountUpdated(class Weapon* InWeapon, byte InFlashCount, bool bViaReplication)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.FlashCountUpdated");
			byte params[9] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			params[4] = InFlashCount;
			*(bool*)&params[8] = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFlashCount(class Weapon* InWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ClearFlashCount");
			byte params[4] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFlashLocation(class Weapon* InWeapon, byte InFiringMode, Object::Vector NewLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetFlashLocation");
			byte params[17] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			params[4] = InFiringMode;
			*(Object::Vector*)&params[8] = NewLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFlashLocation(class Weapon* InWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ClearFlashLocation");
			byte params[4] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FlashLocationUpdated(class Weapon* InWeapon, Object::Vector InFlashLocation, bool bViaReplication)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.FlashLocationUpdated");
			byte params[20] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			*(Object::Vector*)&params[4] = InFlashLocation;
			*(bool*)&params[16] = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WeaponFired(class Weapon* InWeapon, bool bViaReplication, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.WeaponFired");
			byte params[20] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			*(bool*)&params[4] = bViaReplication;
			*(Object::Vector*)&params[8] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WeaponStoppedFiring(class Weapon* InWeapon, bool bViaReplication)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.WeaponStoppedFiring");
			byte params[8] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			*(bool*)&params[4] = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool BotFire(bool bFinished)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.BotFire");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bFinished;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CanAttack(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CanAttack");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool TooCloseToAttack(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.TooCloseToAttack");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool FireOnRelease()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.FireOnRelease");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool HasRangedAttack()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.HasRangedAttack");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool IsFiring()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IsFiring");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool NeedToTurn(Object::Vector targ)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.NeedToTurn");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = targ;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void PlayTeleportEffect(bool bOut, bool bSound)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PlayTeleportEffect");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bOut;
			*(bool*)&params[4] = bSound;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyTeamChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.NotifyTeamChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PossessedBy(class Controller* C, bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PossessedBy");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = C;
			*(bool*)&params[4] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateControllerOnPossess(bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.UpdateControllerOnPossess");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnPossessed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.UnPossessed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DropToGround()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.DropToGround");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool RecommendLongRangedAttack()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.RecommendLongRangedAttack");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		float RangedAttackTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.RangedAttackTime");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void SetWalking(bool bNewIsWalking)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetWalking");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewIsWalking;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanSplash()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CanSplash");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void EndClimbLadder(class LadderVolume* OldLadder)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.EndClimbLadder");
			byte params[4] = { NULL };
			*(class LadderVolume**)&params[0] = OldLadder;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClimbLadder(class LadderVolume* L)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ClimbLadder");
			byte params[4] = { NULL };
			*(class LadderVolume**)&params[0] = L;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.DisplayDebug");
			byte params[12] = { NULL };
			*(class HUD**)&params[0] = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		bool IsFirstPerson()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IsFirstPerson");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ProcessViewRotation(float DeltaTime, Object::Rotator& out_ViewRotation, Object::Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ProcessViewRotation");
			byte params[28] = { NULL };
			*(float*)&params[0] = DeltaTime;
			*(Object::Rotator*)&params[4] = out_ViewRotation;
			*(Object::Rotator*)&params[16] = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ViewRotation = *(Object::Rotator*)&params[4];
			out_DeltaRot = *(Object::Rotator*)&params[16];
		}
		void GetActorEyesViewPoint(Object::Vector& out_Location, Object::Rotator& out_Rotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetActorEyesViewPoint");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = out_Location;
			*(Object::Rotator*)&params[12] = out_Rotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Location = *(Object::Vector*)&params[0];
			out_Rotation = *(Object::Rotator*)&params[12];
		}
		Object::Vector GetPawnViewLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetPawnViewLocation");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
		Object::Vector GetWeaponStartTraceLocation(class Weapon* CurrentWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetWeaponStartTraceLocation");
			byte params[16] = { NULL };
			*(class Weapon**)&params[0] = CurrentWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[4];
		}
		bool InFreeCam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.InFreeCam");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		Object::Rotator GetAdjustedAimFor(class Weapon* W, Object::Vector StartFireLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetAdjustedAimFor");
			byte params[28] = { NULL };
			*(class Weapon**)&params[0] = W;
			*(Object::Vector*)&params[4] = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[16];
		}
		void SetViewRotation(Object::Rotator NewRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetViewRotation");
			byte params[12] = { NULL };
			*(Object::Rotator*)&params[0] = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMoveTarget(class Actor* NewTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetMoveTarget");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = NewTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HandlePickup(class Inventory* Inv)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.HandlePickup");
			byte params[4] = { NULL };
			*(class Inventory**)&params[0] = Inv;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientMessage(ScriptString* S, ScriptName Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ClientMessage");
			byte params[20] = { NULL };
			*(ScriptString**)&params[0] = S;
			*(ScriptName*)&params[12] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.FellOutOfWorld");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OutsideWorldBounds()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.OutsideWorldBounds");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UnCrouch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.UnCrouch");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShouldCrouch(bool bCrouch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ShouldCrouch");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bCrouch;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndCrouch(float HeightAdjust)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.EndCrouch");
			byte params[4] = { NULL };
			*(float*)&params[0] = HeightAdjust;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartCrouch(float HeightAdjust)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.StartCrouch");
			byte params[4] = { NULL };
			*(float*)&params[0] = HeightAdjust;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HandleMomentum(Object::Vector Momentum, Object::Vector HitLocation, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.HandleMomentum");
			byte params[56] = { NULL };
			*(Object::Vector*)&params[0] = Momentum;
			*(Object::Vector*)&params[12] = HitLocation;
			*(ScriptClass**)&params[24] = DamageType;
			*(Actor::TraceHitInfo*)&params[28] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddVelocity(Object::Vector NewVelocity, Object::Vector HitLocation, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.AddVelocity");
			byte params[56] = { NULL };
			*(Object::Vector*)&params[0] = NewVelocity;
			*(Object::Vector*)&params[12] = HitLocation;
			*(ScriptClass**)&params[24] = DamageType;
			*(Actor::TraceHitInfo*)&params[28] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KilledBy(class Pawn* EventInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.KilledBy");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeFallingDamage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.TakeFallingDamage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Restart()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.Restart");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientRestart()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ClientRestart");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientSetRotation(Object::Rotator NewRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ClientSetRotation");
			byte params[12] = { NULL };
			*(Object::Rotator*)&params[0] = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdatePawnRotation(Object::Rotator NewRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.UpdatePawnRotation");
			byte params[12] = { NULL };
			*(Object::Rotator*)&params[0] = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FaceRotation(Object::Rotator NewRotation, float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.FaceRotation");
			byte params[16] = { NULL };
			*(Object::Rotator*)&params[0] = NewRotation;
			*(float*)&params[12] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool EncroachingOn(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.EncroachingOn");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void EncroachedBy(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.EncroachedBy");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void gibbedBy(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.gibbedBy");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void JumpOffPawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.JumpOffPawn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StuckOnPawn(class Pawn* OtherPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.StuckOnPawn");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = OtherPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BaseChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.BaseChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanBeBaseForPawn(class Pawn* aPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CanBeBaseForPawn");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void CrushedBy(class Pawn* OtherPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CrushedBy");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = OtherPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetachFromController(bool bDestroyController)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.DetachFromController");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bDestroyController;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnDefaultController()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SpawnDefaultController");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceivedNewEvent(class SequenceEvent* Evt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ReceivedNewEvent");
			byte params[4] = { NULL };
			*(class SequenceEvent**)&params[0] = Evt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAssignController(class SeqAct_AssignController* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.OnAssignController");
			byte params[4] = { NULL };
			*(class SeqAct_AssignController**)&params[0] = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnGiveInventory(class SeqAct_GiveInventory* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.OnGiveInventory");
			byte params[4] = { NULL };
			*(class SeqAct_GiveInventory**)&params[0] = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Gasp()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.Gasp");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMovementPhysics()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetMovementPhysics");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AdjustDamage(int& InDamage, Object::Vector& Momentum, class Controller* InstigatedBy, Object::Vector HitLocation, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.AdjustDamage");
			byte params[68] = { NULL };
			*(int*)&params[0] = InDamage;
			*(Object::Vector*)&params[4] = Momentum;
			*(class Controller**)&params[16] = InstigatedBy;
			*(Object::Vector*)&params[20] = HitLocation;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InDamage = *(int*)&params[0];
			Momentum = *(Object::Vector*)&params[4];
		}
		bool HealDamage(int Amount, class Controller* Healer, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.HealDamage");
			byte params[16] = { NULL };
			*(int*)&params[0] = Amount;
			*(class Controller**)&params[4] = Healer;
			*(ScriptClass**)&params[8] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void PruneDamagedBoneList(ScriptArray<ScriptName>& Bones)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PruneDamagedBoneList");
			byte params[12] = { NULL };
			*(ScriptArray<ScriptName>*)&params[0] = Bones;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Bones = *(ScriptArray<ScriptName>*)&params[0];
		}
		bool TakeRadiusDamageOnBones(class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Object::Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, ScriptArray<ScriptName> Bones)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.TakeRadiusDamageOnBones");
			byte params[56] = { NULL };
			*(class Controller**)&params[0] = InstigatedBy;
			*(float*)&params[4] = BaseDamage;
			*(float*)&params[8] = DamageRadius;
			*(ScriptClass**)&params[12] = DamageType;
			*(float*)&params[16] = Momentum;
			*(Object::Vector*)&params[20] = HurtOrigin;
			*(bool*)&params[32] = bFullDamage;
			*(class Actor**)&params[36] = DamageCauser;
			*(ScriptArray<ScriptName>*)&params[40] = Bones;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[52];
		}
		void NotifyTakeHit(class Controller* InstigatedBy, Object::Vector HitLocation, int Damage, ScriptClass* DamageType, Object::Vector Momentum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.NotifyTakeHit");
			byte params[36] = { NULL };
			*(class Controller**)&params[0] = InstigatedBy;
			*(Object::Vector*)&params[4] = HitLocation;
			*(int*)&params[16] = Damage;
			*(ScriptClass**)&params[20] = DamageType;
			*(Object::Vector*)&params[24] = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Controller* SetKillInstigator(class Controller* InstigatedBy, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetKillInstigator");
			byte params[12] = { NULL };
			*(class Controller**)&params[0] = InstigatedBy;
			*(ScriptClass**)&params[4] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Controller**)&params[8];
		}
		void TakeDamage(int Damage, class Controller* InstigatedBy, Object::Vector HitLocation, Object::Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.TakeDamage");
			byte params[68] = { NULL };
			*(int*)&params[0] = Damage;
			*(class Controller**)&params[4] = InstigatedBy;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		byte GetTeamNum()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetTeamNum");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[0];
		}
		class TeamInfo* GetTeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetTeam");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TeamInfo**)&params[0];
		}
		bool IsSameTeam(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IsSameTeam");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ThrowWeaponOnDeath()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ThrowWeaponOnDeath");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DelayTriggerDeath()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.DelayTriggerDeath");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Falling()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.Falling");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Landed(Object::Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.Landed");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = HitNormal;
			*(class Actor**)&params[12] = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TickSpecial(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.TickSpecial");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HeadVolumeChange(class PhysicsVolume* newHeadVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.HeadVolumeChange");
			byte params[4] = { NULL };
			*(class PhysicsVolume**)&params[0] = newHeadVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BreathTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.BreathTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeDrowningDamage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.TakeDrowningDamage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayDyingSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PlayDyingSound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayHit(float Damage, class Controller* InstigatedBy, Object::Vector HitLocation, ScriptClass* DamageType, Object::Vector Momentum, Actor::TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PlayHit");
			byte params[64] = { NULL };
			*(float*)&params[0] = Damage;
			*(class Controller**)&params[4] = InstigatedBy;
			*(Object::Vector*)&params[8] = HitLocation;
			*(ScriptClass**)&params[20] = DamageType;
			*(Object::Vector*)&params[24] = Momentum;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TurnOff()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.TurnOff");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetDyingPhysics()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetDyingPhysics");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayDying(ScriptClass* DamageType, Object::Vector HitLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PlayDying");
			byte params[16] = { NULL };
			*(ScriptClass**)&params[0] = DamageType;
			*(Object::Vector*)&params[4] = HitLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TornOff()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.TornOff");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayFootStepSound(int FootDown)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PlayFootStepSound");
			byte params[4] = { NULL };
			*(int*)&params[0] = FootDown;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayLanded(float ImpactVel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PlayLanded");
			byte params[4] = { NULL };
			*(float*)&params[0] = ImpactVel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Vehicle* GetVehicleBase()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetVehicleBase");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Vehicle**)&params[0];
		}
		void Suicide()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.Suicide");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartDriving(class Vehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.StartDriving");
			byte params[4] = { NULL };
			*(class Vehicle**)&params[0] = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopDriving(class Vehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.StopDriving");
			byte params[4] = { NULL };
			*(class Vehicle**)&params[0] = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddDefaultInventory()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.AddDefaultInventory");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawHUD(class HUD* H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.DrawHUD");
			byte params[4] = { NULL };
			*(class HUD**)&params[0] = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ThrowActiveWeapon(bool bDestroyWeap)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ThrowActiveWeapon");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bDestroyWeap;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TossInventory(class Inventory* Inv, Object::Vector ForceVelocity)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.TossInventory");
			byte params[16] = { NULL };
			*(class Inventory**)&params[0] = Inv;
			*(Object::Vector*)&params[4] = ForceVelocity;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetActiveWeapon(class Weapon* NewWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetActiveWeapon");
			byte params[4] = { NULL };
			*(class Weapon**)&params[0] = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayWeaponSwitch(class Weapon* OldWeapon, class Weapon* NewWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PlayWeaponSwitch");
			byte params[8] = { NULL };
			*(class Weapon**)&params[0] = OldWeapon;
			*(class Weapon**)&params[4] = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetCollisionRadius()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetCollisionRadius");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		bool IsStationary()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IsStationary");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SpawnedByKismet()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SpawnedByKismet");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DoKismetAttachment(class Actor* Attachment, class SeqAct_AttachToActor* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.DoKismetAttachment");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Attachment;
			*(class SeqAct_AttachToActor**)&params[4] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetDamageScaling()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetDamageScaling");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void OnSetMaterial(class SeqAct_SetMaterial* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.OnSetMaterial");
			byte params[4] = { NULL };
			*(class SeqAct_SetMaterial**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnTeleport(class SeqAct_Teleport* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.OnTeleport");
			byte params[4] = { NULL };
			*(class SeqAct_Teleport**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MessagePlayer(ScriptString* msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.MessagePlayer");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BecomeViewTarget(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.BecomeViewTarget");
			byte params[4] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SoakPause()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SoakPause");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearConstraints()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ClearConstraints");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddPathConstraint(class PathConstraint* Constraint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.AddPathConstraint");
			byte params[4] = { NULL };
			*(class PathConstraint**)&params[0] = Constraint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddGoalEvaluator(class PathGoalEvaluator* Evaluator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.AddGoalEvaluator");
			byte params[4] = { NULL };
			*(class PathGoalEvaluator**)&params[0] = Evaluator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class PathConstraint* CreatePathConstraint(ScriptClass* ConstraintClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CreatePathConstraint");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = ConstraintClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PathConstraint**)&params[4];
		}
		void IncrementPathStep(int Cnt, class Canvas* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IncrementPathStep");
			byte params[8] = { NULL };
			*(int*)&params[0] = Cnt;
			*(class Canvas**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void IncrementPathChild(int Cnt, class Canvas* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IncrementPathChild");
			byte params[8] = { NULL };
			*(int*)&params[0] = Cnt;
			*(class Canvas**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawPathStep(class Canvas* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.DrawPathStep");
			byte params[4] = { NULL };
			*(class Canvas**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearPathStep()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ClearPathStep");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ZeroMovementVariables()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ZeroMovementVariables");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetCinematicMode(bool bInCinematicMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetCinematicMode");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bInCinematicMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetRootMotionInterpCurrentTime(float inTime, float DeltaTime, bool bUpdateSkelPose)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetRootMotionInterpCurrentTime");
			byte params[12] = { NULL };
			*(float*)&params[0] = inTime;
			*(float*)&params[4] = DeltaTime;
			*(bool*)&params[8] = bUpdateSkelPose;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Speak(class SoundCue* Cue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.Speak");
			byte params[4] = { NULL };
			*(class SoundCue**)&params[0] = Cue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSetVelocity(class SeqAct_SetVelocity* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.OnSetVelocity");
			byte params[4] = { NULL };
			*(class SeqAct_SetVelocity**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckClotheslineDamage(class Pawn* PawnHittingMe)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CheckClotheslineDamage");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = PawnHittingMe;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
