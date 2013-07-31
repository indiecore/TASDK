#pragma once
#include "Core.Factory.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TextureRenderTargetFactoryNew : public Factory
	{
	public:
		enum Format : byte
		{
			A8R8G8B8 = 0,
			G8 = 1,
			FloatRGB = 2,
			Format_MAX = 3,
		};
		ADD_STRUCT(int, Width, 112)
		ADD_STRUCT(int, Height, 116)
		ADD_STRUCT(TextureRenderTargetFactoryNew::Format, Format, 120)
	};
}
#undef ADD_STRUCT
