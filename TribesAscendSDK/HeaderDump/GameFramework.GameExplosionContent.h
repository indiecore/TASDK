#pragma once
#include "Core.Object.h"
#include "Engine.CameraShake.h"
#include "Engine.FogVolumeSphericalDensityInfo.h"
#include "Engine.ParticleSystem.h"
#include "Engine.SoundCue.h"
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
	class GameExplosionContent : public Object
	{
	public:
		ADD_OBJECT(FogVolumeSphericalDensityInfo, FogVolumeArchetype, 128)
		ADD_OBJECT(ParticleSystem, ParticleEmitterTemplate, 124)
		ADD_STRUCT(float, ExploRadialBlurMaxBlur, 120)
		ADD_STRUCT(float, ExploRadialBlurFadeOutTime, 116)
		ADD_STRUCT(float, ExploLightFadeOutTime, 108)
		ADD_STRUCT(float, CameraLensEffectRadius, 100)
		ADD_OBJECT(ScriptClass, CameraLensEffect, 96)
		ADD_STRUCT(float, CamShakeFalloff, 92)
		ADD_STRUCT(float, CamShakeOuterRadius, 88)
		ADD_STRUCT(float, CamShakeInnerRadius, 84)
		ADD_OBJECT(CameraShake, CamShake_Rear, 80)
		ADD_OBJECT(CameraShake, CamShake_Right, 76)
		ADD_OBJECT(CameraShake, CamShake_Left, 72)
		ADD_OBJECT(CameraShake, CamShake, 68)
		ADD_OBJECT(SoundCue, ExplosionSound, 64)
		ADD_BOOL(bOrientCameraShakeTowardsEpicenter, 60, 0x2)
		ADD_BOOL(bAutoControllerVibration, 60, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
