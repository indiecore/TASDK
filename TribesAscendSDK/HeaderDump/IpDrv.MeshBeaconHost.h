#pragma once
#include "IpDrv.MeshBeacon.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#include "IpDrv.MeshBeacon.ConnectionBandwidthStats.h"
#include "IpDrv.MeshBeaconHost.ClientMeshBeaconConnection.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.MeshBeaconHost." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty IpDrv.MeshBeaconHost." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MeshBeaconHost : public MeshBeacon
	{
	public:
		ADD_VAR(::IntProperty, ConnectionBacklog, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAllowBandwidthTesting, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<UniqueNetId>, OwningPlayerId, 0xFFFFFFFF)
		void OnReceivedClientCreateNewSessionResult(bool bSucceeded, ScriptName SessionName, ScriptClass* SearchClass, byte& PlatformSpecificInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.OnReceivedClientCreateNewSessionResult");
			byte* params = (byte*)malloc(17);
			*(bool*)params = bSucceeded;
			*(ScriptName*)(params + 4) = SessionName;
			*(ScriptClass**)(params + 12) = SearchClass;
			*(params + 16) = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			PlatformSpecificInfo = *(params + 16);
			free(params);
		}
		void OnAllPendingPlayersConnected()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.OnAllPendingPlayersConnected");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnFinishedBandwidthTest(UniqueNetId PlayerNetId, byte TestType, byte TestResult, ConnectionBandwidthStats& BandwidthStats)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.OnFinishedBandwidthTest");
			byte* params = (byte*)malloc(22);
			*(UniqueNetId*)params = PlayerNetId;
			*(params + 8) = TestType;
			*(params + 9) = TestResult;
			*(ConnectionBandwidthStats*)(params + 12) = BandwidthStats;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			BandwidthStats = *(ConnectionBandwidthStats*)(params + 12);
			free(params);
		}
		void OnStartedBandwidthTest(UniqueNetId PlayerNetId, byte TestType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.OnStartedBandwidthTest");
			byte* params = (byte*)malloc(9);
			*(UniqueNetId*)params = PlayerNetId;
			*(params + 8) = TestType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnReceivedClientConnectionRequest(ClientMeshBeaconConnection& NewClientConnection)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.OnReceivedClientConnectionRequest");
			byte* params = (byte*)malloc(88);
			*(ClientMeshBeaconConnection*)params = NewClientConnection;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			NewClientConnection = *(ClientMeshBeaconConnection*)params;
			free(params);
		}
		bool InitHostBeacon(UniqueNetId InOwningPlayerId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.InitHostBeacon");
			byte* params = (byte*)malloc(12);
			*(UniqueNetId*)params = InOwningPlayerId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void DestroyBeacon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.DestroyBeacon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool RequestClientBandwidthTest(UniqueNetId PlayerNetId, byte TestType, int TestBufferSize)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.RequestClientBandwidthTest");
			byte* params = (byte*)malloc(17);
			*(UniqueNetId*)params = PlayerNetId;
			*(params + 8) = TestType;
			*(int*)(params + 12) = TestBufferSize;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool HasInProgressBandwidthTest()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.HasInProgressBandwidthTest");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void CancelInProgressBandwidthTests()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.CancelInProgressBandwidthTests");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool HasPendingBandwidthTest()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.HasPendingBandwidthTest");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void CancelPendingBandwidthTests()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.CancelPendingBandwidthTests");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AllowBandwidthTesting(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.AllowBandwidthTesting");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPendingPlayerConnections(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Players)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.SetPendingPlayerConnections");
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
		int GetConnectionIndexForPlayer(UniqueNetId PlayerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.GetConnectionIndexForPlayer");
			byte* params = (byte*)malloc(12);
			*(UniqueNetId*)params = PlayerNetId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		bool AllPlayersConnected(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Players)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.AllPlayersConnected");
			byte* params = (byte*)malloc(16);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = Players;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Players = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void TellClientsToTravel(ScriptName SessionName, ScriptClass* SearchClass, byte& PlatformSpecificInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.TellClientsToTravel");
			byte* params = (byte*)malloc(13);
			*(ScriptName*)params = SessionName;
			*(ScriptClass**)(params + 8) = SearchClass;
			*(params + 12) = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			PlatformSpecificInfo = *(params + 12);
			free(params);
		}
		bool RequestClientCreateNewSession(UniqueNetId PlayerNetId, ScriptName SessionName, ScriptClass* SearchClass, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Players)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconHost.RequestClientCreateNewSession");
			byte* params = (byte*)malloc(36);
			*(UniqueNetId*)params = PlayerNetId;
			*(ScriptName*)(params + 8) = SessionName;
			*(ScriptClass**)(params + 16) = SearchClass;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 20) = Players;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Players = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 20);
			auto returnVal = *(bool*)(params + 32);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
