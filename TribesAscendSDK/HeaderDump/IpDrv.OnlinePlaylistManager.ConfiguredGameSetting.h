#pragma once
#include "Engine.OnlineGameSettings.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlinePlaylistManager.ConfiguredGameSetting." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty OnlinePlaylistManager.ConfiguredGameSetting." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ConfiguredGameSetting
	{
	public:
		ADD_OBJECT(OnlineGameSettings, GameSettings)
		ADD_VAR(::StrProperty, URL, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, GameSettingsClassName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GameSettingId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
