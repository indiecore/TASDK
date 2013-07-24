#pragma once
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
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
