#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrQueueManager.ServerInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ServerInfo
	{
	public:
		ADD_VAR(::IntProperty, PlayerCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PlayerMax, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MapName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ServerName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bFavorite, 0x2)
		ADD_VAR(::IntProperty, queueId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Ping, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPrivate, 0x1)
		ADD_VAR(::StrProperty, Ruleset, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MinLevel, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxLevel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ServerDesc, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GameType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
