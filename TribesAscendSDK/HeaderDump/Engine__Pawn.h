#pragma once
#include "Engine__SeqAct_AttachToActor.h"
#include "Engine__RB_BodyInstance.h"
#include "Engine__Actor.h"
#include "Engine__NavigationPoint.h"
#include "Engine__Controller.h"
#include "Engine__Inventory.h"
#include "Engine__Weapon.h"
#include "Engine__InventoryManager.h"
#include "Engine__PhysicsVolume.h"
#include "Engine__SeqAct_SetVelocity.h"
#include "Engine__MaterialInstanceConstant.h"
#include "Engine__LadderVolume.h"
#include "Engine__Vehicle.h"
#include "Engine__PlayerStart.h"
#include "Engine__SoundCue.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__PathGoalEvaluator.h"
#include "Engine__TeamInfo.h"
#include "Engine__PathConstraint.h"
#include "Engine__PlayerController.h"
#include "Engine__FaceFXAnimSet.h"
#include "Engine__HUD.h"
#include "Engine__InterpGroup.h"
#include "Engine__SeqAct_Interp.h"
#include "Engine__InterpGroupInst.h"
#include "Engine__SeqAct_PlayFaceFXAnim.h"
#include "Engine__FaceFXAsset.h"
#include "Engine__SequenceEvent.h"
#include "Engine__SeqAct_AssignController.h"
#include "Engine__SeqAct_GiveInventory.h"
#include "Engine__SeqAct_SetMaterial.h"
#include "Engine__SeqAct_Teleport.h"
#include "Engine__Canvas.h"
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
		ADD_OBJECT(ScriptClass, InventoryManagerClass)
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
		ADD_OBJECT(ScriptClass, HitDamageType)
		ADD_STRUCT(::VectorProperty, TakeHitLocation, 0xFFFFFFFF
		ADD_OBJECT(PlayerStart, LastStartSpot)
		ADD_OBJECT(PlayerReplicationInfo, PlayerReplicationInfo)
		ADD_OBJECT(ScriptClass, ControllerClass)
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
		// Here lies the not-yet-implemented method 'IsHumanControlled'
		// Here lies the not-yet-implemented method 'IsLocallyControlled'
		// Here lies the not-yet-implemented method 'PlayActorFaceFXAnim'
		// Here lies the not-yet-implemented method 'StopFiring'
		// Here lies the not-yet-implemented method 'GetBaseAimRotation'
		// Here lies the not-yet-implemented method 'GetHumanReadableName'
		// Here lies the not-yet-implemented method 'Died'
		// Here lies the not-yet-implemented method 'GetDefaultCameraMode'
		// Here lies the not-yet-implemented method 'CanThrowWeapon'
		// Here lies the not-yet-implemented method 'SetDesiredRotation'
		// Here lies the not-yet-implemented method 'DoJump'
		// Here lies the not-yet-implemented method 'SetRemoteViewPitch'
		// Here lies the not-yet-implemented method 'CannotJumpNow'
		// Here lies the not-yet-implemented method 'CheckWaterJump'
		// Here lies the not-yet-implemented method 'TouchingWaterVolume'
		// Here lies the not-yet-implemented method 'ReachedDestination'
		// Here lies the not-yet-implemented method 'SpecialMoveTo'
		// Here lies the not-yet-implemented method 'SetScalarParameterInterp'
		// Here lies the not-yet-implemented method 'CheatFly'
		// Here lies the not-yet-implemented method 'CheatWalk'
		// Here lies the not-yet-implemented method 'CheatGhost'
		// Here lies the not-yet-implemented method 'IsPlayerPawn'
		// Here lies the not-yet-implemented method 'FindInventoryType'
		// Here lies the not-yet-implemented method 'CreateInventory'
		// Here lies the not-yet-implemented method 'InGodMode'
		// Here lies the not-yet-implemented method 'ValidAnchor'
		// Here lies the not-yet-implemented method 'GetBestAnchor'
		// Here lies the not-yet-implemented method 'CreatePathGoalEvaluator'
		// Here lies the not-yet-implemented method 'GetCollisionHeight'
		// Here lies the not-yet-implemented method 'GetCollisionExtent'
		// Here lies the not-yet-implemented method 'GetViewRotation'
		// Here lies the not-yet-implemented method 'CanGrabLadder'
		// Here lies the not-yet-implemented method 'LineOfSightTo'
		// Here lies the not-yet-implemented method 'PickWallAdjust'
		// Here lies the not-yet-implemented method 'LockDesiredRotation'
		// Here lies the not-yet-implemented method 'ResetDesiredRotation'
		// Here lies the not-yet-implemented method 'CheckDesiredRotation'
		// Here lies the not-yet-implemented method 'IsDesiredRotationInUse'
		// Here lies the not-yet-implemented method 'IsDesiredRotationLocked'
		// Here lies the not-yet-implemented method 'PostInitAnimTree'
		// Here lies the not-yet-implemented method 'CacheAnimNodes'
		// Here lies the not-yet-implemented method 'ClearAnimNodes'
		// Here lies the not-yet-implemented method 'UpdateAnimSetList'
		// Here lies the not-yet-implemented method 'BuildScriptAnimSetList'
		// Here lies the not-yet-implemented method 'AddAnimSets'
		// Here lies the not-yet-implemented method 'AnimSetListUpdated'
		// Here lies the not-yet-implemented method 'RestoreAnimSetsToDefault'
		// Here lies the not-yet-implemented method 'BeginAnimControl'
		// Here lies the not-yet-implemented method 'MAT_BeginAnimControl'
		// Here lies the not-yet-implemented method 'FinishAnimControl'
		// Here lies the not-yet-implemented method 'MAT_FinishAnimControl'
		// Here lies the not-yet-implemented method 'SetAnimPosition'
		// Here lies the not-yet-implemented method 'MAT_SetAnimPosition'
		// Here lies the not-yet-implemented method 'MAT_SetAnimWeights'
		// Here lies the not-yet-implemented method 'MAT_SetMorphWeight'
		// Here lies the not-yet-implemented method 'MAT_SetSkelControlScale'
		// Here lies the not-yet-implemented method 'InterpolationStarted'
		// Here lies the not-yet-implemented method 'InterpolationFinished'
		// Here lies the not-yet-implemented method 'MAT_BeginAIGroup'
		// Here lies the not-yet-implemented method 'MAT_FinishAIGroup'
		// Here lies the not-yet-implemented method 'StopActorFaceFXAnim'
		// Here lies the not-yet-implemented method 'GetFaceFXAudioComponent'
		// Here lies the not-yet-implemented method 'IsActorPlayingFaceFXAnim'
		// Here lies the not-yet-implemented method 'CanActorPlayFaceFXAnim'
		// Here lies the not-yet-implemented method 'OnPlayFaceFXAnim'
		// Here lies the not-yet-implemented method 'FaceFXAudioFinished'
		// Here lies the not-yet-implemented method 'GetActorFaceFXAsset'
		// Here lies the not-yet-implemented method 'SetMorphWeight'
		// Here lies the not-yet-implemented method 'SetSkelControlScale'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'IsAliveAndWell'
		// Here lies the not-yet-implemented method 'AdjustDestination'
		// Here lies the not-yet-implemented method 'SuggestJumpVelocity'
		// Here lies the not-yet-implemented method 'GetFallDuration'
		// Here lies the not-yet-implemented method 'IsValidEnemyTargetFor'
		// Here lies the not-yet-implemented method 'IsInvisible'
		// Here lies the not-yet-implemented method 'SetAnchor'
		// Here lies the not-yet-implemented method 'ReachedPoint'
		// Here lies the not-yet-implemented method 'ForceCrouch'
		// Here lies the not-yet-implemented method 'SetPushesRigidBodies'
		// Here lies the not-yet-implemented method 'ReachedDesiredRotation'
		// Here lies the not-yet-implemented method 'GetBoundingCylinder'
		// Here lies the not-yet-implemented method 'InitRagdoll'
		// Here lies the not-yet-implemented method 'TermRagdoll'
		// Here lies the not-yet-implemented method 'SpecialMoveThruEdge'
		// Here lies the not-yet-implemented method 'SetBaseEyeheight'
		// Here lies the not-yet-implemented method 'PlayerChangedTeam'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'StartFire'
		// Here lies the not-yet-implemented method 'StopFire'
		// Here lies the not-yet-implemented method 'GetWeaponFiringMode'
		// Here lies the not-yet-implemented method 'SetFiringMode'
		// Here lies the not-yet-implemented method 'FiringModeUpdated'
		// Here lies the not-yet-implemented method 'IncrementFlashCount'
		// Here lies the not-yet-implemented method 'FlashCountUpdated'
		// Here lies the not-yet-implemented method 'ClearFlashCount'
		// Here lies the not-yet-implemented method 'SetFlashLocation'
		// Here lies the not-yet-implemented method 'ClearFlashLocation'
		// Here lies the not-yet-implemented method 'FlashLocationUpdated'
		// Here lies the not-yet-implemented method 'WeaponFired'
		// Here lies the not-yet-implemented method 'WeaponStoppedFiring'
		// Here lies the not-yet-implemented method 'BotFire'
		// Here lies the not-yet-implemented method 'CanAttack'
		// Here lies the not-yet-implemented method 'TooCloseToAttack'
		// Here lies the not-yet-implemented method 'FireOnRelease'
		// Here lies the not-yet-implemented method 'HasRangedAttack'
		// Here lies the not-yet-implemented method 'IsFiring'
		// Here lies the not-yet-implemented method 'NeedToTurn'
		// Here lies the not-yet-implemented method 'PlayTeleportEffect'
		// Here lies the not-yet-implemented method 'NotifyTeamChanged'
		// Here lies the not-yet-implemented method 'PossessedBy'
		// Here lies the not-yet-implemented method 'UpdateControllerOnPossess'
		// Here lies the not-yet-implemented method 'UnPossessed'
		// Here lies the not-yet-implemented method 'DropToGround'
		// Here lies the not-yet-implemented method 'RecommendLongRangedAttack'
		// Here lies the not-yet-implemented method 'RangedAttackTime'
		// Here lies the not-yet-implemented method 'SetWalking'
		// Here lies the not-yet-implemented method 'CanSplash'
		// Here lies the not-yet-implemented method 'EndClimbLadder'
		// Here lies the not-yet-implemented method 'ClimbLadder'
		// Here lies the not-yet-implemented method 'DisplayDebug'
		// Here lies the not-yet-implemented method 'IsFirstPerson'
		// Here lies the not-yet-implemented method 'ProcessViewRotation'
		// Here lies the not-yet-implemented method 'GetActorEyesViewPoint'
		// Here lies the not-yet-implemented method 'GetPawnViewLocation'
		// Here lies the not-yet-implemented method 'GetWeaponStartTraceLocation'
		// Here lies the not-yet-implemented method 'InFreeCam'
		// Here lies the not-yet-implemented method 'GetAdjustedAimFor'
		// Here lies the not-yet-implemented method 'SetViewRotation'
		// Here lies the not-yet-implemented method 'SetMoveTarget'
		// Here lies the not-yet-implemented method 'HandlePickup'
		// Here lies the not-yet-implemented method 'ClientMessage'
		// Here lies the not-yet-implemented method 'FellOutOfWorld'
		// Here lies the not-yet-implemented method 'OutsideWorldBounds'
		// Here lies the not-yet-implemented method 'UnCrouch'
		// Here lies the not-yet-implemented method 'ShouldCrouch'
		// Here lies the not-yet-implemented method 'EndCrouch'
		// Here lies the not-yet-implemented method 'StartCrouch'
		// Here lies the not-yet-implemented method 'HandleMomentum'
		// Here lies the not-yet-implemented method 'AddVelocity'
		// Here lies the not-yet-implemented method 'KilledBy'
		// Here lies the not-yet-implemented method 'TakeFallingDamage'
		// Here lies the not-yet-implemented method 'Restart'
		// Here lies the not-yet-implemented method 'ClientRestart'
		// Here lies the not-yet-implemented method 'ClientSetRotation'
		// Here lies the not-yet-implemented method 'UpdatePawnRotation'
		// Here lies the not-yet-implemented method 'FaceRotation'
		// Here lies the not-yet-implemented method 'EncroachingOn'
		// Here lies the not-yet-implemented method 'EncroachedBy'
		// Here lies the not-yet-implemented method 'gibbedBy'
		// Here lies the not-yet-implemented method 'JumpOffPawn'
		// Here lies the not-yet-implemented method 'StuckOnPawn'
		// Here lies the not-yet-implemented method 'BaseChange'
		// Here lies the not-yet-implemented method 'CanBeBaseForPawn'
		// Here lies the not-yet-implemented method 'CrushedBy'
		// Here lies the not-yet-implemented method 'DetachFromController'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'PreBeginPlay'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'SpawnDefaultController'
		// Here lies the not-yet-implemented method 'ReceivedNewEvent'
		// Here lies the not-yet-implemented method 'OnAssignController'
		// Here lies the not-yet-implemented method 'OnGiveInventory'
		// Here lies the not-yet-implemented method 'Gasp'
		// Here lies the not-yet-implemented method 'SetMovementPhysics'
		// Here lies the not-yet-implemented method 'AdjustDamage'
		// Here lies the not-yet-implemented method 'HealDamage'
		// Here lies the not-yet-implemented method 'PruneDamagedBoneList'
		// Here lies the not-yet-implemented method 'TakeRadiusDamageOnBones'
		// Here lies the not-yet-implemented method 'NotifyTakeHit'
		// Here lies the not-yet-implemented method 'SetKillInstigator'
		// Here lies the not-yet-implemented method 'TakeDamage'
		// Here lies the not-yet-implemented method 'GetTeamNum'
		// Here lies the not-yet-implemented method 'GetTeam'
		// Here lies the not-yet-implemented method 'IsSameTeam'
		// Here lies the not-yet-implemented method 'ThrowWeaponOnDeath'
		// Here lies the not-yet-implemented method 'DelayTriggerDeath'
		// Here lies the not-yet-implemented method 'Falling'
		// Here lies the not-yet-implemented method 'Landed'
		// Here lies the not-yet-implemented method 'TickSpecial'
		// Here lies the not-yet-implemented method 'HeadVolumeChange'
		// Here lies the not-yet-implemented method 'BreathTimer'
		// Here lies the not-yet-implemented method 'TakeDrowningDamage'
		// Here lies the not-yet-implemented method 'PlayDyingSound'
		// Here lies the not-yet-implemented method 'PlayHit'
		// Here lies the not-yet-implemented method 'TurnOff'
		// Here lies the not-yet-implemented method 'SetDyingPhysics'
		// Here lies the not-yet-implemented method 'PlayDying'
		// Here lies the not-yet-implemented method 'TornOff'
		// Here lies the not-yet-implemented method 'PlayFootStepSound'
		// Here lies the not-yet-implemented method 'PlayLanded'
		// Here lies the not-yet-implemented method 'GetVehicleBase'
		// Here lies the not-yet-implemented method 'Suicide'
		// Here lies the not-yet-implemented method 'StartDriving'
		// Here lies the not-yet-implemented method 'StopDriving'
		// Here lies the not-yet-implemented method 'AddDefaultInventory'
		// Here lies the not-yet-implemented method 'DrawHUD'
		// Here lies the not-yet-implemented method 'ThrowActiveWeapon'
		// Here lies the not-yet-implemented method 'TossInventory'
		// Here lies the not-yet-implemented method 'SetActiveWeapon'
		// Here lies the not-yet-implemented method 'PlayWeaponSwitch'
		// Here lies the not-yet-implemented method 'GetCollisionRadius'
		// Here lies the not-yet-implemented method 'IsStationary'
		// Here lies the not-yet-implemented method 'SpawnedByKismet'
		// Here lies the not-yet-implemented method 'DoKismetAttachment'
		// Here lies the not-yet-implemented method 'GetDamageScaling'
		// Here lies the not-yet-implemented method 'OnSetMaterial'
		// Here lies the not-yet-implemented method 'OnTeleport'
		// Here lies the not-yet-implemented method 'MessagePlayer'
		// Here lies the not-yet-implemented method 'BecomeViewTarget'
		// Here lies the not-yet-implemented method 'SoakPause'
		// Here lies the not-yet-implemented method 'ClearConstraints'
		// Here lies the not-yet-implemented method 'AddPathConstraint'
		// Here lies the not-yet-implemented method 'AddGoalEvaluator'
		// Here lies the not-yet-implemented method 'CreatePathConstraint'
		// Here lies the not-yet-implemented method 'IncrementPathStep'
		// Here lies the not-yet-implemented method 'IncrementPathChild'
		// Here lies the not-yet-implemented method 'DrawPathStep'
		// Here lies the not-yet-implemented method 'ClearPathStep'
		// Here lies the not-yet-implemented method 'ZeroMovementVariables'
		// Here lies the not-yet-implemented method 'SetCinematicMode'
		// Here lies the not-yet-implemented method 'SetRootMotionInterpCurrentTime'
		// Here lies the not-yet-implemented method 'Speak'
		// Here lies the not-yet-implemented method 'OnSetVelocity'
		// Here lies the not-yet-implemented method 'CheckClotheslineDamage'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
