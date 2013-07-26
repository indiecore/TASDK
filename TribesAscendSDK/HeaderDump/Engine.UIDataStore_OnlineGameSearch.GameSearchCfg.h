#pragma once
#include "Engine.OnlineGameSearch.h"
#include "Engine.UIDataProvider_Settings.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UIDataStore_OnlineGameSearch.GameSearchCfg." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UIDataStore_OnlineGameSearch.GameSearchCfg." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameSearchCfg
	{
	public:
		ADD_VAR(::NameProperty, SearchName, 0xFFFFFFFF)
		ADD_OBJECT(OnlineGameSearch, Search)
		ADD_OBJECT(UIDataProvider_Settings, DesiredSettingsProvider)
		ADD_OBJECT(ScriptClass, SearchResultsProviderClass)
		ADD_OBJECT(ScriptClass, DefaultGameSettingsClass)
		ADD_OBJECT(ScriptClass, GameSearchClass)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
