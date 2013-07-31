#pragma once
#include "Core.Object.h"
#include "Engine.MaterialExpressionFontSample.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionFontSampleParameter : public MaterialExpressionFontSample
	{
	public:
		ADD_STRUCT(Object::Guid, ExpressionGUID, 124)
		ADD_STRUCT(ScriptName, ParameterName, 116)
	};
}
#undef ADD_STRUCT
