#pragma once
#include "Core.DistributionFloat.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class DistributionFloatConstantCurve : public DistributionFloat
	{
	public:
		ADD_STRUCT(Object::InterpCurveFloat, ConstantCurve, 80)
	};
}
#undef ADD_STRUCT
