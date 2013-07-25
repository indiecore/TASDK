#pragma once
#include "Engine.UIDataStore_OnlineGameSearch.h"
#include "UDKBase.UDKUIDataProvider_ServerDetails.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDataStore_OnlineGameSearch." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDataStore_OnlineGameSearch : public UIDataStore_OnlineGameSearch
	{
	public:
		ADD_OBJECT(UDKUIDataProvider_ServerDetails, ServerDetailsProvider)
		void Init()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDataStore_OnlineGameSearch.Init");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool SubmitGameSearch(byte ControllerIndex, bool bInvalidateExistingSearchResults)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDataStore_OnlineGameSearch.SubmitGameSearch");
			byte* params = (byte*)malloc(9);
			*params = ControllerIndex;
			*(bool*)(params + 4) = bInvalidateExistingSearchResults;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void OnSearchComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDataStore_OnlineGameSearch.OnSearchComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool HasOutstandingQueries(bool bRestrictCheckToSelf)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDataStore_OnlineGameSearch.HasOutstandingQueries");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bRestrictCheckToSelf;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool HasExistingSearchResults()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDataStore_OnlineGameSearch.HasExistingSearchResults");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_OBJECT
