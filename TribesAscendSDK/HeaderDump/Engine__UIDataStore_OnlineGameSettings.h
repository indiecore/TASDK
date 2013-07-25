#pragma once
#include "Engine__UIDataStore_Settings.h"
#include "Engine__UIDataProvider.h"
#include "Engine__OnlineGameSettings.h"
#include "Engine__UIDataProvider_Settings.h"
#include "Engine__LocalPlayer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataStore_OnlineGameSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.UIDataStore_OnlineGameSettings." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIDataStore_OnlineGameSettings : public UIDataStore_Settings
	{
	public:
		ADD_VAR(::IntProperty, SelectedIndex, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, SettingsProviderClass)
		// Here lies the not-yet-implemented method 'OnSettingProviderChanged'
		// Here lies the not-yet-implemented method 'CreateGame'
		// Here lies the not-yet-implemented method 'GetCurrentGameSettings'
		// Here lies the not-yet-implemented method 'GetCurrentProvider'
		// Here lies the not-yet-implemented method 'SetCurrentByIndex'
		// Here lies the not-yet-implemented method 'SetCurrentByName'
		// Here lies the not-yet-implemented method 'MoveToNext'
		// Here lies the not-yet-implemented method 'MoveToPrevious'
		// Here lies the not-yet-implemented method 'Registered'
		// Here lies the not-yet-implemented method 'Unregistered'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
