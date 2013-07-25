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
		// Here lies the not-yet-implemented method 'OnClientCancellationReceived'
		// Here lies the not-yet-implemented method 'OnReservationsFull'
		// Here lies the not-yet-implemented method 'OnReservationChange'
		// Here lies the not-yet-implemented method 'PauseReservationRequests'
		// Here lies the not-yet-implemented method 'InitHostBeacon'
		// Here lies the not-yet-implemented method 'AddPartyReservationEntry'
		// Here lies the not-yet-implemented method 'UpdatePartyReservationEntry'
		// Here lies the not-yet-implemented method 'GetExistingReservation'
		// Here lies the not-yet-implemented method 'HandlePlayerLogout'
		// Here lies the not-yet-implemented method 'DestroyBeacon'
		// Here lies the not-yet-implemented method 'TellClientsToTravel'
		// Here lies the not-yet-implemented method 'TellClientsHostIsReady'
		// Here lies the not-yet-implemented method 'TellClientsHostHasCancelled'
		// Here lies the not-yet-implemented method 'AreReservationsFull'
		// Here lies the not-yet-implemented method 'RegisterPartyMembers'
		// Here lies the not-yet-implemented method 'UnregisterPartyMembers'
		// Here lies the not-yet-implemented method 'UnregisterParty'
		// Here lies the not-yet-implemented method 'AppendReservationSkillsToSearch'
		// Here lies the not-yet-implemented method 'GetPlayers'
		// Here lies the not-yet-implemented method 'GetPartyLeaders'
		// Here lies the not-yet-implemented method 'GetMaxAvailableTeamSize'
	};
}
#undef ADD_VAR
