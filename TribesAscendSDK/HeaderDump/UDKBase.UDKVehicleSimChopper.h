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
	class UDKVehicleSimChopper : public SVehicleSimBase
	{
	public:
		struct AnglePID
		{
		public:
			ADD_STRUCT(float, PrevError, 16)
			ADD_STRUCT(float, PrevIntegral, 12)
			ADD_STRUCT(float, IGain, 8)
			ADD_STRUCT(float, DGain, 4)
			ADD_STRUCT(float, PGain, 0)
		};
		ADD_STRUCT(float, HardLimitAirSpeedScale, 304)
		ADD_STRUCT(float, StoppedBrakeTorque, 300)
		ADD_STRUCT(Vector, OldVelocity, 288)
		ADD_STRUCT(float, CurrentStabilizationMultiplier, 284)
		ADD_STRUCT(float, StabilizationForceMultiplier, 280)
		ADD_STRUCT(float, AccumulatedTime, 276)
		ADD_STRUCT(Vector, RandTorque, 264)
		ADD_STRUCT(Vector, RandForce, 252)
		ADD_STRUCT(float, PitchViewCorrelation, 248)
		ADD_STRUCT(float, TargetPitch, 244)
		ADD_STRUCT(float, TargetHeading, 240)
		ADD_STRUCT(float, StrafeTurnDamping, 236)
		ADD_BOOL(bStabilizeStops, 232, 0x40)
		ADD_BOOL(bHeadingInitialized, 232, 0x20)
		ADD_BOOL(bStrafeAffectsTurnDamping, 232, 0x10)
		ADD_BOOL(bRecentlyHit, 232, 0x8)
		ADD_BOOL(bShouldCutThrustMaxOnImpact, 232, 0x4)
		ADD_BOOL(bFullThrustOnDirectionChange, 232, 0x2)
		ADD_BOOL(bAllowZThrust, 232, 0x1)
		ADD_STRUCT(float, RandForceInterval, 228)
		ADD_STRUCT(float, MaxRandForce, 224)
		ADD_STRUCT(float, StopThreshold, 220)
		ADD_STRUCT(float, RollDamping, 216)
		ADD_STRUCT(float, RollTorqueMax, 212)
		ADD_STRUCT(float, RollTorqueStrafeFactor, 208)
		ADD_STRUCT(float, RollTorqueTurnFactor, 204)
		ADD_STRUCT(float, PitchDamping, 200)
		ADD_STRUCT(float, PitchTorqueMax, 196)
		ADD_STRUCT(float, PitchTorqueFactor, 192)
		ADD_STRUCT(float, MaxYawRate, 188)
		ADD_STRUCT(float, TurnDamping, 184)
		ADD_STRUCT(float, TurnTorqueMax, 180)
		ADD_STRUCT(float, TurnTorqueFactor, 176)
		ADD_STRUCT(float, UpDamping, 172)
		ADD_STRUCT(float, MaxRiseForce, 168)
		ADD_STRUCT(float, DirectionChangeForce, 164)
		ADD_STRUCT(float, LatDamping, 160)
		ADD_STRUCT(float, MaxStrafeForce, 156)
		ADD_STRUCT(float, LongDamping, 152)
		ADD_STRUCT(float, MaxReverseForce, 148)
		ADD_STRUCT(float, MaxThrustForce, 144)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
