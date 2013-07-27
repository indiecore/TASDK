#pragma once
#include "Core.Object.h"
#include "Engine.NxForceFieldComponent.h"
#include "Engine.NxForceFieldGeneric.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class NxForceFieldGenericComponent : public NxForceFieldComponent
	{
	public:
		ADD_STRUCT(Object::Pointer, Kernel, 732)
		ADD_STRUCT(float, TorusRadius, 728)
		ADD_STRUCT(Object::Vector, FalloffQuadratic, 716)
		ADD_STRUCT(Object::Vector, FalloffLinear, 704)
		ADD_STRUCT(Object::Vector, Noise, 692)
		ADD_STRUCT(Object::Vector, VelocityTarget, 680)
		ADD_STRUCT(Object::Vector, VelocityMultiplierZ, 668)
		ADD_STRUCT(Object::Vector, VelocityMultiplierY, 656)
		ADD_STRUCT(Object::Vector, VelocityMultiplierX, 644)
		ADD_STRUCT(Object::Vector, PositionTarget, 632)
		ADD_STRUCT(Object::Vector, PositionMultiplierZ, 620)
		ADD_STRUCT(Object::Vector, PositionMultiplierY, 608)
		ADD_STRUCT(Object::Vector, PositionMultiplierX, 596)
		ADD_STRUCT(Object::Vector, Constant, 584)
		ADD_STRUCT(NxForceFieldGeneric::FFG_ForceFieldCoordinates, Coordinates, 580)
		ADD_STRUCT(float, RoughExtentZ, 576)
		ADD_STRUCT(float, RoughExtentY, 572)
		ADD_STRUCT(float, RoughExtentX, 568)
	};
}
#undef ADD_STRUCT
