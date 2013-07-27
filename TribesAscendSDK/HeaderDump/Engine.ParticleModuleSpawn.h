#pragma once
#include "Engine.ParticleModuleSpawnBase.h"
#include "Engine.ParticleEmitter.h"
#include "Core.DistributionFloat.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleSpawn : public ParticleModuleSpawnBase
	{
	public:
		ADD_STRUCT(ScriptArray<ParticleEmitter::ParticleBurst>, BurstList, 136)
		ADD_STRUCT(ParticleEmitter::EParticleBurstMethod, ParticleBurstMethod, 132)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, RateScale, 104)
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, Rate, 76)
	};
}
#undef ADD_STRUCT
