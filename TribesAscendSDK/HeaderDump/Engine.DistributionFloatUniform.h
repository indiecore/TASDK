#pragma once
#include "Core.DistributionFloat.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class DistributionFloatUniform : public DistributionFloat
	{
	public:
		ADD_STRUCT(float, Max, 84)
		ADD_STRUCT(float, Min, 80)
	};
}
#undef ADD_STRUCT
