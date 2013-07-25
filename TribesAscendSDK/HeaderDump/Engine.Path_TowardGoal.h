#pragma once
#include "Engine.PathConstraint.h"
#include "Engine.Actor.h"
#include "Engine.Pawn.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Path_TowardGoal." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Path_TowardGoal : public PathConstraint
	{
	public:
		ADD_OBJECT(Actor, GoalActor)
		bool TowardGoal(class Pawn* P, class Actor* Goal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Path_TowardGoal.TowardGoal");
			byte* params = (byte*)malloc(12);
			*(class Pawn**)params = P;
			*(class Actor**)(params + 4) = Goal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Path_TowardGoal.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_OBJECT
