#pragma once
#include "Engine.LocalPlayer.h"
#include "Engine.Interaction.h"
#include "Engine.Texture2D.h"
#include "Engine.Canvas.h"
#include "Core.Object.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class TrChatInput : public Interaction
	{
	public:
		ADD_BOOL(bEnableUI, 148, 0x4)
		ADD_BOOL(bCtrl, 148, 0x2)
		ADD_BOOL(bCaptureKeyInput, 148, 0x1)
		ADD_STRUCT(ScriptString*, ChannelStr, 136)
		ADD_STRUCT(int, TypedStrPos, 132)
		ADD_STRUCT(ScriptString*, TypedStr, 120)
		ADD_OBJECT(Texture2D, DefaultTexture_White, 116)
		ADD_OBJECT(Texture2D, DefaultTexture_Black, 112)
		ADD_OBJECT(LocalPlayer, ConsoleTargetPlayer, 108)
		void Initialized()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatInput.Initialized");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetInputText(ScriptString* Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatInput.SetInputText");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Text;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCursorPos(int Position)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatInput.SetCursorPos");
			byte params[4] = { NULL };
			*(int*)&params[0] = Position;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ConsoleCommand(ScriptString* Command)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatInput.ConsoleCommand");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Command;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartTyping(ScriptString* Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatInput.StartTyping");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Text;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostRender_Console(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatInput.PostRender_Console");
			byte params[4] = { NULL };
			*(class Canvas**)&params[0] = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool InputKey(int ControllerId, ScriptName Key, Object::EInputEvent Event, float AmountDepressed, bool bGamepad)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatInput.InputKey");
			byte params[25] = { NULL };
			*(int*)&params[0] = ControllerId;
			*(ScriptName*)&params[4] = Key;
			*(Object::EInputEvent*)&params[12] = Event;
			*(float*)&params[16] = AmountDepressed;
			*(bool*)&params[20] = bGamepad;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool InputChar(int ControllerId, ScriptString* Unicode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatInput.InputChar");
			byte params[20] = { NULL };
			*(int*)&params[0] = ControllerId;
			*(ScriptString**)&params[4] = Unicode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void FlushPlayerInput()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatInput.FlushPlayerInput");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ProcessControlKey(ScriptName Key, Object::EInputEvent Event)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatInput.ProcessControlKey");
			byte params[13] = { NULL };
			*(ScriptName*)&params[0] = Key;
			*(Object::EInputEvent*)&params[8] = Event;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void AppendInputText(ScriptString* Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatInput.AppendInputText");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Text;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
