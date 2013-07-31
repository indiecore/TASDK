#pragma once
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "UTGame.UTBot.h"
#include "UTGame.UTCTFFlag.h"
#include "UTGame.UTSquadAI.h"
#include "Engine.NavigationPoint.h"
#include "UDKBase.UDKSquadAI.h"
#include "Engine.Pawn.h"
#include "UTGame.UTVehicle.h"
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
	class UTCTFSquadAI : public UTSquadAI
	{
	public:
		ADD_OBJECT(UTCTFFlag, EnemyFlag, 688)
		ADD_OBJECT(UTCTFFlag, FriendlyFlag, 684)
		ADD_STRUCT(ScriptArray<UDKSquadAI::AlternateRoute>, EnemyFlagRoutes, 696)
		ADD_STRUCT(ScriptArray<UDKSquadAI::AlternateRoute>, FriendlyFlagRoutes, 708)
		ADD_OBJECT(NavigationPoint, HidePath, 692)
		ADD_STRUCT(float, LastSeeFlagCarrier, 680)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46551);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool AllowDetourTo(class UTBot* B, class NavigationPoint* N)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46552);
			byte params[12] = { NULL };
			*(class UTBot**)params = B;
			*(class NavigationPoint**)&params[4] = N;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool ShouldUseAlternatePaths()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46556);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SetAlternatePathTo(class NavigationPoint* NewRouteObjective, class UTBot* RouteMaker)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46558);
			byte params[8] = { NULL };
			*(class NavigationPoint**)params = NewRouteObjective;
			*(class UTBot**)&params[4] = RouteMaker;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool BeDevious(class Pawn* Enemy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46562);
			byte params[8] = { NULL };
			*(class Pawn**)params = Enemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool FindPathToObjective(class UTBot* B, class Actor* O)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46565);
			byte params[12] = { NULL };
			*(class UTBot**)params = B;
			*(class Actor**)&params[4] = O;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool GoPickupFlag(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46569);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class Actor* FormationCenter(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46574);
			byte params[8] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[4];
		}
		bool VisibleToEnemiesOf(class Actor* A, class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46577);
			byte params[12] = { NULL };
			*(class Actor**)params = A;
			*(class UTBot**)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		class NavigationPoint* FindHidePathFor(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46581);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class NavigationPoint**)&params[4];
		}
		bool CheckVehicle(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46585);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool OrdersForFlagCarrier(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46588);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool MustKeepEnemy(class Pawn* E)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46592);
			byte params[8] = { NULL };
			*(class Pawn**)params = E;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool NearEnemyBase(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46595);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool NearHomeBase(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46598);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool FlagNearBase()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46601);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool OverrideFollowPlayer(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46603);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CheckSquadObjectives(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46606);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void EnemyFlagTakenBy(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46612);
			byte params[4] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AllowTaunt(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46615);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ShouldDeferTo(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46618);
			byte params[8] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		byte PriorityObjective(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46621);
			byte params[5] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[4];
		}
		float ModifyThreat(float Current, class Pawn* NewThreat, bool bThreatVisible, class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46624);
			byte params[20] = { NULL };
			*(float*)params = Current;
			*(class Pawn**)&params[4] = NewThreat;
			*(bool*)&params[8] = bThreatVisible;
			*(class UTBot**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[16];
		}
		bool AllowContinueOnFoot(class UTBot* B, class UTVehicle* V)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46630);
			byte params[12] = { NULL };
			*(class UTBot**)params = B;
			*(class UTVehicle**)&params[4] = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void ModifyAggression(class UTBot* B, float& Aggression)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46634);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			*(float*)&params[4] = Aggression;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Aggression = *(float*)&params[4];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
