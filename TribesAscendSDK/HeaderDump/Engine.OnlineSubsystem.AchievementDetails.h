#pragma once
#include "Engine.Surface.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineSubsystem.AchievementDetails." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty OnlineSubsystem.AchievementDetails." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AchievementDetails
	{
	public:
		ADD_VAR(::IntProperty, Id, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, AchievementName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Description, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HowTo, 0xFFFFFFFF)
		ADD_OBJECT(Surface, Image)
		ADD_VAR(::IntProperty, GamerPoints, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsSecret, 0x1)
		ADD_VAR(::BoolProperty, bWasAchievedOnline, 0x2)
		ADD_VAR(::BoolProperty, bWasAchievedOffline, 0x4)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
