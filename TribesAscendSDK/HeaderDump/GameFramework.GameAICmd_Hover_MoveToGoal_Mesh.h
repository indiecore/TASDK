#pragma once
#include "Engine.HUD.h"
#include "GameFramework.GameAICommand.h"
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
	class GameAICmd_Hover_MoveToGoal_Mesh : public GameAICommand
	{
	public:
		ADD_STRUCT(int, MaxMoveFails, 172)
		ADD_STRUCT(int, MoveFailCounter, 168)
		ADD_STRUCT(Vector, InitialFinalDestination, 156)
		ADD_STRUCT(Vector, LastMoveVectDest, 144)
		ADD_STRUCT(Vector, MoveVectDest, 132)
		ADD_STRUCT(float, GoalDistance, 128)
		ADD_STRUCT(float, SubGoalReachDist, 124)
		ADD_STRUCT(float, CurrentHoverHeight, 120)
		ADD_STRUCT(float, DesiredHoverHeight, 116)
		ADD_BOOL(bWasFiring, 112, 0x1)
		ADD_STRUCT(float, Radius, 108)
		ADD_OBJECT(Actor, Goal, 104)
		ADD_OBJECT(Actor, Find, 100)
		ADD_STRUCT(Vector, Transient_FinalDest, 88)
		bool HoverToGoal(class GameAIController* AI, class Actor* InGoal, float InGoalDistance, float InHoverHeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30693);
			byte params[20] = { NULL };
			*(class GameAIController**)params = AI;
			*(class Actor**)&params[4] = InGoal;
			*(float*)&params[8] = InGoalDistance;
			*(float*)&params[12] = InHoverHeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool HoverToPoint(class GameAIController* AI, Vector InPoint, float InGoalDistance, float InHoverHeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30700);
			byte params[28] = { NULL };
			*(class GameAIController**)params = AI;
			*(Vector*)&params[4] = InPoint;
			*(float*)&params[16] = InGoalDistance;
			*(float*)&params[20] = InHoverHeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void Pushed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30707);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Popped()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30708);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool HandlePathObstruction(class Actor* BlockedBy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30709);
			byte params[8] = { NULL };
			*(class Actor**)params = BlockedBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsEnemyBasedOnInterpActor(class Pawn* InEnemy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30741);
			byte params[8] = { NULL };
			*(class Pawn**)params = InEnemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void DrawDebug(class HUD* H, ScriptName Category)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30744);
			byte params[12] = { NULL };
			*(class HUD**)params = H;
			*(ScriptName*)&params[4] = Category;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
