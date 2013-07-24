#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKSkelControl_LookAt." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKSkelControl_LookAt : public SkelControlLookAt
	{
	public:
		ADD_VAR(::FloatProperty, RollLimit, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PitchLimit, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, YawLimit, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShowPerAxisLimits, 0x8)
		ADD_VAR(::BoolProperty, bLimitRoll, 0x4)
		ADD_VAR(::BoolProperty, bLimitPitch, 0x2)
		ADD_VAR(::BoolProperty, bLimitYaw, 0x1)
	};
}
#undef ADD_VAR
