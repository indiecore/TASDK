#pragma once
#include "Engine__TextureRenderTarget2D.h"
#include "GFxUI__SwfMovie.h"
#include "Core__Object.h"
#include "GFxUI__GFxDataStoreSubscriber.h"
#include "Engine__Texture.h"
#include "Engine__PlayerController.h"
#include "Engine__LocalPlayer.h"
#include "Engine__GameViewportClient.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GFxUI.GFxMoviePlayer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GFxUI.GFxMoviePlayer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GFxUI.GFxMoviePlayer." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxMoviePlayer : public Object
	{
	public:
		ADD_VAR(::IntProperty, LocalPlayerOwnerIndex, 0xFFFFFFFF)
		ADD_OBJECT(SwfMovie, MovieInfo)
		ADD_VAR(::BoolProperty, bAutoPlay, 0x80)
		ADD_OBJECT(Object, ExternalInterface)
		ADD_VAR(::BoolProperty, bPauseGameWhileActive, 0x100)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'pMovie'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'pCaptureKeys'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'pFocusIgnoreKeys'!
		ADD_VAR(::IntProperty, NextASUObject, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bMovieIsOpen, 0x1)
		ADD_VAR(::BoolProperty, bDisplayWithHudOff, 0x2)
		ADD_VAR(::BoolProperty, bEnableGammaCorrection, 0x4)
		ADD_VAR(::BoolProperty, bWidgetsInitializedThisFrame, 0x8)
		ADD_VAR(::BoolProperty, bLogUnhandedWidgetInitializations, 0x10)
		ADD_VAR(::BoolProperty, bAllowInput, 0x20)
		ADD_VAR(::BoolProperty, bAllowFocus, 0x40)
		ADD_VAR(::BoolProperty, bCloseOnLevelChange, 0x200)
		ADD_VAR(::BoolProperty, bOnlyOwnerFocusable, 0x400)
		ADD_VAR(::BoolProperty, bDiscardNonOwnerInput, 0x800)
		ADD_VAR(::BoolProperty, bCaptureInput, 0x1000)
		ADD_VAR(::BoolProperty, bIgnoreMouseInput, 0x2000)
		ADD_VAR(::BoolProperty, bForceSmoothAnimation, 0x4000)
		ADD_OBJECT(TextureRenderTarget2D, RenderTexture)
		ADD_VAR(::ByteProperty, TimingMode, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, RenderTextureMode, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Priority, 0xFFFFFFFF)
		ADD_OBJECT(GFxDataStoreSubscriber, DataStoreSubscriber)
		// Here lies the not-yet-implemented method 'OnFocusLost'
		// Here lies the not-yet-implemented method 'OnFocusGained'
		// Here lies the not-yet-implemented method 'ConsoleCommand'
		// Here lies the not-yet-implemented method 'GetPC'
		// Here lies the not-yet-implemented method 'GetLP'
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'SetWidgetPathBinding'
		// Here lies the not-yet-implemented method 'Advance'
		// Here lies the not-yet-implemented method 'PostWidgetInit'
		// Here lies the not-yet-implemented method 'WidgetUnloaded'
		// Here lies the not-yet-implemented method 'WidgetInitialized'
		// Here lies the not-yet-implemented method 'ActionScriptObject'
		// Here lies the not-yet-implemented method 'ActionScriptString'
		// Here lies the not-yet-implemented method 'ActionScriptFloat'
		// Here lies the not-yet-implemented method 'ActionScriptInt'
		// Here lies the not-yet-implemented method 'ActionScriptVoid'
		// Here lies the not-yet-implemented method 'Invoke'
		// Here lies the not-yet-implemented method 'ActionScriptSetFunction'
		// Here lies the not-yet-implemented method 'CreateArray'
		// Here lies the not-yet-implemented method 'CreateObject'
		// Here lies the not-yet-implemented method 'SetVariableStringArray'
		// Here lies the not-yet-implemented method 'SetVariableFloatArray'
		// Here lies the not-yet-implemented method 'SetVariableIntArray'
		// Here lies the not-yet-implemented method 'SetVariableArray'
		// Here lies the not-yet-implemented method 'GetVariableStringArray'
		// Here lies the not-yet-implemented method 'GetVariableFloatArray'
		// Here lies the not-yet-implemented method 'GetVariableIntArray'
		// Here lies the not-yet-implemented method 'GetVariableArray'
		// Here lies the not-yet-implemented method 'SetVariableObject'
		// Here lies the not-yet-implemented method 'SetVariableString'
		// Here lies the not-yet-implemented method 'SetVariableNumber'
		// Here lies the not-yet-implemented method 'SetVariableBool'
		// Here lies the not-yet-implemented method 'SetVariable'
		// Here lies the not-yet-implemented method 'GetVariableObject'
		// Here lies the not-yet-implemented method 'GetVariableString'
		// Here lies the not-yet-implemented method 'GetVariableNumber'
		// Here lies the not-yet-implemented method 'GetVariableBool'
		// Here lies the not-yet-implemented method 'GetVariable'
		// Here lies the not-yet-implemented method 'FilterButtonInput'
		// Here lies the not-yet-implemented method 'FlushPlayerInput'
		// Here lies the not-yet-implemented method 'ClearFocusIgnoreKeys'
		// Here lies the not-yet-implemented method 'AddFocusIgnoreKey'
		// Here lies the not-yet-implemented method 'ClearCaptureKeys'
		// Here lies the not-yet-implemented method 'AddCaptureKey'
		// Here lies the not-yet-implemented method 'SetMovieCanReceiveInput'
		// Here lies the not-yet-implemented method 'SetMovieCanReceiveFocus'
		// Here lies the not-yet-implemented method 'SetPerspective3D'
		// Here lies the not-yet-implemented method 'SetView3D'
		// Here lies the not-yet-implemented method 'GetVisibleFrameRect'
		// Here lies the not-yet-implemented method 'SetAlignment'
		// Here lies the not-yet-implemented method 'SetViewScaleMode'
		// Here lies the not-yet-implemented method 'SetViewport'
		// Here lies the not-yet-implemented method 'GetGameViewportClient'
		// Here lies the not-yet-implemented method 'SetPriority'
		// Here lies the not-yet-implemented method 'PublishDataStoreValues'
		// Here lies the not-yet-implemented method 'RefreshDataStoreBindings'
		// Here lies the not-yet-implemented method 'SetExternalTexture'
		// Here lies the not-yet-implemented method 'SetExternalInterface'
		// Here lies the not-yet-implemented method 'SetForceSmoothAnimation'
		// Here lies the not-yet-implemented method 'SetTimingMode'
		// Here lies the not-yet-implemented method 'SetMovieInfo'
		// Here lies the not-yet-implemented method 'ConditionalClearPause'
		// Here lies the not-yet-implemented method 'OnClose'
		// Here lies the not-yet-implemented method 'Close'
		// Here lies the not-yet-implemented method 'SetPause'
		// Here lies the not-yet-implemented method 'OnPostAdvance'
		// Here lies the not-yet-implemented method 'PostAdvance'
		// Here lies the not-yet-implemented method 'Start'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
