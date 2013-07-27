#pragma once
#include "Engine.Pawn.h"
#include "GameFramework.GameCameraBase.h"
#include "Engine.Camera.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
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
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GamePlayerCamera : public Camera
	{
	public:
		ADD_STRUCT(Object::Matrix, LastTargetBaseTM, 1136)
		ADD_OBJECT(Actor, LastTargetBase, 1124)
		ADD_STRUCT(float, SplitScreenShakeScale, 1120)
		ADD_OBJECT(Actor, LastViewTarget, 1116)
		ADD_STRUCT(float, ForcedCamFOV, 1112)
		ADD_BOOL(bResetInterp, 1108, 0x4)
		ADD_BOOL(bInterpolateCamChanges, 1108, 0x2)
		ADD_BOOL(bUseForcedCamFOV, 1108, 0x1)
		ADD_OBJECT(GameCameraBase, CurrentCamera, 1104)
		ADD_OBJECT(ScriptClass, FixedCameraClass, 1100)
		ADD_OBJECT(GameCameraBase, FixedCam, 1096)
		ADD_OBJECT(ScriptClass, ThirdPersonCameraClass, 1092)
		ADD_OBJECT(GameCameraBase, ThirdPersonCam, 1088)
		class GameCameraBase* CreateCamera(ScriptClass* CameraClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31745);
			byte params[8] = { NULL };
			*(ScriptClass**)params = CameraClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GameCameraBase**)&params[4];
		}
		void CacheLastTargetBaseInfo(class Actor* TargetBase)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31749);
			byte params[4] = { NULL };
			*(class Actor**)params = TargetBase;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31751);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31752);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class GameCameraBase* FindBestCameraType(class Actor* CameraTarget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31753);
			byte params[8] = { NULL };
			*(class Actor**)params = CameraTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GameCameraBase**)&params[4];
		}
		bool ShouldConstrainAspectRatio()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31757);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void UpdateViewTarget(Camera::TViewTarget& OutVT, float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31759);
			byte params[48] = { NULL };
			*(Camera::TViewTarget*)params = OutVT;
			*(float*)&params[44] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutVT = *(Camera::TViewTarget*)params;
		}
		float AdjustFOVForViewport(float inHorizFOV, class Pawn* CameraTargetPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31765);
			byte params[12] = { NULL };
			*(float*)params = inHorizFOV;
			*(class Pawn**)&params[4] = CameraTargetPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		void UpdateCameraLensEffects(Camera::TViewTarget& OutVT)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31766);
			byte params[44] = { NULL };
			*(Camera::TViewTarget*)params = OutVT;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutVT = *(Camera::TViewTarget*)params;
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31769);
			byte params[12] = { NULL };
			*(class HUD**)params = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		void SetColorScale(Vector NewColorScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31774);
			byte params[12] = { NULL };
			*(Vector*)params = NewColorScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetInterpolation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31776);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProcessViewRotation(float DeltaTime, Rotator& out_ViewRotation, Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31777);
			byte params[28] = { NULL };
			*(float*)params = DeltaTime;
			*(Rotator*)&params[4] = out_ViewRotation;
			*(Rotator*)&params[16] = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ViewRotation = *(Rotator*)&params[4];
			out_DeltaRot = *(Rotator*)&params[16];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
