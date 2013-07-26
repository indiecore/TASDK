#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " FrameworkGame.RequiredMobileInputConfig." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RequiredMobileInputConfig
	{
	public:
		ADD_VAR(::BoolProperty, bIsAttractModeGroup, 0x1)
		ADD_VAR(::StrProperty, GroupName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
