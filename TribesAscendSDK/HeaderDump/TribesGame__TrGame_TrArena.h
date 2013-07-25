#pragma once
#include "TribesGame__TrPlayerController.h"
#include "TribesGame__TrGame.h"
#include "Engine__Controller.h"
#include "UTGame__UTTeamInfo.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGame_TrArena." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrGame_TrArena : public TrGame
	{
	public:
		ADD_VAR(::IntProperty, m_nGoalWonRounds, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_bHasTeamBenchedAPlayer, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nNumEnemiesAliveAtLastManStanding, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'ApplyServerSettings'
		// Here lies the not-yet-implemented method 'ResetScores'
		// Here lies the not-yet-implemented method 'RepopulatePlayerLists'
		// Here lies the not-yet-implemented method 'SetTeam'
		// Here lies the not-yet-implemented method 'Logout'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'ResetLevel'
		// Here lies the not-yet-implemented method 'RespawnPlayers'
		// Here lies the not-yet-implemented method 'ResetRound'
		// Here lies the not-yet-implemented method 'ScoreKill'
		// Here lies the not-yet-implemented method 'CheckScore'
		// Here lies the not-yet-implemented method 'DetermineWinningTeam'
		// Here lies the not-yet-implemented method 'GetRoundWinningTeam'
		// Here lies the not-yet-implemented method 'EndTheRound'
		// Here lies the not-yet-implemented method 'GotoPendingRoundStartTimer'
		// Here lies the not-yet-implemented method 'GetNumRemainingAlivePlayers'
		// Here lies the not-yet-implemented method 'IsBloodEagleOutOfLives'
		// Here lies the not-yet-implemented method 'IsDiamondSwordOutOfLives'
		// Here lies the not-yet-implemented method 'CheckEndGame'
		// Here lies the not-yet-implemented method 'CheckForAutoBalance'
		// Here lies the not-yet-implemented method 'SendMatchCountdown'
		// Here lies the not-yet-implemented method 'AllowRespawn'
		// Here lies the not-yet-implemented method 'OnServerSpawnedPlayer'
		// Here lies the not-yet-implemented method 'GetGameTypeId'
		// Here lies the not-yet-implemented method 'SendMatchOver'
	};
}
#undef ADD_VAR
