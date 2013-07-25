#pragma once
#include "Engine__Emitter.h"
#include "UDKBase__UDKPlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKEmitCameraEffect." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKEmitCameraEffect." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKEmitCameraEffect : public Emitter
	{
	public:
		ADD_OBJECT(UDKPlayerController, Cam)
		ADD_VAR(::FloatProperty, DistFromCamera, 0xFFFFFFFF)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKEmitCameraEffect.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKEmitCameraEffect.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RegisterCamera(class UDKPlayerController* inCam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKEmitCameraEffect.RegisterCamera");
			byte* params = (byte*)malloc(4);
			*(class UDKPlayerController**)params = inCam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Activate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKEmitCameraEffect.Activate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Deactivate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKEmitCameraEffect.Deactivate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateLocation(Vector& CamLoc, Rotator& CamRot, float CamFOVDeg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKEmitCameraEffect.UpdateLocation");
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
