#pragma once
#include "Engine.UIDataStore_OnlineGameSearch.h"
#include "UDKBase.UDKUIDataProvider_ServerDetails.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UDKDataStore_GameSearchBase : public UIDataStore_OnlineGameSearch
	{
	public:
		ADD_OBJECT(UDKUIDataProvider_ServerDetails, ServerDetailsProvider, 168)
		bool GetEnabledMutators(ScriptArray<int>& MutatorIndices)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34756);
			byte params[16] = { NULL };
			*(ScriptArray<int>*)params = MutatorIndices;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			MutatorIndices = *(ScriptArray<int>*)params;
			return *(bool*)&params[12];
		}
		void Init()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34760);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool SubmitGameSearch(byte ControllerIndex, bool bInvalidateExistingSearchResults)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34761);
			byte params[9] = { NULL };
			*params = ControllerIndex;
			*(bool*)&params[4] = bInvalidateExistingSearchResults;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void OnSearchComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34766);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool HasOutstandingQueries(bool bRestrictCheckToSelf)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34768);
			byte params[8] = { NULL };
			*(bool*)params = bRestrictCheckToSelf;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool HasExistingSearchResults()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34773);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
	};
}
#undef ADD_OBJECT
