#pragma once
#include "Core.Object.Vector2D.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Canvas.WrappedStringElement." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Canvas.WrappedStringElement." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class WrappedStringElement
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, LineExtent, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Value, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
