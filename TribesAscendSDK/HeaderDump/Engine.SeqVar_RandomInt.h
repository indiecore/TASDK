#pragma once
#include "Engine.SeqVar_Int.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqVar_RandomInt : public SeqVar_Int
	{
	public:
		ADD_STRUCT(int, Max, 156)
		ADD_STRUCT(int, Min, 152)
	};
}
#undef ADD_STRUCT
