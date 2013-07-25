#pragma once
#include "Engine__MaterialExpression.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MaterialExpressionCompound." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionCompound : public MaterialExpression
	{
	public:
		ADD_VAR(::BoolProperty, bExpanded, 0x1)
		ADD_VAR(::StrProperty, Caption, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
