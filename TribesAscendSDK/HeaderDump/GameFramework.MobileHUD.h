#pragma once
#include "GameFramework.SeqEvent_HudRender.h"
#include "Engine.HUD.h"
#include "Engine.Font.h"
#include "Engine.Texture2D.h"
#include "GameFramework.MobileInputZone.h"
#include "Core.Object.h"
#include "GameFramework.MobilePlayerInput.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class MobileHUD : public HUD
	{
	public:
		ADD_STRUCT(ScriptArray<class SeqEvent_HudRender*>, KismetRenderEvents, 1348)
		ADD_STRUCT(float, MobileTiltSize, 1344)
		ADD_STRUCT(float, MobileTiltY, 1340)
		ADD_STRUCT(float, MobileTiltX, 1336)
		ADD_STRUCT(MobileInputZone::TextureUVs, SliderUVs, 1272)
		ADD_OBJECT(Texture2D, SliderImages, 1256)
		ADD_STRUCT(MobileInputZone::TextureUVs, TrackballTouchIndicatorUVs, 1240)
		ADD_OBJECT(Texture2D, TrackballTouchIndicator, 1236)
		ADD_STRUCT(MobileInputZone::TextureUVs, TrackballBackgroundUVs, 1220)
		ADD_OBJECT(Texture2D, TrackballBackground, 1216)
		ADD_STRUCT(Object::Color, ButtonCaptionColor, 1212)
		ADD_OBJECT(Font, ButtonFont, 1208)
		ADD_STRUCT(MobileInputZone::TextureUVs, ButtonUVs, 1176)
		ADD_OBJECT(Texture2D, ButtonImages, 1168)
		ADD_STRUCT(MobileInputZone::TextureUVs, JoystickHatUVs, 1152)
		ADD_OBJECT(Texture2D, JoystickHat, 1148)
		ADD_STRUCT(MobileInputZone::TextureUVs, JoystickBackgroundUVs, 1132)
		ADD_OBJECT(Texture2D, JoystickBackground, 1128)
		ADD_BOOL(bShowMotionDebug, 1124, 0x80)
		ADD_BOOL(bDebugZonePresses, 1124, 0x40)
		ADD_BOOL(bDebugZones, 1124, 0x20)
		ADD_BOOL(bDebugTouches, 1124, 0x10)
		ADD_BOOL(bShowMobileTilt, 1124, 0x8)
		ADD_BOOL(bForceMobileHUD, 1124, 0x4)
		ADD_BOOL(bShowMobileHud, 1124, 0x2)
		ADD_BOOL(bShowGameHud, 1124, 0x1)
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
		void DrawMobileDebugString(float XPos, float YPos, ScriptString* Str)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileHUD.DrawMobileDebugString");
			byte params[20] = { NULL };
			*(float*)&params[0] = XPos;
			*(float*)&params[4] = YPos;
			*(ScriptString**)&params[8] = Str;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShowMobileHud()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileHUD.ShowMobileHud");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
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
			byte params[4] = { NULL };
			*(class MobileInputZone**)&params[0] = Zone;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawMobileZone_Joystick(class MobileInputZone* Zone)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileHUD.DrawMobileZone_Joystick");
			byte params[4] = { NULL };
			*(class MobileInputZone**)&params[0] = Zone;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawMobileZone_Trackball(class MobileInputZone* Zone)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileHUD.DrawMobileZone_Trackball");
			byte params[4] = { NULL };
			*(class MobileInputZone**)&params[0] = Zone;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawMobileTilt(class MobilePlayerInput* MobileInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileHUD.DrawMobileTilt");
			byte params[4] = { NULL };
			*(class MobilePlayerInput**)&params[0] = MobileInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawMobileZone_Slider(class MobileInputZone* Zone)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileHUD.DrawMobileZone_Slider");
			byte params[4] = { NULL };
			*(class MobileInputZone**)&params[0] = Zone;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RefreshKismetLinks()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileHUD.RefreshKismetLinks");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddKismetRenderEvent(class SeqEvent_HudRender* NewEvent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileHUD.AddKismetRenderEvent");
			byte params[4] = { NULL };
			*(class SeqEvent_HudRender**)&params[0] = NewEvent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RenderKismetHud()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileHUD.RenderKismetHud");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
