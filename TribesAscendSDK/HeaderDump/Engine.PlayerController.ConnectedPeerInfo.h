#pragma once
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " PlayerController.ConnectedPeerInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty PlayerController.ConnectedPeerInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ConnectedPeerInfo
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<UniqueNetId>, PlayerID, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, NatType, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bLostConnectionToHost, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
