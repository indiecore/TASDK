#pragma once
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ClientBeaconAddressResolver : public Object
	{
	public:
		ADD_STRUCT(ScriptName, BeaconName, 64)
		ADD_STRUCT(int, BeaconPort, 60)
	};
}
#undef ADD_STRUCT
