#pragma once
#include "Engine.SVehicleSimCar.h"
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
	class SVehicleSimTank : public SVehicleSimCar
	{
	public:
		ADD_BOOL(bTurnInPlaceOnSteer, 240, 0x1)
		ADD_STRUCT(float, TurnGripScaleRate, 236)
		ADD_STRUCT(float, TurnMaxGripReduction, 232)
		ADD_STRUCT(float, TurnInPlaceThrottle, 228)
		ADD_STRUCT(float, SteeringLatStiffnessFactor, 224)
		ADD_STRUCT(float, InsideTrackTorqueFactor, 220)
		ADD_STRUCT(float, EngineDamping, 216)
		ADD_STRUCT(float, MaxEngineTorque, 212)
		ADD_STRUCT(float, RightTrackTorque, 208)
		ADD_STRUCT(float, LeftTrackTorque, 204)
		ADD_STRUCT(float, RightTrackVel, 200)
		ADD_STRUCT(float, LeftTrackVel, 196)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
