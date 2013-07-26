#pragma once
#include "Engine.ParticleModuleLifetime.h"
#include "Engine.ParticleModule.ParticleRandomSeedInfo.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleLifetime_Seeded." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleLifetime_Seeded : public ParticleModuleLifetime
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<ParticleRandomSeedInfo>, RandomSeedInfo, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
