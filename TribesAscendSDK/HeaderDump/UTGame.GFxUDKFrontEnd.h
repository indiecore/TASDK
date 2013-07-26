#pragma once
#include "GFxUI.GFxMoviePlayer.h"
#include "UTGame.GFxUDKFrontEnd_JoinGame.h"
#include "UTGame.GFxUDKFrontEnd_Mutators.h"
#include "UTGame.GFxUDKFrontEnd_PasswordDialog.h"
#include "UTGame.GFxUDKFrontEnd_ErrorDialog.h"
#include "UTGame.GFxUDKFrontEnd_View.h"
#include "UTGame.GFxUDKFrontEnd_JoinDialog.h"
#include "UTGame.GFxUDKFrontEnd_InfoDialog.h"
#include "UTGame.GFxUDKFrontEnd_FilterDialog.h"
#include "UTGame.GFxUDKFrontEnd_ServerSettings.h"
#include "GFxUI.GFxObject.h"
#include "UTGame.GFxUDKFrontEnd_Settings.h"
#include "UTGame.GFxUDKFrontEnd_GameMode.h"
#include "UTGame.GFxUDKFrontEnd_MapSelect.h"
#include "UTGame.GFxUDKFrontEnd_HostGame.h"
#include "UTGame.GFxUDKFrontEnd_Multiplayer.h"
#include "UTGame.GFxUDKFrontEnd_InstantAction.h"
#include "UTGame.GFxUDKFrontEnd_MainMenu.h"
#include "UTGame.GFxUDKFrontEnd.ViewInfo.h"
#include "UTGame.GFxUDKFrontEnd_Screen.h"
#include "UTGame.GFxUDKFrontEnd_Dialog.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUDKFrontEnd." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUDKFrontEnd." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd : public GFxMoviePlayer
	{
	public:
		ADD_OBJECT(GFxUDKFrontEnd_PasswordDialog, PasswordDialog)
		ADD_OBJECT(GFxUDKFrontEnd_ErrorDialog, ErrorDialog)
		ADD_OBJECT(GFxUDKFrontEnd_JoinDialog, JoinDialog)
		ADD_OBJECT(GFxUDKFrontEnd_FilterDialog, FilterDialog)
		ADD_OBJECT(GFxUDKFrontEnd_InfoDialog, InfoDialog)
		ADD_OBJECT(GFxUDKFrontEnd_JoinGame, JoinGameView)
		ADD_OBJECT(GFxUDKFrontEnd_ServerSettings, ServerSettingsView)
		ADD_OBJECT(GFxUDKFrontEnd_Settings, SettingsView)
		ADD_OBJECT(GFxUDKFrontEnd_Mutators, MutatorsView)
		ADD_OBJECT(GFxUDKFrontEnd_GameMode, GameModeView)
		ADD_OBJECT(GFxUDKFrontEnd_MapSelect, MapSelectView)
		ADD_OBJECT(GFxUDKFrontEnd_HostGame, HostGameView)
		ADD_OBJECT(GFxUDKFrontEnd_Multiplayer, MultiplayerView)
		ADD_OBJECT(GFxUDKFrontEnd_InstantAction, InstantActionView)
		ADD_OBJECT(GFxUDKFrontEnd_MainMenu, MainMenuView)
		ADD_VAR(::BoolProperty, bInitialized, 0x1)
		ADD_OBJECT(GFxObject, ManagerMC)
		ADD_OBJECT(GFxObject, RootMC)
		void EscapeDelegate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.EscapeDelegate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool Start(bool StartPaused)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.Start");
			byte* params = (byte*)malloc(8);
			*(bool*)params = StartPaused;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void ConfigFrontEnd()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.ConfigFrontEnd");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASShowCursor(bool bShowCursor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.ASShowCursor");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bShowCursor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LoadViews()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.LoadViews");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LoadView(ViewInfo InViewInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.LoadView");
			byte* params = (byte*)malloc(32);
			*(ViewInfo*)params = InViewInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LoadViewByName(ScriptName InViewName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.LoadViewByName");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = InViewName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsViewLoaded(ScriptName InViewName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.IsViewLoaded");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = InViewName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void SetEscapeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.SetEscapeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PushViewByName(ScriptName TargetViewName, class GFxUDKFrontEnd_Screen* ParentView)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.PushViewByName");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = TargetViewName;
			*(class GFxUDKFrontEnd_Screen**)(params + 8) = ParentView;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class GFxUDKFrontEnd_Dialog* SpawnDialog(ScriptName TargetDialogName, class GFxUDKFrontEnd_Screen* ParentView)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.SpawnDialog");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = TargetDialogName;
			*(class GFxUDKFrontEnd_Screen**)(params + 8) = ParentView;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxUDKFrontEnd_Dialog**)(params + 12);
			free(params);
			return returnVal;
		}
		void ConfigureTargetDialog(class GFxUDKFrontEnd_View* TargetDialog)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.ConfigureTargetDialog");
			byte* params = (byte*)malloc(4);
			*(class GFxUDKFrontEnd_View**)params = TargetDialog;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ConfigureTargetView(class GFxUDKFrontEnd_View* TargetView)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.ConfigureTargetView");
			byte* params = (byte*)malloc(4);
			*(class GFxUDKFrontEnd_View**)params = TargetView;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsViewAllowed(class GFxUDKFrontEnd_View* TargetView)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.IsViewAllowed");
			byte* params = (byte*)malloc(8);
			*(class GFxUDKFrontEnd_View**)params = TargetView;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void PushView(class GFxUDKFrontEnd_View* TargetView)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.PushView");
			byte* params = (byte*)malloc(4);
			*(class GFxUDKFrontEnd_View**)params = TargetView;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PushDialogView(class GFxUDKFrontEnd_View* dialogView)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.PushDialogView");
			byte* params = (byte*)malloc(4);
			*(class GFxUDKFrontEnd_View**)params = dialogView;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSelectionFocus(class GFxObject* MovieClip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.SetSelectionFocus");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = MovieClip;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ASSetSelectionFocus(class GFxObject* MovieClip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.ASSetSelectionFocus");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = MovieClip;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class GFxObject* PopView()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.PopView");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)params;
			free(params);
			return returnVal;
		}
		class GFxObject* PopViewStub()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.PopViewStub");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)params;
			free(params);
			return returnVal;
		}
		void UpdateViewLayout()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.UpdateViewLayout");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ConfigureView(class GFxUDKFrontEnd_View* InView, ScriptName WidgetName, ScriptName WidgetPath)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.ConfigureView");
			byte* params = (byte*)malloc(20);
			*(class GFxUDKFrontEnd_View**)params = InView;
			*(ScriptName*)(params + 4) = WidgetName;
			*(ScriptName*)(params + 12) = WidgetPath;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostWidgetInit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.PostWidgetInit");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CheckLinkConnectionAndError(ScriptArray<wchar_t> AlternateTitle, ScriptArray<wchar_t> AlternateMessage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.CheckLinkConnectionAndError");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = AlternateTitle;
			*(ScriptArray<wchar_t>*)(params + 12) = AlternateMessage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.WidgetInitialized");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = WidgetName;
			*(ScriptName*)(params + 8) = WidgetPath;
			*(class GFxObject**)(params + 16) = Widget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		void LoadDependantViews(ScriptName InViewName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.LoadDependantViews");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = InViewName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DestroyDependantViews(ScriptName InViewName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.DestroyDependantViews");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = InViewName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
