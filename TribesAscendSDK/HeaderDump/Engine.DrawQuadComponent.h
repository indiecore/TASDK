#pragma once
#include "Engine.PrimitiveComponent.h"
#include "Engine.Texture.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class DrawQuadComponent : public PrimitiveComponent
	{
	public:
		ADD_STRUCT(float, Height, 496)
		ADD_STRUCT(float, Width, 492)
		ADD_OBJECT(Texture, Texture, 488)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
