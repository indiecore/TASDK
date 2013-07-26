#pragma once
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameViewportClient.DebugDisplayProperty." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameViewportClient.DebugDisplayProperty." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class DebugDisplayProperty
	{
	public:
		ADD_VAR(::BoolProperty, bSpecialProperty, 0x1)
		ADD_VAR(::NameProperty, PropertyName, 0xFFFFFFFF)
		ADD_OBJECT(Object, Obj)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
