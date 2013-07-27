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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrKeyBindings.GetCurrentBind");
			byte params[13] = { NULL };
			*(TrObject::ESettingsList*)&params[0] = Key;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* SaveKeyBind(int Index, ScriptString* KeyName, bool bStore)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrKeyBindings.SaveKeyBind");
			byte params[32] = { NULL };
			*(int*)&params[0] = Index;
			*(ScriptString**)&params[4] = KeyName;
			*(bool*)&params[16] = bStore;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[20];
		}
		void FlushSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrKeyBindings.FlushSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearSettingById(int SettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrKeyBindings.ClearSettingById");
			byte params[4] = { NULL };
			*(int*)&params[0] = SettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearSettingByValue(ScriptString* StrValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrKeyBindings.ClearSettingByValue");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = StrValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StoreSetting(int SettingId, ScriptString* KeyBind)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrKeyBindings.StoreSetting");
			byte params[16] = { NULL };
			*(int*)&params[0] = SettingId;
			*(ScriptString**)&params[4] = KeyBind;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* ReadSetting(int SettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrKeyBindings.ReadSetting");
			byte params[16] = { NULL };
			*(int*)&params[0] = SettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void CaptureNextKey()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrKeyBindings.CaptureNextKey");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetDefaultKeyBindings(class PlayerInput* pInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrKeyBindings.ResetDefaultKeyBindings");
			byte params[4] = { NULL };
			*(class PlayerInput**)&params[0] = pInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetDefaultSpectatorBindings(class TrPlayerInput_Spectator* pInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrKeyBindings.ResetDefaultSpectatorBindings");
			byte params[4] = { NULL };
			*(class TrPlayerInput_Spectator**)&params[0] = pInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReadBindings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrKeyBindings.ReadBindings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddBinding(ScriptString* Command, ScriptString* KeyName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrKeyBindings.AddBinding");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = Command;
			*(ScriptString**)&params[12] = KeyName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyKeyBinding(int Index, ScriptString* val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrKeyBindings.ApplyKeyBinding");
			byte params[16] = { NULL };
			*(int*)&params[0] = Index;
			*(ScriptString**)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* SavePlayerKeyBind(int Index, ScriptString* KeyName, bool bStore)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrKeyBindings.SavePlayerKeyBind");
			byte params[32] = { NULL };
			*(int*)&params[0] = Index;
			*(ScriptString**)&params[4] = KeyName;
			*(bool*)&params[16] = bStore;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[20];
		}
		ScriptString* SaveSpectatorKeyBind(int Index, ScriptString* KeyName, bool bStore)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrKeyBindings.SaveSpectatorKeyBind");
			byte params[32] = { NULL };
			*(int*)&params[0] = Index;
			*(ScriptString**)&params[4] = KeyName;
			*(bool*)&params[16] = bStore;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[20];
		}
		void UnbindPlayerCommand(class PlayerInput* pInput, ScriptString* Command)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrKeyBindings.UnbindPlayerCommand");
			byte params[16] = { NULL };
			*(class PlayerInput**)&params[0] = pInput;
			*(ScriptString**)&params[4] = Command;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnbindSpectatorCommand(class TrPlayerInput_Spectator* pInput, ScriptString* Command)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrKeyBindings.UnbindSpectatorCommand");
			byte params[16] = { NULL };
			*(class TrPlayerInput_Spectator**)&params[0] = pInput;
			*(ScriptString**)&params[4] = Command;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetCurrentBinding(class PlayerInput* pInput, ScriptString* Command)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrKeyBindings.GetCurrentBinding");
			byte params[28] = { NULL };
			*(class PlayerInput**)&params[0] = pInput;
			*(ScriptString**)&params[4] = Command;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[16];
		}
		ScriptString* GetCommandName(TrObject::ESettingsList Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrKeyBindings.GetCommandName");
			byte params[13] = { NULL };
			*(TrObject::ESettingsList*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void ApplyDefaultSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrKeyBindings.ApplyDefaultSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class PlayerInput* GetPlayerInput()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrKeyBindings.GetPlayerInput");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PlayerInput**)&params[0];
		}
		class TrPlayerInput_Spectator* GetSpectatorInput()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrKeyBindings.GetSpectatorInput");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrPlayerInput_Spectator**)&params[0];
		}
		void UpdateRuntimePlayer(class PlayerInput* EngineInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrKeyBindings.UpdateRuntimePlayer");
			byte params[4] = { NULL };
			*(class PlayerInput**)&params[0] = EngineInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateRuntimeSpectator(class TrPlayerInput_Spectator* SpecInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrKeyBindings.UpdateRuntimeSpectator");
			byte params[4] = { NULL };
			*(class TrPlayerInput_Spectator**)&params[0] = SpecInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SaveInterceptKeys()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrKeyBindings.SaveInterceptKeys");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
