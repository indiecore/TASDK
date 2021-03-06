#pragma once
#include "Engine.ParticleModuleSizeBase.h"
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
	class ParticleModuleSizeScaleByTime : public ParticleModuleSizeBase
	{
	public:
		ADD_BOOL(bEnableZ, 100, 0x4)
		ADD_BOOL(bEnableY, 100, 0x2)
		ADD_BOOL(bEnableX, 100, 0x1)
		ADD_STRUCT(DistributionVector::RawDistributionVector, SizeScaleByTime, 72)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
