#pragma once
#include "Engine.SkelControlSingleBone.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKSkelControl_SpinControl : public SkelControlSingleBone
	{
	public:
		ADD_STRUCT(Object::Vector, Axis, 240)
		ADD_STRUCT(float, DegreesPerSecond, 236)
	};
}
#undef ADD_STRUCT
