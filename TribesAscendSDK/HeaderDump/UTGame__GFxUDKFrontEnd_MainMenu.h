#pragma once
#include "GFxUI__GFxObject.h"
#include "UTGame__GFxUDKFrontEnd_Screen.h"
#include "GFxUI__GFxClikWidget.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUDKFrontEnd_MainMenu." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUDKFrontEnd_MainMenu." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_MainMenu : public GFxUDKFrontEnd_Screen
	{
	public:
		ADD_OBJECT(GFxClikWidget, ListMC)
		ADD_VAR(::ByteProperty, LastSelectedIndex, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, UserNameTxt)
		ADD_OBJECT(GFxObject, UserLabelTxt)
		ADD_OBJECT(GFxObject, ListDataProvider)
		// Here lies the not-yet-implemented method 'OnViewLoaded'
		// Here lies the not-yet-implemented method 'OnTopMostView'
		// Here lies the not-yet-implemented method 'DisableSubComponents'
		// Here lies the not-yet-implemented method 'Select_InstantAction'
		// Here lies the not-yet-implemented method 'Select_Multiplayer'
		// Here lies the not-yet-implemented method 'Select_ExitGame'
		// Here lies the not-yet-implemented method 'ExitDialog_SelectOK'
		// Here lies the not-yet-implemented method 'ExitDialog_SelectBack'
		// Here lies the not-yet-implemented method 'OnListItemPress'
		// Here lies the not-yet-implemented method 'OnListChange'
		// Here lies the not-yet-implemented method 'UpdateDescription'
		// Here lies the not-yet-implemented method 'UpdateListDataProvider'
		// Here lies the not-yet-implemented method 'SetList'
		// Here lies the not-yet-implemented method 'OnEscapeKeyPress'
		// Here lies the not-yet-implemented method 'WidgetInitialized'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
