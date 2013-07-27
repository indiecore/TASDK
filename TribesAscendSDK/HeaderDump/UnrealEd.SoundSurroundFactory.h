#pragma once
#include "Core.Factory.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SoundSurroundFactory : public Factory
	{
	public:
		ADD_STRUCT(float, CueVolume, 112)
	};
}
#undef ADD_STRUCT
