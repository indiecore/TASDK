#pragma once
#include "GameFramework.SeqEvent_MobileZoneBase.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_MobileLook : public SeqEvent_MobileZoneBase
	{
	public:
		ADD_STRUCT(Vector, RotationVector, 276)
		ADD_STRUCT(float, StickStrength, 272)
		ADD_STRUCT(float, Yaw, 268)
	};
}
#undef ADD_STRUCT
