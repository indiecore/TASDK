#pragma once
#include "Core.Object.h"
namespace UnrealScript
{
	class TrChatConsoleCommands : public Object
	{
	public:
		void ChatConsoleCommand(ScriptArray<wchar_t> Command)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.ChatConsoleCommand");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Command;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReportPlayer(ScriptArray<wchar_t> PlayerName, ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.ReportPlayer");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			*(ScriptArray<wchar_t>*)(params + 12) = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Say(ScriptArray<wchar_t> msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.Say");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TeamSay(ScriptArray<wchar_t> msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.TeamSay");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Mute(ScriptArray<wchar_t> PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.Mute");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Unmute(ScriptArray<wchar_t> PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.Unmute");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Votekick(ScriptArray<wchar_t> PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.Votekick");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Report(ScriptArray<wchar_t> PlayerName, ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.Report");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			*(ScriptArray<wchar_t>*)(params + 12) = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Tell(ScriptArray<wchar_t> PlayerName, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.Tell");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			*(ScriptArray<wchar_t>*)(params + 12) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(int*)params = Count;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SC(ScriptArray<wchar_t> fsRequest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.SC");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = fsRequest;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendCtrlRequest(ScriptArray<wchar_t> fsRequest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.SendCtrlRequest");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = fsRequest;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendGameRequest(ScriptArray<wchar_t> fsRequest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.SendGameRequest");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = fsRequest;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpecList()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsoleCommands.SpecList");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
