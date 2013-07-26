#pragma once
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Object.IndirectArray_Mirror." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Object.IndirectArray_Mirror." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class IndirectArray_Mirror
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, Data, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ArrayNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ArrayMax, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
