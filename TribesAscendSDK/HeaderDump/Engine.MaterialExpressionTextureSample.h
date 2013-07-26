#pragma once
#include "Engine.MaterialExpression.h"
#include "Engine.MaterialExpression.ExpressionInput.h"
#include "Engine.Texture.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.MaterialExpressionTextureSample." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.MaterialExpressionTextureSample." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MaterialExpressionTextureSample : public MaterialExpression
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<ExpressionInput>, Coordinates, 0xFFFFFFFF)
		ADD_OBJECT(Texture, Texture)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
