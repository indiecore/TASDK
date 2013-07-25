#pragma once
#include "Engine.Pawn.h"
#include "Engine.Info.h"
#include "TribesGame.TrVehicle.h"
#include "TribesGame.TrDevice_SaberLauncher.h"
#include "TribesGame.TrPlayerController.h"
#include "TribesGame.TrProj_TrackingMissile.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSeekingMissileManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrSeekingMissileManager : public Info
	{
	public:
		ADD_VAR(::IntProperty, RepCounter, 0xFFFFFFFF)
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddSaberLauncher(class TrDevice_SaberLauncher* SaberLauncherToAdd, byte MissileLockValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.AddSaberLauncher");
			byte* params = (byte*)malloc(5);
			*(class TrDevice_SaberLauncher**)params = SaberLauncherToAdd;
			*(params + 4) = MissileLockValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveSaberLauncher(class TrDevice_SaberLauncher* SaberLauncherToRemove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.RemoveSaberLauncher");
			byte* params = (byte*)malloc(4);
			*(class TrDevice_SaberLauncher**)params = SaberLauncherToRemove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetNumSaberLaunchersTargetingController(class TrPlayerController* Controller, bool bOnlyClientNotified)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.GetNumSaberLaunchersTargetingController");
			byte* params = (byte*)malloc(12);
			*(class TrPlayerController**)params = Controller;
			*(bool*)(params + 4) = bOnlyClientNotified;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int GetNumSaberLaunchersTargetingVehicle(class TrVehicle* targetVehicle, bool bOnlyClientNotified)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.GetNumSaberLaunchersTargetingVehicle");
			byte* params = (byte*)malloc(12);
			*(class TrVehicle**)params = targetVehicle;
			*(bool*)(params + 4) = bOnlyClientNotified;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		void AddMissile(class TrProj_TrackingMissile* MissileToAdd)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.AddMissile");
			byte* params = (byte*)malloc(4);
			*(class TrProj_TrackingMissile**)params = MissileToAdd;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveMissile(class TrProj_TrackingMissile* MissileToRemove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.RemoveMissile");
			byte* params = (byte*)malloc(4);
			*(class TrProj_TrackingMissile**)params = MissileToRemove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetNumMissilesTrackingController(class TrPlayerController* Controller)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.GetNumMissilesTrackingController");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = Controller;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetNumMissilesTrackingVehicle(class TrVehicle* targetVehicle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.GetNumMissilesTrackingVehicle");
			byte* params = (byte*)malloc(8);
			*(class TrVehicle**)params = targetVehicle;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void VictimControllerUpdated(class TrPlayerController* VictimController, byte MissileEvent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.VictimControllerUpdated");
			byte* params = (byte*)malloc(5);
			*(class TrPlayerController**)params = VictimController;
			*(params + 4) = MissileEvent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TargetVehicleUpdated(class TrVehicle* targetVehicle, byte MissileEvent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.TargetVehicleUpdated");
			byte* params = (byte*)malloc(5);
			*(class TrVehicle**)params = targetVehicle;
			*(params + 4) = MissileEvent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BeginSaberLauncherTargeting(class TrPlayerController* VictimController)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.BeginSaberLauncherTargeting");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = VictimController;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopSaberLauncherTargeting(class TrPlayerController* VictimController)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.StopSaberLauncherTargeting");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = VictimController;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BeginMissileTracking(class TrPlayerController* VictimController)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.BeginMissileTracking");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = VictimController;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopMissileTracking(class TrPlayerController* VictimController)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.StopMissileTracking");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = VictimController;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PawnLeftVehicle(class Pawn* LeavingPawn, class TrVehicle* Vehicle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.PawnLeftVehicle");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = LeavingPawn;
			*(class TrVehicle**)(params + 4) = Vehicle;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PawnEnteredVehicle(class Pawn* EnteringPawn, class TrVehicle* Vehicle, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.PawnEnteredVehicle");
			byte* params = (byte*)malloc(12);
			*(class Pawn**)params = EnteringPawn;
			*(class TrVehicle**)(params + 4) = Vehicle;
			*(int*)(params + 8) = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
