#pragma once
#include "IpDrv.MeshBeacon.h"
#include "IpDrv.ClientBeaconAddressResolver.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.MeshBeaconClient." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty IpDrv.MeshBeaconClient." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty IpDrv.MeshBeaconClient." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MeshBeaconClient : public MeshBeacon
	{
	public:
		ADD_VAR(::BoolProperty, bUsingRegisteredAddr, 0x1)
		ADD_OBJECT(ClientBeaconAddressResolver, Resolver)
		ADD_OBJECT(ScriptClass, ResolverClass)
		ADD_VAR(::StrProperty, ResolverClassName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ConnectionRequestElapsedTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ConnectionRequestTimeout, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ClientBeaconRequestType, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ClientBeaconState, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct IpDrv.MeshBeaconClient.ClientBandwidthTestData' for the property named 'CurrentBandwidthTest'!
		// WARNING: Unknown structure type 'ScriptStruct IpDrv.MeshBeaconClient.ClientConnectionRequest' for the property named 'ClientPendingRequest'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineGameSearch.OnlineGameSearchResult' for the property named 'HostPendingRequest'!
		void OnCreateNewSessionRequestReceived(ScriptName SessionName, ScriptClass* SearchClass, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Players)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconClient.OnCreateNewSessionRequestReceived");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = SessionName;
			*(ScriptClass**)(params + 8) = SearchClass;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12) = Players;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Players = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12);
			free(params);
		}
		void OnTravelRequestReceived(ScriptName SessionName, ScriptClass* SearchClass, byte& PlatformSpecificInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconClient.OnTravelRequestReceived");
			byte* params = (byte*)malloc(13);
			*(ScriptName*)params = SessionName;
			*(ScriptClass**)(params + 8) = SearchClass;
			*(params + 12) = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			PlatformSpecificInfo = *(params + 12);
			free(params);
		}
		void OnReceivedBandwidthTestResults(byte TestType, byte TestResult, 
// WARNING: Unknown structure type 'ScriptStruct IpDrv.MeshBeacon.ConnectionBandwidthStats'!
void*& BandwidthStats)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconClient.OnReceivedBandwidthTestResults");
			byte* params = (byte*)malloc(14);
			*params = TestType;
			*(params + 1) = TestResult;
			*(
// WARNING: Unknown structure type 'ScriptStruct IpDrv.MeshBeacon.ConnectionBandwidthStats'!
void**)(params + 4) = BandwidthStats;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			BandwidthStats = *(
// WARNING: Unknown structure type 'ScriptStruct IpDrv.MeshBeacon.ConnectionBandwidthStats'!
void**)(params + 4);
			free(params);
		}
		void OnReceivedBandwidthTestRequest(byte TestType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconClient.OnReceivedBandwidthTestRequest");
			byte* params = (byte*)malloc(1);
			*params = TestType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnConnectionRequestResult(byte ConnectionResult)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconClient.OnConnectionRequestResult");
			byte* params = (byte*)malloc(1);
			*params = ConnectionResult;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DestroyBeacon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconClient.DestroyBeacon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool RequestConnection(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineGameSearch.OnlineGameSearchResult'!
void*& DesiredHost, 
// WARNING: Unknown structure type 'ScriptStruct IpDrv.MeshBeaconClient.ClientConnectionRequest'!
void*& ClientRequest, bool bRegisterSecureAddress)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconClient.RequestConnection");
			byte* params = (byte*)malloc(52);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineGameSearch.OnlineGameSearchResult'!
void**)params = DesiredHost;
			*(
// WARNING: Unknown structure type 'ScriptStruct IpDrv.MeshBeaconClient.ClientConnectionRequest'!
void**)(params + 8) = ClientRequest;
			*(bool*)(params + 44) = bRegisterSecureAddress;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			DesiredHost = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineGameSearch.OnlineGameSearchResult'!
void**)params;
			ClientRequest = *(
// WARNING: Unknown structure type 'ScriptStruct IpDrv.MeshBeaconClient.ClientConnectionRequest'!
void**)(params + 8);
			auto returnVal = *(bool*)(params + 48);
			free(params);
			return returnVal;
		}
		bool BeginBandwidthTest(byte TestType, int TestBufferSize)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconClient.BeginBandwidthTest");
			byte* params = (byte*)malloc(9);
			*params = TestType;
			*(int*)(params + 4) = TestBufferSize;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool SendHostNewGameSessionResponse(bool bSuccess, ScriptName SessionName, ScriptClass* SearchClass, byte& PlatformSpecificInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeaconClient.SendHostNewGameSessionResponse");
			byte* params = (byte*)malloc(21);
			*(bool*)params = bSuccess;
			*(ScriptName*)(params + 4) = SessionName;
			*(ScriptClass**)(params + 12) = SearchClass;
			*(params + 16) = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			PlatformSpecificInfo = *(params + 16);
			auto returnVal = *(bool*)(params + 96);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
