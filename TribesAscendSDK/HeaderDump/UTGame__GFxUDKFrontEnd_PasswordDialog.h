#pragma once
#include "GFxUI__GFxClikWidget.h"
#include "UTGame__GFxUDKFrontEnd_Dialog.h"
#include "GFxUI__GFxObject.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUDKFrontEnd_PasswordDialog." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_PasswordDialog : public GFxUDKFrontEnd_Dialog
	{
	public:
		ADD_OBJECT(GFxClikWidget, JoinBtn)
		ADD_OBJECT(GFxObject, PasswordTextField)
		ADD_OBJECT(GFxClikWidget, PasswordRendererMC)
		// Here lies the not-yet-implemented method 'GetPassword'
		// Here lies the not-yet-implemented method 'OnTopMostView'
		// Here lies the not-yet-implemented method 'ClearPasswordRenderer'
		// Here lies the not-yet-implemented method 'OnViewClosed'
		// Here lies the not-yet-implemented method 'DisableSubComponents'
		// Here lies the not-yet-implemented method 'SetBackButtonListener'
		// Here lies the not-yet-implemented method 'SetOKButtonListener'
		// Here lies the not-yet-implemented method 'WidgetInitialized'
	};
}
#undef ADD_OBJECT
