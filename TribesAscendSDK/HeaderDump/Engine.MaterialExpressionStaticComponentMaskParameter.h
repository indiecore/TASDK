#pragma once
#include "Engine.MaterialExpressionParameter.h"
#include "Core.Object.h"
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
	class MaterialExpressionStaticComponentMaskParameter : public MaterialExpressionParameter
	{
	public:
		ADD_STRUCT(Object::Pointer, InstanceOverride, 164)
		ADD_BOOL(DefaultA, 160, 0x8)
		ADD_BOOL(DefaultB, 160, 0x4)
		ADD_BOOL(DefaultG, 160, 0x2)
		ADD_BOOL(DefaultR, 160, 0x1)
		ADD_STRUCT(MaterialExpression::ExpressionInput, Input, 132)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
