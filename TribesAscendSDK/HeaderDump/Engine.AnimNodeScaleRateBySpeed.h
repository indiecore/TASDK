#pragma once
#include "Engine.AnimNodeScalePlayRate.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class AnimNodeScaleRateBySpeed : public AnimNodeScalePlayRate
	{
	public:
		ADD_STRUCT(float, BaseSpeed, 248)
	};
}
#undef ADD_STRUCT
