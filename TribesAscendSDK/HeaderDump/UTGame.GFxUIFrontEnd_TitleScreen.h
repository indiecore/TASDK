#pragma once
#include "GFxUI.GFxMoviePlayer.h"
#include "GFxUI.GFxClikWidget.h"
#include "GFxUI.GFxClikWidget.EventData.h"
#include "GFxUI.GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUIFrontEnd_TitleScreen." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUIFrontEnd_TitleScreen." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUIFrontEnd_TitleScreen : public GFxMoviePlayer
	{
	public:
		ADD_VAR(::ByteProperty, Selection, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CampaignMap, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, InstantActionMap, 0xFFFFFFFF)
		ADD_OBJECT(GFxClikWidget, MenuBtn6MC)
		ADD_OBJECT(GFxClikWidget, MenuBtn5MC)
		ADD_OBJECT(GFxClikWidget, MenuBtn4MC)
		ADD_OBJECT(GFxClikWidget, MenuBtn3MC)
		ADD_OBJECT(GFxClikWidget, MenuBtn2MC)
		ADD_OBJECT(GFxClikWidget, MenuBtn1MC)
		ADD_OBJECT(GFxObject, BlackMC)
		ADD_OBJECT(GFxObject, MenuButtonsMC)
		ADD_OBJECT(GFxObject, MainMenuMC)
		ADD_OBJECT(GFxObject, TitleScreenMC)
		bool Start(bool StartPaused)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIFrontEnd_TitleScreen.Start");
			byte* params = (byte*)malloc(8);
			*(bool*)params = StartPaused;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool FilterButtonInput(int ControllerId, ScriptName ButtonName, byte InputEvent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIFrontEnd_TitleScreen.FilterButtonInput");
			byte* params = (byte*)malloc(17);
			*(int*)params = ControllerId;
			*(ScriptName*)(params + 4) = ButtonName;
			*(params + 12) = InputEvent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void OnMenuButtonPress(EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIFrontEnd_TitleScreen.OnMenuButtonPress");
			byte* params = (byte*)malloc(36);
			*(EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void UT_ConsoleCommand(ScriptArray<wchar_t> Cmd, bool bWriteToLog)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIFrontEnd_TitleScreen.UT_ConsoleCommand");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Cmd;
			*(bool*)(params + 12) = bWriteToLog;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
