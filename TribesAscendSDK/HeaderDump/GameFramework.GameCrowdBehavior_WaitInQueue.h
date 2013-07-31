#pragma once
#include "GameFramework.GameCrowdAgentBehavior.h"
#include "GameFramework.GameCrowdDestinationQueuePoint.h"
#include "GameFramework.GameCrowdDestination.h"
#include "Engine.Actor.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GameCrowdBehavior_WaitInQueue : public GameCrowdAgentBehavior
	{
	public:
		ADD_OBJECT(GameCrowdDestinationQueuePoint, QueuePosition, 88)
		ADD_BOOL(bStoppingBehavior, 84, 0x1)
		bool HandleMovement()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31286);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ChangingDestination(class GameCrowdDestination* NewDest)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31288);
			byte params[4] = { NULL };
			*(class GameCrowdDestination**)params = NewDest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Actor* GetDestinationActor()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31290);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)params;
		}
		ScriptString* GetBehaviorString()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31292);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		bool ShouldEndIdle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31294);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void StopBehavior()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31296);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_OBJECT
