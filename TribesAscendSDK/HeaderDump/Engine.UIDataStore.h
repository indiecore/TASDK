#pragma once
#include "Engine.LocalPlayer.h"
#include "Engine.UIDataProvider.h"
#include "Engine.DataStoreClient.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UIDataStore : public UIDataProvider
	{
	public:
		ADD_STRUCT(ScriptName, Tag, 88)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, RefreshSubscriberNotifies, 96)
		bool NotifyGameSessionEnded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore.NotifyGameSessionEnded");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void OnDataStoreValueUpdated(class UIDataStore* SourceDataStore, bool bValuesInvalidated, ScriptName PropertyTag, class UIDataProvider* SourceProvider, int ArrayIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore.OnDataStoreValueUpdated");
			byte params[24] = { NULL };
			*(class UIDataStore**)&params[0] = SourceDataStore;
			*(bool*)&params[4] = bValuesInvalidated;
			*(ScriptName*)&params[8] = PropertyTag;
			*(class UIDataProvider**)&params[16] = SourceProvider;
			*(int*)&params[20] = ArrayIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Registered(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore.Registered");
			byte params[4] = { NULL };
			*(class LocalPlayer**)&params[0] = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Unregistered(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore.Unregistered");
			byte params[4] = { NULL };
			*(class LocalPlayer**)&params[0] = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SubscriberAttached(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* Subscriber)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore.SubscriberAttached");
			byte params[8] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)&params[0] = Subscriber;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SubscriberDetached(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* Subscriber)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore.SubscriberDetached");
			byte params[8] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)&params[0] = Subscriber;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RefreshSubscribers(ScriptName PropertyTag, bool bInvalidateValues, class UIDataProvider* SourceProvider, int ArrayIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore.RefreshSubscribers");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = PropertyTag;
			*(bool*)&params[8] = bInvalidateValues;
			*(class UIDataProvider**)&params[12] = SourceProvider;
			*(int*)&params[16] = ArrayIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnCommit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore.OnCommit");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class DataStoreClient* GetDataStoreClient()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore.GetDataStoreClient");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class DataStoreClient**)&params[0];
		}
	};
}
#undef ADD_STRUCT
