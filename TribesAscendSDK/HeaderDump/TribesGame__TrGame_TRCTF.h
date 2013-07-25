#pragma once
#include "TribesGame__TrFlagBase.h"
#include "UTGame__UTCarriedObject.h"
#include "TribesGame__TrGame.h"
#include "TribesGame__TrFlagCTF.h"
#include "Engine__Controller.h"
#include "Engine__Pawn.h"
#include "Engine__AIController.h"
#include "Engine__Actor.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__PlayerController.h"
#include "UTGame__UTPlayerController.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrGame_TRCTF." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrGame_TRCTF : public TrGame
	{
	public:
		ADD_OBJECT(TrFlagCTF, m_Flags)
		ADD_OBJECT(ScriptClass, AnnouncerMessageClass)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'ApplyServerSettings'
		// Here lies the not-yet-implemented method 'GetHandicapNeed'
		// Here lies the not-yet-implemented method 'GetLocationFor'
		// Here lies the not-yet-implemented method 'RegisterFlag'
		// Here lies the not-yet-implemented method 'NearGoal'
		// Here lies the not-yet-implemented method 'WantFastSpawnFor'
		// Here lies the not-yet-implemented method 'CheckEndGame'
		// Here lies the not-yet-implemented method 'ScoreFlag'
		// Here lies the not-yet-implemented method 'ViewObjective'
		// Here lies the not-yet-implemented method 'GetAutoObjectiveFor'
		// Here lies the not-yet-implemented method 'AnnounceScore'
		// Here lies the not-yet-implemented method 'CheckScore'
		// Here lies the not-yet-implemented method 'GetGameTypeId'
	};
}
#undef ADD_OBJECT
