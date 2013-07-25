#pragma once
#include "Engine__PlayerController.h"
#include "UTGame__UTTeamGame.h"
#include "UTGame__UTCTFFlag.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__Controller.h"
#include "Engine__Pawn.h"
#include "Engine__AIController.h"
#include "Engine__Actor.h"
#include "UTGame__UTCarriedObject.h"
#include "UTGame__UTPlayerController.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTCTFGame." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTCTFGame : public UTTeamGame
	{
	public:
		ADD_OBJECT(ScriptClass, AnnouncerMessageClass)
		ADD_OBJECT(UTCTFFlag, Flags)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'SetEndGameFocus'
		// Here lies the not-yet-implemented method 'GetHandicapNeed'
		// Here lies the not-yet-implemented method 'GetLocationFor'
		// Here lies the not-yet-implemented method 'RegisterFlag'
		// Here lies the not-yet-implemented method 'NearGoal'
		// Here lies the not-yet-implemented method 'WantFastSpawnFor'
		// Here lies the not-yet-implemented method 'CheckEndGame'
		// Here lies the not-yet-implemented method 'ScoreFlag'
		// Here lies the not-yet-implemented method 'ViewObjective'
		// Here lies the not-yet-implemented method 'GetAutoObjectiveFor'
	};
}
#undef ADD_OBJECT
