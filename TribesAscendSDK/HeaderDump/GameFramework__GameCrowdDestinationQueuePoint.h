#pragma once
#include "GameFramework__GameCrowdDestination.h"
#include "GameFramework__GameCrowdInteractionPoint.h"
#include "GameFramework__GameCrowdAgent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameCrowdDestinationQueuePoint." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameCrowdDestinationQueuePoint." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameCrowdDestinationQueuePoint : public GameCrowdInteractionPoint
	{
	public:
		ADD_OBJECT(GameCrowdAgent, QueuedAgent)
		ADD_OBJECT(GameCrowdDestinationQueuePoint, NextQueuePosition)
		ADD_VAR(::BoolProperty, bPendingAdvance, 0x2)
		ADD_OBJECT(ScriptClass, QueueBehaviorClass)
		ADD_VAR(::FloatProperty, AverageReactionTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bClearingQueue, 0x1)
		ADD_OBJECT(GameCrowdDestination, QueueDestination)
		ADD_OBJECT(GameCrowdInteractionPoint, PreviousQueuePosition)
		// Here lies the not-yet-implemented method 'HasCustomer'
		// Here lies the not-yet-implemented method 'HasSpace'
		// Here lies the not-yet-implemented method 'QueueReachedBy'
		// Here lies the not-yet-implemented method 'ReachedDestination'
		// Here lies the not-yet-implemented method 'AdvanceCustomerTo'
		// Here lies the not-yet-implemented method 'ActuallyAdvance'
		// Here lies the not-yet-implemented method 'AddCustomer'
		// Here lies the not-yet-implemented method 'ClearQueue'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
