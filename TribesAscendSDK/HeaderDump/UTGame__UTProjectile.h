#pragma once
#include "Engine__Actor.h"
#include "Engine__ParticleSystem.h"
#include "UDKBase__UDKProjectile.h"
#include "Engine__MaterialInterface.h"
#include "Engine__SoundCue.h"
#include "Engine__PhysicalMaterial.h"
#include "Engine__Pawn.h"
#include "Engine__Controller.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTProjectile." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTProjectile." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTProjectile : public UDKProjectile
	{
	public:
		ADD_VAR(::FloatProperty, GlobalCheckRadiusTweak, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TossZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxExplosionLightDistance, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, ExplosionLightClass)
		ADD_OBJECT(ScriptClass, ProjectileLightClass)
		ADD_VAR(::FloatProperty, MaxEffectDistance, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, DecalDissolveParamName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DurationOfDecal, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DecalHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DecalWidth, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInterface, ExplosionDecal)
		ADD_OBJECT(ParticleSystem, ProjExplosionTemplate)
		ADD_OBJECT(ParticleSystem, ProjFlightTemplate)
		ADD_OBJECT(SoundCue, ExplosionSound)
		ADD_OBJECT(SoundCue, AmbientSound)
		ADD_VAR(::BoolProperty, bAttachExplosionToVehicles, 0x40)
		ADD_VAR(::BoolProperty, bWaitForEffects, 0x20)
		ADD_VAR(::BoolProperty, bSuppressExplosionFX, 0x10)
		ADD_VAR(::BoolProperty, bAdvanceExplosionEffect, 0x8)
		ADD_VAR(::BoolProperty, m_bDestroyProjEffects, 0x4)
		ADD_VAR(::BoolProperty, bImportantAmbientSound, 0x2)
		ADD_VAR(::BoolProperty, bSuppressSounds, 0x1)
		// Here lies the not-yet-implemented method 'CreateProjectileLight'
		// Here lies the not-yet-implemented method 'Landed'
		// Here lies the not-yet-implemented method 'CanSplash'
		// Here lies the not-yet-implemented method 'PreBeginPlay'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'SetInitialState'
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'ProcessTouch'
		// Here lies the not-yet-implemented method 'Explode'
		// Here lies the not-yet-implemented method 'SpawnFlightEffects'
		// Here lies the not-yet-implemented method 'SetExplosionEffectParameters'
		// Here lies the not-yet-implemented method 'GetExplosionSound'
		// Here lies the not-yet-implemented method 'SpawnExplosionEffects'
		// Here lies the not-yet-implemented method 'ShouldSpawnExplosionLight'
		// Here lies the not-yet-implemented method 'ShutDown'
		// Here lies the not-yet-implemented method 'TornOff'
		// Here lies the not-yet-implemented method 'HideProjectile'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'MyOnParticleSystemFinished'
		// Here lies the not-yet-implemented method 'CalcCamera'
		// Here lies the not-yet-implemented method 'GetHomingTarget'
		// Here lies the not-yet-implemented method 'GetPawnOwner'
		// Here lies the not-yet-implemented method 'CalculateTravelTime'
		// Here lies the not-yet-implemented method 'StaticGetTimeToLocation'
		// Here lies the not-yet-implemented method 'GetTimeToLocation'
		// Here lies the not-yet-implemented method 'GetRange'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
