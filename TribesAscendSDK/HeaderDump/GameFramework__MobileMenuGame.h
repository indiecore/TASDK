#pragma once
#include "Engine__GameInfo.h"
#include "Engine__PlayerController.h"
#include "Engine__Controller.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.MobileMenuGame." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MobileMenuGame : public GameInfo
	{
	public:
		ADD_OBJECT(ScriptClass, InitialSceneToDisplayClass)
		// Here lies the not-yet-implemented method 'PostLogin'
		// Here lies the not-yet-implemented method 'StartMatch'
		// Here lies the not-yet-implemented method 'RestartPlayer'
	};
}
#undef ADD_OBJECT
