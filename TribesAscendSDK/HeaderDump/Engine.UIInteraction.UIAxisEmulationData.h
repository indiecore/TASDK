#pragma once
#include "Engine.UIInteraction.UIKeyRepeatData.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UIInteraction.UIAxisEmulationData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIAxisEmulationData : public UIKeyRepeatData
	{
	public:
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
	};
}
#undef ADD_VAR
