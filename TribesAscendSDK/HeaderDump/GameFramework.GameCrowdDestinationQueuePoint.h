#pragma once
#include "GameFramework.GameCrowdInteractionPoint.h"
#include "GameFramework.GameCrowdAgent.h"
#include "GameFramework.GameCrowdDestination.h"
#include "Core.Object.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GameCrowdDestinationQueuePoint : public GameCrowdInteractionPoint
	{
	public:
		ADD_OBJECT(GameCrowdAgent, QueuedAgent, 492)
		ADD_OBJECT(GameCrowdDestinationQueuePoint, NextQueuePosition, 484)
		ADD_BOOL(bPendingAdvance, 500, 0x2)
		ADD_OBJECT(ScriptClass, QueueBehaviorClass, 508)
		ADD_STRUCT(float, AverageReactionTime, 504)
		ADD_BOOL(bClearingQueue, 500, 0x1)
		ADD_OBJECT(GameCrowdDestination, QueueDestination, 496)
		ADD_OBJECT(GameCrowdInteractionPoint, PreviousQueuePosition, 488)
		bool HasCustomer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestinationQueuePoint.HasCustomer");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool HasSpace()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestinationQueuePoint.HasSpace");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool QueueReachedBy(class GameCrowdAgent* Agent, Object::Vector TestPosition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestinationQueuePoint.QueueReachedBy");
			byte params[20] = { NULL };
			*(class GameCrowdAgent**)&params[0] = Agent;
			*(Object::Vector*)&params[4] = TestPosition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void ReachedDestination(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestinationQueuePoint.ReachedDestination");
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)&params[0] = Agent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdvanceCustomerTo(class GameCrowdInteractionPoint* FrontPosition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestinationQueuePoint.AdvanceCustomerTo");
			byte params[4] = { NULL };
			*(class GameCrowdInteractionPoint**)&params[0] = FrontPosition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ActuallyAdvance()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestinationQueuePoint.ActuallyAdvance");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddCustomer(class GameCrowdAgent* NewCustomer, class GameCrowdInteractionPoint* PreviousPosition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestinationQueuePoint.AddCustomer");
			byte params[8] = { NULL };
			*(class GameCrowdAgent**)&params[0] = NewCustomer;
			*(class GameCrowdInteractionPoint**)&params[4] = PreviousPosition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearQueue(class GameCrowdAgent* OldCustomer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdDestinationQueuePoint.ClearQueue");
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)&params[0] = OldCustomer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
