#pragma once
#include "Engine.ParticleModuleVelocityBase.h"
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleVelocity." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleVelocity : public ParticleModuleVelocityBase
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, StartVelocityRadial, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, StartVelocity, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
