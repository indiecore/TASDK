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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.Initialize");
			byte params[4] = { NULL };
			*(class OnlineSubsystem**)&params[0] = Sub;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddKill(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddKill");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddDeath(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddDeath");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddAssist(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddAssist");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddAccolade(class TrPlayerController* PC, int Id, int ActivityId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddAccolade");
			byte params[12] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			*(int*)&params[4] = Id;
			*(int*)&params[8] = ActivityId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddCredits(class TrPlayerController* PC, int val, bool bSpent, bool bFree)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddCredits");
			byte params[16] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			*(int*)&params[4] = val;
			*(bool*)&params[8] = bSpent;
			*(bool*)&params[12] = bFree;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateTimePlayed(class TrPlayerController* PC, int TimeUsed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.UpdateTimePlayed");
			byte params[8] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			*(int*)&params[4] = TimeUsed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateWeapon(class TrPlayerController* PC, int WeaponId, int ActivityId, int ShotsFired, int TimeUsed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.UpdateWeapon");
			byte params[20] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			*(int*)&params[4] = WeaponId;
			*(int*)&params[8] = ActivityId;
			*(int*)&params[12] = ShotsFired;
			*(int*)&params[16] = TimeUsed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateDamage(class TrPlayerController* PC, int WeaponId, int Amount, int Dist, bool bKill, bool bVehicle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.UpdateDamage");
			byte params[24] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			*(int*)&params[4] = WeaponId;
			*(int*)&params[8] = Amount;
			*(int*)&params[12] = Dist;
			*(bool*)&params[16] = bKill;
			*(bool*)&params[20] = bVehicle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetIdentification(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.SetIdentification");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetActiveClass(class TrPlayerController* PC, int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.SetActiveClass");
			byte params[8] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			*(int*)&params[4] = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddRepair(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddRepair");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddFlagCap(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddFlagCap");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddFlagGrab(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddFlagGrab");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddFlagReturn(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddFlagReturn");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddMidairKill(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddMidairKill");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddVehicleKill(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddVehicleKill");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetXP(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.SetXP");
			byte params[8] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTeam(class TrPlayerController* PC, int TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.SetTeam");
			byte params[8] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			*(int*)&params[4] = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddVehicleDestruction(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddVehicleDestruction");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpeedSkied(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.SetSpeedSkied");
			byte params[8] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddDeployableDestruction(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddDeployableDestruction");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddCreditsSpent(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddCreditsSpent");
			byte params[8] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDistanceKill(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.SetDistanceKill");
			byte params[8] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpeedFlagCap(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.SetSpeedFlagCap");
			byte params[8] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddCreditsEarned(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddCreditsEarned");
			byte params[8] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddDistanceSkied(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddDistanceSkied");
			byte params[8] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpeedFlagGrab(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.SetSpeedFlagGrab");
			byte params[8] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDistanceHeadshot(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.SetDistanceHeadshot");
			byte params[8] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FallingDeath(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.FallingDeath");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SkiDistance(class TrPlayerController* PC, int Distance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.SkiDistance");
			byte params[8] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			*(int*)&params[4] = Distance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BeltKill(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.BeltKill");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CallIn(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.CallIn");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CallInKill(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.CallInKill");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RegeneratedToFull(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.RegeneratedToFull");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FlagGrabSpeed(class TrPlayerController* PC, int Speed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.FlagGrabSpeed");
			byte params[8] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			*(int*)&params[4] = Speed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VEHICLEKILL(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.VEHICLEKILL");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InvStationVisited(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.InvStationVisited");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SkiSpeed(class TrPlayerController* PC, int Speed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.SkiSpeed");
			byte params[8] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			*(int*)&params[4] = Speed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BaseUpgrade(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.BaseUpgrade");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TrackPlayerMovement(class TrPlayerController* PC, int TimeStamp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.TrackPlayerMovement");
			byte params[8] = { NULL };
			*(class TrPlayerController**)&params[0] = PC;
			*(int*)&params[4] = TimeStamp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddVehicleSpawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddVehicleSpawn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddGeneratorDestruction()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddGeneratorDestruction");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WriteMatchStats()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.WriteMatchStats");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void WritePlayerStats(ScriptArray<class PlayerReplicationInfo*> PRIArray)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.WritePlayerStats");
			byte params[12] = { NULL };
			*(ScriptArray<class PlayerReplicationInfo*>*)&params[0] = PRIArray;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GameEnd()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.GameEnd");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Flush()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.Flush");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
