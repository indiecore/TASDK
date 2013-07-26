#pragma once
#include "Engine.CameraModifier.h"
#include "Engine.CameraShake.FOscillator.h"
#include "Engine.CameraModifier_CameraShake.CameraShakeInstance.h"
#include "Engine.CameraShake.h"
#include "Core.Object.Rotator.h"
#include "Engine.Camera.h"
#include "Core.Object.TPOV.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.CameraModifier_CameraShake." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class CameraModifier_CameraShake : public CameraModifier
	{
	public:
		ADD_VAR(::FloatProperty, SplitScreenShakeScale, 0xFFFFFFFF)
		float InitializeOffset(FOscillator& Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier_CameraShake.InitializeOffset");
			byte* params = (byte*)malloc(16);
			*(FOscillator*)params = Param;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Param = *(FOscillator*)params;
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		void ReinitShake(int ActiveShakeIdx, float Scale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier_CameraShake.ReinitShake");
			byte* params = (byte*)malloc(8);
			*(int*)params = ActiveShakeIdx;
			*(float*)(params + 4) = Scale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		CameraShakeInstance InitializeShake(class CameraShake* NewShake, float Scale, byte PlaySpace, Rotator UserPlaySpaceRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier_CameraShake.InitializeShake");
			byte* params = (byte*)malloc(165);
			*(class CameraShake**)params = NewShake;
			*(float*)(params + 4) = Scale;
			*(params + 8) = PlaySpace;
			*(Rotator*)(params + 12) = UserPlaySpaceRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(CameraShakeInstance*)(params + 32);
			free(params);
			return returnVal;
		}
		void AddCameraShake(class CameraShake* NewShake, float Scale, byte PlaySpace, Rotator UserPlaySpaceRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier_CameraShake.AddCameraShake");
			byte* params = (byte*)malloc(21);
			*(class CameraShake**)params = NewShake;
			*(float*)(params + 4) = Scale;
			*(params + 8) = PlaySpace;
			*(Rotator*)(params + 12) = UserPlaySpaceRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveCameraShake(class CameraShake* Shake)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier_CameraShake.RemoveCameraShake");
			byte* params = (byte*)malloc(4);
			*(class CameraShake**)params = Shake;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveAllCameraShakes()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier_CameraShake.RemoveAllCameraShakes");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateCameraShake(float DeltaTime, CameraShakeInstance& Shake, TPOV& OutPOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier_CameraShake.UpdateCameraShake");
			byte* params = (byte*)malloc(176);
			*(float*)params = DeltaTime;
			*(CameraShakeInstance*)(params + 16) = Shake;
			*(TPOV*)(params + 160) = OutPOV;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Shake = *(CameraShakeInstance*)(params + 16);
			OutPOV = *(TPOV*)(params + 160);
			free(params);
		}
		bool ModifyCamera(class Camera* Camera, float DeltaTime, TPOV& OutPOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier_CameraShake.ModifyCamera");
			byte* params = (byte*)malloc(40);
			*(class Camera**)params = Camera;
			*(float*)(params + 4) = DeltaTime;
			*(TPOV*)(params + 8) = OutPOV;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutPOV = *(TPOV*)(params + 8);
			auto returnVal = *(bool*)(params + 36);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
