#pragma once
#include "Core.Object.Pointer.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " PartyBeaconHost.ClientBeaconConnection." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty PartyBeaconHost.ClientBeaconConnection." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ClientBeaconConnection
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, Socket, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ElapsedHeartbeatTime, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<UniqueNetId>, PartyLeader, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
