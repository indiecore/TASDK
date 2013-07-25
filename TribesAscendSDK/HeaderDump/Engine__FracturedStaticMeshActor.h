#pragma once
#include "Engine__Actor.h"
#include "Engine__FracturedStaticMeshPart.h"
#include "Engine__MaterialInterface.h"
#include "Engine__SoundCue.h"
#include "Engine__Controller.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.FracturedStaticMeshActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.FracturedStaticMeshActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.FracturedStaticMeshActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class FracturedStaticMeshActor : public Actor
	{
	public:
		ADD_OBJECT(MaterialInterface, MI_LoseChunkPreviousMaterial)
		ADD_OBJECT(SoundCue, SingleChunkFractureSound)
		ADD_OBJECT(SoundCue, ExplosionFractureSound)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.PhysEffectInfo' for the property named 'PartImpactEffect'!
		ADD_VAR(::FloatProperty, FractureCullMaxDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FractureCullMinDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ChunkHealthScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bBreakChunksOnActorTouch, 0x2)
		ADD_VAR(::BoolProperty, bHasShownMissingSoundWarning, 0x1)
		ADD_VAR(::IntProperty, MaxPartsToSpawnAtOnce, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'IsFracturedByDamageType'
		// Here lies the not-yet-implemented method 'FractureEffectIsRelevant'
		// Here lies the not-yet-implemented method 'SpawnPart'
		// Here lies the not-yet-implemented method 'SpawnPartMulti'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'ResetHealth'
		// Here lies the not-yet-implemented method 'BreakOffIsolatedIslands'
		// Here lies the not-yet-implemented method 'SpawnDeferredParts'
		// Here lies the not-yet-implemented method 'RemoveDecals'
		// Here lies the not-yet-implemented method 'TakeDamage'
		// Here lies the not-yet-implemented method 'Explode'
		// Here lies the not-yet-implemented method 'BreakOffPartsInRadius'
		// Here lies the not-yet-implemented method 'ResetVisibility'
		// Here lies the not-yet-implemented method 'HideOneFragment'
		// Here lies the not-yet-implemented method 'HideFragmentsToMaximizeMemoryUsage'
		// Here lies the not-yet-implemented method 'SetLoseChunkReplacementMaterial'
		// Here lies the not-yet-implemented method 'NotifyHitByExplosion'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
