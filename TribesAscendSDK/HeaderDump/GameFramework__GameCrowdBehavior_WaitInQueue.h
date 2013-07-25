#pragma once
#include "Engine__Actor.h"
#include "GameFramework__GameCrowdAgentBehavior.h"
#include "GameFramework__GameCrowdDestinationQueuePoint.h"
#include "GameFramework__GameCrowdDestination.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameCrowdBehavior_WaitInQueue." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameCrowdBehavior_WaitInQueue." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameCrowdBehavior_WaitInQueue : public GameCrowdAgentBehavior
	{
	public:
		ADD_OBJECT(GameCrowdDestinationQueuePoint, QueuePosition)
		ADD_VAR(::BoolProperty, bStoppingBehavior, 0x1)
		// Here lies the not-yet-implemented method 'HandleMovement'
		// Here lies the not-yet-implemented method 'ChangingDestination'
		// Here lies the not-yet-implemented method 'GetDestinationActor'
		// Here lies the not-yet-implemented method 'GetBehaviorString'
		// Here lies the not-yet-implemented method 'ShouldEndIdle'
		// Here lies the not-yet-implemented method 'StopBehavior'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
