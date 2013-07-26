#pragma once
#include "Core.Object.SparseArray_Mirror.h"
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Object.Set_Mirror." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Object.Set_Mirror." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Set_Mirror
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<SparseArray_Mirror>, Elements, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, Hash, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, InlineHash, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, HashSize, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
