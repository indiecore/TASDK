#pragma once
#include "Core.Object.h"
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
	class SoundMode : public Object
	{
	public:
		class SoundClassAdjuster
		{
		public:
			ADD_STRUCT(float, VoiceCenterChannelVolumeAdjuster, 24)
			ADD_BOOL(bApplyToChildren, 20, 0x1)
			ADD_STRUCT(float, PitchAdjuster, 16)
			ADD_STRUCT(float, VolumeAdjuster, 12)
			ADD_STRUCT(ScriptName, SoundClass, 4)
			ADD_STRUCT(AudioDevice::ESoundClassName, SoundClassName, 0)
		};
		class AudioEQEffect
		{
		public:
			ADD_STRUCT(float, LFGain, 32)
			ADD_STRUCT(float, LFFrequency, 28)
			ADD_STRUCT(float, MFGain, 24)
			ADD_STRUCT(float, MFBandwidth, 20)
			ADD_STRUCT(float, MFCutoffFrequency, 16)
			ADD_STRUCT(float, HFGain, 12)
			ADD_STRUCT(float, HFFrequency, 8)
			ADD_STRUCT(Object::Double, RootTime, 0)
		};
		ADD_STRUCT(ScriptArray<SoundMode::SoundClassAdjuster>, SoundClassEffects, 100)
		ADD_STRUCT(float, FadeOutTime, 124)
		ADD_STRUCT(float, Duration, 120)
		ADD_STRUCT(float, FadeInTime, 116)
		ADD_STRUCT(float, InitialDelay, 112)
		ADD_STRUCT(SoundMode::AudioEQEffect, EQSettings, 64)
		ADD_BOOL(bApplyEQ, 60, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
