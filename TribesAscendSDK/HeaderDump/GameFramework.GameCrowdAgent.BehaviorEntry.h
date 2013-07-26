#pragma once
#include "Engine.Actor.h"
#include "GameFramework.GameCrowdAgentBehavior.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameCrowdAgent.BehaviorEntry." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameCrowdAgent.BehaviorEntry." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class BehaviorEntry
	{
	public:
		ADD_VAR(::BoolProperty, bCanBeUsed, 0x4)
		ADD_VAR(::BoolProperty, bHasBeenUsed, 0x2)
		ADD_VAR(::BoolProperty, bNeverRepeat, 0x1)
		ADD_VAR(::FloatProperty, BehaviorFrequency, 0xFFFFFFFF)
		ADD_OBJECT(Actor, LookAtActor)
		ADD_OBJECT(GameCrowdAgentBehavior, BehaviorArchetype)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
