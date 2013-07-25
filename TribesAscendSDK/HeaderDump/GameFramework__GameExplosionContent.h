#pragma once
#include "Engine__SoundCue.h"
#include "Core__Object.h"
#include "Engine__FogVolumeSphericalDensityInfo.h"
#include "Engine__ParticleSystem.h"
#include "Engine__CameraShake.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameExplosionContent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameExplosionContent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameExplosionContent : public Object
	{
	public:
		ADD_OBJECT(FogVolumeSphericalDensityInfo, FogVolumeArchetype)
		ADD_OBJECT(ParticleSystem, ParticleEmitterTemplate)
		ADD_VAR(::FloatProperty, ExploRadialBlurMaxBlur, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExploRadialBlurFadeOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExploLightFadeOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CameraLensEffectRadius, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, CameraLensEffect)
		ADD_VAR(::FloatProperty, CamShakeFalloff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CamShakeOuterRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CamShakeInnerRadius, 0xFFFFFFFF)
		ADD_OBJECT(CameraShake, CamShake_Rear)
		ADD_OBJECT(CameraShake, CamShake_Right)
		ADD_OBJECT(CameraShake, CamShake_Left)
		ADD_OBJECT(CameraShake, CamShake)
		ADD_OBJECT(SoundCue, ExplosionSound)
		ADD_VAR(::BoolProperty, bOrientCameraShakeTowardsEpicenter, 0x2)
		ADD_VAR(::BoolProperty, bAutoControllerVibration, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
