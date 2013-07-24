#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKScriptedNavigationPoint." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKScriptedNavigationPoint : public NavigationPoint
	{
	public:
		ADD_VAR(::BoolProperty, bAnchorMustBeReachable, 0x4)
		ADD_VAR(::BoolProperty, bScriptNotifyAnchorFindingResult, 0x2)
		ADD_VAR(::BoolProperty, bScriptSpecifyEndAnchor, 0x1)
	};
}
#undef ADD_VAR
