#pragma once
#include "Core.Object.h"
namespace UnrealScript
{
	class TrChatConsoleCommands : public Object
	{
	public:
		void ChatConsoleCommand(ScriptString* Command)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74377);
			byte params[12] = { NULL };
			*(ScriptString**)params = Command;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReportPlayer(ScriptString* PlayerName, ScriptString* Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74379);
			byte params[24] = { NULL };
			*(ScriptString**)params = PlayerName;
			*(ScriptString**)&params[12] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Say(ScriptString* msg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74382);
			byte params[12] = { NULL };
			*(ScriptString**)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamSay(ScriptString* msg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74384);
			byte params[12] = { NULL };
			*(ScriptString**)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Mute(ScriptString* PlayerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74386);
			byte params[12] = { NULL };
			*(ScriptString**)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Unmute(ScriptString* PlayerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74388);
			byte params[12] = { NULL };
			*(ScriptString**)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Votekick(ScriptString* PlayerName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74390);
			byte params[12] = { NULL };
			*(ScriptString**)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Report(ScriptString* PlayerName, ScriptString* Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74392);
			byte params[24] = { NULL };
			*(ScriptString**)params = PlayerName;
			*(ScriptString**)&params[12] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Tell(ScriptString* PlayerName, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74395);
			byte params[24] = { NULL };
			*(ScriptString**)params = PlayerName;
			*(ScriptString**)&params[12] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Exit()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74398);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Quit()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74399);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GiveCredits(int Count)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74400);
			byte params[4] = { NULL };
			*(int*)params = Count;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SC(ScriptString* fsRequest)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74402);
			byte params[12] = { NULL };
			*(ScriptString**)params = fsRequest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendCtrlRequest(ScriptString* fsRequest)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74404);
			byte params[12] = { NULL };
			*(ScriptString**)params = fsRequest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendGameRequest(ScriptString* fsRequest)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74406);
			byte params[12] = { NULL };
			*(ScriptString**)params = fsRequest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpecList()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74408);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
