#pragma once
#include "Engine.MaterialExpression.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionConstantClamp : public MaterialExpression
	{
	public:
		ADD_STRUCT(float, Max, 140)
		ADD_STRUCT(float, Min, 136)
		ADD_STRUCT(MaterialExpression::ExpressionInput, Input, 108)
	};
}
#undef ADD_STRUCT
