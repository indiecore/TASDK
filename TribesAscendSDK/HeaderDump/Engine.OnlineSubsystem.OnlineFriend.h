#pragma once
#include "Core.Object.QWord.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineSubsystem.OnlineFriend." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty OnlineSubsystem.OnlineFriend." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlineFriend
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<UniqueNetId>, UniqueId, 0xFFFFFFFF)
		ADD_STRUCT(::QWordProperty, SessionId, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NickName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PresenceInfo, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, FriendState, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsOnline, 0x1)
		ADD_VAR(::BoolProperty, bIsPlaying, 0x2)
		ADD_VAR(::BoolProperty, bIsPlayingThisGame, 0x4)
		ADD_VAR(::BoolProperty, bIsJoinable, 0x8)
		ADD_VAR(::BoolProperty, bHasVoiceSupport, 0x10)
		ADD_VAR(::BoolProperty, bHaveInvited, 0x20)
		ADD_VAR(::BoolProperty, bHasInvitedYou, 0x40)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
