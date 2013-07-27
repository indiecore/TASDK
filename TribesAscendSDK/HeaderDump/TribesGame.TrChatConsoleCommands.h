#pragma once
#include "Core.Object.h"
namespace UnrealScript
{
	class TrChatConsoleCommands : public Object
	{
	public:
		void ChatConsoleCommand(ScriptString* Command)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.ChatConsoleCommand");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Command;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReportPlayer(ScriptString* PlayerName, ScriptString* Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.ReportPlayer");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			*(ScriptString**)&params[12] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Say(ScriptString* msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.Say");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamSay(ScriptString* msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.TeamSay");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Mute(ScriptString* PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.Mute");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Unmute(ScriptString* PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.Unmute");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Votekick(ScriptString* PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.Votekick");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Report(ScriptString* PlayerName, ScriptString* Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.Report");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			*(ScriptString**)&params[12] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Tell(ScriptString* PlayerName, ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.Tell");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			*(ScriptString**)&params[12] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Exit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.Exit");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Quit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.Quit");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GiveCredits(int Count)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.GiveCredits");
			byte params[4] = { NULL };
			*(int*)&params[0] = Count;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SC(ScriptString* fsRequest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.SC");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = fsRequest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendCtrlRequest(ScriptString* fsRequest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.SendCtrlRequest");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = fsRequest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendGameRequest(ScriptString* fsRequest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.SendGameRequest");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = fsRequest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpecList()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.SpecList");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
