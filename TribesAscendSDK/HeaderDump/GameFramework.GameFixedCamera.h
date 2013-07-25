#pragma once
#include "Engine.Pawn.h"
#include "GameFramework.GameCameraBase.h"
#include "GameFramework.GamePlayerCamera.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameFixedCamera." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GameFixedCamera : public GameCameraBase
	{
	public:
		ADD_VAR(::FloatProperty, DefaultFOV, 0xFFFFFFFF)
		void UpdateCamera(class Pawn* P, class GamePlayerCamera* CameraActor, float DeltaTime, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void*& OutVT)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameFixedCamera.UpdateCamera");
			byte* params = (byte*)malloc(56);
			*(class Pawn**)params = P;
			*(class GamePlayerCamera**)(params + 4) = CameraActor;
			*(float*)(params + 8) = DeltaTime;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void**)(params + 12) = OutVT;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutVT = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.TViewTarget'!
void**)(params + 12);
			free(params);
		}
		void OnBecomeActive(class GameCameraBase* OldCamera)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameFixedCamera.OnBecomeActive");
			byte* params = (byte*)malloc(4);
			*(class GameCameraBase**)params = OldCamera;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
