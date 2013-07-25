#pragma once
#include "Engine.Info.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ZoneInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ZoneInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ZoneInfo : public Info
	{
	public:
		ADD_VAR(::FloatProperty, KillZ, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSoftKillZ, 0x1)
		ADD_OBJECT(ScriptClass, KillZDamageType)
		ADD_VAR(::FloatProperty, SoftKill, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
