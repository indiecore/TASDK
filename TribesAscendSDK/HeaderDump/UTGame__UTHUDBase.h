#pragma once
#include "Engine__PlayerController.h"
#include "Engine__Canvas.h"
#include "Engine__Texture2D.h"
#include "UDKBase__UDKHUD.h"
#include "UTGame__GFxUI_PauseMenu.h"
#include "UTGame__UTPlayerController.h"
#include "UTGame__UTGameReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTHUDBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTHUDBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTHUDBase." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTHUDBase : public UDKHUD
	{
	public:
		ADD_VAR(::BoolProperty, bCrosshairShow, 0x4)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'BlackColor'!
		ADD_OBJECT(Texture2D, IconHudTexture)
		ADD_VAR(::BoolProperty, bCrosshairOnFriendly, 0x8)
		ADD_VAR(::FloatProperty, ResolutionScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastPickupTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ConfiguredCrosshairScaling, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bGreenCrosshair, 0x10)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'LightGreenColor'!
		ADD_VAR(::BoolProperty, bIsSplitScreen, 0x1)
		ADD_VAR(::IntProperty, ViewY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ViewX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ResolutionScaleX, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'LightGoldColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'GoldColor'!
		ADD_VAR(::StrProperty, ConsoleIconFontClassName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastTimeTooltipDrawn, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'ToolTipSepCoords'!
		ADD_VAR(::BoolProperty, bEnableActorOverlays, 0x2)
		ADD_OBJECT(UTGameReplicationInfo, UTGRI)
		ADD_OBJECT(UTPlayerController, UTPlayerOwner)
		ADD_OBJECT(ScriptClass, MusicManagerClass)
		ADD_OBJECT(GFxUI_PauseMenu, PauseMenuMovie)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'Timer'
		// Here lies the not-yet-implemented method 'ShowMenu'
		// Here lies the not-yet-implemented method 'ResolutionChanged'
		// Here lies the not-yet-implemented method 'DisplayHit'
		// Here lies the not-yet-implemented method 'PostRender'
		// Here lies the not-yet-implemented method 'RemoveMovies'
		// Here lies the not-yet-implemented method 'SetVisible'
		// Here lies the not-yet-implemented method 'CloseOtherMenus'
		// Here lies the not-yet-implemented method 'TogglePauseMenu'
		// Here lies the not-yet-implemented method 'CompletePauseMenuClose'
		// Here lies the not-yet-implemented method 'ReleaseShowScores'
		// Here lies the not-yet-implemented method 'GetLocalPlayerOwnerIndex'
		// Here lies the not-yet-implemented method 'DrawToolTip'
		// Here lies the not-yet-implemented method 'CheckCrosshairOnFriendly'
		// Here lies the not-yet-implemented method 'ClearCrosshairOnFriendly'
		// Here lies the not-yet-implemented method 'DrawShadowedTile'
		// Here lies the not-yet-implemented method 'DrawShadowedStretchedTile'
		// Here lies the not-yet-implemented method 'DrawShadowedRotatedTile'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
