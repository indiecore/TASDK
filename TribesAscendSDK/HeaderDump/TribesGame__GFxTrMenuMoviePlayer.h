#pragma once
#include "Engine__OnlineSubsystem.h"
#include "GFxUI__GFxMoviePlayer.h"
#include "TribesGame__TrUser.h"
#include "TribesGame__TrStreamManager.h"
#include "TribesGame__GFxTrMenuSounds.h"
#include "GFxUI__GFxObject.h"
#include "PlatformCommon__TgPlayerProfile.h"
#include "TribesGame__GFxTrScene_EULA.h"
#include "TribesGame__TrStrings.h"
#include "TribesGame__TrInventoryHelper.h"
#include "TribesGame__TrPageManager.h"
#include "TribesGame__TrEquipInterface.h"
#include "TribesGame__TrBrowserManager.h"
#include "TribesGame__GFxTrScene_MatchSummary.h"
#include "TribesGame__TrLoginManager.h"
#include "TribesGame__TrQueueManager.h"
#include "TribesGame__TrPartyManager.h"
#include "TribesGame__TrLoadingData.h"
#include "TribesGame__TrSettingsManager.h"
#include "TribesGame__TrRibbonManager.h"
#include "TribesGame__TrFriendManager.h"
#include "TribesGame__GFxTrScene_PlayerSummary.h"
#include "TribesGame__TrHUD.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrMenuMoviePlayer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.GFxTrMenuMoviePlayer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.GFxTrMenuMoviePlayer." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxTrMenuMoviePlayer : public GFxMoviePlayer
	{
	public:
		ADD_VAR(::ByteProperty, m_PopupType, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bInitialized, 0x1000)
		ADD_OBJECT(GFxObject, _global)
		ADD_OBJECT(OnlineSubsystem, OnlineSub)
		ADD_OBJECT(TrUser, User)
		ADD_OBJECT(TrStrings, Strings)
		ADD_OBJECT(TrStreamManager, StreamManager)
		ADD_OBJECT(TrInventoryHelper, EquipHelper)
		ADD_OBJECT(TrEquipInterface, EquipInterface)
		ADD_OBJECT(TgPlayerProfile, PlayerProfile)
		ADD_OBJECT(TrBrowserManager, Browser)
		ADD_OBJECT(TrLoginManager, LoginManager)
		ADD_OBJECT(TrQueueManager, QueueManager)
		ADD_OBJECT(TrPartyManager, PartyManager)
		ADD_OBJECT(TrLoadingData, LoadingData)
		ADD_OBJECT(TrPageManager, Pages)
		ADD_OBJECT(TrSettingsManager, SettingsManager)
		ADD_OBJECT(TrRibbonManager, RibbonManager)
		ADD_OBJECT(TrFriendManager, Friends)
		ADD_OBJECT(GFxTrScene_EULA, EULAScene)
		ADD_OBJECT(GFxTrScene_MatchSummary, MatchSummaryScene)
		ADD_OBJECT(GFxTrScene_PlayerSummary, PlayerSummaryScene)
		ADD_OBJECT(GFxTrMenuSounds, MenuSounds)
		ADD_VAR(::BoolProperty, bStartupCompleted, 0x2)
		ADD_VAR(::BoolProperty, bCreatingNewPlayer, 0x8000)
		ADD_VAR(::BoolProperty, bOpeningMenu, 0x1000)
		ADD_VAR(::BoolProperty, bPeachy, 0x1)
		ADD_VAR(::BoolProperty, bWaitingForEntry, 0x4000)
		ADD_VAR(::BoolProperty, bFullyLoaded, 0x800)
		ADD_VAR(::BoolProperty, bLoggedIn, 0x200)
		ADD_VAR(::BoolProperty, bNeedsEULA, 0x100)
		ADD_VAR(::IntProperty, EstimatedWaitTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWaitingForServerDropPopup, 0x1)
		ADD_VAR(::BoolProperty, bInGame, 0x8)
		ADD_VAR(::BoolProperty, bLoading, 0x10)
		ADD_VAR(::BoolProperty, bEndOfMatch, 0x80)
		ADD_VAR(::BoolProperty, bViewingSummary, 0x10000000)
		ADD_VAR(::BoolProperty, bWelcomed, 0x4)
		ADD_VAR(::BoolProperty, bWaitingForQuitGameConfirm, 0x20000000)
		ADD_VAR(::BoolProperty, bWaitingForLeaveMatchConfirm, 0x40000000)
		ADD_VAR(::StrProperty, LoginFailure, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWaitingForLoginFailedPopup, 0x8)
		ADD_VAR(::BoolProperty, LoginSuccess, 0x20000)
		ADD_VAR(::BoolProperty, bProfileLoaded, 0x4000)
		ADD_VAR(::BoolProperty, bEquipmentLoaded, 0x40000)
		ADD_VAR(::StrProperty, LoginPlayer, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, LoginReason, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRefreshingMenu, 0x2000)
		ADD_VAR(::StrProperty, GenericFailReason, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWaitingForJoinFailed, 0x20)
		ADD_VAR(::BoolProperty, bWaitingForJoinRequiresPassword, 0x40)
		ADD_VAR(::IntProperty, PlayerNameFailType, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWaitingForPlayerNamePopup, 0x4000000)
		ADD_VAR(::IntProperty, Progress, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RankIcon, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NextRank, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bBlockRelease, 0x2000)
		ADD_VAR(::IntProperty, EndOfMatchTimer, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CapturedKey, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWaitingForPopup, 0x80)
		ADD_VAR(::BoolProperty, bChatOpen, 0x200)
		ADD_VAR(::BoolProperty, bBlockHotkey, 0x400)
		ADD_VAR(::StrProperty, UnlockItemName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, UnlockTypeName, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, UnlockIconType, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, UnlockIconId, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWaitingForLoginQueuePopup, 0x80000000)
		ADD_VAR(::BoolProperty, bWaitingForAFKKickPopup, 0x2)
		ADD_VAR(::BoolProperty, bWaitingForPurchaseReturn, 0x10)
		ADD_VAR(::BoolProperty, bWaitingForAddFriendPopup, 0x4)
		ADD_VAR(::StrProperty, PurchaseFailedMsg, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShowPurchaseFailed, 0x100000)
		ADD_VAR(::IntProperty, PurchasingCurrency, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShowPromoCodeFailed, 0x1000000)
		ADD_VAR(::StrProperty, PromoFailReason, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShowGenericFailure, 0x2000000)
		ADD_VAR(::BoolProperty, bWaitingForPlayerNameInput, 0x8000000)
		ADD_VAR(::StrProperty, NameRulesMessage, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.GFxTrMenuMoviePlayer.VendorItemData' for the property named 'PortalPurchase'!
		ADD_VAR(::BoolProperty, bInQueue, 0x20)
		ADD_VAR(::BoolProperty, bQueueListDirty, 0x40)
		ADD_VAR(::BoolProperty, bWebVendorLoaded, 0x10000)
		ADD_VAR(::BoolProperty, bShowDiamondSword, 0x80000)
		ADD_VAR(::BoolProperty, bWaitingForSelectionPopup, 0x200000)
		ADD_VAR(::BoolProperty, bWaitingForCurrencyPopup, 0x400000)
		ADD_VAR(::BoolProperty, bWaitingForConfirmationPopup, 0x800000)
		ADD_VAR(::BoolProperty, bPasswordPopup, 0x100)
		ADD_VAR(::BoolProperty, bInvitationPopup, 0x400)
		ADD_VAR(::BoolProperty, bBadgeModification, 0x800)
		ADD_VAR(::StrProperty, NextMapName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FriendLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FollowerLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OfflineLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OnlineLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, InGameLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, InLobbyLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OKLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CancelLabel, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'DelegateNoParam'
		// Here lies the not-yet-implemented method 'DelegateInt'
		// Here lies the not-yet-implemented method 'DelegateBool'
		// Here lies the not-yet-implemented method 'DelegateString'
		// Here lies the not-yet-implemented method 'DelegateGFxList'
		// Here lies the not-yet-implemented method 'DelegateIntInt'
		// Here lies the not-yet-implemented method 'DelegateIntString'
		// Here lies the not-yet-implemented method 'DelegateStringInt'
		// Here lies the not-yet-implemented method 'DelegateStringBool'
		// Here lies the not-yet-implemented method 'DelegateIntGFxList'
		// Here lies the not-yet-implemented method 'DelegateOnMarshalEvent'
		// Here lies the not-yet-implemented method 'DelegateGetInt'
		// Here lies the not-yet-implemented method 'DelegateGetPrice'
		// Here lies the not-yet-implemented method 'DelegateIntIntInt'
		// Here lies the not-yet-implemented method 'DelegateGetBoolIntInt'
		// Here lies the not-yet-implemented method 'DelegateLogin'
		// Here lies the not-yet-implemented method 'DelegateBoolGetBool'
		// Here lies the not-yet-implemented method 'DelegateGetString'
		// Here lies the not-yet-implemented method 'DelegateOptions'
		// Here lies the not-yet-implemented method 'DelegateAction'
		// Here lies the not-yet-implemented method 'UseSteam'
		// Here lies the not-yet-implemented method 'RequestPurchaseSteamItem'
		// Here lies the not-yet-implemented method 'RequestSteamUserData'
		// Here lies the not-yet-implemented method 'GetGoldItemInfo'
		// Here lies the not-yet-implemented method 'UsePortal'
		// Here lies the not-yet-implemented method 'GetPortalBalance'
		// Here lies the not-yet-implemented method 'GetPortalCurrencyName'
		// Here lies the not-yet-implemented method 'RequestPurchasePortalItem'
		// Here lies the not-yet-implemented method 'CheckAutoLoginStatus'
		// Here lies the not-yet-implemented method 'PurchasedItem'
		// Here lies the not-yet-implemented method 'OnMarshalEvent'
		// Here lies the not-yet-implemented method 'ReadPlayerProfileData'
		// Here lies the not-yet-implemented method 'UserLoginChanged'
		// Here lies the not-yet-implemented method 'RegisterMarshalCallback'
		// Here lies the not-yet-implemented method 'GetVersionString'
		// Here lies the not-yet-implemented method 'ForceFocus'
		// Here lies the not-yet-implemented method 'AddAcquisition'
		// Here lies the not-yet-implemented method 'GetQueueUIInfo'
		// Here lies the not-yet-implemented method 'GetLanguageFontIndex'
		// Here lies the not-yet-implemented method 'RequestStreams'
		// Here lies the not-yet-implemented method 'GetEquipmentXP'
		// Here lies the not-yet-implemented method 'GetEquipmentTierXP'
		// Here lies the not-yet-implemented method 'HaveClanTag'
		// Here lies the not-yet-implemented method 'Start'
		// Here lies the not-yet-implemented method 'SetLoginDelegate'
		// Here lies the not-yet-implemented method 'SetSubmitPlayerNameDelegate'
		// Here lies the not-yet-implemented method 'SetLoadTeamMiscDataDelegate'
		// Here lies the not-yet-implemented method 'SetLoadTeamScoreboardDataDelegate'
		// Here lies the not-yet-implemented method 'SetLoadTeamStatsDataDelegate'
		// Here lies the not-yet-implemented method 'SetLoadTeamAccoladeDataDelegate'
		// Here lies the not-yet-implemented method 'SetLoadPlayerMiscDataDelegate'
		// Here lies the not-yet-implemented method 'SetLoadPlayerStatsDataDelegate'
		// Here lies the not-yet-implemented method 'SetLoadPlayerAccoladeDataDelegate'
		// Here lies the not-yet-implemented method 'SetAcceptEULADelegate'
		// Here lies the not-yet-implemented method 'SetSoundXPGain'
		// Here lies the not-yet-implemented method 'SetSoundClassType'
		// Here lies the not-yet-implemented method 'SetSoundSkillType'
		// Here lies the not-yet-implemented method 'SetEscapeClass'
		// Here lies the not-yet-implemented method 'SetExitGameDelegate'
		// Here lies the not-yet-implemented method 'SetGetPlatformDelegate'
		// Here lies the not-yet-implemented method 'SetGetViewModeDelegate'
		// Here lies the not-yet-implemented method 'SetShowSummaryDelegate'
		// Here lies the not-yet-implemented method 'SetAlertDelegate'
		// Here lies the not-yet-implemented method 'SetBrowserGoldDelegate'
		// Here lies the not-yet-implemented method 'SetBrowserStoreDelegate'
		// Here lies the not-yet-implemented method 'SetBrowserSupportDelegate'
		// Here lies the not-yet-implemented method 'SetBrowserProfileDelegate'
		// Here lies the not-yet-implemented method 'SetBrowserBoosterDelegate'
		// Here lies the not-yet-implemented method 'SetBrowserClassVideoDelegate'
		// Here lies the not-yet-implemented method 'SetBrowserActivateKeyDelegate'
		// Here lies the not-yet-implemented method 'SetBrowserCreateAccountDelegate'
		// Here lies the not-yet-implemented method 'SetBrowserRecoverPasswordDelegate'
		// Here lies the not-yet-implemented method 'SetBrowserRecoverUsernameDelegate'
		// Here lies the not-yet-implemented method 'SetExitQueueDelegate'
		// Here lies the not-yet-implemented method 'SetJoinCustomServerDelegate'
		// Here lies the not-yet-implemented method 'SetFavoriteServerDelegate'
		// Here lies the not-yet-implemented method 'SetPasswordServerDelegate'
		// Here lies the not-yet-implemented method 'SetServerPageDelegate'
		// Here lies the not-yet-implemented method 'SetServerSortDelegate'
		// Here lies the not-yet-implemented method 'SetReticuleActionDelegate'
		// Here lies the not-yet-implemented method 'SetSaveReticuleDelegate'
		// Here lies the not-yet-implemented method 'SetRequestNewsDelegate'
		// Here lies the not-yet-implemented method 'SetStartLoginDelegate'
		// Here lies the not-yet-implemented method 'SetSmoothAnimDelegate'
		// Here lies the not-yet-implemented method 'ASC_SetFontIndex'
		// Here lies the not-yet-implemented method 'ASC_Resize'
		// Here lies the not-yet-implemented method 'SetPopupDataDelegate'
		// Here lies the not-yet-implemented method 'SetPopupCompleteDelegate'
		// Here lies the not-yet-implemented method 'SetFocusedActionDelegate'
		// Here lies the not-yet-implemented method 'SetSelectedActionDelegate'
		// Here lies the not-yet-implemented method 'SetModifiedActionDelegate'
		// Here lies the not-yet-implemented method 'SetModifyFocusDelegate'
		// Here lies the not-yet-implemented method 'SetActionUpDelegate'
		// Here lies the not-yet-implemented method 'SetActionDownDelegate'
		// Here lies the not-yet-implemented method 'SetHelpButtonDelegate'
		// Here lies the not-yet-implemented method 'SetProfilePageUpDelegate'
		// Here lies the not-yet-implemented method 'SetProfilePageDownDelegate'
		// Here lies the not-yet-implemented method 'SetMutePlayerDelegate'
		// Here lies the not-yet-implemented method 'SetSummaryActionDelegate'
		// Here lies the not-yet-implemented method 'SetFriendPlayerDelegate'
		// Here lies the not-yet-implemented method 'SetLoadXPSummaryDelegate'
		// Here lies the not-yet-implemented method 'SetPromoActionDelegate'
		// Here lies the not-yet-implemented method 'SetSelectedFeatureDelegate'
		// Here lies the not-yet-implemented method 'CompleteStartup'
		// Here lies the not-yet-implemented method 'SummaryAction'
		// Here lies the not-yet-implemented method 'StartMainMenu'
		// Here lies the not-yet-implemented method 'ToggleMutePlayer'
		// Here lies the not-yet-implemented method 'StripTag'
		// Here lies the not-yet-implemented method 'StartPeach'
		// Here lies the not-yet-implemented method 'StartLogin'
		// Here lies the not-yet-implemented method 'ShowPeach'
		// Here lies the not-yet-implemented method 'ASC_ShowPeach'
		// Here lies the not-yet-implemented method 'EntryPlayerReady'
		// Here lies the not-yet-implemented method 'HaveEntry'
		// Here lies the not-yet-implemented method 'SetPlayerMainMenu'
		// Here lies the not-yet-implemented method 'ClosePopup'
		// Here lies the not-yet-implemented method 'SetPlayerInLogin'
		// Here lies the not-yet-implemented method 'QueuePopup'
		// Here lies the not-yet-implemented method 'SetPlayerInLobby'
		// Here lies the not-yet-implemented method 'ASC_StopLoading'
		// Here lies the not-yet-implemented method 'SetPlayerLoading'
		// Here lies the not-yet-implemented method 'ASC_GotoState'
		// Here lies the not-yet-implemented method 'SetPlayerInGame'
		// Here lies the not-yet-implemented method 'SetEndOfMatch'
		// Here lies the not-yet-implemented method 'ShowSummary'
		// Here lies the not-yet-implemented method 'Escape'
		// Here lies the not-yet-implemented method 'CloseClasses'
		// Here lies the not-yet-implemented method 'OpenMenu'
		// Here lies the not-yet-implemented method 'OpenClasses'
		// Here lies the not-yet-implemented method 'OpenFriends'
		// Here lies the not-yet-implemented method 'OpenSettings'
		// Here lies the not-yet-implemented method 'QuitGame'
		// Here lies the not-yet-implemented method 'LeaveMatch'
		// Here lies the not-yet-implemented method 'QuitGamePopup'
		// Here lies the not-yet-implemented method 'LeaveMatchPopup'
		// Here lies the not-yet-implemented method 'QuitGamePopupComplete'
		// Here lies the not-yet-implemented method 'LeaveMatchPopupComplete'
		// Here lies the not-yet-implemented method 'Quit'
		// Here lies the not-yet-implemented method 'SendPlayerLogin'
		// Here lies the not-yet-implemented method 'AlienMenu'
		// Here lies the not-yet-implemented method 'OnProfileLoaded'
		// Here lies the not-yet-implemented method 'IsLoadComplete'
		// Here lies the not-yet-implemented method 'SendBack'
		// Here lies the not-yet-implemented method 'EquipmentLoaded'
		// Here lies the not-yet-implemented method 'EquipmentChanged'
		// Here lies the not-yet-implemented method 'RefreshPage'
		// Here lies the not-yet-implemented method 'SwapModel'
		// Here lies the not-yet-implemented method 'JoinFailed'
		// Here lies the not-yet-implemented method 'DisplayJoinFailed'
		// Here lies the not-yet-implemented method 'JoinRequiresPassword'
		// Here lies the not-yet-implemented method 'JoinRequiresPasswordComplete'
		// Here lies the not-yet-implemented method 'CheckRibbons'
		// Here lies the not-yet-implemented method 'ProfileUpdated'
		// Here lies the not-yet-implemented method 'ASC_ProfileUpdated'
		// Here lies the not-yet-implemented method 'ExitPopup'
		// Here lies the not-yet-implemented method 'ASC_PopupError'
		// Here lies the not-yet-implemented method 'DisplayEULA'
		// Here lies the not-yet-implemented method 'ASC_HideLogin'
		// Here lies the not-yet-implemented method 'ASC_FillEULAText'
		// Here lies the not-yet-implemented method 'CreateNewPlayer'
		// Here lies the not-yet-implemented method 'PlayerNameNotAllowed'
		// Here lies the not-yet-implemented method 'GetUserSelectedClass'
		// Here lies the not-yet-implemented method 'FillProfileData'
		// Here lies the not-yet-implemented method 'SendProfileData'
		// Here lies the not-yet-implemented method 'ASC_FillProfile'
		// Here lies the not-yet-implemented method 'GetBoostLabel'
		// Here lies the not-yet-implemented method 'GetRankFromXP'
		// Here lies the not-yet-implemented method 'WidgetInitialized'
		// Here lies the not-yet-implemented method 'RestorePlayerHUD'
		// Here lies the not-yet-implemented method 'GetPlatform'
		// Here lies the not-yet-implemented method 'GetViewMode'
		// Here lies the not-yet-implemented method 'ShowMovie'
		// Here lies the not-yet-implemented method 'HideMovie'
		// Here lies the not-yet-implemented method 'ASC_HideMovie'
		// Here lies the not-yet-implemented method 'ChatMessageReceived'
		// Here lies the not-yet-implemented method 'UpdateStatus'
		// Here lies the not-yet-implemented method 'SetCountdownTimer'
		// Here lies the not-yet-implemented method 'LoadingTimer'
		// Here lies the not-yet-implemented method 'RequestPaperDoll'
		// Here lies the not-yet-implemented method 'KeyBindCaptured'
		// Here lies the not-yet-implemented method 'KeyPressCaptured'
		// Here lies the not-yet-implemented method 'TeamSelectActive'
		// Here lies the not-yet-implemented method 'TeamSelectOpen'
		// Here lies the not-yet-implemented method 'PlayerNeedsTeam'
		// Here lies the not-yet-implemented method 'PlayerNeedsClass'
		// Here lies the not-yet-implemented method 'GetPlayerHUD'
		// Here lies the not-yet-implemented method 'StartHotkeyBlock'
		// Here lies the not-yet-implemented method 'EndHotkeyBlock'
		// Here lies the not-yet-implemented method 'UnlockedItem'
		// Here lies the not-yet-implemented method 'UnlockedGold'
		// Here lies the not-yet-implemented method 'UnlockedXP'
		// Here lies the not-yet-implemented method 'UnlockedBooster'
		// Here lies the not-yet-implemented method 'UnlockedBadge'
		// Here lies the not-yet-implemented method 'UnlockedNameChange'
		// Here lies the not-yet-implemented method 'UnlockedVIP'
		// Here lies the not-yet-implemented method 'UnlockedServerTime'
		// Here lies the not-yet-implemented method 'UnlockedClanTag'
		// Here lies the not-yet-implemented method 'UnlockedSkill'
		// Here lies the not-yet-implemented method 'WinOfTheDay'
		// Here lies the not-yet-implemented method 'ClaimedPromotion'
		// Here lies the not-yet-implemented method 'CheckVIPForLogin'
		// Here lies the not-yet-implemented method 'ReadyAcquisition'
		// Here lies the not-yet-implemented method 'DisplayAcquisitions'
		// Here lies the not-yet-implemented method 'FireAcquisitions'
		// Here lies the not-yet-implemented method 'ASC_UnlockedItem'
		// Here lies the not-yet-implemented method 'KickVoteFeedback'
		// Here lies the not-yet-implemented method 'PlayerInLoginQueue'
		// Here lies the not-yet-implemented method 'LoginQueuePopupData'
		// Here lies the not-yet-implemented method 'LoginQueuePopupComplete'
		// Here lies the not-yet-implemented method 'ServerDropPopupData'
		// Here lies the not-yet-implemented method 'AFKKickPopupData'
		// Here lies the not-yet-implemented method 'LoginFailedPopup'
		// Here lies the not-yet-implemented method 'WaitingForPurchaseReturn'
		// Here lies the not-yet-implemented method 'PasswordPopup'
		// Here lies the not-yet-implemented method 'AddFriendScoreboardPopup'
		// Here lies the not-yet-implemented method 'PurchaseFailed'
		// Here lies the not-yet-implemented method 'PurchaseFailedPopup'
		// Here lies the not-yet-implemented method 'PromoCodeFailed'
		// Here lies the not-yet-implemented method 'PromoCodeFailedPopup'
		// Here lies the not-yet-implemented method 'GenericFailure'
		// Here lies the not-yet-implemented method 'GenericFailurePopup'
		// Here lies the not-yet-implemented method 'NewPlayerNamePopup'
		// Here lies the not-yet-implemented method 'RevertSetting'
		// Here lies the not-yet-implemented method 'DealTimer'
		// Here lies the not-yet-implemented method 'RequestNews'
		// Here lies the not-yet-implemented method 'ASC_ShowNews'
		// Here lies the not-yet-implemented method 'QueueTimer'
		// Here lies the not-yet-implemented method 'BeginExperienceTweens'
		// Here lies the not-yet-implemented method 'TweenExperienceSummary'
		// Here lies the not-yet-implemented method 'TweenPlayerSummary'
		// Here lies the not-yet-implemented method 'ToggleWorkingGraphic'
		// Here lies the not-yet-implemented method 'ShowWorkingGraphic'
		// Here lies the not-yet-implemented method 'HideWorkingGraphic'
		// Here lies the not-yet-implemented method 'UnlockedUnknown'
		// Here lies the not-yet-implemented method 'SeedAccolades'
		// Here lies the not-yet-implemented method 'UILoadSummary'
		// Here lies the not-yet-implemented method 'ASC_LoadPlayerSummary'
		// Here lies the not-yet-implemented method 'ClearVehicleMenu'
		// Here lies the not-yet-implemented method 'ShowVehicleMenu'
		// Here lies the not-yet-implemented method 'PullOpenMenu'
		// Here lies the not-yet-implemented method 'ASC_OpeningMenu'
		// Here lies the not-yet-implemented method 'ASC_ForceFocus'
		// Here lies the not-yet-implemented method 'AddVehicleMenuOption'
		// Here lies the not-yet-implemented method 'ShowChat'
		// Here lies the not-yet-implemented method 'HideChat'
		// Here lies the not-yet-implemented method 'PushChat'
		// Here lies the not-yet-implemented method 'ToggleChat'
		// Here lies the not-yet-implemented method 'StartSteamTransaction'
		// Here lies the not-yet-implemented method 'ShowSteamResponse'
		// Here lies the not-yet-implemented method 'HandlePopup'
		// Here lies the not-yet-implemented method 'HandlePopupComplete'
		// Here lies the not-yet-implemented method 'NavigateSteamGold'
		// Here lies the not-yet-implemented method 'CreateAccount'
		// Here lies the not-yet-implemented method 'ShowNotification'
		// Here lies the not-yet-implemented method 'HideNotification'
		// Here lies the not-yet-implemented method 'UpdateButton'
		// Here lies the not-yet-implemented method 'HidePopup'
		// Here lies the not-yet-implemented method 'ASC_ShowQueue'
		// Here lies the not-yet-implemented method 'ASC_LeftGame'
		// Here lies the not-yet-implemented method 'ASC_JoinGame'
		// Here lies the not-yet-implemented method 'ASC_FocusLogin'
		// Here lies the not-yet-implemented method 'ASC_LoadMatchSummary'
		// Here lies the not-yet-implemented method 'ASC_GlobalAlert'
		// Here lies the not-yet-implemented method 'ASC_KeyPressCaptured'
		// Here lies the not-yet-implemented method 'ASC_PromptNewPlayerName'
		// Here lies the not-yet-implemented method 'ASC_PurchaseComplete'
		// Here lies the not-yet-implemented method 'ASC_ShowReticuleBuilder'
		// Here lies the not-yet-implemented method 'ASC_HideReticuleBuilder'
		// Here lies the not-yet-implemented method 'ASC_SetMapLoadText'
		// Here lies the not-yet-implemented method 'SetSoundSkillBar'
		// Here lies the not-yet-implemented method 'SetSoundPerkType'
		// Here lies the not-yet-implemented method 'SetShowingPopupDelegate'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
