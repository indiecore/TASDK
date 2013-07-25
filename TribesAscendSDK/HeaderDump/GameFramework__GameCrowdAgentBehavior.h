#pragma once
#include "GameFramework__GameCrowdDestination.h"
#include "Core__Object.h"
#include "Engine__Actor.h"
#include "GameFramework__GameCrowdAgent.h"
#include "Engine__AnimNodeSequence.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameCrowdAgentBehavior." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameCrowdAgentBehavior." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameCrowdAgentBehavior : public Object
	{
	public:
		ADD_OBJECT(Actor, ActionTarget)
		ADD_VAR(::FloatProperty, MaxPlayerDistance, 0xFFFFFFFF)
		ADD_OBJECT(GameCrowdAgent, MyAgent)
		ADD_VAR(::FloatProperty, TimeToStopPropagatingViralBehavior, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DurationOfViralBehaviorPropagation, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsPanicked, 0x10)
		ADD_VAR(::BoolProperty, bPassOnIsViralBehaviorFlag, 0x8)
		ADD_VAR(::BoolProperty, bIsViralBehavior, 0x4)
		ADD_VAR(::BoolProperty, bFaceActionTargetFirst, 0x2)
		ADD_VAR(::BoolProperty, bIdleBehavior, 0x1)
		// Here lies the not-yet-implemented method 'AllowBehaviorAt'
		// Here lies the not-yet-implemented method 'AllowThisDestination'
		// Here lies the not-yet-implemented method 'CanBeUsedBy'
		// Here lies the not-yet-implemented method 'GetDestinationActor'
		// Here lies the not-yet-implemented method 'GetBehaviorString'
		// Here lies the not-yet-implemented method 'ShouldEndIdle'
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'FinishedTargetRotation'
		// Here lies the not-yet-implemented method 'HandleMovement'
		// Here lies the not-yet-implemented method 'InitBehavior'
		// Here lies the not-yet-implemented method 'StopBehavior'
		// Here lies the not-yet-implemented method 'OnAnimEnd'
		// Here lies the not-yet-implemented method 'ChangingDestination'
		// Here lies the not-yet-implemented method 'ActivatedBy'
		// Here lies the not-yet-implemented method 'PropagateViralBehaviorTo'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
