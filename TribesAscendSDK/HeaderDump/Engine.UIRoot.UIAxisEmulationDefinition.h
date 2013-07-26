#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UIRoot.UIAxisEmulationDefinition." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIAxisEmulationDefinition
	{
	public:
		ADD_VAR(::NameProperty, InputKeyToEmulate, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEmulateButtonPress, 0x1)
		ADD_VAR(::NameProperty, AdjacentAxisInputKey, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AxisInputKey, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
