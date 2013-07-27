#pragma once
#include "Engine.Pawn.h"
#include "Engine.Info.h"
#include "TribesGame.TrVehicle.h"
#include "TribesGame.TrObject.h"
#include "TribesGame.TrDevice_SaberLauncher.h"
#include "TribesGame.TrPlayerController.h"
#include "TribesGame.TrProj_TrackingMissile.h"
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
	class TrSeekingMissileManager : public Info
	{
	public:
		enum ETrackingMissileEvent : byte
		{
			MissileEvent_NewMissileTracking = 0,
			MissileEvent_MissileStoppedTracking = 1,
			MissileEvent_NewSaberLauncherTargeting = 2,
			MissileEvent_SaberLauncherStoppedTargeting = 3,
			MissileEvent_NotifyClientAboutSaberLauncher = 4,
			MissileEvent_MAX = 5,
		};
		class TargetingSaberLauncherInfo
		{
		public:
			ADD_OBJECT(TrDevice_SaberLauncher, SaberLauncher, 0)
			ADD_STRUCT(float, RemainingClientNotificationTime, 8)
			ADD_OBJECT(TrPlayerController, VictimController, 4)
		};
		class SeekingMissileInfo
		{
		public:
			ADD_OBJECT(TrProj_TrackingMissile, Missile, 0)
			ADD_OBJECT(TrPlayerController, VictimController, 4)
		};
		ADD_STRUCT(ScriptArray<TrSeekingMissileManager::TargetingSaberLauncherInfo>, ActiveTargetingSaberLaunchers, 488)
		ADD_STRUCT(ScriptArray<TrSeekingMissileManager::SeekingMissileInfo>, ActiveSeekingMissiles, 476)
		ADD_STRUCT(int, RepCounter, 500)
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddSaberLauncher(class TrDevice_SaberLauncher* SaberLauncherToAdd, TrObject::EMissileLock MissileLockValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.AddSaberLauncher");
			byte params[5] = { NULL };
			*(class TrDevice_SaberLauncher**)&params[0] = SaberLauncherToAdd;
			*(TrObject::EMissileLock*)&params[4] = MissileLockValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveSaberLauncher(class TrDevice_SaberLauncher* SaberLauncherToRemove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.RemoveSaberLauncher");
			byte params[4] = { NULL };
			*(class TrDevice_SaberLauncher**)&params[0] = SaberLauncherToRemove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetNumSaberLaunchersTargetingController(class TrPlayerController* Controller, bool bOnlyClientNotified)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.GetNumSaberLaunchersTargetingController");
			byte params[12] = { NULL };
			*(class TrPlayerController**)&params[0] = Controller;
			*(bool*)&params[4] = bOnlyClientNotified;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int GetNumSaberLaunchersTargetingVehicle(class TrVehicle* targetVehicle, bool bOnlyClientNotified)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.GetNumSaberLaunchersTargetingVehicle");
			byte params[12] = { NULL };
			*(class TrVehicle**)&params[0] = targetVehicle;
			*(bool*)&params[4] = bOnlyClientNotified;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void AddMissile(class TrProj_TrackingMissile* MissileToAdd)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.AddMissile");
			byte params[4] = { NULL };
			*(class TrProj_TrackingMissile**)&params[0] = MissileToAdd;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveMissile(class TrProj_TrackingMissile* MissileToRemove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.RemoveMissile");
			byte params[4] = { NULL };
			*(class TrProj_TrackingMissile**)&params[0] = MissileToRemove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetNumMissilesTrackingController(class TrPlayerController* Controller)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.GetNumMissilesTrackingController");
			byte params[8] = { NULL };
			*(class TrPlayerController**)&params[0] = Controller;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int GetNumMissilesTrackingVehicle(class TrVehicle* targetVehicle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.GetNumMissilesTrackingVehicle");
			byte params[8] = { NULL };
			*(class TrVehicle**)&params[0] = targetVehicle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void VictimControllerUpdated(class TrPlayerController* VictimController, TrSeekingMissileManager::ETrackingMissileEvent MissileEvent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.VictimControllerUpdated");
			byte params[5] = { NULL };
			*(class TrPlayerController**)&params[0] = VictimController;
			*(TrSeekingMissileManager::ETrackingMissileEvent*)&params[4] = MissileEvent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TargetVehicleUpdated(class TrVehicle* targetVehicle, TrSeekingMissileManager::ETrackingMissileEvent MissileEvent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.TargetVehicleUpdated");
			byte params[5] = { NULL };
			*(class TrVehicle**)&params[0] = targetVehicle;
			*(TrSeekingMissileManager::ETrackingMissileEvent*)&params[4] = MissileEvent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BeginSaberLauncherTargeting(class TrPlayerController* VictimController)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.BeginSaberLauncherTargeting");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = VictimController;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopSaberLauncherTargeting(class TrPlayerController* VictimController)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.StopSaberLauncherTargeting");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = VictimController;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BeginMissileTracking(class TrPlayerController* VictimController)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.BeginMissileTracking");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = VictimController;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopMissileTracking(class TrPlayerController* VictimController)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.StopMissileTracking");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = VictimController;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnLeftVehicle(class Pawn* LeavingPawn, class TrVehicle* Vehicle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.PawnLeftVehicle");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = LeavingPawn;
			*(class TrVehicle**)&params[4] = Vehicle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnEnteredVehicle(class Pawn* EnteringPawn, class TrVehicle* Vehicle, int SeatIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeekingMissileManager.PawnEnteredVehicle");
			byte params[12] = { NULL };
			*(class Pawn**)&params[0] = EnteringPawn;
			*(class TrVehicle**)&params[4] = Vehicle;
			*(int*)&params[8] = SeatIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
