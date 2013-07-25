#pragma once
#include "UTGame__UTTeamInfo.h"
#include "UDKBase__UDKSquadAI.h"
#include "Engine__NavigationPoint.h"
#include "Engine__Pawn.h"
#include "Engine__Controller.h"
#include "UTGame__UTBot.h"
#include "Engine__Actor.h"
#include "UTGame__UTPlayerReplicationInfo.h"
#include "UTGame__UTVehicle.h"
#include "UTGame__UTGameObjective.h"
#include "Engine__PlayerController.h"
#include "Engine__HUD.h"
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
		// Here lies the not-yet-implemented method 'AllowContinueOnFoot'
		// Here lies the not-yet-implemented method 'AllowImpactJumpBy'
		// Here lies the not-yet-implemented method 'GetOrders'
		// Here lies the not-yet-implemented method 'SetEnemy'
		// Here lies the not-yet-implemented method 'AssignSquadResponsibility'
		// Here lies the not-yet-implemented method 'FindNewEnemyFor'
		// Here lies the not-yet-implemented method 'MustKeepEnemy'
		// Here lies the not-yet-implemented method 'IsDefending'
		// Here lies the not-yet-implemented method 'HasOtherVisibleEnemy'
		// Here lies the not-yet-implemented method 'PriorityObjective'
		// Here lies the not-yet-implemented method 'AllowDetourTo'
		// Here lies the not-yet-implemented method 'SetFacingActor'
		// Here lies the not-yet-implemented method 'FormationCenter'
		// Here lies the not-yet-implemented method 'AcceptableDefensivePosition'
		// Here lies the not-yet-implemented method 'FindDefensivePositionFor'
		// Here lies the not-yet-implemented method 'ClearPathFor'
		// Here lies the not-yet-implemented method 'LostEnemy'
		// Here lies the not-yet-implemented method 'PickRetreatDestination'
		// Here lies the not-yet-implemented method 'BeDevious'
		// Here lies the not-yet-implemented method 'ShouldSuppressEnemy'
		// Here lies the not-yet-implemented method 'VehicleDesireability'
		// Here lies the not-yet-implemented method 'HandlePathObstruction'
		// Here lies the not-yet-implemented method 'FindPathToObjective'
		// Here lies the not-yet-implemented method 'GetSize'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'CriticalObjectiveWarning'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'GetLinkVehicle'
		// Here lies the not-yet-implemented method 'GetFacingRotation'
		// Here lies the not-yet-implemented method 'AddEnemy'
		// Here lies the not-yet-implemented method 'ValidEnemy'
		// Here lies the not-yet-implemented method 'IsOnSquad'
		// Here lies the not-yet-implemented method 'RemoveEnemy'
		// Here lies the not-yet-implemented method 'NotifyKilled'
		// Here lies the not-yet-implemented method 'ModifyThreat'
		// Here lies the not-yet-implemented method 'UnderFire'
		// Here lies the not-yet-implemented method 'AssessThreat'
		// Here lies the not-yet-implemented method 'ShouldDeferTo'
		// Here lies the not-yet-implemented method 'WaitAtThisPosition'
		// Here lies the not-yet-implemented method 'WanderNearLeader'
		// Here lies the not-yet-implemented method 'NearFormationCenter'
		// Here lies the not-yet-implemented method 'CloseToLeader'
		// Here lies the not-yet-implemented method 'MergeWith'
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'ShouldUseAlternatePaths'
		// Here lies the not-yet-implemented method 'SetAlternatePathTo'
		// Here lies the not-yet-implemented method 'TryToIntercept'
		// Here lies the not-yet-implemented method 'CloseEnoughToObjective'
		// Here lies the not-yet-implemented method 'LeaveVehicleToReachObjective'
		// Here lies the not-yet-implemented method 'MustCompleteOnFoot'
		// Here lies the not-yet-implemented method 'LeaveVehicleAtParkingSpot'
		// Here lies the not-yet-implemented method 'SetLeader'
		// Here lies the not-yet-implemented method 'RemovePlayer'
		// Here lies the not-yet-implemented method 'RemoveBot'
		// Here lies the not-yet-implemented method 'AddBot'
		// Here lies the not-yet-implemented method 'SetDefenseScriptFor'
		// Here lies the not-yet-implemented method 'SetObjective'
		// Here lies the not-yet-implemented method 'Retask'
		// Here lies the not-yet-implemented method 'GetOrderStringFor'
		// Here lies the not-yet-implemented method 'GetShortOrderStringFor'
		// Here lies the not-yet-implemented method 'PickNewLeader'
		// Here lies the not-yet-implemented method 'TellBotToFollow'
		// Here lies the not-yet-implemented method 'AllowTaunt'
		// Here lies the not-yet-implemented method 'AddTransientCosts'
		// Here lies the not-yet-implemented method 'MaxVehicleDist'
		// Here lies the not-yet-implemented method 'NeverBail'
		// Here lies the not-yet-implemented method 'BotEnteredVehicle'
		// Here lies the not-yet-implemented method 'IsOnPathToSquadObjective'
		// Here lies the not-yet-implemented method 'GetOnHoverboard'
		// Here lies the not-yet-implemented method 'EnterAndExitVehicle'
		// Here lies the not-yet-implemented method 'GotoVehicle'
		// Here lies the not-yet-implemented method 'CheckVehicle'
		// Here lies the not-yet-implemented method 'CheckHoverboard'
		// Here lies the not-yet-implemented method 'ShouldUseHoverboard'
		// Here lies the not-yet-implemented method 'OverrideFollowPlayer'
		// Here lies the not-yet-implemented method 'ShouldCheckSuperVehicle'
		// Here lies the not-yet-implemented method 'CheckSuperItem'
		// Here lies the not-yet-implemented method 'CheckSquadObjectives'
		// Here lies the not-yet-implemented method 'BotSuitability'
		// Here lies the not-yet-implemented method 'PickBotToReassign'
		// Here lies the not-yet-implemented method 'DisplayDebug'
		// Here lies the not-yet-implemented method 'FriendlyToward'
		// Here lies the not-yet-implemented method 'GetMaxDefenseDistanceFrom'
		// Here lies the not-yet-implemented method 'RateDefensivePosition'
		// Here lies the not-yet-implemented method 'MarkHuntingSpots'
		// Here lies the not-yet-implemented method 'ModifyAggression'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
