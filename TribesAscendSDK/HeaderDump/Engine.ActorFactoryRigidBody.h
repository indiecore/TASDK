#pragma once
#include "Engine.ActorFactoryDynamicSM.h"
#include "Engine.PrimitiveComponent.h"
#include "Core.Object.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ActorFactoryRigidBody : public ActorFactoryDynamicSM
	{
	public:
		ADD_STRUCT(float, StayUprightMaxTorque, 148)
		ADD_STRUCT(float, StayUprightTorqueFactor, 144)
		ADD_STRUCT(PrimitiveComponent::ERBCollisionChannel, RBChannel, 140)
		ADD_STRUCT(Object::Vector, InitialVelocity, 120)
		ADD_BOOL(bEnableStayUprightSpring, 116, 0x8)
		ADD_BOOL(bLocalSpaceInitialVelocity, 116, 0x4)
		ADD_BOOL(bDamageAppliesImpulse, 116, 0x2)
		ADD_BOOL(bStartAwake, 116, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
