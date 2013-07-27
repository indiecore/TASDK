#pragma once
#include "UTGame.UTDeathmatch.h"
#include "Engine.Pawn.h"
#include "Engine.PlayerController.h"
#include "UTGame.UTTeamInfo.h"
#include "UTGame.UTGameObjective.h"
#include "Engine.PlayerReplicationInfo.h"
#include "UTGame.UTBot.h"
#include "Engine.PlayerStart.h"
#include "Engine.Controller.h"
#include "Engine.AIController.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#include "Engine.TeamInfo.h"
#include "Engine.Actor.h"
#include "UTGame.UTPlayerController.h"
#include "Engine.OnlineSubsystem.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTTeamGame : public UTDeathmatch
	{
	public:
		ADD_STRUCT(ScriptName, FlagKillMessageName, 1320)
		ADD_STRUCT(float, SwapRequestTime, 1316)
		ADD_OBJECT(PlayerController, PendingTeamSwap, 1312)
		ADD_OBJECT(ScriptClass, TeamScoreMessageClass, 1308)
		ADD_STRUCT(ScriptString*, TeamFactions, 1284)
		ADD_OBJECT(ScriptClass, TeamAIType, 1276)
		ADD_OBJECT(UTTeamInfo, Teams, 1268)
		ADD_STRUCT(float, TeammateBoost, 1264)
		ADD_STRUCT(float, FriendlyFireScale, 1260)
		ADD_BOOL(bForceAllRed, 1256, 0x20)
		ADD_BOOL(bScoreVictimsTarget, 1256, 0x10)
		ADD_BOOL(bSpawnInTeamArea, 1256, 0x8)
		ADD_BOOL(bScoreTeamKills, 1256, 0x4)
		ADD_BOOL(bAllowNonTeamChat, 1256, 0x2)
		ADD_BOOL(bPlayersBalanceTeams, 1256, 0x1)
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostLogin(class PlayerController* NewPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.PostLogin");
			byte params[4] = { NULL };
			*(class PlayerController**)&params[0] = NewPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FindNewObjectives(class UTGameObjective* DisabledObjective)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.FindNewObjectives");
			byte params[4] = { NULL };
			*(class UTGameObjective**)&params[0] = DisabledObjective;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreateTeam(int TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.CreateTeam");
			byte params[4] = { NULL };
			*(int*)&params[0] = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetHandicapNeed(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.GetHandicapNeed");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		class UTTeamInfo* GetBotTeam(int TeamBots, bool bUseTeamIndex, int TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.GetBotTeam");
			byte params[16] = { NULL };
			*(int*)&params[0] = TeamBots;
			*(bool*)&params[4] = bUseTeamIndex;
			*(int*)&params[8] = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTTeamInfo**)&params[12];
		}
		int LevelRecommendedPlayers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.LevelRecommendedPlayers");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		bool CheckMaxLives(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.CheckMaxLives");
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void InitGame(ScriptString* Options, ScriptString*& ErrorMessage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.InitGame");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = Options;
			*(ScriptString**)&params[12] = ErrorMessage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ErrorMessage = *(ScriptString**)&params[12];
		}
		bool TooManyBots(class Controller* botToRemove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.TooManyBots");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = botToRemove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void NotifyKilled(class Controller* Killer, class Controller* KilledPlayer, class Pawn* KilledPawn, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.NotifyKilled");
			byte params[16] = { NULL };
			*(class Controller**)&params[0] = Killer;
			*(class Controller**)&params[4] = KilledPlayer;
			*(class Pawn**)&params[8] = KilledPawn;
			*(ScriptClass**)&params[12] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptString* Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.CheckEndGame");
			byte params[20] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = Winner;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void SetEndGameFocus(class PlayerReplicationInfo* Winner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.SetEndGameFocus");
			byte params[4] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = Winner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanSpectate(class PlayerController* Viewer, class PlayerReplicationInfo* ViewTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.CanSpectate");
			byte params[12] = { NULL };
			*(class PlayerController**)&params[0] = Viewer;
			*(class PlayerReplicationInfo**)&params[4] = ViewTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void RestartGame()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.RestartGame");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		byte PickTeam(byte Num, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.PickTeam");
			byte params[6] = { NULL };
			params[0] = Num;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[8];
		}
		bool ChangeTeam(class Controller* Other, int Num, bool bNewTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.ChangeTeam");
			byte params[16] = { NULL };
			*(class Controller**)&params[0] = Other;
			*(int*)&params[4] = Num;
			*(bool*)&params[8] = bNewTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void SetTeam(class Controller* Other, class UTTeamInfo* NewTeam, bool bNewTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.SetTeam");
			byte params[12] = { NULL };
			*(class Controller**)&params[0] = Other;
			*(class UTTeamInfo**)&params[4] = NewTeam;
			*(bool*)&params[8] = bNewTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float RatePlayerStart(class PlayerStart* P, byte Team, class Controller* Player)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.RatePlayerStart");
			byte params[13] = { NULL };
			*(class PlayerStart**)&params[0] = P;
			params[4] = Team;
			*(class Controller**)&params[8] = Player;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		bool CheckScore(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.CheckScore");
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class Pawn* FindVictimsTarget(class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.FindVictimsTarget");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Pawn**)&params[4];
		}
		bool NearGoal(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.NearGoal");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ScoreKill(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.ScoreKill");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = Killer;
			*(class Controller**)&params[4] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CampaignSkillAdjust(class UTBot* aBot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.CampaignSkillAdjust");
			byte params[4] = { NULL };
			*(class UTBot**)&params[0] = aBot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdjustSkill(class AIController* B, class PlayerController* P, bool bWinner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.AdjustSkill");
			byte params[12] = { NULL };
			*(class AIController**)&params[0] = B;
			*(class PlayerController**)&params[4] = P;
			*(bool*)&params[8] = bWinner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendFlagKillMessage(class Controller* Killer, class UTPlayerReplicationInfo* KillerPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.SendFlagKillMessage");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = Killer;
			*(class UTPlayerReplicationInfo**)&params[4] = KillerPRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool DominatingVictory()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.DominatingVictory");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool IsAWinner(class PlayerController* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.IsAWinner");
			byte params[8] = { NULL };
			*(class PlayerController**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsWinningTeam(class TeamInfo* T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.IsWinningTeam");
			byte params[8] = { NULL };
			*(class TeamInfo**)&params[0] = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PlayRegularEndOfMatchMessage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.PlayRegularEndOfMatchMessage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AnnounceScore(int ScoringTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.AnnounceScore");
			byte params[4] = { NULL };
			*(int*)&params[0] = ScoringTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OverridePRI(class PlayerController* PC, class PlayerReplicationInfo* OldPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.OverridePRI");
			byte params[8] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			*(class PlayerReplicationInfo**)&params[4] = OldPRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AllowClientToTeleport(class UTPlayerReplicationInfo* ClientPRI, class Actor* DestinationActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.AllowClientToTeleport");
			byte params[12] = { NULL };
			*(class UTPlayerReplicationInfo**)&params[0] = ClientPRI;
			*(class Actor**)&params[4] = DestinationActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void ShowPathTo(class PlayerController* P, int TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.ShowPathTo");
			byte params[8] = { NULL };
			*(class PlayerController**)&params[0] = P;
			*(int*)&params[4] = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetSeamlessTravelActorList(bool bToEntry, ScriptArray<class Actor*>& ActorList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.GetSeamlessTravelActorList");
			byte params[16] = { NULL };
			*(bool*)&params[0] = bToEntry;
			*(ScriptArray<class Actor*>*)&params[4] = ActorList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ActorList = *(ScriptArray<class Actor*>*)&params[4];
		}
		void Logout(class Controller* Exiting)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.Logout");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = Exiting;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HandleSeamlessTravelPlayer(class Controller*& C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.HandleSeamlessTravelPlayer");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			C = *(class Controller**)&params[0];
		}
		void ParseSpeechRecipients(class UTPlayerController* Speaker, ScriptArray<OnlineSubsystem::SpeechRecognizedWord>& Words, ScriptArray<class UTBot*>& Recipients)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.ParseSpeechRecipients");
			byte params[28] = { NULL };
			*(class UTPlayerController**)&params[0] = Speaker;
			*(ScriptArray<OnlineSubsystem::SpeechRecognizedWord>*)&params[4] = Words;
			*(ScriptArray<class UTBot*>*)&params[16] = Recipients;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Words = *(ScriptArray<OnlineSubsystem::SpeechRecognizedWord>*)&params[4];
			Recipients = *(ScriptArray<class UTBot*>*)&params[16];
		}
		void ProcessSpeechOrders(class UTPlayerController* Speaker, ScriptArray<OnlineSubsystem::SpeechRecognizedWord>& Words, ScriptArray<class UTBot*>& Recipients)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.ProcessSpeechOrders");
			byte params[28] = { NULL };
			*(class UTPlayerController**)&params[0] = Speaker;
			*(ScriptArray<OnlineSubsystem::SpeechRecognizedWord>*)&params[4] = Words;
			*(ScriptArray<class UTBot*>*)&params[16] = Recipients;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Words = *(ScriptArray<OnlineSubsystem::SpeechRecognizedWord>*)&params[4];
			Recipients = *(ScriptArray<class UTBot*>*)&params[16];
		}
		void ProcessSpeechRecognition(class UTPlayerController* Speaker, ScriptArray<OnlineSubsystem::SpeechRecognizedWord>& Words)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.ProcessSpeechRecognition");
			byte params[16] = { NULL };
			*(class UTPlayerController**)&params[0] = Speaker;
			*(ScriptArray<OnlineSubsystem::SpeechRecognizedWord>*)&params[4] = Words;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Words = *(ScriptArray<OnlineSubsystem::SpeechRecognizedWord>*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
