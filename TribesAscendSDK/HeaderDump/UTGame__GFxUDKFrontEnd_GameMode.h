#pragma once
#include "GFxUI__GFxObject.h"
#include "UTGame__GFxUDKFrontEnd_Screen.h"
#include "GFxUI__GFxClikWidget.h"
#include "Engine__UIDataStore_OnlineGameSettings.h"
#include "UTGame__UTUIDataStore_StringList.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUDKFrontEnd_GameMode." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUDKFrontEnd_GameMode." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_GameMode : public GFxUDKFrontEnd_Screen
	{
	public:
		ADD_OBJECT(GFxClikWidget, ImgScrollerMC)
		ADD_OBJECT(GFxObject, MenuMC)
		ADD_OBJECT(GFxObject, ListDataProvider)
		ADD_OBJECT(GFxClikWidget, ListMC)
		ADD_VAR(::StrProperty, MapName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, GameMode, 0xFFFFFFFF)
		ADD_OBJECT(UTUIDataStore_StringList, StringListDataStore)
		ADD_OBJECT(UIDataStore_OnlineGameSettings, SettingsDataStore)
		// Here lies the not-yet-implemented method 'OnViewLoaded'
		// Here lies the not-yet-implemented method 'OnTopMostView'
		// Here lies the not-yet-implemented method 'DisableSubComponents'
		// Here lies the not-yet-implemented method 'OnGameModeSelected'
		// Here lies the not-yet-implemented method 'OnGameModeChange'
		// Here lies the not-yet-implemented method 'OnListItemPress'
		// Here lies the not-yet-implemented method 'OnListChange'
		// Here lies the not-yet-implemented method 'UpdateDescription'
		// Here lies the not-yet-implemented method 'UpdateListDataProvider'
		// Here lies the not-yet-implemented method 'SetImgScroller'
		// Here lies the not-yet-implemented method 'ASSetList'
		// Here lies the not-yet-implemented method 'WidgetInitialized'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
