#pragma once
#include "GFxUI__GFxObject.h"
#include "UTGame__GFxUDKFrontEnd_Screen.h"
#include "UTGame__UTUIDataStore_MenuItems.h"
#include "GFxUI__GFxClikWidget.h"
#include "Engine__UIDataStore_OnlineGameSettings.h"
#include "UTGame__UTUIDataStore_StringList.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUDKFrontEnd_LaunchGame." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUDKFrontEnd_LaunchGame." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_LaunchGame : public GFxUDKFrontEnd_Screen
	{
	public:
		ADD_OBJECT(GFxObject, MutatorsLabelTxt)
		ADD_OBJECT(GFxObject, RespawnLabelTxt)
		ADD_OBJECT(GFxObject, TimeLabelTxt)
		ADD_OBJECT(GFxObject, ScoreLabelTxt)
		ADD_OBJECT(GFxObject, OpponentsLabelTxt)
		ADD_OBJECT(GFxObject, BotLvlLabelTxt)
		ADD_OBJECT(GFxObject, MapLabelTxt)
		ADD_OBJECT(GFxObject, MutatorsTxt)
		ADD_OBJECT(GFxObject, RespawnTxt)
		ADD_OBJECT(GFxObject, MapTxt)
		ADD_OBJECT(GFxObject, TimeTxt)
		ADD_OBJECT(GFxObject, ScoreTxt)
		ADD_OBJECT(GFxObject, OpponentsTxt)
		ADD_OBJECT(GFxObject, BotLvlTxt)
		ADD_OBJECT(GFxObject, GameTitleTxt)
		ADD_OBJECT(GFxObject, MapNameTxt)
		ADD_OBJECT(GFxObject, MapImageMC)
		ADD_OBJECT(GFxObject, MenuMC)
		ADD_OBJECT(GFxObject, ListDataProvider)
		ADD_OBJECT(GFxClikWidget, ListMC)
		ADD_VAR(::StrProperty, DefaultGameModePrefixes, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DefaultMapImage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DefaultGameModeSettings, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DefaultGameMode, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DefaultMapName, 0xFFFFFFFF)
		ADD_OBJECT(UTUIDataStore_MenuItems, MenuDataStore)
		ADD_OBJECT(UTUIDataStore_StringList, StringListDataStore)
		ADD_OBJECT(UIDataStore_OnlineGameSettings, SettingsDataStore)
		// Here lies the not-yet-implemented method 'GetGameModeFriendlyString'
		// Here lies the not-yet-implemented method 'OnViewLoaded'
		// Here lies the not-yet-implemented method 'OnViewActivated'
		// Here lies the not-yet-implemented method 'DisableSubComponents'
		// Here lies the not-yet-implemented method 'OnTopMostView'
		// Here lies the not-yet-implemented method 'UpdateGameSettingsPanel'
		// Here lies the not-yet-implemented method 'PlayOpenAnimation'
		// Here lies the not-yet-implemented method 'PlayCloseAnimation'
		// Here lies the not-yet-implemented method 'OnStartGame_Confirm'
		// Here lies the not-yet-implemented method 'OnListItemPress'
		// Here lies the not-yet-implemented method 'OnListChange'
		// Here lies the not-yet-implemented method 'UpdateDescription'
		// Here lies the not-yet-implemented method 'UpdateListDataProvider'
		// Here lies the not-yet-implemented method 'WidgetInitialized'
		// Here lies the not-yet-implemented method 'GetStringFromMarkup'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
