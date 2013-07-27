#pragma once
#include "Engine.NavigationPoint.h"
#include "Engine.PortalTeleporter.h"
#include "Engine.Actor.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class PortalMarker : public NavigationPoint
	{
	public:
		ADD_OBJECT(PortalTeleporter, MyPortal, 692)
		bool CanTeleport(class Actor* A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PortalMarker.CanTeleport");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_OBJECT
