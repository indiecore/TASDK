#pragma once
#include "Core.Object.BitArray_Mirror.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Object.SparseArray_Mirror." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Object.SparseArray_Mirror." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SparseArray_Mirror
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<BitArray_Mirror>, AllocationFlags, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FirstFreeIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumFreeIndices, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
