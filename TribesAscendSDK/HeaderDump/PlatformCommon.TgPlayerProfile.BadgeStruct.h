#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TgPlayerProfile.BadgeStruct." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class BadgeStruct
	{
	public:
		ADD_VAR(::StrProperty, Description, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Title, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Category, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxValue, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Progress, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Tier, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Icon, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ActivityId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, BadgeId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
