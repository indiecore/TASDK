#pragma once
#include "GFxUI__GFxObject.h"
#include "UTGame__GFxUDKFrontEnd_Screen.h"
#include "UTGame__UTUIDataStore_MenuItems.h"
#include "GFxUI__GFxClikWidget.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUDKFrontEnd_Mutators." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUDKFrontEnd_Mutators." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_Mutators : public GFxUDKFrontEnd_Screen
	{
	public:
		ADD_VAR(::BoolProperty, bFirstUpdateAfterActivation, 0x1)
		ADD_OBJECT(GFxObject, ConfigListDataProvider)
		ADD_OBJECT(GFxClikWidget, ConfigListMC)
		ADD_OBJECT(GFxObject, ListDataProvider)
		ADD_OBJECT(GFxObject, MenuMC)
		ADD_OBJECT(GFxClikWidget, ListMC)
		ADD_OBJECT(UTUIDataStore_MenuItems, MenuDataStore)
		// Here lies the not-yet-implemented method 'GetNumEnabledMutators'
		// Here lies the not-yet-implemented method 'GetEnabledMutators'
		// Here lies the not-yet-implemented method 'OnViewLoaded'
		// Here lies the not-yet-implemented method 'OnViewActivated'
		// Here lies the not-yet-implemented method 'SortAllMutatorsBasedOnOfficialArray'
		// Here lies the not-yet-implemented method 'OnTopMostView'
		// Here lies the not-yet-implemented method 'DisableSubComponents'
		// Here lies the not-yet-implemented method 'PlayOpenAnimation'
		// Here lies the not-yet-implemented method 'OnListItemPress'
		// Here lies the not-yet-implemented method 'FindMutatorIndexByClass'
		// Here lies the not-yet-implemented method 'OnListChange'
		// Here lies the not-yet-implemented method 'UpdateDescription'
		// Here lies the not-yet-implemented method 'UpdateListDataProvider'
		// Here lies the not-yet-implemented method 'UpdateConfigListDataProvider'
		// Here lies the not-yet-implemented method 'SetMutatorEnabled'
		// Here lies the not-yet-implemented method 'AddMutatorAndFilterList'
		// Here lies the not-yet-implemented method 'ApplyGameModeFilter'
		// Here lies the not-yet-implemented method 'IsCurrentMutatorConfigurable'
		// Here lies the not-yet-implemented method 'SetList'
		// Here lies the not-yet-implemented method 'SetConfigList'
		// Here lies the not-yet-implemented method 'WidgetInitialized'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
