#pragma once
#include "Engine__TriggerVolume.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DynamicTriggerVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DynamicTriggerVolume : public TriggerVolume
	{
	public:
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
	};
}
#undef ADD_VAR
