#pragma once
#include "Engine.ParticleModuleLifetimeBase.h"
#include "Core.DistributionFloat.RawDistributionFloat.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleLifetime." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleLifetime : public ParticleModuleLifetimeBase
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, Lifetime, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
