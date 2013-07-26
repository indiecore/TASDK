#pragma once
#include "Engine.ParticleModuleRotationBase.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleMeshRotation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleMeshRotation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleMeshRotation : public ParticleModuleRotationBase
	{
	public:
		ADD_VAR(::BoolProperty, bInheritParent, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, StartRotation, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
