#pragma once
#include "Engine.AnimNodeBlend.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKAnimBlendBySpeed : public AnimNodeBlend
	{
	public:
		ADD_STRUCT(float, MaxSpeed, 264)
		ADD_STRUCT(float, MinSpeed, 260)
	};
}
#undef ADD_STRUCT
