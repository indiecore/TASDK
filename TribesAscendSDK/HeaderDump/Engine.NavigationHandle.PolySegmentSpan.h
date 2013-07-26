#pragma once
#include "Core.Object.Vector.h"
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty NavigationHandle.PolySegmentSpan." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PolySegmentSpan
	{
	public:
		ADD_STRUCT(::VectorProperty, P2, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, P1, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, Poly, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
