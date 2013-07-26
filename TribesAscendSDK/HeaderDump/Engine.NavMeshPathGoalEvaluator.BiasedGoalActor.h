#pragma once
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " NavMeshPathGoalEvaluator.BiasedGoalActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty NavMeshPathGoalEvaluator.BiasedGoalActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class BiasedGoalActor
	{
	public:
		ADD_VAR(::IntProperty, ExtraCost, 0xFFFFFFFF)
		ADD_OBJECT(Actor, Goal)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
