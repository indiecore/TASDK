#pragma once
#include "UDKBase.UDKBot.h"
#include "Engine.Controller.h"
#include "UTGame.UTPickupFactory.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.NavigationPoint.h"
#include "UTGame.UTDefensePoint.h"
#include "Engine.Pawn.h"
#include "Engine.Weapon.h"
#include "Engine.Inventory.h"
#include "UTGame.UTAvoidMarker.h"
#include "Engine.InterpActor.h"
#include "UTGame.UTSeqAct_AIStartFireAt.h"
#include "UTGame.UTCharInfo.h"
#include "UTGame.UTSeqAct_AIStopFire.h"
#include "Engine.HUD.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.PhysicsVolume.h"
#include "Engine.Vehicle.h"
#include "Engine.Projectile.h"
#include "UDKBase.UDKVehicle.h"
#include "Engine.PickupFactory.h"
#include "UTGame.UTSeqAct_AIFreeze.h"
#include "Engine.LiftCenter.h"
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
	class UTBot : public UDKBot
	{
	public:
		static const auto MAXSTAKEOUTDIST = 2000;
		static const auto ENEMYLOCATIONFUZZ = 1200;
		static const auto TACTICALHEIGHTADVANTAGE = 320;
		static const auto MINSTRAFEDIST = 200;
		static const auto MINVIEWDIST = 200;
		static const float AngleConvert;
		ADD_OBJECT(Actor, NoVehicleGoal, 1304)
		ADD_STRUCT(Object::Vector, DirectionHint, 1308)
		ADD_OBJECT(ScriptClass, KilledVehicleClass, 1164)
		ADD_BOOL(bHuntPlayer, 1132, 0x1)
		ADD_OBJECT(ScriptClass, FavoriteWeapon, 1256)
		ADD_OBJECT(UTDefensePoint, DefensePoint, 1296)
		ADD_BOOL(bJustLanded, 1132, 0x8000)
		ADD_STRUCT(ScriptString*, GoalString, 1264)
		ADD_STRUCT(float, LastInjuredVoiceMessageTime, 1544)
		ADD_STRUCT(float, LastCanAttackCheckTime, 1540)
		ADD_OBJECT(Actor, LastFireTarget, 1536)
		ADD_STRUCT(float, LastTryHoverboardTime, 1532)
		ADD_STRUCT(float, LastActionMusicUpdate, 1528)
		ADD_OBJECT(Actor, ScriptedTarget, 1524)
		ADD_STRUCT(Object::Vector, LastKillerPosition, 1512)
		ADD_STRUCT(Object::Vector, LastKnownPosition, 1500)
		ADD_OBJECT(Controller, OldOrderGiver, 1496)
		ADD_STRUCT(ScriptName, OldOrders, 1488)
		ADD_STRUCT(ScriptName, OrderNames, 1360)
		ADD_STRUCT(float, GatherTime, 1356)
		ADD_STRUCT(float, LastFireAttempt, 1352)
		ADD_STRUCT(int, NumRandomJumps, 1348)
		ADD_STRUCT(float, CampTime, 1344)
		ADD_STRUCT(float, LastSearchWeight, 1340)
		ADD_STRUCT(float, LastSearchTime, 1336)
		ADD_OBJECT(Pawn, FailedHuntEnemy, 1332)
		ADD_STRUCT(float, FailedHuntTime, 1328)
		ADD_STRUCT(float, LastRespawnTime, 1324)
		ADD_STRUCT(float, StopStartTime, 1320)
		ADD_OBJECT(NavigationPoint, DefensivePosition, 1300)
		ADD_STRUCT(float, ReTaskTime, 1292)
		ADD_OBJECT(UTBot, NextSquadMember, 1288)
		ADD_STRUCT(ScriptString*, SoakString, 1276)
		ADD_STRUCT(float, OldMessageTime, 1260)
		ADD_STRUCT(float, Jumpiness, 1252)
		ADD_STRUCT(float, ReactionTime, 1248)
		ADD_STRUCT(float, Tactics, 1244)
		ADD_STRUCT(float, CombatStyle, 1240)
		ADD_STRUCT(float, StrafingAbility, 1236)
		ADD_STRUCT(float, BaseAggressiveness, 1232)
		ADD_STRUCT(float, Accuracy, 1228)
		ADD_STRUCT(float, BaseAlertness, 1224)
		ADD_STRUCT(float, ForcedFlagDropTime, 1220)
		ADD_STRUCT(float, RetreatStartTime, 1216)
		ADD_STRUCT(float, LastUnderFire, 1212)
		ADD_STRUCT(float, StartTacticalTime, 1208)
		ADD_OBJECT(Actor, StartleActor, 1204)
		ADD_STRUCT(float, LoseEnemyCheckTime, 1200)
		ADD_STRUCT(float, Aggression, 1196)
		ADD_STRUCT(float, AcquireTime, 1192)
		ADD_OBJECT(NavigationPoint, BlockedPath, 1188)
		ADD_STRUCT(float, LastAttractCheck, 1184)
		ADD_STRUCT(float, Aggressiveness, 1180)
		ADD_STRUCT(Object::Vector, HidingSpot, 1168)
		ADD_STRUCT(int, LastTauntIndex, 1160)
		ADD_STRUCT(int, OldMessageID, 1156)
		ADD_STRUCT(ScriptName, OldMessageType, 1148)
		ADD_STRUCT(float, MaxSpecialJumpZ, 1144)
		ADD_STRUCT(float, ImpactJumpZ, 1140)
		ADD_OBJECT(Actor, ImpactTarget, 1136)
		ADD_BOOL(bResetCombatTimer, 1132, 0x40000000)
		ADD_BOOL(bCheckDriverPickups, 1132, 0x20000000)
		ADD_BOOL(bDirectHunt, 1132, 0x10000000)
		ADD_BOOL(bFinalStretch, 1132, 0x8000000)
		ADD_BOOL(bSpawnedByKismet, 1132, 0x4000000)
		ADD_BOOL(bBetrayTeam, 1132, 0x2000000)
		ADD_BOOL(bShortCamp, 1132, 0x1000000)
		ADD_BOOL(bForceNoDetours, 1132, 0x800000)
		ADD_BOOL(bSendFlagMessage, 1132, 0x400000)
		ADD_BOOL(bScriptedFrozen, 1132, 0x200000)
		ADD_BOOL(bAllowedToImpactJump, 1132, 0x100000)
		ADD_BOOL(bPendingDoubleJump, 1132, 0x80000)
		ADD_BOOL(bHasSuperWeapon, 1132, 0x40000)
		ADD_BOOL(bIgnoreEnemyChange, 1132, 0x20000)
		ADD_BOOL(bRecommendFastMove, 1132, 0x10000)
		ADD_BOOL(bPursuingFlag, 1132, 0x4000)
		ADD_BOOL(bMustCharge, 1132, 0x2000)
		ADD_BOOL(bStoppedFiring, 1132, 0x1000)
		ADD_BOOL(bFireSuccess, 1132, 0x800)
		ADD_BOOL(bForcedDirection, 1132, 0x400)
		ADD_BOOL(bHasFired, 1132, 0x200)
		ADD_BOOL(bWasNearObjective, 1132, 0x100)
		ADD_BOOL(bTacticalDoubleJump, 1132, 0x80)
		ADD_BOOL(bReachedGatherPoint, 1132, 0x40)
		ADD_BOOL(bInitLifeMessage, 1132, 0x20)
		ADD_BOOL(bFrustrated, 1132, 0x10)
		ADD_BOOL(bChangeDir, 1132, 0x8)
		ADD_BOOL(bStrafeDir, 1132, 0x4)
		ADD_BOOL(bCanFire, 1132, 0x2)
		ADD_STRUCT(float, LastWarningTime, 1128)
		ADD_OBJECT(Pawn, InstantWarningShooter, 1124)
		Object::Vector GetDirectionHint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.GetDirectionHint");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
		float RatePickup(class Actor* PickupHolder, ScriptClass* InvClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.RatePickup");
			byte params[12] = { NULL };
			*(class Actor**)&params[0] = PickupHolder;
			*(ScriptClass**)&params[4] = InvClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		bool PriorityObjective()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.PriorityObjective");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		float RateWeapon(class Weapon* W)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.RateWeapon");
			byte params[8] = { NULL };
			*(class Weapon**)&params[0] = W;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		bool WeaponFireAgain(bool bFinishedFire)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.WeaponFireAgain");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bFinishedFire;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool NeedWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.NeedWeapon");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool DoWaitForLanding()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.DoWaitForLanding");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void DelayedLeaveVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.DelayedLeaveVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool NotifyLanded(Object::Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.NotifyLanded");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = HitNormal;
			*(class Actor**)&params[12] = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void SetFall()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SetFall");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CustomActionFunc(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.CustomActionFunc");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void EnemyJustTeleported()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.EnemyJustTeleported");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WasKilledBy(class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.WasKilledBy");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartMonitoring(class Pawn* P, float MaxDist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.StartMonitoring");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			*(float*)&params[4] = MaxDist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnDied(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.PawnDied");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool HasTimedPowerup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.HasTimedPowerup");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void NotifyAddInventory(class Inventory* NewItem)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.NotifyAddInventory");
			byte params[4] = { NULL };
			*(class Inventory**)&params[0] = NewItem;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetupSpecialPathAbilities()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SetupSpecialPathAbilities");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool NotifyHitWall(Object::Vector HitNormal, class Actor* Wall)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.NotifyHitWall");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = HitNormal;
			*(class Actor**)&params[12] = Wall;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void FearThisSpot(class UTAvoidMarker* aSpot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.FearThisSpot");
			byte params[4] = { NULL };
			*(class UTAvoidMarker**)&params[0] = aSpot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Startle(class Actor* Feared)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.Startle");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Feared;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCombatTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SetCombatTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanImpactJump()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.CanImpactJump");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
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
			byte params[4] = { NULL };
			*(class InterpActor**)&params[0] = M;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReadyForLift()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ReadyForLift");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldFireAgain()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ShouldFireAgain");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void TimedFireWeaponAtEnemy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.TimedFireWeaponAtEnemy");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool FireWeaponAt(class Actor* A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.FireWeaponAt");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CanAttack(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.CanAttack");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void OnAIStartFireAt(class UTSeqAct_AIStartFireAt* FireAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.OnAIStartFireAt");
			byte params[4] = { NULL };
			*(class UTSeqAct_AIStartFireAt**)&params[0] = FireAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			*(class UTSeqAct_AIStopFire**)&params[0] = FireAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float WeaponPreference(class Weapon* W)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.WeaponPreference");
			byte params[8] = { NULL };
			*(class Weapon**)&params[0] = W;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		bool ProficientWithWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ProficientWithWeapon");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool CanComboMoving()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.CanComboMoving");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool CanCombo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.CanCombo");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void DisplayDebug(class HUD* HUD, float& YL, float& YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.DisplayDebug");
			byte params[12] = { NULL };
			*(class HUD**)&params[0] = HUD;
			*(float*)&params[4] = YL;
			*(float*)&params[8] = YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			YL = *(float*)&params[4];
			YPos = *(float*)&params[8];
		}
		ScriptName GetOrders()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.GetOrders");
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[0];
		}
		void YellAt(class PlayerReplicationInfo* Moron)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.YellAt");
			byte params[4] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = Moron;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendMessage(class PlayerReplicationInfo* Recipient, ScriptName MessageType, float Wait, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SendMessage");
			byte params[20] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = Recipient;
			*(ScriptName*)&params[4] = MessageType;
			*(float*)&params[12] = Wait;
			*(ScriptClass**)&params[16] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBotOrders(ScriptName NewOrders, class Controller* OrderGiver, bool bShouldAck)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SetBotOrders");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = NewOrders;
			*(class Controller**)&params[8] = OrderGiver;
			*(bool*)&params[12] = bShouldAck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTemporaryOrders(ScriptName NewOrders, class Controller* OrderGiver)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SetTemporaryOrders");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = NewOrders;
			*(class Controller**)&params[8] = OrderGiver;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearTemporaryOrders()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ClearTemporaryOrders");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HearNoise(float Loudness, class Actor* NoiseMaker, ScriptName NoiseType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.HearNoise");
			byte params[16] = { NULL };
			*(float*)&params[0] = Loudness;
			*(class Actor**)&params[4] = NoiseMaker;
			*(ScriptName*)&params[8] = NoiseType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SeePlayer(class Pawn* SeenPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SeePlayer");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = SeenPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAttractionState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SetAttractionState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ClearShot(Object::Vector TargetLoc, bool bImmediateFire)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ClearShot");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = TargetLoc;
			*(bool*)&params[12] = bImmediateFire;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool CanStakeOut()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.CanStakeOut");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void CheckIfShouldCrouch(Object::Vector StartPosition, Object::Vector TargetPosition, float probability)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.CheckIfShouldCrouch");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = StartPosition;
			*(Object::Vector*)&params[12] = TargetPosition;
			*(float*)&params[24] = probability;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsSniping()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.IsSniping");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void FreePoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.FreePoint");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool AssignSquadResponsibility()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.AssignSquadResponsibility");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		float RelativeStrength(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.RelativeStrength");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void SetEnemyInfo(bool bNewEnemyVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SetEnemyInfo");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewEnemyVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnemyChanged(bool bNewEnemyVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.EnemyChanged");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewEnemyVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool StrafeFromDamage(float Damage, ScriptClass* DamageType, bool bFindDest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.StrafeFromDamage");
			byte params[16] = { NULL };
			*(float*)&params[0] = Damage;
			*(ScriptClass**)&params[4] = DamageType;
			*(bool*)&params[8] = bFindDest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void NotifyPhysicsVolumeChange(class PhysicsVolume* NewVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.NotifyPhysicsVolumeChange");
			byte params[4] = { NULL };
			*(class PhysicsVolume**)&params[0] = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = aPawn;
			*(bool*)&params[4] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Initialize(float InSkill, UTCharInfo::CharacterInfo& BotInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.Initialize");
			byte params[116] = { NULL };
			*(float*)&params[0] = InSkill;
			*(UTCharInfo::CharacterInfo*)&params[4] = BotInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			BotInfo = *(UTCharInfo::CharacterInfo*)&params[4];
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
			byte params[4] = { NULL };
			*(float*)&params[0] = NewAlertness;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			*(class Vehicle**)&params[0] = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LeaveVehicle(bool bBlocking)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.LeaveVehicle");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bBlocking;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VehicleFightEnemy(bool bCanCharge, float EnemyStrength)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.VehicleFightEnemy");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bCanCharge;
			*(float*)&params[4] = EnemyStrength;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FightEnemy(bool bCanCharge, float EnemyStrength)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.FightEnemy");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bCanCharge;
			*(float*)&params[4] = EnemyStrength;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DoRangedAttackOn(class Actor* A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.DoRangedAttackOn");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ChooseAttackMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ChooseAttackMode");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool FindSuperPickup(float MaxDist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.FindSuperPickup");
			byte params[8] = { NULL };
			*(float*)&params[0] = MaxDist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool FindInventoryGoal(float BestWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.FindInventoryGoal");
			byte params[8] = { NULL };
			*(float*)&params[0] = BestWeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void TossFlagToPlayer(class Controller* OrderGiver)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.TossFlagToPlayer");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = OrderGiver;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool PickRetreatDestination()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.PickRetreatDestination");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SoakStop(ScriptString* problem)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SoakStop");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = problem;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool FindRoamDest()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.FindRoamDest");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void Restart(bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.Restart");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckPathToGoalAround(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.CheckPathToGoalAround");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ClearPathFor(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ClearPathFor");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AdjustAround(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.AdjustAround");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool NotifyBump(class Actor* Other, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.NotifyBump");
			byte params[20] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(Object::Vector*)&params[4] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
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
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = O;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetRouteToGoal(class Actor* A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SetRouteToGoal");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool AllowDetourTo(class NavigationPoint* N)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.AllowDetourTo");
			byte params[8] = { NULL };
			*(class NavigationPoint**)&params[0] = N;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool FindBestPathToward(class Actor* A, bool bCheckedReach, bool bAllowDetour)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.FindBestPathToward");
			byte params[16] = { NULL };
			*(class Actor**)&params[0] = A;
			*(bool*)&params[4] = bCheckedReach;
			*(bool*)&params[8] = bAllowDetour;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool CheckFutureSight(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.CheckFutureSight");
			byte params[8] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float AdjustAimError(float TargetDist, bool bInstantProj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.AdjustAimError");
			byte params[12] = { NULL };
			*(float*)&params[0] = TargetDist;
			*(bool*)&params[4] = bInstantProj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		Object::Rotator GetAdjustedAimFor(class Weapon* InWeapon, Object::Vector projStart)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.GetAdjustedAimFor");
			byte params[28] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			*(Object::Vector*)&params[4] = projStart;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[16];
		}
		bool TryDuckTowardsMoveTarget(Object::Vector Dir, Object::Vector Y)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.TryDuckTowardsMoveTarget");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = Dir;
			*(Object::Vector*)&params[12] = Y;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void DelayedWarning()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.DelayedWarning");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceiveProjectileWarning(class Projectile* Proj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ReceiveProjectileWarning");
			byte params[4] = { NULL };
			*(class Projectile**)&params[0] = Proj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyTakeHit(class Controller* InstigatedBy, Object::Vector HitLocation, int Damage, ScriptClass* DamageType, Object::Vector Momentum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.NotifyTakeHit");
			byte params[36] = { NULL };
			*(class Controller**)&params[0] = InstigatedBy;
			*(Object::Vector*)&params[4] = HitLocation;
			*(int*)&params[16] = Damage;
			*(ScriptClass**)&params[20] = DamageType;
			*(Object::Vector*)&params[24] = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DelayedInstantWarning()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.DelayedInstantWarning");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceiveWarning(class Pawn* shooter, float projSpeed, Object::Vector FireDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ReceiveWarning");
			byte params[20] = { NULL };
			*(class Pawn**)&params[0] = shooter;
			*(float*)&params[4] = projSpeed;
			*(Object::Vector*)&params[8] = FireDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReceiveRunOverWarning(class UDKVehicle* V, float projSpeed, Object::Vector VehicleDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ReceiveRunOverWarning");
			byte params[20] = { NULL };
			*(class UDKVehicle**)&params[0] = V;
			*(float*)&params[4] = projSpeed;
			*(Object::Vector*)&params[8] = VehicleDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyFallingHitWall(Object::Vector HitNormal, class Actor* HitActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.NotifyFallingHitWall");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = HitNormal;
			*(class Actor**)&params[12] = HitActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MissedDodge()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.MissedDodge");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool TryWallDodge(Object::Vector HitNormal, class Actor* HitActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.TryWallDodge");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = HitNormal;
			*(class Actor**)&params[12] = HitActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void ChangeStrafe()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ChangeStrafe");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool TryToDuck(Object::Vector duckDir, bool bReversed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.TryToDuck");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = duckDir;
			*(bool*)&params[12] = bReversed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void NotifyKilled(class Controller* Killer, class Controller* Killed, class Pawn* KilledPawn, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.NotifyKilled");
			byte params[16] = { NULL };
			*(class Controller**)&params[0] = Killer;
			*(class Controller**)&params[4] = Killed;
			*(class Pawn**)&params[8] = KilledPawn;
			*(ScriptClass**)&params[12] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Actor* FaceMoveTarget()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.FaceMoveTarget");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[0];
		}
		bool ShouldStrafeTo(class Actor* WayPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ShouldStrafeTo");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = WayPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class Actor* FaceActor(float StrafingModifier)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.FaceActor");
			byte params[8] = { NULL };
			*(float*)&params[0] = StrafingModifier;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[4];
		}
		float SuperDesireability(class PickupFactory* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SuperDesireability");
			byte params[8] = { NULL };
			*(class PickupFactory**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		bool SuperPickupNotSpokenFor(class UTPickupFactory* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.SuperPickupNotSpokenFor");
			byte params[8] = { NULL };
			*(class UTPickupFactory**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void DamageAttitudeTo(class Controller* Other, float Damage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.DamageAttitudeTo");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = Other;
			*(float*)&params[4] = Damage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsRetreating()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.IsRetreating");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void OnAIFreeze(class UTSeqAct_AIFreeze* FreezeAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.OnAIFreeze");
			byte params[4] = { NULL };
			*(class UTSeqAct_AIFreeze**)&params[0] = FreezeAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsDefending()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.IsDefending");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool ShouldDefendPosition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.ShouldDefendPosition");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void MoveToDefensePoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.MoveToDefensePoint");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MoveAwayFrom(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.MoveAwayFrom");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		bool LostContact(float MaxTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.LostContact");
			byte params[8] = { NULL };
			*(float*)&params[0] = MaxTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool LoseEnemy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.LoseEnemy");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
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
			byte params[8] = { NULL };
			*(float*)&params[0] = Dist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsStrafing()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.IsStrafing");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool EngageDirection(Object::Vector StrafeDir, bool bForced)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.EngageDirection");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = StrafeDir;
			*(bool*)&params[12] = bForced;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool IsHunting()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.IsHunting");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool FindViewSpot()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.FindViewSpot");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool Stopped()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.Stopped");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool IsShootingObjective()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.IsShootingObjective");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool FocusOnLeader(bool bLeaderFiring)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.FocusOnLeader");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bLeaderFiring;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
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
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ActionFunc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnderLift(class LiftCenter* M)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.UnderLift");
			byte params[4] = { NULL };
			*(class LiftCenter**)&params[0] = M;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool HandlePathObstruction(class Actor* BlockedBy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTBot.HandlePathObstruction");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = BlockedBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
	const float UTBot::AngleConvert = 0.0000958738f;
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
