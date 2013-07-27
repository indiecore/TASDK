#pragma once
#include "Core.Object.h"
#include "Engine.FogVolumeDensityComponent.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class FogVolumeConeDensityComponent : public FogVolumeDensityComponent
	{
	public:
		ADD_STRUCT(float, ConeMaxAngle, 180)
		ADD_STRUCT(Object::Vector, ConeAxis, 168)
		ADD_STRUCT(float, ConeRadius, 164)
		ADD_STRUCT(Object::Vector, ConeVertex, 152)
		ADD_STRUCT(float, MaxDensity, 148)
	};
}
#undef ADD_STRUCT
