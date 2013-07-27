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
	class MeshBeacon : public Object
	{
	public:
		enum EMeshBeaconPacketType : byte
		{
			MB_Packet_UnknownType = 0,
			MB_Packet_ClientNewConnectionRequest = 1,
			MB_Packet_ClientBeginBandwidthTest = 2,
			MB_Packet_ClientCreateNewSessionResponse = 3,
			MB_Packet_HostNewConnectionResponse = 4,
			MB_Packet_HostBandwidthTestRequest = 5,
			MB_Packet_HostCompletedBandwidthTest = 6,
			MB_Packet_HostTravelRequest = 7,
			MB_Packet_HostCreateNewSessionRequest = 8,
			MB_Packet_DummyData = 9,
			MB_Packet_Heartbeat = 10,
			MB_Packet_MAX = 11,
		};
		enum EMeshBeaconConnectionResult : byte
		{
			MB_ConnectionResult_Succeeded = 0,
			MB_ConnectionResult_Duplicate = 1,
			MB_ConnectionResult_Timeout = 2,
			MB_ConnectionResult_Error = 3,
			MB_ConnectionResult_MAX = 4,
		};
		enum EMeshBeaconBandwidthTestState : byte
		{
			MB_BandwidthTestState_NotStarted = 0,
			MB_BandwidthTestState_RequestPending = 1,
			MB_BandwidthTestState_StartPending = 2,
			MB_BandwidthTestState_InProgress = 3,
			MB_BandwidthTestState_Completed = 4,
			MB_BandwidthTestState_Incomplete = 5,
			MB_BandwidthTestState_Timeout = 6,
			MB_BandwidthTestState_Error = 7,
			MB_BandwidthTestState_MAX = 8,
		};
		enum EMeshBeaconBandwidthTestResult : byte
		{
			MB_BandwidthTestResult_Succeeded = 0,
			MB_BandwidthTestResult_Timeout = 1,
			MB_BandwidthTestResult_Error = 2,
			MB_BandwidthTestResult_MAX = 3,
		};
		enum EMeshBeaconBandwidthTestType : byte
		{
			MB_BandwidthTestType_Upstream = 0,
			MB_BandwidthTestType_Downstream = 1,
			MB_BandwidthTestType_RoundtripLatency = 2,
			MB_BandwidthTestType_MAX = 3,
		};
		struct ConnectionBandwidthStats
		{
		public:
			ADD_STRUCT(int, RoundtripLatency, 8)
			ADD_STRUCT(int, DownstreamRate, 4)
			ADD_STRUCT(int, UpstreamRate, 0)
		};
		struct PlayerMember
		{
		public:
			ADD_STRUCT(OnlineSubsystem::UniqueNetId, NetId, 8)
			ADD_STRUCT(int, Skill, 4)
			ADD_STRUCT(int, TeamNum, 0)
		};
		ADD_STRUCT(int, MaxBandwidthHistoryEntries, 116)
		ADD_STRUCT(float, MaxBandwidthTestReceiveTime, 112)
		ADD_STRUCT(float, MaxBandwidthTestSendTime, 108)
		ADD_STRUCT(int, MinBandwidthTestBufferSize, 104)
		ADD_STRUCT(int, MaxBandwidthTestBufferSize, 100)
		ADD_STRUCT(int, SocketReceiveBufferSize, 96)
		ADD_STRUCT(int, SocketSendBufferSize, 92)
		ADD_STRUCT(ScriptName, BeaconName, 84)
		ADD_STRUCT(float, ElapsedHeartbeatTime, 80)
		ADD_STRUCT(float, HeartbeatTimeout, 76)
		ADD_BOOL(bShouldTick, 72, 0x4)
		ADD_BOOL(bWantsDeferredDestroy, 72, 0x2)
		ADD_BOOL(bIsInTick, 72, 0x1)
		ADD_STRUCT(Object::Pointer, Socket, 68)
		ADD_STRUCT(int, MeshBeaconPort, 64)
		ADD_STRUCT(Object::Pointer, VfTable_FTickableObject, 60)
		void DestroyBeacon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33192);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
