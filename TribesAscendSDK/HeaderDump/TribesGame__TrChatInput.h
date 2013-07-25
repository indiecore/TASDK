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
		// Here lies the not-yet-implemented method 'Initialized'
		// Here lies the not-yet-implemented method 'SetInputText'
		// Here lies the not-yet-implemented method 'SetCursorPos'
		// Here lies the not-yet-implemented method 'ConsoleCommand'
		// Here lies the not-yet-implemented method 'StartTyping'
		// Here lies the not-yet-implemented method 'PostRender_Console'
		// Here lies the not-yet-implemented method 'InputKey'
		// Here lies the not-yet-implemented method 'InputChar'
		// Here lies the not-yet-implemented method 'FlushPlayerInput'
		// Here lies the not-yet-implemented method 'ProcessControlKey'
		// Here lies the not-yet-implemented method 'AppendInputText'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
