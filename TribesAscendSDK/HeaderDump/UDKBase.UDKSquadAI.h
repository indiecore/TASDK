#pragma once
#include "UDKBase.UDKBot.h"
#include "UDKBase.UDKTeamOwnedInfo.h"
#include "Engine.NavigationPoint.h"
#include "UDKBase.UDKGameObjective.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UDKSquadAI : public UDKTeamOwnedInfo
	{
	public:
		class AlternateRoute
		{
		public:
			ADD_STRUCT(ScriptArray<class NavigationPoint*>, RouteCache, 0)
		};
		ADD_STRUCT(ScriptArray<class NavigationPoint*>, ObjectiveRouteCache, 488)
		ADD_STRUCT(ScriptArray<class NavigationPoint*>, PreviousObjectiveRouteCache, 500)
		ADD_STRUCT(ScriptArray<UDKSquadAI::AlternateRoute>, SquadRoutes, 520)
		ADD_STRUCT(int, MaxSquadRoutes, 532)
		ADD_STRUCT(int, SquadRouteIteration, 516)
		ADD_OBJECT(UDKBot, PendingSquadRouteMaker, 512)
		ADD_OBJECT(NavigationPoint, RouteObjective, 484)
		ADD_OBJECT(UDKGameObjective, SquadObjective, 480)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
