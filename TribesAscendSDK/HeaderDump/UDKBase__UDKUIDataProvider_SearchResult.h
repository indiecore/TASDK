#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKUIDataProvider_SearchResult." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKUIDataProvider_SearchResult : public UIDataProvider_Settings
	{
	public:
		ADD_VAR(::StrProperty, IconFontPathName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, MapNameTag, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ServerFlagsTag, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, GameModeFriendlyNameTag, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, PlayerRatioTag, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
