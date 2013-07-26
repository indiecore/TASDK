#pragma once
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Core.Object.Rotator.h"
#include "GameFramework.GamePlayerCamera.h"
#include "Engine.PostProcessVolume.PostProcessSettings.h"
#include "Engine.Pawn.h"
#include "Engine.Camera.TViewTarget.h"
#include "Engine.HUD.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameCameraBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameCameraBase." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameCameraBase : public Object
	{
	public:
		ADD_VAR(::BoolProperty, bResetCameraInterpolation, 0x1)
		ADD_OBJECT(GamePlayerCamera, PlayerCamera)
		void OnBecomeActive(class GameCameraBase* OldCamera)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCameraBase.OnBecomeActive");
			byte* params = (byte*)malloc(4);
			*(class GameCameraBase**)params = OldCamera;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnBecomeInActive(class GameCameraBase* NewCamera)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCameraBase.OnBecomeInActive");
			byte* params = (byte*)malloc(4);
			*(class GameCameraBase**)params = NewCamera;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResetInterpolation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCameraBase.ResetInterpolation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateCamera(class Pawn* P, class GamePlayerCamera* CameraActor, float DeltaTime, TViewTarget& OutVT)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCameraBase.UpdateCamera");
			byte* params = (byte*)malloc(56);
			*(class Pawn**)params = P;
			*(class GamePlayerCamera**)(params + 4) = CameraActor;
			*(float*)(params + 8) = DeltaTime;
			*(TViewTarget*)(params + 12) = OutVT;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutVT = *(TViewTarget*)(params + 12);
			free(params);
		}
		void ProcessViewRotation(float DeltaTime, class Actor* ViewTarget, Rotator& out_ViewRotation, Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCameraBase.ProcessViewRotation");
			byte* params = (byte*)malloc(32);
			*(float*)params = DeltaTime;
			*(class Actor**)(params + 4) = ViewTarget;
			*(Rotator*)(params + 8) = out_ViewRotation;
			*(Rotator*)(params + 20) = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_ViewRotation = *(Rotator*)(params + 8);
			out_DeltaRot = *(Rotator*)(params + 20);
			free(params);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCameraBase.DisplayDebug");
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = out_YL;
			*(float*)(params + 8) = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_YL = *(float*)(params + 4);
			out_YPos = *(float*)(params + 8);
			free(params);
		}
		void Init()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCameraBase.Init");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ModifyPostProcessSettings(PostProcessSettings& PP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCameraBase.ModifyPostProcessSettings");
			byte* params = (byte*)malloc(220);
			*(PostProcessSettings*)params = PP;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			PP = *(PostProcessSettings*)params;
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
