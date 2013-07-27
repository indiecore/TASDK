#pragma once
#include "Core.Object.h"
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
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class PartyBeacon : public Object
	{
	public:
		enum EReservationPacketType : byte
		{
			RPT_UnknownPacketType = 0,
			RPT_ClientReservationRequest = 1,
			RPT_ClientReservationUpdateRequest = 2,
			RPT_ClientCancellationRequest = 3,
			RPT_HostReservationResponse = 4,
			RPT_HostReservationCountUpdate = 5,
			RPT_HostTravelRequest = 6,
			RPT_HostIsReady = 7,
			RPT_HostHasCancelled = 8,
			RPT_Heartbeat = 9,
			RPT_MAX = 10,
		};
		enum EPartyReservationResult : byte
		{
			PRR_GeneralError = 0,
			PRR_PartyLimitReached = 1,
			PRR_IncorrectPlayerCount = 2,
			PRR_RequestTimedOut = 3,
			PRR_ReservationDuplicate = 4,
			PRR_ReservationNotFound = 5,
			PRR_ReservationAccepted = 6,
			PRR_ReservationDenied = 7,
			PRR_MAX = 8,
		};
		struct PlayerReservation
		{
		public:
			ADD_STRUCT(float, ElapsedSessionTime, 32)
			ADD_STRUCT(Object::Double, Sigma, 24)
			ADD_STRUCT(Object::Double, Mu, 16)
			ADD_STRUCT(int, XpLevel, 12)
			ADD_STRUCT(int, Skill, 8)
			ADD_STRUCT(OnlineSubsystem::UniqueNetId, NetId, 0)
		};
		struct PartyReservation
		{
		public:
			ADD_STRUCT(ScriptArray<PartyBeacon::PlayerReservation>, PartyMembers, 12)
			ADD_STRUCT(OnlineSubsystem::UniqueNetId, PartyLeader, 4)
			ADD_STRUCT(int, TeamNum, 0)
		};
		ADD_STRUCT(ScriptName, BeaconName, 84)
		ADD_STRUCT(float, ElapsedHeartbeatTime, 80)
		ADD_STRUCT(float, HeartbeatTimeout, 76)
		ADD_BOOL(bShouldTick, 72, 0x4)
		ADD_BOOL(bWantsDeferredDestroy, 72, 0x2)
		ADD_BOOL(bIsInTick, 72, 0x1)
		ADD_STRUCT(Object::Pointer, Socket, 68)
		ADD_STRUCT(int, PartyBeaconPort, 64)
		ADD_STRUCT(Object::Pointer, VfTable_FTickableObject, 60)
		void OnDestroyComplete()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33885);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DestroyBeacon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33909);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
