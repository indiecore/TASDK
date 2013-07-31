#pragma once
#include "Engine.PrimitiveComponent.h"
#include "Engine.RigidBodyBase.h"
#include "Engine.SeqAct_Toggle.h"
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
	class RB_CylindricalForceActor : public RigidBodyBase
	{
	public:
		ADD_STRUCT(PrimitiveComponent::RBCollisionChannelContainer, CollideWithChannels, 520)
		ADD_BOOL(bForceApplyToProjectiles, 516, 0x10)
		ADD_BOOL(bForceApplyToRigidBodies, 516, 0x8)
		ADD_BOOL(bForceApplyToFluid, 516, 0x4)
		ADD_BOOL(bForceApplyToCloth, 516, 0x2)
		ADD_BOOL(bForceActive, 516, 0x1)
		ADD_STRUCT(float, HeightOffset, 512)
		ADD_STRUCT(float, ForceHeight, 508)
		ADD_STRUCT(float, ForceTopRadius, 504)
		ADD_STRUCT(float, ForceRadius, 500)
		ADD_STRUCT(float, EscapeVelocity, 496)
		ADD_STRUCT(float, LiftFalloffHeight, 492)
		ADD_STRUCT(float, LiftStrength, 488)
		ADD_STRUCT(float, RotationalStrength, 484)
		ADD_STRUCT(float, RadialStrength, 480)
		void OnToggle(class SeqAct_Toggle* inAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25229);
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
