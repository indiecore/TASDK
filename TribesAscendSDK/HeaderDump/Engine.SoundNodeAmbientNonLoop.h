#pragma once
#include "Engine.SoundNodeAmbient.h"
#include "Core.DistributionFloat.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SoundNodeAmbientNonLoop : public SoundNodeAmbient
	{
	public:
		ADD_STRUCT(DistributionFloat::RawDistributionFloat, DelayTime, 312)
		ADD_STRUCT(float, DelayMax, 308)
		ADD_STRUCT(float, DelayMin, 304)
	};
}
#undef ADD_STRUCT
