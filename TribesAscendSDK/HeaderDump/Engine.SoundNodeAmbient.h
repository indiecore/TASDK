#pragma once
#include "Engine.SoundNode.h"
#include "Core.DistributionFloat.h"
#include "Engine.SoundNodeWave.h"
#include "Engine.SoundNodeAttenuation.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class SoundNodeAmbient : public SoundNode
	{
	public:
		struct AmbientSoundSlot
		{
		public:
			ADD_STRUCT(float, Weight, 12)
			ADD_STRUCT(float, VolumeScale, 8)
			ADD_STRUCT(float, PitchScale, 4)
			ADD_OBJECT(SoundNodeWave, Wave, 0)
		};
		ADD_STRUCT(ScriptArray<SoundNodeAmbient::AmbientSoundSlot>, SoundSlots, 120)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, VolumeModulation, 276)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, PitchModulation, 248)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, LPFMaxRadius, 220)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, LPFMinRadius, 192)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, MaxRadius, 164)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, MinRadius, 136)
		ADD_OBJECT(SoundNodeWave, Wave, 132)
		ADD_STRUCT(float, VolumeMax, 116)
		ADD_STRUCT(float, VolumeMin, 112)
		ADD_STRUCT(float, PitchMax, 108)
		ADD_STRUCT(float, PitchMin, 104)
		ADD_STRUCT(float, LPFRadiusMax, 100)
		ADD_STRUCT(float, LPFRadiusMin, 96)
		ADD_STRUCT(float, RadiusMax, 92)
		ADD_STRUCT(float, RadiusMin, 88)
		ADD_STRUCT(SoundNodeAttenuation::SoundDistanceModel, DistanceModel, 84)
		ADD_STRUCT(float, dBAttenuationAtMax, 80)
		ADD_BOOL(bAttenuateWithLowPassFilter, 76, 0x8)
		ADD_BOOL(bAttenuateWithLPF, 76, 0x4)
		ADD_BOOL(bSpatialize, 76, 0x2)
		ADD_BOOL(bAttenuate, 76, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
