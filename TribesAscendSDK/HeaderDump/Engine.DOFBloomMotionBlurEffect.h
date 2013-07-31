#pragma once
#include "Engine.DOFAndBloomEffect.h"
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
	class DOFBloomMotionBlurEffect : public DOFAndBloomEffect
	{
	public:
		ADD_STRUCT(float, CameraTranslationThreshold, 192)
		ADD_STRUCT(float, CameraRotationThreshold, 188)
		ADD_BOOL(FullMotionBlur, 184, 0x1)
		ADD_STRUCT(float, MotionBlurAmount, 180)
		ADD_STRUCT(float, MaxVelocity, 176)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
