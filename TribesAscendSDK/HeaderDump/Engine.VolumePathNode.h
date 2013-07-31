#pragma once
#include "Engine.PathNode.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class VolumePathNode : public PathNode
	{
	public:
		ADD_STRUCT(float, StartingHeight, 696)
		ADD_STRUCT(float, StartingRadius, 692)
	};
}
#undef ADD_STRUCT
