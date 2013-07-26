#pragma once
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Object.OctreeElementId." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Object.OctreeElementId." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OctreeElementId
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, Node, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ElementIndex, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
