#pragma once
#include "Engine__Actor.h"
#include "UTGame__UTSquadAI.h"
#include "UTGame__UTCTFFlag.h"
#include "Engine__Controller.h"
#include "Engine__Pawn.h"
#include "Engine__NavigationPoint.h"
#include "UTGame__UTBot.h"
#include "UTGame__UTVehicle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTCTFSquadAI." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTCTFSquadAI." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTCTFSquadAI : public UTSquadAI
	{
	public:
		ADD_OBJECT(UTCTFFlag, EnemyFlag)
		ADD_OBJECT(UTCTFFlag, FriendlyFlag)
		ADD_OBJECT(NavigationPoint, HidePath)
		ADD_VAR(::FloatProperty, LastSeeFlagCarrier, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'AllowDetourTo'
		// Here lies the not-yet-implemented method 'ShouldUseAlternatePaths'
		// Here lies the not-yet-implemented method 'SetAlternatePathTo'
		// Here lies the not-yet-implemented method 'BeDevious'
		// Here lies the not-yet-implemented method 'FindPathToObjective'
		// Here lies the not-yet-implemented method 'GoPickupFlag'
		// Here lies the not-yet-implemented method 'FormationCenter'
		// Here lies the not-yet-implemented method 'VisibleToEnemiesOf'
		// Here lies the not-yet-implemented method 'FindHidePathFor'
		// Here lies the not-yet-implemented method 'CheckVehicle'
		// Here lies the not-yet-implemented method 'OrdersForFlagCarrier'
		// Here lies the not-yet-implemented method 'MustKeepEnemy'
		// Here lies the not-yet-implemented method 'NearEnemyBase'
		// Here lies the not-yet-implemented method 'NearHomeBase'
		// Here lies the not-yet-implemented method 'FlagNearBase'
		// Here lies the not-yet-implemented method 'OverrideFollowPlayer'
		// Here lies the not-yet-implemented method 'CheckSquadObjectives'
		// Here lies the not-yet-implemented method 'EnemyFlagTakenBy'
		// Here lies the not-yet-implemented method 'AllowTaunt'
		// Here lies the not-yet-implemented method 'ShouldDeferTo'
		// Here lies the not-yet-implemented method 'PriorityObjective'
		// Here lies the not-yet-implemented method 'ModifyThreat'
		// Here lies the not-yet-implemented method 'AllowContinueOnFoot'
		// Here lies the not-yet-implemented method 'ModifyAggression'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
