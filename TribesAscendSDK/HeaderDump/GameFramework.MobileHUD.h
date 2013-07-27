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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32333);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostRender()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32334);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawMobileDebugString(float XPos, float YPos, ScriptString* Str)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32343);
			byte params[20] = { NULL };
			*(float*)params = XPos;
			*(float*)&params[4] = YPos;
			*(ScriptString**)&params[8] = Str;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShowMobileHud()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32347);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void RenderMobileMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32349);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawInputZoneOverlays()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32359);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawMobileZone_Button(class MobileInputZone* Zone)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32387);
			byte params[4] = { NULL };
			*(class MobileInputZone**)params = Zone;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawMobileZone_Joystick(class MobileInputZone* Zone)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32411);
			byte params[4] = { NULL };
			*(class MobileInputZone**)params = Zone;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawMobileZone_Trackball(class MobileInputZone* Zone)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32425);
			byte params[4] = { NULL };
			*(class MobileInputZone**)params = Zone;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawMobileTilt(class MobilePlayerInput* MobileInput)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32429);
			byte params[4] = { NULL };
			*(class MobilePlayerInput**)params = MobileInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawMobileZone_Slider(class MobileInputZone* Zone)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32446);
			byte params[4] = { NULL };
			*(class MobileInputZone**)params = Zone;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RefreshKismetLinks()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32453);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddKismetRenderEvent(class SeqEvent_HudRender* NewEvent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32458);
			byte params[4] = { NULL };
			*(class SeqEvent_HudRender**)params = NewEvent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RenderKismetHud()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32461);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
