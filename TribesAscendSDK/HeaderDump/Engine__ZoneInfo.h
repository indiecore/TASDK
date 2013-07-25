#pragma once
#include "Engine__Info.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ZoneInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ZoneInfo : public Info
	{
	public:
		ADD_VAR(::FloatProperty, KillZ, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSoftKillZ, 0x1)
		ADD_VAR(::FloatProperty, SoftKill, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
