#pragma once
#include "UTGame.UTMutator.h"
#include "Engine.Controller.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTMutator_SlowTimeKills : public UTMutator
	{
	public:
		ADD_STRUCT(float, SlowSpeed, 504)
		ADD_STRUCT(float, RampUpTime, 500)
		ADD_STRUCT(float, SlowTime, 496)
		bool MutatorIsAllowed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48619);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ScoreKill(class Controller* Killer, class Controller* Killed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48621);
			byte params[8] = { NULL };
			*(class Controller**)params = Killer;
			*(class Controller**)&params[4] = Killed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Timer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48624);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
