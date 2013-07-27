#pragma once
#include "GFxUI.GFxObject.h"
#include "Engine.PlayerInput.h"
#include "TribesGame.TrObject.h"
#include "TribesGame.TrPlayerInput_Spectator.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class TrKeyBindings : public GFxObject
	{
	public:
		ADD_STRUCT(ScriptString*, m_EscapeKeybind, 136)
		ADD_STRUCT(ScriptString*, m_FriendsHotkey, 232)
		ADD_STRUCT(ScriptString*, m_SettingsHotkey, 244)
		ADD_STRUCT(ScriptString*, m_MainMenuHotkey, 256)
		ADD_STRUCT(ScriptString*, m_ClassSelectKeybind, 172)
		ADD_STRUCT(ScriptString*, m_TeamSelectKeybind, 160)
		ADD_STRUCT(ScriptString*, m_TalkReplyKeybind, 220)
		ADD_STRUCT(ScriptString*, m_ChatHotkey, 268)
		ADD_STRUCT(ScriptString*, m_TalkKeybind, 196)
		ADD_STRUCT(ScriptString*, m_TeamTalkKeybind, 208)
		ADD_STRUCT(ScriptString*, m_ScoreboardKeybind, 184)
		ADD_STRUCT(ScriptString*, m_EnterKeybind, 148)
		ADD_OBJECT(PlayerInput, m_EngineInput, 132)
		ADD_OBJECT(GFxObject, m_KeyBindingsList, 128)
		ADD_STRUCT(int, m_KeyBindingsCount, 124)
		ADD_BOOL(m_bGotInputKey, 120, 0x1)
		ScriptString* GetCurrentBind(TrObject::ESettingsList Key)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59263);
			byte params[13] = { NULL };
			*(TrObject::ESettingsList*)params = Key;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* SaveKeyBind(int Index, ScriptString* KeyName, bool bStore)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59276);
			byte params[32] = { NULL };
			*(int*)params = Index;
			*(ScriptString**)&params[4] = KeyName;
			*(bool*)&params[16] = bStore;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[20];
		}
		void FlushSettings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98370);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearSettingById(int SettingId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98371);
			byte params[4] = { NULL };
			*(int*)params = SettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearSettingByValue(ScriptString* StrValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98373);
			byte params[12] = { NULL };
			*(ScriptString**)params = StrValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StoreSetting(int SettingId, ScriptString* KeyBind)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98375);
			byte params[16] = { NULL };
			*(int*)params = SettingId;
			*(ScriptString**)&params[4] = KeyBind;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* ReadSetting(int SettingId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98378);
			byte params[16] = { NULL };
			*(int*)params = SettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void CaptureNextKey()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98381);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetDefaultKeyBindings(class PlayerInput* pInput)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98382);
			byte params[4] = { NULL };
			*(class PlayerInput**)params = pInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetDefaultSpectatorBindings(class TrPlayerInput_Spectator* pInput)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98384);
			byte params[4] = { NULL };
			*(class TrPlayerInput_Spectator**)params = pInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReadBindings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98386);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddBinding(ScriptString* Command, ScriptString* KeyName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98392);
			byte params[24] = { NULL };
			*(ScriptString**)params = Command;
			*(ScriptString**)&params[12] = KeyName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyKeyBinding(int Index, ScriptString* val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98396);
			byte params[16] = { NULL };
			*(int*)params = Index;
			*(ScriptString**)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* SavePlayerKeyBind(int Index, ScriptString* KeyName, bool bStore)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98403);
			byte params[32] = { NULL };
			*(int*)params = Index;
			*(ScriptString**)&params[4] = KeyName;
			*(bool*)&params[16] = bStore;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[20];
		}
		ScriptString* SaveSpectatorKeyBind(int Index, ScriptString* KeyName, bool bStore)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98412);
			byte params[32] = { NULL };
			*(int*)params = Index;
			*(ScriptString**)&params[4] = KeyName;
			*(bool*)&params[16] = bStore;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[20];
		}
		void UnbindPlayerCommand(class PlayerInput* pInput, ScriptString* Command)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98421);
			byte params[16] = { NULL };
			*(class PlayerInput**)params = pInput;
			*(ScriptString**)&params[4] = Command;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnbindSpectatorCommand(class TrPlayerInput_Spectator* pInput, ScriptString* Command)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98426);
			byte params[16] = { NULL };
			*(class TrPlayerInput_Spectator**)params = pInput;
			*(ScriptString**)&params[4] = Command;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetCurrentBinding(class PlayerInput* pInput, ScriptString* Command)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98431);
			byte params[28] = { NULL };
			*(class PlayerInput**)params = pInput;
			*(ScriptString**)&params[4] = Command;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[16];
		}
		ScriptString* GetCommandName(TrObject::ESettingsList Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98436);
			byte params[13] = { NULL };
			*(TrObject::ESettingsList*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void ApplyDefaultSettings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98439);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class PlayerInput* GetPlayerInput()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98443);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PlayerInput**)params;
		}
		class TrPlayerInput_Spectator* GetSpectatorInput()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98446);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrPlayerInput_Spectator**)params;
		}
		void UpdateRuntimePlayer(class PlayerInput* EngineInput)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98449);
			byte params[4] = { NULL };
			*(class PlayerInput**)params = EngineInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateRuntimeSpectator(class TrPlayerInput_Spectator* SpecInput)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98452);
			byte params[4] = { NULL };
			*(class TrPlayerInput_Spectator**)params = SpecInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SaveInterceptKeys()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98455);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
