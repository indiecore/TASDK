#pragma once
#include "Engine.SequenceEvent.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_RigidBodyCollision : public SequenceEvent
	{
	public:
		ADD_STRUCT(float, MinCollisionVelocity, 256)
	};
}
#undef ADD_STRUCT
