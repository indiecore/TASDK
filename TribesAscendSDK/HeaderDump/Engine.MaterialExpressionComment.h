#pragma once
#include "Engine.MaterialExpression.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MaterialExpressionComment." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionComment : public MaterialExpression
	{
	public:
		ADD_VAR(::StrProperty, Text, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SizeY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SizeX, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PosY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PosX, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
