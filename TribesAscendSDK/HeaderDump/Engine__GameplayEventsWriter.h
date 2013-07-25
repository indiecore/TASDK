#pragma once
#include "Engine__GameplayEvents.h"
#include "Engine__GameInfo.h"
#include "Engine__Controller.h"
#include "Engine__TeamInfo.h"
#include "Engine__CoverLink.h"
#include "Engine__GenericParamListStatEntry.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.GameplayEventsWriter." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameplayEventsWriter : public GameplayEvents
	{
	public:
		ADD_OBJECT(GameInfo, Game)
		// Here lies the not-yet-implemented method 'ResolvePlayerIndex'
		// Here lies the not-yet-implemented method 'StartLogging'
		// Here lies the not-yet-implemented method 'ResetLogging'
		// Here lies the not-yet-implemented method 'EndLogging'
		// Here lies the not-yet-implemented method 'IsSessionInProgress'
		// Here lies the not-yet-implemented method 'OpenStatsFile'
		// Here lies the not-yet-implemented method 'CloseStatsFile'
		// Here lies the not-yet-implemented method 'SerializeHeader'
		// Here lies the not-yet-implemented method 'SerializeFooter'
		// Here lies the not-yet-implemented method 'Poll'
		// Here lies the not-yet-implemented method 'GetGameTypeId'
		// Here lies the not-yet-implemented method 'LogGameIntEvent'
		// Here lies the not-yet-implemented method 'LogGameStringEvent'
		// Here lies the not-yet-implemented method 'LogGameFloatEvent'
		// Here lies the not-yet-implemented method 'LogGamePositionEvent'
		// Here lies the not-yet-implemented method 'LogTeamIntEvent'
		// Here lies the not-yet-implemented method 'LogTeamFloatEvent'
		// Here lies the not-yet-implemented method 'LogTeamStringEvent'
		// Here lies the not-yet-implemented method 'LogPlayerIntEvent'
		// Here lies the not-yet-implemented method 'LogPlayerFloatEvent'
		// Here lies the not-yet-implemented method 'LogPlayerStringEvent'
		// Here lies the not-yet-implemented method 'LogPlayerSpawnEvent'
		// Here lies the not-yet-implemented method 'LogPlayerLoginChange'
		// Here lies the not-yet-implemented method 'LogAllPlayerPositionsEvent'
		// Here lies the not-yet-implemented method 'LogPlayerKillDeath'
		// Here lies the not-yet-implemented method 'LogPlayerPlayerEvent'
		// Here lies the not-yet-implemented method 'LogWeaponIntEvent'
		// Here lies the not-yet-implemented method 'LogDamageEvent'
		// Here lies the not-yet-implemented method 'LogProjectileIntEvent'
		// Here lies the not-yet-implemented method 'LogSystemPollEvents'
		// Here lies the not-yet-implemented method 'GetGenericParamListEntry'
		// Here lies the not-yet-implemented method 'RecordAIPathFail'
		// Here lies the not-yet-implemented method 'RecordCoverLinkFireLinks'
	};
}
#undef ADD_OBJECT
