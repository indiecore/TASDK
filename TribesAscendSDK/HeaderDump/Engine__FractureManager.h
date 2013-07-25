#pragma once
#include "Engine__ParticleSystem.h"
#include "Engine__Actor.h"
#include "Engine__FracturedStaticMeshActor.h"
#include "Engine__FracturedStaticMeshPart.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.FractureManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class FractureManager : public Actor
	{
	public:
		ADD_VAR(::FloatProperty, ExplosionVelScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DestroyMinAngVel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DestroyVibrationLevel, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnableSpawnChunkEffectForRadialDamage, 0x2)
		ADD_VAR(::BoolProperty, bEnableAntiVibration, 0x1)
		ADD_VAR(::IntProperty, FSMPartPoolSize, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetFSMFractureCullDistanceScale'
		// Here lies the not-yet-implemented method 'GetFSMDirectSpawnChanceScale'
		// Here lies the not-yet-implemented method 'SpawnChunkDestroyEffect'
		// Here lies the not-yet-implemented method 'GetNumFSMPartsScale'
		// Here lies the not-yet-implemented method 'GetFSMRadialSpawnChanceScale'
		// Here lies the not-yet-implemented method 'PreBeginPlay'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'CleanUpFSMParts'
		// Here lies the not-yet-implemented method 'CreateFSMParts'
		// Here lies the not-yet-implemented method 'ResetPoolVisibility'
		// Here lies the not-yet-implemented method 'GetFSMPart'
		// Here lies the not-yet-implemented method 'SpawnPartActor'
		// Here lies the not-yet-implemented method 'ReturnPartActor'
		// Here lies the not-yet-implemented method 'Tick'
	};
}
#undef ADD_VAR
