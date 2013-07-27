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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58463);
			byte params[5] = { NULL };
			*(TrObject::ESettingsList*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void FlushSettings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78165);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StoreSetting(int SettingId, int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78166);
			byte params[8] = { NULL };
			*(int*)params = SettingId;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int ReadSetting(int SettingId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78169);
			byte params[8] = { NULL };
			*(int*)params = SettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void ReadSettings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78172);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LoadControlSettings(class GFxObject* List)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78175);
			byte params[4] = { NULL };
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddControlSetting(ScriptString* ControlName, float val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78180);
			byte params[16] = { NULL };
			*(ScriptString**)params = ControlName;
			*(float*)&params[12] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SaveControlSetting(int Index, float val, bool bStore)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78184);
			byte params[12] = { NULL };
			*(int*)params = Index;
			*(float*)&params[4] = val;
			*(bool*)&params[8] = bStore;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		TrObject::ESettingsList GetControlTypeFromName(ScriptString* ControlName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78192);
			byte params[13] = { NULL };
			*(ScriptString**)params = ControlName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(TrObject::ESettingsList*)&params[12];
		}
		ScriptString* GetControlNameFromType(TrObject::ESettingsList Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78195);
			byte params[13] = { NULL };
			*(TrObject::ESettingsList*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		class PlayerInput* GetPlayerInput()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78198);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PlayerInput**)params;
		}
		void UpdateRuntimePlayer(class PlayerInput* EngineInput)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78201);
			byte params[4] = { NULL };
			*(class PlayerInput**)params = EngineInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SaveTinyWeaponValue(int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78204);
			byte params[4] = { NULL };
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetTinyWeaponValue()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78206);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool GetAlienFXValue()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78208);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SaveAlienFXValue(int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78210);
			byte params[4] = { NULL };
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SaveChatFilterValue(int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78212);
			byte params[4] = { NULL };
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetChatFilterValue()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78214);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SaveHUDFriendStateNotificationsValue(int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78216);
			byte params[4] = { NULL };
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetHUDFriendStateNotifications()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78218);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SaveWhisperNotificationsValue(int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78220);
			byte params[4] = { NULL };
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetWhisperNotificationsValue()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78222);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void SaveHelpTextValue(int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78224);
			byte params[4] = { NULL };
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetHelpTextValue()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78229);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SaveSimulatedProjectilesValue(int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78231);
			byte params[4] = { NULL };
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetSimulatedProjectilesValue()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78233);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SaveDamageCounterValue(int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78235);
			byte params[4] = { NULL };
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetDamageCounterValue()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78237);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SaveHUDObjectivesValue(int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78239);
			byte params[4] = { NULL };
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetHUDObjectivesValue()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78241);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
