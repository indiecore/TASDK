#pragma once
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineSubsystem.OnlineFriendMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty OnlineSubsystem.OnlineFriendMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlineFriendMessage
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<UniqueNetId>, SendingPlayerId, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SendingPlayerNick, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsFriendInvite, 0x1)
		ADD_VAR(::BoolProperty, bIsGameInvite, 0x2)
		ADD_VAR(::BoolProperty, bWasAccepted, 0x4)
		ADD_VAR(::BoolProperty, bWasDenied, 0x8)
		ADD_VAR(::StrProperty, Message, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
