#pragma once
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
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
