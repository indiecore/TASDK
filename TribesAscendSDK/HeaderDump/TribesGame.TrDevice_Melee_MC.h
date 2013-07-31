#pragma once
#include "TribesGame.TrDevice_Melee.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrDevice_Melee_MC : public TrDevice_Melee
	{
	public:
		ADD_STRUCT(ScriptString*, ContentDeviceClassString, 2192)
	};
}
#undef ADD_STRUCT
