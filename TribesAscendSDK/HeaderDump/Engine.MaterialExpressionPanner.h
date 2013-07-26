#pragma once
#include "Engine.MaterialExpression.h"
#include "Engine.MaterialExpression.ExpressionInput.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MaterialExpressionPanner." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.MaterialExpressionPanner." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionPanner : public MaterialExpression
	{
	public:
		ADD_VAR(::FloatProperty, SpeedY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpeedX, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ExpressionInput>, Time, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ExpressionInput>, Coordinate, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
