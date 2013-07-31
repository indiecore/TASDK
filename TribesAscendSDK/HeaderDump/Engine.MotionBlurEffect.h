#pragma once
#include "Engine.PostProcessEffect.h"
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
	class MotionBlurEffect : public PostProcessEffect
	{
	public:
		ADD_STRUCT(float, CameraTranslationThreshold, 116)
		ADD_STRUCT(float, CameraRotationThreshold, 112)
		ADD_BOOL(FullMotionBlur, 108, 0x1)
		ADD_STRUCT(float, MotionBlurAmount, 104)
		ADD_STRUCT(float, MaxVelocity, 100)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
