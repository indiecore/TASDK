#pragma once
#include "UTGame__GFxUDKFrontEnd_View.h"
#include "GFxUI__GFxClikWidget.h"
#include "GFxUI__GFxObject.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUDKFrontEnd_Dialog." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_Dialog : public GFxUDKFrontEnd_View
	{
	public:
		ADD_OBJECT(GFxClikWidget, AcceptBtn)
		ADD_OBJECT(GFxClikWidget, BackBtn)
		ADD_OBJECT(GFxObject, InfoTxt)
		ADD_OBJECT(GFxObject, TitleTxt)
		ADD_OBJECT(GFxObject, DialogMC)
		// Here lies the not-yet-implemented method 'AcceptDelegate'
		// Here lies the not-yet-implemented method 'OnViewClosed'
		// Here lies the not-yet-implemented method 'DisableSubComponents'
		// Here lies the not-yet-implemented method 'OnTopMostView'
		// Here lies the not-yet-implemented method 'PlayOpenAnimation'
		// Here lies the not-yet-implemented method 'PlayCloseAnimation'
		// Here lies the not-yet-implemented method 'SetBackButton'
		// Here lies the not-yet-implemented method 'SetBackButton_OnPress'
		// Here lies the not-yet-implemented method 'Select_Back'
		// Here lies the not-yet-implemented method 'WidgetInitialized'
	};
}
#undef ADD_OBJECT
