#pragma once
#include "IpDrv__ClientBeaconAddressResolver.h"
#include "IpDrv__PartyBeacon.h"
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
		// Here lies the not-yet-implemented method 'OnHostHasCancelled'
		// Here lies the not-yet-implemented method 'OnHostIsReady'
		// Here lies the not-yet-implemented method 'OnTravelRequestReceived'
		// Here lies the not-yet-implemented method 'OnReservationCountUpdated'
		// Here lies the not-yet-implemented method 'OnReservationRequestComplete'
		// Here lies the not-yet-implemented method 'RequestReservation'
		// Here lies the not-yet-implemented method 'RequestReservationUpdate'
		// Here lies the not-yet-implemented method 'CancelReservation'
		// Here lies the not-yet-implemented method 'DestroyBeacon'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
