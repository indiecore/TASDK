#pragma once
#include "Engine.ForcedReachSpec.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class CoverSlipReachSpec : public ForcedReachSpec
	{
	public:
		ADD_STRUCT(byte, SpecDirection, 144)
	};
}
#undef ADD_STRUCT
