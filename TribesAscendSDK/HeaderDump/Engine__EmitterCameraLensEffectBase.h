#pragma once
#include "Engine__Emitter.h"
#include "Engine__Camera.h"
#include "Engine__ParticleSystem.h"
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
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'RegisterCamera'
		// Here lies the not-yet-implemented method 'NotifyRetriggered'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'ActivateLensEffect'
		// Here lies the not-yet-implemented method 'UpdateLocation'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
