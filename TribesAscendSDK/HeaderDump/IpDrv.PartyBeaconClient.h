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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconClient.OnHostHasCancelled");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnHostIsReady()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconClient.OnHostIsReady");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTravelRequestReceived(ScriptName SessionName, ScriptClass* SearchClass, byte PlatformSpecificInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconClient.OnTravelRequestReceived");
			byte params[13] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(ScriptClass**)&params[8] = SearchClass;
			params[12] = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReservationCountUpdated(int ReservationRemaining)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconClient.OnReservationCountUpdated");
			byte params[4] = { NULL };
			*(int*)&params[0] = ReservationRemaining;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReservationRequestComplete(PartyBeacon::EPartyReservationResult ReservationResult)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconClient.OnReservationRequestComplete");
			byte params[1] = { NULL };
			*(PartyBeacon::EPartyReservationResult*)&params[0] = ReservationResult;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool RequestReservation(OnlineGameSearch::OnlineGameSearchResult& DesiredHost, OnlineSubsystem::UniqueNetId RequestingPartyLeader, ScriptArray<PartyBeacon::PlayerReservation>& Players)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconClient.RequestReservation");
			byte params[32] = { NULL };
			*(OnlineGameSearch::OnlineGameSearchResult*)&params[0] = DesiredHost;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = RequestingPartyLeader;
			*(ScriptArray<PartyBeacon::PlayerReservation>*)&params[16] = Players;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DesiredHost = *(OnlineGameSearch::OnlineGameSearchResult*)&params[0];
			Players = *(ScriptArray<PartyBeacon::PlayerReservation>*)&params[16];
			return *(bool*)&params[28];
		}
		bool RequestReservationUpdate(OnlineGameSearch::OnlineGameSearchResult& DesiredHost, OnlineSubsystem::UniqueNetId RequestingPartyLeader, ScriptArray<PartyBeacon::PlayerReservation>& PlayersToAdd)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconClient.RequestReservationUpdate");
			byte params[32] = { NULL };
			*(OnlineGameSearch::OnlineGameSearchResult*)&params[0] = DesiredHost;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = RequestingPartyLeader;
			*(ScriptArray<PartyBeacon::PlayerReservation>*)&params[16] = PlayersToAdd;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DesiredHost = *(OnlineGameSearch::OnlineGameSearchResult*)&params[0];
			PlayersToAdd = *(ScriptArray<PartyBeacon::PlayerReservation>*)&params[16];
			return *(bool*)&params[28];
		}
		bool CancelReservation(OnlineSubsystem::UniqueNetId CancellingPartyLeader)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconClient.CancelReservation");
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = CancellingPartyLeader;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void DestroyBeacon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconClient.DestroyBeacon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
