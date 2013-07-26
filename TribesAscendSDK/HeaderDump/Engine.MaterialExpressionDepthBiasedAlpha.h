#pragma once
#include "Engine.MaterialExpression.h"
#include "Engine.MaterialExpression.ExpressionInput.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MaterialExpressionDepthBiasedAlpha." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.MaterialExpressionDepthBiasedAlpha." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionDepthBiasedAlpha : public MaterialExpression
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<ExpressionInput>, Bias, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ExpressionInput>, Alpha, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BiasScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bNormalize, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
