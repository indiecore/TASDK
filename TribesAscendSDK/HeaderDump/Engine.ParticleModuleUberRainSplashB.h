#pragma once
#include "Engine.ParticleModuleUberBase.h"
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleUberRainSplashB." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleUberRainSplashB." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleUberRainSplashB : public ParticleModuleUberBase
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, StartRotationRate, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, MultiplyZ, 0x4)
		ADD_VAR(::BoolProperty, MultiplyY, 0x2)
		ADD_VAR(::BoolProperty, MultiplyX, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, LifeMultiplier, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, AlphaOverLife, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, ColorOverLife, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, StartSize, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, Lifetime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
