#pragma once
#include "Core.Object.Box.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty KMeshProps.KConvexElem." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class KConvexElem
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Box>, ElemBox, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
