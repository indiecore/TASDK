#pragma once
#include "Engine.UIRoot.h"
#include "Engine.UIDataStore.h"
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
	class DataStoreClient : public UIRoot
	{
	public:
		struct PlayerDataStoreGroup
		{
		public:
			ADD_STRUCT(ScriptArray<class UIDataStore*>, DataStores, 4)
			ADD_OBJECT(LocalPlayer, PlayerOwner, 0)
		};
		ADD_STRUCT(ScriptArray<ScriptString*>, GlobalDataStoreClasses, 60)
		ADD_STRUCT(ScriptArray<class UIDataStore*>, GlobalDataStores, 72)
		ADD_STRUCT(ScriptArray<ScriptString*>, PlayerDataStoreClassNames, 84)
		ADD_STRUCT(ScriptArray<ScriptClass*>, PlayerDataStoreClasses, 96)
		ADD_STRUCT(ScriptArray<DataStoreClient::PlayerDataStoreGroup>, PlayerDataStores, 108)
		class UIDataStore* FindDataStore(ScriptName DataStoreTag, class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7802);
			byte params[16] = { NULL };
			*(ScriptName*)params = DataStoreTag;
			*(class LocalPlayer**)&params[8] = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UIDataStore**)&params[12];
		}
		ScriptClass* FindDataStoreClass(ScriptClass* RequiredMetaClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7804);
			byte params[8] = { NULL };
			*(ScriptClass**)params = RequiredMetaClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[4];
		}
		class UIDataStore* CreateDataStore(ScriptClass* DataStoreClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7806);
			byte params[8] = { NULL };
			*(ScriptClass**)params = DataStoreClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UIDataStore**)&params[4];
		}
		bool RegisterDataStore(class UIDataStore* DataStore, class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7808);
			byte params[12] = { NULL };
			*(class UIDataStore**)params = DataStore;
			*(class LocalPlayer**)&params[4] = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void GetPlayerDataStoreClasses(ScriptArray<ScriptClass*>& out_DataStoreClasses)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7818);
			byte params[12] = { NULL };
			*(ScriptArray<ScriptClass*>*)params = out_DataStoreClasses;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_DataStoreClasses = *(ScriptArray<ScriptClass*>*)params;
		}
		bool UnregisterDataStore(class UIDataStore* DataStore)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7824);
			byte params[8] = { NULL };
			*(class UIDataStore**)params = DataStore;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		int FindPlayerDataStoreIndex(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13653);
			byte params[8] = { NULL };
			*(class LocalPlayer**)params = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void NotifyGameSessionEnded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13661);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DebugDumpDataStoreInfo(bool bVerbose)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13668);
			byte params[4] = { NULL };
			*(bool*)params = bVerbose;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
