#pragma once
#include "UTGame__UTConsole.h"
#include "TribesGame__TrPlayerController.h"
#include "Engine__Canvas.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrChatConsole." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrChatConsole." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrChatConsole : public UTConsole
	{
	public:
		ADD_OBJECT(TrPlayerController, m_TrPC)
		ADD_VAR(::FloatProperty, m_fTypingTime, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EscHelp, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TabHelp, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TellHelp, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SlashHelp, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastFriendCount, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ChannelStr, 0xFFFFFFFF)
		void Initialized()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsole.Initialized");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetPlayerController()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsole.GetPlayerController");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ConsoleCommand(ScriptArray<wchar_t> Command)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsole.ConsoleCommand");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Command;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartTypingChat(ScriptArray<wchar_t> Text, bool bFullConsole, ScriptArray<wchar_t> startText)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsole.StartTypingChat");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = Text;
			*(bool*)(params + 12) = bFullConsole;
			*(ScriptArray<wchar_t>*)(params + 16) = startText;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartTyping(ScriptArray<wchar_t> Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsole.StartTyping");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Text;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsSlashCommand()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsole.IsSlashCommand");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsPlayerTell()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsole.IsPlayerTell");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void PostRender_Console(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsole.PostRender_Console");
			byte* params = (byte*)malloc(4);
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool InputKey(int ControllerId, ScriptName Key, byte Event, float AmountDepressed, bool bGamepad)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsole.InputKey");
			byte* params = (byte*)malloc(25);
			*(int*)params = ControllerId;
			*(ScriptName*)(params + 4) = Key;
			*(params + 12) = Event;
			*(float*)(params + 16) = AmountDepressed;
			*(bool*)(params + 20) = bGamepad;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		void AddOnlineFriendHelp()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatConsole.AddOnlineFriendHelp");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
