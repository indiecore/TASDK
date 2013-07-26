#pragma once
#include "Core.DistributionFloat.h"
#include "Core.Object.InterpCurveFloat.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.DistributionFloatConstantCurve." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DistributionFloatConstantCurve : public DistributionFloat
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<InterpCurveFloat>, ConstantCurve, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
