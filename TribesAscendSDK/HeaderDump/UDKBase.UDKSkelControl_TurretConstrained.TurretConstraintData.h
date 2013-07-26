#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKSkelControl_TurretConstrained.TurretConstraintData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TurretConstraintData
	{
	public:
		ADD_VAR(::IntProperty, RollConstraint, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, YawConstraint, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PitchConstraint, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
