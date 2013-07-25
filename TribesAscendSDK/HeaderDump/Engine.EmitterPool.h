#pragma once
#include "Engine.Actor.h"
#include "Engine.ParticleSystem.h"
#include "Engine.MaterialInstanceConstant.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.EmitterPool." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class EmitterPool : public Actor
	{
	public:
		ADD_VAR(::IntProperty, IdealMaterialInstanceConstants, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, IdealStaticMeshComponents, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SMC_MIC_CurrentReductionTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SMC_MIC_ReductionTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bLogPoolOverflowList, 0x2)
		ADD_VAR(::BoolProperty, bLogPoolOverflow, 0x1)
		ADD_VAR(::IntProperty, MaxActiveEffects, 0xFFFFFFFF)
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SpawnEmitter(class ParticleSystem* EmitterTemplate, Vector SpawnLocation, Rotator SpawnRotation, class Actor* AttachToActor, bool bInheritScaleFromBase)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.EmitterPool.SpawnEmitter");
			byte* params = (byte*)malloc(40);
			*(class ParticleSystem**)params = EmitterTemplate;
			*(Vector*)(params + 4) = SpawnLocation;
			*(Rotator*)(params + 16) = SpawnRotation;
			*(class Actor**)(params + 28) = AttachToActor;
			*(bool*)(params + 32) = bInheritScaleFromBase;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 36);
			free(params);
			return returnVal;
		}
		void OnParticleSystemFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.EmitterPool.OnParticleSystemFinished");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReturnToPool(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.EmitterPool.ReturnToPool");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearPoolComponents(bool bClearActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.EmitterPool.ClearPoolComponents");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bClearActive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FreeStaticMeshComponents(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.EmitterPool.FreeStaticMeshComponents");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* GetFreeStaticMeshComponent(bool bCreateNewObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.EmitterPool.GetFreeStaticMeshComponent");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bCreateNewObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4);
			free(params);
			return returnVal;
		}
		void FreeMaterialInstanceConstants(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SMC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.EmitterPool.FreeMaterialInstanceConstants");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SMC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class MaterialInstanceConstant* GetFreeMatInstConsts(bool bCreateNewObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.EmitterPool.GetFreeMatInstConsts");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bCreateNewObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class MaterialInstanceConstant**)(params + 4);
			free(params);
			return returnVal;
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* GetPooledComponent(class ParticleSystem* EmitterTemplate, bool bAutoActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.EmitterPool.GetPooledComponent");
			byte* params = (byte*)malloc(12);
			*(class ParticleSystem**)params = EmitterTemplate;
			*(bool*)(params + 4) = bAutoActivate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 8);
			free(params);
			return returnVal;
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SpawnEmitterMeshAttachment(class ParticleSystem* EmitterTemplate, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Mesh, ScriptName AttachPointName, bool bAttachToSocket, Vector RelativeLoc, Rotator RelativeRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.EmitterPool.SpawnEmitterMeshAttachment");
			byte* params = (byte*)malloc(48);
			*(class ParticleSystem**)params = EmitterTemplate;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = Mesh;
			*(ScriptName*)(params + 8) = AttachPointName;
			*(bool*)(params + 16) = bAttachToSocket;
			*(Vector*)(params + 20) = RelativeLoc;
			*(Rotator*)(params + 32) = RelativeRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 44);
			free(params);
			return returnVal;
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SpawnEmitterCustomLifetime(class ParticleSystem* EmitterTemplate, bool bSkipAutoActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.EmitterPool.SpawnEmitterCustomLifetime");
			byte* params = (byte*)malloc(12);
			*(class ParticleSystem**)params = EmitterTemplate;
			*(bool*)(params + 4) = bSkipAutoActivate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
