#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKSkelControl_HoverboardVibration." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKSkelControl_HoverboardVibration : public SkelControlSingleBone
	{
	public:
		ADD_VAR(::FloatProperty, VibInput, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VibMaxAmplitude, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VibTurnAmpScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VibSpeedAmpScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VibFrequency, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
