#pragma once
#include "Engine.PlayerInput.h"
#include "GameFramework.SeqEvent_MobileRawInput.h"
#include "GameFramework.SeqEvent_MobileBase.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "GameFramework.MobileMenuObject.h"
#include "GameFramework.MobileInputZone.h"
#include "Engine.Canvas.h"
#include "GameFramework.MobileMenuScene.h"
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
	class MobilePlayerInput : public PlayerInput
	{
	public:
		static const auto NumTouchDataEntries = 5;
		enum EUIOrientation : byte
		{
			UI_Unknown = 0,
			UI_Portait = 1,
			UI_PortaitUpsideDown = 2,
			UI_LandscapeRight = 3,
			UI_LandscapeLeft = 4,
			UI_MAX = 5,
		};
		class MobileInputGroup
		{
		public:
			ADD_STRUCT(ScriptArray<class MobileInputZone*>, AssociatedZones, 12)
			ADD_STRUCT(ScriptString*, GroupName, 0)
		};
		class MobileInputZoneClassMap
		{
		public:
			ADD_OBJECT(ScriptClass, ClassType, 12)
			ADD_STRUCT(ScriptString*, Name, 0)
		};
		class TouchDataEvent
		{
		public:
			ADD_STRUCT(Object::Double, DeviceTime, 12)
			ADD_STRUCT(Object::Vector2D, Location, 4)
			ADD_STRUCT(MobileInputZone::EZoneTouchEvent, EventType, 0)
		};
		class TouchData
		{
		public:
			ADD_BOOL(bInUse, 40, 0x1)
			ADD_STRUCT(MobileInputZone::EZoneTouchEvent, State, 48)
			ADD_OBJECT(MobileInputZone, Zone, 44)
			ADD_STRUCT(int, Handle, 0)
			ADD_STRUCT(ScriptArray<MobilePlayerInput::TouchDataEvent>, Events, 52)
			ADD_STRUCT(float, LastActiveTime, 64)
			ADD_STRUCT(float, MoveDeltaTime, 36)
			ADD_STRUCT(Object::Double, MoveEventDeviceTime, 28)
			ADD_STRUCT(float, TouchDuration, 24)
			ADD_STRUCT(Object::Double, InitialDeviceTime, 16)
			ADD_STRUCT(float, TotalMoveDistance, 12)
			ADD_STRUCT(Object::Vector2D, Location, 4)
		};
		ADD_STRUCT(Object::Vector, DeviceAccelerometerRawData, 928)
		ADD_BOOL(bDeviceHasGyroscope, 764, 0x10)
		ADD_STRUCT(Object::Vector, DeviceGyroRawData, 916)
		ADD_STRUCT(Object::Vector, DeviceMotionAttitude, 844)
		ADD_STRUCT(Object::Vector, DeviceMotionRotationRate, 856)
		ADD_STRUCT(Object::Vector, DeviceMotionGravity, 868)
		ADD_STRUCT(Object::Vector, DeviceMotionAcceleration, 880)
		ADD_STRUCT(MobilePlayerInput::TouchData, Touches, 380)
		ADD_STRUCT(float, MobileYaw, 780)
		ADD_STRUCT(float, MobileYawCenter, 784)
		ADD_STRUCT(float, MobileYawMultiplier, 788)
		ADD_STRUCT(float, MobilePitch, 768)
		ADD_STRUCT(float, MobilePitchCenter, 772)
		ADD_STRUCT(float, MobilePitchMultiplier, 776)
		ADD_STRUCT(ScriptArray<MobilePlayerInput::MobileInputGroup>, MobileInputGroups, 724)
		ADD_STRUCT(ScriptArray<class MobileInputZone*>, MobileInputZones, 740)
		ADD_STRUCT(ScriptArray<MobilePlayerInput::MobileInputZoneClassMap>, MobileInputZoneClasses, 752)
		ADD_STRUCT(ScriptArray<class MobileMenuScene*>, MobileMenuStack, 816)
		ADD_STRUCT(ScriptArray<class SeqEvent_MobileBase*>, MobileSeqEventHandlers, 892)
		ADD_STRUCT(ScriptArray<class SeqEvent_MobileRawInput*>, MobileRawInputSeqEventHandlers, 904)
		ADD_STRUCT(float, MobileInactiveTime, 840)
		ADD_STRUCT(ScriptString*, NativeDebugString, 828)
		ADD_STRUCT(float, ZoneTimeout, 812)
		ADD_STRUCT(float, MobileTapRepeatTime, 808)
		ADD_STRUCT(float, MobileMinHoldForTap, 804)
		ADD_STRUCT(float, MobileDoubleTapTime, 800)
		ADD_STRUCT(float, MobileYawDeadzoneSize, 796)
		ADD_STRUCT(float, MobilePitchDeadzoneSize, 792)
		ADD_BOOL(bDeviceHasAccelerometer, 764, 0x20)
		ADD_BOOL(bFakeMobileTouches, 764, 0x8)
		ADD_BOOL(bDisableTouchInput, 764, 0x4)
		ADD_BOOL(bAllowTouchesInCinematic, 764, 0x2)
		ADD_BOOL(bSupportsAccelerometer, 764, 0x1)
		ADD_STRUCT(int, CurrentMobileGroup, 736)
		ADD_OBJECT(MobileMenuObject, InteractiveObject, 720)
		bool HasZones()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.HasZones");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		ScriptArray<class MobileInputZone*> GetCurrentZones()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.GetCurrentZones");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptArray<class MobileInputZone*>*)&params[0];
		}
		class MobileMenuScene* OpenMenuScene(ScriptClass* SceneClass, ScriptString* Mode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.OpenMenuScene");
			byte params[20] = { NULL };
			*(ScriptClass**)&params[0] = SceneClass;
			*(ScriptString**)&params[4] = Mode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MobileMenuScene**)&params[16];
		}
		void OnInputTouch(int Handle, MobileInputZone::EZoneTouchEvent Type, Object::Vector2D TouchLocation, float DeviceTimestamp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.OnInputTouch");
			byte params[17] = { NULL };
			*(int*)&params[0] = Handle;
			*(MobileInputZone::EZoneTouchEvent*)&params[4] = Type;
			*(Object::Vector2D*)&params[8] = TouchLocation;
			*(float*)&params[16] = DeviceTimestamp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool OnPreviewTouch(float X, float Y)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.OnPreviewTouch");
			byte params[12] = { NULL };
			*(float*)&params[0] = X;
			*(float*)&params[4] = Y;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void OnTouchNotHandledInMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.OnTouchNotHandledInMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnMobileMotion(class PlayerInput* PlayerInput, Object::Vector CurrentAttitude, Object::Vector CurrentRotationRate, Object::Vector CurrentGravity, Object::Vector CurrentAcceleration)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.OnMobileMotion");
			byte params[52] = { NULL };
			*(class PlayerInput**)&params[0] = PlayerInput;
			*(Object::Vector*)&params[4] = CurrentAttitude;
			*(Object::Vector*)&params[16] = CurrentRotationRate;
			*(Object::Vector*)&params[28] = CurrentGravity;
			*(Object::Vector*)&params[40] = CurrentAcceleration;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NativeInitializeInputSystem()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.NativeInitializeInputSystem");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NativeInitializeInputZones()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.NativeInitializeInputZones");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendInputKey(ScriptName Key, Object::EInputEvent Event, float AmountDepressed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.SendInputKey");
			byte params[13] = { NULL };
			*(ScriptName*)&params[0] = Key;
			*(Object::EInputEvent*)&params[8] = Event;
			*(float*)&params[12] = AmountDepressed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendInputAxis(ScriptName Key, float Delta, float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.SendInputAxis");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = Key;
			*(float*)&params[8] = Delta;
			*(float*)&params[12] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitInputSystem()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.InitInputSystem");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientInitInputSystem()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.ClientInitInputSystem");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitTouchSystem()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.InitTouchSystem");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitializeInputZones()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.InitializeInputZones");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RefreshKismetLinks()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.RefreshKismetLinks");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddKismetEventHandler(class SeqEvent_MobileBase* NewHandler)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.AddKismetEventHandler");
			byte params[4] = { NULL };
			*(class SeqEvent_MobileBase**)&params[0] = NewHandler;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddKismetRawInputEventHandler(class SeqEvent_MobileRawInput* NewHandler)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.AddKismetRawInputEventHandler");
			byte params[4] = { NULL };
			*(class SeqEvent_MobileRawInput**)&params[0] = NewHandler;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class MobileInputZone* FindZone(ScriptString* ZoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.FindZone");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = ZoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MobileInputZone**)&params[12];
		}
		class MobileInputZone* FindorAddZone(ScriptString* ZoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.FindorAddZone");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = ZoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MobileInputZone**)&params[12];
		}
		void CloseMenuScene(class MobileMenuScene* SceneToClose)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.CloseMenuScene");
			byte params[4] = { NULL };
			*(class MobileMenuScene**)&params[0] = SceneToClose;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CloseAllMenus()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.CloseAllMenus");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RenderMenus(class Canvas* Canvas, float RenderDelta)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.RenderMenus");
			byte params[8] = { NULL };
			*(class Canvas**)&params[0] = Canvas;
			*(float*)&params[4] = RenderDelta;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PreClientTravel(ScriptString* PendingURL, Actor::ETravelType TravelType, bool bIsSeamlessTravel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.PreClientTravel");
			byte params[17] = { NULL };
			*(ScriptString**)&params[0] = PendingURL;
			*(Actor::ETravelType*)&params[12] = TravelType;
			*(bool*)&params[16] = bIsSeamlessTravel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
