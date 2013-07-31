#pragma once
#include "Engine.SVehicleSimTank.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrSVehicleSimTank : public SVehicleSimTank
	{
	public:
		ADD_STRUCT(float, m_fVelocityChangeDamping, 248)
		ADD_STRUCT(float, m_fLastDirectionNudgeTime, 244)
	};
}
#undef ADD_STRUCT
