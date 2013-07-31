#pragma once
#include "Engine.SkelControlSingleBone.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKSkelControl_VehicleFlap : public SkelControlSingleBone
	{
	public:
		ADD_STRUCT(ScriptName, LeftFlapControl, 260)
		ADD_STRUCT(ScriptName, RightFlapControl, 252)
		ADD_STRUCT(float, MaxPitchChange, 248)
		ADD_STRUCT(float, MaxPitchTime, 244)
		ADD_STRUCT(float, OldZPitch, 240)
		ADD_STRUCT(float, maxPitch, 236)
	};
}
#undef ADD_STRUCT
