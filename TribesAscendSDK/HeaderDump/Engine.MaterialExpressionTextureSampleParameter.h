#pragma once
#include "Engine.MaterialExpressionTextureSample.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionTextureSampleParameter : public MaterialExpressionTextureSample
	{
	public:
		ADD_STRUCT(Object::Guid, ExpressionGUID, 148)
		ADD_STRUCT(ScriptName, ParameterName, 140)
	};
}
#undef ADD_STRUCT
