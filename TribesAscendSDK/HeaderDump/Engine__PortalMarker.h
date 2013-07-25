#pragma once
#include "Engine__PortalTeleporter.h"
#include "Engine__NavigationPoint.h"
#include "Engine__Actor.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.PortalMarker." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PortalMarker : public NavigationPoint
	{
	public:
		ADD_OBJECT(PortalTeleporter, MyPortal)
		// Here lies the not-yet-implemented method 'CanTeleport'
	};
}
#undef ADD_OBJECT
