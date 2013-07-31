#pragma once
#include "Engine.Texture2D.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ShadowMapTexture2D : public Texture2D
	{
	public:
		ADD_STRUCT(int, ShadowmapFlags, 368)
	};
}
#undef ADD_STRUCT
