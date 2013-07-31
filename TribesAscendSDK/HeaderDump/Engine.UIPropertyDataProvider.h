#pragma once
#include "Core.Property.h"
#include "Engine.UIDataProvider.h"
#include "Engine.UIRoot.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UIPropertyDataProvider : public UIDataProvider
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptClass*>, ComplexPropertyTypes, 88)
		bool CanSupportComplexPropertyType(class Property* UnsupportedProperty)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22596);
			byte params[8] = { NULL };
			*(class Property**)params = UnsupportedProperty;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool GetCustomPropertyValue(UIRoot::UIProviderScriptFieldValue& PropertyValue, int ArrayIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22599);
			byte params[92] = { NULL };
			*(UIRoot::UIProviderScriptFieldValue*)params = PropertyValue;
			*(int*)&params[84] = ArrayIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PropertyValue = *(UIRoot::UIProviderScriptFieldValue*)params;
			return *(bool*)&params[88];
		}
	};
}
#undef ADD_STRUCT
