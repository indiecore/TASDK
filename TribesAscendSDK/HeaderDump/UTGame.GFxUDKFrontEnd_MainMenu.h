#pragma once
#include "UTGame.GFxUDKFrontEnd_Screen.h"
#include "GFxUI.GFxClikWidget.h"
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
	class GFxUDKFrontEnd_MainMenu : public GFxUDKFrontEnd_Screen
	{
	public:
		struct Option
		{
		public:
			ADD_STRUCT(ScriptString*, OptionDesc, 24)
			ADD_STRUCT(ScriptString*, OptionLabel, 12)
			ADD_STRUCT(ScriptString*, OptionName, 0)
		};
		ADD_OBJECT(GFxClikWidget, ListMC, 232)
		ADD_STRUCT(ScriptArray<GFxUDKFrontEnd_MainMenu::Option>, ListOptions, 220)
		ADD_STRUCT(byte, LastSelectedIndex, 248)
		ADD_OBJECT(GFxObject, UserNameTxt, 244)
		ADD_OBJECT(GFxObject, UserLabelTxt, 240)
		ADD_OBJECT(GFxObject, ListDataProvider, 236)
		void OnViewLoaded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38595);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38596);
			byte params[4] = { NULL };
			*(bool*)params = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisableSubComponents(bool bDisableComponents)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38598);
			byte params[4] = { NULL };
			*(bool*)params = bDisableComponents;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Select_InstantAction()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38600);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Select_Multiplayer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38601);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Select_ExitGame()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38602);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ExitDialog_SelectOK(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38604);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ExitDialog_SelectBack(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38606);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnListItemPress(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38608);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnListChange(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38612);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateDescription()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38614);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateListDataProvider()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38617);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetList(class GFxObject* InList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38621);
			byte params[4] = { NULL };
			*(class GFxObject**)params = InList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnEscapeKeyPress()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38623);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38624);
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
