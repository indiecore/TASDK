#pragma once
#include "Core.Object.h"
#include "Engine.MaterialInterface.h"
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
	class LightFunction : public Object
	{
	public:
		ADD_STRUCT(float, DisabledBrightness, 76)
		ADD_STRUCT(Object::Vector, Scale, 64)
		ADD_OBJECT(MaterialInterface, SourceMaterial, 60)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
