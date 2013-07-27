#pragma once
#include "Engine.Controller.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.ParticleSystem.h"
#include "Engine.MaterialInterface.h"
#include "Engine.SoundCue.h"
#include "Engine.FracturedStaticMeshPart.h"
#include "Engine.Pawn.h"
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
	class FracturedStaticMeshActor : public Actor
	{
	public:
		struct DeferredPartToSpawn
		{
		public:
			ADD_BOOL(bExplosion, 32, 0x1)
			ADD_STRUCT(float, RelativeScale, 28)
			ADD_STRUCT(Vector, InitialAngVel, 16)
			ADD_STRUCT(Vector, InitialVel, 4)
			ADD_STRUCT(int, ChunkIndex, 0)
		};
		ADD_STRUCT(ScriptArray<int>, ChunkHealth, 488)
		ADD_STRUCT(ScriptArray<ScriptClass*>, FracturedByDamageType, 504)
		ADD_STRUCT(ScriptArray<class ParticleSystem*>, OverrideFragmentDestroyEffects, 520)
		ADD_STRUCT(ScriptArray<FracturedStaticMeshActor::DeferredPartToSpawn>, DeferredPartsToSpawn, 540)
		ADD_OBJECT(MaterialInterface, MI_LoseChunkPreviousMaterial, 576)
		ADD_OBJECT(SoundCue, SingleChunkFractureSound, 572)
		ADD_OBJECT(SoundCue, ExplosionFractureSound, 568)
		ADD_STRUCT(Actor::PhysEffectInfo, PartImpactEffect, 552)
		ADD_STRUCT(float, FractureCullMaxDistance, 536)
		ADD_STRUCT(float, FractureCullMinDistance, 532)
		ADD_STRUCT(float, ChunkHealthScale, 516)
		ADD_BOOL(bBreakChunksOnActorTouch, 500, 0x2)
		ADD_BOOL(bHasShownMissingSoundWarning, 500, 0x1)
		ADD_STRUCT(int, MaxPartsToSpawnAtOnce, 476)
		bool IsFracturedByDamageType(ScriptClass* dmgType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13388);
			byte params[8] = { NULL };
			*(ScriptClass**)params = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool FractureEffectIsRelevant(bool bForceDedicated, class Pawn* EffectInstigator, byte& bWantPhysChunksAndParticles)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13390);
			byte params[13] = { NULL };
			*(bool*)params = bForceDedicated;
			*(class Pawn**)&params[4] = EffectInstigator;
			params[8] = bWantPhysChunksAndParticles;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			bWantPhysChunksAndParticles = params[8];
			return *(bool*)&params[12];
		}
		class FracturedStaticMeshPart* SpawnPart(int ChunkIndex, Vector InitialVel, Vector InitialAngVel, float RelativeScale, bool bExplosion)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16474);
			byte params[40] = { NULL };
			*(int*)params = ChunkIndex;
			*(Vector*)&params[4] = InitialVel;
			*(Vector*)&params[16] = InitialAngVel;
			*(float*)&params[28] = RelativeScale;
			*(bool*)&params[32] = bExplosion;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class FracturedStaticMeshPart**)&params[36];
		}
		class FracturedStaticMeshPart* SpawnPartMulti(ScriptArray<int> ChunkIndices, Vector InitialVel, Vector InitialAngVel, float RelativeScale, bool bExplosion)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16481);
			byte params[48] = { NULL };
			*(ScriptArray<int>*)params = ChunkIndices;
			*(Vector*)&params[12] = InitialVel;
			*(Vector*)&params[24] = InitialAngVel;
			*(float*)&params[36] = RelativeScale;
			*(bool*)&params[40] = bExplosion;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class FracturedStaticMeshPart**)&params[44];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16489);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetHealth()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16491);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BreakOffIsolatedIslands(ScriptArray<byte>& FragmentVis, ScriptArray<int> IgnoreFrags, Vector ChunkDir, ScriptArray<class FracturedStaticMeshPart*> DisableCollWithPart, bool bWantPhysChunks)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16494);
			byte params[52] = { NULL };
			*(ScriptArray<byte>*)params = FragmentVis;
			*(ScriptArray<int>*)&params[12] = IgnoreFrags;
			*(Vector*)&params[24] = ChunkDir;
			*(ScriptArray<class FracturedStaticMeshPart*>*)&params[36] = DisableCollWithPart;
			*(bool*)&params[48] = bWantPhysChunks;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			FragmentVis = *(ScriptArray<byte>*)params;
		}
		bool SpawnDeferredParts()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16503);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void RemoveDecals(int IndexToRemoveDecalsFrom)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16519);
			byte params[4] = { NULL };
			*(int*)params = IndexToRemoveDecalsFrom;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16521);
			byte params[68] = { NULL };
			*(int*)params = Damage;
			*(class Controller**)&params[4] = EventInstigator;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Explode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16551);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BreakOffPartsInRadius(Vector Origin, float Radius, float RBStrength, bool bWantPhysChunksAndParticles)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16559);
			byte params[24] = { NULL };
			*(Vector*)params = Origin;
			*(float*)&params[12] = Radius;
			*(float*)&params[16] = RBStrength;
			*(bool*)&params[20] = bWantPhysChunksAndParticles;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetVisibility()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16564);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideOneFragment()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16565);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideFragmentsToMaximizeMemoryUsage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16569);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetLoseChunkReplacementMaterial()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16574);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyHitByExplosion(class Controller* InstigatorController, float DamageAmount, ScriptClass* dmgType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16577);
			byte params[12] = { NULL };
			*(class Controller**)params = InstigatorController;
			*(float*)&params[4] = DamageAmount;
			*(ScriptClass**)&params[8] = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
