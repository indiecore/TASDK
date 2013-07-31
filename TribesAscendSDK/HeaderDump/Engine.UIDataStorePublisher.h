#pragma once
#include "Engine.UIDataStoreSubscriber.h"
#include "Engine.UIDataStore.h"
namespace UnrealScript
{
	class UIDataStorePublisher : public UIDataStoreSubscriber
	{
	public:
		bool SaveSubscriberValue(ScriptArray<class UIDataStore*>& out_BoundDataStores, int BindingIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28908);
			byte params[20] = { NULL };
			*(ScriptArray<class UIDataStore*>*)params = out_BoundDataStores;
			*(int*)&params[12] = BindingIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_BoundDataStores = *(ScriptArray<class UIDataStore*>*)params;
			return *(bool*)&params[16];
		}
	};
}
