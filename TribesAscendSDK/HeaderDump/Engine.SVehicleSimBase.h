#pragma once
#include "Engine.ActorComponent.h"
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
	class SVehicleSimBase : public ActorComponent
	{
	public:
		ADD_STRUCT(float, WheelLatExtremumValue, 120)
		ADD_STRUCT(float, WheelLatExtremumSlip, 116)
		ADD_STRUCT(float, WheelLatAsymptoteSlip, 124)
		ADD_STRUCT(float, WheelLatAsymptoteValue, 128)
		ADD_STRUCT(float, AutoDriveSteer, 140)
		ADD_BOOL(bAutoDrive, 136, 0x4)
		ADD_BOOL(bClampedFrictionModel, 136, 0x2)
		ADD_BOOL(bWheelSpeedOverride, 136, 0x1)
		ADD_STRUCT(float, WheelInertia, 132)
		ADD_STRUCT(float, WheelLongAsymptoteValue, 112)
		ADD_STRUCT(float, WheelLongAsymptoteSlip, 108)
		ADD_STRUCT(float, WheelLongExtremumValue, 104)
		ADD_STRUCT(float, WheelLongExtremumSlip, 100)
		ADD_STRUCT(float, WheelSuspensionBias, 96)
		ADD_STRUCT(float, WheelSuspensionDamping, 92)
		ADD_STRUCT(float, WheelSuspensionStiffness, 88)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
