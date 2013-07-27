#pragma once
#include "UDKBase.UDKTeamOwnedInfo.h"
#include "UTGame.UTTeamInfo.h"
#include "UTGame.UTGameObjective.h"
#include "UTGame.UTVehicleFactory.h"
#include "UTGame.UTBot.h"
#include "Engine.Controller.h"
#include "UTGame.UTPickupFactory.h"
#include "UTGame.UTSquadAI.h"
#include "Engine.Pawn.h"
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
	class UTTeamAI : public UDKTeamOwnedInfo
	{
	public:
		ADD_OBJECT(UTTeamInfo, EnemyTeam, 480)
		ADD_OBJECT(UTGameObjective, Objectives, 488)
		ADD_OBJECT(UTSquadAI, Squads, 500)
		ADD_BOOL(bFoundSuperItems, 652, 0x1)
		ADD_STRUCT(ScriptArray<class UTVehicleFactory*>, ImportantVehicleFactories, 656)
		ADD_STRUCT(int, NumSuperPickups, 648)
		ADD_OBJECT(UTPickupFactory, SuperPickups, 584)
		ADD_STRUCT(ScriptName, OrderList, 520)
		ADD_STRUCT(int, OrderOffset, 516)
		ADD_OBJECT(ScriptClass, SquadType, 512)
		ADD_OBJECT(UTSquadAI, FreelanceSquad, 508)
		ADD_OBJECT(UTSquadAI, AttackSquad, 504)
		ADD_OBJECT(UTGameObjective, PickedStandaloneObjective, 496)
		ADD_OBJECT(UTGameObjective, PickedObjective, 492)
		ADD_STRUCT(int, NumSupportingPlayer, 484)
		class UTSquadAI* FindHumanSquad()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.FindHumanSquad");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTSquadAI**)&params[0];
		}
		class UTGameObjective* GetPriorityAttackObjectiveFor(class UTSquadAI* InAttackSquad, class Controller* InController)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.GetPriorityAttackObjectiveFor");
			byte params[12] = { NULL };
			*(class UTSquadAI**)&params[0] = InAttackSquad;
			*(class Controller**)&params[4] = InController;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTGameObjective**)&params[8];
		}
		bool FriendlyToward(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.FriendlyToward");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Timer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.Timer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CriticalObjectiveWarning(class UTGameObjective* G, class Pawn* NewEnemy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.CriticalObjectiveWarning");
			byte params[8] = { NULL };
			*(class UTGameObjective**)&params[0] = G;
			*(class Pawn**)&params[4] = NewEnemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FindSuperItems()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.FindSuperItems");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReAssessStrategy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.ReAssessStrategy");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyKilled(class Controller* Killer, class Controller* Killed, class Pawn* KilledPawn, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.NotifyKilled");
			byte params[16] = { NULL };
			*(class Controller**)&params[0] = Killer;
			*(class Controller**)&params[4] = Killed;
			*(class Pawn**)&params[8] = KilledPawn;
			*(ScriptClass**)&params[12] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FindNewObjectives(class UTGameObjective* DisabledObjective)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.FindNewObjectives");
			byte params[4] = { NULL };
			*(class UTGameObjective**)&params[0] = DisabledObjective;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FindNewObjectiveFor(class UTSquadAI* S, bool bForceUpdate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.FindNewObjectiveFor");
			byte params[8] = { NULL };
			*(class UTSquadAI**)&params[0] = S;
			*(bool*)&params[4] = bForceUpdate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveSquad(class UTSquadAI* Squad)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.RemoveSquad");
			byte params[4] = { NULL };
			*(class UTSquadAI**)&params[0] = Squad;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetObjectiveLists()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.SetObjectiveLists");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class UTSquadAI* AddHumanSquad()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.AddHumanSquad");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTSquadAI**)&params[0];
		}
		void PutBotOnSquadLedBy(class Controller* C, class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.PutBotOnSquadLedBy");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = C;
			*(class UTBot**)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class UTSquadAI* AddSquadWithLeader(class Controller* C, class UTGameObjective* O)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.AddSquadWithLeader");
			byte params[12] = { NULL };
			*(class Controller**)&params[0] = C;
			*(class UTGameObjective**)&params[4] = O;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTSquadAI**)&params[8];
		}
		class UTGameObjective* GetLeastDefendedObjective(class Controller* InController)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.GetLeastDefendedObjective");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = InController;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTGameObjective**)&params[4];
		}
		class UTGameObjective* GetPriorityStandaloneObjectiveFor(class UTSquadAI* InAttackSquad, class Controller* InController)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.GetPriorityStandaloneObjectiveFor");
			byte params[12] = { NULL };
			*(class UTSquadAI**)&params[0] = InAttackSquad;
			*(class Controller**)&params[4] = InController;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTGameObjective**)&params[8];
		}
		class UTGameObjective* GetPriorityFreelanceObjectiveFor(class UTSquadAI* InFreelanceSquad)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.GetPriorityFreelanceObjectiveFor");
			byte params[8] = { NULL };
			*(class UTSquadAI**)&params[0] = InFreelanceSquad;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTGameObjective**)&params[4];
		}
		bool PutOnDefense(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.PutOnDefense");
			byte params[8] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PutOnOffense(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.PutOnOffense");
			byte params[4] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PutOnFreelance(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.PutOnFreelance");
			byte params[4] = { NULL };
			*(class UTBot**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBotOrders(class UTBot* NewBot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.SetBotOrders");
			byte params[4] = { NULL };
			*(class UTBot**)&params[0] = NewBot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetOrders(class UTBot* B, ScriptName NewOrders, class Controller* OrderGiver)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.SetOrders");
			byte params[16] = { NULL };
			*(class UTBot**)&params[0] = B;
			*(ScriptName*)&params[4] = NewOrders;
			*(class Controller**)&params[12] = OrderGiver;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveFromTeam(class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.RemoveFromTeam");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
