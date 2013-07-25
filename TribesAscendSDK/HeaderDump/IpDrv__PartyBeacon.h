#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.PartyBeacon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty IpDrv.PartyBeacon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PartyBeacon : public Object
	{
	public:
		ADD_VAR(::NameProperty, BeaconName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ElapsedHeartbeatTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HeartbeatTimeout, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShouldTick, 0x4)
		ADD_VAR(::BoolProperty, bWantsDeferredDestroy, 0x2)
		ADD_VAR(::BoolProperty, bIsInTick, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'Socket'!
		ADD_VAR(::IntProperty, PartyBeaconPort, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_FTickableObject'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
