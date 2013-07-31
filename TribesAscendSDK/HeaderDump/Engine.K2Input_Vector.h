#pragma once
#include "Engine.K2Input.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class K2Input_Vector : public K2Input
	{
	public:
		ADD_STRUCT(Vector, DefaultVector, 84)
	};
}
#undef ADD_STRUCT
