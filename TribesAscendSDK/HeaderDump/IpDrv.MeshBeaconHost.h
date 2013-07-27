#pragma once
#include "Engine.OnlineSubsystem.h"
#include "IpDrv.MeshBeacon.h"
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
	class MeshBeaconHost : public MeshBeacon
	{
	public:
		class ClientConnectionBandwidthTestData
		{
		public:
			ADD_STRUCT(MeshBeacon::ConnectionBandwidthStats, BandwidthStats, 28)
			ADD_STRUCT(Object::Double, TestStartTime, 20)
			ADD_STRUCT(Object::Double, RequestTestStartTime, 12)
			ADD_STRUCT(int, BytesReceived, 8)
			ADD_STRUCT(int, BytesTotalNeeded, 4)
			ADD_STRUCT(MeshBeacon::EMeshBeaconBandwidthTestType, TestType, 1)
			ADD_STRUCT(MeshBeacon::EMeshBeaconBandwidthTestState, CurrentState, 0)
		};
		class ClientMeshBeaconConnection
		{
		public:
			ADD_STRUCT(ScriptArray<MeshBeacon::ConnectionBandwidthStats>, BandwidthHistory, 72)
			ADD_STRUCT(int, MinutesSinceLastTest, 84)
			ADD_STRUCT(float, GoodHostRatio, 68)
			ADD_BOOL(bCanHostVs, 64, 0x1)
			ADD_STRUCT(OnlineSubsystem::ENATType, NatType, 60)
			ADD_STRUCT(MeshBeaconHost::ClientConnectionBandwidthTestData, BandwidthTest, 20)
			ADD_BOOL(bConnectionAccepted, 16, 0x1)
			ADD_STRUCT(Object::Pointer, Socket, 12)
			ADD_STRUCT(float, ElapsedHeartbeatTime, 8)
			ADD_STRUCT(OnlineSubsystem::UniqueNetId, PlayerNetId, 0)
		};
		ADD_STRUCT(ScriptArray<MeshBeaconHost::ClientMeshBeaconConnection>, ClientConnections, 120)
		ADD_STRUCT(ScriptArray<OnlineSubsystem::UniqueNetId>, PendingPlayerConnections, 132)
		ADD_STRUCT(int, ConnectionBacklog, 156)
		ADD_BOOL(bAllowBandwidthTesting, 152, 0x1)
		ADD_STRUCT(OnlineSubsystem::UniqueNetId, OwningPlayerId, 144)
		void OnReceivedClientCreateNewSessionResult(bool bSucceeded, ScriptName SessionName, ScriptClass* SearchClass, byte& PlatformSpecificInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.OnReceivedClientCreateNewSessionResult");
			byte params[17] = { NULL };
			*(bool*)&params[0] = bSucceeded;
			*(ScriptName*)&params[4] = SessionName;
			*(ScriptClass**)&params[12] = SearchClass;
			params[16] = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PlatformSpecificInfo = params[16];
		}
		void OnAllPendingPlayersConnected()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.OnAllPendingPlayersConnected");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnFinishedBandwidthTest(OnlineSubsystem::UniqueNetId PlayerNetId, MeshBeacon::EMeshBeaconBandwidthTestType TestType, MeshBeacon::EMeshBeaconBandwidthTestResult TestResult, MeshBeacon::ConnectionBandwidthStats& BandwidthStats)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.OnFinishedBandwidthTest");
			byte params[22] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PlayerNetId;
			*(MeshBeacon::EMeshBeaconBandwidthTestType*)&params[8] = TestType;
			*(MeshBeacon::EMeshBeaconBandwidthTestResult*)&params[9] = TestResult;
			*(MeshBeacon::ConnectionBandwidthStats*)&params[12] = BandwidthStats;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			BandwidthStats = *(MeshBeacon::ConnectionBandwidthStats*)&params[12];
		}
		void OnStartedBandwidthTest(OnlineSubsystem::UniqueNetId PlayerNetId, MeshBeacon::EMeshBeaconBandwidthTestType TestType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.OnStartedBandwidthTest");
			byte params[9] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PlayerNetId;
			*(MeshBeacon::EMeshBeaconBandwidthTestType*)&params[8] = TestType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReceivedClientConnectionRequest(MeshBeaconHost::ClientMeshBeaconConnection& NewClientConnection)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.OnReceivedClientConnectionRequest");
			byte params[88] = { NULL };
			*(MeshBeaconHost::ClientMeshBeaconConnection*)&params[0] = NewClientConnection;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			NewClientConnection = *(MeshBeaconHost::ClientMeshBeaconConnection*)&params[0];
		}
		bool InitHostBeacon(OnlineSubsystem::UniqueNetId InOwningPlayerId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.InitHostBeacon");
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = InOwningPlayerId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void DestroyBeacon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.DestroyBeacon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool RequestClientBandwidthTest(OnlineSubsystem::UniqueNetId PlayerNetId, MeshBeacon::EMeshBeaconBandwidthTestType TestType, int TestBufferSize)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.RequestClientBandwidthTest");
			byte params[17] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PlayerNetId;
			*(MeshBeacon::EMeshBeaconBandwidthTestType*)&params[8] = TestType;
			*(int*)&params[12] = TestBufferSize;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool HasInProgressBandwidthTest()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.HasInProgressBandwidthTest");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void CancelInProgressBandwidthTests()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.CancelInProgressBandwidthTests");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool HasPendingBandwidthTest()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.HasPendingBandwidthTest");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void CancelPendingBandwidthTests()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.CancelPendingBandwidthTests");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AllowBandwidthTesting(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.AllowBandwidthTesting");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPendingPlayerConnections(ScriptArray<OnlineSubsystem::UniqueNetId>& Players)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.SetPendingPlayerConnections");
			byte params[12] = { NULL };
			*(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[0] = Players;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Players = *(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[0];
		}
		int GetConnectionIndexForPlayer(OnlineSubsystem::UniqueNetId PlayerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.GetConnectionIndexForPlayer");
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PlayerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		bool AllPlayersConnected(ScriptArray<OnlineSubsystem::UniqueNetId>& Players)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.AllPlayersConnected");
			byte params[16] = { NULL };
			*(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[0] = Players;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Players = *(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[0];
			return *(bool*)&params[12];
		}
		void TellClientsToTravel(ScriptName SessionName, ScriptClass* SearchClass, byte& PlatformSpecificInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.TellClientsToTravel");
			byte params[13] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(ScriptClass**)&params[8] = SearchClass;
			params[12] = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PlatformSpecificInfo = params[12];
		}
		bool RequestClientCreateNewSession(OnlineSubsystem::UniqueNetId PlayerNetId, ScriptName SessionName, ScriptClass* SearchClass, ScriptArray<MeshBeacon::PlayerMember>& Players)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.RequestClientCreateNewSession");
			byte params[36] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PlayerNetId;
			*(ScriptName*)&params[8] = SessionName;
			*(ScriptClass**)&params[16] = SearchClass;
			*(ScriptArray<MeshBeacon::PlayerMember>*)&params[20] = Players;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Players = *(ScriptArray<MeshBeacon::PlayerMember>*)&params[20];
			return *(bool*)&params[32];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
