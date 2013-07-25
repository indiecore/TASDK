#pragma once
#include "Engine__UIDataStoreSubscriber.h"
namespace UnrealScript
{
	class UIDataStorePublisher : public UIDataStoreSubscriber
	{
	public:
		bool SaveSubscriberValue(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& out_BoundDataStores, int BindingIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStorePublisher.SaveSubscriberValue");
			byte* params = (byte*)malloc(20);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = out_BoundDataStores;
			*(int*)(params + 12) = BindingIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_BoundDataStores = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
	};
}
