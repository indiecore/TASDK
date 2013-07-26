#pragma once
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Object.BitArray_Mirror." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Object.BitArray_Mirror." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class BitArray_Mirror
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, IndirectData, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, InlineData, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumBits, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxBits, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
