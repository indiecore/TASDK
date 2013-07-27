#pragma once
#include "Engine.OnlinePlayerStorage.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TgPlayerProfile : public OnlinePlayerStorage
	{
	public:
		class BadgeStruct
		{
		public:
			ADD_STRUCT(ScriptString*, Description, 40)
			ADD_STRUCT(ScriptString*, Title, 28)
			ADD_STRUCT(int, Category, 24)
			ADD_STRUCT(int, MaxValue, 20)
			ADD_STRUCT(int, Progress, 16)
			ADD_STRUCT(int, Tier, 12)
			ADD_STRUCT(int, Icon, 8)
			ADD_STRUCT(int, ActivityId, 4)
			ADD_STRUCT(int, BadgeId, 0)
		};
		class PropertyPair
		{
		public:
			ADD_STRUCT(int, Value, 4)
			ADD_STRUCT(int, PropertyId, 0)
		};
		class AccoladeStruct
		{
		public:
			ADD_STRUCT(int, Value, 12)
			ADD_STRUCT(int, Type, 8)
			ADD_STRUCT(int, ActivityId, 4)
			ADD_STRUCT(int, AccoladeId, 0)
		};
		ADD_STRUCT(ScriptArray<TgPlayerProfile::BadgeStruct>, Badges, 192)
		ADD_STRUCT(ScriptArray<TgPlayerProfile::BadgeStruct>, TopBadges, 204)
		ADD_STRUCT(ScriptArray<TgPlayerProfile::PropertyPair>, ClassTimePlayed, 216)
		ADD_STRUCT(ScriptArray<TgPlayerProfile::AccoladeStruct>, Accolades, 228)
		ADD_STRUCT(ScriptString*, PlayerName, 180)
		ADD_STRUCT(int, PlayerID, 176)
		ADD_BOOL(bBoost, 172, 0x2)
		ADD_BOOL(bVIP, 172, 0x1)
		ADD_STRUCT(int, ObjsDestroyed, 168)
		ADD_STRUCT(int, GensDestroyed, 164)
		ADD_STRUCT(int, FlagCaps, 160)
		ADD_STRUCT(int, FlagGrabs, 156)
		ADD_STRUCT(int, FastestSki, 152)
		ADD_STRUCT(int, TotalAccolades, 148)
		ADD_STRUCT(int, TimePlayed, 144)
		ADD_STRUCT(int, InfoMask, 140)
		ADD_STRUCT(int, BoostHoursRemaining, 136)
		ADD_STRUCT(int, AverageScore, 132)
		ADD_STRUCT(int, AssistPoints, 128)
		ADD_STRUCT(int, XPPoints, 124)
		ADD_STRUCT(int, HZPoints, 120)
		ADD_STRUCT(int, XpLevel, 116)
		ADD_STRUCT(int, Assists, 112)
		ADD_STRUCT(int, Deaths, 108)
		ADD_STRUCT(int, Kills, 104)
		ADD_STRUCT(int, Rank, 100)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
