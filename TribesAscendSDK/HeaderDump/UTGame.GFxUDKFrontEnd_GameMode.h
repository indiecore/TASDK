#pragma once
#include "UTGame.GFxUDKFrontEnd_Screen.h"
#include "UTGame.UTUIDataStore_StringList.h"
#include "UTGame.UTUIDataProvider_GameModeInfo.h"
#include "GFxUI.GFxClikWidget.h"
#include "Engine.UIDataStore_OnlineGameSettings.h"
#include "GFxUI.GFxObject.h"
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
	class GFxUDKFrontEnd_GameMode : public GFxUDKFrontEnd_Screen
	{
	public:
		ADD_STRUCT(ScriptArray<class UTUIDataProvider_GameModeInfo*>, GameModeList, 268)
		ADD_OBJECT(GFxClikWidget, ImgScrollerMC, 264)
		ADD_OBJECT(GFxObject, MenuMC, 260)
		ADD_OBJECT(GFxObject, ListDataProvider, 256)
		ADD_OBJECT(GFxClikWidget, ListMC, 252)
		ADD_STRUCT(ScriptString*, MapName, 240)
		ADD_STRUCT(ScriptString*, GameMode, 228)
		ADD_OBJECT(UTUIDataStore_StringList, StringListDataStore, 224)
		ADD_OBJECT(UIDataStore_OnlineGameSettings, SettingsDataStore, 220)
		void OnViewLoaded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_GameMode.OnViewLoaded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_GameMode.OnTopMostView");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisableSubComponents(bool bDisableComponents)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_GameMode.DisableSubComponents");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bDisableComponents;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnGameModeSelected(ScriptString* InGameMode, ScriptString* InDefaultMap, ScriptString* InGameSettingsClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_GameMode.OnGameModeSelected");
			byte params[36] = { NULL };
			*(ScriptString**)&params[0] = InGameMode;
			*(ScriptString**)&params[12] = InDefaultMap;
			*(ScriptString**)&params[24] = InGameSettingsClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnGameModeChange(int SelectedIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_GameMode.OnGameModeChange");
			byte params[4] = { NULL };
			*(int*)&params[0] = SelectedIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnListItemPress(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_GameMode.OnListItemPress");
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)&params[0] = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnListChange(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_GameMode.OnListChange");
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)&params[0] = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			*(class GFxClikWidget**)&params[0] = InImgScroller;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ASSetList(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_GameMode.ASSetList");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_GameMode.WidgetInitialized");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = WidgetName;
			*(ScriptName*)&params[8] = WidgetPath;
			*(class GFxObject**)&params[16] = Widget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
