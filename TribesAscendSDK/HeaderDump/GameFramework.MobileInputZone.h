#pragma once
#include "Core.Object.h"
#include "Engine.Texture2D.h"
#include "GameFramework.MobilePlayerInput.h"
#include "GameFramework.SeqEvent_MobileZoneBase.h"
#include "Engine.Canvas.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.MobileInputZone." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.MobileInputZone." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.MobileInputZone." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MobileInputZone : public Object
	{
	public:
		ADD_VAR(::BoolProperty, bIsInvisible, 0x200)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'RenderColor'!
		ADD_VAR(::FloatProperty, AnimatingFadeOpacity, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, State, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InactiveAlpha, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TransitionTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ActivateTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DeactivateTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Type, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, X, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Y, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SizeX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SizeY, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, OverrideTexture1)
		// WARNING: Unknown structure type 'ScriptStruct GameFramework.MobileInputZone.TextureUVs' for the property named 'OverrideUVs1'!
		ADD_OBJECT(Texture2D, OverrideTexture2)
		// WARNING: Unknown structure type 'ScriptStruct GameFramework.MobileInputZone.TextureUVs' for the property named 'OverrideUVs2'!
		ADD_VAR(::FloatProperty, ActiveSizeX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ActiveSizeY, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Caption, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CaptionXAdjustment, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CaptionYAdjustment, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'CurrentCenter'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'CurrentLocation'!
		ADD_VAR(::BoolProperty, bRenderGuides, 0x8000)
		ADD_VAR(::ByteProperty, SlideType, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastWentActiveTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TotalActiveTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'LastAxisValues'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'EscapeVelocity'!
		ADD_OBJECT(MobilePlayerInput, InputOwner)
		ADD_VAR(::FloatProperty, TimeSinceLastTapRepeat, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastTouchTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PreviousLocationCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PreviousMoveDeltaTimes, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'PreviousLocations'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'InitialCenter'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'InitialLocation'!
		ADD_VAR(::StrProperty, OverrideTexture2Name, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OverrideTexture1Name, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TapDistanceConstraint, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ResetCenterAfterInactivityTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Border, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AuthoredGlobalScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsDoubleTapAndHold, 0x10000)
		ADD_VAR(::BoolProperty, bAllowFirstDeltaForTrackballZone, 0x4000)
		ADD_VAR(::BoolProperty, bUseGentleTransitions, 0x2000)
		ADD_VAR(::BoolProperty, bFloatingTiltZone, 0x1000)
		ADD_VAR(::BoolProperty, bCenterOnEvent, 0x800)
		ADD_VAR(::BoolProperty, bQuickDoubleTap, 0x400)
		ADD_VAR(::BoolProperty, bCenterY, 0x100)
		ADD_VAR(::BoolProperty, bCenterX, 0x80)
		ADD_VAR(::BoolProperty, bSizeYFromSizeX, 0x40)
		ADD_VAR(::BoolProperty, bActiveSizeYFromX, 0x20)
		ADD_VAR(::BoolProperty, bRelativeSizeY, 0x10)
		ADD_VAR(::BoolProperty, bRelativeSizeX, 0x8)
		ADD_VAR(::BoolProperty, bRelativeY, 0x4)
		ADD_VAR(::BoolProperty, bRelativeX, 0x2)
		ADD_VAR(::BoolProperty, bScalePawnMovement, 0x1)
		ADD_VAR(::FloatProperty, EscapeVelocityStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Smoothing, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Acceleration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HorizMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VertMultiplier, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, DoubleTapInputKey, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, TapInputKey, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, HorizontalInputKey, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, InputKey, 0xFFFFFFFF)
		bool OnPreDrawZone(class MobileInputZone* Zone, class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileInputZone.OnPreDrawZone");
			byte* params = (byte*)malloc(12);
			*(class MobileInputZone**)params = Zone;
			*(class Canvas**)(params + 4) = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void OnPostDrawZone(class MobileInputZone* Zone, class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileInputZone.OnPostDrawZone");
			byte* params = (byte*)malloc(8);
			*(class MobileInputZone**)params = Zone;
			*(class Canvas**)(params + 4) = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool OnProcessSlide(class MobileInputZone* Zone, byte EventType, int SlideValue, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* ViewportSize)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileInputZone.OnProcessSlide");
			byte* params = (byte*)malloc(21);
			*(class MobileInputZone**)params = Zone;
			*(params + 4) = EventType;
			*(int*)(params + 8) = SlideValue;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 12) = ViewportSize;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool OnDoubleTapDelegate(class MobileInputZone* Zone, byte EventType, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* TouchLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileInputZone.OnDoubleTapDelegate");
			byte* params = (byte*)malloc(17);
			*(class MobileInputZone**)params = Zone;
			*(params + 4) = EventType;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 8) = TouchLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool OnTapDelegate(class MobileInputZone* Zone, byte EventType, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* TouchLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileInputZone.OnTapDelegate");
			byte* params = (byte*)malloc(17);
			*(class MobileInputZone**)params = Zone;
			*(params + 4) = EventType;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 8) = TouchLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool OnProcessInputDelegate(class MobileInputZone* Zone, float DeltaTime, int Handle, byte EventType, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* TouchLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.MobileInputZone.OnProcessInputDelegate");
			byte* params = (byte*)malloc(25);
			*(class MobileInputZone**)params = Zone;
			*(float*)(params + 4) = DeltaTime;
			*(int*)(params + 8) = Handle;
			*(params + 12) = EventType;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 16) = TouchLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(4);
			*(class SeqEvent_MobileZoneBase**)params = NewHandler;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
