#pragma once
#include "TribesGame.TrStreamManager.h"
#include "GFxUI.GFxMoviePlayer.h"
#include "TribesGame.TrBrowserManager.h"
#include "PlatformCommon.TgPlayerProfile.h"
#include "GFxUI.GFxObject.h"
#include "TribesGame.TrPageManager.h"
#include "Engine.OnlineSubsystem.h"
#include "TribesGame.TrStrings.h"
#include "TribesGame.TrUser.h"
#include "TribesGame.TrInventoryHelper.h"
#include "TribesGame.TrEquipInterface.h"
#include "TribesGame.TrLoginManager.h"
#include "TribesGame.TrQueueManager.h"
#include "TribesGame.TrPartyManager.h"
#include "TribesGame.TrLoadingData.h"
#include "TribesGame.TrSettingsManager.h"
#include "TribesGame.TrRibbonManager.h"
#include "TribesGame.TrFriendManager.h"
#include "TribesGame.GFxTrScene_EULA.h"
#include "TribesGame.GFxTrScene_MatchSummary.h"
#include "TribesGame.GFxTrScene_PlayerSummary.h"
#include "TribesGame.GFxTrMenuSounds.h"
#include "TribesGame.TrHUD.h"
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
		void DelegateNoParam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.DelegateNoParam");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DelegateInt(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.DelegateInt");
			byte* params = (byte*)malloc(4);
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DelegateBool(bool bVal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.DelegateBool");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DelegateString(ScriptArray<wchar_t> val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.DelegateString");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DelegateGFxList(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.DelegateGFxList");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DelegateIntInt(int Val1, int Val2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.DelegateIntInt");
			byte* params = (byte*)malloc(8);
			*(int*)params = Val1;
			*(int*)(params + 4) = Val2;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DelegateIntString(int Val1, ScriptArray<wchar_t> Val2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.DelegateIntString");
			byte* params = (byte*)malloc(16);
			*(int*)params = Val1;
			*(ScriptArray<wchar_t>*)(params + 4) = Val2;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DelegateStringInt(ScriptArray<wchar_t> Val1, int Val2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.DelegateStringInt");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Val1;
			*(int*)(params + 12) = Val2;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DelegateStringBool(ScriptArray<wchar_t> val, bool bVal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.DelegateStringBool");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = val;
			*(bool*)(params + 12) = bVal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DelegateIntGFxList(int val, class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.DelegateIntGFxList");
			byte* params = (byte*)malloc(8);
			*(int*)params = val;
			*(class GFxObject**)(params + 4) = List;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DelegateOnMarshalEvent(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer'!
void* pMarEvent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.DelegateOnMarshalEvent");
			byte* params = (byte*)malloc(4);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer'!
void**)params = pMarEvent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int DelegateGetInt()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.DelegateGetInt");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int DelegateGetPrice(float XPValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.DelegateGetPrice");
			byte* params = (byte*)malloc(8);
			*(float*)params = XPValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		bool DelegateIntIntInt(int Val1, int Val2, int Val3)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.DelegateIntIntInt");
			byte* params = (byte*)malloc(16);
			*(int*)params = Val1;
			*(int*)(params + 4) = Val2;
			*(int*)(params + 8) = Val3;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool DelegateGetBoolIntInt(int SlotId, int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.DelegateGetBoolIntInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = SlotId;
			*(int*)(params + 4) = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool DelegateLogin(ScriptArray<wchar_t> UserName, ScriptArray<wchar_t> Password, bool bRemember)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.DelegateLogin");
			byte* params = (byte*)malloc(32);
			*(ScriptArray<wchar_t>*)params = UserName;
			*(ScriptArray<wchar_t>*)(params + 12) = Password;
			*(bool*)(params + 24) = bRemember;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		bool DelegateBoolGetBool(bool val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.DelegateBoolGetBool");
			byte* params = (byte*)malloc(8);
			*(bool*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> DelegateGetString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.DelegateGetString");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void DelegateOptions(class GFxObject* List, int ClassId, int SkillId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.DelegateOptions");
			byte* params = (byte*)malloc(12);
			*(class GFxObject**)params = List;
			*(int*)(params + 4) = ClassId;
			*(int*)(params + 8) = SkillId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int DelegateAction(int val, class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.DelegateAction");
			byte* params = (byte*)malloc(12);
			*(int*)params = val;
			*(class GFxObject**)(params + 4) = List;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		bool UseSteam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.UseSteam");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void RequestPurchaseSteamItem(int LootId, int Price)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.RequestPurchaseSteamItem");
			byte* params = (byte*)malloc(8);
			*(int*)params = LootId;
			*(int*)(params + 4) = Price;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RequestSteamUserData()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.RequestSteamUserData");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetGoldItemInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.GetGoldItemInfo");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		bool UsePortal()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.UsePortal");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		int GetPortalBalance()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.GetPortalBalance");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetPortalCurrencyName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.GetPortalCurrencyName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		bool RequestPurchasePortalItem(int LootItemId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.RequestPurchasePortalItem");
			byte* params = (byte*)malloc(8);
			*(int*)params = LootItemId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CheckAutoLoginStatus()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.CheckAutoLoginStatus");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void PurchasedItem(int VendorId, int LootId, bool bSuccess, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.PurchasedItem");
			byte* params = (byte*)malloc(24);
			*(int*)params = VendorId;
			*(int*)(params + 4) = LootId;
			*(bool*)(params + 8) = bSuccess;
			*(ScriptArray<wchar_t>*)(params + 12) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnMarshalEvent(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer'!
void* pMarEvent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.OnMarshalEvent");
			byte* params = (byte*)malloc(4);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer'!
void**)params = pMarEvent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ReadPlayerProfileData(class TgPlayerProfile* Profile)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ReadPlayerProfileData");
			byte* params = (byte*)malloc(8);
			*(class TgPlayerProfile**)params = Profile;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void UserLoginChanged(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer'!
void* pMarEvent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.UserLoginChanged");
			byte* params = (byte*)malloc(4);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer'!
void**)params = pMarEvent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool RegisterMarshalCallback(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MarshalEventDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.RegisterMarshalCallback");
			byte* params = (byte*)malloc(16);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = MarshalEventDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetVersionString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.GetVersionString");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void ForceFocus()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ForceFocus");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool AddAcquisition(int VendorId, int LootId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.AddAcquisition");
			byte* params = (byte*)malloc(12);
			*(int*)params = VendorId;
			*(int*)(params + 4) = LootId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void GetQueueUIInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.GetQueueUIInfo");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetLanguageFontIndex()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.GetLanguageFontIndex");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void RequestStreams()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.RequestStreams");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetEquipmentXP(int ActivityId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.GetEquipmentXP");
			byte* params = (byte*)malloc(8);
			*(int*)params = ActivityId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetEquipmentTierXP(int ActivityId, int Tier)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.GetEquipmentTierXP");
			byte* params = (byte*)malloc(12);
			*(int*)params = ActivityId;
			*(int*)(params + 4) = Tier;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		bool HaveClanTag()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.HaveClanTag");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool Start(bool StartPaused)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.Start");
			byte* params = (byte*)malloc(8);
			*(bool*)params = StartPaused;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void SetLoginDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetLoginDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSubmitPlayerNameDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetSubmitPlayerNameDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetLoadTeamMiscDataDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetLoadTeamMiscDataDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetLoadTeamScoreboardDataDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetLoadTeamScoreboardDataDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetLoadTeamStatsDataDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetLoadTeamStatsDataDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetLoadTeamAccoladeDataDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetLoadTeamAccoladeDataDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetLoadPlayerMiscDataDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetLoadPlayerMiscDataDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetLoadPlayerStatsDataDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetLoadPlayerStatsDataDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetLoadPlayerAccoladeDataDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetLoadPlayerAccoladeDataDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAcceptEULADelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetAcceptEULADelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSoundXPGain(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetSoundXPGain");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSoundClassType(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetSoundClassType");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSoundSkillType(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetSoundSkillType");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetEscapeClass(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetEscapeClass");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetExitGameDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetExitGameDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetGetPlatformDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetGetPlatformDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetGetViewModeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetGetViewModeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetShowSummaryDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetShowSummaryDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAlertDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetAlertDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBrowserGoldDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetBrowserGoldDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBrowserStoreDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetBrowserStoreDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBrowserSupportDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetBrowserSupportDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBrowserProfileDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetBrowserProfileDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBrowserBoosterDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetBrowserBoosterDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBrowserClassVideoDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetBrowserClassVideoDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBrowserActivateKeyDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetBrowserActivateKeyDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBrowserCreateAccountDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetBrowserCreateAccountDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBrowserRecoverPasswordDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetBrowserRecoverPasswordDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBrowserRecoverUsernameDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetBrowserRecoverUsernameDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetExitQueueDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetExitQueueDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetJoinCustomServerDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetJoinCustomServerDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFavoriteServerDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetFavoriteServerDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPasswordServerDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetPasswordServerDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetServerPageDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetServerPageDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetServerSortDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetServerSortDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetReticuleActionDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetReticuleActionDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSaveReticuleDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetSaveReticuleDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetRequestNewsDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetRequestNewsDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetStartLoginDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetStartLoginDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSmoothAnimDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetSmoothAnimDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ASC_SetFontIndex(int FontIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_SetFontIndex");
			byte* params = (byte*)malloc(4);
			*(int*)params = FontIdx;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ASC_Resize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_Resize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPopupDataDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetPopupDataDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPopupCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetPopupCompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFocusedActionDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetFocusedActionDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSelectedActionDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetSelectedActionDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetModifiedActionDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetModifiedActionDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetModifyFocusDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetModifyFocusDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetActionUpDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetActionUpDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetActionDownDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetActionDownDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetHelpButtonDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetHelpButtonDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetProfilePageUpDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetProfilePageUpDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetProfilePageDownDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetProfilePageDownDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetMutePlayerDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetMutePlayerDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSummaryActionDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetSummaryActionDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFriendPlayerDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetFriendPlayerDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetLoadXPSummaryDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetLoadXPSummaryDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPromoActionDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetPromoActionDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSelectedFeatureDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetSelectedFeatureDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CompleteStartup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.CompleteStartup");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SummaryAction(int ActionId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SummaryAction");
			byte* params = (byte*)malloc(4);
			*(int*)params = ActionId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartMainMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.StartMainMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleMutePlayer(ScriptArray<wchar_t> PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ToggleMutePlayer");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> StripTag(ScriptArray<wchar_t> sValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.StripTag");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = sValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		void StartPeach()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.StartPeach");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartLogin()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.StartLogin");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowPeach()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ShowPeach");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_ShowPeach()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_ShowPeach");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EntryPlayerReady()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.EntryPlayerReady");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool HaveEntry()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.HaveEntry");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetPlayerMainMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetPlayerMainMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClosePopup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ClosePopup");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPlayerInLogin(bool bServerDrop)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetPlayerInLogin");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bServerDrop;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void QueuePopup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.QueuePopup");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPlayerInLobby()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetPlayerInLobby");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_StopLoading()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_StopLoading");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPlayerLoading()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetPlayerLoading");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_GotoState(ScriptArray<wchar_t> NewState)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_GotoState");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = NewState;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPlayerInGame()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetPlayerInGame");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetEndOfMatch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetEndOfMatch");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowSummary()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ShowSummary");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Escape()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.Escape");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CloseClasses()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.CloseClasses");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OpenMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.OpenMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OpenClasses()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.OpenClasses");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OpenFriends()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.OpenFriends");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OpenSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.OpenSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void QuitGame()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.QuitGame");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LeaveMatch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.LeaveMatch");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void QuitGamePopup(class GFxObject* Obj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.QuitGamePopup");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LeaveMatchPopup(class GFxObject* Obj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.LeaveMatchPopup");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void QuitGamePopupComplete(int Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.QuitGamePopupComplete");
			byte* params = (byte*)malloc(4);
			*(int*)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LeaveMatchPopupComplete(int Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.LeaveMatchPopupComplete");
			byte* params = (byte*)malloc(4);
			*(int*)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Quit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.Quit");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendPlayerLogin(ScriptArray<wchar_t> PlayerName, ScriptArray<wchar_t> Reason, bool Success, bool bNeedEULA)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SendPlayerLogin");
			byte* params = (byte*)malloc(32);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			*(ScriptArray<wchar_t>*)(params + 12) = Reason;
			*(bool*)(params + 24) = Success;
			*(bool*)(params + 28) = bNeedEULA;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AlienMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.AlienMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnProfileLoaded(bool bShowEula)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.OnProfileLoaded");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bShowEula;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsLoadComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.IsLoadComplete");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SendBack()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SendBack");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EquipmentLoaded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.EquipmentLoaded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EquipmentChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.EquipmentChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RefreshPage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.RefreshPage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SwapModel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SwapModel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void JoinFailed(ScriptArray<wchar_t> Error)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.JoinFailed");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Error;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisplayJoinFailed(class GFxObject* Obj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.DisplayJoinFailed");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void JoinRequiresPassword()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.JoinRequiresPassword");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void JoinRequiresPasswordComplete(int Action, ScriptArray<wchar_t> TextInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.JoinRequiresPasswordComplete");
			byte* params = (byte*)malloc(16);
			*(int*)params = Action;
			*(ScriptArray<wchar_t>*)(params + 4) = TextInput;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CheckRibbons(bool bForce)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.CheckRibbons");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bForce;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProfileUpdated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ProfileUpdated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_ProfileUpdated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_ProfileUpdated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ExitPopup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ExitPopup");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_PopupError(ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_PopupError");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisplayEULA()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.DisplayEULA");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_HideLogin()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_HideLogin");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_FillEULAText(ScriptArray<wchar_t> EULAText, ScriptArray<wchar_t> Title, ScriptArray<wchar_t> Accept, ScriptArray<wchar_t> Decline)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_FillEULAText");
			byte* params = (byte*)malloc(48);
			*(ScriptArray<wchar_t>*)params = EULAText;
			*(ScriptArray<wchar_t>*)(params + 12) = Title;
			*(ScriptArray<wchar_t>*)(params + 24) = Accept;
			*(ScriptArray<wchar_t>*)(params + 36) = Decline;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CreateNewPlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.CreateNewPlayer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayerNameNotAllowed(bool bTaken)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.PlayerNameNotAllowed");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bTaken;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetUserSelectedClass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.GetUserSelectedClass");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void FillProfileData()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.FillProfileData");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendProfileData()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SendProfileData");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_FillProfile(class GFxObject* ObjList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_FillProfile");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = ObjList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetBoostLabel(int Hours)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.GetBoostLabel");
			byte* params = (byte*)malloc(16);
			*(int*)params = Hours;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptClass* GetRankFromXP(int XP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.GetRankFromXP");
			byte* params = (byte*)malloc(8);
			*(int*)params = XP;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 4);
			free(params);
			return returnVal;
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.WidgetInitialized");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = WidgetName;
			*(ScriptName*)(params + 8) = WidgetPath;
			*(class GFxObject**)(params + 16) = Widget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		void RestorePlayerHUD()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.RestorePlayerHUD");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetPlatform()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.GetPlatform");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetViewMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.GetViewMode");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void ShowMovie(bool bFocus)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ShowMovie");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bFocus;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HideMovie()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.HideMovie");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_HideMovie()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_HideMovie");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChatMessageReceived(int Channel, ScriptArray<wchar_t> Sender, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ChatMessageReceived");
			byte* params = (byte*)malloc(28);
			*(int*)params = Channel;
			*(ScriptArray<wchar_t>*)(params + 4) = Sender;
			*(ScriptArray<wchar_t>*)(params + 16) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateStatus(ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.UpdateStatus");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetCountdownTimer(int Seconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetCountdownTimer");
			byte* params = (byte*)malloc(4);
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LoadingTimer(bool bStart)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.LoadingTimer");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bStart;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool RequestPaperDoll()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.RequestPaperDoll");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void KeyBindCaptured(ScriptArray<wchar_t> KeyName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.KeyBindCaptured");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = KeyName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool KeyPressCaptured(ScriptArray<wchar_t> KeyName, bool bReleased)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.KeyPressCaptured");
			byte* params = (byte*)malloc(20);
			*(ScriptArray<wchar_t>*)params = KeyName;
			*(bool*)(params + 12) = bReleased;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool TeamSelectActive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.TeamSelectActive");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool TeamSelectOpen()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.TeamSelectOpen");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool PlayerNeedsTeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.PlayerNeedsTeam");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool PlayerNeedsClass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.PlayerNeedsClass");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		class TrHUD* GetPlayerHUD()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.GetPlayerHUD");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrHUD**)params;
			free(params);
			return returnVal;
		}
		void StartHotkeyBlock()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.StartHotkeyBlock");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EndHotkeyBlock()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.EndHotkeyBlock");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UnlockedItem(ScriptArray<wchar_t> Description, int ItemId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.UnlockedItem");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Description;
			*(int*)(params + 12) = ItemId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UnlockedGold(ScriptArray<wchar_t> Description)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.UnlockedGold");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Description;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UnlockedXP(ScriptArray<wchar_t> Description)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.UnlockedXP");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Description;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UnlockedBooster(ScriptArray<wchar_t> Description)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.UnlockedBooster");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Description;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UnlockedBadge(ScriptArray<wchar_t> Description, ScriptArray<wchar_t> RankStr, int Id)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.UnlockedBadge");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = Description;
			*(ScriptArray<wchar_t>*)(params + 12) = RankStr;
			*(int*)(params + 24) = Id;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UnlockedNameChange(ScriptArray<wchar_t> Description)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.UnlockedNameChange");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Description;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UnlockedVIP()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.UnlockedVIP");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UnlockedServerTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.UnlockedServerTime");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UnlockedClanTag(bool bRemoved)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.UnlockedClanTag");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bRemoved;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UnlockedSkill(int SkillId, int ParentId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.UnlockedSkill");
			byte* params = (byte*)malloc(8);
			*(int*)params = SkillId;
			*(int*)(params + 4) = ParentId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void WinOfTheDay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.WinOfTheDay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClaimedPromotion(ScriptArray<wchar_t> PromoName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ClaimedPromotion");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PromoName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CheckVIPForLogin()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.CheckVIPForLogin");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReadyAcquisition(ScriptArray<wchar_t> TopName, ScriptArray<wchar_t> BotName, byte IconType, int IconId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ReadyAcquisition");
			byte* params = (byte*)malloc(29);
			*(ScriptArray<wchar_t>*)params = TopName;
			*(ScriptArray<wchar_t>*)(params + 12) = BotName;
			*(params + 24) = IconType;
			*(int*)(params + 28) = IconId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisplayAcquisitions()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.DisplayAcquisitions");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FireAcquisitions()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.FireAcquisitions");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_UnlockedItem(ScriptArray<wchar_t> TopName, ScriptArray<wchar_t> BotName, ScriptArray<wchar_t> IconType, int IconId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_UnlockedItem");
			byte* params = (byte*)malloc(40);
			*(ScriptArray<wchar_t>*)params = TopName;
			*(ScriptArray<wchar_t>*)(params + 12) = BotName;
			*(ScriptArray<wchar_t>*)(params + 24) = IconType;
			*(int*)(params + 36) = IconId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void KickVoteFeedback(bool bComplete, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.KickVoteFeedback");
			byte* params = (byte*)malloc(16);
			*(bool*)params = bComplete;
			*(ScriptArray<wchar_t>*)(params + 4) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayerInLoginQueue(int Estimate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.PlayerInLoginQueue");
			byte* params = (byte*)malloc(4);
			*(int*)params = Estimate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LoginQueuePopupData(class GFxObject* Obj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.LoginQueuePopupData");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LoginQueuePopupComplete(int Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.LoginQueuePopupComplete");
			byte* params = (byte*)malloc(4);
			*(int*)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerDropPopupData(class GFxObject* Obj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ServerDropPopupData");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AFKKickPopupData(class GFxObject* Obj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.AFKKickPopupData");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LoginFailedPopup(class GFxObject* Obj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.LoginFailedPopup");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void WaitingForPurchaseReturn(class GFxObject* Obj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.WaitingForPurchaseReturn");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PasswordPopup(class GFxObject* Obj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.PasswordPopup");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddFriendScoreboardPopup(class GFxObject* Obj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.AddFriendScoreboardPopup");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PurchaseFailed(ScriptArray<wchar_t> FailMessage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.PurchaseFailed");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = FailMessage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PurchaseFailedPopup(class GFxObject* Obj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.PurchaseFailedPopup");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PromoCodeFailed(ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.PromoCodeFailed");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PromoCodeFailedPopup(class GFxObject* Obj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.PromoCodeFailedPopup");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GenericFailure(ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.GenericFailure");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GenericFailurePopup(class GFxObject* Obj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.GenericFailurePopup");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NewPlayerNamePopup(class GFxObject* Obj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.NewPlayerNamePopup");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RevertSetting()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.RevertSetting");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DealTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.DealTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RequestNews()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.RequestNews");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_ShowNews(ScriptArray<wchar_t> News, bool bFeatured)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_ShowNews");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = News;
			*(bool*)(params + 12) = bFeatured;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void QueueTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.QueueTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BeginExperienceTweens(bool bDailyCompleted, bool bWeeklyCompleted)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.BeginExperienceTweens");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bDailyCompleted;
			*(bool*)(params + 4) = bWeeklyCompleted;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TweenExperienceSummary()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.TweenExperienceSummary");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TweenPlayerSummary()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.TweenPlayerSummary");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleWorkingGraphic(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ToggleWorkingGraphic");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowWorkingGraphic()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ShowWorkingGraphic");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideWorkingGraphic()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.HideWorkingGraphic");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UnlockedUnknown(int VendorId, int LootId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.UnlockedUnknown");
			byte* params = (byte*)malloc(8);
			*(int*)params = VendorId;
			*(int*)(params + 4) = LootId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SeedAccolades(class TgPlayerProfile* Profile)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SeedAccolades");
			byte* params = (byte*)malloc(4);
			*(class TgPlayerProfile**)params = Profile;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UILoadSummary()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.UILoadSummary");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_LoadPlayerSummary()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_LoadPlayerSummary");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearVehicleMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ClearVehicleMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowVehicleMenu(int Credits)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ShowVehicleMenu");
			byte* params = (byte*)malloc(4);
			*(int*)params = Credits;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PullOpenMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.PullOpenMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_OpeningMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_OpeningMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_ForceFocus()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_ForceFocus");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddVehicleMenuOption(ScriptArray<wchar_t> ClassName, ScriptArray<wchar_t> DisplayName, int Cost, int Icon, int CountSpawned, int CountAllowed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.AddVehicleMenuOption");
			byte* params = (byte*)malloc(40);
			*(ScriptArray<wchar_t>*)params = ClassName;
			*(ScriptArray<wchar_t>*)(params + 12) = DisplayName;
			*(int*)(params + 24) = Cost;
			*(int*)(params + 28) = Icon;
			*(int*)(params + 32) = CountSpawned;
			*(int*)(params + 36) = CountAllowed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowChat()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ShowChat");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideChat()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.HideChat");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PushChat(ScriptArray<wchar_t> chatStr)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.PushChat");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = chatStr;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ToggleChat()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ToggleChat");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartSteamTransaction()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.StartSteamTransaction");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowSteamResponse(bool bAuthorized)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ShowSteamResponse");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bAuthorized;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool HandlePopup(class GFxObject* Obj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.HandlePopup");
			byte* params = (byte*)malloc(8);
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool HandlePopupComplete(int Id, ScriptArray<wchar_t> Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.HandlePopupComplete");
			byte* params = (byte*)malloc(20);
			*(int*)params = Id;
			*(ScriptArray<wchar_t>*)(params + 4) = Text;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void NavigateSteamGold(bool bSuccess)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.NavigateSteamGold");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bSuccess;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CreateAccount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.CreateAccount");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowNotification(ScriptArray<wchar_t> Message, ScriptArray<wchar_t> Message2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ShowNotification");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Message;
			*(ScriptArray<wchar_t>*)(params + 12) = Message2;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HideNotification()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.HideNotification");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateButton(class GFxObject* Obj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.UpdateButton");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HidePopup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.HidePopup");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_ShowQueue(ScriptArray<wchar_t> Estimate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_ShowQueue");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Estimate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ASC_LeftGame()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_LeftGame");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_JoinGame()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_JoinGame");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_FocusLogin()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_FocusLogin");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_LoadMatchSummary()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_LoadMatchSummary");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_GlobalAlert(ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_GlobalAlert");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ASC_KeyPressCaptured(ScriptArray<wchar_t> KeyName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_KeyPressCaptured");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = KeyName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ASC_PromptNewPlayerName(ScriptArray<wchar_t> ErrorString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_PromptNewPlayerName");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = ErrorString;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ASC_PurchaseComplete(bool bSuccess, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_PurchaseComplete");
			byte* params = (byte*)malloc(16);
			*(bool*)params = bSuccess;
			*(ScriptArray<wchar_t>*)(params + 4) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ASC_ShowReticuleBuilder(class GFxObject* Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_ShowReticuleBuilder");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = Data;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ASC_HideReticuleBuilder()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_HideReticuleBuilder");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASC_SetMapLoadText(ScriptArray<wchar_t> A, ScriptArray<wchar_t> B, ScriptArray<wchar_t> C, ScriptArray<wchar_t> D, ScriptArray<wchar_t> E, ScriptArray<wchar_t> F, ScriptArray<wchar_t> G, ScriptArray<wchar_t> H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.ASC_SetMapLoadText");
			byte* params = (byte*)malloc(96);
			*(ScriptArray<wchar_t>*)params = A;
			*(ScriptArray<wchar_t>*)(params + 12) = B;
			*(ScriptArray<wchar_t>*)(params + 24) = C;
			*(ScriptArray<wchar_t>*)(params + 36) = D;
			*(ScriptArray<wchar_t>*)(params + 48) = E;
			*(ScriptArray<wchar_t>*)(params + 60) = F;
			*(ScriptArray<wchar_t>*)(params + 72) = G;
			*(ScriptArray<wchar_t>*)(params + 84) = H;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSoundSkillBar(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetSoundSkillBar");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSoundPerkType(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetSoundPerkType");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetShowingPopupDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* In)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrMenuMoviePlayer.SetShowingPopupDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = In;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
