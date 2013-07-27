#pragma once
#include "Engine.Settings.h"
#include "Engine.OnlineSubsystem.h"
#include "Core.Object.h"
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
	class OnlineGameSettings : public Settings
	{
	public:
		ADD_BOOL(bUsesArbitration, 132, 0x100)
		ADD_STRUCT(int, NumOpenPrivateConnections, 120)
		ADD_STRUCT(int, NumOpenPublicConnections, 116)
		ADD_STRUCT(OnlineSubsystem::EOnlineGameState, GameState, 164)
		ADD_STRUCT(OnlineSubsystem::UniqueNetId, OwningPlayerId, 148)
		ADD_BOOL(bIsLanMatch, 132, 0x2)
		ADD_BOOL(bUsesStats, 132, 0x4)
		ADD_STRUCT(int, NumPublicConnections, 108)
		ADD_STRUCT(int, BuildUniqueId, 168)
		ADD_STRUCT(float, MatchQuality, 160)
		ADD_STRUCT(int, PingInMs, 156)
		ADD_STRUCT(ScriptString*, OwningPlayerName, 136)
		ADD_BOOL(bHasSkillUpdateInProgress, 132, 0x1000)
		ADD_BOOL(bIsDedicated, 132, 0x800)
		ADD_BOOL(bWasFromInvite, 132, 0x400)
		ADD_BOOL(bAntiCheatProtected, 132, 0x200)
		ADD_BOOL(bAllowJoinViaPresenceFriendsOnly, 132, 0x80)
		ADD_BOOL(bAllowJoinViaPresence, 132, 0x40)
		ADD_BOOL(bUsesPresence, 132, 0x20)
		ADD_BOOL(bAllowInvites, 132, 0x10)
		ADD_BOOL(bAllowJoinInProgress, 132, 0x8)
		ADD_BOOL(bShouldAdvertise, 132, 0x1)
		ADD_STRUCT(Object::QWord, ServerNonce, 124)
		ADD_STRUCT(int, NumPrivateConnections, 112)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
