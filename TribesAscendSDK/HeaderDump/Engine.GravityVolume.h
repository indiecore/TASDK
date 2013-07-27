#pragma once
#include "Engine.PhysicsVolume.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class GravityVolume : public PhysicsVolume
	{
	public:
		ADD_STRUCT(float, GravityZ, 584)
	};
}
#undef ADD_STRUCT
