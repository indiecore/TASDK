#pragma once
#include "UTGame__GFxUIView.h"
#include "GFxUI__GFxObject.h"
#include "UTGame__GFxUDKFrontEnd.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUDKFrontEnd_View." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUDKFrontEnd_View." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_View : public GFxUIView
	{
	public:
		ADD_VAR(::NameProperty, ViewName, 0xFFFFFFFF)
		ADD_OBJECT(GFxUDKFrontEnd, MenuManager)
		// Here lies the not-yet-implemented method 'OnViewLoaded'
		// Here lies the not-yet-implemented method 'OnTopMostView'
		// Here lies the not-yet-implemented method 'OnViewActivated'
		// Here lies the not-yet-implemented method 'OnViewClosed'
		// Here lies the not-yet-implemented method 'DisableSubComponents'
		// Here lies the not-yet-implemented method 'PlayOpenAnimation'
		// Here lies the not-yet-implemented method 'PlayCloseAnimation'
		// Here lies the not-yet-implemented method 'Select_Back'
		// Here lies the not-yet-implemented method 'MoveBackImpl'
		// Here lies the not-yet-implemented method 'OnEscapeKeyPress'
		// Here lies the not-yet-implemented method 'WidgetInitialized'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
