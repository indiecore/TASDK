#pragma once
#include "GFxUI__GFxObject.h"
#include "Engine__PlayerInput.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrControlSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrControlSettings." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrControlSettings : public GFxObject
	{
	public:
		ADD_OBJECT(GFxObject, m_ControlSettingsList)
		ADD_VAR(::IntProperty, m_ControlSettingsCount, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetCurrentControlValue'
		// Here lies the not-yet-implemented method 'FlushSettings'
		// Here lies the not-yet-implemented method 'StoreSetting'
		// Here lies the not-yet-implemented method 'ReadSetting'
		// Here lies the not-yet-implemented method 'ReadSettings'
		// Here lies the not-yet-implemented method 'LoadControlSettings'
		// Here lies the not-yet-implemented method 'AddControlSetting'
		// Here lies the not-yet-implemented method 'SaveControlSetting'
		// Here lies the not-yet-implemented method 'GetControlTypeFromName'
		// Here lies the not-yet-implemented method 'GetControlNameFromType'
		// Here lies the not-yet-implemented method 'GetPlayerInput'
		// Here lies the not-yet-implemented method 'UpdateRuntimePlayer'
		// Here lies the not-yet-implemented method 'SaveTinyWeaponValue'
		// Here lies the not-yet-implemented method 'GetTinyWeaponValue'
		// Here lies the not-yet-implemented method 'GetAlienFXValue'
		// Here lies the not-yet-implemented method 'SaveAlienFXValue'
		// Here lies the not-yet-implemented method 'SaveChatFilterValue'
		// Here lies the not-yet-implemented method 'GetChatFilterValue'
		// Here lies the not-yet-implemented method 'SaveHUDFriendStateNotificationsValue'
		// Here lies the not-yet-implemented method 'GetHUDFriendStateNotifications'
		// Here lies the not-yet-implemented method 'SaveWhisperNotificationsValue'
		// Here lies the not-yet-implemented method 'GetWhisperNotificationsValue'
		// Here lies the not-yet-implemented method 'SaveHelpTextValue'
		// Here lies the not-yet-implemented method 'GetHelpTextValue'
		// Here lies the not-yet-implemented method 'SaveSimulatedProjectilesValue'
		// Here lies the not-yet-implemented method 'GetSimulatedProjectilesValue'
		// Here lies the not-yet-implemented method 'SaveDamageCounterValue'
		// Here lies the not-yet-implemented method 'GetDamageCounterValue'
		// Here lies the not-yet-implemented method 'SaveHUDObjectivesValue'
		// Here lies the not-yet-implemented method 'GetHUDObjectivesValue'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
