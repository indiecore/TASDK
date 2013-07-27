#pragma once
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.CameraShake.h"
#include "Engine.SoundCue.h"
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
	class GameExplosion : public Object
	{
	public:
		ADD_STRUCT(float, CameraLensEffectRadius, 224)
		ADD_OBJECT(ScriptClass, CameraLensEffect, 220)
		ADD_STRUCT(float, CamShakeFalloff, 216)
		ADD_STRUCT(float, CamShakeOuterRadius, 212)
		ADD_STRUCT(float, CamShakeInnerRadius, 208)
		ADD_OBJECT(CameraShake, CamShake_Rear, 204)
		ADD_OBJECT(CameraShake, CamShake_Right, 200)
		ADD_OBJECT(CameraShake, CamShake_Left, 196)
		ADD_OBJECT(CameraShake, CamShake, 192)
		ADD_STRUCT(float, FracturePartVel, 188)
		ADD_STRUCT(float, FractureMeshRadius, 184)
		ADD_STRUCT(float, ExploRadialBlurMaxBlur, 180)
		ADD_STRUCT(float, ExploRadialBlurFadeOutTime, 176)
		ADD_STRUCT(float, ExploLightFadeOutTime, 168)
		ADD_OBJECT(SoundCue, ExplosionSound, 160)
		ADD_STRUCT(Object::Vector, HitNormal, 148)
		ADD_STRUCT(Object::Vector, HitLocation, 136)
		ADD_OBJECT(Actor, HitActor, 132)
		ADD_STRUCT(float, ExplosionEmitterScale, 128)
		ADD_OBJECT(ParticleSystem, ParticleEmitterTemplate, 124)
		ADD_STRUCT(float, MomentumTransferScale, 120)
		ADD_STRUCT(Object::Vector2D, CringeDuration, 112)
		ADD_STRUCT(float, CringeRadius, 108)
		ADD_STRUCT(float, KnockDownStrength, 104)
		ADD_STRUCT(float, KnockDownRadius, 100)
		ADD_OBJECT(ScriptClass, MyDamageType, 96)
		ADD_OBJECT(ScriptClass, ActorClassToIgnoreForKnockdownsAndCringes, 92)
		ADD_OBJECT(ScriptClass, ActorClassToIgnoreForDamage, 88)
		ADD_OBJECT(Actor, ActorToIgnoreForDamage, 84)
		ADD_STRUCT(float, DamageFalloffExponent, 80)
		ADD_STRUCT(float, DamageRadius, 76)
		ADD_STRUCT(float, Damage, 72)
		ADD_STRUCT(float, DamageDelay, 68)
		ADD_STRUCT(float, DirectionalExplosionAngleDeg, 64)
		ADD_BOOL(bAutoControllerVibration, 60, 0x400)
		ADD_BOOL(bOrientCameraShakeTowardsEpicenter, 60, 0x200)
		ADD_BOOL(bUseOverlapCheck, 60, 0x100)
		ADD_BOOL(bUseMapSpecificValues, 60, 0x80)
		ADD_BOOL(bParticleSystemIsBeingOverriddenDontUsePhysMatVersion, 60, 0x40)
		ADD_BOOL(bAllowPerMaterialFX, 60, 0x20)
		ADD_BOOL(bCausesFracture, 60, 0x10)
		ADD_BOOL(bAttachExplosionEmitterToAttachee, 60, 0x8)
		ADD_BOOL(bFullDamageToAttachee, 60, 0x4)
		ADD_BOOL(bAllowTeammateCringes, 60, 0x2)
		ADD_BOOL(bDirectionalExplosion, 60, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
