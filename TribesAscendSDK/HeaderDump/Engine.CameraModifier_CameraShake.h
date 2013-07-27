#pragma once
#include "Engine.CameraModifier.h"
#include "Engine.CameraShake.h"
#include "Engine.Camera.h"
#include "Core.Object.h"
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
	class CameraModifier_CameraShake : public CameraModifier
	{
	public:
		class CameraShakeInstance
		{
		public:
			ADD_STRUCT(Object::Matrix, UserPlaySpaceMatrix, 80)
			ADD_STRUCT(Camera::ECameraAnimPlaySpace, PlaySpace, 68)
			ADD_OBJECT(CameraAnimInst, AnimInst, 64)
			ADD_STRUCT(float, Scale, 60)
			ADD_STRUCT(float, FOVSinOffset, 56)
			ADD_STRUCT(Object::Vector, RotSinOffset, 44)
			ADD_STRUCT(Object::Vector, LocSinOffset, 32)
			ADD_STRUCT(float, CurrentBlendOutTime, 28)
			ADD_BOOL(bBlendingOut, 24, 0x1)
			ADD_STRUCT(float, CurrentBlendInTime, 20)
			ADD_BOOL(bBlendingIn, 16, 0x1)
			ADD_STRUCT(float, OscillatorTimeRemaining, 12)
			ADD_STRUCT(ScriptName, SourceShakeName, 4)
			ADD_OBJECT(CameraShake, SourceShake, 0)
		};
		ADD_STRUCT(ScriptArray<CameraModifier_CameraShake::CameraShakeInstance>, ActiveShakes, 88)
		ADD_STRUCT(float, SplitScreenShakeScale, 100)
		float InitializeOffset(CameraShake::FOscillator& Param)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier_CameraShake.InitializeOffset");
			byte params[16] = { NULL };
			*(CameraShake::FOscillator*)&params[0] = Param;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Param = *(CameraShake::FOscillator*)&params[0];
			return *(float*)&params[12];
		}
		void ReinitShake(int ActiveShakeIdx, float Scale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier_CameraShake.ReinitShake");
			byte params[8] = { NULL };
			*(int*)&params[0] = ActiveShakeIdx;
			*(float*)&params[4] = Scale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		CameraModifier_CameraShake::CameraShakeInstance InitializeShake(class CameraShake* NewShake, float Scale, Camera::ECameraAnimPlaySpace PlaySpace, Object::Rotator UserPlaySpaceRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier_CameraShake.InitializeShake");
			byte params[165] = { NULL };
			*(class CameraShake**)&params[0] = NewShake;
			*(float*)&params[4] = Scale;
			*(Camera::ECameraAnimPlaySpace*)&params[8] = PlaySpace;
			*(Object::Rotator*)&params[12] = UserPlaySpaceRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(CameraModifier_CameraShake::CameraShakeInstance*)&params[32];
		}
		void AddCameraShake(class CameraShake* NewShake, float Scale, Camera::ECameraAnimPlaySpace PlaySpace, Object::Rotator UserPlaySpaceRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier_CameraShake.AddCameraShake");
			byte params[21] = { NULL };
			*(class CameraShake**)&params[0] = NewShake;
			*(float*)&params[4] = Scale;
			*(Camera::ECameraAnimPlaySpace*)&params[8] = PlaySpace;
			*(Object::Rotator*)&params[12] = UserPlaySpaceRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveCameraShake(class CameraShake* Shake)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier_CameraShake.RemoveCameraShake");
			byte params[4] = { NULL };
			*(class CameraShake**)&params[0] = Shake;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveAllCameraShakes()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier_CameraShake.RemoveAllCameraShakes");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateCameraShake(float DeltaTime, CameraModifier_CameraShake::CameraShakeInstance& Shake, Object::TPOV& OutPOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier_CameraShake.UpdateCameraShake");
			byte params[176] = { NULL };
			*(float*)&params[0] = DeltaTime;
			*(CameraModifier_CameraShake::CameraShakeInstance*)&params[16] = Shake;
			*(Object::TPOV*)&params[160] = OutPOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Shake = *(CameraModifier_CameraShake::CameraShakeInstance*)&params[16];
			OutPOV = *(Object::TPOV*)&params[160];
		}
		bool ModifyCamera(class Camera* Camera, float DeltaTime, Object::TPOV& OutPOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CameraModifier_CameraShake.ModifyCamera");
			byte params[40] = { NULL };
			*(class Camera**)&params[0] = Camera;
			*(float*)&params[4] = DeltaTime;
			*(Object::TPOV*)&params[8] = OutPOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutPOV = *(Object::TPOV*)&params[8];
			return *(bool*)&params[36];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
