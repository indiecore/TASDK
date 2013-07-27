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
		ADD_STRUCT(Vector, DirectionHint, 1308)
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
		ADD_STRUCT(Vector, LastKillerPosition, 1512)
		ADD_STRUCT(Vector, LastKnownPosition, 1500)
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
		ADD_STRUCT(Vector, HidingSpot, 1168)
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
		Vector GetDirectionHint()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39470);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		float RatePickup(class Actor* PickupHolder, ScriptClass* InvClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40412);
			byte params[12] = { NULL };
			*(class Actor**)params = PickupHolder;
			*(ScriptClass**)&params[4] = InvClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		bool PriorityObjective()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40639);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		float RateWeapon(class Weapon* W)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40931);
			byte params[8] = { NULL };
			*(class Weapon**)params = W;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		bool WeaponFireAgain(bool bFinishedFire)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41003);
			byte params[8] = { NULL };
			*(bool*)params = bFinishedFire;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool NeedWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(41201);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool DoWaitForLanding()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42432);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void DelayedLeaveVehicle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42434);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool NotifyLanded(Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42438);
			byte params[20] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void SetFall()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42442);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CustomActionFunc(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42457);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void EnemyJustTeleported()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42550);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WasKilledBy(class Controller* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42552);
			byte params[4] = { NULL };
			*(class Controller**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartMonitoring(class Pawn* P, float MaxDist)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42554);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			*(float*)&params[4] = MaxDist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnDied(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42557);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42559);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42560);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnedByKismet()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42561);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool LandingShake()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42562);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool HasTimedPowerup()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42564);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void NotifyAddInventory(class Inventory* NewItem)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42568);
			byte params[4] = { NULL };
			*(class Inventory**)params = NewItem;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetupSpecialPathAbilities()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42570);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool NotifyHitWall(Vector HitNormal, class Actor* Wall)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42571);
			byte params[20] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = Wall;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void FearThisSpot(class UTAvoidMarker* aSpot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42579);
			byte params[4] = { NULL };
			*(class UTAvoidMarker**)params = aSpot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Startle(class Actor* Feared)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42582);
			byte params[4] = { NULL };
			*(class Actor**)params = Feared;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCombatTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42584);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanImpactJump()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42585);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void TimeDJReset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42589);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetDoubleJump()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42590);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WaitForMover(class InterpActor* M)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42592);
			byte params[4] = { NULL };
			*(class InterpActor**)params = M;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReadyForLift()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42594);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldFireAgain()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42597);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void TimedFireWeaponAtEnemy()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42606);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool FireWeaponAt(class Actor* A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42607);
			byte params[8] = { NULL };
			*(class Actor**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CanAttack(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42610);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void OnAIStartFireAt(class UTSeqAct_AIStartFireAt* FireAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42614);
			byte params[4] = { NULL };
			*(class UTSeqAct_AIStartFireAt**)params = FireAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TimedFireWeaponAtScriptedTarget()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42619);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopFiring()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42620);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnAIStopFire(class UTSeqAct_AIStopFire* FireAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42621);
			byte params[4] = { NULL };
			*(class UTSeqAct_AIStopFire**)params = FireAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float WeaponPreference(class Weapon* W)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42626);
			byte params[8] = { NULL };
			*(class Weapon**)params = W;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		bool ProficientWithWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42632);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool CanComboMoving()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42635);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool CanCombo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42637);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void DisplayDebug(class HUD* HUD, float& YL, float& YPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42639);
			byte params[12] = { NULL };
			*(class HUD**)params = HUD;
			*(float*)&params[4] = YL;
			*(float*)&params[8] = YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			YL = *(float*)&params[4];
			YPos = *(float*)&params[8];
		}
		ScriptName GetOrders()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42651);
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)params;
		}
		void YellAt(class PlayerReplicationInfo* Moron)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42658);
			byte params[4] = { NULL };
			*(class PlayerReplicationInfo**)params = Moron;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendMessage(class PlayerReplicationInfo* Recipient, ScriptName MessageType, float Wait, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42661);
			byte params[20] = { NULL };
			*(class PlayerReplicationInfo**)params = Recipient;
			*(ScriptName*)&params[4] = MessageType;
			*(float*)&params[12] = Wait;
			*(ScriptClass**)&params[16] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBotOrders(ScriptName NewOrders, class Controller* OrderGiver, bool bShouldAck)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42666);
			byte params[16] = { NULL };
			*(ScriptName*)params = NewOrders;
			*(class Controller**)&params[8] = OrderGiver;
			*(bool*)&params[12] = bShouldAck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTemporaryOrders(ScriptName NewOrders, class Controller* OrderGiver)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42671);
			byte params[12] = { NULL };
			*(ScriptName*)params = NewOrders;
			*(class Controller**)&params[8] = OrderGiver;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearTemporaryOrders()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42674);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HearNoise(float Loudness, class Actor* NoiseMaker, ScriptName NoiseType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42675);
			byte params[16] = { NULL };
			*(float*)params = Loudness;
			*(class Actor**)&params[4] = NoiseMaker;
			*(ScriptName*)&params[8] = NoiseType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SeePlayer(class Pawn* SeenPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42681);
			byte params[4] = { NULL };
			*(class Pawn**)params = SeenPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAttractionState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42683);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ClearShot(Vector TargetLoc, bool bImmediateFire)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42684);
			byte params[20] = { NULL };
			*(Vector*)params = TargetLoc;
			*(bool*)&params[12] = bImmediateFire;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool CanStakeOut()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42689);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void CheckIfShouldCrouch(Vector StartPosition, Vector TargetPosition, float probability)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42692);
			byte params[28] = { NULL };
			*(Vector*)params = StartPosition;
			*(Vector*)&params[12] = TargetPosition;
			*(float*)&params[24] = probability;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsSniping()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42700);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void FreePoint()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42703);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool AssignSquadResponsibility()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42704);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		float RelativeStrength(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42708);
			byte params[8] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void SetEnemyInfo(bool bNewEnemyVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42713);
			byte params[4] = { NULL };
			*(bool*)params = bNewEnemyVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnemyChanged(bool bNewEnemyVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42718);
			byte params[4] = { NULL };
			*(bool*)params = bNewEnemyVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool StrafeFromDamage(float Damage, ScriptClass* DamageType, bool bFindDest)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42720);
			byte params[16] = { NULL };
			*(float*)params = Damage;
			*(ScriptClass**)&params[4] = DamageType;
			*(bool*)&params[8] = bFindDest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void NotifyPhysicsVolumeChange(class PhysicsVolume* NewVolume)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42725);
			byte params[4] = { NULL };
			*(class PhysicsVolume**)params = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MayDodgeToMoveTarget()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42728);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyJumpApex()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42740);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyMissedJump()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42746);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42753);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Possess(class Pawn* aPawn, bool bVehicleTransition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42754);
			byte params[8] = { NULL };
			*(class Pawn**)params = aPawn;
			*(bool*)&params[4] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Initialize(float InSkill, UTCharInfo::CharacterInfo& BotInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42757);
			byte params[116] = { NULL };
			*(float*)params = InSkill;
			*(UTCharInfo::CharacterInfo*)&params[4] = BotInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			BotInfo = *(UTCharInfo::CharacterInfo*)&params[4];
		}
		void ResetSkill()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42763);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMaxDesiredSpeed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42764);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPeripheralVision()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42765);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetAlertness(float NewAlertness)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42766);
			byte params[4] = { NULL };
			*(float*)params = NewAlertness;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WhatToDoNext()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42768);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ExecuteWhatToDoNext()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42771);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EnterVehicle(class Vehicle* V)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42780);
			byte params[4] = { NULL };
			*(class Vehicle**)params = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LeaveVehicle(bool bBlocking)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42782);
			byte params[4] = { NULL };
			*(bool*)params = bBlocking;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VehicleFightEnemy(bool bCanCharge, float EnemyStrength)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42785);
			byte params[8] = { NULL };
			*(bool*)params = bCanCharge;
			*(float*)&params[4] = EnemyStrength;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FightEnemy(bool bCanCharge, float EnemyStrength)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42789);
			byte params[8] = { NULL };
			*(bool*)params = bCanCharge;
			*(float*)&params[4] = EnemyStrength;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DoRangedAttackOn(class Actor* A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42801);
			byte params[4] = { NULL };
			*(class Actor**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ChooseAttackMode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42804);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool FindSuperPickup(float MaxDist)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42810);
			byte params[8] = { NULL };
			*(float*)params = MaxDist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool FindInventoryGoal(float BestWeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42817);
			byte params[8] = { NULL };
			*(float*)params = BestWeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void TossFlagToPlayer(class Controller* OrderGiver)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42822);
			byte params[4] = { NULL };
			*(class Controller**)params = OrderGiver;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool PickRetreatDestination()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42828);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SoakStop(ScriptString* problem)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42831);
			byte params[12] = { NULL };
			*(ScriptString**)params = problem;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool FindRoamDest()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42834);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void Restart(bool bVehicleTransition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42837);
			byte params[4] = { NULL };
			*(bool*)params = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckPathToGoalAround(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42839);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ClearPathFor(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42842);
			byte params[4] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AdjustAround(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42844);
			byte params[8] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool NotifyBump(class Actor* Other, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42853);
			byte params[20] = { NULL };
			*(class Actor**)params = Other;
			*(Vector*)&params[4] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void NotifyPostLanded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42864);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TimedDodgeToMoveTarget()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42865);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool StartMoveToward(class Actor* O)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42866);
			byte params[8] = { NULL };
			*(class Actor**)params = O;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetRouteToGoal(class Actor* A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42869);
			byte params[8] = { NULL };
			*(class Actor**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool AllowDetourTo(class NavigationPoint* N)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42872);
			byte params[8] = { NULL };
			*(class NavigationPoint**)params = N;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool FindBestPathToward(class Actor* A, bool bCheckedReach, bool bAllowDetour)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42877);
			byte params[16] = { NULL };
			*(class Actor**)params = A;
			*(bool*)&params[4] = bCheckedReach;
			*(bool*)&params[8] = bAllowDetour;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool CheckFutureSight(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42883);
			byte params[8] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float AdjustAimError(float TargetDist, bool bInstantProj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42887);
			byte params[12] = { NULL };
			*(float*)params = TargetDist;
			*(bool*)&params[4] = bInstantProj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		Rotator GetAdjustedAimFor(class Weapon* InWeapon, Vector projStart)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42902);
			byte params[28] = { NULL };
			*(class Weapon**)params = InWeapon;
			*(Vector*)&params[4] = projStart;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[16];
		}
		bool TryDuckTowardsMoveTarget(Vector Dir, Vector Y)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42920);
			byte params[28] = { NULL };
			*(Vector*)params = Dir;
			*(Vector*)&params[12] = Y;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void DelayedWarning()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42925);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceiveProjectileWarning(class Projectile* Proj)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42936);
			byte params[4] = { NULL };
			*(class Projectile**)params = Proj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyTakeHit(class Controller* InstigatedBy, Vector HitLocation, int Damage, ScriptClass* DamageType, Vector Momentum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42943);
			byte params[36] = { NULL };
			*(class Controller**)params = InstigatedBy;
			*(Vector*)&params[4] = HitLocation;
			*(int*)&params[16] = Damage;
			*(ScriptClass**)&params[20] = DamageType;
			*(Vector*)&params[24] = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DelayedInstantWarning()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42949);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceiveWarning(class Pawn* shooter, float projSpeed, Vector FireDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42954);
			byte params[20] = { NULL };
			*(class Pawn**)params = shooter;
			*(float*)&params[4] = projSpeed;
			*(Vector*)&params[8] = FireDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReceiveRunOverWarning(class UDKVehicle* V, float projSpeed, Vector VehicleDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42965);
			byte params[20] = { NULL };
			*(class UDKVehicle**)params = V;
			*(float*)&params[4] = projSpeed;
			*(Vector*)&params[8] = VehicleDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyFallingHitWall(Vector HitNormal, class Actor* HitActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42969);
			byte params[16] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = HitActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MissedDodge()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42972);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool TryWallDodge(Vector HitNormal, class Actor* HitActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42978);
			byte params[20] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = HitActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void ChangeStrafe()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42992);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool TryToDuck(Vector duckDir, bool bReversed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42993);
			byte params[20] = { NULL };
			*(Vector*)params = duckDir;
			*(bool*)&params[12] = bReversed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void NotifyKilled(class Controller* Killer, class Controller* Killed, class Pawn* KilledPawn, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43008);
			byte params[16] = { NULL };
			*(class Controller**)params = Killer;
			*(class Controller**)&params[4] = Killed;
			*(class Pawn**)&params[8] = KilledPawn;
			*(ScriptClass**)&params[12] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Actor* FaceMoveTarget()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43013);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)params;
		}
		bool ShouldStrafeTo(class Actor* WayPoint)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43015);
			byte params[8] = { NULL };
			*(class Actor**)params = WayPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class Actor* FaceActor(float StrafingModifier)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43019);
			byte params[8] = { NULL };
			*(float*)params = StrafingModifier;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[4];
		}
		float SuperDesireability(class PickupFactory* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43031);
			byte params[8] = { NULL };
			*(class PickupFactory**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		bool SuperPickupNotSpokenFor(class UTPickupFactory* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43034);
			byte params[8] = { NULL };
			*(class UTPickupFactory**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void DamageAttitudeTo(class Controller* Other, float Damage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43038);
			byte params[8] = { NULL };
			*(class Controller**)params = Other;
			*(float*)&params[4] = Damage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsRetreating()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43041);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void OnAIFreeze(class UTSeqAct_AIFreeze* FreezeAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43043);
			byte params[4] = { NULL };
			*(class UTSeqAct_AIFreeze**)params = FreezeAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsDefending()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43047);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool ShouldDefendPosition()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43049);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void MoveToDefensePoint()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43051);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MoveAwayFrom(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43052);
			byte params[4] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WanderOrCamp()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43054);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EnableBumps()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43055);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Celebrate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43096);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ForceGiveWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43097);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetDesiredOffset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43128);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		bool LostContact(float MaxTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43154);
			byte params[8] = { NULL };
			*(float*)params = MaxTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool LoseEnemy()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43157);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void DoStakeOut()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43161);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DoCharge()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43162);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DoTacticalMove()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43163);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DoRetreat()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43164);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool DefendMelee(float Dist)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43167);
			byte params[8] = { NULL };
			*(float*)params = Dist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsStrafing()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43236);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool EngageDirection(Vector StrafeDir, bool bForced)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43238);
			byte params[20] = { NULL };
			*(Vector*)params = StrafeDir;
			*(bool*)&params[12] = bForced;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool IsHunting()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43287);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool FindViewSpot()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43289);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool Stopped()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43369);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsShootingObjective()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43371);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool FocusOnLeader(bool bLeaderFiring)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43373);
			byte params[8] = { NULL };
			*(bool*)params = bLeaderFiring;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void StopMovement()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43376);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PerformCustomAction(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ActionFunc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43536);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ActionFunc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnderLift(class LiftCenter* M)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43541);
			byte params[4] = { NULL };
			*(class LiftCenter**)params = M;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool HandlePathObstruction(class Actor* BlockedBy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43544);
			byte params[8] = { NULL };
			*(class Actor**)params = BlockedBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
	const float UTBot::AngleConvert = 0.0000958738f;
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
