#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTConsolePlayerController.ProfileSettingToUE3BindingDatum." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ProfileSettingToUE3BindingDatum
	{
	public:
		ADD_VAR(::NameProperty, UE3BindingName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ProfileSettingName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
