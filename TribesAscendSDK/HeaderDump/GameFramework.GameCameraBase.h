#pragma once
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "GameFramework.GamePlayerCamera.h"
#include "Engine.PostProcessVolume.h"
#include "Engine.Camera.h"
#include "Engine.Pawn.h"
#include "Engine.HUD.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GameCameraBase : public Object
	{
	public:
		ADD_BOOL(bResetCameraInterpolation, 64, 0x1)
		ADD_OBJECT(GamePlayerCamera, PlayerCamera, 60)
		void OnBecomeActive(class GameCameraBase* OldCamera)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCameraBase.OnBecomeActive");
			byte params[4] = { NULL };
			*(class GameCameraBase**)&params[0] = OldCamera;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnBecomeInActive(class GameCameraBase* NewCamera)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCameraBase.OnBecomeInActive");
			byte params[4] = { NULL };
			*(class GameCameraBase**)&params[0] = NewCamera;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetInterpolation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCameraBase.ResetInterpolation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateCamera(class Pawn* P, class GamePlayerCamera* CameraActor, float DeltaTime, Camera::TViewTarget& OutVT)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCameraBase.UpdateCamera");
			byte params[56] = { NULL };
			*(class Pawn**)&params[0] = P;
			*(class GamePlayerCamera**)&params[4] = CameraActor;
			*(float*)&params[8] = DeltaTime;
			*(Camera::TViewTarget*)&params[12] = OutVT;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutVT = *(Camera::TViewTarget*)&params[12];
		}
		void ProcessViewRotation(float DeltaTime, class Actor* ViewTarget, Object::Rotator& out_ViewRotation, Object::Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCameraBase.ProcessViewRotation");
			byte params[32] = { NULL };
			*(float*)&params[0] = DeltaTime;
			*(class Actor**)&params[4] = ViewTarget;
			*(Object::Rotator*)&params[8] = out_ViewRotation;
			*(Object::Rotator*)&params[20] = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ViewRotation = *(Object::Rotator*)&params[8];
			out_DeltaRot = *(Object::Rotator*)&params[20];
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCameraBase.DisplayDebug");
			byte params[12] = { NULL };
			*(class HUD**)&params[0] = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		void Init()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCameraBase.Init");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ModifyPostProcessSettings(PostProcessVolume::PostProcessSettings& PP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCameraBase.ModifyPostProcessSettings");
			byte params[220] = { NULL };
			*(PostProcessVolume::PostProcessSettings*)&params[0] = PP;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PP = *(PostProcessVolume::PostProcessSettings*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_OBJECT
