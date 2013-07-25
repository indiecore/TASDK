#pragma once
#include "Engine__Actor.h"
#include "Engine__Font.h"
#include "Engine__PlayerController.h"
#include "Engine__Canvas.h"
#include "Engine__Pawn.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.HUD." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.HUD." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.HUD." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class HUD : public Actor
	{
	public:
		ADD_OBJECT(Canvas, Canvas)
		ADD_VAR(::FloatProperty, RatioY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RatioX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CenterY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CenterX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SizeY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SizeX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RenderDelta, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastHUDRenderTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ConsoleMessagePosY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ConsoleMessagePosX, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.HUD.HudLocalizedMessage' for the property named 'LocalMessages'!
		ADD_VAR(::IntProperty, MaxHUDAreaMessageCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MessageFontOffset, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ConsoleFontSize, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ConsoleMessageCount, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'ConsoleColor'!
		ADD_VAR(::FloatProperty, HudCanvasScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShowOverlays, 0x40)
		ADD_VAR(::BoolProperty, bMessageBeep, 0x20)
		ADD_VAR(::BoolProperty, bShowBadConnectionAlert, 0x10)
		ADD_VAR(::BoolProperty, bShowDebugInfo, 0x8)
		ADD_VAR(::BoolProperty, bShowScores, 0x4)
		ADD_VAR(::BoolProperty, bShowHUD, 0x2)
		ADD_VAR(::BoolProperty, bLostFocusPaused, 0x1)
		ADD_OBJECT(PlayerController, PlayerOwner)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'RedColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'GreenColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'WhiteColor'!
		// Here lies the not-yet-implemented method 'ShouldDisplayDebug'
		// Here lies the not-yet-implemented method 'Draw3DLine'
		// Here lies the not-yet-implemented method 'Draw2DLine'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'DrawActorOverlays'
		// Here lies the not-yet-implemented method 'RemovePostRenderedActor'
		// Here lies the not-yet-implemented method 'AddPostRenderedActor'
		// Here lies the not-yet-implemented method 'ToggleHUD'
		// Here lies the not-yet-implemented method 'ShowHUD'
		// Here lies the not-yet-implemented method 'ShowScores'
		// Here lies the not-yet-implemented method 'SetShowScores'
		// Here lies the not-yet-implemented method 'ShowDebug'
		// Here lies the not-yet-implemented method 'ShowDebugInfo'
		// Here lies the not-yet-implemented method 'DrawRoute'
		// Here lies the not-yet-implemented method 'PreCalcValues'
		// Here lies the not-yet-implemented method 'PostRender'
		// Here lies the not-yet-implemented method 'DrawHUD'
		// Here lies the not-yet-implemented method 'DisplayBadConnectionAlert'
		// Here lies the not-yet-implemented method 'ClearMessage'
		// Here lies the not-yet-implemented method 'Message'
		// Here lies the not-yet-implemented method 'DisplayConsoleMessages'
		// Here lies the not-yet-implemented method 'AddConsoleMessage'
		// Here lies the not-yet-implemented method 'LocalizedMessage'
		// Here lies the not-yet-implemented method 'AddLocalizedMessage'
		// Here lies the not-yet-implemented method 'GetScreenCoords'
		// Here lies the not-yet-implemented method 'DrawMessage'
		// Here lies the not-yet-implemented method 'DrawMessageText'
		// Here lies the not-yet-implemented method 'DisplayLocalMessages'
		// Here lies the not-yet-implemented method 'DisplayKismetMessages'
		// Here lies the not-yet-implemented method 'DrawText'
		// Here lies the not-yet-implemented method 'GetFontSizeIndex'
		// Here lies the not-yet-implemented method 'PlayerOwnerDied'
		// Here lies the not-yet-implemented method 'OnLostFocusPause'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
