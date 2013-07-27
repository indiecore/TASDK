#pragma once
#include "UTGame.UTConsole.h"
#include "Engine.Console.h"
#include "TribesGame.TrPlayerController.h"
#include "Engine.Canvas.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrChatConsole : public UTConsole
	{
	public:
		ADD_STRUCT(ScriptArray<Console::AutoCompleteCommand>, TribesAutoCompleteList, 468)
		ADD_OBJECT(TrPlayerController, m_TrPC, 536)
		ADD_STRUCT(float, m_fTypingTime, 532)
		ADD_STRUCT(ScriptString*, EscHelp, 520)
		ADD_STRUCT(ScriptString*, TabHelp, 508)
		ADD_STRUCT(ScriptString*, TellHelp, 496)
		ADD_STRUCT(ScriptString*, SlashHelp, 484)
		ADD_STRUCT(int, LastFriendCount, 480)
		ADD_STRUCT(ScriptString*, ChannelStr, 456)
		void Initialized()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74294);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetPlayerController()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74295);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ConsoleCommand(ScriptString* Command)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74297);
			byte params[12] = { NULL };
			*(ScriptString**)params = Command;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartTypingChat(ScriptString* Text, bool bFullConsole, ScriptString* startText)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74300);
			byte params[28] = { NULL };
			*(ScriptString**)params = Text;
			*(bool*)&params[12] = bFullConsole;
			*(ScriptString**)&params[16] = startText;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartTyping(ScriptString* Text)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74304);
			byte params[12] = { NULL };
			*(ScriptString**)params = Text;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsSlashCommand()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74306);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsPlayerTell()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74308);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void PostRender_Console(class Canvas* Canvas)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74310);
			byte params[4] = { NULL };
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool InputKey(int ControllerId, ScriptName Key, Object::EInputEvent Event, float AmountDepressed, bool bGamepad)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74312);
			byte params[25] = { NULL };
			*(int*)params = ControllerId;
			*(ScriptName*)&params[4] = Key;
			*(Object::EInputEvent*)&params[12] = Event;
			*(float*)&params[16] = AmountDepressed;
			*(bool*)&params[20] = bGamepad;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void AddOnlineFriendHelp()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74319);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
