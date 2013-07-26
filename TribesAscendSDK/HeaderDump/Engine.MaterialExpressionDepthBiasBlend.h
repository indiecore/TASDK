#pragma once
#include "Engine.MaterialExpressionTextureSample.h"
#include "Engine.MaterialExpression.ExpressionInput.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MaterialExpressionDepthBiasBlend." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.MaterialExpressionDepthBiasBlend." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionDepthBiasBlend : public MaterialExpressionTextureSample
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<ExpressionInput>, Bias, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BiasScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bNormalize, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
