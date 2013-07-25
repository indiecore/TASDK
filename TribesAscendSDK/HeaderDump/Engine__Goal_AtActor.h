#pragma once
#include "Engine__PathGoalEvaluator.h"
#include "Engine__Actor.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Goal_AtActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Goal_AtActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Goal_AtActor : public PathGoalEvaluator
	{
	public:
		ADD_VAR(::BoolProperty, bKeepPartial, 0x1)
		ADD_VAR(::FloatProperty, GoalDist, 0xFFFFFFFF)
		ADD_OBJECT(Actor, GoalActor)
		bool AtActor(class Pawn* P, class Actor* Goal, float Dist, bool bReturnPartial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Goal_AtActor.AtActor");
			byte* params = (byte*)malloc(20);
			*(class Pawn**)params = P;
			*(class Actor**)(params + 4) = Goal;
			*(float*)(params + 8) = Dist;
			*(bool*)(params + 12) = bReturnPartial;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Goal_AtActor.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
