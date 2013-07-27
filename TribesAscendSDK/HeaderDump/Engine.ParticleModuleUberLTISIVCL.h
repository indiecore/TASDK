#pragma once
#include "Engine.ParticleModuleUberBase.h"
#include "Core.DistributionVector.h"
#include "Core.DistributionFloat.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleUberLTISIVCL : public ParticleModuleUberBase
	{
	public:
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, AlphaOverLife, 224)
		ADD_STRUCT(DistributionVector::RawDistributionVector, ColorOverLife, 196)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, StartVelocityRadial, 168)
		ADD_STRUCT(DistributionVector::RawDistributionVector, StartVelocity, 140)
		ADD_STRUCT(DistributionVector::RawDistributionVector, StartSize, 112)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, Lifetime, 84)
	};
}
#undef ADD_STRUCT
