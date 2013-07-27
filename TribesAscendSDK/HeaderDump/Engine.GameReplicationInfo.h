#pragma once
#include "Engine.ReplicationInfo.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.TeamInfo.h"
#include "Engine.Actor.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GameReplicationInfo : public ReplicationInfo
	{
	public:
		ADD_STRUCT(ScriptArray<class PlayerReplicationInfo*>, PRIArray, 532)
		ADD_OBJECT(ScriptClass, GameClass, 476)
		ADD_BOOL(bMatchHasBegun, 480, 0x2)
		ADD_STRUCT(ScriptArray<class TeamInfo*>, Teams, 504)
		ADD_STRUCT(ScriptArray<class PlayerReplicationInfo*>, InactivePRIArray, 544)
		ADD_OBJECT(Actor, Winner, 528)
		ADD_STRUCT(ScriptString*, ServerName, 516)
		ADD_STRUCT(int, TimeLimit, 500)
		ADD_STRUCT(int, GoalScore, 496)
		ADD_STRUCT(int, RemainingMinute, 492)
		ADD_STRUCT(int, ElapsedTime, 488)
		ADD_STRUCT(int, RemainingTime, 484)
		ADD_BOOL(r_bFriendlyFire, 480, 0x8)
		ADD_BOOL(bMatchIsOver, 480, 0x4)
		ADD_BOOL(bStopCountDown, 480, 0x1)
		bool ShouldShowGore()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7289);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17769);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17772);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReceivedGameClass()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17774);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17776);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Timer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17777);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool OnSameTeam(class Actor* A, class Actor* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17778);
			byte params[12] = { NULL };
			*(class Actor**)params = A;
			*(class Actor**)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void AddPRI(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17782);
			byte params[4] = { NULL };
			*(class PlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemovePRI(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17785);
			byte params[4] = { NULL };
			*(class PlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTeam(int Index, class TeamInfo* TI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17788);
			byte params[8] = { NULL };
			*(int*)params = Index;
			*(class TeamInfo**)&params[4] = TI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartMatch()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17791);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndGame()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17792);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsMultiplayerGame()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17793);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsCoopMultiplayerGame()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17795);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
