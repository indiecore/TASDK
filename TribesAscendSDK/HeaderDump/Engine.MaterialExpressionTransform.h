#pragma once
#include "Engine.MaterialExpression.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionTransform : public MaterialExpression
	{
	public:
		enum EMaterialVectorCoordTransform : byte
		{
			TRANSFORM_World = 0,
			TRANSFORM_View = 1,
			TRANSFORM_Local = 2,
			TRANSFORM_Tangent = 3,
			TRANSFORM_MAX = 4,
		};
		enum EMaterialVectorCoordTransformSource : byte
		{
			TRANSFORMSOURCE_World = 0,
			TRANSFORMSOURCE_Local = 1,
			TRANSFORMSOURCE_Tangent = 2,
			TRANSFORMSOURCE_MAX = 3,
		};
		ADD_STRUCT(MaterialExpressionTransform::EMaterialVectorCoordTransform, TransformType, 137)
		ADD_STRUCT(MaterialExpressionTransform::EMaterialVectorCoordTransformSource, TransformSourceType, 136)
		ADD_STRUCT(MaterialExpression::ExpressionInput, Input, 108)
	};
}
#undef ADD_STRUCT
