#pragma once
#include "Engine.ParticleModule.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleOrbitBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleOrbitBase : public ParticleModule
	{
	public:
		ADD_VAR(::BoolProperty, bUseEmitterTime, 0x1)
	};
}
#undef ADD_VAR
