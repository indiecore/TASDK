#pragma once
#include "UTGame__UTTeamInfo.h"
#include "UDKBase__UDKTeamOwnedInfo.h"
#include "UTGame__UTBot.h"
#include "UTGame__UTPickupFactory.h"
#include "UTGame__UTGameObjective.h"
#include "UTGame__UTSquadAI.h"
#include "Engine__Pawn.h"
#include "Engine__Controller.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTTeamAI." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTTeamAI." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTTeamAI : public UDKTeamOwnedInfo
	{
	public:
		ADD_OBJECT(UTTeamInfo, EnemyTeam)
		ADD_OBJECT(UTGameObjective, Objectives)
		ADD_OBJECT(UTSquadAI, Squads)
		ADD_VAR(::BoolProperty, bFoundSuperItems, 0x1)
		ADD_VAR(::IntProperty, NumSuperPickups, 0xFFFFFFFF)
		ADD_OBJECT(UTPickupFactory, SuperPickups)
		ADD_VAR(::NameProperty, OrderList, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, OrderOffset, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, SquadType)
		ADD_OBJECT(UTSquadAI, FreelanceSquad)
		ADD_OBJECT(UTSquadAI, AttackSquad)
		ADD_OBJECT(UTGameObjective, PickedStandaloneObjective)
		ADD_OBJECT(UTGameObjective, PickedObjective)
		ADD_VAR(::IntProperty, NumSupportingPlayer, 0xFFFFFFFF)
		class UTSquadAI* FindHumanSquad()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.FindHumanSquad");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTSquadAI**)params;
			free(params);
			return returnVal;
		}
		class UTGameObjective* GetPriorityAttackObjectiveFor(class UTSquadAI* InAttackSquad, class Controller* InController)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.GetPriorityAttackObjectiveFor");
			byte* params = (byte*)malloc(12);
			*(class UTSquadAI**)params = InAttackSquad;
			*(class Controller**)(params + 4) = InController;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTGameObjective**)(params + 8);
			free(params);
			return returnVal;
		}
		bool FriendlyToward(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.FriendlyToward");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(8);
			*(class UTGameObjective**)params = G;
			*(class Pawn**)(params + 4) = NewEnemy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(16);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = Killed;
			*(class Pawn**)(params + 8) = KilledPawn;
			*(ScriptClass**)(params + 12) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FindNewObjectives(class UTGameObjective* DisabledObjective)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.FindNewObjectives");
			byte* params = (byte*)malloc(4);
			*(class UTGameObjective**)params = DisabledObjective;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FindNewObjectiveFor(class UTSquadAI* S, bool bForceUpdate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.FindNewObjectiveFor");
			byte* params = (byte*)malloc(8);
			*(class UTSquadAI**)params = S;
			*(bool*)(params + 4) = bForceUpdate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveSquad(class UTSquadAI* Squad)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.RemoveSquad");
			byte* params = (byte*)malloc(4);
			*(class UTSquadAI**)params = Squad;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetObjectiveLists()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.SetObjectiveLists");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class UTSquadAI* AddHumanSquad()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.AddHumanSquad");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTSquadAI**)params;
			free(params);
			return returnVal;
		}
		void PutBotOnSquadLedBy(class Controller* C, class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.PutBotOnSquadLedBy");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = C;
			*(class UTBot**)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class UTSquadAI* AddSquadWithLeader(class Controller* C, class UTGameObjective* O)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.AddSquadWithLeader");
			byte* params = (byte*)malloc(12);
			*(class Controller**)params = C;
			*(class UTGameObjective**)(params + 4) = O;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTSquadAI**)(params + 8);
			free(params);
			return returnVal;
		}
		class UTGameObjective* GetLeastDefendedObjective(class Controller* InController)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.GetLeastDefendedObjective");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = InController;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTGameObjective**)(params + 4);
			free(params);
			return returnVal;
		}
		class UTGameObjective* GetPriorityStandaloneObjectiveFor(class UTSquadAI* InAttackSquad, class Controller* InController)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.GetPriorityStandaloneObjectiveFor");
			byte* params = (byte*)malloc(12);
			*(class UTSquadAI**)params = InAttackSquad;
			*(class Controller**)(params + 4) = InController;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTGameObjective**)(params + 8);
			free(params);
			return returnVal;
		}
		class UTGameObjective* GetPriorityFreelanceObjectiveFor(class UTSquadAI* InFreelanceSquad)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.GetPriorityFreelanceObjectiveFor");
			byte* params = (byte*)malloc(8);
			*(class UTSquadAI**)params = InFreelanceSquad;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTGameObjective**)(params + 4);
			free(params);
			return returnVal;
		}
		bool PutOnDefense(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.PutOnDefense");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void PutOnOffense(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.PutOnOffense");
			byte* params = (byte*)malloc(4);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PutOnFreelance(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.PutOnFreelance");
			byte* params = (byte*)malloc(4);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBotOrders(class UTBot* NewBot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.SetBotOrders");
			byte* params = (byte*)malloc(4);
			*(class UTBot**)params = NewBot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetOrders(class UTBot* B, ScriptName NewOrders, class Controller* OrderGiver)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.SetOrders");
			byte* params = (byte*)malloc(16);
			*(class UTBot**)params = B;
			*(ScriptName*)(params + 4) = NewOrders;
			*(class Controller**)(params + 12) = OrderGiver;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveFromTeam(class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamAI.RemoveFromTeam");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
