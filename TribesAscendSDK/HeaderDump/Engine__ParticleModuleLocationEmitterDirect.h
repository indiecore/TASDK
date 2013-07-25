#pragma once
#include "Engine__ParticleModuleLocationBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleLocationEmitterDirect." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleLocationEmitterDirect : public ParticleModuleLocationBase
	{
	public:
		ADD_VAR(::NameProperty, EmitterName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
