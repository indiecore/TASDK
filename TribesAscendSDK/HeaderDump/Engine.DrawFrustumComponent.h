#pragma once
#include "Engine.PrimitiveComponent.h"
#include "Engine.Texture.h"
#include "Core.Object.h"
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
	class DrawFrustumComponent : public PrimitiveComponent
	{
	public:
		ADD_OBJECT(Texture, Texture, 508)
		ADD_STRUCT(float, FrustumEndDist, 504)
		ADD_STRUCT(float, FrustumStartDist, 500)
		ADD_STRUCT(float, FrustumAspectRatio, 496)
		ADD_STRUCT(float, FrustumAngle, 492)
		ADD_STRUCT(Object::Color, FrustumColor, 488)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
