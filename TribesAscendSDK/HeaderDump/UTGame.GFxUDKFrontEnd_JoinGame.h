#pragma once
#include "UTGame.GFxUDKFrontEnd_JoinDialog.h"
#include "Engine.OnlineSubsystem.h"
#include "UDKBase.UDKDataStore_GameSearchBase.h"
#include "UTGame.GFxUDKFrontEnd_Screen.h"
#include "UTGame.UTUIDataStore_StringList.h"
#include "GFxUI.GFxClikWidget.EventData.h"
#include "GFxUI.GFxObject.h"
#include "UTGame.UTUIDataStore_MenuItems.h"
#include "GFxUI.GFxClikWidget.h"
#include "UTGame.GFxUDKFrontEnd_PasswordDialog.h"
#include "UTGame.UTDataStore_GameSearchDM.h"
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
		void OnViewLoaded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.OnViewLoaded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnViewActivated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.OnViewActivated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ForceLANOption(int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.ForceLANOption");
			byte* params = (byte*)malloc(4);
			*(int*)params = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateFilterButton()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.UpdateFilterButton");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.OnTopMostView");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnViewClosed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.OnViewClosed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableSubComponents(bool bDisableComponents)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.DisableSubComponents");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bDisableComponents;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ValidateServerType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.ValidateServerType");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Cleanup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.Cleanup");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetGameTypeSearchProviderIndex(ScriptArray<wchar_t> GameClassName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.GetGameTypeSearchProviderIndex");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = GameClassName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		void OnGameTypeChanged(int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.OnGameTypeChanged");
			byte* params = (byte*)malloc(4);
			*(int*)params = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ConditionalRefreshServerList(int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.ConditionalRefreshServerList");
			byte* params = (byte*)malloc(4);
			*(int*)params = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UseLANMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.UseLANMode");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateButtonStates()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.UpdateButtonStates");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PromptForServerPassword()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.PromptForServerPassword");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptArray<wchar_t> StripInvalidPasswordCharacters(ScriptArray<wchar_t> PasswordString, ScriptArray<wchar_t> InvalidChars)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.StripInvalidPasswordCharacters");
			byte* params = (byte*)malloc(36);
			*(ScriptArray<wchar_t>*)params = PasswordString;
			*(ScriptArray<wchar_t>*)(params + 12) = InvalidChars;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 24);
			free(params);
			return returnVal;
		}
		void OnPasswordDialog_OK(EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.OnPasswordDialog_OK");
			byte* params = (byte*)malloc(36);
			*(EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessJoin()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.ProcessJoin");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateServerCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.UpdateServerCount");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptArray<wchar_t> BuildJoinURL(ScriptArray<wchar_t> ResolvedConnectionURL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.BuildJoinURL");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = ResolvedConnectionURL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		void RefreshServerList(int InPlayerIndex, int MaxResults)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.RefreshServerList");
			byte* params = (byte*)malloc(8);
			*(int*)params = InPlayerIndex;
			*(int*)(params + 4) = MaxResults;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SubmitServerListQuery(int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.SubmitServerListQuery");
			byte* params = (byte*)malloc(4);
			*(int*)params = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnFindOnlineGamesCompleteDelegate(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.OnFindOnlineGamesCompleteDelegate");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnFindOnlineGamesComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.OnFindOnlineGamesComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetDesiredMatchType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.GetDesiredMatchType");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void OnRefreshButtonPress(EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.OnRefreshButtonPress");
			byte* params = (byte*)malloc(36);
			*(EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnFilterButtonPress(EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.OnFilterButtonPress");
			byte* params = (byte*)malloc(36);
			*(EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerFilterChangedGameType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.ServerFilterChangedGameType");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateListDataProvider()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.UpdateListDataProvider");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnServerHeaderPress(EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.OnServerHeaderPress");
			byte* params = (byte*)malloc(36);
			*(EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnMapHeaderPress(EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.OnMapHeaderPress");
			byte* params = (byte*)malloc(36);
			*(EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPlayersHeaderPress(EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.OnPlayersHeaderPress");
			byte* params = (byte*)malloc(36);
			*(EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPingHeaderPress(EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.OnPingHeaderPress");
			byte* params = (byte*)malloc(36);
			*(EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnServerListItemPress(EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.OnServerListItemPress");
			byte* params = (byte*)malloc(36);
			*(EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SpectateServer(EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.SpectateServer");
			byte* params = (byte*)malloc(36);
			*(EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void JoinServerClikListener(EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.JoinServerClikListener");
			byte* params = (byte*)malloc(36);
			*(EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void JoinServer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.JoinServer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnJoinGameComplete(ScriptName SessionName, bool bSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.OnJoinGameComplete");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SessionName;
			*(bool*)(params + 8) = bSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AllowJoinServer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.AllowJoinServer");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void CancelQuery(byte DesiredCancelAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.CancelQuery");
			byte* params = (byte*)malloc(1);
			*params = DesiredCancelAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetRefreshing(bool IsRefreshing)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.SetRefreshing");
			byte* params = (byte*)malloc(4);
			*(bool*)params = IsRefreshing;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnCancelSearchComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.OnCancelSearchComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyGameTypeChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.NotifyGameTypeChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinGame.WidgetInitialized");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = WidgetName;
			*(ScriptName*)(params + 8) = WidgetPath;
			*(class GFxObject**)(params + 16) = Widget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
