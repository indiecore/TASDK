#pragma once
#include "Engine.LocalPlayer.h"
#include "Engine.UIDataProvider.h"
#include "Engine.DataStoreClient.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataStore." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIDataStore : public UIDataProvider
	{
	public:
		ADD_VAR(::NameProperty, Tag, 0xFFFFFFFF)
		bool NotifyGameSessionEnded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore.NotifyGameSessionEnded");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void OnDataStoreValueUpdated(class UIDataStore* SourceDataStore, bool bValuesInvalidated, ScriptName PropertyTag, class UIDataProvider* SourceProvider, int ArrayIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore.OnDataStoreValueUpdated");
			byte* params = (byte*)malloc(24);
			*(class UIDataStore**)params = SourceDataStore;
			*(bool*)(params + 4) = bValuesInvalidated;
			*(ScriptName*)(params + 8) = PropertyTag;
			*(class UIDataProvider**)(params + 16) = SourceProvider;
			*(int*)(params + 20) = ArrayIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Registered(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore.Registered");
			byte* params = (byte*)malloc(4);
			*(class LocalPlayer**)params = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Unregistered(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore.Unregistered");
			byte* params = (byte*)malloc(4);
			*(class LocalPlayer**)params = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SubscriberAttached(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* Subscriber)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore.SubscriberAttached");
			byte* params = (byte*)malloc(8);
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params = Subscriber;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SubscriberDetached(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* Subscriber)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore.SubscriberDetached");
			byte* params = (byte*)malloc(8);
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params = Subscriber;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RefreshSubscribers(ScriptName PropertyTag, bool bInvalidateValues, class UIDataProvider* SourceProvider, int ArrayIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore.RefreshSubscribers");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = PropertyTag;
			*(bool*)(params + 8) = bInvalidateValues;
			*(class UIDataProvider**)(params + 12) = SourceProvider;
			*(int*)(params + 16) = ArrayIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnCommit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore.OnCommit");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class DataStoreClient* GetDataStoreClient()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore.GetDataStoreClient");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class DataStoreClient**)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
