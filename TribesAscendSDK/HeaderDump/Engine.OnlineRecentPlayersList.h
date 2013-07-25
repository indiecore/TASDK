#pragma once
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.OnlineRecentPlayersList." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.OnlineRecentPlayersList." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlineRecentPlayersList : public Object
	{
	public:
		ADD_VAR(::IntProperty, RecentPartiesAddIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RecentPlayersAddIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxRecentParties, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxRecentPlayers, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineRecentPlayersList.RecentParty' for the property named 'LastParty'!
		void AddPlayerToRecentPlayers(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* NewPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineRecentPlayersList.AddPlayerToRecentPlayers");
			byte* params = (byte*)malloc(8);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = NewPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearRecentPlayers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineRecentPlayersList.ClearRecentPlayers");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddPartyToRecentParties(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PartyLeader, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& PartyMembers)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineRecentPlayersList.AddPartyToRecentParties");
			byte* params = (byte*)malloc(20);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = PartyLeader;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = PartyMembers;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			PartyMembers = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8);
			free(params);
		}
		void ClearRecentParties()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineRecentPlayersList.ClearRecentParties");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetPlayersFromRecentParties(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Players)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineRecentPlayersList.GetPlayersFromRecentParties");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = Players;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Players = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		void GetPlayersFromCurrentPlayers(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Players)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineRecentPlayersList.GetPlayersFromCurrentPlayers");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = Players;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Players = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		int GetSkillForCurrentPlayer(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* Player)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineRecentPlayersList.GetSkillForCurrentPlayer");
			byte* params = (byte*)malloc(12);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = Player;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int GetTeamForCurrentPlayer(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* Player)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineRecentPlayersList.GetTeamForCurrentPlayer");
			byte* params = (byte*)malloc(12);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = Player;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		void SetLastParty(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PartyLeader, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& PartyMembers)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineRecentPlayersList.SetLastParty");
			byte* params = (byte*)malloc(20);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = PartyLeader;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = PartyMembers;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			PartyMembers = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8);
			free(params);
		}
		bool ShowRecentPlayerList(byte LocalUserNum, ScriptArray<wchar_t> Title, ScriptArray<wchar_t> Description)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineRecentPlayersList.ShowRecentPlayerList");
			byte* params = (byte*)malloc(29);
			*params = LocalUserNum;
			*(ScriptArray<wchar_t>*)(params + 4) = Title;
			*(ScriptArray<wchar_t>*)(params + 16) = Description;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		bool ShowRecentPartiesPlayerList(byte LocalUserNum, ScriptArray<wchar_t> Title, ScriptArray<wchar_t> Description)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineRecentPlayersList.ShowRecentPartiesPlayerList");
			byte* params = (byte*)malloc(29);
			*params = LocalUserNum;
			*(ScriptArray<wchar_t>*)(params + 4) = Title;
			*(ScriptArray<wchar_t>*)(params + 16) = Description;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		bool ShowLastPartyPlayerList(byte LocalUserNum, ScriptArray<wchar_t> Title, ScriptArray<wchar_t> Description)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineRecentPlayersList.ShowLastPartyPlayerList");
			byte* params = (byte*)malloc(29);
			*params = LocalUserNum;
			*(ScriptArray<wchar_t>*)(params + 4) = Title;
			*(ScriptArray<wchar_t>*)(params + 16) = Description;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		bool ShowCurrentPlayersList(byte LocalUserNum, ScriptArray<wchar_t> Title, ScriptArray<wchar_t> Description)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineRecentPlayersList.ShowCurrentPlayersList");
			byte* params = (byte*)malloc(29);
			*params = LocalUserNum;
			*(ScriptArray<wchar_t>*)(params + 4) = Title;
			*(ScriptArray<wchar_t>*)(params + 16) = Description;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		void SetCurrentPlayersList(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* Players)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineRecentPlayersList.SetCurrentPlayersList");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = Players;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetCurrentPlayersListCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineRecentPlayersList.GetCurrentPlayersListCount");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
