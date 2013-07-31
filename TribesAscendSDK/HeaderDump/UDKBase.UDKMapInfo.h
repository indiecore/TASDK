#pragma once
#include "Engine.MapInfo.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKMapInfo : public MapInfo
	{
	public:
		ADD_STRUCT(float, VisibilityModifier, 60)
	};
}
#undef ADD_STRUCT
