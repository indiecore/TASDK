#pragma once
#include "Engine.TextureRenderTarget.h"
#include "Engine.Texture.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TextureRenderTargetCube : public TextureRenderTarget
	{
	public:
		ADD_STRUCT(Texture::EPixelFormat, Format, 248)
		ADD_STRUCT(int, SizeX, 244)
	};
}
#undef ADD_STRUCT
