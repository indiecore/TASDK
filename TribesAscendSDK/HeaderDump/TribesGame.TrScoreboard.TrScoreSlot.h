#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrScoreboard.TrScoreSlot." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrScoreSlot
	{
	public:
		ADD_VAR(::IntProperty, RankIcon, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Rank, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Ping, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Score, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Assists, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Kills, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ClassAbb, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PlayerName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
