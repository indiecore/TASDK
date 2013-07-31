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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30511);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool HasSpace()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30516);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool QueueReachedBy(class GameCrowdAgent* Agent, Vector TestPosition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31302);
			byte params[20] = { NULL };
			*(class GameCrowdAgent**)params = Agent;
			*(Vector*)&params[4] = TestPosition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void ReachedDestination(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31306);
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdvanceCustomerTo(class GameCrowdInteractionPoint* FrontPosition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31309);
			byte params[4] = { NULL };
			*(class GameCrowdInteractionPoint**)params = FrontPosition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ActuallyAdvance()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31311);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddCustomer(class GameCrowdAgent* NewCustomer, class GameCrowdInteractionPoint* PreviousPosition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31315);
			byte params[8] = { NULL };
			*(class GameCrowdAgent**)params = NewCustomer;
			*(class GameCrowdInteractionPoint**)&params[4] = PreviousPosition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearQueue(class GameCrowdAgent* OldCustomer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31318);
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)params = OldCustomer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
