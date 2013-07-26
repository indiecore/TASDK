#pragma once
#include "Engine.Emitter.h"
#include "Engine.Camera.h"
#include "Core.Object.Rotator.h"
#include "Engine.ParticleSystem.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.EmitterCameraLensEffectBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.EmitterCameraLensEffectBase." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class EmitterCameraLensEffectBase : public Emitter
	{
	public:
		ADD_VAR(::BoolProperty, bAllowMultipleInstances, 0x1)
		ADD_OBJECT(Camera, BaseCamera)
		ADD_VAR(::FloatProperty, DistFromCamera, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BaseFOV, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, PS_CameraEffectNonExtremeContent)
		ADD_OBJECT(ParticleSystem, PS_CameraEffect)
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.EmitterCameraLensEffectBase.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RegisterCamera(class Camera* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.EmitterCameraLensEffectBase.RegisterCamera");
			byte* params = (byte*)malloc(4);
			*(class Camera**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyRetriggered()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.EmitterCameraLensEffectBase.NotifyRetriggered");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.EmitterCameraLensEffectBase.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ActivateLensEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.EmitterCameraLensEffectBase.ActivateLensEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateLocation(Vector& CamLoc, Rotator& CamRot, float CamFOVDeg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.EmitterCameraLensEffectBase.UpdateLocation");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = CamLoc;
			*(Rotator*)(params + 12) = CamRot;
			*(float*)(params + 24) = CamFOVDeg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			CamLoc = *(Vector*)params;
			CamRot = *(Rotator*)(params + 12);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
