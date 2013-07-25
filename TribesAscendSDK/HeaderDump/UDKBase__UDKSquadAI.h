#pragma once
#include "UDKBase__UDKTeamOwnedInfo.h"
#include "UDKBase__UDKBot.h"
#include "Engine__NavigationPoint.h"
#include "UDKBase__UDKGameObjective.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKSquadAI." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKSquadAI." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKSquadAI : public UDKTeamOwnedInfo
	{
	public:
		ADD_VAR(::IntProperty, MaxSquadRoutes, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SquadRouteIteration, 0xFFFFFFFF)
		ADD_OBJECT(UDKBot, PendingSquadRouteMaker)
		ADD_OBJECT(NavigationPoint, RouteObjective)
		ADD_OBJECT(UDKGameObjective, SquadObjective)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
