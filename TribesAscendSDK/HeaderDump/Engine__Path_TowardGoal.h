#pragma once
#include "Engine__PathConstraint.h"
#include "Engine__Actor.h"
#include "Engine__Pawn.h"
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
		// Here lies the not-yet-implemented method 'TowardGoal'
		// Here lies the not-yet-implemented method 'Recycle'
	};
}
#undef ADD_OBJECT
