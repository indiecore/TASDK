#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Info.PlayerResponseLine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PlayerResponseLine
	{
	public:
		ADD_VAR(::IntProperty, StatsID, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Score, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Ping, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PlayerName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PlayerID, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PlayerNum, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
