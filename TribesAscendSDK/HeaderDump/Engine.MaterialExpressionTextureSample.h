#pragma once
#include "Engine.MaterialExpression.h"
#include "Engine.Texture.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class MaterialExpressionTextureSample : public MaterialExpression
	{
	public:
		ADD_STRUCT(MaterialExpression::ExpressionInput, Coordinates, 112)
		ADD_OBJECT(Texture, Texture, 108)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
