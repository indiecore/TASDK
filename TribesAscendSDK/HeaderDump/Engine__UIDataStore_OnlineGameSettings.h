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
		void OnSettingProviderChanged(class UIDataProvider* SourceProvider, ScriptName SettingsName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSettings.OnSettingProviderChanged");
			byte* params = (byte*)malloc(12);
			*(class UIDataProvider**)params = SourceProvider;
			*(ScriptName*)(params + 4) = SettingsName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CreateGame(byte ControllerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSettings.CreateGame");
			byte* params = (byte*)malloc(5);
			*params = ControllerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		class OnlineGameSettings* GetCurrentGameSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSettings.GetCurrentGameSettings");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class OnlineGameSettings**)params;
			free(params);
			return returnVal;
		}
		class UIDataProvider_Settings* GetCurrentProvider()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSettings.GetCurrentProvider");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UIDataProvider_Settings**)params;
			free(params);
			return returnVal;
		}
		void SetCurrentByIndex(int NewIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSettings.SetCurrentByIndex");
			byte* params = (byte*)malloc(4);
			*(int*)params = NewIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetCurrentByName(ScriptName SettingsName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSettings.SetCurrentByName");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = SettingsName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(class LocalPlayer**)params = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Unregistered(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlineGameSettings.Unregistered");
			byte* params = (byte*)malloc(4);
			*(class LocalPlayer**)params = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
