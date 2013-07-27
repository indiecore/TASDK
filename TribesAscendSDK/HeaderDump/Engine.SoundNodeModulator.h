#pragma once
#include "Engine.SoundNode.h"
#include "Core.DistributionFloat.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SoundNodeModulator : public SoundNode
	{
	public:
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, VolumeModulation, 120)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, PitchModulation, 92)
		ADD_STRUCT(float, VolumeMax, 88)
		ADD_STRUCT(float, VolumeMin, 84)
		ADD_STRUCT(float, PitchMax, 80)
		ADD_STRUCT(float, PitchMin, 76)
	};
}
#undef ADD_STRUCT
