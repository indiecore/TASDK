#pragma once
#include "Core.Object.h"
#include "Engine.OnlineSubsystem.h"
#include "TribesGame.TrPlayerController.h"
#include "Engine.PlayerReplicationInfo.h"
namespace UnrealScript
{
	class TrStatsInterface : public Object
	{
	public:
		void Initialize(class OnlineSubsystem* Sub)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112611);
			byte params[4] = { NULL };
			*(class OnlineSubsystem**)params = Sub;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddKill(class TrPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112613);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddDeath(class TrPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112615);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddAssist(class TrPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112617);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddAccolade(class TrPlayerController* PC, int Id, int ActivityId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112619);
			byte params[12] = { NULL };
			*(class TrPlayerController**)params = PC;
			*(int*)&params[4] = Id;
			*(int*)&params[8] = ActivityId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddCredits(class TrPlayerController* PC, int val, bool bSpent, bool bFree)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112623);
			byte params[16] = { NULL };
			*(class TrPlayerController**)params = PC;
			*(int*)&params[4] = val;
			*(bool*)&params[8] = bSpent;
			*(bool*)&params[12] = bFree;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateTimePlayed(class TrPlayerController* PC, int TimeUsed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112628);
			byte params[8] = { NULL };
			*(class TrPlayerController**)params = PC;
			*(int*)&params[4] = TimeUsed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateWeapon(class TrPlayerController* PC, int WeaponId, int ActivityId, int ShotsFired, int TimeUsed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112631);
			byte params[20] = { NULL };
			*(class TrPlayerController**)params = PC;
			*(int*)&params[4] = WeaponId;
			*(int*)&params[8] = ActivityId;
			*(int*)&params[12] = ShotsFired;
			*(int*)&params[16] = TimeUsed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateDamage(class TrPlayerController* PC, int WeaponId, int Amount, int Dist, bool bKill, bool bVehicle)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112637);
			byte params[24] = { NULL };
			*(class TrPlayerController**)params = PC;
			*(int*)&params[4] = WeaponId;
			*(int*)&params[8] = Amount;
			*(int*)&params[12] = Dist;
			*(bool*)&params[16] = bKill;
			*(bool*)&params[20] = bVehicle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetIdentification(class TrPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112644);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetActiveClass(class TrPlayerController* PC, int ClassId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112646);
			byte params[8] = { NULL };
			*(class TrPlayerController**)params = PC;
			*(int*)&params[4] = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddRepair(class TrPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112649);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddFlagCap(class TrPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112651);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddFlagGrab(class TrPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112653);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddFlagReturn(class TrPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112655);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddMidairKill(class TrPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112657);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddVehicleKill(class TrPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112659);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetXP(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112661);
			byte params[8] = { NULL };
			*(class TrPlayerController**)params = PC;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTeam(class TrPlayerController* PC, int TeamNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112664);
			byte params[8] = { NULL };
			*(class TrPlayerController**)params = PC;
			*(int*)&params[4] = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddVehicleDestruction(class TrPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112667);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpeedSkied(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112669);
			byte params[8] = { NULL };
			*(class TrPlayerController**)params = PC;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddDeployableDestruction(class TrPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112672);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddCreditsSpent(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112674);
			byte params[8] = { NULL };
			*(class TrPlayerController**)params = PC;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDistanceKill(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112677);
			byte params[8] = { NULL };
			*(class TrPlayerController**)params = PC;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpeedFlagCap(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112680);
			byte params[8] = { NULL };
			*(class TrPlayerController**)params = PC;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddCreditsEarned(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112683);
			byte params[8] = { NULL };
			*(class TrPlayerController**)params = PC;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddDistanceSkied(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112686);
			byte params[8] = { NULL };
			*(class TrPlayerController**)params = PC;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpeedFlagGrab(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112689);
			byte params[8] = { NULL };
			*(class TrPlayerController**)params = PC;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDistanceHeadshot(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112692);
			byte params[8] = { NULL };
			*(class TrPlayerController**)params = PC;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FallingDeath(class TrPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112695);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SkiDistance(class TrPlayerController* PC, int Distance)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112697);
			byte params[8] = { NULL };
			*(class TrPlayerController**)params = PC;
			*(int*)&params[4] = Distance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BeltKill(class TrPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112700);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CallIn(class TrPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112702);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CallInKill(class TrPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112704);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RegeneratedToFull(class TrPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112706);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FlagGrabSpeed(class TrPlayerController* PC, int Speed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112708);
			byte params[8] = { NULL };
			*(class TrPlayerController**)params = PC;
			*(int*)&params[4] = Speed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VEHICLEKILL(class TrPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112711);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InvStationVisited(class TrPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112713);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SkiSpeed(class TrPlayerController* PC, int Speed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112715);
			byte params[8] = { NULL };
			*(class TrPlayerController**)params = PC;
			*(int*)&params[4] = Speed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BaseUpgrade(class TrPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112718);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TrackPlayerMovement(class TrPlayerController* PC, int TimeStamp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112720);
			byte params[8] = { NULL };
			*(class TrPlayerController**)params = PC;
			*(int*)&params[4] = TimeStamp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddVehicleSpawn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112723);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddGeneratorDestruction()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112724);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WriteMatchStats()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112725);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WritePlayerStats(ScriptArray<class PlayerReplicationInfo*> PRIArray)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112726);
			byte params[12] = { NULL };
			*(ScriptArray<class PlayerReplicationInfo*>*)params = PRIArray;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GameEnd()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112729);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Flush()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112730);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
