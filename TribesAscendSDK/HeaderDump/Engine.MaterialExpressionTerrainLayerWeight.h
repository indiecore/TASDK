#pragma once
#include "Engine.MaterialExpression.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionTerrainLayerWeight : public MaterialExpression
	{
	public:
		ADD_STRUCT(Object::Guid, ExpressionGUID, 180)
		ADD_STRUCT(float, PreviewWeight, 176)
		ADD_STRUCT(ScriptName, ParameterName, 168)
		ADD_STRUCT(MaterialExpression::ExpressionInput, Layer, 140)
		ADD_STRUCT(MaterialExpression::ExpressionInput, Base, 112)
		ADD_STRUCT(Object::Pointer, InstanceOverride, 108)
	};
}
#undef ADD_STRUCT
