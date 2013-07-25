#pragma once
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "GameFramework.GameCrowdAgent.h"
#include "Engine.AnimNodeSequence.h"
#include "GameFramework.GameCrowdDestination.h"
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
		bool AllowBehaviorAt(class GameCrowdDestination* Destination)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.AllowBehaviorAt");
			byte* params = (byte*)malloc(8);
			*(class GameCrowdDestination**)params = Destination;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool AllowThisDestination(class GameCrowdDestination* Destination)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.AllowThisDestination");
			byte* params = (byte*)malloc(8);
			*(class GameCrowdDestination**)params = Destination;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CanBeUsedBy(class GameCrowdAgent* Agent, Vector CameraLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.CanBeUsedBy");
			byte* params = (byte*)malloc(20);
			*(class GameCrowdAgent**)params = Agent;
			*(Vector*)(params + 4) = CameraLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		class Actor* GetDestinationActor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.GetDestinationActor");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetBehaviorString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.GetBehaviorString");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		bool ShouldEndIdle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.ShouldEndIdle");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FinishedTargetRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.FinishedTargetRotation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool HandleMovement()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.HandleMovement");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void InitBehavior(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.InitBehavior");
			byte* params = (byte*)malloc(4);
			*(class GameCrowdAgent**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopBehavior()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.StopBehavior");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnAnimEnd(class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.OnAnimEnd");
			byte* params = (byte*)malloc(12);
			*(class AnimNodeSequence**)params = SeqNode;
			*(float*)(params + 4) = PlayedTime;
			*(float*)(params + 8) = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ChangingDestination(class GameCrowdDestination* NewDest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.ChangingDestination");
			byte* params = (byte*)malloc(4);
			*(class GameCrowdDestination**)params = NewDest;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ActivatedBy(class Actor* NewActionTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.ActivatedBy");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = NewActionTarget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PropagateViralBehaviorTo(class GameCrowdAgent* OtherAgent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdAgentBehavior.PropagateViralBehaviorTo");
			byte* params = (byte*)malloc(4);
			*(class GameCrowdAgent**)params = OtherAgent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
