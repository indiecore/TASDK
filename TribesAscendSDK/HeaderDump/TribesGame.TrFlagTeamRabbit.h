#pragma once
#include "TribesGame.TrFlagBase.h"
#include "Engine.Controller.h"
namespace UnrealScript
{
	class TrFlagTeamRabbit : public TrFlagBase
	{
	public:
		void SetHolder(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(88641);
			byte params[4] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearHolder()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(88643);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendHome(class Controller* Returner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(88644);
			byte params[4] = { NULL };
			*(class Controller**)params = Returner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BroadcastReturnedMessage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(88646);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientReturnedHome()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(88655);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
