#pragma once
#include "Engine.MaterialExpressionParameter.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionVectorParameter : public MaterialExpressionParameter
	{
	public:
		ADD_STRUCT(Object::LinearColor, DefaultValue, 132)
	};
}
#undef ADD_STRUCT
