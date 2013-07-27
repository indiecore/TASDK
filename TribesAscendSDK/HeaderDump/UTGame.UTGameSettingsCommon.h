#pragma once
#include "UDKBase.UDKGameSettingsCommon.h"
#include "Engine.GameInfo.h"
#include "UTGame.UTUIDataStore_MenuItems.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTGameSettingsCommon : public UDKGameSettingsCommon
	{
	public:
		static const auto GS_USERNAME_MAXLENGTH = 15;
		static const auto GS_PASSWORD_MAXLENGTH = 30;
		static const auto GS_MESSAGE_MAXLENGTH = 255;
		static const auto GS_EMAIL_MAXLENGTH = 50;
		static const auto GS_CDKEY_PART_MAXLENGTH = 4;
		static const auto CONTEXT_PRESENCE_MENUPRESENCE = 0;
		static const auto CONTEXT_GAME_MODE = 0x0000800B;
		static const auto CONTEXT_GAME_MODE_DM = 0;
		static const auto CONTEXT_GAME_MODE_CTF = 1;
		static const auto CONTEXT_GAME_MODE_WAR = 2;
		static const auto CONTEXT_GAME_MODE_VCTF = 3;
		static const auto CONTEXT_GAME_MODE_TDM = 4;
		static const auto CONTEXT_GAME_MODE_DUEL = 5;
		static const auto CONTEXT_GAME_MODE_CUSTOM = 6;
		static const auto CONTEXT_GAME_MODE_CAMPAIGN = 7;
		static const auto CONTEXT_MAPNAME = 0;
		static const auto CONTEXT_LOCKEDSERVER = 1;
		static const auto CONTEXT_ALLOWKEYBOARD = 2;
		static const auto CONTEXT_BOTSKILL = 10;
		static const auto CONTEXT_PURESERVER = 11;
		static const auto CONTEXT_VSBOTS = 12;
		static const auto CONTEXT_CAMPAIGN = 13;
		static const auto CONTEXT_FORCERESPAWN = 14;
		static const auto CONTEXT_FULLSERVER = 15;
		static const auto CONTEXT_EMPTYSERVER = 16;
		static const auto CONTEXT_DEDICATEDSERVER = 17;
		static const auto CONTEXT_MAPNAME_CUSTOM = 0;
		static const auto CONTEXT_BOTSKILL_NOVICE = 0;
		static const auto CONTEXT_BOTSKILL_AVERAGE = 1;
		static const auto CONTEXT_BOTSKILL_EXPERIENCED = 2;
		static const auto CONTEXT_BOTSKILL_SKILLED = 3;
		static const auto CONTEXT_BOTSKILL_ADEPT = 4;
		static const auto CONTEXT_BOTSKILL_MASTERFUL = 5;
		static const auto CONTEXT_BOTSKILL_INHUMAN = 6;
		static const auto CONTEXT_BOTSKILL_GODLIKE = 7;
		static const auto CONTEXT_GOALSCORE = 0;
		static const auto CONTEXT_GOALSCORE = 1;
		static const auto CONTEXT_GOALSCORE = 2;
		static const auto CONTEXT_GOALSCORE = 3;
		static const auto CONTEXT_GOALSCORE = 4;
		static const auto CONTEXT_NUMBOTS = 0;
		static const auto CONTEXT_NUMBOTS = 1;
		static const auto CONTEXT_NUMBOTS = 2;
		static const auto CONTEXT_NUMBOTS = 3;
		static const auto CONTEXT_NUMBOTS = 4;
		static const auto CONTEXT_NUMBOTS = 5;
		static const auto CONTEXT_NUMBOTS = 6;
		static const auto CONTEXT_NUMBOTS = 7;
		static const auto CONTEXT_NUMBOTS = 8;
		static const auto CONTEXT_TIMELIMIT = 0;
		static const auto CONTEXT_TIMELIMIT = 1;
		static const auto CONTEXT_TIMELIMIT = 2;
		static const auto CONTEXT_TIMELIMIT = 3;
		static const auto CONTEXT_TIMELIMIT = 4;
		static const auto CONTEXT_PURESERVER_NO = 0;
		static const auto CONTEXT_PURESERVER_YES = 1;
		static const auto CONTEXT_PURESERVER_ANY = 2;
		static const auto CONTEXT_LOCKEDSERVER_NO = 0;
		static const auto CONTEXT_LOCKEDSERVER_YES = 1;
		static const auto CONTEXT_CAMPAIGN_NO = 0;
		static const auto CONTEXT_CAMPAIGN_YES = 1;
		static const auto CONTEXT_FORCERESPAWN_NO = 0;
		static const auto CONTEXT_FORCERESPAWN_YES = 1;
		static const auto CONTEXT_ALLOWKEYBOARD_NO = 0;
		static const auto CONTEXT_ALLOWKEYBOARD_YES = 1;
		static const auto CONTEXT_ALLOWKEYBOARD_ANY = 2;
		static const auto CONTEXT_FULLSERVER_NO = 0;
		static const auto CONTEXT_FULLSERVER_YES = 1;
		static const auto CONTEXT_EMPTYSERVER_NO = 0;
		static const auto CONTEXT_EMPTYSERVER_YES = 1;
		static const auto CONTEXT_DEDICATEDSERVER_NO = 0;
		static const auto CONTEXT_DEDICATEDSERVER_YES = 1;
		static const auto CONTEXT_VSBOTS_NONE = 0;
		static const auto CONTEXT_VSBOTS_1_TO = 1;
		static const auto CONTEXT_VSBOTS_1_TO = 2;
		static const auto CONTEXT_VSBOTS_3_TO = 3;
		static const auto CONTEXT_VSBOTS_2_TO = 4;
		static const auto CONTEXT_VSBOTS_3_TO = 5;
		static const auto CONTEXT_VSBOTS_4_TO = 6;
		static const auto PROPERTY_NUMBOTS = 0x100000F7;
		static const auto PROPERTY_TIMELIMIT = 0x1000000A;
		static const auto PROPERTY_GOALSCORE = 0x1000000B;
		static const auto PROPERTY_LEADERBOARDRATING = 0x20000004;
		static const auto PROPERTY_EPICMUTATORS = 0x10000105;
		static const auto PROPERTY_CUSTOMMAPNAME = 0x40000001;
		static const auto PROPERTY_CUSTOMGAMEMODE = 0x40000002;
		static const auto PROPERTY_SERVERDESCRIPTION = 0x40000003;
		static const auto PROPERTY_CUSTOMMUTATORS = 0x40000004;
		static const auto QUERY_DM = 0;
		static const auto QUERY_TDM = 1;
		static const auto QUERY_CTF = 2;
		static const auto QUERY_VCTF = 3;
		static const auto QUERY_WAR = 4;
		static const auto QUERY_DUEL = 5;
		static const auto QUERY_CAMPAIGN = 6;
		static const auto STATS_VIEW_DM_PLAYER_ALLTIME = 1;
		static const auto STATS_VIEW_DM_RANKED_ALLTIME = 2;
		static const auto STATS_VIEW_DM_WEAPONS_ALLTIME = 3;
		static const auto STATS_VIEW_DM_VEHICLES_ALLTIME = 4;
		static const auto STATS_VIEW_DM_VEHICLEWEAPONS_ALLTIME = 5;
		static const auto STATS_VIEW_DM_VEHICLES_RANKED_ALLTIME = 6;
		static const auto STATS_VIEW_DM_VEHICLEWEAPONS_RANKED_ALLTIME = 7;
		static const auto STATS_VIEW_DM_WEAPONS_RANKED_ALLTIME = 8;
		ADD_STRUCT(int, MaxPlayers, 172)
		ADD_STRUCT(int, MinNetPlayers, 176)
		void SetCustomMapName(ScriptString* MapName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameSettingsCommon.SetCustomMapName");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = MapName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetOfficialMutatorBitmask(int MutatorBitmask)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameSettingsCommon.SetOfficialMutatorBitmask");
			byte params[4] = { NULL };
			*(int*)&params[0] = MutatorBitmask;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BuildURL(ScriptString*& OutURL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameSettingsCommon.BuildURL");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = OutURL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutURL = *(ScriptString**)&params[0];
		}
		void UpdateFromURL(ScriptString*& URL, class GameInfo* Game)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameSettingsCommon.UpdateFromURL");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = URL;
			*(class GameInfo**)&params[12] = Game;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			URL = *(ScriptString**)&params[0];
		}
		void SetMutators(ScriptString*& URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameSettingsCommon.SetMutators");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			URL = *(ScriptString**)&params[0];
		}
		int GenerateMutatorBitmaskFromURL(class UTUIDataStore_MenuItems* MenuDataStore, ScriptArray<ScriptString*>& MutatorClassNames)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameSettingsCommon.GenerateMutatorBitmaskFromURL");
			byte params[20] = { NULL };
			*(class UTUIDataStore_MenuItems**)&params[0] = MenuDataStore;
			*(ScriptArray<ScriptString*>*)&params[4] = MutatorClassNames;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			MutatorClassNames = *(ScriptArray<ScriptString*>*)&params[4];
			return *(int*)&params[16];
		}
		void SetCustomMutators(class UTUIDataStore_MenuItems* MenuDataStore, ScriptArray<ScriptString*>& MutatorClassNames)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTGameSettingsCommon.SetCustomMutators");
			byte params[16] = { NULL };
			*(class UTUIDataStore_MenuItems**)&params[0] = MenuDataStore;
			*(ScriptArray<ScriptString*>*)&params[4] = MutatorClassNames;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			MutatorClassNames = *(ScriptArray<ScriptString*>*)&params[4];
		}
	};
}
#undef ADD_STRUCT
