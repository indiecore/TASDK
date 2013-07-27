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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.AllowBehaviorAt");
			byte params[8] = { NULL };
			*(class GameCrowdDestination**)&params[0] = Destination;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool AllowThisDestination(class GameCrowdDestination* Destination)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.AllowThisDestination");
			byte params[8] = { NULL };
			*(class GameCrowdDestination**)&params[0] = Destination;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CanBeUsedBy(class GameCrowdAgent* Agent, Object::Vector CameraLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.CanBeUsedBy");
			byte params[20] = { NULL };
			*(class GameCrowdAgent**)&params[0] = Agent;
			*(Object::Vector*)&params[4] = CameraLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		class Actor* GetDestinationActor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.GetDestinationActor");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[0];
		}
		ScriptString* GetBehaviorString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.GetBehaviorString");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		bool ShouldEndIdle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.ShouldEndIdle");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FinishedTargetRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.FinishedTargetRotation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool HandleMovement()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.HandleMovement");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void InitBehavior(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.InitBehavior");
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)&params[0] = Agent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopBehavior()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.StopBehavior");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnAnimEnd(class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.OnAnimEnd");
			byte params[12] = { NULL };
			*(class AnimNodeSequence**)&params[0] = SeqNode;
			*(float*)&params[4] = PlayedTime;
			*(float*)&params[8] = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ChangingDestination(class GameCrowdDestination* NewDest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.ChangingDestination");
			byte params[4] = { NULL };
			*(class GameCrowdDestination**)&params[0] = NewDest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ActivatedBy(class Actor* NewActionTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.ActivatedBy");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = NewActionTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PropagateViralBehaviorTo(class GameCrowdAgent* OtherAgent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.PropagateViralBehaviorTo");
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)&params[0] = OtherAgent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
