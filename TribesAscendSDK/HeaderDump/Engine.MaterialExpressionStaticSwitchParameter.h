#pragma once
#include "Engine.MaterialExpressionParameter.h"
#include "Core.Object.Pointer.h"
#include "Engine.MaterialExpression.ExpressionInput.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MaterialExpressionStaticSwitchParameter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.MaterialExpressionStaticSwitchParameter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionStaticSwitchParameter : public MaterialExpressionParameter
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, InstanceOverride, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ExpressionInput>, B, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ExpressionInput>, A, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, ExtendedCaptionDisplay, 0x2)
		ADD_VAR(::BoolProperty, DefaultValue, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
