#pragma once
#include "Engine__NetDriver.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DemoRecDriver." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DemoRecDriver : public NetDriver
	{
	public:
		ADD_VAR(::StrProperty, DemoSpectatorClass, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxRewindPoints, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RewindPointInterval, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumRecentRewindPoints, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
