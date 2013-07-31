#pragma once
#include "Engine.K2NodeBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class AIGatherNodeBase : public K2NodeBase
	{
	public:
		ADD_STRUCT(ScriptString*, NodeName, 96)
		ADD_STRUCT(float, LastUpdateTime, 92)
	};
}
#undef ADD_STRUCT
