#pragma once
#include "Core.Object.QWord.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineSubsystem.OnlinePartyMember." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty OnlineSubsystem.OnlinePartyMember." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlinePartyMember
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<UniqueNetId>, UniqueId, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NickName, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LocalUserNum, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, NatType, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TitleId, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsLocal, 0x1)
		ADD_VAR(::BoolProperty, bIsInPartyVoice, 0x2)
		ADD_VAR(::BoolProperty, bIsTalking, 0x4)
		ADD_VAR(::BoolProperty, bIsInGameSession, 0x8)
		ADD_VAR(::BoolProperty, bIsPlayingThisGame, 0x10)
		ADD_STRUCT(::QWordProperty, SessionId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Data1, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Data2, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Data3, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Data4, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
