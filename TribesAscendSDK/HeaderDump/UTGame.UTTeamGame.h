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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45150);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostLogin(class PlayerController* NewPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45152);
			byte params[4] = { NULL };
			*(class PlayerController**)params = NewPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FindNewObjectives(class UTGameObjective* DisabledObjective)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45155);
			byte params[4] = { NULL };
			*(class UTGameObjective**)params = DisabledObjective;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreateTeam(int TeamIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45157);
			byte params[4] = { NULL };
			*(int*)params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetHandicapNeed(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45159);
			byte params[8] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		class UTTeamInfo* GetBotTeam(int TeamBots, bool bUseTeamIndex, int TeamIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45163);
			byte params[16] = { NULL };
			*(int*)params = TeamBots;
			*(bool*)&params[4] = bUseTeamIndex;
			*(int*)&params[8] = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTTeamInfo**)&params[12];
		}
		int LevelRecommendedPlayers()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45173);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		bool CheckMaxLives(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45177);
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void InitGame(ScriptString* Options, ScriptString*& ErrorMessage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45183);
			byte params[24] = { NULL };
			*(ScriptString**)params = Options;
			*(ScriptString**)&params[12] = ErrorMessage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ErrorMessage = *(ScriptString**)&params[12];
		}
		bool TooManyBots(class Controller* botToRemove)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45188);
			byte params[8] = { NULL };
			*(class Controller**)params = botToRemove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void NotifyKilled(class Controller* Killer, class Controller* KilledPlayer, class Pawn* KilledPawn, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45193);
			byte params[16] = { NULL };
			*(class Controller**)params = Killer;
			*(class Controller**)&params[4] = KilledPlayer;
			*(class Pawn**)&params[8] = KilledPawn;
			*(ScriptClass**)&params[12] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptString* Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45198);
			byte params[20] = { NULL };
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void SetEndGameFocus(class PlayerReplicationInfo* Winner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45204);
			byte params[4] = { NULL };
			*(class PlayerReplicationInfo**)params = Winner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanSpectate(class PlayerController* Viewer, class PlayerReplicationInfo* ViewTarget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45207);
			byte params[12] = { NULL };
			*(class PlayerController**)params = Viewer;
			*(class PlayerReplicationInfo**)&params[4] = ViewTarget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void RestartGame()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45211);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		byte PickTeam(byte Num, class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45221);
			byte params[6] = { NULL };
			*params = Num;
			*(class Controller**)&params[4] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[8];
		}
		bool ChangeTeam(class Controller* Other, int Num, bool bNewTeam)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45231);
			byte params[16] = { NULL };
			*(class Controller**)params = Other;
			*(int*)&params[4] = Num;
			*(bool*)&params[8] = bNewTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void SetTeam(class Controller* Other, class UTTeamInfo* NewTeam, bool bNewTeam)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45238);
			byte params[12] = { NULL };
			*(class Controller**)params = Other;
			*(class UTTeamInfo**)&params[4] = NewTeam;
			*(bool*)&params[8] = bNewTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float RatePlayerStart(class PlayerStart* P, byte Team, class Controller* Player)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45243);
			byte params[13] = { NULL };
			*(class PlayerStart**)params = P;
			params[4] = Team;
			*(class Controller**)&params[8] = Player;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		bool CheckScore(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45249);
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class Pawn* FindVictimsTarget(class Controller* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45252);
			byte params[8] = { NULL };
			*(class Controller**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Pawn**)&params[4];
		}
		bool NearGoal(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45262);
			byte params[8] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ScoreKill(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45265);
			byte params[8] = { NULL };
			*(class Controller**)params = Killer;
			*(class Controller**)&params[4] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CampaignSkillAdjust(class UTBot* aBot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45273);
			byte params[4] = { NULL };
			*(class UTBot**)params = aBot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdjustSkill(class AIController* B, class PlayerController* P, bool bWinner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45275);
			byte params[12] = { NULL };
			*(class AIController**)params = B;
			*(class PlayerController**)&params[4] = P;
			*(bool*)&params[8] = bWinner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendFlagKillMessage(class Controller* Killer, class UTPlayerReplicationInfo* KillerPRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45280);
			byte params[8] = { NULL };
			*(class Controller**)params = Killer;
			*(class UTPlayerReplicationInfo**)&params[4] = KillerPRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool DominatingVictory()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45283);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsAWinner(class PlayerController* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45285);
			byte params[8] = { NULL };
			*(class PlayerController**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsWinningTeam(class TeamInfo* T)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45288);
			byte params[8] = { NULL };
			*(class TeamInfo**)params = T;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PlayRegularEndOfMatchMessage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45291);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AnnounceScore(int ScoringTeam)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45294);
			byte params[4] = { NULL };
			*(int*)params = ScoringTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OverridePRI(class PlayerController* PC, class PlayerReplicationInfo* OldPRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45299);
			byte params[8] = { NULL };
			*(class PlayerController**)params = PC;
			*(class PlayerReplicationInfo**)&params[4] = OldPRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AllowClientToTeleport(class UTPlayerReplicationInfo* ClientPRI, class Actor* DestinationActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45304);
			byte params[12] = { NULL };
			*(class UTPlayerReplicationInfo**)params = ClientPRI;
			*(class Actor**)&params[4] = DestinationActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void ShowPathTo(class PlayerController* P, int TeamNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45308);
			byte params[8] = { NULL };
			*(class PlayerController**)params = P;
			*(int*)&params[4] = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetSeamlessTravelActorList(bool bToEntry, ScriptArray<class Actor*>& ActorList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45314);
			byte params[16] = { NULL };
			*(bool*)params = bToEntry;
			*(ScriptArray<class Actor*>*)&params[4] = ActorList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ActorList = *(ScriptArray<class Actor*>*)&params[4];
		}
		void Logout(class Controller* Exiting)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45319);
			byte params[4] = { NULL };
			*(class Controller**)params = Exiting;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HandleSeamlessTravelPlayer(class Controller*& C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45324);
			byte params[4] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			C = *(class Controller**)params;
		}
		void ParseSpeechRecipients(class UTPlayerController* Speaker, ScriptArray<OnlineSubsystem::SpeechRecognizedWord>& Words, ScriptArray<class UTBot*>& Recipients)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45327);
			byte params[28] = { NULL };
			*(class UTPlayerController**)params = Speaker;
			*(ScriptArray<OnlineSubsystem::SpeechRecognizedWord>*)&params[4] = Words;
			*(ScriptArray<class UTBot*>*)&params[16] = Recipients;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Words = *(ScriptArray<OnlineSubsystem::SpeechRecognizedWord>*)&params[4];
			Recipients = *(ScriptArray<class UTBot*>*)&params[16];
		}
		void ProcessSpeechOrders(class UTPlayerController* Speaker, ScriptArray<OnlineSubsystem::SpeechRecognizedWord>& Words, ScriptArray<class UTBot*>& Recipients)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45339);
			byte params[28] = { NULL };
			*(class UTPlayerController**)params = Speaker;
			*(ScriptArray<OnlineSubsystem::SpeechRecognizedWord>*)&params[4] = Words;
			*(ScriptArray<class UTBot*>*)&params[16] = Recipients;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Words = *(ScriptArray<OnlineSubsystem::SpeechRecognizedWord>*)&params[4];
			Recipients = *(ScriptArray<class UTBot*>*)&params[16];
		}
		void ProcessSpeechRecognition(class UTPlayerController* Speaker, ScriptArray<OnlineSubsystem::SpeechRecognizedWord>& Words)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45349);
			byte params[16] = { NULL };
			*(class UTPlayerController**)params = Speaker;
			*(ScriptArray<OnlineSubsystem::SpeechRecognizedWord>*)&params[4] = Words;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Words = *(ScriptArray<OnlineSubsystem::SpeechRecognizedWord>*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
