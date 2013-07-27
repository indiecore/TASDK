#pragma once
#include "Engine.ParticleModuleLifetimeBase.h"
#include "Core.DistributionFloat.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleLifetime : public ParticleModuleLifetimeBase
	{
	public:
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, Lifetime, 72)
	};
}
#undef ADD_STRUCT
