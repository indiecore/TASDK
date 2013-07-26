#pragma once
#include "Core.Object.LinearColor.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GFxObject.ASColorTransform." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ASColorTransform
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, Add, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, Multiply, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
