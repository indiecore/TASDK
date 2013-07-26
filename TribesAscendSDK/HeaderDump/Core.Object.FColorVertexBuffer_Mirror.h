#pragma once
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Object.FColorVertexBuffer_Mirror." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Object.FColorVertexBuffer_Mirror." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class FColorVertexBuffer_Mirror
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VfTable, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VertexData, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Data, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Stride, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumVertices, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
