#pragma once
#include "Core.Object.Double.h"
#include "IpDrv.MeshBeacon.ConnectionBandwidthStats.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " MeshBeaconHost.ClientConnectionBandwidthTestData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty MeshBeaconHost.ClientConnectionBandwidthTestData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ClientConnectionBandwidthTestData
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<ConnectionBandwidthStats>, BandwidthStats, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Double>, TestStartTime, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Double>, RequestTestStartTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, BytesReceived, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, BytesTotalNeeded, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, TestType, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, CurrentState, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
