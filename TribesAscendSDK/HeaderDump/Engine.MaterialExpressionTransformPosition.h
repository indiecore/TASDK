#pragma once
#include "Engine.MaterialExpression.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionTransformPosition : public MaterialExpression
	{
	public:
		enum EMaterialPositionTransform : byte
		{
			TRANSFORMPOS_World = 0,
			TRANSFORMPOS_MAX = 1,
		};
		ADD_STRUCT(MaterialExpressionTransformPosition::EMaterialPositionTransform, TransformType, 136)
		ADD_STRUCT(MaterialExpression::ExpressionInput, Input, 108)
	};
}
#undef ADD_STRUCT
