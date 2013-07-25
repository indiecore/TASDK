#pragma once
#include "Engine__MaterialExpression.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MaterialExpressionComponentMask." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.MaterialExpressionComponentMask." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionComponentMask : public MaterialExpression
	{
	public:
		ADD_VAR(::BoolProperty, A, 0x8)
		ADD_VAR(::BoolProperty, B, 0x4)
		ADD_VAR(::BoolProperty, G, 0x2)
		ADD_VAR(::BoolProperty, R, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Engine.MaterialExpression.ExpressionInput' for the property named 'Input'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
