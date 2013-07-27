#pragma once
#include "UTGame.UTGFxTweenableMoviePlayer.h"
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
	class GFxUI_PauseMenu : public UTGFxTweenableMoviePlayer
	{
	public:
		ADD_STRUCT(ScriptString*, ExitString, 436)
		ADD_STRUCT(ScriptString*, ResumeString, 424)
		ADD_OBJECT(GFxClikWidget, Btn_ExitMC, 420)
		ADD_OBJECT(GFxClikWidget, Btn_ResumeMC, 416)
		ADD_OBJECT(GFxObject, Btn_Family_Wrapper, 412)
		ADD_OBJECT(GFxObject, Btn_Exit_Wrapper, 408)
		ADD_OBJECT(GFxObject, Btn_Resume_Wrapper, 404)
		ADD_OBJECT(GFxObject, OverlayMC, 400)
		ADD_OBJECT(GFxObject, PauseMC, 396)
		ADD_OBJECT(GFxObject, RootMC, 392)
		bool Start(bool StartPaused)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUI_PauseMenu.Start");
			byte params[8] = { NULL };
			*(bool*)&params[0] = StartPaused;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void OnPressResumeButton(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUI_PauseMenu.OnPressResumeButton");
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)&params[0] = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPressExitButton(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUI_PauseMenu.OnPressExitButton");
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)&params[0] = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayOpenAnimation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUI_PauseMenu.PlayOpenAnimation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayCloseAnimation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUI_PauseMenu.PlayCloseAnimation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnPlayAnimationComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUI_PauseMenu.OnPlayAnimationComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnCloseAnimationComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUI_PauseMenu.OnCloseAnimationComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UT_ConsoleCommand(ScriptString* Cmd, bool bWriteToLog)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUI_PauseMenu.UT_ConsoleCommand");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Cmd;
			*(bool*)&params[12] = bWriteToLog;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
