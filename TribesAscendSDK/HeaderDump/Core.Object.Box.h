#pragma once
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Object.Box." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Object.Box." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Box
	{
	public:
		ADD_STRUCT(::VectorProperty, Min, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Max, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, IsValid, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
