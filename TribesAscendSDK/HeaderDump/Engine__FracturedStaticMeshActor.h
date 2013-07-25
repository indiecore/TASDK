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
		bool IsFracturedByDamageType(ScriptClass* dmgType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshActor.IsFracturedByDamageType");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool FractureEffectIsRelevant(bool bForceDedicated, class Pawn* EffectInstigator, byte& bWantPhysChunksAndParticles)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshActor.FractureEffectIsRelevant");
			byte* params = (byte*)malloc(13);
			*(bool*)params = bForceDedicated;
			*(class Pawn**)(params + 4) = EffectInstigator;
			*(params + 8) = bWantPhysChunksAndParticles;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			bWantPhysChunksAndParticles = *(params + 8);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		class FracturedStaticMeshPart* SpawnPart(int ChunkIndex, Vector InitialVel, Vector InitialAngVel, float RelativeScale, bool bExplosion)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshActor.SpawnPart");
			byte* params = (byte*)malloc(40);
			*(int*)params = ChunkIndex;
			*(Vector*)(params + 4) = InitialVel;
			*(Vector*)(params + 16) = InitialAngVel;
			*(float*)(params + 28) = RelativeScale;
			*(bool*)(params + 32) = bExplosion;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class FracturedStaticMeshPart**)(params + 36);
			free(params);
			return returnVal;
		}
		class FracturedStaticMeshPart* SpawnPartMulti(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* ChunkIndices, Vector InitialVel, Vector InitialAngVel, float RelativeScale, bool bExplosion)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshActor.SpawnPartMulti");
			byte* params = (byte*)malloc(48);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = ChunkIndices;
			*(Vector*)(params + 12) = InitialVel;
			*(Vector*)(params + 24) = InitialAngVel;
			*(float*)(params + 36) = RelativeScale;
			*(bool*)(params + 40) = bExplosion;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class FracturedStaticMeshPart**)(params + 44);
			free(params);
			return returnVal;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshActor.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetHealth()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshActor.ResetHealth");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BreakOffIsolatedIslands(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& FragmentVis, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* IgnoreFrags, Vector ChunkDir, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* DisableCollWithPart, bool bWantPhysChunks)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshActor.BreakOffIsolatedIslands");
			byte* params = (byte*)malloc(52);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = FragmentVis;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12) = IgnoreFrags;
			*(Vector*)(params + 24) = ChunkDir;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 36) = DisableCollWithPart;
			*(bool*)(params + 48) = bWantPhysChunks;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			FragmentVis = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		bool SpawnDeferredParts()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshActor.SpawnDeferredParts");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void RemoveDecals(int IndexToRemoveDecalsFrom)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshActor.RemoveDecals");
			byte* params = (byte*)malloc(4);
			*(int*)params = IndexToRemoveDecalsFrom;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void* HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshActor.TakeDamage");
			byte* params = (byte*)malloc(68);
			*(int*)params = Damage;
			*(class Controller**)(params + 4) = EventInstigator;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = Momentum;
			*(ScriptClass**)(params + 32) = DamageType;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void**)(params + 36) = HitInfo;
			*(class Actor**)(params + 64) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Explode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshActor.Explode");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BreakOffPartsInRadius(Vector Origin, float Radius, float RBStrength, bool bWantPhysChunksAndParticles)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshActor.BreakOffPartsInRadius");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = Origin;
			*(float*)(params + 12) = Radius;
			*(float*)(params + 16) = RBStrength;
			*(bool*)(params + 20) = bWantPhysChunksAndParticles;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResetVisibility()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshActor.ResetVisibility");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideOneFragment()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshActor.HideOneFragment");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideFragmentsToMaximizeMemoryUsage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshActor.HideFragmentsToMaximizeMemoryUsage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetLoseChunkReplacementMaterial()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshActor.SetLoseChunkReplacementMaterial");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyHitByExplosion(class Controller* InstigatorController, float DamageAmount, ScriptClass* dmgType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshActor.NotifyHitByExplosion");
			byte* params = (byte*)malloc(12);
			*(class Controller**)params = InstigatorController;
			*(float*)(params + 4) = DamageAmount;
			*(ScriptClass**)(params + 8) = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
