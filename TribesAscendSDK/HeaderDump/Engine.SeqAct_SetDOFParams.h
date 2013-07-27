#pragma once
#include "Core.Object.h"
#include "Engine.SeqAct_Latent.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqAct_SetDOFParams : public SeqAct_Latent
	{
	public:
		ADD_STRUCT(Object::Vector, OldFocusPosition, 332)
		ADD_STRUCT(float, OldFocusDistance, 328)
		ADD_STRUCT(float, OldFocusInnerRadius, 324)
		ADD_STRUCT(Object::Color, OldModulateBlurColor, 320)
		ADD_STRUCT(float, OldMaxFarBlurAmount, 316)
		ADD_STRUCT(float, OldMinBlurAmount, 312)
		ADD_STRUCT(float, OldMaxNearBlurAmount, 308)
		ADD_STRUCT(float, OldBlurKernelSize, 304)
		ADD_STRUCT(float, OldFalloffExponent, 300)
		ADD_STRUCT(float, InterpolateElapsed, 296)
		ADD_STRUCT(float, InterpolateSeconds, 292)
		ADD_STRUCT(Object::Vector, FocusPosition, 280)
		ADD_STRUCT(float, FocusDistance, 276)
		ADD_STRUCT(float, FocusInnerRadius, 272)
		ADD_STRUCT(Object::Color, ModulateBlurColor, 268)
		ADD_STRUCT(float, MaxFarBlurAmount, 264)
		ADD_STRUCT(float, MinBlurAmount, 260)
		ADD_STRUCT(float, MaxNearBlurAmount, 256)
		ADD_STRUCT(float, BlurKernelSize, 252)
		ADD_STRUCT(float, FalloffExponent, 248)
	};
}
#undef ADD_STRUCT
