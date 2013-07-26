#pragma once
#include "Engine.Actor.RigidBodyState.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SVehicle.VehicleState." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty SVehicle.VehicleState." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class VehicleState
	{
	public:
		ADD_VAR(::IntProperty, ServerView, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bServerHandbrake, 0x1)
		ADD_VAR(::ByteProperty, ServerRise, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ServerSteering, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ServerGas, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ServerBrake, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RigidBodyState>, RBState, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
