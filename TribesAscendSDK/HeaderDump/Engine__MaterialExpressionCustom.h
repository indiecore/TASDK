#pragma once
#include "Engine__MaterialExpression.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MaterialExpressionCustom." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionCustom : public MaterialExpression
	{
	public:
		ADD_VAR(::StrProperty, Description, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, OutputType, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Code, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
