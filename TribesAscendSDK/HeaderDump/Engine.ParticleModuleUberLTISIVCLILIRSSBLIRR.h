#pragma once
#include "Engine.ParticleModuleUberBase.h"
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleUberLTISIVCLILIRSSBLIRR." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleUberLTISIVCLILIRSSBLIRR." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleUberLTISIVCLILIRSSBLIRR : public ParticleModuleUberBase
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, StartRotationRate, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, SizeMultiplyZ, 0x4)
		ADD_VAR(::BoolProperty, SizeMultiplyY, 0x2)
		ADD_VAR(::BoolProperty, SizeMultiplyX, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, SizeLifeMultiplier, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, StartRotation, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, StartLocation, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, AlphaOverLife, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, ColorOverLife, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, StartVelocityRadial, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, StartVelocity, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, StartSize, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, Lifetime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
