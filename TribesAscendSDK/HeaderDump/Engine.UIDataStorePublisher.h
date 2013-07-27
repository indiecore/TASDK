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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStorePublisher.SaveSubscriberValue");
			byte params[20] = { NULL };
			*(ScriptArray<class UIDataStore*>*)&params[0] = out_BoundDataStores;
			*(int*)&params[12] = BindingIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_BoundDataStores = *(ScriptArray<class UIDataStore*>*)&params[0];
			return *(bool*)&params[16];
		}
	};
}
