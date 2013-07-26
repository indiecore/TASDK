#pragma once
#include "Engine.NavigationPoint.h"
#include "UDKBase.UDKSquadAI.h"
#include "Engine.Actor.h"
#include "UTGame.UTBot.h"
#include "Engine.Controller.h"
#include "Engine.Pawn.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#include "UTGame.UTVehicle.h"
#include "Core.Object.Rotator.h"
#include "UTGame.UTTeamInfo.h"
#include "UTGame.UTGameObjective.h"
#include "Engine.PlayerController.h"
#include "Engine.HUD.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTSquadAI." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTSquadAI." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTSquadAI : public UDKSquadAI
	{
	public:
		ADD_OBJECT(Controller, SquadLeader)
		ADD_OBJECT(UTBot, SquadMembers)
		ADD_VAR(::FloatProperty, FormationSize, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShouldUseGatherPoints, 0x20)
		ADD_VAR(::BoolProperty, bAddTransientCosts, 0x10)
		ADD_VAR(::BoolProperty, bRoamingSquad, 0x8)
		ADD_VAR(::BoolProperty, bFreelanceDefend, 0x4)
		ADD_VAR(::BoolProperty, bFreelanceAttack, 0x2)
		ADD_VAR(::BoolProperty, bFreelance, 0x1)
		ADD_VAR(::IntProperty, MaxSquadSize, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, Enemies)
		ADD_VAR(::NameProperty, CurrentOrders, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SupportStringTrailer, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FreelanceString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HoldString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, AttackString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DefendString, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SupportString, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Size, 0xFFFFFFFF)
		ADD_OBJECT(UTSquadAI, NextSquad)
		ADD_OBJECT(UTPlayerReplicationInfo, LeaderPRI)
		bool AllowContinueOnFoot(class UTBot* B, class UTVehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.AllowContinueOnFoot");
			byte* params = (byte*)malloc(12);
			*(class UTBot**)params = B;
			*(class UTVehicle**)(params + 4) = V;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool AllowImpactJumpBy(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.AllowImpactJumpBy");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptName GetOrders()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.GetOrders");
			byte* params = (byte*)malloc(8);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)params;
			free(params);
			return returnVal;
		}
		bool SetEnemy(class UTBot* B, class Pawn* NewEnemy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.SetEnemy");
			byte* params = (byte*)malloc(12);
			*(class UTBot**)params = B;
			*(class Pawn**)(params + 4) = NewEnemy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool AssignSquadResponsibility(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.AssignSquadResponsibility");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool FindNewEnemyFor(class UTBot* B, bool bSeeEnemy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.FindNewEnemyFor");
			byte* params = (byte*)malloc(12);
			*(class UTBot**)params = B;
			*(bool*)(params + 4) = bSeeEnemy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool MustKeepEnemy(class Pawn* E)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.MustKeepEnemy");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = E;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsDefending(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.IsDefending");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool HasOtherVisibleEnemy(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.HasOtherVisibleEnemy");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		byte PriorityObjective(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.PriorityObjective");
			byte* params = (byte*)malloc(5);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 4);
			free(params);
			return returnVal;
		}
		bool AllowDetourTo(class UTBot* B, class NavigationPoint* N)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.AllowDetourTo");
			byte* params = (byte*)malloc(12);
			*(class UTBot**)params = B;
			*(class NavigationPoint**)(params + 4) = N;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		class Actor* SetFacingActor(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.SetFacingActor");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)(params + 4);
			free(params);
			return returnVal;
		}
		class Actor* FormationCenter(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.FormationCenter");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)(params + 4);
			free(params);
			return returnVal;
		}
		bool AcceptableDefensivePosition(class NavigationPoint* N, class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.AcceptableDefensivePosition");
			byte* params = (byte*)malloc(12);
			*(class NavigationPoint**)params = N;
			*(class UTBot**)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		class NavigationPoint* FindDefensivePositionFor(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.FindDefensivePositionFor");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class NavigationPoint**)(params + 4);
			free(params);
			return returnVal;
		}
		bool ClearPathFor(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.ClearPathFor");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool LostEnemy(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.LostEnemy");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool PickRetreatDestination(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.PickRetreatDestination");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool BeDevious(class Pawn* Enemy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.BeDevious");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Enemy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool ShouldSuppressEnemy(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.ShouldSuppressEnemy");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		float VehicleDesireability(class UTVehicle* V, class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.VehicleDesireability");
			byte* params = (byte*)malloc(12);
			*(class UTVehicle**)params = V;
			*(class UTBot**)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		bool HandlePathObstruction(class UTBot* B, class Actor* BlockedBy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.HandlePathObstruction");
			byte* params = (byte*)malloc(12);
			*(class UTBot**)params = B;
			*(class Actor**)(params + 4) = BlockedBy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool FindPathToObjective(class UTBot* B, class Actor* O)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.FindPathToObjective");
			byte* params = (byte*)malloc(12);
			*(class UTBot**)params = B;
			*(class Actor**)(params + 4) = O;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		int GetSize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.GetSize");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CriticalObjectiveWarning(class Pawn* NewEnemy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.CriticalObjectiveWarning");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = NewEnemy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class UTVehicle* GetLinkVehicle(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.GetLinkVehicle");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTVehicle**)(params + 4);
			free(params);
			return returnVal;
		}
		Rotator GetFacingRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.GetFacingRotation");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)params;
			free(params);
			return returnVal;
		}
		bool AddEnemy(class Pawn* NewEnemy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.AddEnemy");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = NewEnemy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool ValidEnemy(class Pawn* NewEnemy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.ValidEnemy");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = NewEnemy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsOnSquad(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.IsOnSquad");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void RemoveEnemy(class Pawn* E)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.RemoveEnemy");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = E;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyKilled(class Controller* Killer, class Controller* Killed, class Pawn* KilledPawn, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.NotifyKilled");
			byte* params = (byte*)malloc(16);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = Killed;
			*(class Pawn**)(params + 8) = KilledPawn;
			*(ScriptClass**)(params + 12) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float ModifyThreat(float Current, class Pawn* NewThreat, bool bThreatVisible, class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.ModifyThreat");
			byte* params = (byte*)malloc(20);
			*(float*)params = Current;
			*(class Pawn**)(params + 4) = NewThreat;
			*(bool*)(params + 8) = bThreatVisible;
			*(class UTBot**)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 16);
			free(params);
			return returnVal;
		}
		bool UnderFire(class Pawn* NewThreat, class UTBot* Ignored)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.UnderFire");
			byte* params = (byte*)malloc(12);
			*(class Pawn**)params = NewThreat;
			*(class UTBot**)(params + 4) = Ignored;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		float AssessThreat(class UTBot* B, class Pawn* NewThreat, bool bThreatVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.AssessThreat");
			byte* params = (byte*)malloc(16);
			*(class UTBot**)params = B;
			*(class Pawn**)(params + 4) = NewThreat;
			*(bool*)(params + 8) = bThreatVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		bool ShouldDeferTo(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.ShouldDeferTo");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool WaitAtThisPosition(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.WaitAtThisPosition");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool WanderNearLeader(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.WanderNearLeader");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool NearFormationCenter(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.NearFormationCenter");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CloseToLeader(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.CloseToLeader");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void MergeWith(class UTSquadAI* S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.MergeWith");
			byte* params = (byte*)malloc(4);
			*(class UTSquadAI**)params = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Initialize(class UTTeamInfo* T, class UTGameObjective* O, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.Initialize");
			byte* params = (byte*)malloc(12);
			*(class UTTeamInfo**)params = T;
			*(class UTGameObjective**)(params + 4) = O;
			*(class Controller**)(params + 8) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShouldUseAlternatePaths()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.ShouldUseAlternatePaths");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetAlternatePathTo(class NavigationPoint* NewRouteObjective, class UTBot* RouteMaker)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.SetAlternatePathTo");
			byte* params = (byte*)malloc(8);
			*(class NavigationPoint**)params = NewRouteObjective;
			*(class UTBot**)(params + 4) = RouteMaker;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool TryToIntercept(class UTBot* B, class Pawn* P, class Actor* RouteGoal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.TryToIntercept");
			byte* params = (byte*)malloc(16);
			*(class UTBot**)params = B;
			*(class Pawn**)(params + 4) = P;
			*(class Actor**)(params + 8) = RouteGoal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool CloseEnoughToObjective(class UTBot* B, class Actor* O)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.CloseEnoughToObjective");
			byte* params = (byte*)malloc(12);
			*(class UTBot**)params = B;
			*(class Actor**)(params + 4) = O;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool LeaveVehicleToReachObjective(class UTBot* B, class Actor* O)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.LeaveVehicleToReachObjective");
			byte* params = (byte*)malloc(12);
			*(class UTBot**)params = B;
			*(class Actor**)(params + 4) = O;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool MustCompleteOnFoot(class Actor* O, class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.MustCompleteOnFoot");
			byte* params = (byte*)malloc(12);
			*(class Actor**)params = O;
			*(class Pawn**)(params + 4) = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void LeaveVehicleAtParkingSpot(class UTBot* B, class Actor* O)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.LeaveVehicleAtParkingSpot");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			*(class Actor**)(params + 4) = O;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetLeader(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.SetLeader");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemovePlayer(class PlayerController* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.RemovePlayer");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveBot(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.RemoveBot");
			byte* params = (byte*)malloc(4);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddBot(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.AddBot");
			byte* params = (byte*)malloc(4);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetDefenseScriptFor(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.SetDefenseScriptFor");
			byte* params = (byte*)malloc(4);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetObjective(class UTGameObjective* O, bool bForceUpdate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.SetObjective");
			byte* params = (byte*)malloc(8);
			*(class UTGameObjective**)params = O;
			*(bool*)(params + 4) = bForceUpdate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Retask(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.Retask");
			byte* params = (byte*)malloc(4);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetOrderStringFor(class UTPlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.GetOrderStringFor");
			byte* params = (byte*)malloc(16);
			*(class UTPlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetShortOrderStringFor(class UTPlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.GetShortOrderStringFor");
			byte* params = (byte*)malloc(16);
			*(class UTPlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		void PickNewLeader()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.PickNewLeader");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool TellBotToFollow(class UTBot* B, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.TellBotToFollow");
			byte* params = (byte*)malloc(12);
			*(class UTBot**)params = B;
			*(class Controller**)(params + 4) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool AllowTaunt(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.AllowTaunt");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void AddTransientCosts(class UTBot* B, float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.AddTransientCosts");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			*(float*)(params + 4) = F;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float MaxVehicleDist(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.MaxVehicleDist");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		bool NeverBail(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.NeverBail");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void BotEnteredVehicle(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.BotEnteredVehicle");
			byte* params = (byte*)malloc(4);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsOnPathToSquadObjective(class Actor* Goal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.IsOnPathToSquadObjective");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Goal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool GetOnHoverboard(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.GetOnHoverboard");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool EnterAndExitVehicle(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.EnterAndExitVehicle");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool GotoVehicle(class UTVehicle* SquadVehicle, class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.GotoVehicle");
			byte* params = (byte*)malloc(12);
			*(class UTVehicle**)params = SquadVehicle;
			*(class UTBot**)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool CheckVehicle(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.CheckVehicle");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CheckHoverboard(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.CheckHoverboard");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool ShouldUseHoverboard(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.ShouldUseHoverboard");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool OverrideFollowPlayer(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.OverrideFollowPlayer");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool ShouldCheckSuperVehicle(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.ShouldCheckSuperVehicle");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CheckSuperItem(class UTBot* B, float SuperDist)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.CheckSuperItem");
			byte* params = (byte*)malloc(12);
			*(class UTBot**)params = B;
			*(float*)(params + 4) = SuperDist;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool CheckSquadObjectives(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.CheckSquadObjectives");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		float BotSuitability(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.BotSuitability");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		class UTBot* PickBotToReassign()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.PickBotToReassign");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTBot**)params;
			free(params);
			return returnVal;
		}
		void DisplayDebug(class HUD* HUD, float& YL, float& YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.DisplayDebug");
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = YL;
			*(float*)(params + 8) = YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			YL = *(float*)(params + 4);
			YPos = *(float*)(params + 8);
			free(params);
		}
		bool FriendlyToward(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.FriendlyToward");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		float GetMaxDefenseDistanceFrom(class Actor* Center, class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.GetMaxDefenseDistanceFrom");
			byte* params = (byte*)malloc(12);
			*(class Actor**)params = Center;
			*(class UTBot**)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		float RateDefensivePosition(class NavigationPoint* N, class UTBot* CurrentBot, class Actor* Center)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.RateDefensivePosition");
			byte* params = (byte*)malloc(16);
			*(class NavigationPoint**)params = N;
			*(class UTBot**)(params + 4) = CurrentBot;
			*(class Actor**)(params + 8) = Center;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		void MarkHuntingSpots(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.MarkHuntingSpots");
			byte* params = (byte*)malloc(4);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ModifyAggression(class UTBot* B, float& Aggression)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSquadAI.ModifyAggression");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			*(float*)(params + 4) = Aggression;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Aggression = *(float*)(params + 4);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
