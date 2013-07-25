#pragma once
#include "GFxUI__GFxObject.h"
#include "UTGame__GFxUDKFrontEnd_Screen.h"
#include "GFxUI__GFxClikWidget.h"
#include "Engine__UIDataStore_OnlineGameSettings.h"
#include "UTGame__UTUIDataStore_StringList.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUDKFrontEnd_GameMode." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUDKFrontEnd_GameMode." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_GameMode : public GFxUDKFrontEnd_Screen
	{
	public:
		ADD_OBJECT(GFxClikWidget, ImgScrollerMC)
		ADD_OBJECT(GFxObject, MenuMC)
		ADD_OBJECT(GFxObject, ListDataProvider)
		ADD_OBJECT(GFxClikWidget, ListMC)
		ADD_VAR(::StrProperty, MapName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, GameMode, 0xFFFFFFFF)
		ADD_OBJECT(UTUIDataStore_StringList, StringListDataStore)
		ADD_OBJECT(UIDataStore_OnlineGameSettings, SettingsDataStore)
		void OnViewLoaded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_GameMode.OnViewLoaded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_GameMode.OnTopMostView");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisableSubComponents(bool bDisableComponents)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_GameMode.DisableSubComponents");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bDisableComponents;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnGameModeSelected(ScriptArray<wchar_t> InGameMode, ScriptArray<wchar_t> InDefaultMap, ScriptArray<wchar_t> InGameSettingsClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_GameMode.OnGameModeSelected");
			byte* params = (byte*)malloc(36);
			*(ScriptArray<wchar_t>*)params = InGameMode;
			*(ScriptArray<wchar_t>*)(params + 12) = InDefaultMap;
			*(ScriptArray<wchar_t>*)(params + 24) = InGameSettingsClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnGameModeChange(int SelectedIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_GameMode.OnGameModeChange");
			byte* params = (byte*)malloc(4);
			*(int*)params = SelectedIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnListItemPress(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxClikWidget.EventData'!
void* ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_GameMode.OnListItemPress");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_GameMode.OnListChange");
			byte* params = (byte*)malloc(36);
			*(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxClikWidget.EventData'!
void**)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateDescription()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_GameMode.UpdateDescription");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateListDataProvider()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_GameMode.UpdateListDataProvider");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetImgScroller(class GFxClikWidget* InImgScroller)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_GameMode.SetImgScroller");
			byte* params = (byte*)malloc(4);
			*(class GFxClikWidget**)params = InImgScroller;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ASSetList(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_GameMode.ASSetList");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_GameMode.WidgetInitialized");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = WidgetName;
			*(ScriptName*)(params + 8) = WidgetPath;
			*(class GFxObject**)(params + 16) = Widget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
