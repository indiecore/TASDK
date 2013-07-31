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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28889);
			byte params[16] = { NULL };
			*(ScriptString**)params = MarkupText;
			*(int*)&params[12] = BindingIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetDataStoreBinding(int BindingIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28892);
			byte params[16] = { NULL };
			*(int*)params = BindingIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		bool RefreshSubscriberValue(int BindingIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28895);
			byte params[8] = { NULL };
			*(int*)params = BindingIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void NotifyDataStoreValueUpdated(class UIDataStore* SourceDataStore, bool bValuesInvalidated, ScriptName PropertyTag, class UIDataProvider* SourceProvider, int ArrayIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28898);
			byte params[24] = { NULL };
			*(class UIDataStore**)params = SourceDataStore;
			*(bool*)&params[4] = bValuesInvalidated;
			*(ScriptName*)&params[8] = PropertyTag;
			*(class UIDataProvider**)&params[16] = SourceProvider;
			*(int*)&params[20] = ArrayIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetBoundDataStores(ScriptArray<class UIDataStore*>& out_BoundDataStores)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28904);
			byte params[12] = { NULL };
			*(ScriptArray<class UIDataStore*>*)params = out_BoundDataStores;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_BoundDataStores = *(ScriptArray<class UIDataStore*>*)params;
		}
		void ClearBoundDataStores()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28907);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
