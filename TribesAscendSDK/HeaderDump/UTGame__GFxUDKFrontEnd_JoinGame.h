#pragma once
#include "GFxUI__GFxObject.h"
#include "UTGame__GFxUDKFrontEnd_Screen.h"
#include "UTGame__GFxUDKFrontEnd_JoinDialog.h"
#include "UDKBase__UDKDataStore_GameSearchBase.h"
#include "UTGame__UTUIDataStore_StringList.h"
#include "GFxUI__GFxClikWidget.h"
#include "UTGame__GFxUDKFrontEnd_PasswordDialog.h"
#include "UTGame__UTUIDataStore_MenuItems.h"
#include "Engine__OnlineSubsystem.h"
#include "UTGame__UTDataStore_GameSearchDM.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUDKFrontEnd_JoinGame." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUDKFrontEnd_JoinGame." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_JoinGame : public GFxUDKFrontEnd_Screen
	{
	public:
		ADD_OBJECT(UDKDataStore_GameSearchBase, SearchDataStore)
		ADD_VAR(::NameProperty, SearchDSName, 0xFFFFFFFF)
		ADD_OBJECT(UTUIDataStore_StringList, StringListDataStore)
		ADD_OBJECT(UTUIDataStore_MenuItems, MenuItemDataStore)
		ADD_OBJECT(OnlineSubsystem, OnlineSub)
		ADD_OBJECT(GFxClikWidget, FlagsHeaderBtn)
		ADD_OBJECT(GFxClikWidget, ServerHeaderBtn)
		ADD_OBJECT(GFxClikWidget, MapHeaderBtn)
		ADD_OBJECT(GFxClikWidget, PlayersHeaderBtn)
		ADD_OBJECT(GFxClikWidget, PingHeaderBtn)
		ADD_VAR(::BoolProperty, bGametypeOutdated, 0x1)
		ADD_VAR(::BoolProperty, bIssuedInitialQuery, 0x4)
		ADD_OBJECT(GFxClikWidget, RefreshBtn)
		ADD_OBJECT(GFxClikWidget, ServerListMC)
		ADD_OBJECT(GFxObject, FilterMatchTypeTxt)
		ADD_OBJECT(GFxObject, FilterGameModeTxt)
		ADD_OBJECT(GFxUDKFrontEnd_PasswordDialog, PasswordDialog)
		ADD_VAR(::StrProperty, ServerPassword, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, StatusTxt)
		ADD_OBJECT(GFxObject, ServerCountTxt)
		ADD_VAR(::BoolProperty, bSpectate, 0x2)
		ADD_VAR(::ByteProperty, QueryCompletionAction, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bQueryDialogShowing, 0x8)
		ADD_OBJECT(GFxObject, HeaderBarMC)
		ADD_VAR(::IntProperty, SelectedIndex, 0xFFFFFFFF)
		ADD_OBJECT(GFxUDKFrontEnd_JoinDialog, JoinDialogMC)
		ADD_VAR(::BoolProperty, bJoinDialogShowing, 0x10)
		ADD_VAR(::BoolProperty, bProcessingJoin, 0x20)
		ADD_OBJECT(GFxObject, LoadingTickerMC)
		ADD_OBJECT(GFxObject, MenuMC)
		ADD_OBJECT(GFxClikWidget, FilterBtn)
		ADD_OBJECT(UTDataStore_GameSearchDM, SearchDMDataStore)
		ADD_VAR(::IntProperty, LastServerAdded, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'OnViewLoaded'
		// Here lies the not-yet-implemented method 'OnViewActivated'
		// Here lies the not-yet-implemented method 'ForceLANOption'
		// Here lies the not-yet-implemented method 'UpdateFilterButton'
		// Here lies the not-yet-implemented method 'OnTopMostView'
		// Here lies the not-yet-implemented method 'OnViewClosed'
		// Here lies the not-yet-implemented method 'DisableSubComponents'
		// Here lies the not-yet-implemented method 'ValidateServerType'
		// Here lies the not-yet-implemented method 'Cleanup'
		// Here lies the not-yet-implemented method 'GetGameTypeSearchProviderIndex'
		// Here lies the not-yet-implemented method 'OnGameTypeChanged'
		// Here lies the not-yet-implemented method 'ConditionalRefreshServerList'
		// Here lies the not-yet-implemented method 'UseLANMode'
		// Here lies the not-yet-implemented method 'UpdateButtonStates'
		// Here lies the not-yet-implemented method 'PromptForServerPassword'
		// Here lies the not-yet-implemented method 'StripInvalidPasswordCharacters'
		// Here lies the not-yet-implemented method 'OnPasswordDialog_OK'
		// Here lies the not-yet-implemented method 'ProcessJoin'
		// Here lies the not-yet-implemented method 'UpdateServerCount'
		// Here lies the not-yet-implemented method 'BuildJoinURL'
		// Here lies the not-yet-implemented method 'RefreshServerList'
		// Here lies the not-yet-implemented method 'SubmitServerListQuery'
		// Here lies the not-yet-implemented method 'OnFindOnlineGamesCompleteDelegate'
		// Here lies the not-yet-implemented method 'OnFindOnlineGamesComplete'
		// Here lies the not-yet-implemented method 'GetDesiredMatchType'
		// Here lies the not-yet-implemented method 'OnRefreshButtonPress'
		// Here lies the not-yet-implemented method 'OnFilterButtonPress'
		// Here lies the not-yet-implemented method 'ServerFilterChangedGameType'
		// Here lies the not-yet-implemented method 'UpdateListDataProvider'
		// Here lies the not-yet-implemented method 'OnServerHeaderPress'
		// Here lies the not-yet-implemented method 'OnMapHeaderPress'
		// Here lies the not-yet-implemented method 'OnPlayersHeaderPress'
		// Here lies the not-yet-implemented method 'OnPingHeaderPress'
		// Here lies the not-yet-implemented method 'OnServerListItemPress'
		// Here lies the not-yet-implemented method 'SpectateServer'
		// Here lies the not-yet-implemented method 'JoinServerClikListener'
		// Here lies the not-yet-implemented method 'JoinServer'
		// Here lies the not-yet-implemented method 'OnJoinGameComplete'
		// Here lies the not-yet-implemented method 'AllowJoinServer'
		// Here lies the not-yet-implemented method 'CancelQuery'
		// Here lies the not-yet-implemented method 'SetRefreshing'
		// Here lies the not-yet-implemented method 'OnCancelSearchComplete'
		// Here lies the not-yet-implemented method 'NotifyGameTypeChanged'
		// Here lies the not-yet-implemented method 'WidgetInitialized'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
