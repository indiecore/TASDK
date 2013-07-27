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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.AllowContinueOnFoot");
			byte params[12] = { NULL };
			*(class UTBot**)&params[0] = B;
			*(class UTVehicle**)&params[4] = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool AllowImpactJumpBy(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.AllowImpactJumpBy");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		ScriptName GetOrders()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.GetOrders");
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[0];
		}
		bool SetEnemy(class UTBot* B, class Pawn* NewEnemy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.SetEnemy");
			byte params[12] = { NULL };
			*(class UTBot**)&params[0] = B;
			*(class Pawn**)&params[4] = NewEnemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool AssignSquadResponsibility(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.AssignSquadResponsibility");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool FindNewEnemyFor(class UTBot* B, bool bSeeEnemy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.FindNewEnemyFor");
			byte params[12] = { NULL };
			*(class UTBot**)&params[0] = B;
			*(bool*)&params[4] = bSeeEnemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool MustKeepEnemy(class Pawn* E)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.MustKeepEnemy");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = E;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsDefending(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.IsDefending");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool HasOtherVisibleEnemy(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.HasOtherVisibleEnemy");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		byte PriorityObjective(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.PriorityObjective");
			byte params[5] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[4];
		}
		bool AllowDetourTo(class UTBot* B, class NavigationPoint* N)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.AllowDetourTo");
			byte params[12] = { NULL };
			*(class UTBot**)&params[0] = B;
			*(class NavigationPoint**)&params[4] = N;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		class Actor* SetFacingActor(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.SetFacingActor");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[4];
		}
		class Actor* FormationCenter(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.FormationCenter");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[4];
		}
		bool AcceptableDefensivePosition(class NavigationPoint* N, class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.AcceptableDefensivePosition");
			byte params[12] = { NULL };
			*(class NavigationPoint**)&params[0] = N;
			*(class UTBot**)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		class NavigationPoint* FindDefensivePositionFor(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.FindDefensivePositionFor");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class NavigationPoint**)&params[4];
		}
		bool ClearPathFor(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.ClearPathFor");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool LostEnemy(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.LostEnemy");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool PickRetreatDestination(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.PickRetreatDestination");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool BeDevious(class Pawn* Enemy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.BeDevious");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = Enemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ShouldSuppressEnemy(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.ShouldSuppressEnemy");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float VehicleDesireability(class UTVehicle* V, class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.VehicleDesireability");
			byte params[12] = { NULL };
			*(class UTVehicle**)&params[0] = V;
			*(class UTBot**)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		bool HandlePathObstruction(class UTBot* B, class Actor* BlockedBy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.HandlePathObstruction");
			byte params[12] = { NULL };
			*(class UTBot**)&params[0] = B;
			*(class Actor**)&params[4] = BlockedBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool FindPathToObjective(class UTBot* B, class Actor* O)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.FindPathToObjective");
			byte params[12] = { NULL };
			*(class UTBot**)&params[0] = B;
			*(class Actor**)&params[4] = O;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		int GetSize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.GetSize");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CriticalObjectiveWarning(class Pawn* NewEnemy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.CriticalObjectiveWarning");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = NewEnemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class UTVehicle* GetLinkVehicle(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.GetLinkVehicle");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTVehicle**)&params[4];
		}
		Object::Rotator GetFacingRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.GetFacingRotation");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[0];
		}
		bool AddEnemy(class Pawn* NewEnemy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.AddEnemy");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = NewEnemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ValidEnemy(class Pawn* NewEnemy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.ValidEnemy");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = NewEnemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsOnSquad(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.IsOnSquad");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void RemoveEnemy(class Pawn* E)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.RemoveEnemy");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = E;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyKilled(class Controller* Killer, class Controller* Killed, class Pawn* KilledPawn, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.NotifyKilled");
			byte params[16] = { NULL };
			*(class Controller**)&params[0] = Killer;
			*(class Controller**)&params[4] = Killed;
			*(class Pawn**)&params[8] = KilledPawn;
			*(ScriptClass**)&params[12] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float ModifyThreat(float Current, class Pawn* NewThreat, bool bThreatVisible, class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.ModifyThreat");
			byte params[20] = { NULL };
			*(float*)&params[0] = Current;
			*(class Pawn**)&params[4] = NewThreat;
			*(bool*)&params[8] = bThreatVisible;
			*(class UTBot**)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[16];
		}
		bool UnderFire(class Pawn* NewThreat, class UTBot* Ignored)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.UnderFire");
			byte params[12] = { NULL };
			*(class Pawn**)&params[0] = NewThreat;
			*(class UTBot**)&params[4] = Ignored;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		float AssessThreat(class UTBot* B, class Pawn* NewThreat, bool bThreatVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.AssessThreat");
			byte params[16] = { NULL };
			*(class UTBot**)&params[0] = B;
			*(class Pawn**)&params[4] = NewThreat;
			*(bool*)&params[8] = bThreatVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		bool ShouldDeferTo(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.ShouldDeferTo");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool WaitAtThisPosition(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.WaitAtThisPosition");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool WanderNearLeader(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.WanderNearLeader");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool NearFormationCenter(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.NearFormationCenter");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CloseToLeader(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.CloseToLeader");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void MergeWith(class UTSquadAI* S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.MergeWith");
			byte params[4] = { NULL };
			*(class UTSquadAI**)&params[0] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Initialize(class UTTeamInfo* T, class UTGameObjective* O, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.Initialize");
			byte params[12] = { NULL };
			*(class UTTeamInfo**)&params[0] = T;
			*(class UTGameObjective**)&params[4] = O;
			*(class Controller**)&params[8] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldUseAlternatePaths()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.ShouldUseAlternatePaths");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SetAlternatePathTo(class NavigationPoint* NewRouteObjective, class UTBot* RouteMaker)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.SetAlternatePathTo");
			byte params[8] = { NULL };
			*(class NavigationPoint**)&params[0] = NewRouteObjective;
			*(class UTBot**)&params[4] = RouteMaker;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool TryToIntercept(class UTBot* B, class Pawn* P, class Actor* RouteGoal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.TryToIntercept");
			byte params[16] = { NULL };
			*(class UTBot**)&params[0] = B;
			*(class Pawn**)&params[4] = P;
			*(class Actor**)&params[8] = RouteGoal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool CloseEnoughToObjective(class UTBot* B, class Actor* O)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.CloseEnoughToObjective");
			byte params[12] = { NULL };
			*(class UTBot**)&params[0] = B;
			*(class Actor**)&params[4] = O;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool LeaveVehicleToReachObjective(class UTBot* B, class Actor* O)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.LeaveVehicleToReachObjective");
			byte params[12] = { NULL };
			*(class UTBot**)&params[0] = B;
			*(class Actor**)&params[4] = O;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool MustCompleteOnFoot(class Actor* O, class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.MustCompleteOnFoot");
			byte params[12] = { NULL };
			*(class Actor**)&params[0] = O;
			*(class Pawn**)&params[4] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void LeaveVehicleAtParkingSpot(class UTBot* B, class Actor* O)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.LeaveVehicleAtParkingSpot");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			*(class Actor**)&params[4] = O;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLeader(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.SetLeader");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemovePlayer(class PlayerController* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.RemovePlayer");
			byte params[4] = { NULL };
			*(class PlayerController**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveBot(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.RemoveBot");
			byte params[4] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddBot(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.AddBot");
			byte params[4] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDefenseScriptFor(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.SetDefenseScriptFor");
			byte params[4] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetObjective(class UTGameObjective* O, bool bForceUpdate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.SetObjective");
			byte params[8] = { NULL };
			*(class UTGameObjective**)&params[0] = O;
			*(bool*)&params[4] = bForceUpdate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Retask(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.Retask");
			byte params[4] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetOrderStringFor(class UTPlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.GetOrderStringFor");
			byte params[16] = { NULL };
			*(class UTPlayerReplicationInfo**)&params[0] = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* GetShortOrderStringFor(class UTPlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.GetShortOrderStringFor");
			byte params[16] = { NULL };
			*(class UTPlayerReplicationInfo**)&params[0] = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void PickNewLeader()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.PickNewLeader");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool TellBotToFollow(class UTBot* B, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.TellBotToFollow");
			byte params[12] = { NULL };
			*(class UTBot**)&params[0] = B;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool AllowTaunt(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.AllowTaunt");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void AddTransientCosts(class UTBot* B, float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.AddTransientCosts");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			*(float*)&params[4] = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float MaxVehicleDist(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.MaxVehicleDist");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		bool NeverBail(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.NeverBail");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void BotEnteredVehicle(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.BotEnteredVehicle");
			byte params[4] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsOnPathToSquadObjective(class Actor* Goal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.IsOnPathToSquadObjective");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Goal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool GetOnHoverboard(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.GetOnHoverboard");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool EnterAndExitVehicle(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.EnterAndExitVehicle");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool GotoVehicle(class UTVehicle* SquadVehicle, class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.GotoVehicle");
			byte params[12] = { NULL };
			*(class UTVehicle**)&params[0] = SquadVehicle;
			*(class UTBot**)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool CheckVehicle(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.CheckVehicle");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CheckHoverboard(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.CheckHoverboard");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ShouldUseHoverboard(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.ShouldUseHoverboard");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool OverrideFollowPlayer(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.OverrideFollowPlayer");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ShouldCheckSuperVehicle(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.ShouldCheckSuperVehicle");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CheckSuperItem(class UTBot* B, float SuperDist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.CheckSuperItem");
			byte params[12] = { NULL };
			*(class UTBot**)&params[0] = B;
			*(float*)&params[4] = SuperDist;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool CheckSquadObjectives(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.CheckSquadObjectives");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float BotSuitability(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.BotSuitability");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		class UTBot* PickBotToReassign()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.PickBotToReassign");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTBot**)&params[0];
		}
		void DisplayDebug(class HUD* HUD, float& YL, float& YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.DisplayDebug");
			byte params[12] = { NULL };
			*(class HUD**)&params[0] = HUD;
			*(float*)&params[4] = YL;
			*(float*)&params[8] = YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			YL = *(float*)&params[4];
			YPos = *(float*)&params[8];
		}
		bool FriendlyToward(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.FriendlyToward");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		float GetMaxDefenseDistanceFrom(class Actor* Center, class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.GetMaxDefenseDistanceFrom");
			byte params[12] = { NULL };
			*(class Actor**)&params[0] = Center;
			*(class UTBot**)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		float RateDefensivePosition(class NavigationPoint* N, class UTBot* CurrentBot, class Actor* Center)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.RateDefensivePosition");
			byte params[16] = { NULL };
			*(class NavigationPoint**)&params[0] = N;
			*(class UTBot**)&params[4] = CurrentBot;
			*(class Actor**)&params[8] = Center;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		void MarkHuntingSpots(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.MarkHuntingSpots");
			byte params[4] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ModifyAggression(class UTBot* B, float& Aggression)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.ModifyAggression");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
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
