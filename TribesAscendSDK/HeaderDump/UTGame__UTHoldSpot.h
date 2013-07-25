#pragma once
#include "UTGame__UTDefensePoint.h"
#include "Engine__Pawn.h"
#include "Engine__NavigationPoint.h"
#include "UTGame__UTVehicle.h"
#include "Engine__Actor.h"
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
		// Here lies the not-yet-implemented method 'PreBeginPlay'
		// Here lies the not-yet-implemented method 'GetMoveTarget'
		// Here lies the not-yet-implemented method 'FreePoint'
		// Here lies the not-yet-implemented method 'SpecifyEndAnchor'
		// Here lies the not-yet-implemented method 'NotifyAnchorFindingResult'
	};
}
#undef ADD_OBJECT
