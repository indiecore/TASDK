#pragma once
#include "Engine.MaterialExpression.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionDepthBiasedAlpha : public MaterialExpression
	{
	public:
		ADD_STRUCT(MaterialExpression::ExpressionInput, Bias, 144)
		ADD_STRUCT(MaterialExpression::ExpressionInput, Alpha, 116)
		ADD_STRUCT(float, BiasScale, 112)
		ADD_BOOL(bNormalize, 108, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
