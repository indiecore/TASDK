#pragma once
#include "TribesGame__TrFlagBase.h"
#include "Engine__Controller.h"
namespace UnrealScript
{
	class TrFlagRabbit : public TrFlagBase
	{
	public:
		void SetHolder(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagRabbit.SetHolder");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearHolder()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagRabbit.ClearHolder");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendHome(class Controller* Returner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagRabbit.SendHome");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = Returner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BroadcastReturnedMessage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagRabbit.BroadcastReturnedMessage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
