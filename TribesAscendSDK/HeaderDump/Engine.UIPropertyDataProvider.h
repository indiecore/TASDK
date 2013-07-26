#pragma once
#include "Engine.UIRoot.UIProviderScriptFieldValue.h"
#include "Core.Property.h"
#include "Engine.UIDataProvider.h"
namespace UnrealScript
{
	class UIPropertyDataProvider : public UIDataProvider
	{
	public:
		bool CanSupportComplexPropertyType(class Property* UnsupportedProperty)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIPropertyDataProvider.CanSupportComplexPropertyType");
			byte* params = (byte*)malloc(8);
			*(class Property**)params = UnsupportedProperty;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool GetCustomPropertyValue(UIProviderScriptFieldValue& PropertyValue, int ArrayIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIPropertyDataProvider.GetCustomPropertyValue");
			byte* params = (byte*)malloc(92);
			*(UIProviderScriptFieldValue*)params = PropertyValue;
			*(int*)(params + 84) = ArrayIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			PropertyValue = *(UIProviderScriptFieldValue*)params;
			auto returnVal = *(bool*)(params + 88);
			free(params);
			return returnVal;
		}
	};
}
