#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrRibbonManager.RibbonData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RibbonData
	{
	public:
		ADD_VAR(::IntProperty, Ribbon, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Type, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Id, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
