#pragma once
#include "Engine.SoundNode.h"
#include "Core.DistributionFloat.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SoundNodeDelay : public SoundNode
	{
	public:
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, DelayDuration, 84)
		ADD_STRUCT(float, DelayMax, 80)
		ADD_STRUCT(float, DelayMin, 76)
	};
}
#undef ADD_STRUCT
