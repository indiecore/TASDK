#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKSkelControl_HoverboardSwing." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKSkelControl_HoverboardSwing : public SkelControlSingleBone
	{
	public:
		ADD_VAR(::FloatProperty, CurrentSwing, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxUseVel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxSwing, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SwingScale, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SwingHistorySlot, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SwingHistoryWindow, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
