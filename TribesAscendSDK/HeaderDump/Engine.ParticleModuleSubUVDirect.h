#pragma once
#include "Core.DistributionVector.h"
#include "Engine.ParticleModuleSubUVBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleSubUVDirect : public ParticleModuleSubUVBase
	{
	public:
		ADD_STRUCT(DistributionVector::RawDistributionVector, SubUVSize, 100)
		ADD_STRUCT(DistributionVector::RawDistributionVector, SubUVPosition, 72)
	};
}
#undef ADD_STRUCT
