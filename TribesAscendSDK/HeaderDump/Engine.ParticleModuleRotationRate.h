#pragma once
#include "Engine.ParticleModuleRotationRateBase.h"
#include "Core.DistributionFloat.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleRotationRate : public ParticleModuleRotationRateBase
	{
	public:
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, StartRotationRate, 72)
	};
}
#undef ADD_STRUCT
