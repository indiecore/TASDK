#pragma once
#include "Engine.ParticleModuleLocationBase.h"
#include "Core.DistributionFloat.h"
#include "Core.DistributionVector.h"
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
	class ParticleModuleLocationPrimitiveBase : public ParticleModuleLocationBase
	{
	public:
		ADD_STRUCT(DistributionVector::RawDistributionVector, StartLocation, 104)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, VelocityScale, 76)
		ADD_BOOL(Velocity, 72, 0x80)
		ADD_BOOL(SurfaceOnly, 72, 0x40)
		ADD_BOOL(Negative_Z, 72, 0x20)
		ADD_BOOL(Negative_Y, 72, 0x10)
		ADD_BOOL(Negative_X, 72, 0x8)
		ADD_BOOL(Positive_Z, 72, 0x4)
		ADD_BOOL(Positive_Y, 72, 0x2)
		ADD_BOOL(Positive_X, 72, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
