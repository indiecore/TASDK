#pragma once
#include "Engine.ParticleModuleLocationPrimitiveCylinder.h"
#include "Engine.ParticleModule.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleLocationPrimitiveCylinder_Seeded : public ParticleModuleLocationPrimitiveCylinder
	{
	public:
		ADD_STRUCT(ParticleModule::ParticleRandomSeedInfo, RandomSeedInfo, 196)
	};
}
#undef ADD_STRUCT
