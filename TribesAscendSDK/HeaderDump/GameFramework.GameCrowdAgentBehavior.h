#pragma once
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "GameFramework.GameCrowdAgent.h"
#include "Engine.AnimNodeSequence.h"
#include "GameFramework.GameCrowdDestination.h"
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
	class GameCrowdAgentBehavior : public Object
	{
	public:
		ADD_OBJECT(Actor, ActionTarget, 64)
		ADD_STRUCT(float, MaxPlayerDistance, 68)
		ADD_OBJECT(GameCrowdAgent, MyAgent, 80)
		ADD_STRUCT(float, TimeToStopPropagatingViralBehavior, 76)
		ADD_STRUCT(float, DurationOfViralBehaviorPropagation, 72)
		ADD_BOOL(bIsPanicked, 60, 0x10)
		ADD_BOOL(bPassOnIsViralBehaviorFlag, 60, 0x8)
		ADD_BOOL(bIsViralBehavior, 60, 0x4)
		ADD_BOOL(bFaceActionTargetFirst, 60, 0x2)
		ADD_BOOL(bIdleBehavior, 60, 0x1)
		bool AllowBehaviorAt(class GameCrowdDestination* Destination)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30493);
			byte params[8] = { NULL };
			*(class GameCrowdDestination**)params = Destination;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool AllowThisDestination(class GameCrowdDestination* Destination)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30523);
			byte params[8] = { NULL };
			*(class GameCrowdDestination**)params = Destination;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CanBeUsedBy(class GameCrowdAgent* Agent, Vector CameraLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(30959);
			byte params[20] = { NULL };
			*(class GameCrowdAgent**)params = Agent;
			*(Vector*)&params[4] = CameraLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		class Actor* GetDestinationActor()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31046);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)params;
		}
		ScriptString* GetBehaviorString()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31095);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		bool ShouldEndIdle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31106);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31108);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FinishedTargetRotation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31112);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool HandleMovement()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31113);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void InitBehavior(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31115);
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopBehavior()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31117);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnAnimEnd(class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31118);
			byte params[12] = { NULL };
			*(class AnimNodeSequence**)params = SeqNode;
			*(float*)&params[4] = PlayedTime;
			*(float*)&params[8] = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ChangingDestination(class GameCrowdDestination* NewDest)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31122);
			byte params[4] = { NULL };
			*(class GameCrowdDestination**)params = NewDest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ActivatedBy(class Actor* NewActionTarget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31124);
			byte params[4] = { NULL };
			*(class Actor**)params = NewActionTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PropagateViralBehaviorTo(class GameCrowdAgent* OtherAgent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31126);
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)params = OtherAgent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
