#pragma once
#include "Engine.SkelControlLookAt.h"
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
	class UDKSkelControl_LookAt : public SkelControlLookAt
	{
	public:
		ADD_STRUCT(float, RollLimit, 332)
		ADD_STRUCT(float, PitchLimit, 328)
		ADD_STRUCT(float, YawLimit, 324)
		ADD_BOOL(bShowPerAxisLimits, 320, 0x8)
		ADD_BOOL(bLimitRoll, 320, 0x4)
		ADD_BOOL(bLimitPitch, 320, 0x2)
		ADD_BOOL(bLimitYaw, 320, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
