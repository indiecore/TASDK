#pragma once
#include "UDKBase.UDKVehicleSimChopper.h"
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
	class UDKVehicleSimHover : public UDKVehicleSimChopper
	{
	public:
		ADD_BOOL(bUnPoweredDriving, 308, 0x8)
		ADD_BOOL(bCanClimbSlopes, 308, 0x4)
		ADD_BOOL(bRepulsorCollisionEnabled, 308, 0x2)
		ADD_BOOL(bDisableWheelsWhenOff, 308, 0x1)
	};
}
#undef ADD_BOOL
