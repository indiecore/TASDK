#pragma once
#include "Engine.Volume.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class RB_ForceFieldExcludeVolume : public Volume
	{
	public:
		ADD_STRUCT(int, ForceFieldChannel, 520)
	};
}
#undef ADD_STRUCT
