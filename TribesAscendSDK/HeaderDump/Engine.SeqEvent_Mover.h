#pragma once
#include "Engine.SequenceEvent.h"
#include "Engine.Actor.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_Mover : public SequenceEvent
	{
	public:
		ADD_STRUCT(float, StayOpenTime, 256)
		void RegisterEvent()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26111);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyEncroachingOn(class Actor* Hit)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26113);
			byte params[4] = { NULL };
			*(class Actor**)params = Hit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyAttached(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26118);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyDetached(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26122);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyFinishedOpen()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26127);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
