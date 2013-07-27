#pragma once
#include "Engine.PathGoalEvaluator.h"
#include "Engine.Actor.h"
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
	class Goal_AtActor : public PathGoalEvaluator
	{
	public:
		ADD_BOOL(bKeepPartial, 84, 0x1)
		ADD_STRUCT(float, GoalDist, 80)
		ADD_OBJECT(Actor, GoalActor, 76)
		bool AtActor(class Pawn* P, class Actor* Goal, float Dist, bool bReturnPartial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Goal_AtActor.AtActor");
			byte params[20] = { NULL };
			*(class Pawn**)&params[0] = P;
			*(class Actor**)&params[4] = Goal;
			*(float*)&params[8] = Dist;
			*(bool*)&params[12] = bReturnPartial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Goal_AtActor.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
