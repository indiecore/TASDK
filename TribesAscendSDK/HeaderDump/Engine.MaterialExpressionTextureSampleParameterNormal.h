#pragma once
#include "Engine.MaterialExpressionTextureSampleParameter.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionTextureSampleParameterNormal : public MaterialExpressionTextureSampleParameter
	{
	public:
		ADD_STRUCT(Object::Pointer, InstanceOverride, 164)
	};
}
#undef ADD_STRUCT
