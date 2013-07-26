#pragma once
#include "Core.Object.Vector.h"
#include "Core.Object.Quat.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Actor.RigidBodyState." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Actor.RigidBodyState." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RigidBodyState
	{
	public:
		ADD_VAR(::ByteProperty, bNewData, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, AngVel, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LinVel, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Quat>, Quaternion, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Position, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
