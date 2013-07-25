#pragma once
#include "IpDrv__MeshBeacon.h"
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
		// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId' for the property named 'OwningPlayerId'!
		// Here lies the not-yet-implemented method 'OnReceivedClientCreateNewSessionResult'
		// Here lies the not-yet-implemented method 'OnAllPendingPlayersConnected'
		// Here lies the not-yet-implemented method 'OnFinishedBandwidthTest'
		// Here lies the not-yet-implemented method 'OnStartedBandwidthTest'
		// Here lies the not-yet-implemented method 'OnReceivedClientConnectionRequest'
		// Here lies the not-yet-implemented method 'InitHostBeacon'
		// Here lies the not-yet-implemented method 'DestroyBeacon'
		// Here lies the not-yet-implemented method 'RequestClientBandwidthTest'
		// Here lies the not-yet-implemented method 'HasInProgressBandwidthTest'
		// Here lies the not-yet-implemented method 'CancelInProgressBandwidthTests'
		// Here lies the not-yet-implemented method 'HasPendingBandwidthTest'
		// Here lies the not-yet-implemented method 'CancelPendingBandwidthTests'
		// Here lies the not-yet-implemented method 'AllowBandwidthTesting'
		// Here lies the not-yet-implemented method 'SetPendingPlayerConnections'
		// Here lies the not-yet-implemented method 'GetConnectionIndexForPlayer'
		// Here lies the not-yet-implemented method 'AllPlayersConnected'
		// Here lies the not-yet-implemented method 'TellClientsToTravel'
		// Here lies the not-yet-implemented method 'RequestClientCreateNewSession'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
