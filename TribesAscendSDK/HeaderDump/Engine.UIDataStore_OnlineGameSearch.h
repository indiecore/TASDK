#pragma once
#include "Engine.UIDataStore_Remote.h"
#include "Engine.OnlineSubsystem.h"
#include "Core.Object.h"
#include "Engine.OnlineGameSearch.h"
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
	class UIDataStore_OnlineGameSearch : public UIDataStore_Remote
	{
	public:
		class GameSearchCfg
		{
		public:
			ADD_STRUCT(ScriptArray<class UIDataProvider_Settings*>, SearchResults, 16)
			ADD_STRUCT(ScriptName, SearchName, 32)
			ADD_OBJECT(OnlineGameSearch, Search, 28)
			ADD_OBJECT(UIDataProvider_Settings, DesiredSettingsProvider, 12)
			ADD_OBJECT(ScriptClass, SearchResultsProviderClass, 8)
			ADD_OBJECT(ScriptClass, DefaultGameSettingsClass, 4)
			ADD_OBJECT(ScriptClass, GameSearchClass, 0)
		};
		ADD_STRUCT(ScriptArray<UIDataStore_OnlineGameSearch::GameSearchCfg>, GameSearchCfgList, 148)
		ADD_STRUCT(int, ActiveSearchIndex, 164)
		ADD_STRUCT(int, SelectedIndex, 160)
		ADD_OBJECT(OnlineSubsystem, OnlineSub, 136)
		ADD_STRUCT(ScriptName, SearchResultsName, 128)
		ADD_STRUCT(Object::Pointer, VfTable_IUIListElementCellProvider, 124)
		ADD_STRUCT(Object::Pointer, VfTable_IUIListElementProvider, 120)
		void Init()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.Init");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool InvalidateCurrentSearchResults()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.InvalidateCurrentSearchResults");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool SubmitGameSearch(byte ControllerIndex, bool bInvalidateExistingSearchResults)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.SubmitGameSearch");
			byte params[9] = { NULL };
			params[0] = ControllerIndex;
			*(bool*)&params[4] = bInvalidateExistingSearchResults;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool OverrideQuerySubmission(byte ControllerId, class OnlineGameSearch* Search)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.OverrideQuerySubmission");
			byte params[9] = { NULL };
			params[0] = ControllerId;
			*(class OnlineGameSearch**)&params[4] = Search;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void OnSearchComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.OnSearchComplete");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetSearchResultFromIndex(int ListIndex, OnlineGameSearch::OnlineGameSearchResult& Result)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.GetSearchResultFromIndex");
			byte params[16] = { NULL };
			*(int*)&params[0] = ListIndex;
			*(OnlineGameSearch::OnlineGameSearchResult*)&params[4] = Result;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Result = *(OnlineGameSearch::OnlineGameSearchResult*)&params[4];
			return *(bool*)&params[12];
		}
		bool ShowHostGamercard(byte ControllerIndex, int ListIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.ShowHostGamercard");
			byte params[9] = { NULL };
			params[0] = ControllerIndex;
			*(int*)&params[4] = ListIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void BuildSearchResults()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.BuildSearchResults");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class OnlineGameSearch* GetCurrentGameSearch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.GetCurrentGameSearch");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class OnlineGameSearch**)&params[0];
		}
		class OnlineGameSearch* GetActiveGameSearch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.GetActiveGameSearch");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class OnlineGameSearch**)&params[0];
		}
		int FindSearchConfigurationIndex(ScriptName SearchTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.FindSearchConfigurationIndex");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SearchTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void SetCurrentByIndex(int NewIndex, bool bInvalidateExistingSearchResults)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.SetCurrentByIndex");
			byte params[8] = { NULL };
			*(int*)&params[0] = NewIndex;
			*(bool*)&params[4] = bInvalidateExistingSearchResults;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCurrentByName(ScriptName SearchName, bool bInvalidateExistingSearchResults)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.SetCurrentByName");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SearchName;
			*(bool*)&params[8] = bInvalidateExistingSearchResults;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MoveToNext(bool bInvalidateExistingSearchResults)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.MoveToNext");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bInvalidateExistingSearchResults;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MoveToPrevious(bool bInvalidateExistingSearchResults)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.MoveToPrevious");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bInvalidateExistingSearchResults;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearAllSearchResults()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.ClearAllSearchResults");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
