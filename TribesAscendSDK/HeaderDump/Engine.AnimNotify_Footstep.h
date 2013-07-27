#pragma once
#include "Engine.AnimNotify.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class AnimNotify_Footstep : public AnimNotify
	{
	public:
		ADD_STRUCT(int, FootDown, 64)
	};
}
#undef ADD_STRUCT
