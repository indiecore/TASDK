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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38968);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnViewActivated()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38969);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38970);
			byte params[4] = { NULL };
			*(bool*)params = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisableSubComponents(bool bDisableComponents)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38972);
			byte params[4] = { NULL };
			*(bool*)params = bDisableComponents;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSelectedOptionSet()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38974);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LoadDataFromStore()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38975);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Select_Back(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38985);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SaveState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38987);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetList(class GFxObject* List)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38995);
			byte params[4] = { NULL };
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnListChange(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38997);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnOptionChanged(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38999);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateDescription()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39001);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateListDataProvider()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39004);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int FindLocalizedSettingIndexByName(ScriptString* InSettingName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39005);
			byte params[16] = { NULL };
			*(ScriptString**)params = InSettingName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		void OnEscapeKeyPress()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39011);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Select_BackImpl()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39012);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int FindPropertyIndexByName(ScriptString* InPropertyName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39013);
			byte params[16] = { NULL };
			*(ScriptString**)params = InPropertyName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39019);
			byte params[24] = { NULL };
			*(ScriptName*)params = WidgetName;
			*(ScriptName*)&params[8] = WidgetPath;
			*(class GFxObject**)&params[16] = Widget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
