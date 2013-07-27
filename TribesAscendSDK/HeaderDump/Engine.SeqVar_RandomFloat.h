#pragma once
#include "Engine.SeqVar_Float.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqVar_RandomFloat : public SeqVar_Float
	{
	public:
		ADD_STRUCT(float, Max, 156)
		ADD_STRUCT(float, Min, 152)
	};
}
#undef ADD_STRUCT
