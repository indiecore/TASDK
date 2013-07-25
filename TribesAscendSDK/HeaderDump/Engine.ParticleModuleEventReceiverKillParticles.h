#pragma once
#include "Engine.ParticleModuleEventReceiverBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleEventReceiverKillParticles." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleEventReceiverKillParticles : public ParticleModuleEventReceiverBase
	{
	public:
		ADD_VAR(::BoolProperty, bStopSpawning, 0x1)
	};
}
#undef ADD_VAR
