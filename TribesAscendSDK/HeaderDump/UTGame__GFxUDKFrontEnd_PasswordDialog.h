#pragma once
#include "UTGame__GFxUDKFrontEnd_Dialog.h"
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
	};
}
#undef ADD_OBJECT
