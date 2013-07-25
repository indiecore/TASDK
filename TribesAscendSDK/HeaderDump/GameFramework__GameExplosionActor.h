#pragma once
#include "Engine__ParticleSystem.h"
#include "Engine__Actor.h"
#include "Engine__Controller.h"
#include "Engine__PhysicalMaterial.h"
#include "GameFramework__GameExplosion.h"
#include "GameFramework__GamePawn.h"
#include "Engine__PlayerController.h"
#include "Engine__CameraShake.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameExplosionActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.GameExplosionActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameExplosionActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameExplosionActor : public Actor
	{
	public:
		ADD_STRUCT(::VectorProperty, ExplosionDirection, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, DirectionalExplosionMinDot, 0xFFFFFFFF)
		ADD_OBJECT(Controller, AttacheeController)
		ADD_OBJECT(Actor, Attachee)
		ADD_STRUCT(::VectorProperty, HitLocationFromPhysMaterialTrace, 0xFFFFFFFF
		ADD_OBJECT(Actor, HitActorFromPhysMaterialTrace)
		ADD_OBJECT(Controller, InstigatorController)
		ADD_OBJECT(GameExplosion, ExplosionTemplate)
		ADD_VAR(::FloatProperty, RadialBlurMaxBlurAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RadialBlurFadeTimeRemaining, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RadialBlurFadeTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LightInitialBrightness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LightFadeTimeRemaining, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LightFadeTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDrawDebug, 0x4)
		ADD_VAR(::BoolProperty, bExplodeMoreThanOnce, 0x2)
		ADD_VAR(::BoolProperty, bHasExploded, 0x1)
		// Here lies the not-yet-implemented method 'PreBeginPlay'
		// Here lies the not-yet-implemented method 'GetPhysicalMaterial'
		// Here lies the not-yet-implemented method 'DoFullDamageToActor'
		// Here lies the not-yet-implemented method 'IsBehindExplosion'
		// Here lies the not-yet-implemented method 'BoxDistanceToPoint'
		// Here lies the not-yet-implemented method 'DoExplosionDamage'
		// Here lies the not-yet-implemented method 'GetEffectCheckRadius'
		// Here lies the not-yet-implemented method 'SpecialPawnEffectsFor'
		// Here lies the not-yet-implemented method 'UpdateExplosionTemplateWithPerMaterialFX'
		// Here lies the not-yet-implemented method 'SpawnExplosionParticleSystem'
		// Here lies the not-yet-implemented method 'SpawnExplosionDecal'
		// Here lies the not-yet-implemented method 'SpawnExplosionFogVolume'
		// Here lies the not-yet-implemented method 'Explode'
		// Here lies the not-yet-implemented method 'DelayedExplosionDamage'
		// Here lies the not-yet-implemented method 'DrawDebug'
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'DoExplosionCameraEffects'
		// Here lies the not-yet-implemented method 'SpawnCameraLensEffects'
		// Here lies the not-yet-implemented method 'ChooseCameraShake'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
