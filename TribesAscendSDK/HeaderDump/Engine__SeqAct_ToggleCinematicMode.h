#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_ToggleCinematicMode." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_ToggleCinematicMode : public SequenceAction
	{
	public:
		ADD_VAR(::BoolProperty, bHidePlayer, 0x4)
		ADD_VAR(::BoolProperty, bHideHUD, 0x10)
		ADD_VAR(::BoolProperty, bDisableMovement, 0x1)
		ADD_VAR(::BoolProperty, bDisableTurning, 0x2)
		ADD_VAR(::BoolProperty, bDisableInput, 0x8)
		ADD_VAR(::BoolProperty, bDroppedPickups, 0x40)
		ADD_VAR(::BoolProperty, bDeadBodies, 0x20)
	};
}
#undef ADD_VAR
