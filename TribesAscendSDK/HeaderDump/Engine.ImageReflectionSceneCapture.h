#pragma once
#include "Engine.ImageReflection.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ImageReflectionSceneCapture : public ImageReflection
	{
	public:
		ADD_STRUCT(float, ColorRange, 488)
		ADD_STRUCT(float, DepthRange, 484)
	};
}
#undef ADD_STRUCT
