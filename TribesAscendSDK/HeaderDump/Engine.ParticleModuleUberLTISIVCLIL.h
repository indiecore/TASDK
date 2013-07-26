#pragma once
#include "Engine.ParticleModuleUberBase.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#include "Core.DistributionFloat.RawDistributionFloat.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleUberLTISIVCLIL." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleUberLTISIVCLIL : public ParticleModuleUberBase
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, StartLocation, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, AlphaOverLife, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, ColorOverLife, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, StartVelocityRadial, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, StartVelocity, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, StartSize, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, Lifetime, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
