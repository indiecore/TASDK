#pragma once
#include "Engine.ParticleModuleRotationRateBase.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleMeshRotationRateMultiplyLife." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleMeshRotationRateMultiplyLife : public ParticleModuleRotationRateBase
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, LifeMultiplier, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
