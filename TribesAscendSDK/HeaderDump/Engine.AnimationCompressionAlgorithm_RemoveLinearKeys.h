#pragma once
#include "Engine.AnimationCompressionAlgorithm.h"
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
	class AnimationCompressionAlgorithm_RemoveLinearKeys : public AnimationCompressionAlgorithm
	{
	public:
		ADD_BOOL(bActuallyFilterLinearKeys, 104, 0x2)
		ADD_BOOL(bRetarget, 104, 0x1)
		ADD_STRUCT(float, ParentKeyScale, 100)
		ADD_STRUCT(float, EffectorDiffSocket, 96)
		ADD_STRUCT(float, MinEffectorDiff, 92)
		ADD_STRUCT(float, MaxEffectorDiff, 88)
		ADD_STRUCT(float, MaxAngleDiff, 84)
		ADD_STRUCT(float, MaxPosDiff, 80)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
