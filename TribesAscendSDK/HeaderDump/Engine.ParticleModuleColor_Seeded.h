#pragma once
#include "Engine.ParticleModuleColor.h"
#include "Engine.ParticleModule.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleColor_Seeded : public ParticleModuleColor
	{
	public:
		ADD_STRUCT(ParticleModule::ParticleRandomSeedInfo, RandomSeedInfo, 132)
	};
}
#undef ADD_STRUCT
