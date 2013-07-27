#pragma once
#include "Engine.GameplayEventsHandler.h"
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
	class GameStateObject : public GameplayEventsHandler
	{
	public:
		enum GameSessionType : byte
		{
			GT_SessionInvalid = 0,
			GT_SinglePlayer = 1,
			GT_Coop = 2,
			GT_Multiplayer = 3,
			GT_MAX = 4,
		};
		struct TeamState
		{
		public:
			ADD_STRUCT(ScriptArray<int>, PlayerIndices, 4)
			ADD_STRUCT(int, TeamIndex, 0)
		};
		struct PlayerState
		{
		public:
			ADD_STRUCT(float, TimeAliveSinceLastDeath, 12)
			ADD_STRUCT(float, TimeSpawned, 8)
			ADD_STRUCT(int, CurrentTeamIndex, 4)
			ADD_STRUCT(int, PlayerIndex, 0)
		};
		ADD_STRUCT(int, MaxRoundNumber, 124)
		ADD_STRUCT(int, RoundNumber, 120)
		ADD_BOOL(bIsRoundStarted, 116, 0x2)
		ADD_BOOL(bIsMatchStarted, 116, 0x1)
		ADD_STRUCT(GameStateObject::GameSessionType, SessionType, 112)
		ADD_STRUCT(Object::Array_Mirror, PlayerStates, 100)
		ADD_STRUCT(Object::Array_Mirror, TeamStates, 88)
		void PreProcessStream()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31955);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31956);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
