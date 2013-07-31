#pragma once
#include "Engine.SoundNode.h"
#include "Core.DistributionFloat.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SoundNodeOscillator : public SoundNode
	{
	public:
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, Center, 196)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, Offset, 168)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, Frequency, 140)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, Amplitude, 112)
		ADD_STRUCT(float, CenterMax, 108)
		ADD_STRUCT(float, CenterMin, 104)
		ADD_STRUCT(float, OffsetMax, 100)
		ADD_STRUCT(float, OffsetMin, 96)
		ADD_STRUCT(float, FrequencyMax, 92)
		ADD_STRUCT(float, FrequencyMin, 88)
		ADD_STRUCT(float, AmplitudeMax, 84)
		ADD_STRUCT(float, AmplitudeMin, 80)
		ADD_BOOL(bModulatePitch, 76, 0x2)
		ADD_BOOL(bModulateVolume, 76, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
