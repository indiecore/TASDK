#pragma once
#include "Core__Interface.h"
#include "Engine__UIDataStore.h"
#include "Engine__UIDataProvider.h"
namespace UnrealScript
{
	class UIDataStoreSubscriber : public Interface
	{
	public:
		void SetDataStoreBinding(ScriptArray<wchar_t> MarkupText, int BindingIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStoreSubscriber.SetDataStoreBinding");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = MarkupText;
			*(int*)(params + 12) = BindingIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetDataStoreBinding(int BindingIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStoreSubscriber.GetDataStoreBinding");
			byte* params = (byte*)malloc(16);
			*(int*)params = BindingIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		bool RefreshSubscriberValue(int BindingIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStoreSubscriber.RefreshSubscriberValue");
			byte* params = (byte*)malloc(8);
			*(int*)params = BindingIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void NotifyDataStoreValueUpdated(class UIDataStore* SourceDataStore, bool bValuesInvalidated, ScriptName PropertyTag, class UIDataProvider* SourceProvider, int ArrayIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStoreSubscriber.NotifyDataStoreValueUpdated");
			byte* params = (byte*)malloc(24);
			*(class UIDataStore**)params = SourceDataStore;
			*(bool*)(params + 4) = bValuesInvalidated;
			*(ScriptName*)(params + 8) = PropertyTag;
			*(class UIDataProvider**)(params + 16) = SourceProvider;
			*(int*)(params + 20) = ArrayIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetBoundDataStores(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& out_BoundDataStores)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStoreSubscriber.GetBoundDataStores");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = out_BoundDataStores;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_BoundDataStores = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		void ClearBoundDataStores()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStoreSubscriber.ClearBoundDataStores");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
