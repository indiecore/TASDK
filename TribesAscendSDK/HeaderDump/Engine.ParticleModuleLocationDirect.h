#pragma once
#include "Engine.ParticleModuleLocationBase.h"
#include "Core.DistributionVector.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleLocationDirect : public ParticleModuleLocationBase
	{
	public:
		ADD_STRUCT(DistributionVector::RawDistributionVector, Direction, 156)
		ADD_STRUCT(DistributionVector::RawDistributionVector, ScaleFactor, 128)
		ADD_STRUCT(DistributionVector::RawDistributionVector, LocationOffset, 100)
		ADD_STRUCT(DistributionVector::RawDistributionVector, Location, 72)
	};
}
#undef ADD_STRUCT
