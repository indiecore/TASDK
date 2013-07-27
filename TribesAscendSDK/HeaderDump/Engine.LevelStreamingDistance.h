#pragma once
#include "Engine.LevelStreaming.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class LevelStreamingDistance : public LevelStreaming
	{
	public:
		ADD_STRUCT(float, MaxDistance, 164)
		ADD_STRUCT(Object::Vector, Origin, 152)
	};
}
#undef ADD_STRUCT
