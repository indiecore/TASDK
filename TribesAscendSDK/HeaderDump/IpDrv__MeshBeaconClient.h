#pragma once
#include "IpDrv__MeshBeacon.h"
#include "IpDrv__ClientBeaconAddressResolver.h"
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
		// Here lies the not-yet-implemented method 'OnCreateNewSessionRequestReceived'
		// Here lies the not-yet-implemented method 'OnTravelRequestReceived'
		// Here lies the not-yet-implemented method 'OnReceivedBandwidthTestResults'
		// Here lies the not-yet-implemented method 'OnReceivedBandwidthTestRequest'
		// Here lies the not-yet-implemented method 'OnConnectionRequestResult'
		// Here lies the not-yet-implemented method 'DestroyBeacon'
		// Here lies the not-yet-implemented method 'RequestConnection'
		// Here lies the not-yet-implemented method 'BeginBandwidthTest'
		// Here lies the not-yet-implemented method 'SendHostNewGameSessionResponse'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
