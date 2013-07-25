#pragma once
#include "UTGame__UTDefensePoint.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTHoldSpot." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTHoldSpot : public UTDefensePoint
	{
	public:
		ADD_OBJECT(NavigationPoint, LastAnchor)
		ADD_OBJECT(UTVehicle, HoldVehicle)
	};
}
#undef ADD_OBJECT
