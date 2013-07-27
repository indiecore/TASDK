#pragma once
#include "Engine.ParticleModuleUberBase.h"
#include "Core.DistributionVector.h"
#include "Core.DistributionFloat.h"
#include "Engine.ParticleModuleLocationPrimitiveCylinder.h"
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
	class ParticleModuleUberRainImpacts : public ParticleModuleUberBase
	{
	public:
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, AlphaOverLife, 344)
		ADD_STRUCT(DistributionVector::RawDistributionVector, ColorOverLife, 316)
		ADD_STRUCT(ParticleModuleLocationPrimitiveCylinder::CylinderHeightAxis, PC_HeightAxis, 312)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, PC_StartHeight, 284)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, PC_StartRadius, 256)
		ADD_STRUCT(DistributionVector::RawDistributionVector, PC_StartLocation, 228)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, PC_VelocityScale, 200)
		ADD_STRUCT(DistributionVector::RawDistributionVector, LifeMultiplier, 172)
		ADD_BOOL(bRadialVelocity, 168, 0x2000)
		ADD_BOOL(bVelocity, 168, 0x1000)
		ADD_BOOL(bSurfaceOnly, 168, 0x800)
		ADD_BOOL(bNegative_Z, 168, 0x400)
		ADD_BOOL(bNegative_Y, 168, 0x200)
		ADD_BOOL(bNegative_X, 168, 0x100)
		ADD_BOOL(bPositive_Z, 168, 0x80)
		ADD_BOOL(bPositive_Y, 168, 0x40)
		ADD_BOOL(bPositive_X, 168, 0x20)
		ADD_BOOL(bIsUsingCylinder, 168, 0x10)
		ADD_BOOL(MultiplyZ, 168, 0x8)
		ADD_BOOL(MultiplyY, 168, 0x4)
		ADD_BOOL(MultiplyX, 168, 0x2)
		ADD_BOOL(bInheritParent, 168, 0x1)
		ADD_STRUCT(DistributionVector::RawDistributionVector, StartRotation, 140)
		ADD_STRUCT(DistributionVector::RawDistributionVector, StartSize, 112)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, Lifetime, 84)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
