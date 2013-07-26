#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrGameObjective.UpgradeSelectionList." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrGameObjective.UpgradeSelectionList." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UpgradeSelectionList
	{
	public:
		ADD_VAR(::NameProperty, PropertyName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NewValue, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, UpgradeCreditCost, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, UpgradeLevel, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, UpgradeClass)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
