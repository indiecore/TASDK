#pragma once
#include "Engine.GameplayEvents.h"
#include "Engine.GameInfo.h"
#include "Core.Object.h"
#include "Engine.Controller.h"
#include "Engine.TeamInfo.h"
#include "Engine.OnlineSubsystem.h"
#include "Engine.CoverLink.h"
#include "Engine.GenericParamListStatEntry.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GameplayEventsWriter : public GameplayEvents
	{
	public:
		static const auto GAMEEVENT_MATCH_STARTED = 0;
		static const auto GAMEEVENT_MATCH_ENDED = 1;
		static const auto GAMEEVENT_ROUND_STARTED = 2;
		static const auto GAMEEVENT_ROUND_ENDED = 3;
		static const auto GAMEEVENT_GAME_CLASS = 6;
		static const auto GAMEEVENT_GAME_OPTION_URL = 7;
		static const auto GAMEEVENT_GAME_MAPNAME = 8;
		static const auto GAMEEVENT_MEMORYUSAGE_POLL = 35;
		static const auto GAMEEVENT_FRAMERATE_POLL = 36;
		static const auto GAMEEVENT_NETWORKUSAGEIN_POLL = 37;
		static const auto GAMEEVENT_NETWORKUSAGEOUT_POLL = 38;
		static const auto GAMEEVENT_PING_POLL = 39;
		static const auto GAMEEVENT_RENDERTHREAD_POLL = 40;
		static const auto GAMEEVENT_GAMETHREAD_POLL = 41;
		static const auto GAMEEVENT_GPUFRAMETIME_POLL = 42;
		static const auto GAMEEVENT_FRAMETIME_POLL = 43;
		static const auto GAMEEVENT_TEAM_CREATED = 50;
		static const auto GAMEEVENT_TEAM_GAME_SCORE = 51;
		static const auto GAMEEVENT_TEAM_MATCH_WON = 4;
		static const auto GAMEEVENT_TEAM_ROUND_WON = 5;
		static const auto GAMEEVENT_TEAM_ROUND_STALEMATE = 6;
		static const auto GAMEEVENT_PLAYER_LOGIN = 100;
		static const auto GAMEEVENT_PLAYER_LOGOUT = 101;
		static const auto GAMEEVENT_PLAYER_SPAWN = 102;
		static const auto GAMEEVENT_PLAYER_MATCH_WON = 103;
		static const auto GAMEEVENT_PLAYER_KILL = 104;
		static const auto GAMEEVENT_PLAYER_LOCATION_POLL = 105;
		static const auto GAMEEVENT_PLAYER_TEAMCHANGE = 106;
		static const auto GAMEEVENT_PLAYER_KILL_STREAK = 107;
		static const auto GAMEEVENT_PLAYER_DEATH = 108;
		static const auto GAMEEVENT_PLAYER_ROUND_WON = 109;
		static const auto GAMEEVENT_PLAYER_ROUND_STALEMATE = 110;
		static const auto GAMEEVENT_WEAPON_DAMAGE = 150;
		static const auto GAMEEVENT_WEAPON_DAMAGE_MELEE = 151;
		static const auto GAMEEVENT_WEAPON_FIRED = 152;
		static const auto GAMEEVENT_PLAYER_KILL_NORMAL = 200;
		static const auto GAMEEVENT_GENERIC_PARAM_LIST_START = 300;
		static const auto GAMEEVENT_GENERIC_PARAM_LIST_END = 400;
		static const auto GAMEEVENT_GAME_SPECIFIC = 1000;
		static const auto GAMEEVENT_MAX_EVENTID = 0x0000FFFF;
		ADD_OBJECT(GameInfo, Game, 336)
		int ResolvePlayerIndex(class Controller* Player)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.ResolvePlayerIndex");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = Player;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void StartLogging(float HeartbeatDelta)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.StartLogging");
			byte params[4] = { NULL };
			*(float*)&params[0] = HeartbeatDelta;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetLogging(float HeartbeatDelta)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.ResetLogging");
			byte params[4] = { NULL };
			*(float*)&params[0] = HeartbeatDelta;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EndLogging()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.EndLogging");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsSessionInProgress()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.IsSessionInProgress");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool OpenStatsFile(ScriptString* Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.OpenStatsFile");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void CloseStatsFile()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.CloseStatsFile");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool SerializeHeader()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.SerializeHeader");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool SerializeFooter()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.SerializeFooter");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void Poll()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.Poll");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetGameTypeId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.GetGameTypeId");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void LogGameIntEvent(int EventID, int Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogGameIntEvent");
			byte params[8] = { NULL };
			*(int*)&params[0] = EventID;
			*(int*)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogGameStringEvent(int EventID, ScriptString* Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogGameStringEvent");
			byte params[16] = { NULL };
			*(int*)&params[0] = EventID;
			*(ScriptString**)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogGameFloatEvent(int EventID, float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogGameFloatEvent");
			byte params[8] = { NULL };
			*(int*)&params[0] = EventID;
			*(float*)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogGamePositionEvent(int EventID, Object::Vector& Position, float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogGamePositionEvent");
			byte params[20] = { NULL };
			*(int*)&params[0] = EventID;
			*(Object::Vector*)&params[4] = Position;
			*(float*)&params[16] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Position = *(Object::Vector*)&params[4];
		}
		void LogTeamIntEvent(int EventID, class TeamInfo* Team, int Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogTeamIntEvent");
			byte params[12] = { NULL };
			*(int*)&params[0] = EventID;
			*(class TeamInfo**)&params[4] = Team;
			*(int*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogTeamFloatEvent(int EventID, class TeamInfo* Team, float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogTeamFloatEvent");
			byte params[12] = { NULL };
			*(int*)&params[0] = EventID;
			*(class TeamInfo**)&params[4] = Team;
			*(float*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogTeamStringEvent(int EventID, class TeamInfo* Team, ScriptString* Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogTeamStringEvent");
			byte params[20] = { NULL };
			*(int*)&params[0] = EventID;
			*(class TeamInfo**)&params[4] = Team;
			*(ScriptString**)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogPlayerIntEvent(int EventID, class Controller* Player, int Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogPlayerIntEvent");
			byte params[12] = { NULL };
			*(int*)&params[0] = EventID;
			*(class Controller**)&params[4] = Player;
			*(int*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogPlayerFloatEvent(int EventID, class Controller* Player, float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogPlayerFloatEvent");
			byte params[12] = { NULL };
			*(int*)&params[0] = EventID;
			*(class Controller**)&params[4] = Player;
			*(float*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogPlayerStringEvent(int EventID, class Controller* Player, ScriptString* EventString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogPlayerStringEvent");
			byte params[20] = { NULL };
			*(int*)&params[0] = EventID;
			*(class Controller**)&params[4] = Player;
			*(ScriptString**)&params[8] = EventString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogPlayerSpawnEvent(int EventID, class Controller* Player, ScriptClass* PawnClass, int TeamID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogPlayerSpawnEvent");
			byte params[16] = { NULL };
			*(int*)&params[0] = EventID;
			*(class Controller**)&params[4] = Player;
			*(ScriptClass**)&params[8] = PawnClass;
			*(int*)&params[12] = TeamID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogPlayerLoginChange(int EventID, class Controller* Player, ScriptString* PlayerName, OnlineSubsystem::UniqueNetId PlayerID, bool bSplitScreen)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogPlayerLoginChange");
			byte params[32] = { NULL };
			*(int*)&params[0] = EventID;
			*(class Controller**)&params[4] = Player;
			*(ScriptString**)&params[8] = PlayerName;
			*(OnlineSubsystem::UniqueNetId*)&params[20] = PlayerID;
			*(bool*)&params[28] = bSplitScreen;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogAllPlayerPositionsEvent(int EventID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogAllPlayerPositionsEvent");
			byte params[4] = { NULL };
			*(int*)&params[0] = EventID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogPlayerKillDeath(int EventID, int KillType, class Controller* Killer, ScriptClass* dmgType, class Controller* Dead)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogPlayerKillDeath");
			byte params[20] = { NULL };
			*(int*)&params[0] = EventID;
			*(int*)&params[4] = KillType;
			*(class Controller**)&params[8] = Killer;
			*(ScriptClass**)&params[12] = dmgType;
			*(class Controller**)&params[16] = Dead;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogPlayerPlayerEvent(int EventID, class Controller* Player, class Controller* Target)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogPlayerPlayerEvent");
			byte params[12] = { NULL };
			*(int*)&params[0] = EventID;
			*(class Controller**)&params[4] = Player;
			*(class Controller**)&params[8] = Target;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogWeaponIntEvent(int EventID, class Controller* Player, ScriptClass* WeaponClass, int Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogWeaponIntEvent");
			byte params[16] = { NULL };
			*(int*)&params[0] = EventID;
			*(class Controller**)&params[4] = Player;
			*(ScriptClass**)&params[8] = WeaponClass;
			*(int*)&params[12] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogDamageEvent(int EventID, class Controller* Player, ScriptClass* dmgType, class Controller* Target, int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogDamageEvent");
			byte params[20] = { NULL };
			*(int*)&params[0] = EventID;
			*(class Controller**)&params[4] = Player;
			*(ScriptClass**)&params[8] = dmgType;
			*(class Controller**)&params[12] = Target;
			*(int*)&params[16] = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogProjectileIntEvent(int EventID, class Controller* Player, ScriptClass* Proj, int Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogProjectileIntEvent");
			byte params[16] = { NULL };
			*(int*)&params[0] = EventID;
			*(class Controller**)&params[4] = Player;
			*(ScriptClass**)&params[8] = Proj;
			*(int*)&params[12] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogSystemPollEvents()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogSystemPollEvents");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class GenericParamListStatEntry* GetGenericParamListEntry()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.GetGenericParamListEntry");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GenericParamListStatEntry**)&params[0];
		}
		void RecordAIPathFail(class Controller* AI, ScriptString* Reason, Object::Vector Dest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.RecordAIPathFail");
			byte params[28] = { NULL };
			*(class Controller**)&params[0] = AI;
			*(ScriptString**)&params[4] = Reason;
			*(Object::Vector*)&params[16] = Dest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int RecordCoverLinkFireLinks(class CoverLink* Link, class Controller* Player)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.RecordCoverLinkFireLinks");
			byte params[12] = { NULL };
			*(class CoverLink**)&params[0] = Link;
			*(class Controller**)&params[4] = Player;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
	};
}
#undef ADD_OBJECT
