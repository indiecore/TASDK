#pragma once
#include "Engine.Actor.ActorReference.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Pylon.PolyReference." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Pylon.PolyReference." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PolyReference
	{
	public:
		ADD_VAR(::IntProperty, PolyId, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ActorReference>, OwningPylon, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
