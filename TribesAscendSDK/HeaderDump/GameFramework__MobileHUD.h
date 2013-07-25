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
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileHUD.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostRender()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileHUD.PostRender");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawMobileDebugString(float XPos, float YPos, ScriptArray<wchar_t> Str)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileHUD.DrawMobileDebugString");
			byte* params = (byte*)malloc(20);
			*(float*)params = XPos;
			*(float*)(params + 4) = YPos;
			*(ScriptArray<wchar_t>*)(params + 8) = Str;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShowMobileHud()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileHUD.ShowMobileHud");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void RenderMobileMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileHUD.RenderMobileMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawInputZoneOverlays()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileHUD.DrawInputZoneOverlays");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawMobileZone_Button(class MobileInputZone* Zone)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileHUD.DrawMobileZone_Button");
			byte* params = (byte*)malloc(4);
			*(class MobileInputZone**)params = Zone;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawMobileZone_Joystick(class MobileInputZone* Zone)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileHUD.DrawMobileZone_Joystick");
			byte* params = (byte*)malloc(4);
			*(class MobileInputZone**)params = Zone;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawMobileZone_Trackball(class MobileInputZone* Zone)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileHUD.DrawMobileZone_Trackball");
			byte* params = (byte*)malloc(4);
			*(class MobileInputZone**)params = Zone;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawMobileTilt(class MobilePlayerInput* MobileInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileHUD.DrawMobileTilt");
			byte* params = (byte*)malloc(4);
			*(class MobilePlayerInput**)params = MobileInput;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawMobileZone_Slider(class MobileInputZone* Zone)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileHUD.DrawMobileZone_Slider");
			byte* params = (byte*)malloc(4);
			*(class MobileInputZone**)params = Zone;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RefreshKismetLinks()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileHUD.RefreshKismetLinks");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddKismetRenderEvent(class SeqEvent_HudRender* NewEvent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileHUD.AddKismetRenderEvent");
			byte* params = (byte*)malloc(4);
			*(class SeqEvent_HudRender**)params = NewEvent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RenderKismetHud()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileHUD.RenderKismetHud");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
