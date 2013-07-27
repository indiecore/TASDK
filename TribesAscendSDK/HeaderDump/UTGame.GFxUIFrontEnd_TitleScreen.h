#pragma once
#include "GFxUI.GFxMoviePlayer.h"
#include "GFxUI.GFxClikWidget.h"
#include "Core.Object.h"
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
	class GFxUIFrontEnd_TitleScreen : public GFxMoviePlayer
	{
	public:
		enum MenuButtonsType : byte
		{
			MENU_BTN_CAMPAIGN = 0,
			MENU_BTN_INSTANTACTION = 1,
			MENU_BTN_MULTIPLAYER = 2,
			MENU_BTN_COMMUNITY = 3,
			MENU_BTN_SETTINGS = 4,
			MENU_BTN_EXIT = 5,
			MENU_BTN_LOGOUT = 6,
			MENU_BTN_SELECT = 7,
			MENU_BTN_MAX = 8,
		};
		ADD_STRUCT(byte, Selection, 444)
		ADD_STRUCT(ScriptString*, CampaignMap, 432)
		ADD_STRUCT(ScriptString*, InstantActionMap, 420)
		ADD_OBJECT(GFxClikWidget, MenuBtn6MC, 416)
		ADD_OBJECT(GFxClikWidget, MenuBtn5MC, 412)
		ADD_OBJECT(GFxClikWidget, MenuBtn4MC, 408)
		ADD_OBJECT(GFxClikWidget, MenuBtn3MC, 404)
		ADD_OBJECT(GFxClikWidget, MenuBtn2MC, 400)
		ADD_OBJECT(GFxClikWidget, MenuBtn1MC, 396)
		ADD_OBJECT(GFxObject, BlackMC, 392)
		ADD_OBJECT(GFxObject, MenuButtonsMC, 388)
		ADD_OBJECT(GFxObject, MainMenuMC, 384)
		ADD_OBJECT(GFxObject, TitleScreenMC, 380)
		bool Start(bool StartPaused)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIFrontEnd_TitleScreen.Start");
			byte params[8] = { NULL };
			*(bool*)&params[0] = StartPaused;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool FilterButtonInput(int ControllerId, ScriptName ButtonName, Object::EInputEvent InputEvent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIFrontEnd_TitleScreen.FilterButtonInput");
			byte params[17] = { NULL };
			*(int*)&params[0] = ControllerId;
			*(ScriptName*)&params[4] = ButtonName;
			*(Object::EInputEvent*)&params[12] = InputEvent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void OnMenuButtonPress(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIFrontEnd_TitleScreen.OnMenuButtonPress");
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)&params[0] = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayCloseAnimation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIFrontEnd_TitleScreen.PlayCloseAnimation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnCloseAnimationComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIFrontEnd_TitleScreen.OnCloseAnimationComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UT_ConsoleCommand(ScriptString* Cmd, bool bWriteToLog)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIFrontEnd_TitleScreen.UT_ConsoleCommand");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Cmd;
			*(bool*)&params[12] = bWriteToLog;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
