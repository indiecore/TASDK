#pragma once
#include "GameFramework.SeqEvent_MobileZoneBase.h"
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
namespace UnrealScript
{
	class SeqEvent_MobileButton : public SeqEvent_MobileZoneBase
	{
	public:
		ADD_BOOL(bSendPressedOnlyOnTouchUp, 268, 0x4)
		ADD_BOOL(bSendPressedOnlyOnTouchDown, 268, 0x2)
		ADD_BOOL(bWasActiveLastFrame, 268, 0x1)
	};
}
#undef ADD_BOOL
