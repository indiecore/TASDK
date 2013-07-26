#pragma once
#include "Engine.ParticleModuleVelocityBase.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleVelocityInheritParent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleVelocityInheritParent : public ParticleModuleVelocityBase
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, Scale, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
