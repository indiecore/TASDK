#pragma once
#include "Engine__ActorFactoryDynamicSM.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ActorFactoryRigidBody." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ActorFactoryRigidBody." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ActorFactoryRigidBody : public ActorFactoryDynamicSM
	{
	public:
		ADD_VAR(::FloatProperty, StayUprightMaxTorque, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StayUprightTorqueFactor, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, RBChannel, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, InitialVelocity, 0xFFFFFFFF
		ADD_VAR(::BoolProperty, bEnableStayUprightSpring, 0x8)
		ADD_VAR(::BoolProperty, bLocalSpaceInitialVelocity, 0x4)
		ADD_VAR(::BoolProperty, bDamageAppliesImpulse, 0x2)
		ADD_VAR(::BoolProperty, bStartAwake, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
