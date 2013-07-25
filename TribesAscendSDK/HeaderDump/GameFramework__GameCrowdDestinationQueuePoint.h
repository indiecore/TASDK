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
		bool HasCustomer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestinationQueuePoint.HasCustomer");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool HasSpace()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestinationQueuePoint.HasSpace");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool QueueReachedBy(class GameCrowdAgent* Agent, Vector TestPosition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestinationQueuePoint.QueueReachedBy");
			byte* params = (byte*)malloc(20);
			*(class GameCrowdAgent**)params = Agent;
			*(Vector*)(params + 4) = TestPosition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void ReachedDestination(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestinationQueuePoint.ReachedDestination");
			byte* params = (byte*)malloc(4);
			*(class GameCrowdAgent**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AdvanceCustomerTo(class GameCrowdInteractionPoint* FrontPosition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestinationQueuePoint.AdvanceCustomerTo");
			byte* params = (byte*)malloc(4);
			*(class GameCrowdInteractionPoint**)params = FrontPosition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ActuallyAdvance()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestinationQueuePoint.ActuallyAdvance");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddCustomer(class GameCrowdAgent* NewCustomer, class GameCrowdInteractionPoint* PreviousPosition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestinationQueuePoint.AddCustomer");
			byte* params = (byte*)malloc(8);
			*(class GameCrowdAgent**)params = NewCustomer;
			*(class GameCrowdInteractionPoint**)(params + 4) = PreviousPosition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearQueue(class GameCrowdAgent* OldCustomer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestinationQueuePoint.ClearQueue");
			byte* params = (byte*)malloc(4);
			*(class GameCrowdAgent**)params = OldCustomer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
