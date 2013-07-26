#pragma once
#include "Core.Object.h"
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.MeshBeacon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty IpDrv.MeshBeacon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MeshBeacon : public Object
	{
	public:
		ADD_VAR(::IntProperty, MaxBandwidthHistoryEntries, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxBandwidthTestReceiveTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxBandwidthTestSendTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MinBandwidthTestBufferSize, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxBandwidthTestBufferSize, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SocketReceiveBufferSize, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SocketSendBufferSize, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BeaconName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ElapsedHeartbeatTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HeartbeatTimeout, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShouldTick, 0x4)
		ADD_VAR(::BoolProperty, bWantsDeferredDestroy, 0x2)
		ADD_VAR(::BoolProperty, bIsInTick, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, Socket, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MeshBeaconPort, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VfTable_FTickableObject, 0xFFFFFFFF)
		void DestroyBeacon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.MeshBeacon.DestroyBeacon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
