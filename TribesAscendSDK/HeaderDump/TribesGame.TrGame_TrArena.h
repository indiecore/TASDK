#pragma once
#include "TribesGame.TrGame.h"
#include "Engine.Controller.h"
#include "UTGame.UTTeamInfo.h"
#include "Engine.PlayerReplicationInfo.h"
#include "TribesGame.TrPlayerController.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrGame_TrArena : public TrGame
	{
	public:
		static const auto MAX_NUM_ARENA_PLAYERS_PER_TEAM = 8;
		ADD_STRUCT(int, m_nGoalWonRounds, 1468)
		ADD_STRUCT(byte, m_bHasTeamBenchedAPlayer, 1464)
		ADD_STRUCT(int, m_nNumEnemiesAliveAtLastManStanding, 1456)
		void ApplyServerSettings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90385);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetScores()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90389);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RepopulatePlayerLists()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90394);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetTeam(class Controller* Other, class UTTeamInfo* NewTeam, bool bNewTeam)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90402);
			byte params[12] = { NULL };
			*(class Controller**)params = Other;
			*(class UTTeamInfo**)&params[4] = NewTeam;
			*(bool*)&params[8] = bNewTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Logout(class Controller* Exiting)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90408);
			byte params[4] = { NULL };
			*(class Controller**)params = Exiting;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90412);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetLevel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90413);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RespawnPlayers()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90414);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetRound()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90416);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ScoreKill(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90424);
			byte params[8] = { NULL };
			*(class Controller**)params = Killer;
			*(class Controller**)&params[4] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckScore(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90439);
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		int DetermineWinningTeam()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90442);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		int GetRoundWinningTeam()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90445);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void EndTheRound(class PlayerReplicationInfo* RoundWinner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90449);
			byte params[4] = { NULL };
			*(class PlayerReplicationInfo**)params = RoundWinner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GotoPendingRoundStartTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90454);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetNumRemainingAlivePlayers(int TeamIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90455);
			byte params[8] = { NULL };
			*(int*)params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool IsBloodEagleOutOfLives()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90461);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsDiamondSwordOutOfLives()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90465);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptString* Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90469);
			byte params[20] = { NULL };
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void CheckForAutoBalance()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90477);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendMatchCountdown(int Seconds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90514);
			byte params[4] = { NULL };
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AllowRespawn(class TrPlayerController* TrPC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90519);
			byte params[8] = { NULL };
			*(class TrPlayerController**)params = TrPC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void OnServerSpawnedPlayer(class TrPlayerController* TrPC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90525);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = TrPC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetGameTypeId()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90530);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void SendMatchOver()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90532);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
