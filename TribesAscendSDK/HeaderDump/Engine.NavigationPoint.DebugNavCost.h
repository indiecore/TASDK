#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " NavigationPoint.DebugNavCost." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DebugNavCost
	{
	public:
		ADD_VAR(::IntProperty, Cost, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Desc, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
