#pragma once
#include "UDKBase__UDKBot.h"
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
		ADD_VAR(::BoolProperty, bHuntPlayer, 0x1)
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
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
