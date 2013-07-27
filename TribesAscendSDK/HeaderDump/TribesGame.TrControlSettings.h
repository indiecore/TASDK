#pragma once
#include "GFxUI.GFxObject.h"
#include "TribesGame.TrObject.h"
#include "Engine.PlayerInput.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrControlSettings : public GFxObject
	{
	public:
		ADD_OBJECT(GFxObject, m_ControlSettingsList, 124)
		ADD_STRUCT(int, m_ControlSettingsCount, 120)
		float GetCurrentControlValue(TrObject::ESettingsList Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetCurrentControlValue");
			byte params[5] = { NULL };
			*(TrObject::ESettingsList*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void FlushSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.FlushSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StoreSetting(int SettingId, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.StoreSetting");
			byte params[8] = { NULL };
			*(int*)&params[0] = SettingId;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int ReadSetting(int SettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.ReadSetting");
			byte params[8] = { NULL };
			*(int*)&params[0] = SettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void ReadSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.ReadSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LoadControlSettings(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.LoadControlSettings");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddControlSetting(ScriptString* ControlName, float val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.AddControlSetting");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = ControlName;
			*(float*)&params[12] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SaveControlSetting(int Index, float val, bool bStore)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.SaveControlSetting");
			byte params[12] = { NULL };
			*(int*)&params[0] = Index;
			*(float*)&params[4] = val;
			*(bool*)&params[8] = bStore;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		TrObject::ESettingsList GetControlTypeFromName(ScriptString* ControlName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetControlTypeFromName");
			byte params[13] = { NULL };
			*(ScriptString**)&params[0] = ControlName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(TrObject::ESettingsList*)&params[12];
		}
		ScriptString* GetControlNameFromType(TrObject::ESettingsList Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetControlNameFromType");
			byte params[13] = { NULL };
			*(TrObject::ESettingsList*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		class PlayerInput* GetPlayerInput()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetPlayerInput");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PlayerInput**)&params[0];
		}
		void UpdateRuntimePlayer(class PlayerInput* EngineInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.UpdateRuntimePlayer");
			byte params[4] = { NULL };
			*(class PlayerInput**)&params[0] = EngineInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SaveTinyWeaponValue(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.SaveTinyWeaponValue");
			byte params[4] = { NULL };
			*(int*)&params[0] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetTinyWeaponValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetTinyWeaponValue");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool GetAlienFXValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetAlienFXValue");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SaveAlienFXValue(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.SaveAlienFXValue");
			byte params[4] = { NULL };
			*(int*)&params[0] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SaveChatFilterValue(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.SaveChatFilterValue");
			byte params[4] = { NULL };
			*(int*)&params[0] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetChatFilterValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetChatFilterValue");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SaveHUDFriendStateNotificationsValue(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.SaveHUDFriendStateNotificationsValue");
			byte params[4] = { NULL };
			*(int*)&params[0] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetHUDFriendStateNotifications()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetHUDFriendStateNotifications");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SaveWhisperNotificationsValue(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.SaveWhisperNotificationsValue");
			byte params[4] = { NULL };
			*(int*)&params[0] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetWhisperNotificationsValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetWhisperNotificationsValue");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void SaveHelpTextValue(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.SaveHelpTextValue");
			byte params[4] = { NULL };
			*(int*)&params[0] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetHelpTextValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetHelpTextValue");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SaveSimulatedProjectilesValue(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.SaveSimulatedProjectilesValue");
			byte params[4] = { NULL };
			*(int*)&params[0] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetSimulatedProjectilesValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetSimulatedProjectilesValue");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SaveDamageCounterValue(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.SaveDamageCounterValue");
			byte params[4] = { NULL };
			*(int*)&params[0] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetDamageCounterValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetDamageCounterValue");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SaveHUDObjectivesValue(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.SaveHUDObjectivesValue");
			byte params[4] = { NULL };
			*(int*)&params[0] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetHUDObjectivesValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetHUDObjectivesValue");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
