#pragma once
#include "Engine.ParticleModuleColorBase.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleColorByParameter : public ParticleModuleColorBase
	{
	public:
		ADD_STRUCT(Object::Color, DefaultColor, 80)
		ADD_STRUCT(ScriptName, ColorParam, 72)
	};
}
#undef ADD_STRUCT
