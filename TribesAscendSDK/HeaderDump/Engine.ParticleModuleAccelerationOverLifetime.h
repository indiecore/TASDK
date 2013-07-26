#pragma once
#include "Engine.ParticleModuleAccelerationBase.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleAccelerationOverLifetime." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleAccelerationOverLifetime : public ParticleModuleAccelerationBase
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, AccelOverLife, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
