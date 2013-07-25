#pragma once
#include "Engine__InterpActor.h"
#include "Engine__CoverLink.h"
#include "Engine__Actor.h"
#include "Engine__NavigationPoint.h"
#include "Engine__Pawn.h"
#include "Engine__SoundCue.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__ReachSpec.h"
#include "Engine__NavigationHandle.h"
#include "Engine__FaceFXAnimSet.h"
#include "Engine__HUD.h"
#include "Engine__InterpGroup.h"
#include "Engine__SeqAct_Possess.h"
#include "Engine__Projectile.h"
#include "Engine__Weapon.h"
#include "Engine__Inventory.h"
#include "Engine__LiftCenter.h"
#include "Engine__PhysicsVolume.h"
#include "Engine__SeqAct_Teleport.h"
#include "Engine__SeqAct_ToggleGodMode.h"
#include "Engine__SeqAct_SetPhysics.h"
#include "Engine__SeqAct_SetVelocity.h"
#include "Engine__SeqAct_ModifyHealth.h"
#include "Engine__SeqAct_ToggleHidden.h"
#include "Engine__SeqAct_Interp.h"
#include "Engine__InterpGroupInst.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Controller." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Controller." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Controller." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Controller : public Actor
	{
	public:
		ADD_OBJECT(Pawn, Pawn)
		ADD_OBJECT(PlayerReplicationInfo, PlayerReplicationInfo)
		ADD_VAR(::BoolProperty, bGodMode, 0x2)
		ADD_STRUCT(::VectorProperty, NavMeshPath_SearchExtent_Modifier, 0xFFFFFFFF
		ADD_STRUCT(::RotatorProperty, OldBasedRotation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, LaneOffset, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, Enemy)
		ADD_VAR(::FloatProperty, MaxMoveTowardPawnTargetTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, HighJumpNodeCostModifier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InUseNodeCostMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SightCounterInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SightCounter, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, FailedReachLocation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, FailedReachTime, 0xFFFFFFFF)
		ADD_OBJECT(Actor, LastFailedReach)
		ADD_OBJECT(Pawn, ShotTarget)
		ADD_STRUCT(::VectorProperty, ViewZ, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, ViewY, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, ViewX, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, GroundPitchTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MoveFailureCount, 0xFFFFFFFF)
		ADD_OBJECT(Actor, FailedMoveTarget)
		ADD_OBJECT(InterpActor, PendingMover)
		ADD_VAR(::FloatProperty, LastRouteFind, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RouteDist, 0xFFFFFFFF)
		ADD_OBJECT(Actor, RouteGoal)
		ADD_STRUCT(::VectorProperty, CurrentPathDir, 0xFFFFFFFF
		ADD_OBJECT(ReachSpec, NextRoutePath)
		ADD_OBJECT(ReachSpec, CurrentPath)
		ADD_OBJECT(NavigationPoint, StartSpot)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.BasedPosition' for the property named 'AdjustPosition'!
		ADD_OBJECT(Actor, GoalList)
		ADD_OBJECT(Actor, Focus)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.BasedPosition' for the property named 'FocalPosition'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.BasedPosition' for the property named 'DestinationPosition'!
		ADD_OBJECT(Actor, MoveTarget)
		ADD_VAR(::FloatProperty, MoveTimer, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, OverrideSearchStart, 0xFFFFFFFF
		ADD_OBJECT(NavigationHandle, NavigationHandle)
		ADD_OBJECT(ScriptClass, NavigationHandleClass)
		ADD_VAR(::FloatProperty, MinHitWall, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, bAltFire, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, bFire, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUsingPathLanes, 0x20000)
		ADD_VAR(::BoolProperty, bSeeFriendly, 0x10000)
		ADD_VAR(::BoolProperty, bPreciseDestination, 0x8000)
		ADD_VAR(::BoolProperty, bNotifyFallingHitWall, 0x4000)
		ADD_VAR(::BoolProperty, bSkipExtraLOSChecks, 0x2000)
		ADD_VAR(::BoolProperty, bLOSflag, 0x1000)
		ADD_VAR(::BoolProperty, bForceStrafe, 0x800)
		ADD_VAR(::BoolProperty, bPreparingMove, 0x400)
		ADD_VAR(::BoolProperty, bAdjusting, 0x200)
		ADD_VAR(::BoolProperty, bCanDoSpecial, 0x100)
		ADD_VAR(::BoolProperty, bAdvancedTactics, 0x80)
		ADD_VAR(::BoolProperty, bOverrideSearchStart, 0x40)
		ADD_VAR(::BoolProperty, bNotifyApex, 0x20)
		ADD_VAR(::BoolProperty, bNotifyPostLanded, 0x10)
		ADD_VAR(::BoolProperty, bSlowerZAcquire, 0x8)
		ADD_VAR(::BoolProperty, bSoaking, 0x4)
		ADD_VAR(::BoolProperty, bIsPlayer, 0x1)
		ADD_OBJECT(Controller, NextController)
		ADD_VAR(::IntProperty, PlayerNum, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IInterface_NavigationHandle'!
		// Here lies the not-yet-implemented method 'IsLocalPlayerController'
		// Here lies the not-yet-implemented method 'RouteCache_Empty'
		// Here lies the not-yet-implemented method 'RouteCache_AddItem'
		// Here lies the not-yet-implemented method 'RouteCache_InsertItem'
		// Here lies the not-yet-implemented method 'RouteCache_RemoveItem'
		// Here lies the not-yet-implemented method 'RouteCache_RemoveIndex'
		// Here lies the not-yet-implemented method 'SetFocalPoint'
		// Here lies the not-yet-implemented method 'GetFocalPoint'
		// Here lies the not-yet-implemented method 'SetDestinationPosition'
		// Here lies the not-yet-implemented method 'GetDestinationPosition'
		// Here lies the not-yet-implemented method 'SetAdjustLocation'
		// Here lies the not-yet-implemented method 'GetAdjustLocation'
		// Here lies the not-yet-implemented method 'NotifyPathChanged'
		// Here lies the not-yet-implemented method 'BeginAnimControl'
		// Here lies the not-yet-implemented method 'SetAnimPosition'
		// Here lies the not-yet-implemented method 'FinishAnimControl'
		// Here lies the not-yet-implemented method 'PlayActorFaceFXAnim'
		// Here lies the not-yet-implemented method 'StopActorFaceFXAnim'
		// Here lies the not-yet-implemented method 'SetMorphWeight'
		// Here lies the not-yet-implemented method 'SetSkelControlScale'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'ClientSetLocation'
		// Here lies the not-yet-implemented method 'ClientSetRotation'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'OnPossess'
		// Here lies the not-yet-implemented method 'Possess'
		// Here lies the not-yet-implemented method 'UnPossess'
		// Here lies the not-yet-implemented method 'PawnDied'
		// Here lies the not-yet-implemented method 'GamePlayEndedState'
		// Here lies the not-yet-implemented method 'NotifyPostLanded'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'CleanupPRI'
		// Here lies the not-yet-implemented method 'Restart'
		// Here lies the not-yet-implemented method 'BeyondFogDistance'
		// Here lies the not-yet-implemented method 'EnemyJustTeleported'
		// Here lies the not-yet-implemented method 'NotifyTakeHit'
		// Here lies the not-yet-implemented method 'InitPlayerReplicationInfo'
		// Here lies the not-yet-implemented method 'GetTeamNum'
		// Here lies the not-yet-implemented method 'ServerRestartPlayer'
		// Here lies the not-yet-implemented method 'ServerGivePawn'
		// Here lies the not-yet-implemented method 'SetCharacter'
		// Here lies the not-yet-implemented method 'GameHasEnded'
		// Here lies the not-yet-implemented method 'NotifyKilled'
		// Here lies the not-yet-implemented method 'NotifyProjLanded'
		// Here lies the not-yet-implemented method 'WarnProjExplode'
		// Here lies the not-yet-implemented method 'RatePickup'
		// Here lies the not-yet-implemented method 'FireWeaponAt'
		// Here lies the not-yet-implemented method 'StopFiring'
		// Here lies the not-yet-implemented method 'RoundHasEnded'
		// Here lies the not-yet-implemented method 'HandlePickup'
		// Here lies the not-yet-implemented method 'GetAdjustedAimFor'
		// Here lies the not-yet-implemented method 'InstantWarnTarget'
		// Here lies the not-yet-implemented method 'ReceiveWarning'
		// Here lies the not-yet-implemented method 'ReceiveProjectileWarning'
		// Here lies the not-yet-implemented method 'SwitchToBestWeapon'
		// Here lies the not-yet-implemented method 'ClientSwitchToBestWeapon'
		// Here lies the not-yet-implemented method 'NotifyChangedWeapon'
		// Here lies the not-yet-implemented method 'LineOfSightTo'
		// Here lies the not-yet-implemented method 'CanSee'
		// Here lies the not-yet-implemented method 'CanSeeByPoints'
		// Here lies the not-yet-implemented method 'PickTarget'
		// Here lies the not-yet-implemented method 'HearNoise'
		// Here lies the not-yet-implemented method 'SeePlayer'
		// Here lies the not-yet-implemented method 'SeeMonster'
		// Here lies the not-yet-implemented method 'EnemyNotVisible'
		// Here lies the not-yet-implemented method 'MoveTo'
		// Here lies the not-yet-implemented method 'MoveToDirectNonPathPos'
		// Here lies the not-yet-implemented method 'MoveToward'
		// Here lies the not-yet-implemented method 'SetupSpecialPathAbilities'
		// Here lies the not-yet-implemented method 'FinishRotation'
		// Here lies the not-yet-implemented method 'FindPathTo'
		// Here lies the not-yet-implemented method 'FindPathToward'
		// Here lies the not-yet-implemented method 'FindPathTowardNearest'
		// Here lies the not-yet-implemented method 'FindRandomDest'
		// Here lies the not-yet-implemented method 'FindPathToIntercept'
		// Here lies the not-yet-implemented method 'PointReachable'
		// Here lies the not-yet-implemented method 'ActorReachable'
		// Here lies the not-yet-implemented method 'MoveUnreachable'
		// Here lies the not-yet-implemented method 'PickWallAdjust'
		// Here lies the not-yet-implemented method 'WaitForLanding'
		// Here lies the not-yet-implemented method 'LongFall'
		// Here lies the not-yet-implemented method 'EndClimbLadder'
		// Here lies the not-yet-implemented method 'MayFall'
		// Here lies the not-yet-implemented method 'AllowDetourTo'
		// Here lies the not-yet-implemented method 'WaitForMover'
		// Here lies the not-yet-implemented method 'MoverFinished'
		// Here lies the not-yet-implemented method 'UnderLift'
		// Here lies the not-yet-implemented method 'HandlePathObstruction'
		// Here lies the not-yet-implemented method 'GetPlayerViewPoint'
		// Here lies the not-yet-implemented method 'GetActorEyesViewPoint'
		// Here lies the not-yet-implemented method 'IsAimingAt'
		// Here lies the not-yet-implemented method 'LandingShake'
		// Here lies the not-yet-implemented method 'NotifyPhysicsVolumeChange'
		// Here lies the not-yet-implemented method 'NotifyHeadVolumeChange'
		// Here lies the not-yet-implemented method 'NotifyLanded'
		// Here lies the not-yet-implemented method 'NotifyHitWall'
		// Here lies the not-yet-implemented method 'NotifyFallingHitWall'
		// Here lies the not-yet-implemented method 'NotifyBump'
		// Here lies the not-yet-implemented method 'NotifyJumpApex'
		// Here lies the not-yet-implemented method 'NotifyMissedJump'
		// Here lies the not-yet-implemented method 'ReachedPreciseDestination'
		// Here lies the not-yet-implemented method 'InLatentExecution'
		// Here lies the not-yet-implemented method 'StopLatentExecution'
		// Here lies the not-yet-implemented method 'DisplayDebug'
		// Here lies the not-yet-implemented method 'GetHumanReadableName'
		// Here lies the not-yet-implemented method 'IsDead'
		// Here lies the not-yet-implemented method 'OnTeleport'
		// Here lies the not-yet-implemented method 'OnToggleGodMode'
		// Here lies the not-yet-implemented method 'OnSetPhysics'
		// Here lies the not-yet-implemented method 'OnSetVelocity'
		// Here lies the not-yet-implemented method 'NotifyCoverDisabled'
		// Here lies the not-yet-implemented method 'NotifyCoverAdjusted'
		// Here lies the not-yet-implemented method 'NotifyCoverClaimViolation'
		// Here lies the not-yet-implemented method 'OnModifyHealth'
		// Here lies the not-yet-implemented method 'NotifyAddInventory'
		// Here lies the not-yet-implemented method 'OnToggleHidden'
		// Here lies the not-yet-implemented method 'IsSpectating'
		// Here lies the not-yet-implemented method 'IsInCombat'
		// Here lies the not-yet-implemented method 'CurrentLevelUnloaded'
		// Here lies the not-yet-implemented method 'SendMessage'
		// Here lies the not-yet-implemented method 'ReadyForLift'
		// Here lies the not-yet-implemented method 'InitNavigationHandle'
		// Here lies the not-yet-implemented method 'InterpolationStarted'
		// Here lies the not-yet-implemented method 'InterpolationFinished'
		// Here lies the not-yet-implemented method 'GeneratePathToActor'
		// Here lies the not-yet-implemented method 'GeneratePathToLocation'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
