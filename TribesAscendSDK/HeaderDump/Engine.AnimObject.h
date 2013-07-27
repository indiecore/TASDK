#pragma once
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class AnimObject : public Object
	{
	public:
		ADD_STRUCT(ScriptString*, CategoryDesc, 80)
		ADD_STRUCT(int, OutDrawY, 76)
		ADD_STRUCT(int, NodePosY, 72)
		ADD_STRUCT(int, NodePosX, 68)
		ADD_STRUCT(int, DrawHeight, 64)
		ADD_STRUCT(int, DrawWidth, 60)
	};
}
#undef ADD_STRUCT
