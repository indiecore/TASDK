#pragma once
#include "Core.Object.h"
#include "Engine.Emitter.h"
#include "Engine.Camera.h"
#include "Engine.ParticleSystem.h"
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
	class EmitterCameraLensEffectBase : public Emitter
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptClass*>, EmittersToTreatAsSame, 508)
		ADD_BOOL(bAllowMultipleInstances, 504, 0x1)
		ADD_OBJECT(Camera, BaseCamera, 520)
		ADD_STRUCT(float, DistFromCamera, 500)
		ADD_STRUCT(float, BaseFOV, 496)
		ADD_OBJECT(ParticleSystem, PS_CameraEffectNonExtremeContent, 492)
		ADD_OBJECT(ParticleSystem, PS_CameraEffect, 488)
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15201);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RegisterCamera(class Camera* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15202);
			byte params[4] = { NULL };
			*(class Camera**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyRetriggered()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15204);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15205);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ActivateLensEffect()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15206);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateLocation(Vector& CamLoc, Rotator& CamRot, float CamFOVDeg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15208);
			byte params[28] = { NULL };
			*(Vector*)params = CamLoc;
			*(Rotator*)&params[12] = CamRot;
			*(float*)&params[24] = CamFOVDeg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CamLoc = *(Vector*)params;
			CamRot = *(Rotator*)&params[12];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
