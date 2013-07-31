#pragma once
#include "Engine.DOFEffect.h"
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
	class DOFAndBloomEffect : public DOFEffect
	{
	public:
		ADD_BOOL(bEnableDepthOfFieldHQ, 172, 0x4)
		ADD_BOOL(bEnableReferenceDOF, 172, 0x2)
		ADD_BOOL(bEnableSeparateBloom, 172, 0x1)
		ADD_STRUCT(float, BlurBloomKernelSize, 168)
		ADD_STRUCT(float, SceneMultiplier, 164)
		ADD_STRUCT(float, BloomScreenBlendThreshold, 160)
		ADD_STRUCT(Object::Color, BloomTint, 156)
		ADD_STRUCT(float, BloomThreshold, 152)
		ADD_STRUCT(float, BloomScale, 148)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
