#pragma once
#include "Engine.ParticleModuleBeamBase.h"
#include "Core.DistributionVector.h"
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
	class ParticleModuleBeamNoise : public ParticleModuleBeamBase
	{
	public:
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, NoiseScale, 216)
		ADD_STRUCT(float, FrequencyDistance, 212)
		ADD_STRUCT(int, NoiseTessellation, 208)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, NoiseTangentStrength, 180)
		ADD_STRUCT(float, NoiseTension, 176)
		ADD_STRUCT(float, NoiseLockTime, 172)
		ADD_STRUCT(float, NoiseLockRadius, 168)
		ADD_STRUCT(DistributionVector::RawDistributionVector, NoiseSpeed, 140)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, NoiseRangeScale, 112)
		ADD_STRUCT(DistributionVector::RawDistributionVector, NoiseRange, 84)
		ADD_STRUCT(int, Frequency_LowRange, 80)
		ADD_STRUCT(int, Frequency, 76)
		ADD_BOOL(bApplyNoiseScale, 72, 0x80)
		ADD_BOOL(bTargetNoise, 72, 0x40)
		ADD_BOOL(bUseNoiseTangents, 72, 0x20)
		ADD_BOOL(bOscillate, 72, 0x10)
		ADD_BOOL(bNoiseLock, 72, 0x8)
		ADD_BOOL(bSmooth, 72, 0x4)
		ADD_BOOL(bNRScaleEmitterTime, 72, 0x2)
		ADD_BOOL(bLowFreq_Enabled, 72, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
