#pragma once
#include "Engine.PathConstraint.h"
#include "Engine.Actor.h"
#include "Engine.Pawn.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class Path_TowardGoal : public PathConstraint
	{
	public:
		ADD_OBJECT(Actor, GoalActor, 68)
		bool TowardGoal(class Pawn* P, class Actor* Goal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23985);
			byte params[12] = { NULL };
			*(class Pawn**)params = P;
			*(class Actor**)&params[4] = Goal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void Recycle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23990);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_OBJECT
