#pragma once
#include "Engine.OnlineSubsystem.h"
#include "UDKBase.UDKDataStore_GameSearchBase.h"
#include "UTGame.GFxUDKFrontEnd_Screen.h"
#include "UTGame.UTUIDataStore_StringList.h"
#include "GFxUI.GFxObject.h"
#include "UTGame.UTUIDataStore_MenuItems.h"
#include "GFxUI.GFxClikWidget.h"
#include "UTGame.GFxUDKFrontEnd_PasswordDialog.h"
#include "Engine.OnlineGameSearch.h"
#include "UTGame.GFxUDKFrontEnd_JoinDialog.h"
#include "UTGame.UTDataStore_GameSearchDM.h"
#include "UDKBase.UDKUIDataProvider_SearchResult.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class GFxUDKFrontEnd_JoinGame : public GFxUDKFrontEnd_Screen
	{
	public:
		static const auto SERVERBROWSER_SERVERTYPE_RANKED = 2;
		static const auto SERVERBROWSER_SERVERTYPE_UNRANKED = 1;
		static const auto SERVERBROWSER_SERVERTYPE_LAN = 0;
		enum EQueryCompletionAction : byte
		{
			QUERYACTION_None = 0,
			QUERYACTION_Default = 1,
			QUERYACTION_CloseScene = 2,
			QUERYACTION_JoinServer = 3,
			QUERYACTION_RefreshAll = 4,
			QUERYACTION_MAX = 5,
		};
		ADD_OBJECT(UDKDataStore_GameSearchBase, SearchDataStore, 220)
		ADD_STRUCT(ScriptName, SearchDSName, 264)
		ADD_OBJECT(UTUIDataStore_StringList, StringListDataStore, 224)
		ADD_OBJECT(UTUIDataStore_MenuItems, MenuItemDataStore, 244)
		ADD_OBJECT(OnlineSubsystem, OnlineSub, 248)
		ADD_OBJECT(GFxClikWidget, FlagsHeaderBtn, 328)
		ADD_OBJECT(GFxClikWidget, ServerHeaderBtn, 332)
		ADD_OBJECT(GFxClikWidget, MapHeaderBtn, 336)
		ADD_OBJECT(GFxClikWidget, PlayersHeaderBtn, 340)
		ADD_OBJECT(GFxClikWidget, PingHeaderBtn, 344)
		ADD_BOOL(bGametypeOutdated, 260, 0x1)
		ADD_BOOL(bIssuedInitialQuery, 260, 0x4)
		ADD_OBJECT(GFxClikWidget, RefreshBtn, 320)
		ADD_OBJECT(GFxClikWidget, ServerListMC, 316)
		ADD_OBJECT(GFxObject, FilterMatchTypeTxt, 348)
		ADD_OBJECT(GFxObject, FilterGameModeTxt, 352)
		ADD_OBJECT(GFxUDKFrontEnd_PasswordDialog, PasswordDialog, 272)
		ADD_STRUCT(ScriptString*, ServerPassword, 284)
		ADD_OBJECT(GFxObject, StatusTxt, 356)
		ADD_OBJECT(GFxObject, ServerCountTxt, 364)
		ADD_BOOL(bSpectate, 260, 0x2)
		ADD_STRUCT(GFxUDKFrontEnd_JoinGame::EQueryCompletionAction, QueryCompletionAction, 280)
		ADD_BOOL(bQueryDialogShowing, 260, 0x8)
		ADD_STRUCT(ScriptArray<OnlineGameSearch::OnlineGameSearchResult>, ServerInfoList, 232)
		ADD_OBJECT(GFxObject, HeaderBarMC, 324)
		ADD_STRUCT(int, SelectedIndex, 372)
		ADD_OBJECT(GFxUDKFrontEnd_JoinDialog, JoinDialogMC, 276)
		ADD_BOOL(bJoinDialogShowing, 260, 0x10)
		ADD_BOOL(bProcessingJoin, 260, 0x20)
		ADD_OBJECT(GFxObject, LoadingTickerMC, 360)
		ADD_OBJECT(GFxObject, MenuMC, 312)
		ADD_OBJECT(GFxClikWidget, FilterBtn, 368)
		ADD_OBJECT(UTDataStore_GameSearchDM, SearchDMDataStore, 228)
		ADD_STRUCT(int, LastServerAdded, 296)
		ADD_STRUCT(ScriptArray<class UDKUIDataProvider_SearchResult*>, ServerListData, 300)
		void OnViewLoaded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38414);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnViewActivated()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38421);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ForceLANOption(int PlayerIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38429);
			byte params[4] = { NULL };
			*(int*)params = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateFilterButton()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38430);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38431);
			byte params[4] = { NULL };
			*(bool*)params = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnViewClosed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38434);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableSubComponents(bool bDisableComponents)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38435);
			byte params[4] = { NULL };
			*(bool*)params = bDisableComponents;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ValidateServerType()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38438);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Cleanup()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38444);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetGameTypeSearchProviderIndex(ScriptString* GameClassName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38450);
			byte params[16] = { NULL };
			*(ScriptString**)params = GameClassName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		void OnGameTypeChanged(int PlayerIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38455);
			byte params[4] = { NULL };
			*(int*)params = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ConditionalRefreshServerList(int PlayerIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38459);
			byte params[4] = { NULL };
			*(int*)params = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UseLANMode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38463);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateButtonStates()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38464);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PromptForServerPassword()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38466);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* StripInvalidPasswordCharacters(ScriptString* PasswordString, ScriptString* InvalidChars)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38468);
			byte params[36] = { NULL };
			*(ScriptString**)params = PasswordString;
			*(ScriptString**)&params[12] = InvalidChars;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[24];
		}
		void OnPasswordDialog_OK(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38473);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessJoin()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38479);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateServerCount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38480);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* BuildJoinURL(ScriptString* ResolvedConnectionURL)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38485);
			byte params[24] = { NULL };
			*(ScriptString**)params = ResolvedConnectionURL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		void RefreshServerList(int InPlayerIndex, int MaxResults)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38490);
			byte params[8] = { NULL };
			*(int*)params = InPlayerIndex;
			*(int*)&params[4] = MaxResults;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SubmitServerListQuery(int PlayerIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38495);
			byte params[4] = { NULL };
			*(int*)params = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFindOnlineGamesCompleteDelegate(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38497);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFindOnlineGamesComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38500);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetDesiredMatchType()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38504);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void OnRefreshButtonPress(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38506);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFilterButtonPress(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38508);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerFilterChangedGameType()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38511);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateListDataProvider()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38512);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnServerHeaderPress(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38523);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnMapHeaderPress(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38525);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPlayersHeaderPress(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38527);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPingHeaderPress(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38529);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnServerListItemPress(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38531);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpectateServer(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38538);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void JoinServerClikListener(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38540);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void JoinServer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38542);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnJoinGameComplete(ScriptName SessionName, bool bSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38550);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AllowJoinServer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38555);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void CancelQuery(GFxUDKFrontEnd_JoinGame::EQueryCompletionAction DesiredCancelAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38558);
			byte params[1] = { NULL };
			*(GFxUDKFrontEnd_JoinGame::EQueryCompletionAction*)params = DesiredCancelAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetRefreshing(bool IsRefreshing)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38560);
			byte params[4] = { NULL };
			*(bool*)params = IsRefreshing;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnCancelSearchComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38563);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyGameTypeChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38567);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38568);
			byte params[24] = { NULL };
			*(ScriptName*)params = WidgetName;
			*(ScriptName*)&params[8] = WidgetPath;
			*(class GFxObject**)&params[16] = Widget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
