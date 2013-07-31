#pragma once
#include "Engine.PrimitiveComponent.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class DrawConeComponent : public PrimitiveComponent
	{
	public:
		ADD_STRUCT(int, ConeSides, 500)
		ADD_STRUCT(float, ConeAngle, 496)
		ADD_STRUCT(float, ConeRadius, 492)
		ADD_STRUCT(Object::Color, ConeColor, 488)
	};
}
#undef ADD_STRUCT
