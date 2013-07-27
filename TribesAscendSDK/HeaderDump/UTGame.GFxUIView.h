#pragma once
#include "GFxUI.GFxObject.h"
#include "UDKBase.UDKPlayerController.h"
#include "Engine.LocalPlayer.h"
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
namespace UnrealScript
{
	class GFxUIView : public GFxObject
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
		ADD_BOOL(bRequiresNetwork, 120, 0x1)
		bool HasLinkConnection()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIView.HasLinkConnection");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		class LocalPlayer* GetPlayerOwner(int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIView.GetPlayerOwner");
			byte params[8] = { NULL };
			*(int*)&params[0] = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class LocalPlayer**)&params[4];
		}
		class UDKPlayerController* GetUDKPlayerOwner(int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIView.GetUDKPlayerOwner");
			byte params[8] = { NULL };
			*(int*)&params[0] = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UDKPlayerController**)&params[4];
		}
		ScriptString* GetPlayerName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIView.GetPlayerName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		bool IsLoggedIn(int ControllerId, bool bRequireOnlineLogin)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIView.IsLoggedIn");
			byte params[12] = { NULL };
			*(int*)&params[0] = ControllerId;
			*(bool*)&params[4] = bRequireOnlineLogin;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		ScriptString* GetCommonOptionsURL()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIView.GetCommonOptionsURL");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		int GetPlayerIndex()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIView.GetPlayerIndex");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		int GetPlayerControllerId(int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIView.GetPlayerControllerId");
			byte params[8] = { NULL };
			*(int*)&params[0] = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void ConsoleCommand(ScriptString* Cmd, bool bWriteToLog)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUIView.ConsoleCommand");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Cmd;
			*(bool*)&params[12] = bWriteToLog;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
