#pragma once
#include "Engine.NavigationPoint.h"
#include "UDKBase.UDKSquadAI.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "UTGame.UTBot.h"
#include "Engine.Controller.h"
#include "Engine.Pawn.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#include "UTGame.UTVehicle.h"
#include "UTGame.UTTeamInfo.h"
#include "UTGame.UTGameObjective.h"
#include "Engine.PlayerController.h"
#include "Engine.HUD.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class UTSquadAI : public UDKSquadAI
	{
	public:
		static const float NEAROBJECTIVEDIST;
		ADD_OBJECT(Controller, SquadLeader, 536)
		ADD_OBJECT(UTBot, SquadMembers, 552)
		ADD_STRUCT(float, FormationSize, 676)
		ADD_BOOL(bShouldUseGatherPoints, 672, 0x20)
		ADD_BOOL(bAddTransientCosts, 672, 0x10)
		ADD_BOOL(bRoamingSquad, 672, 0x8)
		ADD_BOOL(bFreelanceDefend, 672, 0x4)
		ADD_BOOL(bFreelanceAttack, 672, 0x2)
		ADD_BOOL(bFreelance, 672, 0x1)
		ADD_STRUCT(int, MaxSquadSize, 668)
		ADD_OBJECT(Pawn, Enemies, 636)
		ADD_STRUCT(ScriptName, CurrentOrders, 628)
		ADD_STRUCT(ScriptString*, SupportStringTrailer, 616)
		ADD_STRUCT(ScriptString*, FreelanceString, 604)
		ADD_STRUCT(ScriptString*, HoldString, 592)
		ADD_STRUCT(ScriptString*, AttackString, 580)
		ADD_STRUCT(ScriptString*, DefendString, 568)
		ADD_STRUCT(ScriptString*, SupportString, 556)
		ADD_STRUCT(int, Size, 548)
		ADD_OBJECT(UTSquadAI, NextSquad, 544)
		ADD_OBJECT(UTPlayerReplicationInfo, LeaderPRI, 540)
		bool AllowContinueOnFoot(class UTBot* B, class UTVehicle* V)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39422);
			byte params[12] = { NULL };
			*(class UTBot**)params = B;
			*(class UTVehicle**)&params[4] = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool AllowImpactJumpBy(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42587);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		ScriptName GetOrders()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42656);
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)params;
		}
		bool SetEnemy(class UTBot* B, class Pawn* NewEnemy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42679);
			byte params[12] = { NULL };
			*(class UTBot**)params = B;
			*(class Pawn**)&params[4] = NewEnemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool AssignSquadResponsibility(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42706);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool FindNewEnemyFor(class UTBot* B, bool bSeeEnemy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42774);
			byte params[12] = { NULL };
			*(class UTBot**)params = B;
			*(bool*)&params[4] = bSeeEnemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool MustKeepEnemy(class Pawn* E)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42776);
			byte params[8] = { NULL };
			*(class Pawn**)params = E;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsDefending(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42778);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool HasOtherVisibleEnemy(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42799);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		byte PriorityObjective(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42808);
			byte params[5] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[4];
		}
		bool AllowDetourTo(class UTBot* B, class NavigationPoint* N)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42875);
			byte params[12] = { NULL };
			*(class UTBot**)params = B;
			*(class NavigationPoint**)&params[4] = N;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		class Actor* SetFacingActor(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43026);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[4];
		}
		class Actor* FormationCenter(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43080);
			byte params[8] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[4];
		}
		bool AcceptableDefensivePosition(class NavigationPoint* N, class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43086);
			byte params[12] = { NULL };
			*(class NavigationPoint**)params = N;
			*(class UTBot**)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		class NavigationPoint* FindDefensivePositionFor(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43088);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class NavigationPoint**)&params[4];
		}
		bool ClearPathFor(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43119);
			byte params[8] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool LostEnemy(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43159);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool PickRetreatDestination(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43165);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool BeDevious(class Pawn* Enemy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43314);
			byte params[8] = { NULL };
			*(class Pawn**)params = Enemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ShouldSuppressEnemy(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43367);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float VehicleDesireability(class UTVehicle* V, class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43551);
			byte params[12] = { NULL };
			*(class UTVehicle**)params = V;
			*(class UTBot**)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		bool HandlePathObstruction(class UTBot* B, class Actor* BlockedBy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43553);
			byte params[12] = { NULL };
			*(class UTBot**)params = B;
			*(class Actor**)&params[4] = BlockedBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool FindPathToObjective(class UTBot* B, class Actor* O)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44423);
			byte params[12] = { NULL };
			*(class UTBot**)params = B;
			*(class Actor**)&params[4] = O;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		int GetSize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44427);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46165);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CriticalObjectiveWarning(class Pawn* NewEnemy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46167);
			byte params[4] = { NULL };
			*(class Pawn**)params = NewEnemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46173);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class UTVehicle* GetLinkVehicle(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46176);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTVehicle**)&params[4];
		}
		Rotator GetFacingRotation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46180);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)params;
		}
		bool AddEnemy(class Pawn* NewEnemy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46189);
			byte params[8] = { NULL };
			*(class Pawn**)params = NewEnemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ValidEnemy(class Pawn* NewEnemy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46195);
			byte params[8] = { NULL };
			*(class Pawn**)params = NewEnemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsOnSquad(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46203);
			byte params[8] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void RemoveEnemy(class Pawn* E)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46206);
			byte params[4] = { NULL };
			*(class Pawn**)params = E;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyKilled(class Controller* Killer, class Controller* Killed, class Pawn* KilledPawn, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46210);
			byte params[16] = { NULL };
			*(class Controller**)params = Killer;
			*(class Controller**)&params[4] = Killed;
			*(class Pawn**)&params[8] = KilledPawn;
			*(ScriptClass**)&params[12] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float ModifyThreat(float Current, class Pawn* NewThreat, bool bThreatVisible, class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46225);
			byte params[20] = { NULL };
			*(float*)params = Current;
			*(class Pawn**)&params[4] = NewThreat;
			*(bool*)&params[8] = bThreatVisible;
			*(class UTBot**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[16];
		}
		bool UnderFire(class Pawn* NewThreat, class UTBot* Ignored)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46231);
			byte params[12] = { NULL };
			*(class Pawn**)params = NewThreat;
			*(class UTBot**)&params[4] = Ignored;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		float AssessThreat(class UTBot* B, class Pawn* NewThreat, bool bThreatVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46236);
			byte params[16] = { NULL };
			*(class UTBot**)params = B;
			*(class Pawn**)&params[4] = NewThreat;
			*(bool*)&params[8] = bThreatVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		bool ShouldDeferTo(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46244);
			byte params[8] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool WaitAtThisPosition(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46247);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool WanderNearLeader(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46250);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool NearFormationCenter(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46253);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CloseToLeader(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46257);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void MergeWith(class UTSquadAI* S)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46261);
			byte params[4] = { NULL };
			*(class UTSquadAI**)params = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Initialize(class UTTeamInfo* T, class UTGameObjective* O, class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46263);
			byte params[12] = { NULL };
			*(class UTTeamInfo**)params = T;
			*(class UTGameObjective**)&params[4] = O;
			*(class Controller**)&params[8] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldUseAlternatePaths()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46267);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SetAlternatePathTo(class NavigationPoint* NewRouteObjective, class UTBot* RouteMaker)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46269);
			byte params[8] = { NULL };
			*(class NavigationPoint**)params = NewRouteObjective;
			*(class UTBot**)&params[4] = RouteMaker;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool TryToIntercept(class UTBot* B, class Pawn* P, class Actor* RouteGoal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46273);
			byte params[16] = { NULL };
			*(class UTBot**)params = B;
			*(class Pawn**)&params[4] = P;
			*(class Actor**)&params[8] = RouteGoal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool CloseEnoughToObjective(class UTBot* B, class Actor* O)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46278);
			byte params[12] = { NULL };
			*(class UTBot**)params = B;
			*(class Actor**)&params[4] = O;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool LeaveVehicleToReachObjective(class UTBot* B, class Actor* O)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46282);
			byte params[12] = { NULL };
			*(class UTBot**)params = B;
			*(class Actor**)&params[4] = O;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool MustCompleteOnFoot(class Actor* O, class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46287);
			byte params[12] = { NULL };
			*(class Actor**)params = O;
			*(class Pawn**)&params[4] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void LeaveVehicleAtParkingSpot(class UTBot* B, class Actor* O)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46292);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			*(class Actor**)&params[4] = O;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLeader(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46305);
			byte params[4] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemovePlayer(class PlayerController* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46307);
			byte params[4] = { NULL };
			*(class PlayerController**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveBot(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46312);
			byte params[4] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddBot(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46315);
			byte params[4] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDefenseScriptFor(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46318);
			byte params[4] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetObjective(class UTGameObjective* O, bool bForceUpdate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46336);
			byte params[8] = { NULL };
			*(class UTGameObjective**)params = O;
			*(bool*)&params[4] = bForceUpdate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Retask(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46341);
			byte params[4] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetOrderStringFor(class UTPlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46349);
			byte params[16] = { NULL };
			*(class UTPlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* GetShortOrderStringFor(class UTPlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46353);
			byte params[16] = { NULL };
			*(class UTPlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void PickNewLeader()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46356);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool TellBotToFollow(class UTBot* B, class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46358);
			byte params[12] = { NULL };
			*(class UTBot**)params = B;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool AllowTaunt(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46368);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void AddTransientCosts(class UTBot* B, float F)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46371);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			*(float*)&params[4] = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float MaxVehicleDist(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46376);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		bool NeverBail(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46386);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void BotEnteredVehicle(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46389);
			byte params[4] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsOnPathToSquadObjective(class Actor* Goal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46391);
			byte params[8] = { NULL };
			*(class Actor**)params = Goal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool GetOnHoverboard(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46396);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool EnterAndExitVehicle(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46400);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool GotoVehicle(class UTVehicle* SquadVehicle, class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46404);
			byte params[12] = { NULL };
			*(class UTVehicle**)params = SquadVehicle;
			*(class UTBot**)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool CheckVehicle(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46410);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CheckHoverboard(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46427);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ShouldUseHoverboard(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46431);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool OverrideFollowPlayer(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46438);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ShouldCheckSuperVehicle(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46443);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CheckSuperItem(class UTBot* B, float SuperDist)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46447);
			byte params[12] = { NULL };
			*(class UTBot**)params = B;
			*(float*)&params[4] = SuperDist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool CheckSquadObjectives(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46464);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float BotSuitability(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46475);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		class UTBot* PickBotToReassign()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46478);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTBot**)params;
		}
		void DisplayDebug(class HUD* HUD, float& YL, float& YPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46486);
			byte params[12] = { NULL };
			*(class HUD**)params = HUD;
			*(float*)&params[4] = YL;
			*(float*)&params[8] = YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			YL = *(float*)&params[4];
			YPos = *(float*)&params[8];
		}
		bool FriendlyToward(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46500);
			byte params[8] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float GetMaxDefenseDistanceFrom(class Actor* Center, class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46506);
			byte params[12] = { NULL };
			*(class Actor**)params = Center;
			*(class UTBot**)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float RateDefensivePosition(class NavigationPoint* N, class UTBot* CurrentBot, class Actor* Center)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46517);
			byte params[16] = { NULL };
			*(class NavigationPoint**)params = N;
			*(class UTBot**)&params[4] = CurrentBot;
			*(class Actor**)&params[8] = Center;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		void MarkHuntingSpots(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46536);
			byte params[4] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ModifyAggression(class UTBot* B, float& Aggression)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46538);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			*(float*)&params[4] = Aggression;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Aggression = *(float*)&params[4];
		}
	};
	const float UTSquadAI::NEAROBJECTIVEDIST = 2000.0f;
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
