#pragma once
#include "Engine.MaterialExpressionParameter.h"
#include "Core.Object.LinearColor.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.MaterialExpressionVectorParameter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionVectorParameter : public MaterialExpressionParameter
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, DefaultValue, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
