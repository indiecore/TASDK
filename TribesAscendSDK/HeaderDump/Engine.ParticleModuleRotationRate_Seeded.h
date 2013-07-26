#pragma once
#include "Engine.ParticleModuleRotationRate.h"
#include "Engine.ParticleModule.ParticleRandomSeedInfo.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleRotationRate_Seeded." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleRotationRate_Seeded : public ParticleModuleRotationRate
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<ParticleRandomSeedInfo>, RandomSeedInfo, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
