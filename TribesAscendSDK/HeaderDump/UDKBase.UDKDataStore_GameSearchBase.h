#pragma once
#include "Engine.UIDataStore_OnlineGameSearch.h"
#include "UDKBase.UDKUIDataProvider_ServerDetails.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKDataStore_GameSearchBase." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKDataStore_GameSearchBase : public UIDataStore_OnlineGameSearch
	{
	public:
		ADD_OBJECT(UDKUIDataProvider_ServerDetails, ServerDetailsProvider)
		bool GetEnabledMutators(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& MutatorIndices)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKDataStore_GameSearchBase.GetEnabledMutators");
			byte* params = (byte*)malloc(16);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = MutatorIndices;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			MutatorIndices = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void Init()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKDataStore_GameSearchBase.Init");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool SubmitGameSearch(byte ControllerIndex, bool bInvalidateExistingSearchResults)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKDataStore_GameSearchBase.SubmitGameSearch");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKDataStore_GameSearchBase.OnSearchComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool HasOutstandingQueries(bool bRestrictCheckToSelf)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKDataStore_GameSearchBase.HasOutstandingQueries");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bRestrictCheckToSelf;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool HasExistingSearchResults()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKDataStore_GameSearchBase.HasExistingSearchResults");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_OBJECT
