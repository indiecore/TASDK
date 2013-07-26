#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GFxTrScene_MatchSummary.ScoreSlot." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ScoreSlot
	{
	public:
		ADD_VAR(::StrProperty, PlayerName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PlayerID, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Credits, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Assists, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Rank, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Kills, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
