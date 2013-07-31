#pragma once
#include "Engine.Camera.h"
#include "Engine.Pawn.h"
#include "GameFramework.GameCameraBase.h"
#include "GameFramework.GamePlayerCamera.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class GameFixedCamera : public GameCameraBase
	{
	public:
		ADD_STRUCT(float, DefaultFOV, 68)
		void UpdateCamera(class Pawn* P, class GamePlayerCamera* CameraActor, float DeltaTime, Camera::TViewTarget& OutVT)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31703);
			byte params[56] = { NULL };
			*(class Pawn**)params = P;
			*(class GamePlayerCamera**)&params[4] = CameraActor;
			*(float*)&params[8] = DeltaTime;
			*(Camera::TViewTarget*)&params[12] = OutVT;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutVT = *(Camera::TViewTarget*)&params[12];
		}
		void OnBecomeActive(class GameCameraBase* OldCamera)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31709);
			byte params[4] = { NULL };
			*(class GameCameraBase**)params = OldCamera;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
