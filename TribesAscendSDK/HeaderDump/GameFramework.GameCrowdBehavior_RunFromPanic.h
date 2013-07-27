#pragma once
#include "GameFramework.GameCrowdAgentBehavior.h"
#include "Engine.Actor.h"
#include "GameFramework.GameCrowdAgent.h"
#include "GameFramework.GameCrowdDestination.h"
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
	class GameCrowdBehavior_RunFromPanic : public GameCrowdAgentBehavior
	{
	public:
		ADD_STRUCT(float, TimeToStopPanic, 92)
		ADD_STRUCT(float, DurationOfPanic, 88)
		ADD_OBJECT(Actor, PanicFocus, 84)
		void ActivatedBy(class Actor* NewActionTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_RunFromPanic.ActivatedBy");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = NewActionTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitBehavior(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_RunFromPanic.InitBehavior");
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)&params[0] = Agent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopBehavior()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_RunFromPanic.StopBehavior");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PropagateViralBehaviorTo(class GameCrowdAgent* OtherAgent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_RunFromPanic.PropagateViralBehaviorTo");
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)&params[0] = OtherAgent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AllowThisDestination(class GameCrowdDestination* Destination)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_RunFromPanic.AllowThisDestination");
			byte params[8] = { NULL };
			*(class GameCrowdDestination**)&params[0] = Destination;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool AllowBehaviorAt(class GameCrowdDestination* Destination)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_RunFromPanic.AllowBehaviorAt");
			byte params[8] = { NULL };
			*(class GameCrowdDestination**)&params[0] = Destination;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		ScriptString* GetBehaviorString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_RunFromPanic.GetBehaviorString");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdBehavior_RunFromPanic.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
