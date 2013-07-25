#pragma once
#include "TribesGame__TrPlayerController.h"
#include "TribesGame__TrGame.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__PlayerStart.h"
#include "Engine__Pawn.h"
#include "Engine__Controller.h"
#include "TribesGame__TrFlagRabbit.h"
#include "UTGame__UTTeamInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGame_TRRabbit." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrGame_TRRabbit." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrGame_TRRabbit : public TrGame
	{
	public:
		ADD_OBJECT(PlayerReplicationInfo, m_HolderPRI)
		ADD_OBJECT(PlayerReplicationInfo, m_Leader)
		ADD_VAR(::FloatProperty, m_fScoreInterval, 0xFFFFFFFF)
		ADD_OBJECT(TrFlagRabbit, m_Flag)
		// Here lies the not-yet-implemented method 'ApplyServerSettings'
		// Here lies the not-yet-implemented method 'RegisterFlag'
		// Here lies the not-yet-implemented method 'PickedUpFlag'
		// Here lies the not-yet-implemented method 'DroppedFlag'
		// Here lies the not-yet-implemented method 'SetTeam'
		// Here lies the not-yet-implemented method 'ScoreFlagTimer'
		// Here lies the not-yet-implemented method 'ScoreFlagHold'
		// Here lies the not-yet-implemented method 'ScoreKill'
		// Here lies the not-yet-implemented method 'ChangePreviousRabbitTeam'
		// Here lies the not-yet-implemented method 'MakeScoreStruct'
		// Here lies the not-yet-implemented method 'SortPlayerScores'
		// Here lies the not-yet-implemented method 'CheckScore'
		// Here lies the not-yet-implemented method 'CheckEndGame'
		// Here lies the not-yet-implemented method 'PickTeam'
		// Here lies the not-yet-implemented method 'PickTeamForMigration'
		// Here lies the not-yet-implemented method 'PlayEndOfMatchMessage'
		// Here lies the not-yet-implemented method 'DiscardInventory'
		// Here lies the not-yet-implemented method 'RatePlayerStart'
		// Here lies the not-yet-implemented method 'GetGameTypeId'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
