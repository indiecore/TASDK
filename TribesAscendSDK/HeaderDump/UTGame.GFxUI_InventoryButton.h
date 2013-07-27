#pragma once
#include "GFxUI.GFxClikWidget.h"
#include "GFxUI.GFxObject.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GFxUI_InventoryButton : public GFxClikWidget
	{
	public:
		ADD_OBJECT(GFxObject, IconMC, 144)
		ADD_STRUCT(ScriptString*, Content, 132)
		void SetContent(ScriptString* newContent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39083);
			byte params[12] = { NULL };
			*(ScriptString**)params = newContent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetIconMC(class GFxObject* iconClip)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39085);
			byte params[4] = { NULL };
			*(class GFxObject**)params = iconClip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
