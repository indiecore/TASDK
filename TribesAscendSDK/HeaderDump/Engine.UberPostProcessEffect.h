#pragma once
#include "Engine.DOFBloomMotionBlurEffect.h"
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
	class UberPostProcessEffect : public DOFBloomMotionBlurEffect
	{
	public:
		enum ETonemapperType : byte
		{
			Tonemapper_Off = 0,
			Tonemapper_Filmic = 1,
			Tonemapper_Customizable = 2,
			Tonemapper_MAX = 3,
		};
		ADD_STRUCT(float, SceneHDRTonemapperScale, 300)
		ADD_STRUCT(float, BloomSizeScaleLarge, 296)
		ADD_STRUCT(float, BloomSizeScaleMedium, 292)
		ADD_STRUCT(float, BloomSizeScaleSmall, 288)
		ADD_STRUCT(float, BloomWeightLarge, 284)
		ADD_STRUCT(float, BloomWeightMedium, 280)
		ADD_STRUCT(float, BloomWeightSmall, 276)
		ADD_STRUCT(float, SceneImageGrainScale, 272)
		ADD_BOOL(bEnableHDRTonemapper, 268, 0x2)
		ADD_BOOL(bEnableImageGrain, 268, 0x1)
		ADD_STRUCT(float, MotionBlurSoftEdgeKernelSize, 264)
		ADD_STRUCT(float, TonemapperScale, 260)
		ADD_STRUCT(float, TonemapperToeFactor, 256)
		ADD_STRUCT(float, TonemapperRange, 252)
		ADD_STRUCT(UberPostProcessEffect::ETonemapperType, TonemapperType, 248)
		ADD_STRUCT(Vector, SceneShadows, 196)
		ADD_STRUCT(Vector, SceneColorize, 236)
		ADD_STRUCT(float, SceneDesaturation, 232)
		ADD_STRUCT(Vector, SceneMidTones, 220)
		ADD_STRUCT(Vector, SceneHighLights, 208)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
