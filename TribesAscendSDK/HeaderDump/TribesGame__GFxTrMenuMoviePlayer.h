#pragma once
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
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
