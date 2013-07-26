#pragma once
#include "Engine.MaterialExpression.h"
#include "Engine.MaterialExpression.ExpressionInput.h"
#include "Core.Object.LinearColor.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.MaterialExpressionDesaturation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionDesaturation : public MaterialExpression
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, LuminanceFactors, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ExpressionInput>, Percent, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ExpressionInput>, Input, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
