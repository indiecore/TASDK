#pragma once
#include "GFxUI__GFxObject.h"
#include "UTGame__GFxUDKFrontEnd_Screen.h"
#include "Engine__UIDataStore_OnlineGameSettings.h"
#include "GFxUI__GFxClikWidget.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUDKFrontEnd_SettingsBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUDKFrontEnd_SettingsBase." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_SettingsBase : public GFxUDKFrontEnd_Screen
	{
	public:
		ADD_OBJECT(UIDataStore_OnlineGameSettings, SettingsDataStore)
		ADD_OBJECT(GFxObject, MenuMC)
		ADD_OBJECT(GFxObject, ListDataProvider)
		ADD_VAR(::StrProperty, SelectedOptionSet, 0xFFFFFFFF)
		ADD_OBJECT(GFxClikWidget, ListMC)
		// Here lies the not-yet-implemented method 'OnViewLoaded'
		// Here lies the not-yet-implemented method 'OnViewActivated'
		// Here lies the not-yet-implemented method 'OnTopMostView'
		// Here lies the not-yet-implemented method 'DisableSubComponents'
		// Here lies the not-yet-implemented method 'SetSelectedOptionSet'
		// Here lies the not-yet-implemented method 'LoadDataFromStore'
		// Here lies the not-yet-implemented method 'Select_Back'
		// Here lies the not-yet-implemented method 'SaveState'
		// Here lies the not-yet-implemented method 'SetList'
		// Here lies the not-yet-implemented method 'OnListChange'
		// Here lies the not-yet-implemented method 'OnOptionChanged'
		// Here lies the not-yet-implemented method 'UpdateDescription'
		// Here lies the not-yet-implemented method 'UpdateListDataProvider'
		// Here lies the not-yet-implemented method 'FindLocalizedSettingIndexByName'
		// Here lies the not-yet-implemented method 'OnEscapeKeyPress'
		// Here lies the not-yet-implemented method 'Select_BackImpl'
		// Here lies the not-yet-implemented method 'FindPropertyIndexByName'
		// Here lies the not-yet-implemented method 'WidgetInitialized'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
