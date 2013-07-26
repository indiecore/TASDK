#pragma once
#include "Engine.Actor.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Controller.VisiblePortalInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class VisiblePortalInfo
	{
	public:
		ADD_OBJECT(Actor, Destination)
		ADD_OBJECT(Actor, Source)
	};
}
#undef ADD_OBJECT
