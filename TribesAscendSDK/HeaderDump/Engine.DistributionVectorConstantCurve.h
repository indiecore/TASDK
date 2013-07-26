#pragma once
#include "Core.DistributionVector.h"
#include "Core.Object.InterpCurveVector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DistributionVectorConstantCurve." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.DistributionVectorConstantCurve." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DistributionVectorConstantCurve : public DistributionVector
	{
	public:
		ADD_VAR(::ByteProperty, LockedAxes, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bLockAxes, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<InterpCurveVector>, ConstantCurve, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
