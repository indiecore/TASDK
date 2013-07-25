#pragma once
#include "Core__Object.h"
#include "TribesGame__TrStatsInterface.h"
#include "TribesGame__TrGame.h"
#include "TribesGame__TrPlayerController.h"
#include "Engine__Controller.h"
#include "TribesGame__TrVehicle.h"
#include "UTGame__UTPlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAccoladeManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAccoladeManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAccoladeManager : public Object
	{
	public:
		ADD_VAR(::IntProperty, m_nLastFlagReturnTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastFlagGrabTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MAXIMUM_EMERGENCY_GRAB_DISTANCE, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MAXIMUM_FLAG_DEFENSE_DISTANCE, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MINIMUM_ULTRA_GRAB_SPEED, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MINIMUM_FAST_GRAB_SPEED, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MAXIMUM_LLAMA_GRAB_SPEED, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MINIMUM_TIME_FLAG_CREDITS, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nCurrSpinfusorKillStreak, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nCurrExplosiveKillStreak, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nCurrSnipingKillStreak, 0xFFFFFFFF)
		ADD_OBJECT(TrStatsInterface, Stats)
		ADD_OBJECT(TrPlayerController, m_TrPC)
		ADD_OBJECT(TrGame, m_TrG)
		int GetFlagDistance(Vector Loc1, Vector Loc2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.GetFlagDistance");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = Loc1;
			*(Vector*)(params + 12) = Loc2;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 24);
			free(params);
			return returnVal;
		}
		void Initialize(class TrPlayerController* TrPC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.Initialize");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = TrPC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void KilledTheRabbit(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.KilledTheRabbit");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void KilledTheFlagHolder()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.KilledTheFlagHolder");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateStandardKillingSpree(class UTPlayerReplicationInfo* Other, int currentSpree)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.UpdateStandardKillingSpree");
			byte* params = (byte*)malloc(8);
			*(class UTPlayerReplicationInfo**)params = Other;
			*(int*)(params + 4) = currentSpree;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(int*)params = AssistCount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FlagCapture(bool bUnAssisted)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.FlagCapture");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bUnAssisted;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(int*)params = MultiKillLevel;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void VehicleDestroyed(class TrVehicle* aVehicle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.VehicleDestroyed");
			byte* params = (byte*)malloc(4);
			*(class TrVehicle**)params = aVehicle;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateSpecialAccolades(class Controller* Victim)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.UpdateSpecialAccolades");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = Victim;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void QueueAccolade(ScriptClass* Accolade, int ModifiedCredits)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.QueueAccolade");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = Accolade;
			*(int*)(params + 4) = ModifiedCredits;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CreditsGiven(ScriptClass* Accolade)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.CreditsGiven");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = Accolade;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void BroadcastAccolade(ScriptClass* Accolade)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAccoladeManager.BroadcastAccolade");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = Accolade;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
