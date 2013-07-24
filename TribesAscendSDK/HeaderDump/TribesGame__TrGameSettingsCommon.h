#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGameSettingsCommon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrGameSettingsCommon : public UTGameSettingsCommon
	{
	public:
		ADD_VAR(::StrProperty, MapName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, GameMode, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, Console, 0x1)
	};
}
#undef ADD_VAR
