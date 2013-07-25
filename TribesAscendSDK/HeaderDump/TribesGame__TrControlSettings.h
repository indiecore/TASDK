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
		float GetCurrentControlValue(byte Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetCurrentControlValue");
			byte* params = (byte*)malloc(5);
			*params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		void FlushSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.FlushSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StoreSetting(int SettingId, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.StoreSetting");
			byte* params = (byte*)malloc(8);
			*(int*)params = SettingId;
			*(int*)(params + 4) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int ReadSetting(int SettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.ReadSetting");
			byte* params = (byte*)malloc(8);
			*(int*)params = SettingId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void ReadSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.ReadSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LoadControlSettings(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.LoadControlSettings");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddControlSetting(ScriptArray<wchar_t> ControlName, float val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.AddControlSetting");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = ControlName;
			*(float*)(params + 12) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SaveControlSetting(int Index, float val, bool bStore)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.SaveControlSetting");
			byte* params = (byte*)malloc(12);
			*(int*)params = Index;
			*(float*)(params + 4) = val;
			*(bool*)(params + 8) = bStore;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte GetControlTypeFromName(ScriptArray<wchar_t> ControlName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetControlTypeFromName");
			byte* params = (byte*)malloc(13);
			*(ScriptArray<wchar_t>*)params = ControlName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 12);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetControlNameFromType(byte Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetControlNameFromType");
			byte* params = (byte*)malloc(13);
			*params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		class PlayerInput* GetPlayerInput()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetPlayerInput");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PlayerInput**)params;
			free(params);
			return returnVal;
		}
		void UpdateRuntimePlayer(class PlayerInput* EngineInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.UpdateRuntimePlayer");
			byte* params = (byte*)malloc(4);
			*(class PlayerInput**)params = EngineInput;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SaveTinyWeaponValue(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.SaveTinyWeaponValue");
			byte* params = (byte*)malloc(4);
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetTinyWeaponValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetTinyWeaponValue");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool GetAlienFXValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetAlienFXValue");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SaveAlienFXValue(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.SaveAlienFXValue");
			byte* params = (byte*)malloc(4);
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SaveChatFilterValue(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.SaveChatFilterValue");
			byte* params = (byte*)malloc(4);
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetChatFilterValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetChatFilterValue");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SaveHUDFriendStateNotificationsValue(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.SaveHUDFriendStateNotificationsValue");
			byte* params = (byte*)malloc(4);
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetHUDFriendStateNotifications()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetHUDFriendStateNotifications");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SaveWhisperNotificationsValue(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.SaveWhisperNotificationsValue");
			byte* params = (byte*)malloc(4);
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetWhisperNotificationsValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetWhisperNotificationsValue");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void SaveHelpTextValue(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.SaveHelpTextValue");
			byte* params = (byte*)malloc(4);
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetHelpTextValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetHelpTextValue");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SaveSimulatedProjectilesValue(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.SaveSimulatedProjectilesValue");
			byte* params = (byte*)malloc(4);
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetSimulatedProjectilesValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetSimulatedProjectilesValue");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SaveDamageCounterValue(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.SaveDamageCounterValue");
			byte* params = (byte*)malloc(4);
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetDamageCounterValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetDamageCounterValue");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SaveHUDObjectivesValue(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.SaveHUDObjectivesValue");
			byte* params = (byte*)malloc(4);
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetHUDObjectivesValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrControlSettings.GetHUDObjectivesValue");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
