#pragma once
#include "Core.DistributionFloat.h"
#include "Core.Object.InterpCurveVector2D.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.DistributionFloatUniformCurve." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DistributionFloatUniformCurve : public DistributionFloat
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<InterpCurveVector2D>, ConstantCurve, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
