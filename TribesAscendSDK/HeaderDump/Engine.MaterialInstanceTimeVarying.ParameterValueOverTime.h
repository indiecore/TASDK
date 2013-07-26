#pragma once
#include "Core.Object.Guid.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " MaterialInstanceTimeVarying.ParameterValueOverTime." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty MaterialInstanceTimeVarying.ParameterValueOverTime." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParameterValueOverTime
	{
	public:
		ADD_VAR(::BoolProperty, bOffsetFromEnd, 0x1)
		ADD_VAR(::FloatProperty, OffsetTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bNormalizeTime, 0x1)
		ADD_VAR(::FloatProperty, CycleTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAutoActivate, 0x2)
		ADD_VAR(::BoolProperty, bLoop, 0x1)
		ADD_VAR(::NameProperty, ParameterName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StartTime, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Guid>, ExpressionGUID, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
