#pragma once
#include "Engine.SoundNode.h"
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
	class SoundNodeLooping : public SoundNode
	{
	public:
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, LoopCount, 88)
		ADD_STRUCT(float, LoopCountMax, 84)
		ADD_STRUCT(float, LoopCountMin, 80)
		ADD_BOOL(bLoopIndefinitely, 76, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
