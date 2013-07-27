#pragma once
#include "Engine.OnlineGameSettings.h"
#include "Core.Interface.h"
#include "Engine.OnlineSubsystem.h"
#include "Engine.OnlineStatsRead.h"
#include "Engine.OnlineGameSearch.h"
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
		bool ShowOnlineStatsUI(ScriptArray<OnlineSubsystem::UniqueNetId>& Players, class OnlineStatsRead* StatsRead)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSuppliedUIInterface.ShowOnlineStatsUI");
			byte params[20] = { NULL };
			*(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[0] = Players;
			*(class OnlineStatsRead**)&params[12] = StatsRead;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Players = *(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[0];
			return *(bool*)&params[16];
		}
		void AddShowOnlineStatsUICompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ShowOnlineStatsUICompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSuppliedUIInterface.AddShowOnlineStatsUICompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ShowOnlineStatsUICompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearShowOnlineStatsUICompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ShowOnlineStatsUICompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSuppliedUIInterface.ClearShowOnlineStatsUICompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ShowOnlineStatsUICompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShowMatchmakingUI(byte SearchingPlayerNum, class OnlineGameSearch* SearchSettings, class OnlineGameSettings* GameSettings)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSuppliedUIInterface.ShowMatchmakingUI");
			byte params[13] = { NULL };
			params[0] = SearchingPlayerNum;
			*(class OnlineGameSearch**)&params[4] = SearchSettings;
			*(class OnlineGameSettings**)&params[8] = GameSettings;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
	};
}
