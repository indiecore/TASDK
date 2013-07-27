#pragma once
#include "Engine.SVehicleSimCar.h"
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
	class UDKVehicleSimCar : public SVehicleSimCar
	{
	public:
		ADD_STRUCT(float, InAirUprightMaxTorque, 312)
		ADD_STRUCT(float, InAirUprightTorqueFactor, 308)
		ADD_STRUCT(float, AirControlTurnTorque, 304)
		ADD_STRUCT(float, SpeedBasedTurnDamping, 300)
		ADD_STRUCT(float, ConsoleHardTurnGripFactor, 296)
		ADD_STRUCT(float, FrontalCollisionGripFactor, 292)
		ADD_STRUCT(float, ActualHandbrake, 288)
		ADD_STRUCT(float, HandbrakeSpeed, 284)
		ADD_STRUCT(float, HardTurnMotorTorque, 280)
		ADD_STRUCT(float, MinHardTurnSpeed, 276)
		ADD_STRUCT(float, SteeringReductionMinSpeed, 272)
		ADD_STRUCT(float, SteeringReductionSpeed, 268)
		ADD_STRUCT(int, NumWheelsForFullSteering, 264)
		ADD_STRUCT(float, CurrentSteeringReduction, 260)
		ADD_STRUCT(float, SteeringReductionRampUpRate, 256)
		ADD_STRUCT(float, SteeringReductionFactor, 252)
		ADD_BOOL(bAutoHandbrake, 248, 0x8)
		ADD_BOOL(bDriverlessBraking, 248, 0x4)
		ADD_BOOL(bHasForcedThrottle, 248, 0x2)
		ADD_BOOL(bForceThrottle, 248, 0x1)
		ADD_STRUCT(float, ActualThrottle, 244)
		ADD_STRUCT(float, MaxRPM, 240)
		ADD_STRUCT(float, MinRPM, 236)
		ADD_STRUCT(float, ThrottleSpeed, 232)
		ADD_STRUCT(float, LSDFactor, 228)
		ADD_STRUCT(Object::InterpCurveFloat, EngineRPMCurve, 212)
		ADD_STRUCT(Object::InterpCurveFloat, TorqueVSpeedCurve, 196)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
