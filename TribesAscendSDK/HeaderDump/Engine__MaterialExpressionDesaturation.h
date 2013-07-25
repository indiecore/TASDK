#pragma once
#include "Engine__MaterialExpression.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.MaterialExpressionDesaturation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionDesaturation : public MaterialExpression
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'LuminanceFactors'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.MaterialExpression.ExpressionInput' for the property named 'Percent'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.MaterialExpression.ExpressionInput' for the property named 'Input'!
	};
}
#undef ADD_STRUCT
