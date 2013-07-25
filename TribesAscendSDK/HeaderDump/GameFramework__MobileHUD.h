#pragma once
#include "Engine__HUD.h"
#include "Engine__Font.h"
#include "Engine__Texture2D.h"
#include "GameFramework__MobilePlayerInput.h"
#include "GameFramework__MobileInputZone.h"
#include "GameFramework__SeqEvent_HudRender.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.MobileHUD." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.MobileHUD." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.MobileHUD." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MobileHUD : public HUD
	{
	public:
		ADD_VAR(::FloatProperty, MobileTiltSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobileTiltY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobileTiltX, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct GameFramework.MobileInputZone.TextureUVs' for the property named 'SliderUVs'!
		ADD_OBJECT(Texture2D, SliderImages)
		// WARNING: Unknown structure type 'ScriptStruct GameFramework.MobileInputZone.TextureUVs' for the property named 'TrackballTouchIndicatorUVs'!
		ADD_OBJECT(Texture2D, TrackballTouchIndicator)
		// WARNING: Unknown structure type 'ScriptStruct GameFramework.MobileInputZone.TextureUVs' for the property named 'TrackballBackgroundUVs'!
		ADD_OBJECT(Texture2D, TrackballBackground)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'ButtonCaptionColor'!
		ADD_OBJECT(Font, ButtonFont)
		// WARNING: Unknown structure type 'ScriptStruct GameFramework.MobileInputZone.TextureUVs' for the property named 'ButtonUVs'!
		ADD_OBJECT(Texture2D, ButtonImages)
		// WARNING: Unknown structure type 'ScriptStruct GameFramework.MobileInputZone.TextureUVs' for the property named 'JoystickHatUVs'!
		ADD_OBJECT(Texture2D, JoystickHat)
		// WARNING: Unknown structure type 'ScriptStruct GameFramework.MobileInputZone.TextureUVs' for the property named 'JoystickBackgroundUVs'!
		ADD_OBJECT(Texture2D, JoystickBackground)
		ADD_VAR(::BoolProperty, bShowMotionDebug, 0x80)
		ADD_VAR(::BoolProperty, bDebugZonePresses, 0x40)
		ADD_VAR(::BoolProperty, bDebugZones, 0x20)
		ADD_VAR(::BoolProperty, bDebugTouches, 0x10)
		ADD_VAR(::BoolProperty, bShowMobileTilt, 0x8)
		ADD_VAR(::BoolProperty, bForceMobileHUD, 0x4)
		ADD_VAR(::BoolProperty, bShowMobileHud, 0x2)
		ADD_VAR(::BoolProperty, bShowGameHud, 0x1)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'PostRender'
		// Here lies the not-yet-implemented method 'DrawMobileDebugString'
		// Here lies the not-yet-implemented method 'ShowMobileHud'
		// Here lies the not-yet-implemented method 'RenderMobileMenu'
		// Here lies the not-yet-implemented method 'DrawInputZoneOverlays'
		// Here lies the not-yet-implemented method 'DrawMobileZone_Button'
		// Here lies the not-yet-implemented method 'DrawMobileZone_Joystick'
		// Here lies the not-yet-implemented method 'DrawMobileZone_Trackball'
		// Here lies the not-yet-implemented method 'DrawMobileTilt'
		// Here lies the not-yet-implemented method 'DrawMobileZone_Slider'
		// Here lies the not-yet-implemented method 'RefreshKismetLinks'
		// Here lies the not-yet-implemented method 'AddKismetRenderEvent'
		// Here lies the not-yet-implemented method 'RenderKismetHud'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
