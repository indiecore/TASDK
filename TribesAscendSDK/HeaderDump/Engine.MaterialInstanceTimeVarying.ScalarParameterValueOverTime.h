#pragma once
#include "Engine.MaterialInstanceTimeVarying.ParameterValueOverTime.h"
#include "Core.Object.InterpCurveFloat.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " MaterialInstanceTimeVarying.ScalarParameterValueOverTime." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty MaterialInstanceTimeVarying.ScalarParameterValueOverTime." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ScalarParameterValueOverTime : public ParameterValueOverTime
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<InterpCurveFloat>, ParameterValueCurve, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ParameterValue, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
