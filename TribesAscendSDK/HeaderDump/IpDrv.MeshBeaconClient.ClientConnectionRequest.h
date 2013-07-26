#pragma once
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " MeshBeaconClient.ClientConnectionRequest." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty MeshBeaconClient.ClientConnectionRequest." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ClientConnectionRequest
	{
	public:
		ADD_VAR(::IntProperty, MinutesSinceLastTest, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, GoodHostRatio, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCanHostVs, 0x1)
		ADD_VAR(::ByteProperty, NatType, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<UniqueNetId>, PlayerNetId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
