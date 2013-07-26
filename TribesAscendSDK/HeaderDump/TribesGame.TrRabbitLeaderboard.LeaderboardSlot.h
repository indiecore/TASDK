#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrRabbitLeaderboard.LeaderboardSlot." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LeaderboardSlot
	{
	public:
		ADD_VAR(::IntProperty, Score, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, PRIName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
