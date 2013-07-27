#pragma once
#include "Engine.SVehicleSimBase.h"
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
	class SVehicleSimCar : public SVehicleSimBase
	{
	public:
		ADD_STRUCT(float, TimeSinceThrottle, 192)
		ADD_STRUCT(float, ActualSteering, 188)
		ADD_BOOL(bIsDriving, 184, 0x1)
		ADD_STRUCT(float, StopThreshold, 180)
		ADD_STRUCT(float, MaxBrakeTorque, 176)
		ADD_STRUCT(float, EngineBrakeFactor, 172)
		ADD_STRUCT(float, ReverseThrottle, 168)
		ADD_STRUCT(float, SteerSpeed, 164)
		ADD_STRUCT(Object::InterpCurveFloat, MaxSteerAngleCurve, 148)
		ADD_STRUCT(float, ChassisTorqueScale, 144)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
