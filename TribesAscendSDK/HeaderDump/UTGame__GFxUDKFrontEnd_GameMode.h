#pragma once
#include "UTGame__GFxUDKFrontEnd_Screen.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUDKFrontEnd_GameMode." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUDKFrontEnd_GameMode." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_GameMode : public GFxUDKFrontEnd_Screen
	{
	public:
		ADD_OBJECT(GFxClikWidget, ImgScrollerMC)
		ADD_OBJECT(GFxObject, MenuMC)
		ADD_OBJECT(GFxObject, ListDataProvider)
		ADD_OBJECT(GFxClikWidget, ListMC)
		ADD_VAR(::StrProperty, MapName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, GameMode, 0xFFFFFFFF)
		ADD_OBJECT(UTUIDataStore_StringList, StringListDataStore)
		ADD_OBJECT(UIDataStore_OnlineGameSettings, SettingsDataStore)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
