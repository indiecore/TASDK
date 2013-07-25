#pragma once
#include "Engine.UIRoot.h"
#include "Engine.UIDataStore.h"
#include "Engine.LocalPlayer.h"
namespace UnrealScript
{
	class DataStoreClient : public UIRoot
	{
	public:
		class UIDataStore* FindDataStore(ScriptName DataStoreTag, class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DataStoreClient.FindDataStore");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = DataStoreTag;
			*(class LocalPlayer**)(params + 8) = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UIDataStore**)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptClass* FindDataStoreClass(ScriptClass* RequiredMetaClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DataStoreClient.FindDataStoreClass");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = RequiredMetaClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 4);
			free(params);
			return returnVal;
		}
		class UIDataStore* CreateDataStore(ScriptClass* DataStoreClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DataStoreClient.CreateDataStore");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = DataStoreClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UIDataStore**)(params + 4);
			free(params);
			return returnVal;
		}
		bool RegisterDataStore(class UIDataStore* DataStore, class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DataStoreClient.RegisterDataStore");
			byte* params = (byte*)malloc(12);
			*(class UIDataStore**)params = DataStore;
			*(class LocalPlayer**)(params + 4) = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void GetPlayerDataStoreClasses(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& out_DataStoreClasses)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DataStoreClient.GetPlayerDataStoreClasses");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = out_DataStoreClasses;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_DataStoreClasses = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		bool UnregisterDataStore(class UIDataStore* DataStore)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DataStoreClient.UnregisterDataStore");
			byte* params = (byte*)malloc(8);
			*(class UIDataStore**)params = DataStore;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		int FindPlayerDataStoreIndex(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DataStoreClient.FindPlayerDataStoreIndex");
			byte* params = (byte*)malloc(8);
			*(class LocalPlayer**)params = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void NotifyGameSessionEnded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DataStoreClient.NotifyGameSessionEnded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DebugDumpDataStoreInfo(bool bVerbose)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DataStoreClient.DebugDumpDataStoreInfo");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVerbose;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
