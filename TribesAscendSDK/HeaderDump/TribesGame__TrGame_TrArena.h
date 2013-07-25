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
		void ApplyServerSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrArena.ApplyServerSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetScores()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrArena.ResetScores");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RepopulatePlayerLists()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrArena.RepopulatePlayerLists");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetTeam(class Controller* Other, class UTTeamInfo* NewTeam, bool bNewTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrArena.SetTeam");
			byte* params = (byte*)malloc(12);
			*(class Controller**)params = Other;
			*(class UTTeamInfo**)(params + 4) = NewTeam;
			*(bool*)(params + 8) = bNewTeam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Logout(class Controller* Exiting)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrArena.Logout");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = Exiting;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrArena.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetLevel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrArena.ResetLevel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RespawnPlayers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrArena.RespawnPlayers");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetRound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrArena.ResetRound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ScoreKill(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrArena.ScoreKill");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CheckScore(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrArena.CheckScore");
			byte* params = (byte*)malloc(8);
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		int DetermineWinningTeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrArena.DetermineWinningTeam");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetRoundWinningTeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrArena.GetRoundWinningTeam");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void EndTheRound(class PlayerReplicationInfo* RoundWinner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrArena.EndTheRound");
			byte* params = (byte*)malloc(4);
			*(class PlayerReplicationInfo**)params = RoundWinner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GotoPendingRoundStartTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrArena.GotoPendingRoundStartTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetNumRemainingAlivePlayers(int TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrArena.GetNumRemainingAlivePlayers");
			byte* params = (byte*)malloc(8);
			*(int*)params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsBloodEagleOutOfLives()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrArena.IsBloodEagleOutOfLives");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsDiamondSwordOutOfLives()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrArena.IsDiamondSwordOutOfLives");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrArena.CheckEndGame");
			byte* params = (byte*)malloc(20);
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptArray<wchar_t>*)(params + 4) = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void CheckForAutoBalance()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrArena.CheckForAutoBalance");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendMatchCountdown(int Seconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrArena.SendMatchCountdown");
			byte* params = (byte*)malloc(4);
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AllowRespawn(class TrPlayerController* TrPC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrArena.AllowRespawn");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = TrPC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void OnServerSpawnedPlayer(class TrPlayerController* TrPC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrArena.OnServerSpawnedPlayer");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = TrPC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetGameTypeId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrArena.GetGameTypeId");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void SendMatchOver()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrArena.SendMatchOver");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
