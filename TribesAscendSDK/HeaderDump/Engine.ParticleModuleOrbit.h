#pragma once
#include "Engine.ParticleModuleOrbitBase.h"
#include "Engine.ParticleModuleOrbit.OrbitOptions.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleOrbit." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleOrbit." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleOrbit : public ParticleModuleOrbitBase
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<OrbitOptions>, RotationRateOptions, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, RotationRateAmount, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<OrbitOptions>, RotationOptions, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, RotationAmount, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<OrbitOptions>, OffsetOptions, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, OffsetAmount, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ChainMode, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
