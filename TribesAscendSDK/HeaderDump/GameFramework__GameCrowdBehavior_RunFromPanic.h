#pragma once
#include "Engine__Actor.h"
#include "GameFramework__GameCrowdAgentBehavior.h"
#include "GameFramework__GameCrowdAgent.h"
#include "GameFramework__GameCrowdDestination.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameCrowdBehavior_RunFromPanic." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameCrowdBehavior_RunFromPanic." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameCrowdBehavior_RunFromPanic : public GameCrowdAgentBehavior
	{
	public:
		ADD_VAR(::FloatProperty, TimeToStopPanic, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DurationOfPanic, 0xFFFFFFFF)
		ADD_OBJECT(Actor, PanicFocus)
		void ActivatedBy(class Actor* NewActionTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_RunFromPanic.ActivatedBy");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = NewActionTarget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InitBehavior(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_RunFromPanic.InitBehavior");
			byte* params = (byte*)malloc(4);
			*(class GameCrowdAgent**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopBehavior()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_RunFromPanic.StopBehavior");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PropagateViralBehaviorTo(class GameCrowdAgent* OtherAgent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_RunFromPanic.PropagateViralBehaviorTo");
			byte* params = (byte*)malloc(4);
			*(class GameCrowdAgent**)params = OtherAgent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AllowThisDestination(class GameCrowdDestination* Destination)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_RunFromPanic.AllowThisDestination");
			byte* params = (byte*)malloc(8);
			*(class GameCrowdDestination**)params = Destination;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool AllowBehaviorAt(class GameCrowdDestination* Destination)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_RunFromPanic.AllowBehaviorAt");
			byte* params = (byte*)malloc(8);
			*(class GameCrowdDestination**)params = Destination;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetBehaviorString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_RunFromPanic.GetBehaviorString");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_RunFromPanic.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
