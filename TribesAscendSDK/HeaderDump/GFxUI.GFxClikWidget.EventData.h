#pragma once
#include "GFxUI.GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GFxClikWidget.EventData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GFxClikWidget.EventData." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class EventData
	{
	public:
		ADD_VAR(::IntProperty, lastIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Index, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Button, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, mouseIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Data, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Type, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, Target)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
