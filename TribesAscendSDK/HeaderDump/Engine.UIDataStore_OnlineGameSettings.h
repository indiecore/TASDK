#pragma once
#include "Engine.UIDataStore_Settings.h"
#include "Engine.LocalPlayer.h"
#include "Engine.UIDataProvider.h"
#include "Engine.OnlineGameSettings.h"
#include "Engine.UIDataProvider_Settings.h"
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
	class UIDataStore_OnlineGameSettings : public UIDataStore_Settings
	{
	public:
		class GameSettingsCfg
		{
		public:
			ADD_STRUCT(ScriptName, SettingsName, 12)
			ADD_OBJECT(OnlineGameSettings, GameSettings, 8)
			ADD_OBJECT(UIDataProvider_Settings, Provider, 4)
			ADD_OBJECT(ScriptClass, GameSettingsClass, 0)
		};
		ADD_STRUCT(ScriptArray<UIDataStore_OnlineGameSettings::GameSettingsCfg>, GameSettingsCfgList, 120)
		ADD_STRUCT(int, SelectedIndex, 136)
		ADD_OBJECT(ScriptClass, SettingsProviderClass, 132)
		void OnSettingProviderChanged(class UIDataProvider* SourceProvider, ScriptName SettingsName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSettings.OnSettingProviderChanged");
			byte params[12] = { NULL };
			*(class UIDataProvider**)&params[0] = SourceProvider;
			*(ScriptName*)&params[4] = SettingsName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CreateGame(byte ControllerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSettings.CreateGame");
			byte params[5] = { NULL };
			params[0] = ControllerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class OnlineGameSettings* GetCurrentGameSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSettings.GetCurrentGameSettings");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class OnlineGameSettings**)&params[0];
		}
		class UIDataProvider_Settings* GetCurrentProvider()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSettings.GetCurrentProvider");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UIDataProvider_Settings**)&params[0];
		}
		void SetCurrentByIndex(int NewIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSettings.SetCurrentByIndex");
			byte params[4] = { NULL };
			*(int*)&params[0] = NewIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCurrentByName(ScriptName SettingsName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSettings.SetCurrentByName");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = SettingsName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MoveToNext()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSettings.MoveToNext");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MoveToPrevious()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSettings.MoveToPrevious");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Registered(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSettings.Registered");
			byte params[4] = { NULL };
			*(class LocalPlayer**)&params[0] = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Unregistered(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSettings.Unregistered");
			byte params[4] = { NULL };
			*(class LocalPlayer**)&params[0] = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
