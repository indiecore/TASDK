#pragma once
#include "Engine.MaterialExpression.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Material.MaterialInput." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Material.MaterialInput." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MaterialInput
	{
	public:
		ADD_VAR(::IntProperty, GCC64_Padding, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaskA, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaskB, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaskG, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaskR, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Mask, 0xFFFFFFFF)
		ADD_OBJECT(MaterialExpression, Expression)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
