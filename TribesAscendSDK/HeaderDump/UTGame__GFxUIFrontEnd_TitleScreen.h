#pragma once
#include "GFxUI__GFxMoviePlayer.h"
#include "GFxUI__GFxClikWidget.h"
#include "GFxUI__GFxObject.h"
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
		// Here lies the not-yet-implemented method 'Start'
		// Here lies the not-yet-implemented method 'FilterButtonInput'
		// Here lies the not-yet-implemented method 'OnMenuButtonPress'
		// Here lies the not-yet-implemented method 'PlayCloseAnimation'
		// Here lies the not-yet-implemented method 'OnCloseAnimationComplete'
		// Here lies the not-yet-implemented method 'UT_ConsoleCommand'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
