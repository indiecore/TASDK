#pragma once
#include "Core.Object.h"
#include "Engine.FogVolumeDensityComponent.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class FogVolumeLinearHalfspaceDensityComponent : public FogVolumeDensityComponent
	{
	public:
		ADD_STRUCT(Object::Plane, HalfspacePlane, 160)
		ADD_STRUCT(float, PlaneDistanceFactor, 148)
	};
}
#undef ADD_STRUCT
