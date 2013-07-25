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
		float GetFSMFractureCullDistanceScale()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FractureManager.GetFSMFractureCullDistanceScale");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetFSMDirectSpawnChanceScale()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FractureManager.GetFSMDirectSpawnChanceScale");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void SpawnChunkDestroyEffect(class ParticleSystem* Effect, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Box'!
void* ChunkBox, Vector ChunkDir, float Scale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FractureManager.SpawnChunkDestroyEffect");
			byte* params = (byte*)malloc(48);
			*(class ParticleSystem**)params = Effect;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Box'!
void**)(params + 4) = ChunkBox;
			*(Vector*)(params + 32) = ChunkDir;
			*(float*)(params + 44) = Scale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetNumFSMPartsScale()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FractureManager.GetNumFSMPartsScale");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetFSMRadialSpawnChanceScale()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FractureManager.GetFSMRadialSpawnChanceScale");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
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
		class FracturedStaticMeshPart* GetFSMPart(class FracturedStaticMeshActor* Parent, Vector SpawnLocation, Rotator SpawnRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FractureManager.GetFSMPart");
			byte* params = (byte*)malloc(32);
			*(class FracturedStaticMeshActor**)params = Parent;
			*(Vector*)(params + 4) = SpawnLocation;
			*(Rotator*)(params + 16) = SpawnRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class FracturedStaticMeshPart**)(params + 28);
			free(params);
			return returnVal;
		}
		class FracturedStaticMeshPart* SpawnPartActor(class FracturedStaticMeshActor* Parent, Vector SpawnLocation, Rotator SpawnRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FractureManager.SpawnPartActor");
			byte* params = (byte*)malloc(32);
			*(class FracturedStaticMeshActor**)params = Parent;
			*(Vector*)(params + 4) = SpawnLocation;
			*(Rotator*)(params + 16) = SpawnRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class FracturedStaticMeshPart**)(params + 28);
			free(params);
			return returnVal;
		}
		void ReturnPartActor(class FracturedStaticMeshPart* Part)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FractureManager.ReturnPartActor");
			byte* params = (byte*)malloc(4);
			*(class FracturedStaticMeshPart**)params = Part;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FractureManager.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
