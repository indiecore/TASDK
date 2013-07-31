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
		int GetFlagDistance(Vector Loc1, Vector Loc2)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66190);
			byte params[28] = { NULL };
			*(Vector*)params = Loc1;
			*(Vector*)&params[12] = Loc2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[24];
		}
		void Initialize(class TrPlayerController* TrPC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66194);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = TrPC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetStreaks()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66197);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GiveAssist()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66198);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GiveVehicleAssist()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66199);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KillAsRabbit(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66200);
			byte params[8] = { NULL };
			*(class Controller**)params = Killer;
			*(class Controller**)&params[4] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KilledTheRabbit(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66203);
			byte params[8] = { NULL };
			*(class Controller**)params = Killer;
			*(class Controller**)&params[4] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KilledTheFlagHolder()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66206);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateStandardKillingSpree(class UTPlayerReplicationInfo* Other, int currentSpree)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66207);
			byte params[8] = { NULL };
			*(class UTPlayerReplicationInfo**)params = Other;
			*(int*)&params[4] = currentSpree;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void KilledGenerator()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66210);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RepairedBase()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66211);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KilledBaseTurret()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66212);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KilledBaseRadar()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66213);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FlagGrab()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66214);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FlagGrabDeathmatch()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66220);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FlagHeld()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66221);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FlagAssist(int AssistCount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66222);
			byte params[4] = { NULL };
			*(int*)params = AssistCount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FlagCapture(bool bUnAssisted)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66225);
			byte params[4] = { NULL };
			*(bool*)params = bUnAssisted;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FlagReturn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66227);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NoJoy()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66228);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GameCompleted()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66229);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GameWon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66230);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateMultiKills(int MultiKillLevel)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66231);
			byte params[4] = { NULL };
			*(int*)params = MultiKillLevel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VehicleDestroyed(class TrVehicle* aVehicle)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66233);
			byte params[4] = { NULL };
			*(class TrVehicle**)params = aVehicle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateSpecialAccolades(class Controller* Victim)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66236);
			byte params[4] = { NULL };
			*(class Controller**)params = Victim;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void QueueAccolade(ScriptClass* Accolade, int ModifiedCredits)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66270);
			byte params[8] = { NULL };
			*(ScriptClass**)params = Accolade;
			*(int*)&params[4] = ModifiedCredits;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CreditsGiven(ScriptClass* Accolade)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66275);
			byte params[8] = { NULL };
			*(ScriptClass**)params = Accolade;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void BroadcastAccolade(ScriptClass* Accolade)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66278);
			byte params[4] = { NULL };
			*(ScriptClass**)params = Accolade;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
