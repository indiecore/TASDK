#pragma once
#include "Engine.SkelControlSingleBone.h"
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
	class UDKSkelControl_PropellerBlade : public SkelControlSingleBone
	{
	public:
		ADD_STRUCT(float, DesiredRotationsPerSecond, 252)
		ADD_STRUCT(float, RotationsPerSecond, 248)
		ADD_BOOL(bCounterClockwise, 244, 0x1)
		ADD_STRUCT(float, SpinUpTime, 240)
		ADD_STRUCT(float, MaxRotationsPerSecond, 236)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
