#pragma once
#include "Engine__ParticleSystem.h"
#include "Engine__Actor.h"
#include "Engine__MaterialInstanceConstant.h"
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
		// Here lies the not-yet-implemented method 'SpawnEmitter'
		// Here lies the not-yet-implemented method 'OnParticleSystemFinished'
		// Here lies the not-yet-implemented method 'ReturnToPool'
		// Here lies the not-yet-implemented method 'ClearPoolComponents'
		// Here lies the not-yet-implemented method 'FreeStaticMeshComponents'
		// Here lies the not-yet-implemented method 'GetFreeStaticMeshComponent'
		// Here lies the not-yet-implemented method 'FreeMaterialInstanceConstants'
		// Here lies the not-yet-implemented method 'GetFreeMatInstConsts'
		// Here lies the not-yet-implemented method 'GetPooledComponent'
		// Here lies the not-yet-implemented method 'SpawnEmitterMeshAttachment'
		// Here lies the not-yet-implemented method 'SpawnEmitterCustomLifetime'
	};
}
#undef ADD_VAR
