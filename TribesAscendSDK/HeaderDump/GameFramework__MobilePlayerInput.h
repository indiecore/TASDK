#pragma once
#include "Engine__PlayerInput.h"
#include "GameFramework__MobileMenuObject.h"
#include "GameFramework__MobileInputZone.h"
#include "GameFramework__MobileMenuScene.h"
#include "Engine__Canvas.h"
#include "GameFramework__SeqEvent_MobileBase.h"
#include "GameFramework__SeqEvent_MobileRawInput.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.MobilePlayerInput." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.MobilePlayerInput." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.MobilePlayerInput." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MobilePlayerInput : public PlayerInput
	{
	public:
		ADD_STRUCT(::VectorProperty, DeviceAccelerometerRawData, 0xFFFFFFFF
		ADD_VAR(::BoolProperty, bDeviceHasGyroscope, 0x10)
		ADD_STRUCT(::VectorProperty, DeviceGyroRawData, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, DeviceMotionAttitude, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, DeviceMotionRotationRate, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, DeviceMotionGravity, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, DeviceMotionAcceleration, 0xFFFFFFFF
		// WARNING: Unknown structure type 'ScriptStruct GameFramework.MobilePlayerInput.TouchData' for the property named 'Touches'!
		ADD_VAR(::FloatProperty, MobileYaw, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobileYawCenter, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobileYawMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobilePitch, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobilePitchCenter, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobilePitchMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobileInactiveTime, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NativeDebugString, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ZoneTimeout, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobileTapRepeatTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobileMinHoldForTap, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobileDoubleTapTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobileYawDeadzoneSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MobilePitchDeadzoneSize, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDeviceHasAccelerometer, 0x20)
		ADD_VAR(::BoolProperty, bFakeMobileTouches, 0x8)
		ADD_VAR(::BoolProperty, bDisableTouchInput, 0x4)
		ADD_VAR(::BoolProperty, bAllowTouchesInCinematic, 0x2)
		ADD_VAR(::BoolProperty, bSupportsAccelerometer, 0x1)
		ADD_VAR(::IntProperty, CurrentMobileGroup, 0xFFFFFFFF)
		ADD_OBJECT(MobileMenuObject, InteractiveObject)
		bool HasZones()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.HasZones");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* GetCurrentZones()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.GetCurrentZones");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
			return returnVal;
		}
		class MobileMenuScene* OpenMenuScene(ScriptClass* SceneClass, ScriptArray<wchar_t> Mode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.OpenMenuScene");
			byte* params = (byte*)malloc(20);
			*(ScriptClass**)params = SceneClass;
			*(ScriptArray<wchar_t>*)(params + 4) = Mode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class MobileMenuScene**)(params + 16);
			free(params);
			return returnVal;
		}
		void OnInputTouch(int Handle, byte Type, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* TouchLocation, float DeviceTimestamp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.OnInputTouch");
			byte* params = (byte*)malloc(17);
			*(int*)params = Handle;
			*(params + 4) = Type;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 8) = TouchLocation;
			*(float*)(params + 16) = DeviceTimestamp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool OnPreviewTouch(float X, float Y)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.OnPreviewTouch");
			byte* params = (byte*)malloc(12);
			*(float*)params = X;
			*(float*)(params + 4) = Y;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void OnTouchNotHandledInMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.OnTouchNotHandledInMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnMobileMotion(class PlayerInput* PlayerInput, Vector CurrentAttitude, Vector CurrentRotationRate, Vector CurrentGravity, Vector CurrentAcceleration)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.OnMobileMotion");
			byte* params = (byte*)malloc(52);
			*(class PlayerInput**)params = PlayerInput;
			*(Vector*)(params + 4) = CurrentAttitude;
			*(Vector*)(params + 16) = CurrentRotationRate;
			*(Vector*)(params + 28) = CurrentGravity;
			*(Vector*)(params + 40) = CurrentAcceleration;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void SendInputKey(ScriptName Key, byte Event, float AmountDepressed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.SendInputKey");
			byte* params = (byte*)malloc(13);
			*(ScriptName*)params = Key;
			*(params + 8) = Event;
			*(float*)(params + 12) = AmountDepressed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendInputAxis(ScriptName Key, float Delta, float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.SendInputAxis");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = Key;
			*(float*)(params + 8) = Delta;
			*(float*)(params + 12) = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(class SeqEvent_MobileBase**)params = NewHandler;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddKismetRawInputEventHandler(class SeqEvent_MobileRawInput* NewHandler)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.AddKismetRawInputEventHandler");
			byte* params = (byte*)malloc(4);
			*(class SeqEvent_MobileRawInput**)params = NewHandler;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class MobileInputZone* FindZone(ScriptArray<wchar_t> ZoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.FindZone");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = ZoneName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class MobileInputZone**)(params + 12);
			free(params);
			return returnVal;
		}
		class MobileInputZone* FindorAddZone(ScriptArray<wchar_t> ZoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.FindorAddZone");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = ZoneName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class MobileInputZone**)(params + 12);
			free(params);
			return returnVal;
		}
		void CloseMenuScene(class MobileMenuScene* SceneToClose)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.CloseMenuScene");
			byte* params = (byte*)malloc(4);
			*(class MobileMenuScene**)params = SceneToClose;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CloseAllMenus()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.CloseAllMenus");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RenderMenus(class Canvas* Canvas, float RenderDelta)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.RenderMenus");
			byte* params = (byte*)malloc(8);
			*(class Canvas**)params = Canvas;
			*(float*)(params + 4) = RenderDelta;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PreClientTravel(ScriptArray<wchar_t> PendingURL, byte TravelType, bool bIsSeamlessTravel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobilePlayerInput.PreClientTravel");
			byte* params = (byte*)malloc(17);
			*(ScriptArray<wchar_t>*)params = PendingURL;
			*(params + 12) = TravelType;
			*(bool*)(params + 16) = bIsSeamlessTravel;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
