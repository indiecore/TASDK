#pragma once
#include "Core.Object.Matrix.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " KMeshProps.KSphylElem." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty KMeshProps.KSphylElem." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class KSphylElem
	{
	public:
		ADD_VAR(::BoolProperty, bPerPolyShape, 0x2)
		ADD_VAR(::BoolProperty, bNoRBCollision, 0x1)
		ADD_VAR(::FloatProperty, Length, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Radius, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Matrix>, TM, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
