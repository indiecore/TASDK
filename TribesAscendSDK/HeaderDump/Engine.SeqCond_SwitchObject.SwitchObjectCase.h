#pragma once
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SeqCond_SwitchObject.SwitchObjectCase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty SeqCond_SwitchObject.SwitchObjectCase." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SwitchObjectCase
	{
	public:
		ADD_VAR(::BoolProperty, bDefaultValue, 0x2)
		ADD_VAR(::BoolProperty, bFallThru, 0x1)
		ADD_OBJECT(Object, ObjectValue)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
