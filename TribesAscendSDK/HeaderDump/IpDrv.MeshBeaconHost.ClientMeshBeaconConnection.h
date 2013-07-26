#pragma once
#include "IpDrv.MeshBeaconHost.ClientConnectionBandwidthTestData.h"
#include "Core.Object.Pointer.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " MeshBeaconHost.ClientMeshBeaconConnection." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty MeshBeaconHost.ClientMeshBeaconConnection." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ClientMeshBeaconConnection
	{
	public:
		ADD_VAR(::IntProperty, MinutesSinceLastTest, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, GoodHostRatio, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCanHostVs, 0x1)
		ADD_VAR(::ByteProperty, NatType, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ClientConnectionBandwidthTestData>, BandwidthTest, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bConnectionAccepted, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, Socket, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ElapsedHeartbeatTime, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<UniqueNetId>, PlayerNetId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
