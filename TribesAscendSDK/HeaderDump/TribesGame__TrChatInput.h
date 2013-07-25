#pragma once
#include "Engine__Interaction.h"
#include "Engine__Canvas.h"
#include "Engine__Texture2D.h"
#include "Engine__LocalPlayer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrChatInput." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrChatInput." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrChatInput : public Interaction
	{
	public:
		ADD_VAR(::BoolProperty, bEnableUI, 0x4)
		ADD_VAR(::BoolProperty, bCtrl, 0x2)
		ADD_VAR(::BoolProperty, bCaptureKeyInput, 0x1)
		ADD_VAR(::StrProperty, ChannelStr, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TypedStrPos, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TypedStr, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, DefaultTexture_White)
		ADD_OBJECT(Texture2D, DefaultTexture_Black)
		ADD_OBJECT(LocalPlayer, ConsoleTargetPlayer)
		void Initialized()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatInput.Initialized");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetInputText(ScriptArray<wchar_t> Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatInput.SetInputText");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Text;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetCursorPos(int Position)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatInput.SetCursorPos");
			byte* params = (byte*)malloc(4);
			*(int*)params = Position;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ConsoleCommand(ScriptArray<wchar_t> Command)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatInput.ConsoleCommand");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Command;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartTyping(ScriptArray<wchar_t> Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatInput.StartTyping");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Text;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostRender_Console(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatInput.PostRender_Console");
			byte* params = (byte*)malloc(4);
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool InputKey(int ControllerId, ScriptName Key, byte Event, float AmountDepressed, bool bGamepad)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatInput.InputKey");
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
		bool InputChar(int ControllerId, ScriptArray<wchar_t> Unicode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatInput.InputChar");
			byte* params = (byte*)malloc(20);
			*(int*)params = ControllerId;
			*(ScriptArray<wchar_t>*)(params + 4) = Unicode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void FlushPlayerInput()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatInput.FlushPlayerInput");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ProcessControlKey(ScriptName Key, byte Event)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatInput.ProcessControlKey");
			byte* params = (byte*)malloc(13);
			*(ScriptName*)params = Key;
			*(params + 8) = Event;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void AppendInputText(ScriptArray<wchar_t> Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrChatInput.AppendInputText");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Text;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
