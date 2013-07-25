#pragma once
#include "UDKBase__UDKDataStore_GameSearchBase.h"
#include "UTGame__UTDataStore_GameSearchHistory.h"
#include "Engine__LocalPlayer.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTDataStore_GameSearchDM." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTDataStore_GameSearchDM : public UDKDataStore_GameSearchBase
	{
	public:
		ADD_OBJECT(UTDataStore_GameSearchHistory, HistoryGameSearchDataStore)
		ADD_OBJECT(ScriptClass, HistoryGameSearchDataStoreClass)
		void Registered(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchDM.Registered");
			byte* params = (byte*)malloc(4);
			*(class LocalPlayer**)params = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool SubmitGameSearch(byte ControllerIndex, bool bInvalidateExistingSearchResults)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchDM.SubmitGameSearch");
			byte* params = (byte*)malloc(9);
			*params = ControllerIndex;
			*(bool*)(params + 4) = bInvalidateExistingSearchResults;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool HasOutstandingQueries(bool bRestrictCheckToSelf)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchDM.HasOutstandingQueries");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bRestrictCheckToSelf;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		int FindStoredSearchIndex(ScriptName GameSearchName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchDM.FindStoredSearchIndex");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = GameSearchName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int FindStoredSettingValueIndex(int StoredGameSearchIndex, int LocalizedSettingId, bool bAddIfNecessary)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchDM.FindStoredSettingValueIndex");
			byte* params = (byte*)malloc(16);
			*(int*)params = StoredGameSearchIndex;
			*(int*)(params + 4) = LocalizedSettingId;
			*(bool*)(params + 8) = bAddIfNecessary;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		void LoadGameSearchParameters()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchDM.LoadGameSearchParameters");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SaveGameSearchParameters()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDataStore_GameSearchDM.SaveGameSearchParameters");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_OBJECT
