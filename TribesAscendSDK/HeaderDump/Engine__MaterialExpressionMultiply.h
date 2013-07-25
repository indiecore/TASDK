#pragma once
#include "Engine__MaterialExpression.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.MaterialExpressionMultiply." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionMultiply : public MaterialExpression
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Engine.MaterialExpression.ExpressionInput' for the property named 'B'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.MaterialExpression.ExpressionInput' for the property named 'A'!
	};
}
#undef ADD_STRUCT
