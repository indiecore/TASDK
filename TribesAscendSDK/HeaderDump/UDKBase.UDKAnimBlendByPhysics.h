#pragma once
#include "UDKBase.UDKAnimBlendBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKAnimBlendByPhysics : public UDKAnimBlendBase
	{
	public:
		ADD_STRUCT(float, PendingTimeToGo, 356)
		ADD_STRUCT(int, PendingChildIndex, 352)
		ADD_STRUCT(float, LandBlendDelay, 348)
		ADD_STRUCT(int, LastPhysics, 344)
		ADD_STRUCT(int, PhysicsMap, 296)
	};
}
#undef ADD_STRUCT
