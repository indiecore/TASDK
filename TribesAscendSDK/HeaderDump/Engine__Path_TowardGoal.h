#pragma once
#include "Engine__PathConstraint.h"
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
	};
}
#undef ADD_OBJECT
