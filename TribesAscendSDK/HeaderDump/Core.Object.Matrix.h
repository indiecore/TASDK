#pragma once
#include "Core.Object.Plane.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Object.Matrix." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Matrix
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Plane>, XPlane, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Plane>, YPlane, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Plane>, ZPlane, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Plane>, WPlane, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
