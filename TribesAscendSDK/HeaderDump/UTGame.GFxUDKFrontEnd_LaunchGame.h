#pragma once
#include "UTGame.GFxUDKFrontEnd_Screen.h"
#include "Engine.UIDataStore_OnlineGameSettings.h"
#include "UTGame.UTUIDataStore_MenuItems.h"
#include "GFxUI.GFxObject.h"
#include "GFxUI.GFxClikWidget.h"
#include "UTGame.UTUIDataStore_StringList.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUDKFrontEnd_LaunchGame." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUDKFrontEnd_LaunchGame." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_LaunchGame : public GFxUDKFrontEnd_Screen
	{
	public:
		ADD_OBJECT(GFxObject, MutatorsLabelTxt)
		ADD_OBJECT(GFxObject, RespawnLabelTxt)
		ADD_OBJECT(GFxObject, TimeLabelTxt)
		ADD_OBJECT(GFxObject, ScoreLabelTxt)
		ADD_OBJECT(GFxObject, OpponentsLabelTxt)
		ADD_OBJECT(GFxObject, BotLvlLabelTxt)
		ADD_OBJECT(GFxObject, MapLabelTxt)
		ADD_OBJECT(GFxObject, MutatorsTxt)
		ADD_OBJECT(GFxObject, RespawnTxt)
		ADD_OBJECT(GFxObject, MapTxt)
		ADD_OBJECT(GFxObject, TimeTxt)
		ADD_OBJECT(GFxObject, ScoreTxt)
		ADD_OBJECT(GFxObject, OpponentsTxt)
		ADD_OBJECT(GFxObject, BotLvlTxt)
		ADD_OBJECT(GFxObject, GameTitleTxt)
		ADD_OBJECT(GFxObject, MapNameTxt)
		ADD_OBJECT(GFxObject, MapImageMC)
		ADD_OBJECT(GFxObject, MenuMC)
		ADD_OBJECT(GFxObject, ListDataProvider)
		ADD_OBJECT(GFxClikWidget, ListMC)
		ADD_VAR(::StrProperty, DefaultGameModePrefixes, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DefaultMapImage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DefaultGameModeSettings, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DefaultGameMode, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DefaultMapName, 0xFFFFFFFF)
		ADD_OBJECT(UTUIDataStore_MenuItems, MenuDataStore)
		ADD_OBJECT(UTUIDataStore_StringList, StringListDataStore)
		ADD_OBJECT(UIDataStore_OnlineGameSettings, SettingsDataStore)
		ScriptArray<wchar_t> GetGameModeFriendlyString(ScriptArray<wchar_t> InGameMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_LaunchGame.GetGameModeFriendlyString");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = InGameMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		void OnViewLoaded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_LaunchGame.OnViewLoaded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnViewActivated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_LaunchGame.OnViewActivated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableSubComponents(bool bDisableComponents)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_LaunchGame.DisableSubComponents");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bDisableComponents;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_LaunchGame.OnTopMostView");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateGameSettingsPanel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_LaunchGame.UpdateGameSettingsPanel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayOpenAnimation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_LaunchGame.PlayOpenAnimation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayCloseAnimation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_LaunchGame.PlayCloseAnimation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnStartGame_Confirm()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_LaunchGame.OnStartGame_Confirm");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnListItemPress(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxClikWidget.EventData'!
void* ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_LaunchGame.OnListItemPress");
			byte* params = (byte*)malloc(36);
			*(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxClikWidget.EventData'!
void**)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnListChange(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxClikWidget.EventData'!
void* ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_LaunchGame.OnListChange");
			byte* params = (byte*)malloc(36);
			*(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxClikWidget.EventData'!
void**)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateDescription()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_LaunchGame.UpdateDescription");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateListDataProvider()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_LaunchGame.UpdateListDataProvider");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_LaunchGame.WidgetInitialized");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = WidgetName;
			*(ScriptName*)(params + 8) = WidgetPath;
			*(class GFxObject**)(params + 16) = Widget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetStringFromMarkup(ScriptArray<wchar_t> MarkupString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_LaunchGame.GetStringFromMarkup");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = MarkupString;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
