#pragma once
#include "Engine.LevelBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class Level : public LevelBase
	{
	public:
		ADD_STRUCT(float, LightmapTotalSize, 360)
		ADD_STRUCT(float, ShadowmapTotalSize, 364)
	};
}
#undef ADD_STRUCT
