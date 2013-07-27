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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31257);
			byte params[4] = { NULL };
			*(class Actor**)params = NewActionTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitBehavior(class GameCrowdAgent* Agent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31261);
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)params = Agent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopBehavior()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31263);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PropagateViralBehaviorTo(class GameCrowdAgent* OtherAgent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31264);
			byte params[4] = { NULL };
			*(class GameCrowdAgent**)params = OtherAgent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AllowThisDestination(class GameCrowdDestination* Destination)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31266);
			byte params[8] = { NULL };
			*(class GameCrowdDestination**)params = Destination;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool AllowBehaviorAt(class GameCrowdDestination* Destination)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31269);
			byte params[8] = { NULL };
			*(class GameCrowdDestination**)params = Destination;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		ScriptString* GetBehaviorString()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31272);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31274);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
