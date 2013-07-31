#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.MaterialInstanceConstant.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class EmitterPool : public Actor
	{
	public:
		struct EmitterBaseInfo
		{
		public:
			ADD_BOOL(bInheritBaseScale, 32, 0x1)
			ADD_STRUCT(Rotator, RelativeRotation, 20)
			ADD_STRUCT(Vector, RelativeLocation, 8)
			ADD_OBJECT(Actor, Base, 4)
		};
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, PoolComponents, 480)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, ActiveComponents, 492)
		ADD_STRUCT(ScriptArray<EmitterPool::EmitterBaseInfo>, RelativePSCs, 512)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, FreeSMComponents, 540)
		ADD_STRUCT(ScriptArray<class MaterialInstanceConstant*>, FreeMatInstConsts, 552)
		ADD_STRUCT(int, IdealMaterialInstanceConstants, 536)
		ADD_STRUCT(int, IdealStaticMeshComponents, 532)
		ADD_STRUCT(float, SMC_MIC_CurrentReductionTime, 528)
		ADD_STRUCT(float, SMC_MIC_ReductionTime, 524)
		ADD_BOOL(bLogPoolOverflowList, 508, 0x2)
		ADD_BOOL(bLogPoolOverflow, 508, 0x1)
		ADD_STRUCT(int, MaxActiveEffects, 504)
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SpawnEmitter(class ParticleSystem* EmitterTemplate, Vector SpawnLocation, Rotator SpawnRotation, class Actor* AttachToActor, bool bInheritScaleFromBase)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7298);
			byte params[40] = { NULL };
			*(class ParticleSystem**)params = EmitterTemplate;
			*(Vector*)&params[4] = SpawnLocation;
			*(Rotator*)&params[16] = SpawnRotation;
			*(class Actor**)&params[28] = AttachToActor;
			*(bool*)&params[32] = bInheritScaleFromBase;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[36];
		}
		void OnParticleSystemFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15237);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReturnToPool(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15240);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearPoolComponents(bool bClearActive)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15241);
			byte params[4] = { NULL };
			*(bool*)params = bClearActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FreeStaticMeshComponents(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15244);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* GetFreeStaticMeshComponent(bool bCreateNewObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15246);
			byte params[8] = { NULL };
			*(bool*)params = bCreateNewObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4];
		}
		void FreeMaterialInstanceConstants(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SMC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15249);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SMC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class MaterialInstanceConstant* GetFreeMatInstConsts(bool bCreateNewObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15251);
			byte params[8] = { NULL };
			*(bool*)params = bCreateNewObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MaterialInstanceConstant**)&params[4];
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* GetPooledComponent(class ParticleSystem* EmitterTemplate, bool bAutoActivate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15254);
			byte params[12] = { NULL };
			*(class ParticleSystem**)params = EmitterTemplate;
			*(bool*)&params[4] = bAutoActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[8];
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SpawnEmitterMeshAttachment(class ParticleSystem* EmitterTemplate, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Mesh, ScriptName AttachPointName, bool bAttachToSocket, Vector RelativeLoc, Rotator RelativeRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15265);
			byte params[48] = { NULL };
			*(class ParticleSystem**)params = EmitterTemplate;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = Mesh;
			*(ScriptName*)&params[8] = AttachPointName;
			*(bool*)&params[16] = bAttachToSocket;
			*(Vector*)&params[20] = RelativeLoc;
			*(Rotator*)&params[32] = RelativeRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[44];
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SpawnEmitterCustomLifetime(class ParticleSystem* EmitterTemplate, bool bSkipAutoActivate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15274);
			byte params[12] = { NULL };
			*(class ParticleSystem**)params = EmitterTemplate;
			*(bool*)&params[4] = bSkipAutoActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[8];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
