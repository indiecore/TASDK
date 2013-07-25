#pragma once
#include "Engine__HUD.h"
#include "Engine__Camera.h"
#include "Engine__Actor.h"
#include "GameFramework__GameCameraBase.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GamePlayerCamera." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.GamePlayerCamera." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GamePlayerCamera." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GamePlayerCamera : public Camera
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix' for the property named 'LastTargetBaseTM'!
		ADD_OBJECT(Actor, LastTargetBase)
		ADD_VAR(::FloatProperty, SplitScreenShakeScale, 0xFFFFFFFF)
		ADD_OBJECT(Actor, LastViewTarget)
		ADD_VAR(::FloatProperty, ForcedCamFOV, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bResetInterp, 0x4)
		ADD_VAR(::BoolProperty, bInterpolateCamChanges, 0x2)
		ADD_VAR(::BoolProperty, bUseForcedCamFOV, 0x1)
		ADD_OBJECT(GameCameraBase, CurrentCamera)
		ADD_OBJECT(ScriptClass, FixedCameraClass)
		ADD_OBJECT(GameCameraBase, FixedCam)
		ADD_OBJECT(ScriptClass, ThirdPersonCameraClass)
		ADD_OBJECT(GameCameraBase, ThirdPersonCam)
		class GameCameraBase* CreateCamera(ScriptClass* CameraClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerCamera.CreateCamera");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = CameraClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GameCameraBase**)(params + 4);
			free(params);
			return returnVal;
		}
		void CacheLastTargetBaseInfo(class Actor* TargetBase)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerCamera.CacheLastTargetBaseInfo");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = TargetBase;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerCamera.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerCamera.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class GameCameraBase* FindBestCameraType(class Actor* CameraTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerCamera.FindBestCameraType");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = CameraTarget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GameCameraBase**)(params + 4);
			free(params);
			return returnVal;
		}
		bool ShouldConstrainAspectRatio()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerCamera.ShouldConstrainAspectRatio");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void UpdateViewTarget(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void*& OutVT, float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerCamera.UpdateViewTarget");
			byte* params = (byte*)malloc(48);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void**)params = OutVT;
			*(float*)(params + 44) = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutVT = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void**)params;
			free(params);
		}
		float AdjustFOVForViewport(float inHorizFOV, class Pawn* CameraTargetPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerCamera.AdjustFOVForViewport");
			byte* params = (byte*)malloc(12);
			*(float*)params = inHorizFOV;
			*(class Pawn**)(params + 4) = CameraTargetPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		void UpdateCameraLensEffects(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void*& OutVT)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerCamera.UpdateCameraLensEffects");
			byte* params = (byte*)malloc(44);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void**)params = OutVT;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutVT = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void**)params;
			free(params);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerCamera.DisplayDebug");
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = out_YL;
			*(float*)(params + 8) = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_YL = *(float*)(params + 4);
			out_YPos = *(float*)(params + 8);
			free(params);
		}
		void SetColorScale(Vector NewColorScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerCamera.SetColorScale");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = NewColorScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResetInterpolation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerCamera.ResetInterpolation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProcessViewRotation(float DeltaTime, Rotator& out_ViewRotation, Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GamePlayerCamera.ProcessViewRotation");
			byte* params = (byte*)malloc(28);
			*(float*)params = DeltaTime;
			*(Rotator*)(params + 4) = out_ViewRotation;
			*(Rotator*)(params + 16) = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_ViewRotation = *(Rotator*)(params + 4);
			out_DeltaRot = *(Rotator*)(params + 16);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
