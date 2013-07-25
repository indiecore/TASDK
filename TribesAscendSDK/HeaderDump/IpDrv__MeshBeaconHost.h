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
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
