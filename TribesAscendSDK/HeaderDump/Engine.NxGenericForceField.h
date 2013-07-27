#pragma once
#include "Engine.NxForceField.h"
#include "Core.Object.h"
#include "Engine.NxForceFieldGeneric.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class NxGenericForceField : public NxForceField
	{
	public:
		ADD_STRUCT(Object::Pointer, LinearKernel, 692)
		ADD_STRUCT(float, TorusRadius, 688)
		ADD_STRUCT(Vector, FalloffQuadratic, 676)
		ADD_STRUCT(Vector, FalloffLinear, 664)
		ADD_STRUCT(Vector, Noise, 652)
		ADD_STRUCT(Vector, VelocityTarget, 640)
		ADD_STRUCT(Vector, VelocityMultiplierZ, 628)
		ADD_STRUCT(Vector, VelocityMultiplierY, 616)
		ADD_STRUCT(Vector, VelocityMultiplierX, 604)
		ADD_STRUCT(Vector, PositionTarget, 592)
		ADD_STRUCT(Vector, PositionMultiplierZ, 580)
		ADD_STRUCT(Vector, PositionMultiplierY, 568)
		ADD_STRUCT(Vector, PositionMultiplierX, 556)
		ADD_STRUCT(Vector, Constant, 544)
		ADD_STRUCT(NxForceFieldGeneric::FFG_ForceFieldCoordinates, Coordinates, 540)
	};
}
#undef ADD_STRUCT
