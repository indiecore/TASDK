#pragma once
#include "UTGame__UTGFxTweenableMoviePlayer.h"
#include "GFxUI__GFxClikWidget.h"
#include "GFxUI__GFxObject.h"
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
		// Here lies the not-yet-implemented method 'Start'
		// Here lies the not-yet-implemented method 'OnPressResumeButton'
		// Here lies the not-yet-implemented method 'OnPressExitButton'
		// Here lies the not-yet-implemented method 'PlayOpenAnimation'
		// Here lies the not-yet-implemented method 'PlayCloseAnimation'
		// Here lies the not-yet-implemented method 'OnPlayAnimationComplete'
		// Here lies the not-yet-implemented method 'OnCloseAnimationComplete'
		// Here lies the not-yet-implemented method 'UT_ConsoleCommand'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
