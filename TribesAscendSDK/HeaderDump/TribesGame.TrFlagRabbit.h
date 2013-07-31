#pragma once
#include "TribesGame.TrFlagBase.h"
#include "Engine.Controller.h"
namespace UnrealScript
{
	class TrFlagRabbit : public TrFlagBase
	{
	public:
		void SetHolder(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(88625);
			byte params[4] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearHolder()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(88628);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendHome(class Controller* Returner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(88629);
			byte params[4] = { NULL };
			*(class Controller**)params = Returner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BroadcastReturnedMessage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(88631);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
