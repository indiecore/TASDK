#pragma once
#include "Engine.ParticleModuleRequired.h"
#include "Core.Object.h"
#include "Engine.ParticleModuleEventGenerator.h"
#include "Engine.ParticleModuleSpawn.h"
#include "Engine.ParticleModule.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleLODLevel." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ParticleLODLevel." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ParticleLODLevel : public Object
	{
	public:
		ADD_VAR(::IntProperty, PeakActiveParticles, 0xFFFFFFFF)
		ADD_OBJECT(ParticleModuleEventGenerator, EventGenerator)
		ADD_OBJECT(ParticleModuleSpawn, SpawnModule)
		ADD_OBJECT(ParticleModule, TypeDataModule)
		ADD_OBJECT(ParticleModuleRequired, RequiredModule)
		ADD_VAR(::BoolProperty, ConvertedModules, 0x2)
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
		ADD_VAR(::IntProperty, Level, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
