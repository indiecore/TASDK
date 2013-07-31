#pragma once
#include "IpDrv.PartyBeacon.h"
#include "IpDrv.ClientBeaconAddressResolver.h"
#include "Engine.OnlineGameSearch.h"
#include "Engine.OnlineSubsystem.h"
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
	class PartyBeaconClient : public PartyBeacon
	{
	public:
		enum EPartyBeaconClientRequest : byte
		{
			PBClientRequest_NewReservation = 0,
			PBClientRequest_UpdateReservation = 1,
			PBClientRequest_MAX = 2,
		};
		enum EPartyBeaconClientState : byte
		{
			PBCS_None = 0,
			PBCS_Connecting = 1,
			PBCS_Connected = 2,
			PBCS_ConnectionFailed = 3,
			PBCS_AwaitingResponse = 4,
			PBCS_Closed = 5,
			PBCS_MAX = 6,
		};
		ADD_OBJECT(ClientBeaconAddressResolver, Resolver, 164)
		ADD_OBJECT(ScriptClass, ResolverClass, 160)
		ADD_STRUCT(ScriptString*, ResolverClassName, 148)
		ADD_STRUCT(float, ReservationRequestElapsedTime, 144)
		ADD_STRUCT(float, ReservationRequestTimeout, 140)
		ADD_STRUCT(PartyBeaconClient::EPartyBeaconClientRequest, ClientBeaconRequestType, 137)
		ADD_STRUCT(PartyBeaconClient::EPartyBeaconClientState, ClientBeaconState, 136)
		ADD_STRUCT(OnlineGameSearch::OnlineGameSearchResult, HostPendingRequest, 104)
		ADD_STRUCT(PartyBeacon::PartyReservation, PendingRequest, 112)
		void OnHostHasCancelled()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33911);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnHostIsReady()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33913);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTravelRequestReceived(ScriptName SessionName, ScriptClass* SearchClass, byte PlatformSpecificInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33915);
			byte params[13] = { NULL };
			*(ScriptName*)params = SessionName;
			*(ScriptClass**)&params[8] = SearchClass;
			params[12] = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReservationCountUpdated(int ReservationRemaining)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33917);
			byte params[4] = { NULL };
			*(int*)params = ReservationRemaining;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReservationRequestComplete(PartyBeacon::EPartyReservationResult ReservationResult)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33919);
			byte params[1] = { NULL };
			*(PartyBeacon::EPartyReservationResult*)params = ReservationResult;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool RequestReservation(OnlineGameSearch::OnlineGameSearchResult& DesiredHost, OnlineSubsystem::UniqueNetId RequestingPartyLeader, ScriptArray<PartyBeacon::PlayerReservation>& Players)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33936);
			byte params[32] = { NULL };
			*(OnlineGameSearch::OnlineGameSearchResult*)params = DesiredHost;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = RequestingPartyLeader;
			*(ScriptArray<PartyBeacon::PlayerReservation>*)&params[16] = Players;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DesiredHost = *(OnlineGameSearch::OnlineGameSearchResult*)params;
			Players = *(ScriptArray<PartyBeacon::PlayerReservation>*)&params[16];
			return *(bool*)&params[28];
		}
		bool RequestReservationUpdate(OnlineGameSearch::OnlineGameSearchResult& DesiredHost, OnlineSubsystem::UniqueNetId RequestingPartyLeader, ScriptArray<PartyBeacon::PlayerReservation>& PlayersToAdd)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33942);
			byte params[32] = { NULL };
			*(OnlineGameSearch::OnlineGameSearchResult*)params = DesiredHost;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = RequestingPartyLeader;
			*(ScriptArray<PartyBeacon::PlayerReservation>*)&params[16] = PlayersToAdd;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DesiredHost = *(OnlineGameSearch::OnlineGameSearchResult*)params;
			PlayersToAdd = *(ScriptArray<PartyBeacon::PlayerReservation>*)&params[16];
			return *(bool*)&params[28];
		}
		bool CancelReservation(OnlineSubsystem::UniqueNetId CancellingPartyLeader)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33948);
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = CancellingPartyLeader;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void DestroyBeacon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33951);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
