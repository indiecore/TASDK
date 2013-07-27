#pragma once
#include "Core.Object.h"
#include "Engine.AnimSequence.h"
#include "Engine.AnimationCompressionAlgorithm_RemoveLinearKeys.h"
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
	class AnimationCompressionAlgorithm_PerTrackCompression : public AnimationCompressionAlgorithm_RemoveLinearKeys
	{
	public:
		ADD_STRUCT(ScriptArray<AnimSequence::AnimationCompressionFormat>, AllowedRotationFormats, 120)
		ADD_STRUCT(ScriptArray<AnimSequence::AnimationCompressionFormat>, AllowedTranslationFormats, 132)
		ADD_STRUCT(Object::Pointer, PerReductionCachedData, 184)
		ADD_STRUCT(float, PerturbationProbeSize, 180)
		ADD_STRUCT(float, MaxErrorPerTrackRatio, 176)
		ADD_STRUCT(float, TranslationErrorSourceRatio, 172)
		ADD_STRUCT(float, RotationErrorSourceRatio, 168)
		ADD_STRUCT(float, ParentingDivisorExponent, 164)
		ADD_STRUCT(float, ParentingDivisor, 160)
		ADD_STRUCT(int, TrackHeightBias, 156)
		ADD_STRUCT(int, MinKeysForResampling, 152)
		ADD_STRUCT(float, ResampledFramerate, 148)
		ADD_BOOL(bUseAdaptiveError2, 144, 0x8)
		ADD_BOOL(bUseOverrideForEndEffectors, 144, 0x4)
		ADD_BOOL(bUseAdaptiveError, 144, 0x2)
		ADD_BOOL(bResampleAnimation, 144, 0x1)
		ADD_STRUCT(float, MaxAngleDiffBitwise, 116)
		ADD_STRUCT(float, MaxPosDiffBitwise, 112)
		ADD_STRUCT(float, MaxZeroingThreshold, 108)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
