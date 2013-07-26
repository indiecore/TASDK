#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrHelpTextManager.HelpTextTypeRemovalTimerInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class HelpTextTypeRemovalTimerInfo
	{
	public:
		ADD_VAR(::BoolProperty, bSuppress, 0x1)
		ADD_VAR(::FloatProperty, RemainingTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, HelpTextTypeToRemove, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
