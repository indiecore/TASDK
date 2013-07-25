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
		// Here lies the not-yet-implemented method 'Initialized'
		// Here lies the not-yet-implemented method 'SetInputText'
		// Here lies the not-yet-implemented method 'SetCursorPos'
		// Here lies the not-yet-implemented method 'PurgeCommandFromHistory'
		// Here lies the not-yet-implemented method 'ConsoleCommand'
		// Here lies the not-yet-implemented method 'ClearOutput'
		// Here lies the not-yet-implemented method 'OutputTextLine'
		// Here lies the not-yet-implemented method 'OutputText'
		// Here lies the not-yet-implemented method 'StartTyping'
		// Here lies the not-yet-implemented method 'PostRender_Console'
		// Here lies the not-yet-implemented method 'InputKey'
		// Here lies the not-yet-implemented method 'InputChar'
		// Here lies the not-yet-implemented method 'FlushPlayerInput'
		// Here lies the not-yet-implemented method 'ProcessControlKey'
		// Here lies the not-yet-implemented method 'AppendInputText'
		// Here lies the not-yet-implemented method 'BuildRuntimeAutoCompleteList'
		// Here lies the not-yet-implemented method 'UpdateCompleteIndices'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
