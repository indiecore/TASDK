#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SeqAct_RangeSwitch.SwitchRange." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SwitchRange
	{
	public:
		ADD_VAR(::IntProperty, Max, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Min, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
