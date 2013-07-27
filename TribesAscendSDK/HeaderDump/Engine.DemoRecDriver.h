#pragma once
#include "Engine.NetDriver.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class DemoRecDriver : public NetDriver
	{
	public:
		ADD_STRUCT(ScriptString*, DemoSpectatorClass, 444)
		ADD_STRUCT(int, MaxRewindPoints, 580)
		ADD_STRUCT(float, RewindPointInterval, 588)
		ADD_STRUCT(int, NumRecentRewindPoints, 592)
	};
}
#undef ADD_STRUCT
