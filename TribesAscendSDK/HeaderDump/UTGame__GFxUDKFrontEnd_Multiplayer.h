#pragma once
#include "GFxUI__GFxObject.h"
#include "UTGame__GFxUDKFrontEnd_Screen.h"
#include "GFxUI__GFxClikWidget.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUDKFrontEnd_Multiplayer." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_Multiplayer : public GFxUDKFrontEnd_Screen
	{
	public:
		ADD_OBJECT(GFxObject, MenuMC)
		ADD_OBJECT(GFxObject, ListDataProvider)
		ADD_OBJECT(GFxClikWidget, ListMC)
		// Here lies the not-yet-implemented method 'OnViewLoaded'
		// Here lies the not-yet-implemented method 'OnTopMostView'
		// Here lies the not-yet-implemented method 'DisableSubComponents'
		// Here lies the not-yet-implemented method 'Select_JoinGame'
		// Here lies the not-yet-implemented method 'Select_HostGame'
		// Here lies the not-yet-implemented method 'OnListItemPress'
		// Here lies the not-yet-implemented method 'OnListChange'
		// Here lies the not-yet-implemented method 'UpdateDescription'
		// Here lies the not-yet-implemented method 'UpdateListDataProvider'
		// Here lies the not-yet-implemented method 'SetList'
		// Here lies the not-yet-implemented method 'WidgetInitialized'
	};
}
#undef ADD_OBJECT
