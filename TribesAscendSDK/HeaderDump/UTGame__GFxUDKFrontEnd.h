#pragma once
#include "UTGame__GFxUDKFrontEnd_GameMode.h"
#include "GFxUI__GFxMoviePlayer.h"
#include "UTGame__GFxUDKFrontEnd_PasswordDialog.h"
#include "UTGame__GFxUDKFrontEnd_ErrorDialog.h"
#include "UTGame__GFxUDKFrontEnd_FilterDialog.h"
#include "UTGame__GFxUDKFrontEnd_MapSelect.h"
#include "UTGame__GFxUDKFrontEnd_JoinDialog.h"
#include "UTGame__GFxUDKFrontEnd_InfoDialog.h"
#include "UTGame__GFxUDKFrontEnd_ServerSettings.h"
#include "UTGame__GFxUDKFrontEnd_HostGame.h"
#include "UTGame__GFxUDKFrontEnd_JoinGame.h"
#include "UTGame__GFxUDKFrontEnd_Settings.h"
#include "UTGame__GFxUDKFrontEnd_Mutators.h"
#include "UTGame__GFxUDKFrontEnd_Multiplayer.h"
#include "UTGame__GFxUDKFrontEnd_InstantAction.h"
#include "UTGame__GFxUDKFrontEnd_MainMenu.h"
#include "GFxUI__GFxObject.h"
#include "UTGame__GFxUDKFrontEnd_Screen.h"
#include "UTGame__GFxUDKFrontEnd_Dialog.h"
#include "UTGame__GFxUDKFrontEnd_View.h"
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
		// Here lies the not-yet-implemented method 'EscapeDelegate'
		// Here lies the not-yet-implemented method 'Start'
		// Here lies the not-yet-implemented method 'ConfigFrontEnd'
		// Here lies the not-yet-implemented method 'ASShowCursor'
		// Here lies the not-yet-implemented method 'LoadViews'
		// Here lies the not-yet-implemented method 'LoadView'
		// Here lies the not-yet-implemented method 'LoadViewByName'
		// Here lies the not-yet-implemented method 'IsViewLoaded'
		// Here lies the not-yet-implemented method 'SetEscapeDelegate'
		// Here lies the not-yet-implemented method 'PushViewByName'
		// Here lies the not-yet-implemented method 'SpawnDialog'
		// Here lies the not-yet-implemented method 'ConfigureTargetDialog'
		// Here lies the not-yet-implemented method 'ConfigureTargetView'
		// Here lies the not-yet-implemented method 'IsViewAllowed'
		// Here lies the not-yet-implemented method 'PushView'
		// Here lies the not-yet-implemented method 'PushDialogView'
		// Here lies the not-yet-implemented method 'SetSelectionFocus'
		// Here lies the not-yet-implemented method 'ASSetSelectionFocus'
		// Here lies the not-yet-implemented method 'PopView'
		// Here lies the not-yet-implemented method 'PopViewStub'
		// Here lies the not-yet-implemented method 'UpdateViewLayout'
		// Here lies the not-yet-implemented method 'ConfigureView'
		// Here lies the not-yet-implemented method 'PostWidgetInit'
		// Here lies the not-yet-implemented method 'CheckLinkConnectionAndError'
		// Here lies the not-yet-implemented method 'WidgetInitialized'
		// Here lies the not-yet-implemented method 'LoadDependantViews'
		// Here lies the not-yet-implemented method 'DestroyDependantViews'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
