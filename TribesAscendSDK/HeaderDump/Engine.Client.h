#pragma once
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class Client : public Object
	{
	public:
		ADD_STRUCT(float, DisplayGamma, 68)
		ADD_STRUCT(float, MinDesiredFrameRate, 64)
		ADD_STRUCT(float, InitialButtonRepeatDelay, 72)
		ADD_STRUCT(float, ButtonRepeatDelay, 76)
	};
}
#undef ADD_STRUCT
