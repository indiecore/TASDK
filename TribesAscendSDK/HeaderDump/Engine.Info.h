#pragma once
#include "Engine.Actor.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class Info : public Actor
	{
	public:
		struct KeyValuePair
		{
		public:
			ADD_STRUCT(ScriptString*, Value, 12)
			ADD_STRUCT(ScriptString*, Key, 0)
		};
		struct PlayerResponseLine
		{
		public:
			ADD_STRUCT(ScriptArray<Info::KeyValuePair>, PlayerInfo, 32)
			ADD_STRUCT(int, StatsID, 28)
			ADD_STRUCT(int, Score, 24)
			ADD_STRUCT(int, Ping, 20)
			ADD_STRUCT(ScriptString*, PlayerName, 8)
			ADD_STRUCT(int, PlayerID, 4)
			ADD_STRUCT(int, PlayerNum, 0)
		};
		struct ServerResponseLine
		{
		public:
			ADD_STRUCT(ScriptArray<Info::KeyValuePair>, ServerInfo, 72)
			ADD_STRUCT(ScriptArray<Info::PlayerResponseLine>, PlayerInfo, 84)
			ADD_STRUCT(int, Ping, 68)
			ADD_STRUCT(int, MaxPlayers, 64)
			ADD_STRUCT(int, CurrentPlayers, 60)
			ADD_STRUCT(ScriptString*, GameType, 48)
			ADD_STRUCT(ScriptString*, MapName, 36)
			ADD_STRUCT(ScriptString*, ServerName, 24)
			ADD_STRUCT(int, QueryPort, 20)
			ADD_STRUCT(int, Port, 16)
			ADD_STRUCT(ScriptString*, IP, 4)
			ADD_STRUCT(int, ServerID, 0)
		};
	};
}
#undef ADD_STRUCT
