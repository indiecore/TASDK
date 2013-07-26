#pragma once
#include "Engine.MaterialExpression.ExpressionInput.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " MaterialExpressionCustom.CustomInput." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty MaterialExpressionCustom.CustomInput." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class CustomInput
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<ExpressionInput>, Input, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, InputName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
