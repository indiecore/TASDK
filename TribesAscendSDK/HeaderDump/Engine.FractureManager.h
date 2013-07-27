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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16517);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float GetFSMDirectSpawnChanceScale()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16549);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void SpawnChunkDestroyEffect(class ParticleSystem* Effect, Object::Box ChunkBox, Vector ChunkDir, float Scale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16637);
			byte params[48] = { NULL };
			*(class ParticleSystem**)params = Effect;
			*(Object::Box*)&params[4] = ChunkBox;
			*(Vector*)&params[32] = ChunkDir;
			*(float*)&params[44] = Scale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetNumFSMPartsScale()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16644);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float GetFSMRadialSpawnChanceScale()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16646);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16648);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16649);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CleanUpFSMParts()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16650);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateFSMParts()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16652);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetPoolVisibility()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16653);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class FracturedStaticMeshPart* GetFSMPart(class FracturedStaticMeshActor* Parent, Vector SpawnLocation, Rotator SpawnRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16654);
			byte params[32] = { NULL };
			*(class FracturedStaticMeshActor**)params = Parent;
			*(Vector*)&params[4] = SpawnLocation;
			*(Rotator*)&params[16] = SpawnRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class FracturedStaticMeshPart**)&params[28];
		}
		class FracturedStaticMeshPart* SpawnPartActor(class FracturedStaticMeshActor* Parent, Vector SpawnLocation, Rotator SpawnRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16659);
			byte params[32] = { NULL };
			*(class FracturedStaticMeshActor**)params = Parent;
			*(Vector*)&params[4] = SpawnLocation;
			*(Rotator*)&params[16] = SpawnRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class FracturedStaticMeshPart**)&params[28];
		}
		void ReturnPartActor(class FracturedStaticMeshPart* Part)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16665);
			byte params[4] = { NULL };
			*(class FracturedStaticMeshPart**)params = Part;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16667);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
	const float FractureManager::FSM_DEFAULTRECYCLETIME = 0.2f;
}
#undef ADD_BOOL
#undef ADD_STRUCT
