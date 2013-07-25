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
		// Here lies the not-yet-implemented method 'AtActor'
		// Here lies the not-yet-implemented method 'Recycle'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
