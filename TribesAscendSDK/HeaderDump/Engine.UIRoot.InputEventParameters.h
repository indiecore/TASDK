#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UIRoot.InputEventParameters." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InputEventParameters
	{
	public:
		ADD_VAR(::BoolProperty, bShiftPressed, 0x4)
		ADD_VAR(::BoolProperty, bCtrlPressed, 0x2)
		ADD_VAR(::BoolProperty, bAltPressed, 0x1)
		ADD_VAR(::FloatProperty, DeltaTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InputDelta, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, EventType, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, InputKeyName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ControllerId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PlayerIndex, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
