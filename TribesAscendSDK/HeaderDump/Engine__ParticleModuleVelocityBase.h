#pragma once
#include "Engine__ParticleModule.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleVelocityBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleVelocityBase : public ParticleModule
	{
	public:
		ADD_VAR(::BoolProperty, bApplyOwnerScale, 0x2)
		ADD_VAR(::BoolProperty, bInWorldSpace, 0x1)
	};
}
#undef ADD_VAR
