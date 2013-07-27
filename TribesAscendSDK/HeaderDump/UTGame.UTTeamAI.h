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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(44566);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTSquadAI**)params;
		}
		class UTGameObjective* GetPriorityAttackObjectiveFor(class UTSquadAI* InAttackSquad, class Controller* InController)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46310);
			byte params[12] = { NULL };
			*(class UTSquadAI**)params = InAttackSquad;
			*(class Controller**)&params[4] = InController;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTGameObjective**)&params[8];
		}
		bool FriendlyToward(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46504);
			byte params[8] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46647);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Timer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46648);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CriticalObjectiveWarning(class UTGameObjective* G, class Pawn* NewEnemy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46649);
			byte params[8] = { NULL };
			*(class UTGameObjective**)params = G;
			*(class Pawn**)&params[4] = NewEnemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FindSuperItems()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46652);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46656);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReAssessStrategy()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46657);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyKilled(class Controller* Killer, class Controller* Killed, class Pawn* KilledPawn, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46661);
			byte params[16] = { NULL };
			*(class Controller**)params = Killer;
			*(class Controller**)&params[4] = Killed;
			*(class Pawn**)&params[8] = KilledPawn;
			*(ScriptClass**)&params[12] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FindNewObjectives(class UTGameObjective* DisabledObjective)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46667);
			byte params[4] = { NULL };
			*(class UTGameObjective**)params = DisabledObjective;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FindNewObjectiveFor(class UTSquadAI* S, bool bForceUpdate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46670);
			byte params[8] = { NULL };
			*(class UTSquadAI**)params = S;
			*(bool*)&params[4] = bForceUpdate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveSquad(class UTSquadAI* Squad)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46674);
			byte params[4] = { NULL };
			*(class UTSquadAI**)params = Squad;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetObjectiveLists()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46678);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class UTSquadAI* AddHumanSquad()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46681);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTSquadAI**)params;
		}
		void PutBotOnSquadLedBy(class Controller* C, class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46685);
			byte params[8] = { NULL };
			*(class Controller**)params = C;
			*(class UTBot**)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class UTSquadAI* AddSquadWithLeader(class Controller* C, class UTGameObjective* O)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46689);
			byte params[12] = { NULL };
			*(class Controller**)params = C;
			*(class UTGameObjective**)&params[4] = O;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTSquadAI**)&params[8];
		}
		class UTGameObjective* GetLeastDefendedObjective(class Controller* InController)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46694);
			byte params[8] = { NULL };
			*(class Controller**)params = InController;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTGameObjective**)&params[4];
		}
		class UTGameObjective* GetPriorityStandaloneObjectiveFor(class UTSquadAI* InAttackSquad, class Controller* InController)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46708);
			byte params[12] = { NULL };
			*(class UTSquadAI**)params = InAttackSquad;
			*(class Controller**)&params[4] = InController;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTGameObjective**)&params[8];
		}
		class UTGameObjective* GetPriorityFreelanceObjectiveFor(class UTSquadAI* InFreelanceSquad)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46716);
			byte params[8] = { NULL };
			*(class UTSquadAI**)params = InFreelanceSquad;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTGameObjective**)&params[4];
		}
		bool PutOnDefense(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46719);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PutOnOffense(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46723);
			byte params[4] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PutOnFreelance(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46725);
			byte params[4] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBotOrders(class UTBot* NewBot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46727);
			byte params[4] = { NULL };
			*(class UTBot**)params = NewBot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetOrders(class UTBot* B, ScriptName NewOrders, class Controller* OrderGiver)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46731);
			byte params[16] = { NULL };
			*(class UTBot**)params = B;
			*(ScriptName*)&params[4] = NewOrders;
			*(class Controller**)&params[12] = OrderGiver;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveFromTeam(class Controller* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46736);
			byte params[4] = { NULL };
			*(class Controller**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
