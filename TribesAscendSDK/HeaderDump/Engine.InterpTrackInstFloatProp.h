#pragma once
#include "Engine.InterpTrackInstProperty.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class InterpTrackInstFloatProp : public InterpTrackInstProperty
	{
	public:
		ADD_STRUCT(float, ResetFloat, 72)
		ADD_STRUCT(Object::Pointer, FloatProp, 68)
	};
}
#undef ADD_STRUCT
