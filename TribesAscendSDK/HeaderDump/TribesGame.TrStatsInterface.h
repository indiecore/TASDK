#pragma once
#include "Core.Object.h"
#include "Engine.OnlineSubsystem.h"
#include "TribesGame.TrPlayerController.h"
namespace UnrealScript
{
	class TrStatsInterface : public Object
	{
	public:
		void Initialize(class OnlineSubsystem* Sub)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.Initialize");
			byte* params = (byte*)malloc(4);
			*(class OnlineSubsystem**)params = Sub;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddKill(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddKill");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddDeath(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddDeath");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddAssist(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddAssist");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddAccolade(class TrPlayerController* PC, int Id, int ActivityId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddAccolade");
			byte* params = (byte*)malloc(12);
			*(class TrPlayerController**)params = PC;
			*(int*)(params + 4) = Id;
			*(int*)(params + 8) = ActivityId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddCredits(class TrPlayerController* PC, int val, bool bSpent, bool bFree)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddCredits");
			byte* params = (byte*)malloc(16);
			*(class TrPlayerController**)params = PC;
			*(int*)(params + 4) = val;
			*(bool*)(params + 8) = bSpent;
			*(bool*)(params + 12) = bFree;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateTimePlayed(class TrPlayerController* PC, int TimeUsed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.UpdateTimePlayed");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = PC;
			*(int*)(params + 4) = TimeUsed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateWeapon(class TrPlayerController* PC, int WeaponId, int ActivityId, int ShotsFired, int TimeUsed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.UpdateWeapon");
			byte* params = (byte*)malloc(20);
			*(class TrPlayerController**)params = PC;
			*(int*)(params + 4) = WeaponId;
			*(int*)(params + 8) = ActivityId;
			*(int*)(params + 12) = ShotsFired;
			*(int*)(params + 16) = TimeUsed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateDamage(class TrPlayerController* PC, int WeaponId, int Amount, int Dist, bool bKill, bool bVehicle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.UpdateDamage");
			byte* params = (byte*)malloc(24);
			*(class TrPlayerController**)params = PC;
			*(int*)(params + 4) = WeaponId;
			*(int*)(params + 8) = Amount;
			*(int*)(params + 12) = Dist;
			*(bool*)(params + 16) = bKill;
			*(bool*)(params + 20) = bVehicle;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetIdentification(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.SetIdentification");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetActiveClass(class TrPlayerController* PC, int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.SetActiveClass");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = PC;
			*(int*)(params + 4) = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddRepair(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddRepair");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddFlagCap(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddFlagCap");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddFlagGrab(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddFlagGrab");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddFlagReturn(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddFlagReturn");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddMidairKill(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddMidairKill");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddVehicleKill(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddVehicleKill");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetXP(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.SetXP");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = PC;
			*(int*)(params + 4) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetTeam(class TrPlayerController* PC, int TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.SetTeam");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = PC;
			*(int*)(params + 4) = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddVehicleDestruction(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddVehicleDestruction");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpeedSkied(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.SetSpeedSkied");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = PC;
			*(int*)(params + 4) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddDeployableDestruction(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddDeployableDestruction");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddCreditsSpent(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddCreditsSpent");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = PC;
			*(int*)(params + 4) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetDistanceKill(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.SetDistanceKill");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = PC;
			*(int*)(params + 4) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpeedFlagCap(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.SetSpeedFlagCap");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = PC;
			*(int*)(params + 4) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddCreditsEarned(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddCreditsEarned");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = PC;
			*(int*)(params + 4) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddDistanceSkied(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.AddDistanceSkied");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = PC;
			*(int*)(params + 4) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpeedFlagGrab(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.SetSpeedFlagGrab");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = PC;
			*(int*)(params + 4) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetDistanceHeadshot(class TrPlayerController* PC, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.SetDistanceHeadshot");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = PC;
			*(int*)(params + 4) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FallingDeath(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.FallingDeath");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SkiDistance(class TrPlayerController* PC, int Distance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.SkiDistance");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = PC;
			*(int*)(params + 4) = Distance;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BeltKill(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.BeltKill");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CallIn(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.CallIn");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CallInKill(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.CallInKill");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RegeneratedToFull(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.RegeneratedToFull");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FlagGrabSpeed(class TrPlayerController* PC, int Speed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.FlagGrabSpeed");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = PC;
			*(int*)(params + 4) = Speed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void VEHICLEKILL(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.VEHICLEKILL");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InvStationVisited(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.InvStationVisited");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SkiSpeed(class TrPlayerController* PC, int Speed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.SkiSpeed");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = PC;
			*(int*)(params + 4) = Speed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BaseUpgrade(class TrPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.BaseUpgrade");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TrackPlayerMovement(class TrPlayerController* PC, int TimeStamp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.TrackPlayerMovement");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = PC;
			*(int*)(params + 4) = TimeStamp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void WritePlayerStats(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* PRIArray)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrStatsInterface.WritePlayerStats");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = PRIArray;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
