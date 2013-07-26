#pragma once
#include "Engine.LevelStreaming.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TriggerStreamingLevel.LevelStreamingData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TriggerStreamingLevel.LevelStreamingData." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class LevelStreamingData
	{
	public:
		ADD_OBJECT(LevelStreaming, Level)
		ADD_VAR(::BoolProperty, bShouldBlockOnLoad, 0x4)
		ADD_VAR(::BoolProperty, bShouldBeVisible, 0x2)
		ADD_VAR(::BoolProperty, bShouldBeLoaded, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
