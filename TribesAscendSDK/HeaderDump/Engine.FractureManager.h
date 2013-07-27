#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.FracturedStaticMeshPart.h"
#include "Engine.FracturedStaticMeshActor.h"
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
namespace UnrealScript
{
	class FractureManager : public Actor
	{
	public:
		static const float FSM_DEFAULTRECYCLETIME;
		ADD_STRUCT(ScriptArray<class FracturedStaticMeshPart*>, PartPool, 496)
		ADD_STRUCT(ScriptArray<int>, FreeParts, 508)
		ADD_STRUCT(ScriptArray<class FracturedStaticMeshActor*>, ActorsWithDeferredPartsToSpawn, 520)
		ADD_STRUCT(float, ExplosionVelScale, 492)
		ADD_STRUCT(float, DestroyMinAngVel, 488)
		ADD_STRUCT(float, DestroyVibrationLevel, 484)
		ADD_BOOL(bEnableSpawnChunkEffectForRadialDamage, 480, 0x2)
		ADD_BOOL(bEnableAntiVibration, 480, 0x1)
		ADD_STRUCT(int, FSMPartPoolSize, 476)
		float GetFSMFractureCullDistanceScale()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FractureManager.GetFSMFractureCullDistanceScale");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		float GetFSMDirectSpawnChanceScale()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FractureManager.GetFSMDirectSpawnChanceScale");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void SpawnChunkDestroyEffect(class ParticleSystem* Effect, Object::Box ChunkBox, Object::Vector ChunkDir, float Scale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FractureManager.SpawnChunkDestroyEffect");
			byte params[48] = { NULL };
			*(class ParticleSystem**)&params[0] = Effect;
			*(Object::Box*)&params[4] = ChunkBox;
			*(Object::Vector*)&params[32] = ChunkDir;
			*(float*)&params[44] = Scale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetNumFSMPartsScale()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FractureManager.GetNumFSMPartsScale");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		float GetFSMRadialSpawnChanceScale()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FractureManager.GetFSMRadialSpawnChanceScale");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FractureManager.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FractureManager.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CleanUpFSMParts()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FractureManager.CleanUpFSMParts");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateFSMParts()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FractureManager.CreateFSMParts");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetPoolVisibility()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FractureManager.ResetPoolVisibility");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class FracturedStaticMeshPart* GetFSMPart(class FracturedStaticMeshActor* Parent, Object::Vector SpawnLocation, Object::Rotator SpawnRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FractureManager.GetFSMPart");
			byte params[32] = { NULL };
			*(class FracturedStaticMeshActor**)&params[0] = Parent;
			*(Object::Vector*)&params[4] = SpawnLocation;
			*(Object::Rotator*)&params[16] = SpawnRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class FracturedStaticMeshPart**)&params[28];
		}
		class FracturedStaticMeshPart* SpawnPartActor(class FracturedStaticMeshActor* Parent, Object::Vector SpawnLocation, Object::Rotator SpawnRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FractureManager.SpawnPartActor");
			byte params[32] = { NULL };
			*(class FracturedStaticMeshActor**)&params[0] = Parent;
			*(Object::Vector*)&params[4] = SpawnLocation;
			*(Object::Rotator*)&params[16] = SpawnRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class FracturedStaticMeshPart**)&params[28];
		}
		void ReturnPartActor(class FracturedStaticMeshPart* Part)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FractureManager.ReturnPartActor");
			byte params[4] = { NULL };
			*(class FracturedStaticMeshPart**)&params[0] = Part;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FractureManager.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
	const float FractureManager::FSM_DEFAULTRECYCLETIME = 0.2f;
}
#undef ADD_BOOL
#undef ADD_STRUCT
