#pragma once
#include "Engine.Light.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class StaticLightCollectionActor : public Light
	{
	public:
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, LightComponents, 484)
		ADD_STRUCT(int, MaxLightComponents, 496)
	};
}
#undef ADD_STRUCT
