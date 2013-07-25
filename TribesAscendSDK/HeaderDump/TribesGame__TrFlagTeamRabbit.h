#pragma once
#include "TribesGame__TrFlagBase.h"
#include "Engine__Controller.h"
namespace UnrealScript
{
	class TrFlagTeamRabbit : public TrFlagBase
	{
	public:
		void SetHolder(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagTeamRabbit.SetHolder");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearHolder()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagTeamRabbit.ClearHolder");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendHome(class Controller* Returner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagTeamRabbit.SendHome");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = Returner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BroadcastReturnedMessage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagTeamRabbit.BroadcastReturnedMessage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientReturnedHome()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFlagTeamRabbit.ClientReturnedHome");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
