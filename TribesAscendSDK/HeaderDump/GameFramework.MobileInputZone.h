#pragma once
#include "Core.Object.h"
#include "Engine.Texture2D.h"
#include "Engine.Canvas.h"
#include "GameFramework.SeqEvent_MobileZoneBase.h"
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
	class MobileInputZone : public Object
	{
	public:
		enum EZoneType : byte
		{
			ZoneType_Button = 0,
			ZoneType_Joystick = 1,
			ZoneType_Trackball = 2,
			ZoneType_Slider = 3,
			ZoneType_MAX = 4,
		};
		enum EZoneState : byte
		{
			ZoneState_Inactive = 0,
			ZoneState_Activating = 1,
			ZoneState_Active = 2,
			ZoneState_Deactivating = 3,
			ZoneState_MAX = 4,
		};
		enum EZoneTouchEvent : byte
		{
			ZoneEvent_Touch = 0,
			ZoneEvent_Update = 1,
			ZoneEvent_Stationary = 2,
			ZoneEvent_UnTouch = 3,
			ZoneEvent_Cancelled = 4,
			ZoneEvent_MAX = 5,
		};
		enum EZoneSlideType : byte
		{
			ZoneSlide_UpDown = 0,
			ZoneSlide_LeftRight = 1,
			ZoneSlide_MAX = 2,
		};
		class TextureUVs
		{
		public:
			ADD_STRUCT(float, U, 0)
			ADD_STRUCT(float, V, 4)
			ADD_STRUCT(float, UL, 8)
			ADD_STRUCT(float, VL, 12)
		};
		ADD_BOOL(bIsInvisible, 128, 0x200)
		ADD_STRUCT(Object::Color, RenderColor, 180)
		ADD_STRUCT(float, AnimatingFadeOpacity, 376)
		ADD_STRUCT(MobileInputZone::EZoneState, State, 61)
		ADD_STRUCT(float, InactiveAlpha, 184)
		ADD_STRUCT(float, TransitionTime, 384)
		ADD_STRUCT(float, ActivateTime, 172)
		ADD_STRUCT(float, DeactivateTime, 176)
		ADD_STRUCT(MobileInputZone::EZoneType, Type, 60)
		ADD_STRUCT(float, X, 132)
		ADD_STRUCT(float, Y, 136)
		ADD_STRUCT(float, SizeX, 140)
		ADD_STRUCT(float, SizeY, 144)
		ADD_OBJECT(Texture2D, OverrideTexture1, 196)
		ADD_STRUCT(MobileInputZone::TextureUVs, OverrideUVs1, 212)
		ADD_OBJECT(Texture2D, OverrideTexture2, 228)
		ADD_STRUCT(MobileInputZone::TextureUVs, OverrideUVs2, 244)
		ADD_STRUCT(float, ActiveSizeX, 148)
		ADD_STRUCT(float, ActiveSizeY, 152)
		ADD_STRUCT(ScriptString*, Caption, 64)
		ADD_STRUCT(float, CaptionXAdjustment, 188)
		ADD_STRUCT(float, CaptionYAdjustment, 192)
		ADD_STRUCT(Object::Vector2D, CurrentCenter, 276)
		ADD_STRUCT(Object::Vector2D, CurrentLocation, 268)
		ADD_BOOL(bRenderGuides, 128, 0x8000)
		ADD_STRUCT(MobileInputZone::EZoneSlideType, SlideType, 62)
		ADD_STRUCT(ScriptArray<class SeqEvent_MobileZoneBase*>, MobileSeqEventHandlers, 396)
		ADD_STRUCT(float, LastWentActiveTime, 420)
		ADD_STRUCT(float, TotalActiveTime, 416)
		ADD_STRUCT(Object::Vector2D, LastAxisValues, 408)
		ADD_STRUCT(Object::Vector2D, EscapeVelocity, 388)
		ADD_OBJECT(MobilePlayerInput, InputOwner, 380)
		ADD_STRUCT(float, TimeSinceLastTapRepeat, 372)
		ADD_STRUCT(float, LastTouchTime, 368)
		ADD_STRUCT(int, PreviousLocationCount, 364)
		ADD_STRUCT(float, PreviousMoveDeltaTimes, 340)
		ADD_STRUCT(Object::Vector2D, PreviousLocations, 292)
		ADD_STRUCT(Object::Vector2D, InitialCenter, 284)
		ADD_STRUCT(Object::Vector2D, InitialLocation, 260)
		ADD_STRUCT(ScriptString*, OverrideTexture2Name, 232)
		ADD_STRUCT(ScriptString*, OverrideTexture1Name, 200)
		ADD_STRUCT(float, TapDistanceConstraint, 168)
		ADD_STRUCT(float, ResetCenterAfterInactivityTime, 164)
		ADD_STRUCT(float, Border, 160)
		ADD_STRUCT(float, AuthoredGlobalScale, 156)
		ADD_BOOL(bIsDoubleTapAndHold, 128, 0x10000)
		ADD_BOOL(bAllowFirstDeltaForTrackballZone, 128, 0x4000)
		ADD_BOOL(bUseGentleTransitions, 128, 0x2000)
		ADD_BOOL(bFloatingTiltZone, 128, 0x1000)
		ADD_BOOL(bCenterOnEvent, 128, 0x800)
		ADD_BOOL(bQuickDoubleTap, 128, 0x400)
		ADD_BOOL(bCenterY, 128, 0x100)
		ADD_BOOL(bCenterX, 128, 0x80)
		ADD_BOOL(bSizeYFromSizeX, 128, 0x40)
		ADD_BOOL(bActiveSizeYFromX, 128, 0x20)
		ADD_BOOL(bRelativeSizeY, 128, 0x10)
		ADD_BOOL(bRelativeSizeX, 128, 0x8)
		ADD_BOOL(bRelativeY, 128, 0x4)
		ADD_BOOL(bRelativeX, 128, 0x2)
		ADD_BOOL(bScalePawnMovement, 128, 0x1)
		ADD_STRUCT(float, EscapeVelocityStrength, 124)
		ADD_STRUCT(float, Smoothing, 120)
		ADD_STRUCT(float, Acceleration, 116)
		ADD_STRUCT(float, HorizMultiplier, 112)
		ADD_STRUCT(float, VertMultiplier, 108)
		ADD_STRUCT(ScriptName, DoubleTapInputKey, 100)
		ADD_STRUCT(ScriptName, TapInputKey, 92)
		ADD_STRUCT(ScriptName, HorizontalInputKey, 84)
		ADD_STRUCT(ScriptName, InputKey, 76)
		bool OnPreDrawZone(class MobileInputZone* Zone, class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileInputZone.OnPreDrawZone");
			byte params[12] = { NULL };
			*(class MobileInputZone**)&params[0] = Zone;
			*(class Canvas**)&params[4] = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void OnPostDrawZone(class MobileInputZone* Zone, class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileInputZone.OnPostDrawZone");
			byte params[8] = { NULL };
			*(class MobileInputZone**)&params[0] = Zone;
			*(class Canvas**)&params[4] = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool OnProcessSlide(class MobileInputZone* Zone, MobileInputZone::EZoneTouchEvent EventType, int SlideValue, Object::Vector2D ViewportSize)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileInputZone.OnProcessSlide");
			byte params[21] = { NULL };
			*(class MobileInputZone**)&params[0] = Zone;
			*(MobileInputZone::EZoneTouchEvent*)&params[4] = EventType;
			*(int*)&params[8] = SlideValue;
			*(Object::Vector2D*)&params[12] = ViewportSize;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		bool OnDoubleTapDelegate(class MobileInputZone* Zone, MobileInputZone::EZoneTouchEvent EventType, Object::Vector2D TouchLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileInputZone.OnDoubleTapDelegate");
			byte params[17] = { NULL };
			*(class MobileInputZone**)&params[0] = Zone;
			*(MobileInputZone::EZoneTouchEvent*)&params[4] = EventType;
			*(Object::Vector2D*)&params[8] = TouchLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool OnTapDelegate(class MobileInputZone* Zone, MobileInputZone::EZoneTouchEvent EventType, Object::Vector2D TouchLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileInputZone.OnTapDelegate");
			byte params[17] = { NULL };
			*(class MobileInputZone**)&params[0] = Zone;
			*(MobileInputZone::EZoneTouchEvent*)&params[4] = EventType;
			*(Object::Vector2D*)&params[8] = TouchLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool OnProcessInputDelegate(class MobileInputZone* Zone, float DeltaTime, int Handle, MobileInputZone::EZoneTouchEvent EventType, Object::Vector2D TouchLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileInputZone.OnProcessInputDelegate");
			byte params[25] = { NULL };
			*(class MobileInputZone**)&params[0] = Zone;
			*(float*)&params[4] = DeltaTime;
			*(int*)&params[8] = Handle;
			*(MobileInputZone::EZoneTouchEvent*)&params[12] = EventType;
			*(Object::Vector2D*)&params[16] = TouchLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void ActivateZone()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileInputZone.ActivateZone");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DeactivateZone()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileInputZone.DeactivateZone");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddKismetEventHandler(class SeqEvent_MobileZoneBase* NewHandler)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileInputZone.AddKismetEventHandler");
			byte params[4] = { NULL };
			*(class SeqEvent_MobileZoneBase**)&params[0] = NewHandler;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
