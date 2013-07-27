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
	class MaterialExpressionComponentMask : public MaterialExpression
	{
	public:
		ADD_BOOL(A, 136, 0x8)
		ADD_BOOL(B, 136, 0x4)
		ADD_BOOL(G, 136, 0x2)
		ADD_BOOL(R, 136, 0x1)
		ADD_STRUCT(MaterialExpression::ExpressionInput, Input, 108)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
