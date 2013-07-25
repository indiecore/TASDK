#pragma once
#include "Engine.NavigationPoint.h"
#include "Engine.Controller.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.DynamicAnchor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class DynamicAnchor : public NavigationPoint
	{
	public:
		ADD_OBJECT(Controller, CurrentUser)
	};
}
#undef ADD_OBJECT
