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
	class AnimationCompressionAlgorithm_Automatic : public AnimationCompressionAlgorithm
	{
	public:
		ADD_BOOL(bRaiseMaxErrorToExisting, 84, 0x40)
		ADD_BOOL(bAutoReplaceIfExistingErrorTooGreat, 84, 0x20)
		ADD_BOOL(bRunCurrentDefaultCompressor, 84, 0x10)
		ADD_BOOL(bTryIntervalKeyRemoval, 84, 0x8)
		ADD_BOOL(bTryLinearKeyRemovalCompression, 84, 0x4)
		ADD_BOOL(bTryPerTrackBitwiseCompression, 84, 0x2)
		ADD_BOOL(bTryFixedBitwiseCompression, 84, 0x1)
		ADD_STRUCT(float, MaxEndEffectorError, 80)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
