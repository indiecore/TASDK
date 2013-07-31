#pragma once
#include "Engine.ParticleModule.h"
#include "Engine.ParticleModuleLifetime.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleLifetime_Seeded : public ParticleModuleLifetime
	{
	public:
		ADD_STRUCT(ParticleModule::ParticleRandomSeedInfo, RandomSeedInfo, 100)
	};
}
#undef ADD_STRUCT
