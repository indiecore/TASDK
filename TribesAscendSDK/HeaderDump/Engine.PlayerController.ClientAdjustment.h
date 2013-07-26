#pragma once
#include "Core.Object.Vector.h"
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " PlayerController.ClientAdjustment." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty PlayerController.ClientAdjustment." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty PlayerController.ClientAdjustment." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ClientAdjustment
	{
	public:
		ADD_VAR(::ByteProperty, newPhysics, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, NewLoc, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, NewVel, 0xFFFFFFFF)
		ADD_OBJECT(Actor, NewBase)
		ADD_STRUCT(::VectorProperty, NewFloor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeStamp, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, bAckGoodMove, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
