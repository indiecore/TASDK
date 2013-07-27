#pragma once
#include "Core.Object.h"
#include "Engine.SpriteComponent.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class DynamicSpriteComponent : public SpriteComponent
	{
	public:
		ADD_STRUCT(int, LoopCount, 576)
		ADD_STRUCT(Object::Vector, LocationOffset, 564)
		ADD_STRUCT(Object::InterpCurveVector2D, AnimatedPosition, 548)
		ADD_STRUCT(Object::InterpCurveLinearColor, AnimatedColor, 532)
		ADD_STRUCT(Object::InterpCurveFloat, AnimatedScale, 516)
	};
}
#undef ADD_STRUCT
