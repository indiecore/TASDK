#pragma once
#include "Core.Interface.h"
#include "Engine.UIDataStore.h"
#include "Engine.UIDataProvider.h"
namespace UnrealScript
{
	class UIDataStoreSubscriber : public Interface
	{
	public:
		void SetDataStoreBinding(ScriptString* MarkupText, int BindingIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStoreSubscriber.SetDataStoreBinding");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = MarkupText;
			*(int*)&params[12] = BindingIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetDataStoreBinding(int BindingIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStoreSubscriber.GetDataStoreBinding");
			byte params[16] = { NULL };
			*(int*)&params[0] = BindingIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		bool RefreshSubscriberValue(int BindingIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStoreSubscriber.RefreshSubscriberValue");
			byte params[8] = { NULL };
			*(int*)&params[0] = BindingIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void NotifyDataStoreValueUpdated(class UIDataStore* SourceDataStore, bool bValuesInvalidated, ScriptName PropertyTag, class UIDataProvider* SourceProvider, int ArrayIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStoreSubscriber.NotifyDataStoreValueUpdated");
			byte params[24] = { NULL };
			*(class UIDataStore**)&params[0] = SourceDataStore;
			*(bool*)&params[4] = bValuesInvalidated;
			*(ScriptName*)&params[8] = PropertyTag;
			*(class UIDataProvider**)&params[16] = SourceProvider;
			*(int*)&params[20] = ArrayIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetBoundDataStores(ScriptArray<class UIDataStore*>& out_BoundDataStores)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStoreSubscriber.GetBoundDataStores");
			byte params[12] = { NULL };
			*(ScriptArray<class UIDataStore*>*)&params[0] = out_BoundDataStores;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_BoundDataStores = *(ScriptArray<class UIDataStore*>*)&params[0];
		}
		void ClearBoundDataStores()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStoreSubscriber.ClearBoundDataStores");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
