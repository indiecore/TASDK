#pragma once
#include "Engine.ParticleModuleVelocityBase.h"
#include "Core.DistributionVector.h"
#include "Core.DistributionFloat.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleVelocity : public ParticleModuleVelocityBase
	{
	public:
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, StartVelocityRadial, 104)
		ADD_STRUCT(DistributionVector::RawDistributionVector, StartVelocity, 76)
	};
}
#undef ADD_STRUCT
