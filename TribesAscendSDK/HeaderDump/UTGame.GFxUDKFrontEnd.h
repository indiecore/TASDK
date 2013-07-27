#pragma once
#include "GFxUI.GFxMoviePlayer.h"
#include "UTGame.GFxUDKFrontEnd_View.h"
#include "UTGame.GFxUDKFrontEnd_JoinDialog.h"
#include "UTGame.GFxUDKFrontEnd_JoinGame.h"
#include "UTGame.GFxUDKFrontEnd_Mutators.h"
#include "UTGame.GFxUDKFrontEnd_PasswordDialog.h"
#include "UTGame.GFxUDKFrontEnd_ErrorDialog.h"
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
#include "UTGame.GFxUDKFrontEnd_Screen.h"
#include "UTGame.GFxUDKFrontEnd_Dialog.h"
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
	class GFxUDKFrontEnd : public GFxMoviePlayer
	{
	public:
		class ViewInfo
		{
		public:
			ADD_STRUCT(ScriptArray<ScriptName>, DependantViews, 20)
			ADD_STRUCT(ScriptString*, SWFName, 8)
			ADD_STRUCT(ScriptName, ViewName, 0)
		};
		ADD_STRUCT(ScriptArray<GFxUDKFrontEnd::ViewInfo>, ViewData, 452)
		ADD_STRUCT(ScriptArray<class GFxUDKFrontEnd_View*>, ViewStack, 464)
		ADD_STRUCT(ScriptArray<ScriptName>, LoadedViews, 476)
		ADD_OBJECT(GFxUDKFrontEnd_PasswordDialog, PasswordDialog, 448)
		ADD_OBJECT(GFxUDKFrontEnd_ErrorDialog, ErrorDialog, 444)
		ADD_OBJECT(GFxUDKFrontEnd_JoinDialog, JoinDialog, 440)
		ADD_OBJECT(GFxUDKFrontEnd_FilterDialog, FilterDialog, 436)
		ADD_OBJECT(GFxUDKFrontEnd_InfoDialog, InfoDialog, 432)
		ADD_OBJECT(GFxUDKFrontEnd_JoinGame, JoinGameView, 428)
		ADD_OBJECT(GFxUDKFrontEnd_ServerSettings, ServerSettingsView, 424)
		ADD_OBJECT(GFxUDKFrontEnd_Settings, SettingsView, 420)
		ADD_OBJECT(GFxUDKFrontEnd_Mutators, MutatorsView, 416)
		ADD_OBJECT(GFxUDKFrontEnd_GameMode, GameModeView, 412)
		ADD_OBJECT(GFxUDKFrontEnd_MapSelect, MapSelectView, 408)
		ADD_OBJECT(GFxUDKFrontEnd_HostGame, HostGameView, 404)
		ADD_OBJECT(GFxUDKFrontEnd_Multiplayer, MultiplayerView, 400)
		ADD_OBJECT(GFxUDKFrontEnd_InstantAction, InstantActionView, 396)
		ADD_OBJECT(GFxUDKFrontEnd_MainMenu, MainMenuView, 392)
		ADD_BOOL(bInitialized, 388, 0x1)
		ADD_OBJECT(GFxObject, ManagerMC, 384)
		ADD_OBJECT(GFxObject, RootMC, 380)
		void EscapeDelegate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.EscapeDelegate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool Start(bool StartPaused)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.Start");
			byte params[8] = { NULL };
			*(bool*)&params[0] = StartPaused;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ConfigFrontEnd()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.ConfigFrontEnd");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ASShowCursor(bool bShowCursor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.ASShowCursor");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bShowCursor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadViews()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.LoadViews");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LoadView(GFxUDKFrontEnd::ViewInfo InViewInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.LoadView");
			byte params[32] = { NULL };
			*(GFxUDKFrontEnd::ViewInfo*)&params[0] = InViewInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadViewByName(ScriptName InViewName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.LoadViewByName");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = InViewName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsViewLoaded(ScriptName InViewName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.IsViewLoaded");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = InViewName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void SetEscapeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.SetEscapeDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PushViewByName(ScriptName TargetViewName, class GFxUDKFrontEnd_Screen* ParentView)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.PushViewByName");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = TargetViewName;
			*(class GFxUDKFrontEnd_Screen**)&params[8] = ParentView;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxUDKFrontEnd_Dialog* SpawnDialog(ScriptName TargetDialogName, class GFxUDKFrontEnd_Screen* ParentView)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.SpawnDialog");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = TargetDialogName;
			*(class GFxUDKFrontEnd_Screen**)&params[8] = ParentView;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxUDKFrontEnd_Dialog**)&params[12];
		}
		void ConfigureTargetDialog(class GFxUDKFrontEnd_View* TargetDialog)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.ConfigureTargetDialog");
			byte params[4] = { NULL };
			*(class GFxUDKFrontEnd_View**)&params[0] = TargetDialog;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ConfigureTargetView(class GFxUDKFrontEnd_View* TargetView)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.ConfigureTargetView");
			byte params[4] = { NULL };
			*(class GFxUDKFrontEnd_View**)&params[0] = TargetView;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsViewAllowed(class GFxUDKFrontEnd_View* TargetView)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.IsViewAllowed");
			byte params[8] = { NULL };
			*(class GFxUDKFrontEnd_View**)&params[0] = TargetView;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PushView(class GFxUDKFrontEnd_View* TargetView)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.PushView");
			byte params[4] = { NULL };
			*(class GFxUDKFrontEnd_View**)&params[0] = TargetView;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PushDialogView(class GFxUDKFrontEnd_View* dialogView)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.PushDialogView");
			byte params[4] = { NULL };
			*(class GFxUDKFrontEnd_View**)&params[0] = dialogView;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSelectionFocus(class GFxObject* MovieClip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.SetSelectionFocus");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = MovieClip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ASSetSelectionFocus(class GFxObject* MovieClip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.ASSetSelectionFocus");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = MovieClip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* PopView()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.PopView");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[0];
		}
		class GFxObject* PopViewStub()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.PopViewStub");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[0];
		}
		void UpdateViewLayout()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.UpdateViewLayout");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ConfigureView(class GFxUDKFrontEnd_View* InView, ScriptName WidgetName, ScriptName WidgetPath)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.ConfigureView");
			byte params[20] = { NULL };
			*(class GFxUDKFrontEnd_View**)&params[0] = InView;
			*(ScriptName*)&params[4] = WidgetName;
			*(ScriptName*)&params[12] = WidgetPath;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostWidgetInit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.PostWidgetInit");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CheckLinkConnectionAndError(ScriptString* AlternateTitle, ScriptString* AlternateMessage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.CheckLinkConnectionAndError");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = AlternateTitle;
			*(ScriptString**)&params[12] = AlternateMessage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.WidgetInitialized");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = WidgetName;
			*(ScriptName*)&params[8] = WidgetPath;
			*(class GFxObject**)&params[16] = Widget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		void LoadDependantViews(ScriptName InViewName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.LoadDependantViews");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = InViewName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DestroyDependantViews(ScriptName InViewName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd.DestroyDependantViews");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = InViewName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
