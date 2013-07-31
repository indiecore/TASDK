#pragma once
#include "Engine.SkelControlSingleBone.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKSkelControl_HoverboardVibration : public SkelControlSingleBone
	{
	public:
		ADD_STRUCT(float, VibInput, 252)
		ADD_STRUCT(float, VibMaxAmplitude, 248)
		ADD_STRUCT(float, VibTurnAmpScale, 244)
		ADD_STRUCT(float, VibSpeedAmpScale, 240)
		ADD_STRUCT(float, VibFrequency, 236)
	};
}
#undef ADD_STRUCT
