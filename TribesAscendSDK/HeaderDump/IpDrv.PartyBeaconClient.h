#pragma once
#include "IpDrv.PartyBeacon.h"
#include "IpDrv.ClientBeaconAddressResolver.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.PartyBeaconClient." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty IpDrv.PartyBeaconClient." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty IpDrv.PartyBeaconClient." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PartyBeaconClient : public PartyBeacon
	{
	public:
		ADD_OBJECT(ClientBeaconAddressResolver, Resolver)
		ADD_OBJECT(ScriptClass, ResolverClass)
		ADD_VAR(::StrProperty, ResolverClassName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ReservationRequestElapsedTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ReservationRequestTimeout, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ClientBeaconRequestType, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ClientBeaconState, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineGameSearch.OnlineGameSearchResult' for the property named 'HostPendingRequest'!
		// WARNING: Unknown structure type 'ScriptStruct IpDrv.PartyBeacon.PartyReservation' for the property named 'PendingRequest'!
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
			byte* params = (byte*)malloc(13);
			*(ScriptName*)params = SessionName;
			*(ScriptClass**)(params + 8) = SearchClass;
			*(params + 12) = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnReservationCountUpdated(int ReservationRemaining)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconClient.OnReservationCountUpdated");
			byte* params = (byte*)malloc(4);
			*(int*)params = ReservationRemaining;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnReservationRequestComplete(byte ReservationResult)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconClient.OnReservationRequestComplete");
			byte* params = (byte*)malloc(1);
			*params = ReservationResult;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool RequestReservation(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineGameSearch.OnlineGameSearchResult'!
void*& DesiredHost, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* RequestingPartyLeader, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Players)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconClient.RequestReservation");
			byte* params = (byte*)malloc(32);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineGameSearch.OnlineGameSearchResult'!
void**)params = DesiredHost;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 8) = RequestingPartyLeader;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16) = Players;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			DesiredHost = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineGameSearch.OnlineGameSearchResult'!
void**)params;
			Players = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		bool RequestReservationUpdate(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineGameSearch.OnlineGameSearchResult'!
void*& DesiredHost, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* RequestingPartyLeader, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& PlayersToAdd)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconClient.RequestReservationUpdate");
			byte* params = (byte*)malloc(32);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineGameSearch.OnlineGameSearchResult'!
void**)params = DesiredHost;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 8) = RequestingPartyLeader;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16) = PlayersToAdd;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			DesiredHost = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineGameSearch.OnlineGameSearchResult'!
void**)params;
			PlayersToAdd = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		bool CancelReservation(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* CancellingPartyLeader)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconClient.CancelReservation");
			byte* params = (byte*)malloc(12);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = CancellingPartyLeader;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void DestroyBeacon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.PartyBeaconClient.DestroyBeacon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
