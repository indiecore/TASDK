#pragma once
#include "Core.Object.QWord.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#include "Engine.Settings.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.OnlineGameSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.OnlineGameSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlineGameSettings : public Settings
	{
	public:
		ADD_VAR(::BoolProperty, bUsesArbitration, 0x100)
		ADD_VAR(::IntProperty, NumOpenPrivateConnections, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumOpenPublicConnections, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, GameState, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<UniqueNetId>, OwningPlayerId, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsLanMatch, 0x2)
		ADD_VAR(::BoolProperty, bUsesStats, 0x4)
		ADD_VAR(::IntProperty, NumPublicConnections, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, BuildUniqueId, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MatchQuality, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PingInMs, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OwningPlayerName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bHasSkillUpdateInProgress, 0x1000)
		ADD_VAR(::BoolProperty, bIsDedicated, 0x800)
		ADD_VAR(::BoolProperty, bWasFromInvite, 0x400)
		ADD_VAR(::BoolProperty, bAntiCheatProtected, 0x200)
		ADD_VAR(::BoolProperty, bAllowJoinViaPresenceFriendsOnly, 0x80)
		ADD_VAR(::BoolProperty, bAllowJoinViaPresence, 0x40)
		ADD_VAR(::BoolProperty, bUsesPresence, 0x20)
		ADD_VAR(::BoolProperty, bAllowInvites, 0x10)
		ADD_VAR(::BoolProperty, bAllowJoinInProgress, 0x8)
		ADD_VAR(::BoolProperty, bShouldAdvertise, 0x1)
		ADD_STRUCT(::QWordProperty, ServerNonce, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumPrivateConnections, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
