#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineGameSearch.OverrideSkill." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OverrideSkill
	{
	public:
		ADD_VAR(::IntProperty, LeaderboardId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
