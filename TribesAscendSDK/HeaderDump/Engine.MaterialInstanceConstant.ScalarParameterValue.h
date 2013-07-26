#pragma once
#include "Core.Object.Guid.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " MaterialInstanceConstant.ScalarParameterValue." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty MaterialInstanceConstant.ScalarParameterValue." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ScalarParameterValue
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Guid>, ExpressionGUID, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ParameterValue, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ParameterName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
