#pragma once
#include "IpDrv__PartyBeacon.h"
#include "Engine__OnlineGameSearch.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.PartyBeaconHost." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PartyBeaconHost : public PartyBeacon
	{
	public:
		ADD_VAR(::ByteProperty, BeaconState, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bBestFitTeamAssignment, 0x1)
		ADD_VAR(::IntProperty, ReservedHostTeamNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ForceTeamNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ConnectionBacklog, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, OnlineSessionName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumConsumedReservations, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumReservations, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumPlayersPerTeam, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumTeams, 0xFFFFFFFF)
		void OnClientCancellationReceived(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PartyLeader)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconHost.OnClientCancellationReceived");
			byte* params = (byte*)malloc(8);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = PartyLeader;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnReservationsFull()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconHost.OnReservationsFull");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnReservationChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconHost.OnReservationChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PauseReservationRequests(bool bPause)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconHost.PauseReservationRequests");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bPause;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool InitHostBeacon(int InNumTeams, int InNumPlayersPerTeam, int InNumReservations, ScriptName InSessionName, int InForceTeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconHost.InitHostBeacon");
			byte* params = (byte*)malloc(28);
			*(int*)params = InNumTeams;
			*(int*)(params + 4) = InNumPlayersPerTeam;
			*(int*)(params + 8) = InNumReservations;
			*(ScriptName*)(params + 12) = InSessionName;
			*(int*)(params + 20) = InForceTeamNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		byte AddPartyReservationEntry(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PartyLeader, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& PlayerMembers, int TeamNum, bool bIsHost)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconHost.AddPartyReservationEntry");
			byte* params = (byte*)malloc(29);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = PartyLeader;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = PlayerMembers;
			*(int*)(params + 20) = TeamNum;
			*(bool*)(params + 24) = bIsHost;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			PlayerMembers = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8);
			auto returnVal = *(params + 28);
			free(params);
			return returnVal;
		}
		byte UpdatePartyReservationEntry(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PartyLeader, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& PlayerMembers)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconHost.UpdatePartyReservationEntry");
			byte* params = (byte*)malloc(21);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = PartyLeader;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = PlayerMembers;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			PlayerMembers = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8);
			auto returnVal = *(params + 20);
			free(params);
			return returnVal;
		}
		int GetExistingReservation(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void*& PartyLeader)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconHost.GetExistingReservation");
			byte* params = (byte*)malloc(12);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = PartyLeader;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			PartyLeader = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params;
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		void HandlePlayerLogout(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID, bool bMaintainParty)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconHost.HandlePlayerLogout");
			byte* params = (byte*)malloc(12);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = PlayerID;
			*(bool*)(params + 8) = bMaintainParty;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DestroyBeacon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconHost.DestroyBeacon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TellClientsToTravel(ScriptName SessionName, ScriptClass* SearchClass, byte PlatformSpecificInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconHost.TellClientsToTravel");
			byte* params = (byte*)malloc(13);
			*(ScriptName*)params = SessionName;
			*(ScriptClass**)(params + 8) = SearchClass;
			*(params + 12) = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TellClientsHostIsReady()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconHost.TellClientsHostIsReady");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TellClientsHostHasCancelled()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconHost.TellClientsHostHasCancelled");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool AreReservationsFull()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconHost.AreReservationsFull");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void RegisterPartyMembers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconHost.RegisterPartyMembers");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UnregisterPartyMembers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconHost.UnregisterPartyMembers");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UnregisterParty(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PartyLeader)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconHost.UnregisterParty");
			byte* params = (byte*)malloc(8);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = PartyLeader;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AppendReservationSkillsToSearch(class OnlineGameSearch* Search)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconHost.AppendReservationSkillsToSearch");
			byte* params = (byte*)malloc(4);
			*(class OnlineGameSearch**)params = Search;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetPlayers(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Players)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconHost.GetPlayers");
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
		void GetPartyLeaders(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& PartyLeaders)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconHost.GetPartyLeaders");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = PartyLeaders;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			PartyLeaders = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		int GetMaxAvailableTeamSize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconHost.GetMaxAvailableTeamSize");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
