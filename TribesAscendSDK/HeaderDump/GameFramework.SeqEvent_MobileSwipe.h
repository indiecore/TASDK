#pragma once
#include "GameFramework.SeqEvent_MobileRawInput.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_MobileSwipe : public SeqEvent_MobileRawInput
	{
	public:
		ADD_STRUCT(Object::Vector2D, InitialTouch, 280)
		ADD_STRUCT(float, MinDistance, 276)
		ADD_STRUCT(float, Tolerance, 272)
	};
}
#undef ADD_STRUCT
