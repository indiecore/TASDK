#pragma once
#include "Engine__HUD.h"
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
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
