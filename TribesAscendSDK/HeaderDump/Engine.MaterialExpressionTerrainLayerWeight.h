#pragma once
#include "Engine.MaterialExpression.h"
#include "Core.Object.Guid.h"
#include "Engine.MaterialExpression.ExpressionInput.h"
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MaterialExpressionTerrainLayerWeight." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.MaterialExpressionTerrainLayerWeight." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionTerrainLayerWeight : public MaterialExpression
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Guid>, ExpressionGUID, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PreviewWeight, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ParameterName, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ExpressionInput>, Layer, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ExpressionInput>, Base, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, InstanceOverride, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
