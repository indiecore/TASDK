#pragma once
#include "UTGame__UTSeqAct_AIStopFire.h"
#include "UDKBase__UDKBot.h"
#include "UTGame__UTAvoidMarker.h"
#include "Engine__Actor.h"
#include "UTGame__UTDefensePoint.h"
#include "Engine__NavigationPoint.h"
#include "Engine__Pawn.h"
#include "Engine__Controller.h"
#include "Engine__Weapon.h"
#include "Engine__Inventory.h"
#include "Engine__InterpActor.h"
#include "UTGame__UTSeqAct_AIStartFireAt.h"
#include "Engine__HUD.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__PhysicsVolume.h"
#include "Engine__Vehicle.h"
#include "Engine__Projectile.h"
#include "Engine__PickupFactory.h"
#include "UDKBase__UDKVehicle.h"
#include "UTGame__UTPickupFactory.h"
#include "UTGame__UTSeqAct_AIFreeze.h"
#include "Engine__LiftCenter.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTBot." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTBot." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTBot." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTBot : public UDKBot
	{
	public:
		ADD_OBJECT(Actor, NoVehicleGoal)
		ADD_STRUCT(::VectorProperty, DirectionHint, 0xFFFFFFFF
		ADD_OBJECT(ScriptClass, KilledVehicleClass)
		ADD_VAR(::BoolProperty, bHuntPlayer, 0x1)
		ADD_OBJECT(ScriptClass, FavoriteWeapon)
		ADD_OBJECT(UTDefensePoint, DefensePoint)
		ADD_VAR(::BoolProperty, bJustLanded, 0x8000)
		ADD_VAR(::StrProperty, GoalString, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastInjuredVoiceMessageTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastCanAttackCheckTime, 0xFFFFFFFF)
		ADD_OBJECT(Actor, LastFireTarget)
		ADD_VAR(::FloatProperty, LastTryHoverboardTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastActionMusicUpdate, 0xFFFFFFFF)
		ADD_OBJECT(Actor, ScriptedTarget)
		ADD_STRUCT(::VectorProperty, LastKillerPosition, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, LastKnownPosition, 0xFFFFFFFF
		ADD_OBJECT(Controller, OldOrderGiver)
		ADD_VAR(::NameProperty, OldOrders, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, OrderNames, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, GatherTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastFireAttempt, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumRandomJumps, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CampTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastSearchWeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastSearchTime, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, FailedHuntEnemy)
		ADD_VAR(::FloatProperty, FailedHuntTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastRespawnTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StopStartTime, 0xFFFFFFFF)
		ADD_OBJECT(NavigationPoint, DefensivePosition)
		ADD_VAR(::FloatProperty, ReTaskTime, 0xFFFFFFFF)
		ADD_OBJECT(UTBot, NextSquadMember)
		ADD_VAR(::StrProperty, SoakString, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldMessageTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Jumpiness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ReactionTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Tactics, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CombatStyle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StrafingAbility, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BaseAggressiveness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Accuracy, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BaseAlertness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForcedFlagDropTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RetreatStartTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastUnderFire, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StartTacticalTime, 0xFFFFFFFF)
		ADD_OBJECT(Actor, StartleActor)
		ADD_VAR(::FloatProperty, LoseEnemyCheckTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Aggression, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AcquireTime, 0xFFFFFFFF)
		ADD_OBJECT(NavigationPoint, BlockedPath)
		ADD_VAR(::FloatProperty, LastAttractCheck, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Aggressiveness, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, HidingSpot, 0xFFFFFFFF
		ADD_VAR(::IntProperty, LastTauntIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, OldMessageID, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, OldMessageType, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxSpecialJumpZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ImpactJumpZ, 0xFFFFFFFF)
		ADD_OBJECT(Actor, ImpactTarget)
		ADD_VAR(::BoolProperty, bResetCombatTimer, 0x40000000)
		ADD_VAR(::BoolProperty, bCheckDriverPickups, 0x20000000)
		ADD_VAR(::BoolProperty, bDirectHunt, 0x10000000)
		ADD_VAR(::BoolProperty, bFinalStretch, 0x8000000)
		ADD_VAR(::BoolProperty, bSpawnedByKismet, 0x4000000)
		ADD_VAR(::BoolProperty, bBetrayTeam, 0x2000000)
		ADD_VAR(::BoolProperty, bShortCamp, 0x1000000)
		ADD_VAR(::BoolProperty, bForceNoDetours, 0x800000)
		ADD_VAR(::BoolProperty, bSendFlagMessage, 0x400000)
		ADD_VAR(::BoolProperty, bScriptedFrozen, 0x200000)
		ADD_VAR(::BoolProperty, bAllowedToImpactJump, 0x100000)
		ADD_VAR(::BoolProperty, bPendingDoubleJump, 0x80000)
		ADD_VAR(::BoolProperty, bHasSuperWeapon, 0x40000)
		ADD_VAR(::BoolProperty, bIgnoreEnemyChange, 0x20000)
		ADD_VAR(::BoolProperty, bRecommendFastMove, 0x10000)
		ADD_VAR(::BoolProperty, bPursuingFlag, 0x4000)
		ADD_VAR(::BoolProperty, bMustCharge, 0x2000)
		ADD_VAR(::BoolProperty, bStoppedFiring, 0x1000)
		ADD_VAR(::BoolProperty, bFireSuccess, 0x800)
		ADD_VAR(::BoolProperty, bForcedDirection, 0x400)
		ADD_VAR(::BoolProperty, bHasFired, 0x200)
		ADD_VAR(::BoolProperty, bWasNearObjective, 0x100)
		ADD_VAR(::BoolProperty, bTacticalDoubleJump, 0x80)
		ADD_VAR(::BoolProperty, bReachedGatherPoint, 0x40)
		ADD_VAR(::BoolProperty, bInitLifeMessage, 0x20)
		ADD_VAR(::BoolProperty, bFrustrated, 0x10)
		ADD_VAR(::BoolProperty, bChangeDir, 0x8)
		ADD_VAR(::BoolProperty, bStrafeDir, 0x4)
		ADD_VAR(::BoolProperty, bCanFire, 0x2)
		ADD_VAR(::FloatProperty, LastWarningTime, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, InstantWarningShooter)
		// Here lies the not-yet-implemented method 'GetDirectionHint'
		// Here lies the not-yet-implemented method 'RatePickup'
		// Here lies the not-yet-implemented method 'PriorityObjective'
		// Here lies the not-yet-implemented method 'RateWeapon'
		// Here lies the not-yet-implemented method 'WeaponFireAgain'
		// Here lies the not-yet-implemented method 'NeedWeapon'
		// Here lies the not-yet-implemented method 'DoWaitForLanding'
		// Here lies the not-yet-implemented method 'DelayedLeaveVehicle'
		// Here lies the not-yet-implemented method 'NotifyLanded'
		// Here lies the not-yet-implemented method 'SetFall'
		// Here lies the not-yet-implemented method 'CustomActionFunc'
		// Here lies the not-yet-implemented method 'EnemyJustTeleported'
		// Here lies the not-yet-implemented method 'WasKilledBy'
		// Here lies the not-yet-implemented method 'StartMonitoring'
		// Here lies the not-yet-implemented method 'PawnDied'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'SpawnedByKismet'
		// Here lies the not-yet-implemented method 'LandingShake'
		// Here lies the not-yet-implemented method 'HasTimedPowerup'
		// Here lies the not-yet-implemented method 'NotifyAddInventory'
		// Here lies the not-yet-implemented method 'SetupSpecialPathAbilities'
		// Here lies the not-yet-implemented method 'NotifyHitWall'
		// Here lies the not-yet-implemented method 'FearThisSpot'
		// Here lies the not-yet-implemented method 'Startle'
		// Here lies the not-yet-implemented method 'SetCombatTimer'
		// Here lies the not-yet-implemented method 'CanImpactJump'
		// Here lies the not-yet-implemented method 'TimeDJReset'
		// Here lies the not-yet-implemented method 'ResetDoubleJump'
		// Here lies the not-yet-implemented method 'WaitForMover'
		// Here lies the not-yet-implemented method 'ReadyForLift'
		// Here lies the not-yet-implemented method 'ShouldFireAgain'
		// Here lies the not-yet-implemented method 'TimedFireWeaponAtEnemy'
		// Here lies the not-yet-implemented method 'FireWeaponAt'
		// Here lies the not-yet-implemented method 'CanAttack'
		// Here lies the not-yet-implemented method 'OnAIStartFireAt'
		// Here lies the not-yet-implemented method 'TimedFireWeaponAtScriptedTarget'
		// Here lies the not-yet-implemented method 'StopFiring'
		// Here lies the not-yet-implemented method 'OnAIStopFire'
		// Here lies the not-yet-implemented method 'WeaponPreference'
		// Here lies the not-yet-implemented method 'ProficientWithWeapon'
		// Here lies the not-yet-implemented method 'CanComboMoving'
		// Here lies the not-yet-implemented method 'CanCombo'
		// Here lies the not-yet-implemented method 'DisplayDebug'
		// Here lies the not-yet-implemented method 'GetOrders'
		// Here lies the not-yet-implemented method 'YellAt'
		// Here lies the not-yet-implemented method 'SendMessage'
		// Here lies the not-yet-implemented method 'SetBotOrders'
		// Here lies the not-yet-implemented method 'SetTemporaryOrders'
		// Here lies the not-yet-implemented method 'ClearTemporaryOrders'
		// Here lies the not-yet-implemented method 'HearNoise'
		// Here lies the not-yet-implemented method 'SeePlayer'
		// Here lies the not-yet-implemented method 'SetAttractionState'
		// Here lies the not-yet-implemented method 'ClearShot'
		// Here lies the not-yet-implemented method 'CanStakeOut'
		// Here lies the not-yet-implemented method 'CheckIfShouldCrouch'
		// Here lies the not-yet-implemented method 'IsSniping'
		// Here lies the not-yet-implemented method 'FreePoint'
		// Here lies the not-yet-implemented method 'AssignSquadResponsibility'
		// Here lies the not-yet-implemented method 'RelativeStrength'
		// Here lies the not-yet-implemented method 'SetEnemyInfo'
		// Here lies the not-yet-implemented method 'EnemyChanged'
		// Here lies the not-yet-implemented method 'StrafeFromDamage'
		// Here lies the not-yet-implemented method 'NotifyPhysicsVolumeChange'
		// Here lies the not-yet-implemented method 'MayDodgeToMoveTarget'
		// Here lies the not-yet-implemented method 'NotifyJumpApex'
		// Here lies the not-yet-implemented method 'NotifyMissedJump'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'Possess'
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'ResetSkill'
		// Here lies the not-yet-implemented method 'SetMaxDesiredSpeed'
		// Here lies the not-yet-implemented method 'SetPeripheralVision'
		// Here lies the not-yet-implemented method 'SetAlertness'
		// Here lies the not-yet-implemented method 'WhatToDoNext'
		// Here lies the not-yet-implemented method 'ExecuteWhatToDoNext'
		// Here lies the not-yet-implemented method 'EnterVehicle'
		// Here lies the not-yet-implemented method 'LeaveVehicle'
		// Here lies the not-yet-implemented method 'VehicleFightEnemy'
		// Here lies the not-yet-implemented method 'FightEnemy'
		// Here lies the not-yet-implemented method 'DoRangedAttackOn'
		// Here lies the not-yet-implemented method 'ChooseAttackMode'
		// Here lies the not-yet-implemented method 'FindSuperPickup'
		// Here lies the not-yet-implemented method 'FindInventoryGoal'
		// Here lies the not-yet-implemented method 'TossFlagToPlayer'
		// Here lies the not-yet-implemented method 'PickRetreatDestination'
		// Here lies the not-yet-implemented method 'SoakStop'
		// Here lies the not-yet-implemented method 'FindRoamDest'
		// Here lies the not-yet-implemented method 'Restart'
		// Here lies the not-yet-implemented method 'CheckPathToGoalAround'
		// Here lies the not-yet-implemented method 'ClearPathFor'
		// Here lies the not-yet-implemented method 'AdjustAround'
		// Here lies the not-yet-implemented method 'NotifyBump'
		// Here lies the not-yet-implemented method 'NotifyPostLanded'
		// Here lies the not-yet-implemented method 'TimedDodgeToMoveTarget'
		// Here lies the not-yet-implemented method 'StartMoveToward'
		// Here lies the not-yet-implemented method 'SetRouteToGoal'
		// Here lies the not-yet-implemented method 'AllowDetourTo'
		// Here lies the not-yet-implemented method 'FindBestPathToward'
		// Here lies the not-yet-implemented method 'CheckFutureSight'
		// Here lies the not-yet-implemented method 'AdjustAimError'
		// Here lies the not-yet-implemented method 'GetAdjustedAimFor'
		// Here lies the not-yet-implemented method 'TryDuckTowardsMoveTarget'
		// Here lies the not-yet-implemented method 'DelayedWarning'
		// Here lies the not-yet-implemented method 'ReceiveProjectileWarning'
		// Here lies the not-yet-implemented method 'NotifyTakeHit'
		// Here lies the not-yet-implemented method 'DelayedInstantWarning'
		// Here lies the not-yet-implemented method 'ReceiveWarning'
		// Here lies the not-yet-implemented method 'ReceiveRunOverWarning'
		// Here lies the not-yet-implemented method 'NotifyFallingHitWall'
		// Here lies the not-yet-implemented method 'MissedDodge'
		// Here lies the not-yet-implemented method 'TryWallDodge'
		// Here lies the not-yet-implemented method 'ChangeStrafe'
		// Here lies the not-yet-implemented method 'TryToDuck'
		// Here lies the not-yet-implemented method 'NotifyKilled'
		// Here lies the not-yet-implemented method 'FaceMoveTarget'
		// Here lies the not-yet-implemented method 'ShouldStrafeTo'
		// Here lies the not-yet-implemented method 'FaceActor'
		// Here lies the not-yet-implemented method 'SuperDesireability'
		// Here lies the not-yet-implemented method 'SuperPickupNotSpokenFor'
		// Here lies the not-yet-implemented method 'DamageAttitudeTo'
		// Here lies the not-yet-implemented method 'IsRetreating'
		// Here lies the not-yet-implemented method 'OnAIFreeze'
		// Here lies the not-yet-implemented method 'IsDefending'
		// Here lies the not-yet-implemented method 'ShouldDefendPosition'
		// Here lies the not-yet-implemented method 'MoveToDefensePoint'
		// Here lies the not-yet-implemented method 'MoveAwayFrom'
		// Here lies the not-yet-implemented method 'WanderOrCamp'
		// Here lies the not-yet-implemented method 'EnableBumps'
		// Here lies the not-yet-implemented method 'Celebrate'
		// Here lies the not-yet-implemented method 'ForceGiveWeapon'
		// Here lies the not-yet-implemented method 'GetDesiredOffset'
		// Here lies the not-yet-implemented method 'LostContact'
		// Here lies the not-yet-implemented method 'LoseEnemy'
		// Here lies the not-yet-implemented method 'DoStakeOut'
		// Here lies the not-yet-implemented method 'DoCharge'
		// Here lies the not-yet-implemented method 'DoTacticalMove'
		// Here lies the not-yet-implemented method 'DoRetreat'
		// Here lies the not-yet-implemented method 'DefendMelee'
		// Here lies the not-yet-implemented method 'IsStrafing'
		// Here lies the not-yet-implemented method 'EngageDirection'
		// Here lies the not-yet-implemented method 'IsHunting'
		// Here lies the not-yet-implemented method 'FindViewSpot'
		// Here lies the not-yet-implemented method 'Stopped'
		// Here lies the not-yet-implemented method 'IsShootingObjective'
		// Here lies the not-yet-implemented method 'FocusOnLeader'
		// Here lies the not-yet-implemented method 'StopMovement'
		// Here lies the not-yet-implemented method 'PerformCustomAction'
		// Here lies the not-yet-implemented method 'UnderLift'
		// Here lies the not-yet-implemented method 'HandlePathObstruction'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
