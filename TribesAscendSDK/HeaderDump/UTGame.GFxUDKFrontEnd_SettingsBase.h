#pragma once
#include "UTGame.GFxUDKFrontEnd_Screen.h"
#include "GFxUI.GFxObject.h"
#include "Engine.UIDataStore_OnlineGameSettings.h"
#include "UTGame.UTUIDataProvider_MenuOption.h"
#include "GFxUI.GFxClikWidget.h"
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
	class GFxUDKFrontEnd_SettingsBase : public GFxUDKFrontEnd_Screen
	{
	public:
		ADD_STRUCT(ScriptArray<class UTUIDataProvider_MenuOption*>, SettingsList, 244)
		ADD_OBJECT(UIDataStore_OnlineGameSettings, SettingsDataStore, 256)
		ADD_OBJECT(GFxObject, MenuMC, 240)
		ADD_OBJECT(GFxObject, ListDataProvider, 236)
		ADD_STRUCT(ScriptString*, SelectedOptionSet, 224)
		ADD_OBJECT(GFxClikWidget, ListMC, 220)
		void OnViewLoaded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_SettingsBase.OnViewLoaded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnViewActivated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_SettingsBase.OnViewActivated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_SettingsBase.OnTopMostView");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisableSubComponents(bool bDisableComponents)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_SettingsBase.DisableSubComponents");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bDisableComponents;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSelectedOptionSet()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_SettingsBase.SetSelectedOptionSet");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LoadDataFromStore()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_SettingsBase.LoadDataFromStore");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Select_Back(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_SettingsBase.Select_Back");
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)&params[0] = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SaveState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_SettingsBase.SaveState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetList(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_SettingsBase.SetList");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnListChange(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_SettingsBase.OnListChange");
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)&params[0] = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnOptionChanged(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_SettingsBase.OnOptionChanged");
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)&params[0] = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateDescription()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_SettingsBase.UpdateDescription");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateListDataProvider()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_SettingsBase.UpdateListDataProvider");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int FindLocalizedSettingIndexByName(ScriptString* InSettingName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_SettingsBase.FindLocalizedSettingIndexByName");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = InSettingName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		void OnEscapeKeyPress()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_SettingsBase.OnEscapeKeyPress");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Select_BackImpl()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_SettingsBase.Select_BackImpl");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int FindPropertyIndexByName(ScriptString* InPropertyName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_SettingsBase.FindPropertyIndexByName");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = InPropertyName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_SettingsBase.WidgetInitialized");
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
