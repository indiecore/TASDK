#pragma once
#include "Engine.Controller.h"
#include "TribesGame.TrStatsInterface.h"
#include "Core.Object.h"
#include "TribesGame.TrPlayerController.h"
#include "TribesGame.TrVehicle.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#include "TribesGame.TrGame.h"
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
	class TrAccoladeManager : public Object
	{
	public:
		ADD_STRUCT(int, m_nLastFlagReturnTime, 112)
		ADD_STRUCT(int, m_nLastFlagGrabTime, 108)
		ADD_STRUCT(int, MAXIMUM_EMERGENCY_GRAB_DISTANCE, 104)
		ADD_STRUCT(int, MAXIMUM_FLAG_DEFENSE_DISTANCE, 100)
		ADD_STRUCT(int, MINIMUM_ULTRA_GRAB_SPEED, 96)
		ADD_STRUCT(int, MINIMUM_FAST_GRAB_SPEED, 92)
		ADD_STRUCT(int, MAXIMUM_LLAMA_GRAB_SPEED, 88)
		ADD_STRUCT(int, MINIMUM_TIME_FLAG_CREDITS, 84)
		ADD_STRUCT(int, m_nCurrSpinfusorKillStreak, 80)
		ADD_STRUCT(int, m_nCurrExplosiveKillStreak, 76)
		ADD_STRUCT(int, m_nCurrSnipingKillStreak, 72)
		ADD_OBJECT(TrStatsInterface, Stats, 68)
		ADD_OBJECT(TrPlayerController, m_TrPC, 64)
		ADD_OBJECT(TrGame, m_TrG, 60)
		int GetFlagDistance(Object::Vector Loc1, Object::Vector Loc2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.GetFlagDistance");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = Loc1;
			*(Object::Vector*)&params[12] = Loc2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[24];
		}
		void Initialize(class TrPlayerController* TrPC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.Initialize");
			byte params[4] = { NULL };
			*(class TrPlayerController**)&params[0] = TrPC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetStreaks()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.ResetStreaks");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GiveAssist()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.GiveAssist");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GiveVehicleAssist()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.GiveVehicleAssist");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KillAsRabbit(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.KillAsRabbit");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = Killer;
			*(class Controller**)&params[4] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KilledTheRabbit(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.KilledTheRabbit");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = Killer;
			*(class Controller**)&params[4] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KilledTheFlagHolder()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.KilledTheFlagHolder");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateStandardKillingSpree(class UTPlayerReplicationInfo* Other, int currentSpree)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.UpdateStandardKillingSpree");
			byte params[8] = { NULL };
			*(class UTPlayerReplicationInfo**)&params[0] = Other;
			*(int*)&params[4] = currentSpree;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KilledGenerator()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.KilledGenerator");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RepairedBase()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.RepairedBase");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KilledBaseTurret()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.KilledBaseTurret");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KilledBaseRadar()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.KilledBaseRadar");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FlagGrab()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.FlagGrab");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FlagGrabDeathmatch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.FlagGrabDeathmatch");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FlagHeld()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.FlagHeld");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FlagAssist(int AssistCount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.FlagAssist");
			byte params[4] = { NULL };
			*(int*)&params[0] = AssistCount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FlagCapture(bool bUnAssisted)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.FlagCapture");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bUnAssisted;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FlagReturn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.FlagReturn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NoJoy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.NoJoy");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GameCompleted()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.GameCompleted");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GameWon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.GameWon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateMultiKills(int MultiKillLevel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.UpdateMultiKills");
			byte params[4] = { NULL };
			*(int*)&params[0] = MultiKillLevel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VehicleDestroyed(class TrVehicle* aVehicle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.VehicleDestroyed");
			byte params[4] = { NULL };
			*(class TrVehicle**)&params[0] = aVehicle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateSpecialAccolades(class Controller* Victim)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.UpdateSpecialAccolades");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = Victim;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void QueueAccolade(ScriptClass* Accolade, int ModifiedCredits)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.QueueAccolade");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = Accolade;
			*(int*)&params[4] = ModifiedCredits;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CreditsGiven(ScriptClass* Accolade)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.CreditsGiven");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = Accolade;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void BroadcastAccolade(ScriptClass* Accolade)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.BroadcastAccolade");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = Accolade;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
