#pragma once
#include "Core.DistributionFloat.h"
#include "Engine.ParticleModuleSubUVBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleSubUV : public ParticleModuleSubUVBase
	{
	public:
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, SubImageIndex, 72)
	};
}
#undef ADD_STRUCT
