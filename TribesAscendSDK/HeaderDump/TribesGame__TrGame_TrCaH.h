#pragma once
#include "TribesGame__TrPawn.h"
#include "TribesGame__TrGame.h"
#include "Engine__PlayerStart.h"
#include "Engine__Controller.h"
#include "TribesGame__TrCaHCapturePoint.h"
#include "UTGame__UTTeamInfo.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGame_TrCaH." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrGame_TrCaH : public TrGame
	{
	public:
		ADD_VAR(::IntProperty, m_nPostCapturePointTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nTicketCountTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_5PointGoalScore, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_4PointGoalScore, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_3PointGoalScore, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nRemainingTicketTime, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'PreBeginPlay'
		// Here lies the not-yet-implemented method 'ApplyServerSettings'
		// Here lies the not-yet-implemented method 'SetTeam'
		// Here lies the not-yet-implemented method 'Logout'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'ResetLevel'
		// Here lies the not-yet-implemented method 'ScoreKill'
		// Here lies the not-yet-implemented method 'CheckScore'
		// Here lies the not-yet-implemented method 'GotoPendingRoundStartTimer'
		// Here lies the not-yet-implemented method 'CheckEndGame'
		// Here lies the not-yet-implemented method 'AwardPoint'
		// Here lies the not-yet-implemented method 'RestartPlayer'
		// Here lies the not-yet-implemented method 'GetGameTypeId'
		// Here lies the not-yet-implemented method 'OnCapturePointHeld'
		// Here lies the not-yet-implemented method 'OnCapturePointOwnershipChanged'
		// Here lies the not-yet-implemented method 'RatePlayerStart'
		// Here lies the not-yet-implemented method 'ChoosePlayerStart'
	};
}
#undef ADD_VAR
