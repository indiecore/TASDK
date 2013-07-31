#pragma once
#include "Core.Object.h"
#include "Engine.TextureRenderTarget.h"
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
	class TextureRenderTarget2D : public TextureRenderTarget
	{
	public:
		ADD_BOOL(bForceLinearGamma, 272, 0x1)
		ADD_STRUCT(Object::LinearColor, ClearColor, 256)
		ADD_STRUCT(Texture::TextureAddress, AddressY, 254)
		ADD_STRUCT(Texture::TextureAddress, AddressX, 253)
		ADD_STRUCT(Texture::EPixelFormat, Format, 252)
		ADD_STRUCT(int, SizeY, 248)
		ADD_STRUCT(int, SizeX, 244)
		class TextureRenderTarget2D* Create(int InSizeX, int InSizeY, Texture::EPixelFormat InFormat, Object::LinearColor InClearColor, bool bOnlyRenderOnce)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25519);
			byte params[33] = { NULL };
			*(int*)params = InSizeX;
			*(int*)&params[4] = InSizeY;
			*(Texture::EPixelFormat*)&params[8] = InFormat;
			*(Object::LinearColor*)&params[12] = InClearColor;
			*(bool*)&params[28] = bOnlyRenderOnce;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TextureRenderTarget2D**)&params[32];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
