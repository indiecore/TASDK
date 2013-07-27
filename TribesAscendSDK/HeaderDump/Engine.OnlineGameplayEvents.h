#pragma once
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
	class OnlineGameplayEvents : public Object
	{
	public:
		class PlayerInformation
		{
		public:
			ADD_STRUCT(int, LastPlayerEventIdx, 36)
			ADD_BOOL(bIsBot, 32, 0x1)
			ADD_STRUCT(OnlineSubsystem::UniqueNetId, UniqueId, 24)
			ADD_STRUCT(ScriptString*, PlayerName, 12)
			ADD_STRUCT(ScriptString*, ControllerName, 0)
		};
		class GameplayEvent
		{
		public:
			ADD_STRUCT(int, EventNameAndDesc, 4)
			ADD_STRUCT(int, PlayerEventAndTarget, 0)
		};
		class PlayerEvent
		{
		public:
			ADD_STRUCT(int, PlayerPitchAndRoll, 20)
			ADD_STRUCT(int, PlayerIndexAndYaw, 16)
			ADD_STRUCT(Object::Vector, EventLocation, 4)
			ADD_STRUCT(float, EventTime, 0)
		};
		ADD_STRUCT(ScriptArray<OnlineGameplayEvents::PlayerInformation>, PlayerList, 60)
		ADD_STRUCT(ScriptArray<ScriptString*>, EventDescList, 72)
		ADD_STRUCT(ScriptArray<ScriptName>, EventNames, 84)
		ADD_STRUCT(ScriptArray<OnlineGameplayEvents::GameplayEvent>, GameplayEvents, 96)
		ADD_STRUCT(ScriptArray<OnlineGameplayEvents::PlayerEvent>, PlayerEvents, 108)
		ADD_STRUCT(Object::Guid, GameplaySessionID, 136)
		ADD_BOOL(bGameplaySessionInProgress, 132, 0x1)
		ADD_STRUCT(ScriptString*, GameplaySessionStartTime, 120)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
