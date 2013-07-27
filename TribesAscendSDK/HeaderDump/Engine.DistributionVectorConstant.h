#pragma once
#include "Core.DistributionVector.h"
#include "Core.Object.h"
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
	class DistributionVectorConstant : public DistributionVector
	{
	public:
		ADD_STRUCT(DistributionVector::EDistributionVectorLockFlags, LockedAxes, 96)
		ADD_BOOL(bLockAxes, 92, 0x1)
		ADD_STRUCT(Object::Vector, Constant, 80)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
