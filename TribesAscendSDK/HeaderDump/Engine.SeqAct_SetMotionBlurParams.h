#pragma once
#include "Engine.SeqAct_Latent.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqAct_SetMotionBlurParams : public SeqAct_Latent
	{
	public:
		ADD_STRUCT(float, OldMotionBlurAmount, 260)
		ADD_STRUCT(float, InterpolateElapsed, 256)
		ADD_STRUCT(float, InterpolateSeconds, 252)
		ADD_STRUCT(float, MotionBlurAmount, 248)
	};
}
#undef ADD_STRUCT
