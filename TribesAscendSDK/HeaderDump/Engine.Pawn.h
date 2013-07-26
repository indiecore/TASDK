#pragma once
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Engine.Weapon.h"
#include "Engine.InventoryManager.h"
#include "Engine.SeqAct_AttachToActor.h"
#include "Engine.LadderVolume.h"
#include "Engine.FaceFXAnimSet.h"
#include "Core.Object.Vector.h"
#include "Engine.PhysicsVolume.h"
#include "Engine.NavigationPoint.h"
#include "Engine.Pawn.LastHitInfoStruct.h"
#include "Engine.EngineTypes.RootMotionCurve.h"
#include "Engine.SeqAct_AssignController.h"
#include "Engine.Inventory.h"
#include "Engine.MaterialInstanceConstant.h"
#include "Engine.RB_BodyInstance.h"
#include "Core.Object.Rotator.h"
#include "Engine.InterpGroupInst.h"
#include "Engine.PathGoalEvaluator.h"
#include "Engine.Vehicle.h"
#include "Engine.PlayerStart.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.PathConstraint.h"
#include "Core.Object.Pointer.h"
#include "Engine.SeqAct_SetMaterial.h"
#include "Engine.InterpGroup.h"
#include "Engine.PlayerController.h"
#include "Engine.SoundCue.h"
#include "Engine.Pawn.ScalarParameterInterpStruct.h"
#include "Engine.SeqAct_Interp.h"
#include "Engine.Actor.TraceHitInfo.h"
#include "Engine.SeqAct_PlayFaceFXAnim.h"
#include "Engine.FaceFXAsset.h"
#include "Engine.HUD.h"
#include "Engine.SequenceEvent.h"
#include "Engine.SeqAct_GiveInventory.h"
#include "Engine.TeamInfo.h"
#include "Engine.SeqAct_Teleport.h"
#include "Engine.Canvas.h"
#include "Engine.SeqAct_SetVelocity.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Pawn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Pawn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Pawn." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Pawn : public Actor
	{
	public:
		ADD_OBJECT(Controller, Controller)
		ADD_VAR(::IntProperty, MaxPitchLimit, 0xFFFFFFFF)
		ADD_OBJECT(Weapon, Weapon)
		ADD_OBJECT(InventoryManager, InvManager)
		ADD_VAR(::BoolProperty, bIsWalking, 0x4)
		ADD_VAR(::FloatProperty, EyeHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BaseEyeHeight, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Health, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bForceRMVelocity, 0x100000)
		ADD_STRUCT(::VectorProperty, Floor, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRootMotionFromInterpCurve, 0x8000000)
		ADD_VAR(::FloatProperty, CrouchHeight, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsCrouched, 0x10)
		ADD_VAR(::FloatProperty, MaxStepHeight, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bForceMaxAccel, 0x20000)
		ADD_VAR(::FloatProperty, VehicleCheckRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastStartTime, 0xFFFFFFFF)
		ADD_OBJECT(PhysicsVolume, HeadVolume)
		ADD_VAR(::FloatProperty, BreathTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, UnderWaterTime, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, WaterMovementState, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, LandMovementState, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AccelRate, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, WalkingPhysics, 0xFFFFFFFF)
		ADD_OBJECT(LadderVolume, OnLadder)
		ADD_VAR(::BoolProperty, bUpAndOut, 0x2)
		ADD_VAR(::FloatProperty, OutofWaterZ, 0xFFFFFFFF)
		ADD_OBJECT(NavigationPoint, Anchor)
		ADD_STRUCT(::NonArithmeticProperty<LastHitInfoStruct>, LastHitInfo, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, RootMotionInterpCurveLastValue, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RootMotionInterpCurrentTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RootMotionInterpRate, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RootMotionCurve>, RootMotionInterpCurve, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, MIC_PawnHair)
		ADD_OBJECT(MaterialInstanceConstant, MIC_PawnMat)
		ADD_VAR(::IntProperty, FailedLandingCount, 0xFFFFFFFF)
		ADD_OBJECT(RB_BodyInstance, PhysicsPushBody)
		ADD_VAR(::IntProperty, ShotCount, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LastFiringFlashLocation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, FlashLocation, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, InventoryManagerClass)
		ADD_STRUCT(::RotatorProperty, DesiredRotation, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AllowedYawError, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ViewPitchMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ViewPitchMin, 0xFFFFFFFF)
		ADD_OBJECT(Controller, LastHitBy)
		ADD_VAR(::FloatProperty, AlwaysRelevantDistanceSquared, 0xFFFFFFFF)
		ADD_OBJECT(Vehicle, DrivenVehicle)
		ADD_VAR(::FloatProperty, RBPushStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RBPushRadius, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, TearOffMomentum, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, HitDamageType)
		ADD_STRUCT(::VectorProperty, TakeHitLocation, 0xFFFFFFFF)
		ADD_OBJECT(PlayerStart, LastStartSpot)
		ADD_OBJECT(PlayerReplicationInfo, PlayerReplicationInfo)
		ADD_OBJECT(ScriptClass, ControllerClass)
		ADD_VAR(::StrProperty, MenuName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DamageScaling, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SoundDampening, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, noise2loudness, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, noise2other)
		ADD_VAR(::FloatProperty, noise2time, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, noise2spot, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, noise1loudness, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, noise1other)
		ADD_VAR(::FloatProperty, noise1time, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, noise1spot, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, RMVelocity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, KismetDeathDelayTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastPainTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, HealthMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SplashTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AIMaxFallSpeedFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxFallSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CrouchedPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MovementSpeedModifier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WalkingPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AirControl, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxOutOfWaterStepHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, JumpZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LadderSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AirSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WaterSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, GroundSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpawnTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SerpentineTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SerpentineDist, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, SerpentineDir, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NextPathRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DestinationOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastValidAnchorTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FindAnchorFailedTime, 0xFFFFFFFF)
		ADD_OBJECT(NavigationPoint, LastAnchor)
		ADD_VAR(::IntProperty, AnchorItem, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MeleeRange, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Buoyancy, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Mass, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AvgPhysicsTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PeripheralVision, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SightRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Alertness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HearingThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDesiredSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DesiredSpeed, 0xFFFFFFFF)
		ADD_OBJECT(PathGoalEvaluator, PathGoalList)
		ADD_OBJECT(PathConstraint, PathConstraintList)
		ADD_VAR(::FloatProperty, NonPreferredVehiclePathMultiplier, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FullHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CrouchRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, UncrouchTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, FiringMode, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, FlashCount, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, RemoteViewPitch, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, PathSearchType, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VfTable_IInterface_Speaker, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDebugShowCameraLocation, 0x10000000)
		ADD_VAR(::BoolProperty, bNeedsBaseTickedFirst, 0x4000000)
		ADD_VAR(::BoolProperty, bUnlockWhenReached, 0x2000000)
		ADD_VAR(::BoolProperty, bLockDesiredRotation, 0x1000000)
		ADD_VAR(::BoolProperty, bDesiredRotationSet, 0x800000)
		ADD_VAR(::BoolProperty, bPlayedDeath, 0x400000)
		ADD_VAR(::BoolProperty, bForceRegularVelocity, 0x200000)
		ADD_VAR(::BoolProperty, bReplicateHealthToAll, 0x80000)
		ADD_VAR(::BoolProperty, bLimitFallAccel, 0x40000)
		ADD_VAR(::BoolProperty, bRunPhysicsWithNoController, 0x10000)
		ADD_VAR(::BoolProperty, bPathfindsAsVehicle, 0x8000)
		ADD_VAR(::BoolProperty, bModifyNavPointDest, 0x4000)
		ADD_VAR(::BoolProperty, bModifyReachSpecCost, 0x2000)
		ADD_VAR(::BoolProperty, bNoWeaponFiring, 0x1000)
		ADD_VAR(::BoolProperty, bCachedRelevant, 0x800)
		ADD_VAR(::BoolProperty, bStationary, 0x400)
		ADD_VAR(::BoolProperty, bRollToDesired, 0x200)
		ADD_VAR(::BoolProperty, bDontPossess, 0x100)
		ADD_VAR(::BoolProperty, bMuffledHearing, 0x80)
		ADD_VAR(::BoolProperty, bLOSHearing, 0x40)
		ADD_VAR(::BoolProperty, bAmbientCreature, 0x20)
		ADD_VAR(::BoolProperty, bCanPickupInventory, 0x10)
		ADD_VAR(::BoolProperty, bDisplayPathErrors, 0x8)
		ADD_VAR(::BoolProperty, bCanCoverSlip, 0x4)
		ADD_VAR(::BoolProperty, bCanLeap, 0x2)
		ADD_VAR(::BoolProperty, bCanSwatTurn, 0x1)
		ADD_VAR(::BoolProperty, bCanClimbCeilings, 0x80000000)
		ADD_VAR(::BoolProperty, bCanClimbUp, 0x40000000)
		ADD_VAR(::BoolProperty, bCanMantle, 0x20000000)
		ADD_VAR(::BoolProperty, bForceKeepAnchor, 0x10000000)
		ADD_VAR(::BoolProperty, bForceFloorCheck, 0x8000000)
		ADD_VAR(::BoolProperty, bPushesRigidBodies, 0x4000000)
		ADD_VAR(::BoolProperty, bDirectHitWall, 0x2000000)
		ADD_VAR(::BoolProperty, bSimGravityDisabled, 0x1000000)
		ADD_VAR(::BoolProperty, bCanBeBaseForPawns, 0x800000)
		ADD_VAR(::BoolProperty, bCanWalkOffLedges, 0x400000)
		ADD_VAR(::BoolProperty, bIgnoreForces, 0x200000)
		ADD_VAR(::BoolProperty, bSimulateGravity, 0x100000)
		ADD_VAR(::BoolProperty, bPartiallyOverLedge, 0x80000)
		ADD_VAR(::BoolProperty, bAllowLedgeOverhang, 0x40000)
		ADD_VAR(::BoolProperty, bStopAtLedges, 0x20000)
		ADD_VAR(::BoolProperty, bAvoidLedges, 0x10000)
		ADD_VAR(::BoolProperty, bCanStrafe, 0x8000)
		ADD_VAR(::BoolProperty, bCanClimbLadders, 0x4000)
		ADD_VAR(::BoolProperty, bCanFly, 0x2000)
		ADD_VAR(::BoolProperty, bCanSwim, 0x1000)
		ADD_VAR(::BoolProperty, bCanWalk, 0x800)
		ADD_VAR(::BoolProperty, bCanJump, 0x400)
		ADD_VAR(::BoolProperty, bJumpCapable, 0x200)
		ADD_VAR(::BoolProperty, bReducedSpeed, 0x100)
		ADD_VAR(::BoolProperty, bCrawler, 0x80)
		ADD_VAR(::BoolProperty, bCanCrouch, 0x40)
		ADD_VAR(::BoolProperty, bTryToUncrouch, 0x20)
		ADD_VAR(::BoolProperty, bWantsToCrouch, 0x8)
		ADD_VAR(::BoolProperty, bScriptTickSpecial, 0x1)
		ADD_OBJECT(Actor, LastViewer)
		ADD_OBJECT(PlayerController, LastRealViewer)
		ADD_VAR(::FloatProperty, NetRelevancyTime, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, NextPawn)
		ADD_STRUCT(::VectorProperty, PartialLedgeMoveDir, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LedgeCheckThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WalkableFloorZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxJumpHeight, 0xFFFFFFFF)
		bool IsHumanControlled(class Controller* PawnController)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IsHumanControlled");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = PawnController;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsLocallyControlled(class Controller* PawnController)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IsLocallyControlled");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = PawnController;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool PlayActorFaceFXAnim(class FaceFXAnimSet* AnimSet, ScriptArray<wchar_t> GroupName, ScriptArray<wchar_t> SeqName, class SoundCue* SoundCueToPlay)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PlayActorFaceFXAnim");
			byte* params = (byte*)malloc(36);
			*(class FaceFXAnimSet**)params = AnimSet;
			*(ScriptArray<wchar_t>*)(params + 4) = GroupName;
			*(ScriptArray<wchar_t>*)(params + 16) = SeqName;
			*(class SoundCue**)(params + 28) = SoundCueToPlay;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 32);
			free(params);
			return returnVal;
		}
		bool StopFiring()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.StopFiring");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		Rotator GetBaseAimRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetBaseAimRotation");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetHumanReadableName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetHumanReadableName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		bool Died(class Controller* Killer, ScriptClass* DamageType, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.Died");
			byte* params = (byte*)malloc(24);
			*(class Controller**)params = Killer;
			*(ScriptClass**)(params + 4) = DamageType;
			*(Vector*)(params + 8) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		ScriptName GetDefaultCameraMode(class PlayerController* RequestedBy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetDefaultCameraMode");
			byte* params = (byte*)malloc(12);
			*(class PlayerController**)params = RequestedBy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CanThrowWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CanThrowWeapon");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool SetDesiredRotation(Rotator TargetDesiredRotation, bool InLockDesiredRotation, bool InUnlockWhenReached, float InterpolationTime, bool bResetRotationRate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetDesiredRotation");
			byte* params = (byte*)malloc(32);
			*(Rotator*)params = TargetDesiredRotation;
			*(bool*)(params + 12) = InLockDesiredRotation;
			*(bool*)(params + 16) = InUnlockWhenReached;
			*(float*)(params + 20) = InterpolationTime;
			*(bool*)(params + 24) = bResetRotationRate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		bool DoJump(bool bUpdating)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.DoJump");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bUpdating;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void SetRemoteViewPitch(int NewRemoteViewPitch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetRemoteViewPitch");
			byte* params = (byte*)malloc(4);
			*(int*)params = NewRemoteViewPitch;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CannotJumpNow()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CannotJumpNow");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool CheckWaterJump(Vector& WallNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CheckWaterJump");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = WallNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			WallNormal = *(Vector*)params;
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool TouchingWaterVolume()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.TouchingWaterVolume");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool ReachedDestination(class Actor* Goal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ReachedDestination");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Goal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool SpecialMoveTo(class NavigationPoint* Start, class NavigationPoint* End, class Actor* Next)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SpecialMoveTo");
			byte* params = (byte*)malloc(16);
			*(class NavigationPoint**)params = Start;
			*(class NavigationPoint**)(params + 4) = End;
			*(class Actor**)(params + 8) = Next;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void SetScalarParameterInterp(ScalarParameterInterpStruct& ScalarParameterInterp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetScalarParameterInterp");
			byte* params = (byte*)malloc(20);
			*(ScalarParameterInterpStruct*)params = ScalarParameterInterp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ScalarParameterInterp = *(ScalarParameterInterpStruct*)params;
			free(params);
		}
		bool CheatFly()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CheatFly");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool CheatWalk()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CheatWalk");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool CheatGhost()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CheatGhost");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsPlayerPawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IsPlayerPawn");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		class Inventory* FindInventoryType(ScriptClass* DesiredClass, bool bAllowSubclass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.FindInventoryType");
			byte* params = (byte*)malloc(12);
			*(ScriptClass**)params = DesiredClass;
			*(bool*)(params + 4) = bAllowSubclass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Inventory**)(params + 8);
			free(params);
			return returnVal;
		}
		class Inventory* CreateInventory(ScriptClass* NewInvClass, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CreateInventory");
			byte* params = (byte*)malloc(12);
			*(ScriptClass**)params = NewInvClass;
			*(bool*)(params + 4) = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Inventory**)(params + 8);
			free(params);
			return returnVal;
		}
		bool InGodMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.InGodMode");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool ValidAnchor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ValidAnchor");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		class NavigationPoint* GetBestAnchor(class Actor* TestActor, Vector TestLocation, bool bStartPoint, bool bOnlyCheckVisible, float& out_Dist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetBestAnchor");
			byte* params = (byte*)malloc(32);
			*(class Actor**)params = TestActor;
			*(Vector*)(params + 4) = TestLocation;
			*(bool*)(params + 16) = bStartPoint;
			*(bool*)(params + 20) = bOnlyCheckVisible;
			*(float*)(params + 24) = out_Dist;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_Dist = *(float*)(params + 24);
			auto returnVal = *(class NavigationPoint**)(params + 28);
			free(params);
			return returnVal;
		}
		class PathGoalEvaluator* CreatePathGoalEvaluator(ScriptClass* GoalEvalClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CreatePathGoalEvaluator");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = GoalEvalClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PathGoalEvaluator**)(params + 4);
			free(params);
			return returnVal;
		}
		float GetCollisionHeight()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetCollisionHeight");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		Vector GetCollisionExtent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetCollisionExtent");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		Rotator GetViewRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetViewRotation");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)params;
			free(params);
			return returnVal;
		}
		bool CanGrabLadder()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CanGrabLadder");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool LineOfSightTo(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.LineOfSightTo");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool PickWallAdjust(Vector WallHitNormal, class Actor* HitActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PickWallAdjust");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = WallHitNormal;
			*(class Actor**)(params + 12) = HitActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void LockDesiredRotation(bool Lock, bool InUnlockWhenReached)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.LockDesiredRotation");
			byte* params = (byte*)malloc(8);
			*(bool*)params = Lock;
			*(bool*)(params + 4) = InUnlockWhenReached;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsDesiredRotationLocked()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IsDesiredRotationLocked");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PostInitAnimTree");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void AddAnimSets(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& CustomAnimSets)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.AddAnimSets");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = CustomAnimSets;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			CustomAnimSets = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		void AnimSetListUpdated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.AnimSetListUpdated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool RestoreAnimSetsToDefault()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.RestoreAnimSetsToDefault");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void BeginAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.BeginAnimControl");
			byte* params = (byte*)malloc(4);
			*(class InterpGroup**)params = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MAT_BeginAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.MAT_BeginAnimControl");
			byte* params = (byte*)malloc(4);
			*(class InterpGroup**)params = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FinishAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.FinishAnimControl");
			byte* params = (byte*)malloc(4);
			*(class InterpGroup**)params = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MAT_FinishAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.MAT_FinishAnimControl");
			byte* params = (byte*)malloc(4);
			*(class InterpGroup**)params = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAnimPosition(ScriptName SlotName, int ChannelIndex, ScriptName InAnimSeqName, float InPosition, bool bFireNotifies, bool bLooping, bool bEnableRootMotion)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetAnimPosition");
			byte* params = (byte*)malloc(36);
			*(ScriptName*)params = SlotName;
			*(int*)(params + 8) = ChannelIndex;
			*(ScriptName*)(params + 12) = InAnimSeqName;
			*(float*)(params + 20) = InPosition;
			*(bool*)(params + 24) = bFireNotifies;
			*(bool*)(params + 28) = bLooping;
			*(bool*)(params + 32) = bEnableRootMotion;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MAT_SetAnimPosition(ScriptName SlotName, int ChannelIndex, ScriptName InAnimSeqName, float InPosition, bool bFireNotifies, bool bLooping, bool bEnableRootMotion)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.MAT_SetAnimPosition");
			byte* params = (byte*)malloc(36);
			*(ScriptName*)params = SlotName;
			*(int*)(params + 8) = ChannelIndex;
			*(ScriptName*)(params + 12) = InAnimSeqName;
			*(float*)(params + 20) = InPosition;
			*(bool*)(params + 24) = bFireNotifies;
			*(bool*)(params + 28) = bLooping;
			*(bool*)(params + 32) = bEnableRootMotion;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MAT_SetAnimWeights(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* SlotInfos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.MAT_SetAnimWeights");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = SlotInfos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MAT_SetMorphWeight(ScriptName MorphNodeName, float MorphWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.MAT_SetMorphWeight");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = MorphNodeName;
			*(float*)(params + 8) = MorphWeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MAT_SetSkelControlScale(ScriptName SkelControlName, float Scale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.MAT_SetSkelControlScale");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SkelControlName;
			*(float*)(params + 8) = Scale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InterpolationStarted(class SeqAct_Interp* InterpAction, class InterpGroupInst* GroupInst)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.InterpolationStarted");
			byte* params = (byte*)malloc(8);
			*(class SeqAct_Interp**)params = InterpAction;
			*(class InterpGroupInst**)(params + 4) = GroupInst;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InterpolationFinished(class SeqAct_Interp* InterpAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.InterpolationFinished");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Interp**)params = InterpAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MAT_BeginAIGroup(Vector StartLoc, Rotator StartRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.MAT_BeginAIGroup");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = StartLoc;
			*(Rotator*)(params + 12) = StartRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params;
			free(params);
			return returnVal;
		}
		bool IsActorPlayingFaceFXAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IsActorPlayingFaceFXAnim");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool CanActorPlayFaceFXAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CanActorPlayFaceFXAnim");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void OnPlayFaceFXAnim(class SeqAct_PlayFaceFXAnim* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.OnPlayFaceFXAnim");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_PlayFaceFXAnim**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FaceFXAudioFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.FaceFXAudioFinished");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = AC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class FaceFXAsset* GetActorFaceFXAsset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetActorFaceFXAsset");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class FaceFXAsset**)params;
			free(params);
			return returnVal;
		}
		void SetMorphWeight(ScriptName MorphNodeName, float MorphWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetMorphWeight");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = MorphNodeName;
			*(float*)(params + 8) = MorphWeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSkelControlScale(ScriptName SkelControlName, float Scale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetSkelControlScale");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SkelControlName;
			*(float*)(params + 8) = Scale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsAliveAndWell()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IsAliveAndWell");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		Vector AdjustDestination(class Actor* GoalActor, Vector Dest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.AdjustDestination");
			byte* params = (byte*)malloc(28);
			*(class Actor**)params = GoalActor;
			*(Vector*)(params + 4) = Dest;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 16);
			free(params);
			return returnVal;
		}
		bool SuggestJumpVelocity(Vector& JumpVelocity, Vector Destination, Vector Start, bool bRequireFallLanding)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SuggestJumpVelocity");
			byte* params = (byte*)malloc(44);
			*(Vector*)params = JumpVelocity;
			*(Vector*)(params + 12) = Destination;
			*(Vector*)(params + 24) = Start;
			*(bool*)(params + 36) = bRequireFallLanding;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			JumpVelocity = *(Vector*)params;
			auto returnVal = *(bool*)(params + 40);
			free(params);
			return returnVal;
		}
		float GetFallDuration()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetFallDuration");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		bool IsValidEnemyTargetFor(class PlayerReplicationInfo* PRI, bool bNoPRIisEnemy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IsValidEnemyTargetFor");
			byte* params = (byte*)malloc(12);
			*(class PlayerReplicationInfo**)params = PRI;
			*(bool*)(params + 4) = bNoPRIisEnemy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool IsInvisible()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IsInvisible");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetAnchor(class NavigationPoint* NewAnchor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetAnchor");
			byte* params = (byte*)malloc(4);
			*(class NavigationPoint**)params = NewAnchor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ReachedPoint(Vector Point, class Actor* NewAnchor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ReachedPoint");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = Point;
			*(class Actor**)(params + 12) = NewAnchor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void ForceCrouch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ForceCrouch");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPushesRigidBodies(bool NewPush)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetPushesRigidBodies");
			byte* params = (byte*)malloc(4);
			*(bool*)params = NewPush;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ReachedDesiredRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ReachedDesiredRotation");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void GetBoundingCylinder(float& CollisionRadius, float& CollisionHeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetBoundingCylinder");
			byte* params = (byte*)malloc(8);
			*(float*)params = CollisionRadius;
			*(float*)(params + 4) = CollisionHeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			CollisionRadius = *(float*)params;
			CollisionHeight = *(float*)(params + 4);
			free(params);
		}
		bool InitRagdoll()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.InitRagdoll");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool TermRagdoll()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.TermRagdoll");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool SpecialMoveThruEdge(byte Type, int Dir, Vector MoveStart, Vector MoveDest, class Actor* RelActor, int RelItem)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SpecialMoveThruEdge");
			byte* params = (byte*)malloc(41);
			*params = Type;
			*(int*)(params + 4) = Dir;
			*(Vector*)(params + 8) = MoveStart;
			*(Vector*)(params + 20) = MoveDest;
			*(class Actor**)(params + 32) = RelActor;
			*(int*)(params + 36) = RelItem;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 40);
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.StopFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte GetWeaponFiringMode(class Weapon* InWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetWeaponFiringMode");
			byte* params = (byte*)malloc(5);
			*(class Weapon**)params = InWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 4);
			free(params);
			return returnVal;
		}
		void SetFiringMode(class Weapon* InWeapon, byte InFiringMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetFiringMode");
			byte* params = (byte*)malloc(5);
			*(class Weapon**)params = InWeapon;
			*(params + 4) = InFiringMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FiringModeUpdated(class Weapon* InWeapon, byte InFiringMode, bool bViaReplication)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.FiringModeUpdated");
			byte* params = (byte*)malloc(9);
			*(class Weapon**)params = InWeapon;
			*(params + 4) = InFiringMode;
			*(bool*)(params + 8) = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void IncrementFlashCount(class Weapon* InWeapon, byte InFiringMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IncrementFlashCount");
			byte* params = (byte*)malloc(5);
			*(class Weapon**)params = InWeapon;
			*(params + 4) = InFiringMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FlashCountUpdated(class Weapon* InWeapon, byte InFlashCount, bool bViaReplication)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.FlashCountUpdated");
			byte* params = (byte*)malloc(9);
			*(class Weapon**)params = InWeapon;
			*(params + 4) = InFlashCount;
			*(bool*)(params + 8) = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearFlashCount(class Weapon* InWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ClearFlashCount");
			byte* params = (byte*)malloc(4);
			*(class Weapon**)params = InWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFlashLocation(class Weapon* InWeapon, byte InFiringMode, Vector NewLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetFlashLocation");
			byte* params = (byte*)malloc(17);
			*(class Weapon**)params = InWeapon;
			*(params + 4) = InFiringMode;
			*(Vector*)(params + 8) = NewLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearFlashLocation(class Weapon* InWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ClearFlashLocation");
			byte* params = (byte*)malloc(4);
			*(class Weapon**)params = InWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FlashLocationUpdated(class Weapon* InWeapon, Vector InFlashLocation, bool bViaReplication)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.FlashLocationUpdated");
			byte* params = (byte*)malloc(20);
			*(class Weapon**)params = InWeapon;
			*(Vector*)(params + 4) = InFlashLocation;
			*(bool*)(params + 16) = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void WeaponFired(class Weapon* InWeapon, bool bViaReplication, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.WeaponFired");
			byte* params = (byte*)malloc(20);
			*(class Weapon**)params = InWeapon;
			*(bool*)(params + 4) = bViaReplication;
			*(Vector*)(params + 8) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void WeaponStoppedFiring(class Weapon* InWeapon, bool bViaReplication)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.WeaponStoppedFiring");
			byte* params = (byte*)malloc(8);
			*(class Weapon**)params = InWeapon;
			*(bool*)(params + 4) = bViaReplication;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool BotFire(bool bFinished)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.BotFire");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bFinished;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CanAttack(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CanAttack");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool TooCloseToAttack(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.TooCloseToAttack");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool FireOnRelease()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.FireOnRelease");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool HasRangedAttack()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.HasRangedAttack");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsFiring()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IsFiring");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool NeedToTurn(Vector targ)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.NeedToTurn");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = targ;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void PlayTeleportEffect(bool bOut, bool bSound)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PlayTeleportEffect");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bOut;
			*(bool*)(params + 4) = bSound;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyTeamChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.NotifyTeamChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PossessedBy(class Controller* C, bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PossessedBy");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = C;
			*(bool*)(params + 4) = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateControllerOnPossess(bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.UpdateControllerOnPossess");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		float RangedAttackTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.RangedAttackTime");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void SetWalking(bool bNewIsWalking)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetWalking");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewIsWalking;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CanSplash()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CanSplash");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void EndClimbLadder(class LadderVolume* OldLadder)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.EndClimbLadder");
			byte* params = (byte*)malloc(4);
			*(class LadderVolume**)params = OldLadder;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClimbLadder(class LadderVolume* L)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ClimbLadder");
			byte* params = (byte*)malloc(4);
			*(class LadderVolume**)params = L;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.DisplayDebug");
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = out_YL;
			*(float*)(params + 8) = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_YL = *(float*)(params + 4);
			out_YPos = *(float*)(params + 8);
			free(params);
		}
		bool IsFirstPerson()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IsFirstPerson");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ProcessViewRotation(float DeltaTime, Rotator& out_ViewRotation, Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ProcessViewRotation");
			byte* params = (byte*)malloc(28);
			*(float*)params = DeltaTime;
			*(Rotator*)(params + 4) = out_ViewRotation;
			*(Rotator*)(params + 16) = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_ViewRotation = *(Rotator*)(params + 4);
			out_DeltaRot = *(Rotator*)(params + 16);
			free(params);
		}
		void GetActorEyesViewPoint(Vector& out_Location, Rotator& out_Rotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetActorEyesViewPoint");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = out_Location;
			*(Rotator*)(params + 12) = out_Rotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_Location = *(Vector*)params;
			out_Rotation = *(Rotator*)(params + 12);
			free(params);
		}
		Vector GetPawnViewLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetPawnViewLocation");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		Vector GetWeaponStartTraceLocation(class Weapon* CurrentWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetWeaponStartTraceLocation");
			byte* params = (byte*)malloc(16);
			*(class Weapon**)params = CurrentWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 4);
			free(params);
			return returnVal;
		}
		bool InFreeCam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.InFreeCam");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		Rotator GetAdjustedAimFor(class Weapon* W, Vector StartFireLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetAdjustedAimFor");
			byte* params = (byte*)malloc(28);
			*(class Weapon**)params = W;
			*(Vector*)(params + 4) = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 16);
			free(params);
			return returnVal;
		}
		void SetViewRotation(Rotator NewRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetViewRotation");
			byte* params = (byte*)malloc(12);
			*(Rotator*)params = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetMoveTarget(class Actor* NewTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetMoveTarget");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = NewTarget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HandlePickup(class Inventory* Inv)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.HandlePickup");
			byte* params = (byte*)malloc(4);
			*(class Inventory**)params = Inv;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientMessage(ScriptArray<wchar_t> S, ScriptName Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ClientMessage");
			byte* params = (byte*)malloc(20);
			*(ScriptArray<wchar_t>*)params = S;
			*(ScriptName*)(params + 12) = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.FellOutOfWorld");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(bool*)params = bCrouch;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EndCrouch(float HeightAdjust)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.EndCrouch");
			byte* params = (byte*)malloc(4);
			*(float*)params = HeightAdjust;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartCrouch(float HeightAdjust)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.StartCrouch");
			byte* params = (byte*)malloc(4);
			*(float*)params = HeightAdjust;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HandleMomentum(Vector Momentum, Vector HitLocation, ScriptClass* DamageType, TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.HandleMomentum");
			byte* params = (byte*)malloc(56);
			*(Vector*)params = Momentum;
			*(Vector*)(params + 12) = HitLocation;
			*(ScriptClass**)(params + 24) = DamageType;
			*(TraceHitInfo*)(params + 28) = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddVelocity(Vector NewVelocity, Vector HitLocation, ScriptClass* DamageType, TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.AddVelocity");
			byte* params = (byte*)malloc(56);
			*(Vector*)params = NewVelocity;
			*(Vector*)(params + 12) = HitLocation;
			*(ScriptClass**)(params + 24) = DamageType;
			*(TraceHitInfo*)(params + 28) = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void KilledBy(class Pawn* EventInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.KilledBy");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void ClientSetRotation(Rotator NewRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ClientSetRotation");
			byte* params = (byte*)malloc(12);
			*(Rotator*)params = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdatePawnRotation(Rotator NewRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.UpdatePawnRotation");
			byte* params = (byte*)malloc(12);
			*(Rotator*)params = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FaceRotation(Rotator NewRotation, float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.FaceRotation");
			byte* params = (byte*)malloc(16);
			*(Rotator*)params = NewRotation;
			*(float*)(params + 12) = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool EncroachingOn(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.EncroachingOn");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void EncroachedBy(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.EncroachedBy");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void gibbedBy(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.gibbedBy");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void JumpOffPawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.JumpOffPawn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StuckOnPawn(class Pawn* OtherPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.StuckOnPawn");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = OtherPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BaseChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.BaseChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanBeBaseForPawn(class Pawn* aPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CanBeBaseForPawn");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void CrushedBy(class Pawn* OtherPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CrushedBy");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = OtherPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DetachFromController(bool bDestroyController)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.DetachFromController");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bDestroyController;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(class SequenceEvent**)params = Evt;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnAssignController(class SeqAct_AssignController* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.OnAssignController");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_AssignController**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnGiveInventory(class SeqAct_GiveInventory* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.OnGiveInventory");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_GiveInventory**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void AdjustDamage(int& InDamage, Vector& Momentum, class Controller* InstigatedBy, Vector HitLocation, ScriptClass* DamageType, TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.AdjustDamage");
			byte* params = (byte*)malloc(68);
			*(int*)params = InDamage;
			*(Vector*)(params + 4) = Momentum;
			*(class Controller**)(params + 16) = InstigatedBy;
			*(Vector*)(params + 20) = HitLocation;
			*(ScriptClass**)(params + 32) = DamageType;
			*(TraceHitInfo*)(params + 36) = HitInfo;
			*(class Actor**)(params + 64) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			InDamage = *(int*)params;
			Momentum = *(Vector*)(params + 4);
			free(params);
		}
		bool HealDamage(int Amount, class Controller* Healer, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.HealDamage");
			byte* params = (byte*)malloc(16);
			*(int*)params = Amount;
			*(class Controller**)(params + 4) = Healer;
			*(ScriptClass**)(params + 8) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void PruneDamagedBoneList(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Bones)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PruneDamagedBoneList");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = Bones;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Bones = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		bool TakeRadiusDamageOnBones(class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* Bones)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.TakeRadiusDamageOnBones");
			byte* params = (byte*)malloc(56);
			*(class Controller**)params = InstigatedBy;
			*(float*)(params + 4) = BaseDamage;
			*(float*)(params + 8) = DamageRadius;
			*(ScriptClass**)(params + 12) = DamageType;
			*(float*)(params + 16) = Momentum;
			*(Vector*)(params + 20) = HurtOrigin;
			*(bool*)(params + 32) = bFullDamage;
			*(class Actor**)(params + 36) = DamageCauser;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 40) = Bones;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 52);
			free(params);
			return returnVal;
		}
		void NotifyTakeHit(class Controller* InstigatedBy, Vector HitLocation, int Damage, ScriptClass* DamageType, Vector Momentum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.NotifyTakeHit");
			byte* params = (byte*)malloc(36);
			*(class Controller**)params = InstigatedBy;
			*(Vector*)(params + 4) = HitLocation;
			*(int*)(params + 16) = Damage;
			*(ScriptClass**)(params + 20) = DamageType;
			*(Vector*)(params + 24) = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Controller* SetKillInstigator(class Controller* InstigatedBy, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetKillInstigator");
			byte* params = (byte*)malloc(12);
			*(class Controller**)params = InstigatedBy;
			*(ScriptClass**)(params + 4) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Controller**)(params + 8);
			free(params);
			return returnVal;
		}
		void TakeDamage(int Damage, class Controller* InstigatedBy, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.TakeDamage");
			byte* params = (byte*)malloc(68);
			*(int*)params = Damage;
			*(class Controller**)(params + 4) = InstigatedBy;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = Momentum;
			*(ScriptClass**)(params + 32) = DamageType;
			*(TraceHitInfo*)(params + 36) = HitInfo;
			*(class Actor**)(params + 64) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte GetTeamNum()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetTeamNum");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		class TeamInfo* GetTeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetTeam");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TeamInfo**)params;
			free(params);
			return returnVal;
		}
		bool IsSameTeam(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IsSameTeam");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
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
		void Landed(Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.Landed");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = HitNormal;
			*(class Actor**)(params + 12) = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TickSpecial(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.TickSpecial");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HeadVolumeChange(class PhysicsVolume* newHeadVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.HeadVolumeChange");
			byte* params = (byte*)malloc(4);
			*(class PhysicsVolume**)params = newHeadVolume;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void PlayHit(float Damage, class Controller* InstigatedBy, Vector HitLocation, ScriptClass* DamageType, Vector Momentum, TraceHitInfo HitInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PlayHit");
			byte* params = (byte*)malloc(64);
			*(float*)params = Damage;
			*(class Controller**)(params + 4) = InstigatedBy;
			*(Vector*)(params + 8) = HitLocation;
			*(ScriptClass**)(params + 20) = DamageType;
			*(Vector*)(params + 24) = Momentum;
			*(TraceHitInfo*)(params + 36) = HitInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void PlayDying(ScriptClass* DamageType, Vector HitLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PlayDying");
			byte* params = (byte*)malloc(16);
			*(ScriptClass**)params = DamageType;
			*(Vector*)(params + 4) = HitLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TornOff()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.TornOff");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayFootStepSound(int FootDown)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PlayFootStepSound");
			byte* params = (byte*)malloc(4);
			*(int*)params = FootDown;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayLanded(float ImpactVel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PlayLanded");
			byte* params = (byte*)malloc(4);
			*(float*)params = ImpactVel;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Vehicle* GetVehicleBase()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetVehicleBase");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Vehicle**)params;
			free(params);
			return returnVal;
		}
		void Suicide()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.Suicide");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartDriving(class Vehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.StartDriving");
			byte* params = (byte*)malloc(4);
			*(class Vehicle**)params = V;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopDriving(class Vehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.StopDriving");
			byte* params = (byte*)malloc(4);
			*(class Vehicle**)params = V;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddDefaultInventory()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.AddDefaultInventory");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawHUD(class HUD* H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.DrawHUD");
			byte* params = (byte*)malloc(4);
			*(class HUD**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ThrowActiveWeapon(bool bDestroyWeap)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.ThrowActiveWeapon");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bDestroyWeap;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TossInventory(class Inventory* Inv, Vector ForceVelocity)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.TossInventory");
			byte* params = (byte*)malloc(16);
			*(class Inventory**)params = Inv;
			*(Vector*)(params + 4) = ForceVelocity;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetActiveWeapon(class Weapon* NewWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetActiveWeapon");
			byte* params = (byte*)malloc(4);
			*(class Weapon**)params = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayWeaponSwitch(class Weapon* OldWeapon, class Weapon* NewWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.PlayWeaponSwitch");
			byte* params = (byte*)malloc(8);
			*(class Weapon**)params = OldWeapon;
			*(class Weapon**)(params + 4) = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetCollisionRadius()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetCollisionRadius");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		bool IsStationary()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IsStationary");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SpawnedByKismet()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SpawnedByKismet");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DoKismetAttachment(class Actor* Attachment, class SeqAct_AttachToActor* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.DoKismetAttachment");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Attachment;
			*(class SeqAct_AttachToActor**)(params + 4) = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetDamageScaling()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.GetDamageScaling");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void OnSetMaterial(class SeqAct_SetMaterial* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.OnSetMaterial");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_SetMaterial**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnTeleport(class SeqAct_Teleport* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.OnTeleport");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Teleport**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MessagePlayer(ScriptArray<wchar_t> msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.MessagePlayer");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BecomeViewTarget(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.BecomeViewTarget");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(class PathConstraint**)params = Constraint;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddGoalEvaluator(class PathGoalEvaluator* Evaluator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.AddGoalEvaluator");
			byte* params = (byte*)malloc(4);
			*(class PathGoalEvaluator**)params = Evaluator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class PathConstraint* CreatePathConstraint(ScriptClass* ConstraintClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CreatePathConstraint");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = ConstraintClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PathConstraint**)(params + 4);
			free(params);
			return returnVal;
		}
		void IncrementPathStep(int Cnt, class Canvas* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IncrementPathStep");
			byte* params = (byte*)malloc(8);
			*(int*)params = Cnt;
			*(class Canvas**)(params + 4) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void IncrementPathChild(int Cnt, class Canvas* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.IncrementPathChild");
			byte* params = (byte*)malloc(8);
			*(int*)params = Cnt;
			*(class Canvas**)(params + 4) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawPathStep(class Canvas* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.DrawPathStep");
			byte* params = (byte*)malloc(4);
			*(class Canvas**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(bool*)params = bInCinematicMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetRootMotionInterpCurrentTime(float inTime, float DeltaTime, bool bUpdateSkelPose)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.SetRootMotionInterpCurrentTime");
			byte* params = (byte*)malloc(12);
			*(float*)params = inTime;
			*(float*)(params + 4) = DeltaTime;
			*(bool*)(params + 8) = bUpdateSkelPose;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Speak(class SoundCue* Cue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.Speak");
			byte* params = (byte*)malloc(4);
			*(class SoundCue**)params = Cue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnSetVelocity(class SeqAct_SetVelocity* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.OnSetVelocity");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_SetVelocity**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CheckClotheslineDamage(class Pawn* PawnHittingMe)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Pawn.CheckClotheslineDamage");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = PawnHittingMe;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
