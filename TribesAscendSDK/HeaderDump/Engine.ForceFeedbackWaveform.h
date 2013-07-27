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
	class ForceFeedbackWaveform : public Object
	{
	public:
		enum EWaveformFunction : byte
		{
			WF_Constant = 0,
			WF_LinearIncreasing = 1,
			WF_LinearDecreasing = 2,
			WF_Sin0to90 = 3,
			WF_Sin90to180 = 4,
			WF_Sin0to180 = 5,
			WF_Noise = 6,
			WF_MAX = 7,
		};
		class WaveformSample
		{
		public:
			ADD_STRUCT(float, Duration, 4)
			ADD_STRUCT(ForceFeedbackWaveform::EWaveformFunction, RightFunction, 3)
			ADD_STRUCT(ForceFeedbackWaveform::EWaveformFunction, LeftFunction, 2)
			ADD_STRUCT(byte, RightAmplitude, 1)
			ADD_STRUCT(byte, LeftAmplitude, 0)
		};
		ADD_STRUCT(ScriptArray<ForceFeedbackWaveform::WaveformSample>, Samples, 64)
		ADD_STRUCT(float, MaxWaveformDistance, 80)
		ADD_STRUCT(float, WaveformFalloffStartDistance, 76)
		ADD_BOOL(bIsLooping, 60, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
