#pragma once
#include "Engine.Texture.h"
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
	class TextureRenderTarget : public Texture
	{
	public:
		ADD_STRUCT(float, TargetGamma, 240)
		ADD_BOOL(bRenderOnce, 236, 0x4)
		ADD_BOOL(bNeedsTwoCopies, 236, 0x2)
		ADD_BOOL(bUpdateImmediate, 236, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
