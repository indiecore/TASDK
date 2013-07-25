#pragma once
#include "Engine__CameraShake.h"
#include "Engine__CameraModifier.h"
#include "Engine__Camera.h"
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
		float InitializeOffset(
// WARNING: Unknown structure type 'ScriptStruct Engine.CameraShake.FOscillator'!
void*& Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier_CameraShake.InitializeOffset");
			byte* params = (byte*)malloc(16);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.CameraShake.FOscillator'!
void**)params = Param;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Param = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.CameraShake.FOscillator'!
void**)params;
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
		
// WARNING: Unknown structure type 'ScriptStruct Engine.CameraModifier_CameraShake.CameraShakeInstance'!
void* InitializeShake(class CameraShake* NewShake, float Scale, byte PlaySpace, Rotator UserPlaySpaceRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier_CameraShake.InitializeShake");
			byte* params = (byte*)malloc(165);
			*(class CameraShake**)params = NewShake;
			*(float*)(params + 4) = Scale;
			*(params + 8) = PlaySpace;
			*(Rotator*)(params + 12) = UserPlaySpaceRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.CameraModifier_CameraShake.CameraShakeInstance'!
void**)(params + 32);
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
		void UpdateCameraShake(float DeltaTime, 
// WARNING: Unknown structure type 'ScriptStruct Engine.CameraModifier_CameraShake.CameraShakeInstance'!
void*& Shake, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.TPOV'!
void*& OutPOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier_CameraShake.UpdateCameraShake");
			byte* params = (byte*)malloc(176);
			*(float*)params = DeltaTime;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.CameraModifier_CameraShake.CameraShakeInstance'!
void**)(params + 16) = Shake;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.TPOV'!
void**)(params + 160) = OutPOV;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Shake = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.CameraModifier_CameraShake.CameraShakeInstance'!
void**)(params + 16);
			OutPOV = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.TPOV'!
void**)(params + 160);
			free(params);
		}
		bool ModifyCamera(class Camera* Camera, float DeltaTime, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.TPOV'!
void*& OutPOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier_CameraShake.ModifyCamera");
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
	};
}
#undef ADD_VAR
