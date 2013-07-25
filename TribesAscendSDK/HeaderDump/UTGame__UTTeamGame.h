#pragma once
#include "Engine__PlayerReplicationInfo.h"
#include "UTGame__UTDeathmatch.h"
#include "Engine__PlayerController.h"
#include "UTGame__UTTeamInfo.h"
#include "UTGame__UTBot.h"
#include "UTGame__UTGameObjective.h"
#include "Engine__PlayerStart.h"
#include "Engine__Controller.h"
#include "Engine__Pawn.h"
#include "Engine__AIController.h"
#include "UTGame__UTPlayerReplicationInfo.h"
#include "Engine__TeamInfo.h"
#include "Engine__Actor.h"
#include "UTGame__UTPlayerController.h"
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
		// Here lies the not-yet-implemented method 'PreBeginPlay'
		// Here lies the not-yet-implemented method 'PostLogin'
		// Here lies the not-yet-implemented method 'FindNewObjectives'
		// Here lies the not-yet-implemented method 'CreateTeam'
		// Here lies the not-yet-implemented method 'GetHandicapNeed'
		// Here lies the not-yet-implemented method 'GetBotTeam'
		// Here lies the not-yet-implemented method 'LevelRecommendedPlayers'
		// Here lies the not-yet-implemented method 'CheckMaxLives'
		// Here lies the not-yet-implemented method 'InitGame'
		// Here lies the not-yet-implemented method 'TooManyBots'
		// Here lies the not-yet-implemented method 'NotifyKilled'
		// Here lies the not-yet-implemented method 'CheckEndGame'
		// Here lies the not-yet-implemented method 'SetEndGameFocus'
		// Here lies the not-yet-implemented method 'CanSpectate'
		// Here lies the not-yet-implemented method 'RestartGame'
		// Here lies the not-yet-implemented method 'PickTeam'
		// Here lies the not-yet-implemented method 'ChangeTeam'
		// Here lies the not-yet-implemented method 'SetTeam'
		// Here lies the not-yet-implemented method 'RatePlayerStart'
		// Here lies the not-yet-implemented method 'CheckScore'
		// Here lies the not-yet-implemented method 'FindVictimsTarget'
		// Here lies the not-yet-implemented method 'NearGoal'
		// Here lies the not-yet-implemented method 'ScoreKill'
		// Here lies the not-yet-implemented method 'CampaignSkillAdjust'
		// Here lies the not-yet-implemented method 'AdjustSkill'
		// Here lies the not-yet-implemented method 'SendFlagKillMessage'
		// Here lies the not-yet-implemented method 'DominatingVictory'
		// Here lies the not-yet-implemented method 'IsAWinner'
		// Here lies the not-yet-implemented method 'IsWinningTeam'
		// Here lies the not-yet-implemented method 'PlayRegularEndOfMatchMessage'
		// Here lies the not-yet-implemented method 'AnnounceScore'
		// Here lies the not-yet-implemented method 'OverridePRI'
		// Here lies the not-yet-implemented method 'AllowClientToTeleport'
		// Here lies the not-yet-implemented method 'ShowPathTo'
		// Here lies the not-yet-implemented method 'GetSeamlessTravelActorList'
		// Here lies the not-yet-implemented method 'Logout'
		// Here lies the not-yet-implemented method 'HandleSeamlessTravelPlayer'
		// Here lies the not-yet-implemented method 'ParseSpeechRecipients'
		// Here lies the not-yet-implemented method 'ProcessSpeechOrders'
		// Here lies the not-yet-implemented method 'ProcessSpeechRecognition'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
