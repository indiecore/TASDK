#pragma once
#include "Core.Object.InterpCurveVector.h"
#include "Engine.MaterialInstanceTimeVarying.ParameterValueOverTime.h"
#include "Core.Object.LinearColor.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty MaterialInstanceTimeVarying.VectorParameterValueOverTime." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class VectorParameterValueOverTime : public ParameterValueOverTime
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<InterpCurveVector>, ParameterValueCurve, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, ParameterValue, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
