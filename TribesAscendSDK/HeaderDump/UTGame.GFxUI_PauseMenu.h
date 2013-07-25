#pragma once
#include "UTGame.UTGFxTweenableMoviePlayer.h"
#include "GFxUI.GFxClikWidget.h"
#include "GFxUI.GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUI_PauseMenu." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUI_PauseMenu." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUI_PauseMenu : public UTGFxTweenableMoviePlayer
	{
	public:
		ADD_VAR(::StrProperty, ExitString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ResumeString, 0xFFFFFFFF)
		ADD_OBJECT(GFxClikWidget, Btn_ExitMC)
		ADD_OBJECT(GFxClikWidget, Btn_ResumeMC)
		ADD_OBJECT(GFxObject, Btn_Family_Wrapper)
		ADD_OBJECT(GFxObject, Btn_Exit_Wrapper)
		ADD_OBJECT(GFxObject, Btn_Resume_Wrapper)
		ADD_OBJECT(GFxObject, OverlayMC)
		ADD_OBJECT(GFxObject, PauseMC)
		ADD_OBJECT(GFxObject, RootMC)
		bool Start(bool StartPaused)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUI_PauseMenu.Start");
			byte* params = (byte*)malloc(8);
			*(bool*)params = StartPaused;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void OnPressResumeButton(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxClikWidget.EventData'!
void* ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUI_PauseMenu.OnPressResumeButton");
			byte* params = (byte*)malloc(36);
			*(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxClikWidget.EventData'!
void**)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPressExitButton(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxClikWidget.EventData'!
void* ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUI_PauseMenu.OnPressExitButton");
			byte* params = (byte*)malloc(36);
			*(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxClikWidget.EventData'!
void**)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void UT_ConsoleCommand(ScriptArray<wchar_t> Cmd, bool bWriteToLog)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUI_PauseMenu.UT_ConsoleCommand");
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
