#pragma once
#include "Engine.PostProcessEffect.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class BlurEffect : public PostProcessEffect
	{
	public:
		ADD_STRUCT(int, BlurKernelSize, 100)
	};
}
#undef ADD_STRUCT
