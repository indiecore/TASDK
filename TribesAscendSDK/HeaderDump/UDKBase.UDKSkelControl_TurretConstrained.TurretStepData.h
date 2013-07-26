#pragma once
#include "UDKBase.UDKSkelControl_TurretConstrained.TurretConstraintData.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKSkelControl_TurretConstrained.TurretStepData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKSkelControl_TurretConstrained.TurretStepData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TurretStepData
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<TurretConstraintData>, MinAngle, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TurretConstraintData>, MaxAngle, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StepEndAngle, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StepStartAngle, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
