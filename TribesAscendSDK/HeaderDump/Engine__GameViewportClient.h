#pragma once
#include "Engine__Console.h"
#include "Core__Object.h"
#include "Engine__UIInteraction.h"
#include "Engine__Interaction.h"
#include "Engine__LocalPlayer.h"
#include "Engine__Canvas.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.GameViewportClient." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.GameViewportClient." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.GameViewportClient." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameViewportClient : public Object
	{
	public:
		ADD_OBJECT(Console, ViewportConsole)
		ADD_OBJECT(UIInteraction, UIController)
		ADD_VAR(::ByteProperty, ActiveSplitscreenType, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, DesiredSplitscreenType, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, UIControllerClass)
		ADD_VAR(::BoolProperty, bDebugNoGFxUI, 0x80)
		ADD_VAR(::ByteProperty, Default2PSplitType, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Default3PSplitType, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.GameViewportClient.TitleSafeZoneArea' for the property named 'TitleSafeZone'!
		ADD_VAR(::BoolProperty, bShowTitleSafeZone, 0x1)
		ADD_VAR(::FloatProperty, ProgressTimeOut, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ProgressFadeTime, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ProgressMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, LoadingMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SavingMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ConnectingMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PrecachingMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PausedMessage, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_FViewportClient'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_FExec'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'Viewport'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'ViewportFrame'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.QWord' for the property named 'ShowFlags'!
		ADD_VAR(::BoolProperty, bDisplayingUIMouseCursor, 0x2)
		ADD_VAR(::BoolProperty, bUIMouseCaptureOverride, 0x4)
		ADD_VAR(::BoolProperty, bOverrideDiffuseAndSpecular, 0x8)
		ADD_VAR(::BoolProperty, bIsPlayInEditorViewport, 0x10)
		ADD_VAR(::BoolProperty, bShowSystemMouseCursor, 0x20)
		ADD_VAR(::BoolProperty, bDisableWorldRendering, 0x40)
		ADD_VAR(::BoolProperty, bUseHardwareCursorWhenWindowed, 0x100)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'ScaleformInteraction'!
		// Here lies the not-yet-implemented method 'ConsoleCommand'
		// Here lies the not-yet-implemented method 'HandleInputKey'
		// Here lies the not-yet-implemented method 'HandleInputAxis'
		// Here lies the not-yet-implemented method 'HandleInputChar'
		// Here lies the not-yet-implemented method 'GetViewportSize'
		// Here lies the not-yet-implemented method 'IsFullScreenViewport'
		// Here lies the not-yet-implemented method 'ShouldForceFullscreenViewport'
		// Here lies the not-yet-implemented method 'GetNumCustomInteractions'
		// Here lies the not-yet-implemented method 'GetCustomInteractionClass'
		// Here lies the not-yet-implemented method 'SetCustomInteractionObject'
		// Here lies the not-yet-implemented method 'CreatePlayer'
		// Here lies the not-yet-implemented method 'AddLocalPlayer'
		// Here lies the not-yet-implemented method 'RemoveLocalPlayer'
		// Here lies the not-yet-implemented method 'NotifyPlayerAdded'
		// Here lies the not-yet-implemented method 'RemovePlayer'
		// Here lies the not-yet-implemented method 'NotifyPlayerRemoved'
		// Here lies the not-yet-implemented method 'FindPlayerByControllerId'
		// Here lies the not-yet-implemented method 'CreateViewportConsole'
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'CreateInitialPlayer'
		// Here lies the not-yet-implemented method 'InsertInteraction'
		// Here lies the not-yet-implemented method 'GameSessionEnded'
		// Here lies the not-yet-implemented method 'SetSplitscreenConfiguration'
		// Here lies the not-yet-implemented method 'GetSplitscreenConfiguration'
		// Here lies the not-yet-implemented method 'UpdateActiveSplitscreenType'
		// Here lies the not-yet-implemented method 'LayoutPlayers'
		// Here lies the not-yet-implemented method 'GetSubtitleRegion'
		// Here lies the not-yet-implemented method 'ConvertLocalPlayerToGamePlayerIndex'
		// Here lies the not-yet-implemented method 'HasTopSafeZone'
		// Here lies the not-yet-implemented method 'HasBottomSafeZone'
		// Here lies the not-yet-implemented method 'HasLeftSafeZone'
		// Here lies the not-yet-implemented method 'HasRightSafeZone'
		// Here lies the not-yet-implemented method 'GetPixelSizeOfScreen'
		// Here lies the not-yet-implemented method 'CalculateSafeZoneValues'
		// Here lies the not-yet-implemented method 'CalculateDeadZoneForAllSides'
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'DrawTitleSafeArea'
		// Here lies the not-yet-implemented method 'PostRender'
		// Here lies the not-yet-implemented method 'DisplayProgressMessage'
		// Here lies the not-yet-implemented method 'DrawTransition'
		// Here lies the not-yet-implemented method 'DrawTransitionMessage'
		// Here lies the not-yet-implemented method 'SetProgressMessage'
		// Here lies the not-yet-implemented method 'NotifyConnectionError'
		// Here lies the not-yet-implemented method 'SetProgressTime'
		// Here lies the not-yet-implemented method 'ClearProgressMessages'
		// Here lies the not-yet-implemented method 'GetPlayerOwner'
		// Here lies the not-yet-implemented method 'FixupOwnerReferences'
		// Here lies the not-yet-implemented method 'OnPrimaryPlayerSwitch'
		// Here lies the not-yet-implemented method 'BecomePrimaryPlayer'
		// Here lies the not-yet-implemented method 'DebugSetUISystemEnabled'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
