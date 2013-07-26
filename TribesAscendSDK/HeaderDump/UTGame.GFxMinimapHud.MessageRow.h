#pragma once
#include "GFxUI.GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GFxMinimapHud.MessageRow." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GFxMinimapHud.MessageRow." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MessageRow
	{
	public:
		ADD_VAR(::IntProperty, Y, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StartFadeTime, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, TF)
		ADD_OBJECT(GFxObject, MC)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
