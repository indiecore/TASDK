#pragma once
#include "Core.Object.h"
#include "Engine.K2NodeBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class K2GraphBase : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<class K2NodeBase*>, Nodes, 60)
	};
}
#undef ADD_STRUCT
