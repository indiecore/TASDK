#pragma once
#include "TribesGame__TrGame.h"
#include "Engine__PlayerReplicationInfo.h"
#include "TribesGame__TrFlagTeamRabbit.h"
#include "Engine__PlayerStart.h"
#include "Engine__Pawn.h"
#include "Engine__Controller.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGame_TRTeamRabbit." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrGame_TRTeamRabbit." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrGame_TRTeamRabbit : public TrGame
	{
	public:
		ADD_OBJECT(TrFlagTeamRabbit, m_TeamRabbitFlag)
		ADD_VAR(::IntProperty, m_nBuffAmount, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_nBuffedTeamIndex, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bPlayedAnnouncerRally, 0x2)
		ADD_VAR(::BoolProperty, m_bSpawnFlagOnNextKill, 0x1)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'ResetLevel'
		// Here lies the not-yet-implemented method 'ResetScores'
		// Here lies the not-yet-implemented method 'ApplyServerSettings'
		// Here lies the not-yet-implemented method 'SpawnFlag'
		// Here lies the not-yet-implemented method 'Killed'
		// Here lies the not-yet-implemented method 'FlagDestoyed'
		// Here lies the not-yet-implemented method 'PickedUpFlag'
		// Here lies the not-yet-implemented method 'DroppedFlag'
		// Here lies the not-yet-implemented method 'AwardFlagHolder'
		// Here lies the not-yet-implemented method 'ScoreKill'
		// Here lies the not-yet-implemented method 'CheckScore'
		// Here lies the not-yet-implemented method 'CheckEndGame'
		// Here lies the not-yet-implemented method 'RatePlayerStart'
		// Here lies the not-yet-implemented method 'GetGameTypeId'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
