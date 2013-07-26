#pragma once
#include "Core.Object.Pointer.h"
#include "Core.Object.Array_Mirror.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Object.InlinePointerArray_Mirror." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InlinePointerArray_Mirror
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, InlineData, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Array_Mirror>, SecondaryData, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
