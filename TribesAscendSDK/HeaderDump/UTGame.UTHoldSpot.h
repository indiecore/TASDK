#pragma once
#include "Engine.NavigationPoint.h"
#include "UTGame.UTDefensePoint.h"
#include "UTGame.UTVehicle.h"
#include "Engine.Actor.h"
#include "Engine.Pawn.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTHoldSpot : public UTDefensePoint
	{
	public:
		ADD_OBJECT(NavigationPoint, LastAnchor, 744)
		ADD_OBJECT(UTVehicle, HoldVehicle, 740)
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHoldSpot.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Actor* GetMoveTarget()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHoldSpot.GetMoveTarget");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[0];
		}
		void FreePoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHoldSpot.FreePoint");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class NavigationPoint* SpecifyEndAnchor(class Pawn* RouteFinder)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHoldSpot.SpecifyEndAnchor");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = RouteFinder;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class NavigationPoint**)&params[4];
		}
		void NotifyAnchorFindingResult(class NavigationPoint* EndAnchor, class Pawn* RouteFinder)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHoldSpot.NotifyAnchorFindingResult");
			byte params[8] = { NULL };
			*(class NavigationPoint**)&params[0] = EndAnchor;
			*(class Pawn**)&params[4] = RouteFinder;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_OBJECT
