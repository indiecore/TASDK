#pragma once
#include "Engine.ParticleModuleRotationBase.h"
#include "Core.DistributionFloat.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleRotation : public ParticleModuleRotationBase
	{
	public:
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, StartRotation, 72)
	};
}
#undef ADD_STRUCT
