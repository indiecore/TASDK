#pragma once
#include "Engine.ParticleModuleUberBase.h"
#include "Core.DistributionVector.h"
#include "Core.DistributionFloat.h"
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
namespace UnrealScript
{
	class ParticleModuleUberLTISIVCLILIRSSBLIRR : public ParticleModuleUberBase
	{
	public:
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, StartRotationRate, 340)
		ADD_BOOL(SizeMultiplyZ, 336, 0x4)
		ADD_BOOL(SizeMultiplyY, 336, 0x2)
		ADD_BOOL(SizeMultiplyX, 336, 0x1)
		ADD_STRUCT(DistributionVector::RawDistributionVector, SizeLifeMultiplier, 308)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, StartRotation, 280)
		ADD_STRUCT(DistributionVector::RawDistributionVector, StartLocation, 252)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, AlphaOverLife, 224)
		ADD_STRUCT(DistributionVector::RawDistributionVector, ColorOverLife, 196)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, StartVelocityRadial, 168)
		ADD_STRUCT(DistributionVector::RawDistributionVector, StartVelocity, 140)
		ADD_STRUCT(DistributionVector::RawDistributionVector, StartSize, 112)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, Lifetime, 84)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
