#pragma once
#include "Engine.UIDataStore_Remote.h"
#include "Core.Object.Pointer.h"
#include "Engine.OnlineSubsystem.h"
#include "Engine.OnlineGameSearch.h"
#include "Engine.OnlineGameSearch.OnlineGameSearchResult.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataStore_OnlineGameSearch." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDataStore_OnlineGameSearch." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.UIDataStore_OnlineGameSearch." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIDataStore_OnlineGameSearch : public UIDataStore_Remote
	{
	public:
		ADD_VAR(::IntProperty, ActiveSearchIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SelectedIndex, 0xFFFFFFFF)
		ADD_OBJECT(OnlineSubsystem, OnlineSub)
		ADD_VAR(::NameProperty, SearchResultsName, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VfTable_IUIListElementCellProvider, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VfTable_IUIListElementProvider, 0xFFFFFFFF)
		void Init()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.Init");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool InvalidateCurrentSearchResults()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.InvalidateCurrentSearchResults");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool SubmitGameSearch(byte ControllerIndex, bool bInvalidateExistingSearchResults)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.SubmitGameSearch");
			byte* params = (byte*)malloc(9);
			*params = ControllerIndex;
			*(bool*)(params + 4) = bInvalidateExistingSearchResults;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool OverrideQuerySubmission(byte ControllerId, class OnlineGameSearch* Search)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.OverrideQuerySubmission");
			byte* params = (byte*)malloc(9);
			*params = ControllerId;
			*(class OnlineGameSearch**)(params + 4) = Search;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void OnSearchComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.OnSearchComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetSearchResultFromIndex(int ListIndex, OnlineGameSearchResult& Result)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.GetSearchResultFromIndex");
			byte* params = (byte*)malloc(16);
			*(int*)params = ListIndex;
			*(OnlineGameSearchResult*)(params + 4) = Result;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Result = *(OnlineGameSearchResult*)(params + 4);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool ShowHostGamercard(byte ControllerIndex, int ListIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.ShowHostGamercard");
			byte* params = (byte*)malloc(9);
			*params = ControllerIndex;
			*(int*)(params + 4) = ListIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void BuildSearchResults()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.BuildSearchResults");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class OnlineGameSearch* GetCurrentGameSearch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.GetCurrentGameSearch");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class OnlineGameSearch**)params;
			free(params);
			return returnVal;
		}
		class OnlineGameSearch* GetActiveGameSearch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.GetActiveGameSearch");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class OnlineGameSearch**)params;
			free(params);
			return returnVal;
		}
		int FindSearchConfigurationIndex(ScriptName SearchTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.FindSearchConfigurationIndex");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SearchTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		void SetCurrentByIndex(int NewIndex, bool bInvalidateExistingSearchResults)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.SetCurrentByIndex");
			byte* params = (byte*)malloc(8);
			*(int*)params = NewIndex;
			*(bool*)(params + 4) = bInvalidateExistingSearchResults;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetCurrentByName(ScriptName SearchName, bool bInvalidateExistingSearchResults)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.SetCurrentByName");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SearchName;
			*(bool*)(params + 8) = bInvalidateExistingSearchResults;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MoveToNext(bool bInvalidateExistingSearchResults)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.MoveToNext");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bInvalidateExistingSearchResults;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MoveToPrevious(bool bInvalidateExistingSearchResults)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.MoveToPrevious");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bInvalidateExistingSearchResults;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearAllSearchResults()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSearch.ClearAllSearchResults");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
