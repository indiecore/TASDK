#pragma once
#include "Engine.MaterialExpression.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionRotator : public MaterialExpression
	{
	public:
		ADD_STRUCT(float, Speed, 172)
		ADD_STRUCT(float, CenterY, 168)
		ADD_STRUCT(float, CenterX, 164)
		ADD_STRUCT(MaterialExpression::ExpressionInput, Time, 136)
		ADD_STRUCT(MaterialExpression::ExpressionInput, Coordinate, 108)
	};
}
#undef ADD_STRUCT
