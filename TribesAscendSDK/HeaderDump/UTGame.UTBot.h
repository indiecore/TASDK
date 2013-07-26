#pragma once
#include "Core.Object.Vector.h"
#include "UDKBase.UDKBot.h"
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Engine.NavigationPoint.h"
#include "UTGame.UTDefensePoint.h"
#include "Engine.Pawn.h"
#include "Engine.Weapon.h"
#include "Engine.Inventory.h"
#include "UTGame.UTAvoidMarker.h"
#include "Engine.InterpActor.h"
#include "Core.Object.Rotator.h"
#include "UTGame.UTSeqAct_AIStartFireAt.h"
#include "UTGame.UTSeqAct_AIStopFire.h"
#include "Engine.HUD.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.PhysicsVolume.h"
#include "UTGame.UTCharInfo.CharacterInfo.h"
#include "Engine.Vehicle.h"
#include "Engine.Projectile.h"
#include "UDKBase.UDKVehicle.h"
#include "Engine.PickupFactory.h"
#include "UTGame.UTPickupFactory.h"
#include "UTGame.UTSeqAct_AIFreeze.h"
#include "Engine.LiftCenter.h"
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
		ADD_STRUCT(::VectorProperty, DirectionHint, 0xFFFFFFFF)
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
		ADD_STRUCT(::VectorProperty, LastKillerPosition, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LastKnownPosition, 0xFFFFFFFF)
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
		ADD_STRUCT(::VectorProperty, HidingSpot, 0xFFFFFFFF)
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
		Vector GetDirectionHint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.GetDirectionHint");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		float RatePickup(class Actor* PickupHolder, ScriptClass* InvClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.RatePickup");
			byte* params = (byte*)malloc(12);
			*(class Actor**)params = PickupHolder;
			*(ScriptClass**)(params + 4) = InvClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		bool PriorityObjective()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.PriorityObjective");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		float RateWeapon(class Weapon* W)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.RateWeapon");
			byte* params = (byte*)malloc(8);
			*(class Weapon**)params = W;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		bool WeaponFireAgain(bool bFinishedFire)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.WeaponFireAgain");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bFinishedFire;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool NeedWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.NeedWeapon");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool DoWaitForLanding()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.DoWaitForLanding");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void DelayedLeaveVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.DelayedLeaveVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool NotifyLanded(Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.NotifyLanded");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = HitNormal;
			*(class Actor**)(params + 12) = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void SetFall()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SetFall");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CustomActionFunc(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.CustomActionFunc");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void EnemyJustTeleported()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.EnemyJustTeleported");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WasKilledBy(class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.WasKilledBy");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartMonitoring(class Pawn* P, float MaxDist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.StartMonitoring");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			*(float*)(params + 4) = MaxDist;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PawnDied(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.PawnDied");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnedByKismet()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SpawnedByKismet");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool LandingShake()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.LandingShake");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool HasTimedPowerup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.HasTimedPowerup");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void NotifyAddInventory(class Inventory* NewItem)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.NotifyAddInventory");
			byte* params = (byte*)malloc(4);
			*(class Inventory**)params = NewItem;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetupSpecialPathAbilities()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SetupSpecialPathAbilities");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool NotifyHitWall(Vector HitNormal, class Actor* Wall)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.NotifyHitWall");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = HitNormal;
			*(class Actor**)(params + 12) = Wall;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void FearThisSpot(class UTAvoidMarker* aSpot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.FearThisSpot");
			byte* params = (byte*)malloc(4);
			*(class UTAvoidMarker**)params = aSpot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Startle(class Actor* Feared)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.Startle");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Feared;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetCombatTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SetCombatTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanImpactJump()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.CanImpactJump");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void TimeDJReset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.TimeDJReset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetDoubleJump()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ResetDoubleJump");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WaitForMover(class InterpActor* M)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.WaitForMover");
			byte* params = (byte*)malloc(4);
			*(class InterpActor**)params = M;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReadyForLift()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ReadyForLift");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldFireAgain()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ShouldFireAgain");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void TimedFireWeaponAtEnemy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.TimedFireWeaponAtEnemy");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool FireWeaponAt(class Actor* A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.FireWeaponAt");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CanAttack(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.CanAttack");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void OnAIStartFireAt(class UTSeqAct_AIStartFireAt* FireAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.OnAIStartFireAt");
			byte* params = (byte*)malloc(4);
			*(class UTSeqAct_AIStartFireAt**)params = FireAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TimedFireWeaponAtScriptedTarget()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.TimedFireWeaponAtScriptedTarget");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopFiring()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.StopFiring");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnAIStopFire(class UTSeqAct_AIStopFire* FireAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.OnAIStopFire");
			byte* params = (byte*)malloc(4);
			*(class UTSeqAct_AIStopFire**)params = FireAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float WeaponPreference(class Weapon* W)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.WeaponPreference");
			byte* params = (byte*)malloc(8);
			*(class Weapon**)params = W;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		bool ProficientWithWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ProficientWithWeapon");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool CanComboMoving()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.CanComboMoving");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool CanCombo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.CanCombo");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void DisplayDebug(class HUD* HUD, float& YL, float& YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.DisplayDebug");
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = YL;
			*(float*)(params + 8) = YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			YL = *(float*)(params + 4);
			YPos = *(float*)(params + 8);
			free(params);
		}
		ScriptName GetOrders()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.GetOrders");
			byte* params = (byte*)malloc(8);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)params;
			free(params);
			return returnVal;
		}
		void YellAt(class PlayerReplicationInfo* Moron)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.YellAt");
			byte* params = (byte*)malloc(4);
			*(class PlayerReplicationInfo**)params = Moron;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendMessage(class PlayerReplicationInfo* Recipient, ScriptName MessageType, float Wait, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SendMessage");
			byte* params = (byte*)malloc(20);
			*(class PlayerReplicationInfo**)params = Recipient;
			*(ScriptName*)(params + 4) = MessageType;
			*(float*)(params + 12) = Wait;
			*(ScriptClass**)(params + 16) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBotOrders(ScriptName NewOrders, class Controller* OrderGiver, bool bShouldAck)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SetBotOrders");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = NewOrders;
			*(class Controller**)(params + 8) = OrderGiver;
			*(bool*)(params + 12) = bShouldAck;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetTemporaryOrders(ScriptName NewOrders, class Controller* OrderGiver)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SetTemporaryOrders");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = NewOrders;
			*(class Controller**)(params + 8) = OrderGiver;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearTemporaryOrders()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ClearTemporaryOrders");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HearNoise(float Loudness, class Actor* NoiseMaker, ScriptName NoiseType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.HearNoise");
			byte* params = (byte*)malloc(16);
			*(float*)params = Loudness;
			*(class Actor**)(params + 4) = NoiseMaker;
			*(ScriptName*)(params + 8) = NoiseType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SeePlayer(class Pawn* SeenPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SeePlayer");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = SeenPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAttractionState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SetAttractionState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ClearShot(Vector TargetLoc, bool bImmediateFire)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ClearShot");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = TargetLoc;
			*(bool*)(params + 12) = bImmediateFire;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool CanStakeOut()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.CanStakeOut");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void CheckIfShouldCrouch(Vector StartPosition, Vector TargetPosition, float probability)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.CheckIfShouldCrouch");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = StartPosition;
			*(Vector*)(params + 12) = TargetPosition;
			*(float*)(params + 24) = probability;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsSniping()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.IsSniping");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void FreePoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.FreePoint");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool AssignSquadResponsibility()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.AssignSquadResponsibility");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		float RelativeStrength(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.RelativeStrength");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		void SetEnemyInfo(bool bNewEnemyVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SetEnemyInfo");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewEnemyVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnemyChanged(bool bNewEnemyVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.EnemyChanged");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewEnemyVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool StrafeFromDamage(float Damage, ScriptClass* DamageType, bool bFindDest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.StrafeFromDamage");
			byte* params = (byte*)malloc(16);
			*(float*)params = Damage;
			*(ScriptClass**)(params + 4) = DamageType;
			*(bool*)(params + 8) = bFindDest;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void NotifyPhysicsVolumeChange(class PhysicsVolume* NewVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.NotifyPhysicsVolumeChange");
			byte* params = (byte*)malloc(4);
			*(class PhysicsVolume**)params = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MayDodgeToMoveTarget()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.MayDodgeToMoveTarget");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyJumpApex()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.NotifyJumpApex");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyMissedJump()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.NotifyMissedJump");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Possess(class Pawn* aPawn, bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.Possess");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = aPawn;
			*(bool*)(params + 4) = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Initialize(float InSkill, CharacterInfo& BotInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.Initialize");
			byte* params = (byte*)malloc(116);
			*(float*)params = InSkill;
			*(CharacterInfo*)(params + 4) = BotInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			BotInfo = *(CharacterInfo*)(params + 4);
			free(params);
		}
		void ResetSkill()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ResetSkill");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMaxDesiredSpeed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SetMaxDesiredSpeed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPeripheralVision()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SetPeripheralVision");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetAlertness(float NewAlertness)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SetAlertness");
			byte* params = (byte*)malloc(4);
			*(float*)params = NewAlertness;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void WhatToDoNext()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.WhatToDoNext");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ExecuteWhatToDoNext()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ExecuteWhatToDoNext");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EnterVehicle(class Vehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.EnterVehicle");
			byte* params = (byte*)malloc(4);
			*(class Vehicle**)params = V;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LeaveVehicle(bool bBlocking)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.LeaveVehicle");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bBlocking;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void VehicleFightEnemy(bool bCanCharge, float EnemyStrength)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.VehicleFightEnemy");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bCanCharge;
			*(float*)(params + 4) = EnemyStrength;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FightEnemy(bool bCanCharge, float EnemyStrength)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.FightEnemy");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bCanCharge;
			*(float*)(params + 4) = EnemyStrength;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DoRangedAttackOn(class Actor* A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.DoRangedAttackOn");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ChooseAttackMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ChooseAttackMode");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool FindSuperPickup(float MaxDist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.FindSuperPickup");
			byte* params = (byte*)malloc(8);
			*(float*)params = MaxDist;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool FindInventoryGoal(float BestWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.FindInventoryGoal");
			byte* params = (byte*)malloc(8);
			*(float*)params = BestWeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void TossFlagToPlayer(class Controller* OrderGiver)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.TossFlagToPlayer");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = OrderGiver;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool PickRetreatDestination()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.PickRetreatDestination");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SoakStop(ScriptArray<wchar_t> problem)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SoakStop");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = problem;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool FindRoamDest()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.FindRoamDest");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void Restart(bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.Restart");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CheckPathToGoalAround(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.CheckPathToGoalAround");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void ClearPathFor(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ClearPathFor");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AdjustAround(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.AdjustAround");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool NotifyBump(class Actor* Other, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.NotifyBump");
			byte* params = (byte*)malloc(20);
			*(class Actor**)params = Other;
			*(Vector*)(params + 4) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void NotifyPostLanded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.NotifyPostLanded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TimedDodgeToMoveTarget()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.TimedDodgeToMoveTarget");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool StartMoveToward(class Actor* O)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.StartMoveToward");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = O;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool SetRouteToGoal(class Actor* A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SetRouteToGoal");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool AllowDetourTo(class NavigationPoint* N)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.AllowDetourTo");
			byte* params = (byte*)malloc(8);
			*(class NavigationPoint**)params = N;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool FindBestPathToward(class Actor* A, bool bCheckedReach, bool bAllowDetour)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.FindBestPathToward");
			byte* params = (byte*)malloc(16);
			*(class Actor**)params = A;
			*(bool*)(params + 4) = bCheckedReach;
			*(bool*)(params + 8) = bAllowDetour;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool CheckFutureSight(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.CheckFutureSight");
			byte* params = (byte*)malloc(8);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		float AdjustAimError(float TargetDist, bool bInstantProj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.AdjustAimError");
			byte* params = (byte*)malloc(12);
			*(float*)params = TargetDist;
			*(bool*)(params + 4) = bInstantProj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		Rotator GetAdjustedAimFor(class Weapon* InWeapon, Vector projStart)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.GetAdjustedAimFor");
			byte* params = (byte*)malloc(28);
			*(class Weapon**)params = InWeapon;
			*(Vector*)(params + 4) = projStart;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 16);
			free(params);
			return returnVal;
		}
		bool TryDuckTowardsMoveTarget(Vector Dir, Vector Y)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.TryDuckTowardsMoveTarget");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = Dir;
			*(Vector*)(params + 12) = Y;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		void DelayedWarning()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.DelayedWarning");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceiveProjectileWarning(class Projectile* Proj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ReceiveProjectileWarning");
			byte* params = (byte*)malloc(4);
			*(class Projectile**)params = Proj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyTakeHit(class Controller* InstigatedBy, Vector HitLocation, int Damage, ScriptClass* DamageType, Vector Momentum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.NotifyTakeHit");
			byte* params = (byte*)malloc(36);
			*(class Controller**)params = InstigatedBy;
			*(Vector*)(params + 4) = HitLocation;
			*(int*)(params + 16) = Damage;
			*(ScriptClass**)(params + 20) = DamageType;
			*(Vector*)(params + 24) = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DelayedInstantWarning()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.DelayedInstantWarning");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceiveWarning(class Pawn* shooter, float projSpeed, Vector FireDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ReceiveWarning");
			byte* params = (byte*)malloc(20);
			*(class Pawn**)params = shooter;
			*(float*)(params + 4) = projSpeed;
			*(Vector*)(params + 8) = FireDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReceiveRunOverWarning(class UDKVehicle* V, float projSpeed, Vector VehicleDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ReceiveRunOverWarning");
			byte* params = (byte*)malloc(20);
			*(class UDKVehicle**)params = V;
			*(float*)(params + 4) = projSpeed;
			*(Vector*)(params + 8) = VehicleDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyFallingHitWall(Vector HitNormal, class Actor* HitActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.NotifyFallingHitWall");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = HitNormal;
			*(class Actor**)(params + 12) = HitActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MissedDodge()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.MissedDodge");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool TryWallDodge(Vector HitNormal, class Actor* HitActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.TryWallDodge");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = HitNormal;
			*(class Actor**)(params + 12) = HitActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void ChangeStrafe()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ChangeStrafe");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool TryToDuck(Vector duckDir, bool bReversed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.TryToDuck");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = duckDir;
			*(bool*)(params + 12) = bReversed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void NotifyKilled(class Controller* Killer, class Controller* Killed, class Pawn* KilledPawn, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.NotifyKilled");
			byte* params = (byte*)malloc(16);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = Killed;
			*(class Pawn**)(params + 8) = KilledPawn;
			*(ScriptClass**)(params + 12) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Actor* FaceMoveTarget()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.FaceMoveTarget");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)params;
			free(params);
			return returnVal;
		}
		bool ShouldStrafeTo(class Actor* WayPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ShouldStrafeTo");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = WayPoint;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		class Actor* FaceActor(float StrafingModifier)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.FaceActor");
			byte* params = (byte*)malloc(8);
			*(float*)params = StrafingModifier;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)(params + 4);
			free(params);
			return returnVal;
		}
		float SuperDesireability(class PickupFactory* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SuperDesireability");
			byte* params = (byte*)malloc(8);
			*(class PickupFactory**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		bool SuperPickupNotSpokenFor(class UTPickupFactory* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SuperPickupNotSpokenFor");
			byte* params = (byte*)malloc(8);
			*(class UTPickupFactory**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void DamageAttitudeTo(class Controller* Other, float Damage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.DamageAttitudeTo");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Other;
			*(float*)(params + 4) = Damage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsRetreating()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.IsRetreating");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void OnAIFreeze(class UTSeqAct_AIFreeze* FreezeAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.OnAIFreeze");
			byte* params = (byte*)malloc(4);
			*(class UTSeqAct_AIFreeze**)params = FreezeAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsDefending()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.IsDefending");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool ShouldDefendPosition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ShouldDefendPosition");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void MoveToDefensePoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.MoveToDefensePoint");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MoveAwayFrom(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.MoveAwayFrom");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void WanderOrCamp()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.WanderOrCamp");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EnableBumps()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.EnableBumps");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Celebrate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.Celebrate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ForceGiveWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ForceGiveWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetDesiredOffset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.GetDesiredOffset");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		bool LostContact(float MaxTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.LostContact");
			byte* params = (byte*)malloc(8);
			*(float*)params = MaxTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool LoseEnemy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.LoseEnemy");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void DoStakeOut()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.DoStakeOut");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DoCharge()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.DoCharge");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DoTacticalMove()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.DoTacticalMove");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DoRetreat()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.DoRetreat");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool DefendMelee(float Dist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.DefendMelee");
			byte* params = (byte*)malloc(8);
			*(float*)params = Dist;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsStrafing()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.IsStrafing");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool EngageDirection(Vector StrafeDir, bool bForced)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.EngageDirection");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = StrafeDir;
			*(bool*)(params + 12) = bForced;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool IsHunting()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.IsHunting");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool FindViewSpot()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.FindViewSpot");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool Stopped()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.Stopped");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsShootingObjective()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.IsShootingObjective");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool FocusOnLeader(bool bLeaderFiring)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.FocusOnLeader");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bLeaderFiring;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void StopMovement()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.StopMovement");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PerformCustomAction(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ActionFunc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.PerformCustomAction");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ActionFunc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UnderLift(class LiftCenter* M)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.UnderLift");
			byte* params = (byte*)malloc(4);
			*(class LiftCenter**)params = M;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool HandlePathObstruction(class Actor* BlockedBy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.HandlePathObstruction");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = BlockedBy;
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
