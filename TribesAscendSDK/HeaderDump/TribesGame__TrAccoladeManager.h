#pragma once
#include "Core__Object.h"
#include "TribesGame__TrStatsInterface.h"
#include "TribesGame__TrGame.h"
#include "TribesGame__TrPlayerController.h"
#include "Engine__Controller.h"
#include "TribesGame__TrVehicle.h"
#include "UTGame__UTPlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAccoladeManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAccoladeManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAccoladeManager : public Object
	{
	public:
		ADD_VAR(::IntProperty, m_nLastFlagReturnTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastFlagGrabTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MAXIMUM_EMERGENCY_GRAB_DISTANCE, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MAXIMUM_FLAG_DEFENSE_DISTANCE, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MINIMUM_ULTRA_GRAB_SPEED, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MINIMUM_FAST_GRAB_SPEED, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MAXIMUM_LLAMA_GRAB_SPEED, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MINIMUM_TIME_FLAG_CREDITS, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nCurrSpinfusorKillStreak, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nCurrExplosiveKillStreak, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nCurrSnipingKillStreak, 0xFFFFFFFF)
		ADD_OBJECT(TrStatsInterface, Stats)
		ADD_OBJECT(TrPlayerController, m_TrPC)
		ADD_OBJECT(TrGame, m_TrG)
		// Here lies the not-yet-implemented method 'GetFlagDistance'
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'ResetStreaks'
		// Here lies the not-yet-implemented method 'GiveAssist'
		// Here lies the not-yet-implemented method 'GiveVehicleAssist'
		// Here lies the not-yet-implemented method 'KillAsRabbit'
		// Here lies the not-yet-implemented method 'KilledTheRabbit'
		// Here lies the not-yet-implemented method 'KilledTheFlagHolder'
		// Here lies the not-yet-implemented method 'UpdateStandardKillingSpree'
		// Here lies the not-yet-implemented method 'KilledGenerator'
		// Here lies the not-yet-implemented method 'RepairedBase'
		// Here lies the not-yet-implemented method 'KilledBaseTurret'
		// Here lies the not-yet-implemented method 'KilledBaseRadar'
		// Here lies the not-yet-implemented method 'FlagGrab'
		// Here lies the not-yet-implemented method 'FlagGrabDeathmatch'
		// Here lies the not-yet-implemented method 'FlagHeld'
		// Here lies the not-yet-implemented method 'FlagAssist'
		// Here lies the not-yet-implemented method 'FlagCapture'
		// Here lies the not-yet-implemented method 'FlagReturn'
		// Here lies the not-yet-implemented method 'NoJoy'
		// Here lies the not-yet-implemented method 'GameCompleted'
		// Here lies the not-yet-implemented method 'GameWon'
		// Here lies the not-yet-implemented method 'UpdateMultiKills'
		// Here lies the not-yet-implemented method 'VehicleDestroyed'
		// Here lies the not-yet-implemented method 'UpdateSpecialAccolades'
		// Here lies the not-yet-implemented method 'QueueAccolade'
		// Here lies the not-yet-implemented method 'CreditsGiven'
		// Here lies the not-yet-implemented method 'BroadcastAccolade'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
