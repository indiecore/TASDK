#pragma once
#include "Engine.LightComponent.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SkyLightComponent : public LightComponent
	{
	public:
		ADD_STRUCT(Object::Color, LowerColor, 436)
		ADD_STRUCT(float, LowerBrightness, 432)
	};
}
#undef ADD_STRUCT
