#pragma once
#include "Engine__OnlineGameSearch.h"
#include "Core__Interface.h"
#include "Engine__OnlineStatsRead.h"
#include "Engine__OnlineGameSettings.h"
namespace UnrealScript
{
	class OnlineSuppliedUIInterface : public Interface
	{
	public:
		void OnShowOnlineStatsUIComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSuppliedUIInterface.OnShowOnlineStatsUIComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShowOnlineStatsUI(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Players, class OnlineStatsRead* StatsRead)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSuppliedUIInterface.ShowOnlineStatsUI");
			byte* params = (byte*)malloc(20);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = Players;
			*(class OnlineStatsRead**)(params + 12) = StatsRead;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Players = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void AddShowOnlineStatsUICompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ShowOnlineStatsUICompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSuppliedUIInterface.AddShowOnlineStatsUICompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ShowOnlineStatsUICompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearShowOnlineStatsUICompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ShowOnlineStatsUICompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSuppliedUIInterface.ClearShowOnlineStatsUICompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ShowOnlineStatsUICompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShowMatchmakingUI(byte SearchingPlayerNum, class OnlineGameSearch* SearchSettings, class OnlineGameSettings* GameSettings)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSuppliedUIInterface.ShowMatchmakingUI");
			byte* params = (byte*)malloc(13);
			*params = SearchingPlayerNum;
			*(class OnlineGameSearch**)(params + 4) = SearchSettings;
			*(class OnlineGameSettings**)(params + 8) = GameSettings;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
	};
}
