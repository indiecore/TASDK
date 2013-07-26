#pragma once
#include "Engine.OnlineGameSettings.h"
#include "Engine.UIDataProvider_Settings.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UIDataStore_OnlineGameSettings.GameSettingsCfg." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UIDataStore_OnlineGameSettings.GameSettingsCfg." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameSettingsCfg
	{
	public:
		ADD_VAR(::NameProperty, SettingsName, 0xFFFFFFFF)
		ADD_OBJECT(OnlineGameSettings, GameSettings)
		ADD_OBJECT(UIDataProvider_Settings, Provider)
		ADD_OBJECT(ScriptClass, GameSettingsClass)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
