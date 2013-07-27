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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13666);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void OnDataStoreValueUpdated(class UIDataStore* SourceDataStore, bool bValuesInvalidated, ScriptName PropertyTag, class UIDataProvider* SourceProvider, int ArrayIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28432);
			byte params[24] = { NULL };
			*(class UIDataStore**)params = SourceDataStore;
			*(bool*)&params[4] = bValuesInvalidated;
			*(ScriptName*)&params[8] = PropertyTag;
			*(class UIDataProvider**)&params[16] = SourceProvider;
			*(int*)&params[20] = ArrayIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Registered(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28439);
			byte params[4] = { NULL };
			*(class LocalPlayer**)params = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Unregistered(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28441);
			byte params[4] = { NULL };
			*(class LocalPlayer**)params = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SubscriberAttached(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* Subscriber)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28443);
			byte params[8] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params = Subscriber;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SubscriberDetached(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* Subscriber)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28446);
			byte params[8] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params = Subscriber;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RefreshSubscribers(ScriptName PropertyTag, bool bInvalidateValues, class UIDataProvider* SourceProvider, int ArrayIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28449);
			byte params[20] = { NULL };
			*(ScriptName*)params = PropertyTag;
			*(bool*)&params[8] = bInvalidateValues;
			*(class UIDataProvider**)&params[12] = SourceProvider;
			*(int*)&params[16] = ArrayIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnCommit()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28458);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class DataStoreClient* GetDataStoreClient()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28459);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class DataStoreClient**)params;
		}
	};
}
#undef ADD_STRUCT
