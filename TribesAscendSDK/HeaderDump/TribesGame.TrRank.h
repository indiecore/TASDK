#pragma once
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrRank : public Object
	{
	public:
		ADD_STRUCT(int, IconIndex, 64)
		ADD_STRUCT(ScriptString*, FriendlyName, 72)
		ADD_STRUCT(int, Rank, 60)
		ADD_STRUCT(int, RequiredXP, 68)
	};
}
#undef ADD_STRUCT
