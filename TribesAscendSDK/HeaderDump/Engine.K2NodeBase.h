#pragma once
#include "Core.Object.h"
#include "Engine.K2Input.h"
#include "Engine.K2Output.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class K2NodeBase : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<class K2Input*>, Inputs, 60)
		ADD_STRUCT(ScriptArray<class K2Output*>, Outputs, 72)
		ADD_STRUCT(int, NodePosY, 88)
		ADD_STRUCT(int, NodePosX, 84)
	};
}
#undef ADD_STRUCT
