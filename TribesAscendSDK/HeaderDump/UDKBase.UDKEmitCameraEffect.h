#pragma once
#include "Core.Object.h"
#include "Engine.Emitter.h"
#include "UDKBase.UDKPlayerController.h"
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
	class UDKEmitCameraEffect : public Emitter
	{
	public:
		ADD_OBJECT(UDKPlayerController, Cam, 492)
		ADD_STRUCT(float, DistFromCamera, 488)
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
			byte params[4] = { NULL };
			*(class UDKPlayerController**)&params[0] = inCam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
		void UpdateLocation(Object::Vector& CamLoc, Object::Rotator& CamRot, float CamFOVDeg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKEmitCameraEffect.UpdateLocation");
			byte params[28] = { NULL };
			*(Object::Vector*)&params[0] = CamLoc;
			*(Object::Rotator*)&params[12] = CamRot;
			*(float*)&params[24] = CamFOVDeg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CamLoc = *(Object::Vector*)&params[0];
			CamRot = *(Object::Rotator*)&params[12];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
