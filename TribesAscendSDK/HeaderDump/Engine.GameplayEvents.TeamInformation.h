#pragma once
#include "Core.Object.Color.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameplayEvents.TeamInformation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameplayEvents.TeamInformation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TeamInformation
	{
	public:
		ADD_VAR(::IntProperty, MaxSize, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Color>, TeamColor, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TeamName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TeamIndex, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
