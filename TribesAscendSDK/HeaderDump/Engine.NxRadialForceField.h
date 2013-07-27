#pragma once
#include "Engine.NxForceField.h"
#include "Core.Object.h"
#include "Engine.PrimitiveComponent.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class NxRadialForceField : public NxForceField
	{
	public:
		ADD_STRUCT(Object::Pointer, LinearKernel, 556)
		ADD_STRUCT(PrimitiveComponent::ERadialImpulseFalloff, ForceFalloff, 552)
		ADD_STRUCT(float, ForceRadius, 548)
		ADD_STRUCT(float, ForceStrength, 544)
	};
}
#undef ADD_STRUCT
