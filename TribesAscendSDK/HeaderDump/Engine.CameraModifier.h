#pragma once
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.Camera.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.CameraModifier." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.CameraModifier." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class CameraModifier : public Object
	{
	public:
		ADD_VAR(::FloatProperty, TargetAlpha, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Alpha, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AlphaOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AlphaInTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Priority, 0xFFFFFFFF)
		ADD_OBJECT(Camera, CameraOwner)
		ADD_VAR(::BoolProperty, bDebug, 0x8)
		ADD_VAR(::BoolProperty, bExclusive, 0x4)
		ADD_VAR(::BoolProperty, bPendingDisable, 0x2)
		ADD_VAR(::BoolProperty, bDisabled, 0x1)
		bool AddCameraModifier(class Camera* Camera)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier.AddCameraModifier");
			byte* params = (byte*)malloc(8);
			*(class Camera**)params = Camera;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool ProcessViewRotation(class Actor* ViewTarget, float DeltaTime, Rotator& out_ViewRotation, Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier.ProcessViewRotation");
			byte* params = (byte*)malloc(36);
			*(class Actor**)params = ViewTarget;
			*(float*)(params + 4) = DeltaTime;
			*(Rotator*)(params + 8) = out_ViewRotation;
			*(Rotator*)(params + 20) = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_ViewRotation = *(Rotator*)(params + 8);
			out_DeltaRot = *(Rotator*)(params + 20);
			auto returnVal = *(bool*)(params + 32);
			free(params);
			return returnVal;
		}
		void Init()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier.Init");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ModifyCamera(class Camera* Camera, float DeltaTime, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.TPOV'!
void*& OutPOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier.ModifyCamera");
			byte* params = (byte*)malloc(40);
			*(class Camera**)params = Camera;
			*(float*)(params + 4) = DeltaTime;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.TPOV'!
void**)(params + 8) = OutPOV;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutPOV = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.TPOV'!
void**)(params + 8);
			auto returnVal = *(bool*)(params + 36);
			free(params);
			return returnVal;
		}
		bool IsDisabled()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier.IsDisabled");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool RemoveCameraModifier(class Camera* Camera)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier.RemoveCameraModifier");
			byte* params = (byte*)malloc(8);
			*(class Camera**)params = Camera;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void DisableModifier(bool bImmediate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier.DisableModifier");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bImmediate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableModifier()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier.EnableModifier");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleModifier()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier.ToggleModifier");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateAlpha(class Camera* Camera, float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier.UpdateAlpha");
			byte* params = (byte*)malloc(8);
			*(class Camera**)params = Camera;
			*(float*)(params + 4) = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
