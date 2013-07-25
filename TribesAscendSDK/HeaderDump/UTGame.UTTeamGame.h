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
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTTeamGame." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTTeamGame." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTTeamGame : public UTDeathmatch
	{
	public:
		ADD_VAR(::NameProperty, FlagKillMessageName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SwapRequestTime, 0xFFFFFFFF)
		ADD_OBJECT(PlayerController, PendingTeamSwap)
		ADD_OBJECT(ScriptClass, TeamScoreMessageClass)
		ADD_VAR(::StrProperty, TeamFactions, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, TeamAIType)
		ADD_OBJECT(UTTeamInfo, Teams)
		ADD_VAR(::FloatProperty, TeammateBoost, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FriendlyFireScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bForceAllRed, 0x20)
		ADD_VAR(::BoolProperty, bScoreVictimsTarget, 0x10)
		ADD_VAR(::BoolProperty, bSpawnInTeamArea, 0x8)
		ADD_VAR(::BoolProperty, bScoreTeamKills, 0x4)
		ADD_VAR(::BoolProperty, bAllowNonTeamChat, 0x2)
		ADD_VAR(::BoolProperty, bPlayersBalanceTeams, 0x1)
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostLogin(class PlayerController* NewPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.PostLogin");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = NewPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FindNewObjectives(class UTGameObjective* DisabledObjective)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.FindNewObjectives");
			byte* params = (byte*)malloc(4);
			*(class UTGameObjective**)params = DisabledObjective;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CreateTeam(int TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.CreateTeam");
			byte* params = (byte*)malloc(4);
			*(int*)params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetHandicapNeed(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.GetHandicapNeed");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		class UTTeamInfo* GetBotTeam(int TeamBots, bool bUseTeamIndex, int TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.GetBotTeam");
			byte* params = (byte*)malloc(16);
			*(int*)params = TeamBots;
			*(bool*)(params + 4) = bUseTeamIndex;
			*(int*)(params + 8) = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTTeamInfo**)(params + 12);
			free(params);
			return returnVal;
		}
		int LevelRecommendedPlayers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.LevelRecommendedPlayers");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		bool CheckMaxLives(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.CheckMaxLives");
			byte* params = (byte*)malloc(8);
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void InitGame(ScriptArray<wchar_t> Options, ScriptArray<wchar_t>& ErrorMessage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.InitGame");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Options;
			*(ScriptArray<wchar_t>*)(params + 12) = ErrorMessage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ErrorMessage = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
		}
		bool TooManyBots(class Controller* botToRemove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.TooManyBots");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = botToRemove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void NotifyKilled(class Controller* Killer, class Controller* KilledPlayer, class Pawn* KilledPawn, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.NotifyKilled");
			byte* params = (byte*)malloc(16);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = KilledPlayer;
			*(class Pawn**)(params + 8) = KilledPawn;
			*(ScriptClass**)(params + 12) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.CheckEndGame");
			byte* params = (byte*)malloc(20);
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptArray<wchar_t>*)(params + 4) = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void SetEndGameFocus(class PlayerReplicationInfo* Winner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.SetEndGameFocus");
			byte* params = (byte*)malloc(4);
			*(class PlayerReplicationInfo**)params = Winner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CanSpectate(class PlayerController* Viewer, class PlayerReplicationInfo* ViewTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.CanSpectate");
			byte* params = (byte*)malloc(12);
			*(class PlayerController**)params = Viewer;
			*(class PlayerReplicationInfo**)(params + 4) = ViewTarget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void RestartGame()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.RestartGame");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		byte PickTeam(byte Num, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.PickTeam");
			byte* params = (byte*)malloc(6);
			*params = Num;
			*(class Controller**)(params + 4) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 8);
			free(params);
			return returnVal;
		}
		bool ChangeTeam(class Controller* Other, int Num, bool bNewTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.ChangeTeam");
			byte* params = (byte*)malloc(16);
			*(class Controller**)params = Other;
			*(int*)(params + 4) = Num;
			*(bool*)(params + 8) = bNewTeam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void SetTeam(class Controller* Other, class UTTeamInfo* NewTeam, bool bNewTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.SetTeam");
			byte* params = (byte*)malloc(12);
			*(class Controller**)params = Other;
			*(class UTTeamInfo**)(params + 4) = NewTeam;
			*(bool*)(params + 8) = bNewTeam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float RatePlayerStart(class PlayerStart* P, byte Team, class Controller* Player)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.RatePlayerStart");
			byte* params = (byte*)malloc(13);
			*(class PlayerStart**)params = P;
			*(params + 4) = Team;
			*(class Controller**)(params + 8) = Player;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		bool CheckScore(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.CheckScore");
			byte* params = (byte*)malloc(8);
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		class Pawn* FindVictimsTarget(class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.FindVictimsTarget");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Pawn**)(params + 4);
			free(params);
			return returnVal;
		}
		bool NearGoal(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.NearGoal");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void ScoreKill(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.ScoreKill");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CampaignSkillAdjust(class UTBot* aBot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.CampaignSkillAdjust");
			byte* params = (byte*)malloc(4);
			*(class UTBot**)params = aBot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AdjustSkill(class AIController* B, class PlayerController* P, bool bWinner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.AdjustSkill");
			byte* params = (byte*)malloc(12);
			*(class AIController**)params = B;
			*(class PlayerController**)(params + 4) = P;
			*(bool*)(params + 8) = bWinner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendFlagKillMessage(class Controller* Killer, class UTPlayerReplicationInfo* KillerPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.SendFlagKillMessage");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Killer;
			*(class UTPlayerReplicationInfo**)(params + 4) = KillerPRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool DominatingVictory()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.DominatingVictory");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsAWinner(class PlayerController* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.IsAWinner");
			byte* params = (byte*)malloc(8);
			*(class PlayerController**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsWinningTeam(class TeamInfo* T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.IsWinningTeam");
			byte* params = (byte*)malloc(8);
			*(class TeamInfo**)params = T;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void PlayRegularEndOfMatchMessage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.PlayRegularEndOfMatchMessage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AnnounceScore(int ScoringTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.AnnounceScore");
			byte* params = (byte*)malloc(4);
			*(int*)params = ScoringTeam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OverridePRI(class PlayerController* PC, class PlayerReplicationInfo* OldPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.OverridePRI");
			byte* params = (byte*)malloc(8);
			*(class PlayerController**)params = PC;
			*(class PlayerReplicationInfo**)(params + 4) = OldPRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AllowClientToTeleport(class UTPlayerReplicationInfo* ClientPRI, class Actor* DestinationActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.AllowClientToTeleport");
			byte* params = (byte*)malloc(12);
			*(class UTPlayerReplicationInfo**)params = ClientPRI;
			*(class Actor**)(params + 4) = DestinationActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void ShowPathTo(class PlayerController* P, int TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.ShowPathTo");
			byte* params = (byte*)malloc(8);
			*(class PlayerController**)params = P;
			*(int*)(params + 4) = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetSeamlessTravelActorList(bool bToEntry, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& ActorList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.GetSeamlessTravelActorList");
			byte* params = (byte*)malloc(16);
			*(bool*)params = bToEntry;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = ActorList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ActorList = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			free(params);
		}
		void Logout(class Controller* Exiting)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.Logout");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = Exiting;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HandleSeamlessTravelPlayer(class Controller*& C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.HandleSeamlessTravelPlayer");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			C = *(class Controller**)params;
			free(params);
		}
		void ParseSpeechRecipients(class UTPlayerController* Speaker, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Words, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Recipients)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.ParseSpeechRecipients");
			byte* params = (byte*)malloc(28);
			*(class UTPlayerController**)params = Speaker;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = Words;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16) = Recipients;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Words = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			Recipients = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16);
			free(params);
		}
		void ProcessSpeechOrders(class UTPlayerController* Speaker, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Words, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Recipients)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.ProcessSpeechOrders");
			byte* params = (byte*)malloc(28);
			*(class UTPlayerController**)params = Speaker;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = Words;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16) = Recipients;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Words = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			Recipients = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16);
			free(params);
		}
		void ProcessSpeechRecognition(class UTPlayerController* Speaker, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Words)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTTeamGame.ProcessSpeechRecognition");
			byte* params = (byte*)malloc(16);
			*(class UTPlayerController**)params = Speaker;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = Words;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Words = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
