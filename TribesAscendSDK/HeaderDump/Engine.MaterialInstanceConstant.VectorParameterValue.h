#pragma once
#include "Core.Object.Guid.h"
#include "Core.Object.LinearColor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " MaterialInstanceConstant.VectorParameterValue." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty MaterialInstanceConstant.VectorParameterValue." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class VectorParameterValue
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Guid>, ExpressionGUID, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, ParameterValue, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ParameterName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
