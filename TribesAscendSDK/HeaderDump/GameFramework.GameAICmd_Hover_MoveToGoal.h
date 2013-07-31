#pragma once
#include "GameFramework.GameAICommand.h"
#include "Engine.ReachSpec.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "GameFramework.GameAIController.h"
#include "Engine.Pawn.h"
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
	class GameAICmd_Hover_MoveToGoal : public GameAICommand
	{
	public:
		ADD_OBJECT(ReachSpec, CurrentSpec, 136)
		ADD_STRUCT(Vector, MoveVectDest, 124)
		ADD_STRUCT(float, GoalDistance, 120)
		ADD_STRUCT(float, SubGoalReachDist, 116)
		ADD_STRUCT(float, CurrentHoverHeight, 112)
		ADD_STRUCT(float, DesiredHoverHeight, 108)
		ADD_BOOL(bWasFiring, 104, 0x1)
		ADD_STRUCT(float, Radius, 100)
		ADD_OBJECT(Actor, Goal, 96)
		ADD_OBJECT(Actor, Find, 92)
		ADD_OBJECT(Actor, Path, 88)
		bool MoveToGoal(class GameAIController* AI, class Actor* InGoal, float InGoalDistance, float InHoverHeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30644);
			byte params[20] = { NULL };
			*(class GameAIController**)params = AI;
			*(class Actor**)&params[4] = InGoal;
			*(float*)&params[8] = InGoalDistance;
			*(float*)&params[12] = InHoverHeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void Pushed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30651);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool HandlePathObstruction(class Actor* BlockedBy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30652);
			byte params[8] = { NULL };
			*(class Actor**)params = BlockedBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsEnemyBasedOnInterpActor(class Pawn* InEnemy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30674);
			byte params[8] = { NULL };
			*(class Pawn**)params = InEnemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
