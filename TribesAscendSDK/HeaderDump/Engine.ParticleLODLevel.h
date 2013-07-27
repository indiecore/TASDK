#pragma once
#include "Engine.ParticleModuleRequired.h"
#include "Engine.ParticleModuleEventReceiverBase.h"
#include "Core.Object.h"
#include "Engine.ParticleModule.h"
#include "Engine.ParticleModuleSpawn.h"
#include "Engine.ParticleModuleSpawnBase.h"
#include "Engine.ParticleModuleEventGenerator.h"
#include "Engine.ParticleModuleOrbit.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class ParticleLODLevel : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<class ParticleModule*>, Modules, 72)
		ADD_STRUCT(ScriptArray<class ParticleModuleSpawnBase*>, SpawningModules, 96)
		ADD_STRUCT(ScriptArray<class ParticleModule*>, SpawnModules, 108)
		ADD_STRUCT(ScriptArray<class ParticleModule*>, UpdateModules, 120)
		ADD_STRUCT(ScriptArray<class ParticleModuleOrbit*>, OrbitModules, 132)
		ADD_STRUCT(ScriptArray<class ParticleModuleEventReceiverBase*>, EventReceiverModules, 144)
		ADD_STRUCT(int, PeakActiveParticles, 156)
		ADD_OBJECT(ParticleModuleEventGenerator, EventGenerator, 92)
		ADD_OBJECT(ParticleModuleSpawn, SpawnModule, 88)
		ADD_OBJECT(ParticleModule, TypeDataModule, 84)
		ADD_OBJECT(ParticleModuleRequired, RequiredModule, 68)
		ADD_BOOL(ConvertedModules, 64, 0x2)
		ADD_BOOL(bEnabled, 64, 0x1)
		ADD_STRUCT(int, Level, 60)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
