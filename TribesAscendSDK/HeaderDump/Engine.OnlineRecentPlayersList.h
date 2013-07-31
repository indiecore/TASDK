#pragma once
#include "Core.Object.h"
#include "Engine.OnlineSubsystem.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class OnlineRecentPlayersList : public Object
	{
	public:
		struct RecentParty
		{
		public:
			ADD_STRUCT(ScriptArray<OnlineSubsystem::UniqueNetId>, PartyMembers, 8)
			ADD_STRUCT(OnlineSubsystem::UniqueNetId, PartyLeader, 0)
		};
		struct CurrentPlayerMet
		{
		public:
			ADD_STRUCT(OnlineSubsystem::UniqueNetId, NetId, 8)
			ADD_STRUCT(int, Skill, 4)
			ADD_STRUCT(int, TeamNum, 0)
		};
		ADD_STRUCT(ScriptArray<OnlineSubsystem::UniqueNetId>, RecentPlayers, 60)
		ADD_STRUCT(ScriptArray<OnlineRecentPlayersList::RecentParty>, RecentParties, 72)
		ADD_STRUCT(ScriptArray<OnlineRecentPlayersList::CurrentPlayerMet>, CurrentPlayers, 120)
		ADD_STRUCT(int, RecentPartiesAddIndex, 116)
		ADD_STRUCT(int, RecentPlayersAddIndex, 112)
		ADD_STRUCT(int, MaxRecentParties, 108)
		ADD_STRUCT(int, MaxRecentPlayers, 104)
		ADD_STRUCT(OnlineRecentPlayersList::RecentParty, LastParty, 84)
		void AddPlayerToRecentPlayers(OnlineSubsystem::UniqueNetId NewPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22681);
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = NewPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearRecentPlayers()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22684);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddPartyToRecentParties(OnlineSubsystem::UniqueNetId PartyLeader, ScriptArray<OnlineSubsystem::UniqueNetId>& PartyMembers)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22685);
			byte params[20] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PartyLeader;
			*(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[8] = PartyMembers;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PartyMembers = *(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[8];
		}
		void ClearRecentParties()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22690);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetPlayersFromRecentParties(ScriptArray<OnlineSubsystem::UniqueNetId>& Players)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22691);
			byte params[12] = { NULL };
			*(ScriptArray<OnlineSubsystem::UniqueNetId>*)params = Players;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Players = *(ScriptArray<OnlineSubsystem::UniqueNetId>*)params;
		}
		void GetPlayersFromCurrentPlayers(ScriptArray<OnlineSubsystem::UniqueNetId>& Players)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22697);
			byte params[12] = { NULL };
			*(ScriptArray<OnlineSubsystem::UniqueNetId>*)params = Players;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Players = *(ScriptArray<OnlineSubsystem::UniqueNetId>*)params;
		}
		int GetSkillForCurrentPlayer(OnlineSubsystem::UniqueNetId Player)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22701);
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = Player;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int GetTeamForCurrentPlayer(OnlineSubsystem::UniqueNetId Player)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22705);
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = Player;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void SetLastParty(OnlineSubsystem::UniqueNetId PartyLeader, ScriptArray<OnlineSubsystem::UniqueNetId>& PartyMembers)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22709);
			byte params[20] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PartyLeader;
			*(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[8] = PartyMembers;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PartyMembers = *(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[8];
		}
		bool ShowRecentPlayerList(byte LocalUserNum, ScriptString* Title, ScriptString* Description)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22713);
			byte params[29] = { NULL };
			*params = LocalUserNum;
			*(ScriptString**)&params[4] = Title;
			*(ScriptString**)&params[16] = Description;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		bool ShowRecentPartiesPlayerList(byte LocalUserNum, ScriptString* Title, ScriptString* Description)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22719);
			byte params[29] = { NULL };
			*params = LocalUserNum;
			*(ScriptString**)&params[4] = Title;
			*(ScriptString**)&params[16] = Description;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		bool ShowLastPartyPlayerList(byte LocalUserNum, ScriptString* Title, ScriptString* Description)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22727);
			byte params[29] = { NULL };
			*params = LocalUserNum;
			*(ScriptString**)&params[4] = Title;
			*(ScriptString**)&params[16] = Description;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		bool ShowCurrentPlayersList(byte LocalUserNum, ScriptString* Title, ScriptString* Description)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22733);
			byte params[29] = { NULL };
			*params = LocalUserNum;
			*(ScriptString**)&params[4] = Title;
			*(ScriptString**)&params[16] = Description;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		void SetCurrentPlayersList(ScriptArray<OnlineRecentPlayersList::CurrentPlayerMet> Players)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22741);
			byte params[12] = { NULL };
			*(ScriptArray<OnlineRecentPlayersList::CurrentPlayerMet>*)params = Players;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetCurrentPlayersListCount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22744);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
#undef ADD_STRUCT
