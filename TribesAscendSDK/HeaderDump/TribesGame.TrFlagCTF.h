#pragma once
#include "TribesGame.TrFlagBase.h"
#include "Engine.Controller.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrFlagCTF : public TrFlagBase
	{
	public:
		ADD_STRUCT(float, m_YouHaveTheFlagReminderTime, 940)
		ADD_STRUCT(int, m_ReturnedTimeLimit, 936)
		ADD_STRUCT(int, m_LastReturnedTime, 932)
		void LogTaken(class Controller* EventInstigator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(88574);
			byte params[4] = { NULL };
			*(class Controller**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogDropped(class Controller* EventInstigator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(88576);
			byte params[4] = { NULL };
			*(class Controller**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearHolder()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(88578);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendHome(class Controller* Returner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(88586);
			byte params[4] = { NULL };
			*(class Controller**)params = Returner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemindPlayerAboutFlagTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(88589);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BroadcastTakenFromBaseMessage(class Controller* EventInstigator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(88592);
			byte params[4] = { NULL };
			*(class Controller**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BroadcastTakenDroppedMessage(class Controller* EventInstigator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(88595);
			byte params[4] = { NULL };
			*(class Controller**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BroadcastCapturedMessage(class Controller* EventInstigator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(88598);
			byte params[4] = { NULL };
			*(class Controller**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BroadcastReturnedMessage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(88600);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BroadcastDroppedMessage(class Controller* EventInstigator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(88603);
			byte params[4] = { NULL };
			*(class Controller**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
