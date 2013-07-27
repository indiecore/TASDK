#pragma once
#include "Engine.SkelControlWheel.h"
#include "Core.Component.h"
#include "Core.Object.h"
#include "Engine.ParticleSystem.h"
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
	class SVehicleWheel : public Component
	{
	public:
		enum EWheelSide : byte
		{
			SIDE_None = 0,
			SIDE_Left = 1,
			SIDE_Right = 2,
			SIDE_MAX = 3,
		};
		ADD_OBJECT(SkelControlWheel, WheelControl, 104)
		ADD_STRUCT(ScriptName, SkelControlName, 96)
		ADD_STRUCT(Object::Vector, WheelPosition, 168)
		ADD_STRUCT(float, ContactForce, 228)
		ADD_STRUCT(float, LongSlipRatio, 184)
		ADD_STRUCT(float, LatSlipAngle, 188)
		ADD_STRUCT(float, MotorTorque, 76)
		ADD_STRUCT(float, SpinVel, 180)
		ADD_STRUCT(float, LongImpulse, 232)
		ADD_STRUCT(Object::Vector, LongDirection, 204)
		ADD_STRUCT(float, WheelRadius, 128)
		ADD_STRUCT(float, LatImpulse, 236)
		ADD_STRUCT(Object::Vector, LatDirection, 216)
		ADD_STRUCT(ScriptName, SlipParticleParamName, 268)
		ADD_OBJECT(ScriptClass, WheelPSCClass, 260)
		ADD_STRUCT(int, WheelMaterialIndex, 256)
		ADD_STRUCT(Object::Pointer, WheelShape, 252)
		ADD_STRUCT(float, CurrentRotation, 248)
		ADD_STRUCT(float, SuspensionPosition, 244)
		ADD_STRUCT(float, DesiredSuspensionPosition, 240)
		ADD_STRUCT(Object::Vector, ContactNormal, 192)
		ADD_STRUCT(float, ParkedSlipFactor, 164)
		ADD_STRUCT(float, HandbrakeLatSlipFactor, 160)
		ADD_STRUCT(float, HandbrakeLongSlipFactor, 156)
		ADD_STRUCT(float, LatSlipFactor, 152)
		ADD_STRUCT(float, LongSlipFactor, 148)
		ADD_STRUCT(SVehicleWheel::EWheelSide, Side, 144)
		ADD_OBJECT(ParticleSystem, WheelParticleSystem, 140)
		ADD_STRUCT(float, SuspensionSpeed, 136)
		ADD_STRUCT(float, SuspensionTravel, 132)
		ADD_STRUCT(Object::Vector, BoneOffset, 116)
		ADD_STRUCT(ScriptName, BoneName, 108)
		ADD_STRUCT(float, SteerFactor, 92)
		ADD_BOOL(bWheelOnGround, 88, 0x20)
		ADD_BOOL(bIsSquealing, 88, 0x10)
		ADD_BOOL(bCollidesPawns, 88, 0x8)
		ADD_BOOL(bCollidesVehicles, 88, 0x4)
		ADD_BOOL(bHoverWheel, 88, 0x2)
		ADD_BOOL(bPoweredWheel, 88, 0x1)
		ADD_STRUCT(float, ChassisTorque, 84)
		ADD_STRUCT(float, BrakeTorque, 80)
		ADD_STRUCT(float, Steer, 72)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
