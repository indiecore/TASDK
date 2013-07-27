#pragma once
#include "Core.DistributionFloat.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class DistributionFloatConstant : public DistributionFloat
	{
	public:
		ADD_STRUCT(float, Constant, 80)
	};
}
#undef ADD_STRUCT
