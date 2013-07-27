#pragma once
#include "Engine.ActorComponent.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class WindDirectionalSourceComponent : public ActorComponent
	{
	public:
		ADD_STRUCT(float, Speed, 104)
		ADD_STRUCT(float, Frequency, 100)
		ADD_STRUCT(float, Phase, 96)
		ADD_STRUCT(float, Strength, 92)
		ADD_STRUCT(Object::Pointer, SceneProxy, 88)
	};
}
#undef ADD_STRUCT
