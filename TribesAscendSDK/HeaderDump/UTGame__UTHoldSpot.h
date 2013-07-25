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
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHoldSpot.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Actor* GetMoveTarget()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHoldSpot.GetMoveTarget");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)params;
			free(params);
			return returnVal;
		}
		void FreePoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHoldSpot.FreePoint");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class NavigationPoint* SpecifyEndAnchor(class Pawn* RouteFinder)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHoldSpot.SpecifyEndAnchor");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = RouteFinder;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class NavigationPoint**)(params + 4);
			free(params);
			return returnVal;
		}
		void NotifyAnchorFindingResult(class NavigationPoint* EndAnchor, class Pawn* RouteFinder)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHoldSpot.NotifyAnchorFindingResult");
			byte* params = (byte*)malloc(8);
			*(class NavigationPoint**)params = EndAnchor;
			*(class Pawn**)(params + 4) = RouteFinder;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_OBJECT
