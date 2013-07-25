#pragma once
#include "Engine__Actor.h"
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
		ADD_STRUCT(::VectorProperty, Floor, 0xFFFFFFFF
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
		// WARNING: Unknown structure type 'ScriptStruct Engine.Pawn.LastHitInfoStruct' for the property named 'LastHitInfo'!
		ADD_STRUCT(::VectorProperty, RootMotionInterpCurveLastValue, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, RootMotionInterpCurrentTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RootMotionInterpRate, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.EngineTypes.RootMotionCurve' for the property named 'RootMotionInterpCurve'!
		ADD_OBJECT(MaterialInstanceConstant, MIC_PawnHair)
		ADD_OBJECT(MaterialInstanceConstant, MIC_PawnMat)
		ADD_VAR(::IntProperty, FailedLandingCount, 0xFFFFFFFF)
		ADD_OBJECT(RB_BodyInstance, PhysicsPushBody)
		ADD_VAR(::IntProperty, ShotCount, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LastFiringFlashLocation, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, FlashLocation, 0xFFFFFFFF
		ADD_STRUCT(::RotatorProperty, DesiredRotation, 0xFFFFFFFF
		ADD_VAR(::IntProperty, AllowedYawError, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ViewPitchMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ViewPitchMin, 0xFFFFFFFF)
		ADD_OBJECT(Controller, LastHitBy)
		ADD_VAR(::FloatProperty, AlwaysRelevantDistanceSquared, 0xFFFFFFFF)
		ADD_OBJECT(Vehicle, DrivenVehicle)
		ADD_VAR(::FloatProperty, RBPushStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RBPushRadius, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, TearOffMomentum, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, TakeHitLocation, 0xFFFFFFFF
		ADD_OBJECT(PlayerStart, LastStartSpot)
		ADD_OBJECT(PlayerReplicationInfo, PlayerReplicationInfo)
		ADD_VAR(::StrProperty, MenuName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DamageScaling, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SoundDampening, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, noise2loudness, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, noise2other)
		ADD_VAR(::FloatProperty, noise2time, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, noise2spot, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, noise1loudness, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, noise1other)
		ADD_VAR(::FloatProperty, noise1time, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, noise1spot, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, RMVelocity, 0xFFFFFFFF
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
		ADD_STRUCT(::VectorProperty, SerpentineDir, 0xFFFFFFFF
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
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IInterface_Speaker'!
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
		ADD_STRUCT(::VectorProperty, PartialLedgeMoveDir, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, LedgeCheckThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WalkableFloorZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxJumpHeight, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
