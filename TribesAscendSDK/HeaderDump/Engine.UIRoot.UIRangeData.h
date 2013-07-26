#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UIRoot.UIRangeData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIRangeData
	{
	public:
		ADD_VAR(::BoolProperty, bIntRange, 0x1)
		ADD_VAR(::FloatProperty, NudgeValue, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxValue, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinValue, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentValue, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
