#pragma once
#include "Engine__MaterialExpression.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MaterialExpressionPanner." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.MaterialExpressionPanner." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionPanner : public MaterialExpression
	{
	public:
		ADD_VAR(::FloatProperty, SpeedY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpeedX, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.MaterialExpression.ExpressionInput' for the property named 'Time'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.MaterialExpression.ExpressionInput' for the property named 'Coordinate'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
