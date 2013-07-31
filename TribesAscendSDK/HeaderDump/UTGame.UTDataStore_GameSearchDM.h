#pragma once
#include "UTGame.UTDataStore_GameSearchHistory.h"
#include "UDKBase.UDKDataStore_GameSearchBase.h"
#include "Engine.LocalPlayer.h"
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
	class UTDataStore_GameSearchDM : public UDKDataStore_GameSearchBase
	{
	public:
		struct PersistentLocalizedSettingValue
		{
		public:
			ADD_STRUCT(int, ValueId, 4)
			ADD_STRUCT(int, SettingId, 0)
		};
		struct GameSearchSettingsStorage
		{
		public:
			ADD_STRUCT(ScriptArray<UTDataStore_GameSearchDM::PersistentLocalizedSettingValue>, StoredValues, 8)
			ADD_STRUCT(ScriptName, GameSearchName, 0)
		};
		ADD_STRUCT(ScriptArray<UTDataStore_GameSearchDM::GameSearchSettingsStorage>, StoredGameSearchValues, 180)
		ADD_OBJECT(UTDataStore_GameSearchHistory, HistoryGameSearchDataStore, 176)
		ADD_OBJECT(ScriptClass, HistoryGameSearchDataStoreClass, 172)
		void Registered(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46887);
			byte params[4] = { NULL };
			*(class LocalPlayer**)params = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SubmitGameSearch(byte ControllerIndex, bool bInvalidateExistingSearchResults)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46891);
			byte params[9] = { NULL };
			*params = ControllerIndex;
			*(bool*)&params[4] = bInvalidateExistingSearchResults;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool HasOutstandingQueries(bool bRestrictCheckToSelf)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46895);
			byte params[8] = { NULL };
			*(bool*)params = bRestrictCheckToSelf;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		int FindStoredSearchIndex(ScriptName GameSearchName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46906);
			byte params[12] = { NULL };
			*(ScriptName*)params = GameSearchName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int FindStoredSettingValueIndex(int StoredGameSearchIndex, int LocalizedSettingId, bool bAddIfNecessary)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46911);
			byte params[16] = { NULL };
			*(int*)params = StoredGameSearchIndex;
			*(int*)&params[4] = LocalizedSettingId;
			*(bool*)&params[8] = bAddIfNecessary;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		void LoadGameSearchParameters()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46918);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SaveGameSearchParameters()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46926);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
