#pragma once
#include "GFxUI__GFxClikWidget.h"
#include "UTGame__GFxUDKFrontEnd_Dialog.h"
#include "Engine__OnlineGameSettings.h"
#include "GFxUI__GFxObject.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUDKFrontEnd_JoinDialog." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_JoinDialog : public GFxUDKFrontEnd_Dialog
	{
	public:
		ADD_OBJECT(GFxClikWidget, SpectateBtn)
		ADD_OBJECT(GFxClikWidget, JoinBtn)
		ADD_OBJECT(GFxClikWidget, MutatorListMC)
		ADD_OBJECT(GFxClikWidget, ServerInfoListMC)
		// Here lies the not-yet-implemented method 'OnTopMostView'
		// Here lies the not-yet-implemented method 'DisableSubComponents'
		// Here lies the not-yet-implemented method 'PopulateServerInfo'
		// Here lies the not-yet-implemented method 'SetJoinButtonPress'
		// Here lies the not-yet-implemented method 'SetSpectateButtonPress'
		// Here lies the not-yet-implemented method 'WidgetInitialized'
	};
}
#undef ADD_OBJECT
