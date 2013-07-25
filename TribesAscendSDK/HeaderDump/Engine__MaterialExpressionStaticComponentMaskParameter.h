#pragma once
#include "Engine__MaterialExpressionParameter.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MaterialExpressionStaticComponentMaskParameter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.MaterialExpressionStaticComponentMaskParameter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionStaticComponentMaskParameter : public MaterialExpressionParameter
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'InstanceOverride'!
		ADD_VAR(::BoolProperty, DefaultA, 0x8)
		ADD_VAR(::BoolProperty, DefaultB, 0x4)
		ADD_VAR(::BoolProperty, DefaultG, 0x2)
		ADD_VAR(::BoolProperty, DefaultR, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Engine.MaterialExpression.ExpressionInput' for the property named 'Input'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
