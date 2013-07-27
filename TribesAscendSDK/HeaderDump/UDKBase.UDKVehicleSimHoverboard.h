#pragma once
#include "Engine.SVehicleSimBase.h"
#include "Engine.RB_ConstraintInstance.h"
#include "Core.Object.h"
#include "Engine.SoundCue.h"
#include "UDKBase.UDKVehicle.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UDKVehicleSimHoverboard : public SVehicleSimBase
	{
	public:
		ADD_STRUCT(float, CurrentLookYaw, 264)
		ADD_STRUCT(float, SlalomSpeed, 260)
		ADD_STRUCT(float, HoverboardSlalomMaxAngle, 256)
		ADD_STRUCT(float, CurrentSteerOffset, 252)
		ADD_STRUCT(float, LandedCountdown, 248)
		ADD_STRUCT(float, SpinSpeed, 244)
		ADD_STRUCT(float, AutoSpin, 240)
		ADD_STRUCT(float, SpinHeadingOffset, 236)
		ADD_STRUCT(float, TrickJumpWarmup, 232)
		ADD_STRUCT(float, TakeoffYaw, 228)
		ADD_STRUCT(Object::Vector, GroundNormal, 216)
		ADD_OBJECT(SoundCue, OverWaterSound, 212)
		ADD_STRUCT(float, WaterCheckLevel, 208)
		ADD_STRUCT(float, StopThreshold, 204)
		ADD_BOOL(bLeftGround, 200, 0x4)
		ADD_BOOL(bInAJump, 200, 0x2)
		ADD_BOOL(bIsOverDeepWater, 200, 0x1)
		ADD_STRUCT(Object::InterpCurveFloat, TurnDampingSpeedFunc, 184)
		ADD_STRUCT(float, MaxTurnTorque, 180)
		ADD_STRUCT(float, SpinTurnTorqueScale, 176)
		ADD_STRUCT(float, TurnTorqueFactor, 172)
		ADD_STRUCT(float, MaxRiseForce, 168)
		ADD_STRUCT(float, LatDamping, 164)
		ADD_STRUCT(float, MaxStrafeForce, 160)
		ADD_STRUCT(float, LongDamping, 156)
		ADD_STRUCT(float, MaxReverseVelocity, 152)
		ADD_STRUCT(float, MaxReverseForce, 148)
		ADD_STRUCT(float, MaxThrustForce, 144)
		void InitWheels(class UDKVehicle* Vehicle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleSimHoverboard.InitWheels");
			byte params[4] = { NULL };
			*(class UDKVehicle**)&params[0] = Vehicle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateLeanConstraint(class RB_ConstraintInstance* LeanUprightConstraintInstance, Object::Vector LeanY, Object::Vector LeanZ)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleSimHoverboard.UpdateLeanConstraint");
			byte params[28] = { NULL };
			*(class RB_ConstraintInstance**)&params[0] = LeanUprightConstraintInstance;
			*(Object::Vector*)&params[4] = LeanY;
			*(Object::Vector*)&params[16] = LeanZ;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
