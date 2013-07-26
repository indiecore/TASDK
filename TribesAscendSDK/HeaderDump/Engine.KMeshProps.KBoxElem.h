#pragma once
#include "Core.Object.Matrix.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " KMeshProps.KBoxElem." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty KMeshProps.KBoxElem." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class KBoxElem
	{
	public:
		ADD_VAR(::BoolProperty, bPerPolyShape, 0x2)
		ADD_VAR(::BoolProperty, bNoRBCollision, 0x1)
		ADD_VAR(::FloatProperty, Z, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Y, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, X, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Matrix>, TM, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
