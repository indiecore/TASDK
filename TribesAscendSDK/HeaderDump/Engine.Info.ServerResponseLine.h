#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Info.ServerResponseLine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ServerResponseLine
	{
	public:
		ADD_VAR(::IntProperty, Ping, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxPlayers, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CurrentPlayers, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, GameType, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MapName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ServerName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, QueryPort, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Port, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, IP, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ServerID, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
