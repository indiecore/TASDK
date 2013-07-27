#pragma once
#include "Engine.ParticleModuleTrailBase.h"
#include "Core.DistributionFloat.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleTrailTaper : public ParticleModuleTrailBase
	{
	public:
		enum ETrailTaperMethod : byte
		{
			PETTM_None = 0,
			PETTM_Full = 1,
			PETTM_Partial = 2,
			PETTM_MAX = 3,
		};
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, TaperFactor, 76)
		ADD_STRUCT(ParticleModuleTrailTaper::ETrailTaperMethod, TaperMethod, 72)
	};
}
#undef ADD_STRUCT
