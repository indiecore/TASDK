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
		// Here lies the not-yet-implemented method 'FindHumanSquad'
		// Here lies the not-yet-implemented method 'GetPriorityAttackObjectiveFor'
		// Here lies the not-yet-implemented method 'FriendlyToward'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'Timer'
		// Here lies the not-yet-implemented method 'CriticalObjectiveWarning'
		// Here lies the not-yet-implemented method 'FindSuperItems'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'ReAssessStrategy'
		// Here lies the not-yet-implemented method 'NotifyKilled'
		// Here lies the not-yet-implemented method 'FindNewObjectives'
		// Here lies the not-yet-implemented method 'FindNewObjectiveFor'
		// Here lies the not-yet-implemented method 'RemoveSquad'
		// Here lies the not-yet-implemented method 'SetObjectiveLists'
		// Here lies the not-yet-implemented method 'AddHumanSquad'
		// Here lies the not-yet-implemented method 'PutBotOnSquadLedBy'
		// Here lies the not-yet-implemented method 'AddSquadWithLeader'
		// Here lies the not-yet-implemented method 'GetLeastDefendedObjective'
		// Here lies the not-yet-implemented method 'GetPriorityStandaloneObjectiveFor'
		// Here lies the not-yet-implemented method 'GetPriorityFreelanceObjectiveFor'
		// Here lies the not-yet-implemented method 'PutOnDefense'
		// Here lies the not-yet-implemented method 'PutOnOffense'
		// Here lies the not-yet-implemented method 'PutOnFreelance'
		// Here lies the not-yet-implemented method 'SetBotOrders'
		// Here lies the not-yet-implemented method 'SetOrders'
		// Here lies the not-yet-implemented method 'RemoveFromTeam'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
