#pragma once
#include "Engine__Interaction.h"
#include "Engine__Canvas.h"
#include "Engine__Texture2D.h"
#include "Engine__LocalPlayer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Console." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Console." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Console." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Console : public Interaction
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Engine.Console.AutoCompleteNode' for the property named 'AutoCompleteTree'!
		ADD_VAR(::IntProperty, AutoCompleteIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TypedStrPos, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TypedStr, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsRuntimeAutoCompleteUpToDate, 0x40)
		ADD_VAR(::BoolProperty, bRequireCtrlToNavigateAutoComplete, 0x20)
		ADD_VAR(::BoolProperty, bAutoCompleteLocked, 0x10)
		ADD_VAR(::BoolProperty, bEnableUI, 0x8)
		ADD_VAR(::BoolProperty, bCtrl, 0x4)
		ADD_VAR(::BoolProperty, bCaptureKeyInput, 0x2)
		ADD_VAR(::BoolProperty, bNavigatingHistory, 0x1)
		ADD_VAR(::StrProperty, History, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, HistoryCur, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, HistoryBot, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, HistoryTop, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SBPos, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SBHead, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxScrollbackSize, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, TypeKey, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ConsoleKey, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, DefaultTexture_White)
		ADD_OBJECT(Texture2D, DefaultTexture_Black)
		ADD_OBJECT(LocalPlayer, ConsoleTargetPlayer)
		void Initialized()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Console.Initialized");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetInputText(ScriptArray<wchar_t> Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Console.SetInputText");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Text;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetCursorPos(int Position)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Console.SetCursorPos");
			byte* params = (byte*)malloc(4);
			*(int*)params = Position;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PurgeCommandFromHistory(ScriptArray<wchar_t> Command)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Console.PurgeCommandFromHistory");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Command;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ConsoleCommand(ScriptArray<wchar_t> Command)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Console.ConsoleCommand");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Command;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearOutput()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Console.ClearOutput");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OutputTextLine(ScriptArray<wchar_t> Text, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* OverrideColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Console.OutputTextLine");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Text;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 12) = OverrideColor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OutputText(ScriptArray<wchar_t> Text, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* OverrideColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Console.OutputText");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Text;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 12) = OverrideColor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartTyping(ScriptArray<wchar_t> Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Console.StartTyping");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Text;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostRender_Console(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Console.PostRender_Console");
			byte* params = (byte*)malloc(4);
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool InputKey(int ControllerId, ScriptName Key, byte Event, float AmountDepressed, bool bGamepad)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Console.InputKey");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Console.InputChar");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Console.FlushPlayerInput");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ProcessControlKey(ScriptName Key, byte Event)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Console.ProcessControlKey");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Console.AppendInputText");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Text;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BuildRuntimeAutoCompleteList(bool bForce)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Console.BuildRuntimeAutoCompleteList");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bForce;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateCompleteIndices()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Console.UpdateCompleteIndices");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
