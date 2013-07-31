#pragma once
#include "Engine.MaterialExpression.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionIf : public MaterialExpression
	{
	public:
		ADD_STRUCT(MaterialExpression::ExpressionInput, ALessThanB, 220)
		ADD_STRUCT(MaterialExpression::ExpressionInput, AEqualsB, 192)
		ADD_STRUCT(MaterialExpression::ExpressionInput, AGreaterThanB, 164)
		ADD_STRUCT(MaterialExpression::ExpressionInput, B, 136)
		ADD_STRUCT(MaterialExpression::ExpressionInput, A, 108)
	};
}
#undef ADD_STRUCT
