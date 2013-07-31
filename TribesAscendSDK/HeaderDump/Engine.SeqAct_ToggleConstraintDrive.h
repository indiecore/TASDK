#pragma once
#include "Engine.SequenceAction.h"
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
	class SeqAct_ToggleConstraintDrive : public SequenceAction
	{
	public:
		ADD_BOOL(bEnableLinearPositionDrive, 232, 0x4)
		ADD_BOOL(bEnableLinearvelocityDrive, 232, 0x8)
		ADD_BOOL(bEnableAngularPositionDrive, 232, 0x1)
		ADD_BOOL(bEnableAngularVelocityDrive, 232, 0x2)
	};
}
#undef ADD_BOOL
