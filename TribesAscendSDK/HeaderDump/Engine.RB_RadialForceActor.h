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
	class RB_RadialForceActor : public RigidBodyBase
	{
	public:
		enum ERadialForceType : byte
		{
			RFT_Force = 0,
			RFT_Impulse = 1,
			RFT_MAX = 2,
		};
		ADD_BOOL(bForceActive, 500, 0x1)
		ADD_STRUCT(PrimitiveComponent::RBCollisionChannelContainer, CollideWithChannels, 504)
		ADD_BOOL(bForceApplyToProjectiles, 500, 0x10)
		ADD_BOOL(bForceApplyToRigidBodies, 500, 0x8)
		ADD_BOOL(bForceApplyToFluid, 500, 0x4)
		ADD_BOOL(bForceApplyToCloth, 500, 0x2)
		ADD_STRUCT(RB_RadialForceActor::ERadialForceType, RadialForceMode, 497)
		ADD_STRUCT(PrimitiveComponent::ERadialImpulseFalloff, ForceFalloff, 496)
		ADD_STRUCT(float, SpinTorque, 492)
		ADD_STRUCT(float, SwirlStrength, 488)
		ADD_STRUCT(float, ForceRadius, 484)
		ADD_STRUCT(float, ForceStrength, 480)
		void OnToggle(class SeqAct_Toggle* inAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25308);
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
