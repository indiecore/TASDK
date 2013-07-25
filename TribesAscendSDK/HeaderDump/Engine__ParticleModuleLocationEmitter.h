#pragma once
#include "Engine__ParticleModuleLocationBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleLocationEmitter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleLocationEmitter : public ParticleModuleLocationBase
	{
	public:
		ADD_VAR(::FloatProperty, InheritSourceRotationScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InheritSourceVelocityScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bInheritSourceRotation, 0x2)
		ADD_VAR(::BoolProperty, InheritSourceVelocity, 0x1)
		ADD_VAR(::ByteProperty, SelectionMethod, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, EmitterName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
